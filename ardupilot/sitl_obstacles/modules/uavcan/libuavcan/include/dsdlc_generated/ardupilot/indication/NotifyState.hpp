/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/user/cyberimmune-systems-autonomous-delivery-drone-with-kos-contest/modules/DroneCAN/DSDL/ardupilot/indication/20007.NotifyState.uavcan
 */

#ifndef ARDUPILOT_INDICATION_NOTIFYSTATE_HPP_INCLUDED
#define ARDUPILOT_INDICATION_NOTIFYSTATE_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
uint8 VEHICLE_STATE_INITIALISING    = 0
uint8 VEHICLE_STATE_ARMED           = 1
uint8 VEHICLE_STATE_FLYING          = 2
uint8 VEHICLE_STATE_PREARM          = 3
uint8 VEHICLE_STATE_PREARM_GPS      = 4
uint8 VEHICLE_STATE_SAVE_TRIM       = 5
uint8 VEHICLE_STATE_ESC_CALIBRATION = 6
uint8 VEHICLE_STATE_FAILSAFE_RADIO  = 7
uint8 VEHICLE_STATE_FAILSAFE_BATT   = 8
uint8 VEHICLE_STATE_FAILSAFE_GCS    = 9
uint8 VEHICLE_STATE_CHUTE_RELEASED  = 10
uint8 VEHICLE_STATE_EKF_BAD         = 11
uint8 VEHICLE_STATE_FW_UPDATE       = 12
uint8 VEHICLE_STATE_MAGCAL_RUN      = 13
uint8 VEHICLE_STATE_LEAK_DET        = 14
uint8 VEHICLE_STATE_GPS_FUSION      = 15
uint8 VEHICLE_STATE_GPS_GLITCH      = 16
uint8 VEHICLE_STATE_POS_ABS_AVAIL   = 17
uint8 VEHICLE_STATE_LOST            = 18
uint8 VEHICLE_STATE_THROW_READY     = 19
uint8 VEHICLE_STATE_POWERING_OFF    = 20
uint8 VEHICLE_STATE_VIDEO_RECORDING = 21
uint8 VEHICLE_STATE_IS_LANDING      = 22
uint8 VEHICLE_STATE_IS_TAKING_OFF   = 23

uint8 VEHICLE_YAW_EARTH_CENTIDEGREES = 0

# set the type of aux data to be sent
uint8 aux_data_type

# bytes containing packed auxiliary data
# placing it first so we don't do TAO
uint8[<=255] aux_data

# Current Vehicle State Mask
uint64 vehicle_state
******************************************************************************/

/********************* DSDL signature source definition ***********************
ardupilot.indication.NotifyState
saturated uint8 aux_data_type
saturated uint8[<=255] aux_data
saturated uint64 vehicle_state
******************************************************************************/

#undef aux_data_type
#undef aux_data
#undef vehicle_state
#undef VEHICLE_STATE_INITIALISING
#undef VEHICLE_STATE_ARMED
#undef VEHICLE_STATE_FLYING
#undef VEHICLE_STATE_PREARM
#undef VEHICLE_STATE_PREARM_GPS
#undef VEHICLE_STATE_SAVE_TRIM
#undef VEHICLE_STATE_ESC_CALIBRATION
#undef VEHICLE_STATE_FAILSAFE_RADIO
#undef VEHICLE_STATE_FAILSAFE_BATT
#undef VEHICLE_STATE_FAILSAFE_GCS
#undef VEHICLE_STATE_CHUTE_RELEASED
#undef VEHICLE_STATE_EKF_BAD
#undef VEHICLE_STATE_FW_UPDATE
#undef VEHICLE_STATE_MAGCAL_RUN
#undef VEHICLE_STATE_LEAK_DET
#undef VEHICLE_STATE_GPS_FUSION
#undef VEHICLE_STATE_GPS_GLITCH
#undef VEHICLE_STATE_POS_ABS_AVAIL
#undef VEHICLE_STATE_LOST
#undef VEHICLE_STATE_THROW_READY
#undef VEHICLE_STATE_POWERING_OFF
#undef VEHICLE_STATE_VIDEO_RECORDING
#undef VEHICLE_STATE_IS_LANDING
#undef VEHICLE_STATE_IS_TAKING_OFF
#undef VEHICLE_YAW_EARTH_CENTIDEGREES

