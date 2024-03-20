#include "../include/credential_manager.h"

#include <mbedtls_v3/rsa.h>
#include <mbedtls_v3/sha256.h>

#include <string.h>

mbedtls_rsa_context rsaServer;

uint8_t hexCharToInt(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else {
        fprintf(stderr, "Error: %c is not a viable hex value\n", c);
        return 0;
    }
}

void stringToBytes(char* source, uint32_t sourceSize, uint8_t* destination) {
    int j = 127;
    for (int32_t i = sourceSize - 1; i >= 0; i -= 2) {
        if (i > 0)
            destination[j] = 16 * hexCharToInt(source[i - 1]) + hexCharToInt(source[i]);
        else
            destination[j] = hexCharToInt(source[i]);
        j--;
    }
}

int setRsaKey(char* key) {
    char header[] = "$Key: ";
    char* nStart = strstr(key, header);

    if (nStart == NULL) {
        fprintf(stderr, "[%s] Warning: Failed to parse public RSA key received from the server\n", ENTITY_NAME);
        return 0;
    }

    nStart += strlen(header);
    char* eStart = strstr(nStart, " ");

    if (eStart == NULL) {
        fprintf(stderr, "[%s] Warning: Failed to parse public RSA key received from the server\n", ENTITY_NAME);
        return 0;
    }

    uint8_t N[128] = {0};
    uint8_t E[128] = {0};

    stringToBytes(nStart, eStart - nStart, N);
    eStart++;
    stringToBytes(eStart, strlen(eStart), E);

    mbedtls_rsa_init(&rsaServer);
    mbedtls_rsa_import_raw(&rsaServer, N, 128, NULL, 0, NULL, 0, NULL, 0, E, 128);

    return 1;
}

int checkSignature(char* message, uint8_t &correct) {
    correct = 0;

    char* signatureStart = strstr(message, "#");
    if (signatureStart == NULL) {
        fprintf(stderr, "[%s] Warning: Received mission has no signature\n", ENTITY_NAME);
        return 0;
    }
    uint32_t messageLength = signatureStart - message;

    uint8_t hash[32] = {0};
    mbedtls_sha256_context sha256;
    mbedtls_sha256_init(&sha256);
    if (mbedtls_sha256_starts(&sha256, 0) != 0) {
        fprintf(stderr, "[%s] Warning: Failed to calculate hash of received message\n", ENTITY_NAME);
        mbedtls_sha256_free(&sha256);
        return 0;
    }
    if (mbedtls_sha256_update(&sha256, (unsigned char*)message, messageLength) != 0) {
        fprintf(stderr, "[%s] Warning: Failed to calculate hash of received message\n", ENTITY_NAME);
        mbedtls_sha256_free(&sha256);
        return 0;
    }
    if (mbedtls_sha256_finish(&sha256, hash) != 0) {
        fprintf(stderr, "[%s] Warning: Failed to calculate hash of received message\n", ENTITY_NAME);
        mbedtls_sha256_free(&sha256);
        return 0;
    }
    mbedtls_sha256_free(&sha256);

    uint8_t signature[128] = {0};
    uint8_t result[128] = {0};
    signatureStart++;
    stringToBytes(signatureStart, strlen(signatureStart), signature);
    if (mbedtls_rsa_public(&rsaServer, signature, result) != 0) {
        fprintf(stderr, "[%s] Warning: Failed to decode server signature\n", ENTITY_NAME);
        return 0;
    }

    int j = 31;
    for (int i = 127; i >= 0; i--) {
        int check = (j >= 0) ? (result[i] == hash[j]) : !result[i];
        if (!check) {
            fprintf(stderr, "[%s] Warning: Authenticity is not confirmed\n", ENTITY_NAME);
            return 0;
        }
        j--;
    }

    correct = 1;
    return 1;
}