namespace ardupilot
{
namespace indication
{

template <int _tmpl>
struct UAVCAN_EXPORT NotifyState_
{
    typedef const NotifyState_<_tmpl>& ParameterType;
    typedef NotifyState_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_INITIALISING;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_ARMED;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_FLYING;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_PREARM;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_PREARM_GPS;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_SAVE_TRIM;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_ESC_CALIBRATION;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_FAILSAFE_RADIO;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_FAILSAFE_BATT;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_FAILSAFE_GCS;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_CHUTE_RELEASED;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_EKF_BAD;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_FW_UPDATE;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_MAGCAL_RUN;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_LEAK_DET;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_GPS_FUSION;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_GPS_GLITCH;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_POS_ABS_AVAIL;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_LOST;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_THROW_READY;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_POWERING_OFF;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_VIDEO_RECORDING;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_IS_LANDING;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_STATE_IS_TAKING_OFF;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > VEHICLE_YAW_EARTH_CENTIDEGREES;
    };

    struct FieldTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > aux_data_type;
        typedef ::uavcan::Array< ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 255 > aux_data;
        typedef ::uavcan::IntegerSpec< 64, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > vehicle_state;
    };

    enum
    {
        MinBitLen
            = FieldTypes::aux_data_type::MinBitLen
            + FieldTypes::aux_data::MinBitLen
            + FieldTypes::vehicle_state::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::aux_data_type::MaxBitLen
            + FieldTypes::aux_data::MaxBitLen
            + FieldTypes::vehicle_state::MaxBitLen
    };

    // Constants
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_INITIALISING >::Type VEHICLE_STATE_INITIALISING; // 0
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_ARMED >::Type VEHICLE_STATE_ARMED; // 1
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_FLYING >::Type VEHICLE_STATE_FLYING; // 2
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_PREARM >::Type VEHICLE_STATE_PREARM; // 3
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_PREARM_GPS >::Type VEHICLE_STATE_PREARM_GPS; // 4
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_SAVE_TRIM >::Type VEHICLE_STATE_SAVE_TRIM; // 5
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_ESC_CALIBRATION >::Type VEHICLE_STATE_ESC_CALIBRATION; // 6
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_FAILSAFE_RADIO >::Type VEHICLE_STATE_FAILSAFE_RADIO; // 7
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_FAILSAFE_BATT >::Type VEHICLE_STATE_FAILSAFE_BATT; // 8
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_FAILSAFE_GCS >::Type VEHICLE_STATE_FAILSAFE_GCS; // 9
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_CHUTE_RELEASED >::Type VEHICLE_STATE_CHUTE_RELEASED; // 10
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_EKF_BAD >::Type VEHICLE_STATE_EKF_BAD; // 11
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_FW_UPDATE >::Type VEHICLE_STATE_FW_UPDATE; // 12
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_MAGCAL_RUN >::Type VEHICLE_STATE_MAGCAL_RUN; // 13
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_LEAK_DET >::Type VEHICLE_STATE_LEAK_DET; // 14
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_GPS_FUSION >::Type VEHICLE_STATE_GPS_FUSION; // 15
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_GPS_GLITCH >::Type VEHICLE_STATE_GPS_GLITCH; // 16
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_POS_ABS_AVAIL >::Type VEHICLE_STATE_POS_ABS_AVAIL; // 17
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_LOST >::Type VEHICLE_STATE_LOST; // 18
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_THROW_READY >::Type VEHICLE_STATE_THROW_READY; // 19
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_POWERING_OFF >::Type VEHICLE_STATE_POWERING_OFF; // 20
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_VIDEO_RECORDING >::Type VEHICLE_STATE_VIDEO_RECORDING; // 21
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_IS_LANDING >::Type VEHICLE_STATE_IS_LANDING; // 22
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_STATE_IS_TAKING_OFF >::Type VEHICLE_STATE_IS_TAKING_OFF; // 23
    static const typename ::uavcan::StorageType< typename ConstantTypes::VEHICLE_YAW_EARTH_CENTIDEGREES >::Type VEHICLE_YAW_EARTH_CENTIDEGREES; // 0

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::aux_data_type >::Type aux_data_type;
    typename ::uavcan::StorageType< typename FieldTypes::aux_data >::Type aux_data;
    typename ::uavcan::StorageType< typename FieldTypes::vehicle_state >::Type vehicle_state;

    NotifyState_()
        : aux_data_type()
        , aux_data()
        , vehicle_state()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<2120 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 20007 };

    static const char* getDataTypeFullName()
    {
        return "ardupilot.indication.NotifyState";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool NotifyState_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        aux_data_type == rhs.aux_data_type &&
        aux_data == rhs.aux_data &&
        vehicle_state == rhs.vehicle_state;
}

template <int _tmpl>
bool NotifyState_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(aux_data_type, rhs.aux_data_type) &&
        ::uavcan::areClose(aux_data, rhs.aux_data) &&
        ::uavcan::areClose(vehicle_state, rhs.vehicle_state);
}

template <int _tmpl>
int NotifyState_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::aux_data_type::encode(self.aux_data_type, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::aux_data::encode(self.aux_data, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::vehicle_state::encode(self.vehicle_state, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int NotifyState_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::aux_data_type::decode(self.aux_data_type, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::aux_data::decode(self.aux_data, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::vehicle_state::decode(self.vehicle_state, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature NotifyState_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x631F2A9C1651FDECULL);

    FieldTypes::aux_data_type::extendDataTypeSignature(signature);
    FieldTypes::aux_data::extendDataTypeSignature(signature);
    FieldTypes::vehicle_state::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_INITIALISING >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_INITIALISING = 0U; // 0

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_ARMED >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_ARMED = 1U; // 1

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_FLYING >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_FLYING = 2U; // 2

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_PREARM >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_PREARM = 3U; // 3

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_PREARM_GPS >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_PREARM_GPS = 4U; // 4

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_SAVE_TRIM >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_SAVE_TRIM = 5U; // 5

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_ESC_CALIBRATION >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_ESC_CALIBRATION = 6U; // 6

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_FAILSAFE_RADIO >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_FAILSAFE_RADIO = 7U; // 7

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_FAILSAFE_BATT >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_FAILSAFE_BATT = 8U; // 8

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_FAILSAFE_GCS >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_FAILSAFE_GCS = 9U; // 9

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_CHUTE_RELEASED >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_CHUTE_RELEASED = 10U; // 10

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_EKF_BAD >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_EKF_BAD = 11U; // 11

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_FW_UPDATE >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_FW_UPDATE = 12U; // 12

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_MAGCAL_RUN >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_MAGCAL_RUN = 13U; // 13

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_LEAK_DET >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_LEAK_DET = 14U; // 14

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_GPS_FUSION >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_GPS_FUSION = 15U; // 15

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_GPS_GLITCH >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_GPS_GLITCH = 16U; // 16

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_POS_ABS_AVAIL >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_POS_ABS_AVAIL = 17U; // 17

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_LOST >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_LOST = 18U; // 18

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_THROW_READY >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_THROW_READY = 19U; // 19

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_POWERING_OFF >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_POWERING_OFF = 20U; // 20

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_VIDEO_RECORDING >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_VIDEO_RECORDING = 21U; // 21

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_IS_LANDING >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_IS_LANDING = 22U; // 22

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_STATE_IS_TAKING_OFF >::Type
    NotifyState_<_tmpl>::VEHICLE_STATE_IS_TAKING_OFF = 23U; // 23

template <int _tmpl>
const typename ::uavcan::StorageType< typename NotifyState_<_tmpl>::ConstantTypes::VEHICLE_YAW_EARTH_CENTIDEGREES >::Type
    NotifyState_<_tmpl>::VEHICLE_YAW_EARTH_CENTIDEGREES = 0U; // 0

/*
 * Final typedef
 */
typedef NotifyState_<0> NotifyState;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::ardupilot::indication::NotifyState > _uavcan_gdtr_registrator_NotifyState;

}

} // Namespace indication
} // Namespace ardupilot

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::ardupilot::indication::NotifyState >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::ardupilot::indication::NotifyState::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::ardupilot::indication::NotifyState >::stream(Stream& s, ::ardupilot::indication::NotifyState::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "aux_data_type: ";
    YamlStreamer< ::ardupilot::indication::NotifyState::FieldTypes::aux_data_type >::stream(s, obj.aux_data_type, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "aux_data: ";
    YamlStreamer< ::ardupilot::indication::NotifyState::FieldTypes::aux_data >::stream(s, obj.aux_data, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "vehicle_state: ";
    YamlStreamer< ::ardupilot::indication::NotifyState::FieldTypes::vehicle_state >::stream(s, obj.vehicle_state, level + 1);
}

}

namespace ardupilot
{
namespace indication
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::ardupilot::indication::NotifyState::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::ardupilot::indication::NotifyState >::stream(s, obj, 0);
    return s;
}

} // Namespace indication
} // Namespace ardupilot

#endif // ARDUPILOT_INDICATION_NOTIFYSTATE_HPP_INCLUDED