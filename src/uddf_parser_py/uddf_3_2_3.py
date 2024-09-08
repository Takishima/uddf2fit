# Generated using xsdata uddf_3.2.3.xsd --package uddf_parser
from dataclasses import dataclass, field
from enum import Enum
from typing import Optional

from xsdata.models.datatype import XmlDateTime

__NAMESPACE__ = 'http://www.streit.cc/uddf/3.2/'


@dataclass
class IdType:
    class Meta:
        name = 'ID_TYPE'

    id: str | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )


class AbundanceOccurrence(Enum):
    NOT_ASCERTAINABLE = 'not-ascertainable'
    SINGLE_INDIVIDUAL = 'single-individual'
    LOOSE_ASSOCIATION = 'loose-association'
    SWARM = 'swarm'
    COLONY = 'colony'


class AbundanceQuality(Enum):
    EXACT = 'exact'
    ESTIMATED = 'estimated'


@dataclass
class AddressType:
    class Meta:
        name = 'addressType'

    street: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    city: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    postcode: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    country: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    province: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


class AlarmType(Enum):
    ASCENT = 'ascent'
    BREATH = 'breath'
    DECO = 'deco'
    ERROR = 'error'
    LINK = 'link'
    MICROBUBBLES = 'microbubbles'
    RBT = 'rbt'
    SKINCOOLING = 'skincooling'
    SURFACE = 'surface'


@dataclass
class ApplicationdataType:
    class Meta:
        name = 'applicationdataType'

    decotrainer: Optional['ApplicationdataType.Decotrainer'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    hargikas: Optional['ApplicationdataType.Hargikas'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    heinrichsweikamp: Optional['ApplicationdataType.Heinrichsweikamp'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tausim: Optional['ApplicationdataType.Tausim'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tautabu: Optional['ApplicationdataType.Tautabu'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )

    @dataclass
    class Decotrainer:
        other_element: list[object] = field(
            default_factory=list,
            metadata={
                'type': 'Wildcard',
                'namespace': '##other',
                'process_contents': 'skip',
            },
        )

    @dataclass
    class Hargikas:
        other_element: list[object] = field(
            default_factory=list,
            metadata={
                'type': 'Wildcard',
                'namespace': '##other',
                'process_contents': 'skip',
            },
        )

    @dataclass
    class Heinrichsweikamp:
        other_element: list[object] = field(
            default_factory=list,
            metadata={
                'type': 'Wildcard',
                'namespace': '##other',
                'process_contents': 'skip',
            },
        )

    @dataclass
    class Tausim:
        other_element: list[object] = field(
            default_factory=list,
            metadata={
                'type': 'Wildcard',
                'namespace': '##other',
                'process_contents': 'skip',
            },
        )

    @dataclass
    class Tautabu:
        other_element: list[object] = field(
            default_factory=list,
            metadata={
                'type': 'Wildcard',
                'namespace': '##other',
                'process_contents': 'skip',
            },
        )


@dataclass
class BottomtimetablescopeType:
    class Meta:
        name = 'bottomtimetablescopeType'

    divedepthbegin: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    divedepthend: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    divedepthstep: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    breathingconsumptionvolumebegin: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    breathingconsumptionvolumeend: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    breathingconsumptionvolumestep: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    tankvolumebegin: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    tankvolumeend: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    tankvolumestep: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    tankpressurebegin: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    tankpressurereserve: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class ContactType:
    class Meta:
        name = 'contactType'

    language: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    phone: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    mobilephone: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    fax: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    email: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    homepage: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class DcalarmType:
    class Meta:
        name = 'dcalarmType'

    acknowledge: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    period: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    alarm_type: int | None = field(
        default=None,
        metadata={
            'name': 'alarmType',
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class DcalarmtimeType:
    class Meta:
        name = 'dcalarmtimeType'

    acknowledge: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    period: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    alarm_type: int | None = field(
        default=None,
        metadata={
            'name': 'alarmType',
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class DcbuddydataType:
    class Meta:
        name = 'dcbuddydataType'

    buddy: str | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )


@dataclass
class DcdivesitedataType:
    class Meta:
        name = 'dcdivesitedataType'

    divesite: str | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )


@dataclass
class DcgasdefinitionsdataType:
    class Meta:
        name = 'dcgasdefinitionsdataType'

    setdcallgasdefinitions: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    setdcgasdata: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


class DecostopKind(Enum):
    SAFETY = 'safety'
    MANDATORY = 'mandatory'


@dataclass
class DimensionType:
    class Meta:
        name = 'dimensionType'

    length: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    beam: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    draught: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    displacement: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tonnage: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


class DivemodeType(Enum):
    APNEA = 'apnea'
    APNOE = 'apnoe'
    CLOSEDCIRCUIT = 'closedcircuit'
    OPENCIRCUIT = 'opencircuit'
    SEMICLOSEDCIRCUIT = 'semiclosedcircuit'


class DrugTypePeriodicallytaken(Enum):
    NO = 'no'
    YES = 'yes'


@dataclass
class EncapsulatedDateTimeType:
    class Meta:
        name = 'encapsulatedDateTimeType'

    datetime: XmlDateTime | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


class ExaminationTypeExaminationresult(Enum):
    PASSED = 'passed'
    FAILED = 'failed'


class ExposuretoaltitudeTypeTransportation(Enum):
    COMMERCIAL_AIRCRAFT = 'commercial-aircraft'
    UNPRESSURIZED_AIRCRAFT = 'unpressurized-aircraft'
    MEDEVAC_AIRCRAFT = 'medevac-aircraft'
    GROUND_TRANSPORTATION = 'ground-transportation'
    HELICOPTER = 'helicopter'


class GeneratorType(Enum):
    CONVERTER = 'converter'
    DIVECOMPUTER = 'divecomputer'
    LOGBOOK = 'logbook'


@dataclass
class GetdcdataType:
    class Meta:
        name = 'getdcdataType'

    getdcalldata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    getdcgeneratordata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    getdcownerdata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    getdcbuddydata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    getdcgasdefinitionsdata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    getdcdivesitedata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    getdcdivetripdata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    getdcprofiledata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )


class GlobalalarmsgivenGlobalalarm(Enum):
    ASCENT_WARNING_TOO_LONG = 'ascent-warning-too-long'
    SOS_MODE = 'sos-mode'
    WORK_TOO_HARD = 'work-too-hard'


class GloballightintensityType(Enum):
    UNDETERMINED = 'undetermined'
    SUNNY = 'sunny'
    HALF_SHADOW = 'half-shadow'
    SHADOW = 'shadow'
    NO_LIGHT = 'no-light'


class ImagedataMeteringmethod(Enum):
    SPOT = 'spot'
    CENTERWEIGHTED = 'centerweighted'
    MATRIX = 'matrix'


class InformationafterdiveTypeCurrent(Enum):
    NO_CURRENT = 'no-current'
    VERY_MILD_CURRENT = 'very-mild-current'
    MILD_CURRENT = 'mild-current'
    MODERATE_CURRENT = 'moderate-current'
    HARD_CURRENT = 'hard-current'
    VERY_HARD_CURRENT = 'very-hard-current'


class InformationafterdiveTypeDiveplan(Enum):
    NONE = 'none'
    TABLE = 'table'
    DIVE_COMPUTER = 'dive-computer'
    ANOTHER_DIVER = 'another-diver'


class InformationafterdiveTypeDivetable(Enum):
    PADI = 'PADI'
    NAUI = 'NAUI'
    BSAC = 'BSAC'
    BUEHLMANN = 'Buehlmann'
    DCIEM = 'DCIEM'
    US_NAVY = 'US-Navy'
    CSMD = 'CSMD'
    COMEX = 'COMEX'
    OTHER = 'other'


class InformationafterdiveTypeEquipmentmalfunction(Enum):
    NONE = 'none'
    FACE_MASK = 'face-mask'
    FINS = 'fins'
    WEIGHT_BELT = 'weight-belt'
    BUOYANCY_CONTROL_DEVICE = 'buoyancy-control-device'
    THERMAL_PROTECTION = 'thermal-protection'
    DIVE_COMPUTER = 'dive-computer'
    DEPTH_GAUGE = 'depth-gauge'
    PRESSURE_GAUGE = 'pressure-gauge'
    BREATHING_APPARATUS = 'breathing-apparatus'
    DECO_REEL = 'deco-reel'
    OTHER = 'other'


class InformationafterdiveTypeProblems(Enum):
    NONE = 'none'
    EQUALISATION = 'equalisation'
    VERTIGO = 'vertigo'
    OUT_OF_AIR = 'out-of-air'
    BUOYANCY = 'buoyancy'
    SHARED_AIR = 'shared-air'
    RAPID_ASCENT = 'rapid-ascent'
    SEA_SICKNESS = 'sea-sickness'
    OTHER = 'other'


class InformationafterdiveTypeProgram(Enum):
    RECREATION = 'recreation'
    TRAINING = 'training'
    SCIENTIFIC = 'scientific'
    MEDICAL = 'medical'
    COMMERCIAL = 'commercial'
    MILITARY = 'military'
    COMPETITIVE = 'competitive'
    OTHER = 'other'


class InformationafterdiveTypeThermalcomfort(Enum):
    NOT_INDICATED = 'not-indicated'
    COMFORTABLE = 'comfortable'
    COLD = 'cold'
    VERY_COLD = 'very-cold'
    HOT = 'hot'


class InformationafterdiveTypeWorkload(Enum):
    NOT_SPECIFIED = 'not-specified'
    RESTING = 'resting'
    LIGHT = 'light'
    MODERATE = 'moderate'
    SEVERE = 'severe'
    EXHAUSTING = 'exhausting'


class InformationbeforediveTypeApparatus(Enum):
    OPEN_SCUBA = 'open-scuba'
    REBREATHER = 'rebreather'
    SURFACE_SUPPLIED = 'surface-supplied'
    CHAMBER = 'chamber'
    EXPERIMENTAL = 'experimental'


class InformationbeforediveTypePlatform(Enum):
    BEACH_SHORE = 'beach-shore'
    PIER = 'pier'
    SMALL_BOAT = 'small-boat'
    CHARTER_BOAT = 'charter-boat'
    LIVE_ABOARD = 'live-aboard'
    BARGE = 'barge'
    LANDSIDE = 'landside'
    HYPERBARIC_FACILITY = 'hyperbaric-facility'
    OTHER = 'other'


class InformationbeforediveTypePurpose(Enum):
    SIGHTSEEING = 'sightseeing'
    LEARNING = 'learning'
    TEACHING = 'teaching'
    RESEARCH = 'research'
    PHOTOGRAPHY_VIDEOGRAPHY = 'photography-videography'
    SPEARFISHING = 'spearfishing'
    PROFICIENCY = 'proficiency'
    WORK = 'work'
    OTHER = 'other'


class InformationbeforediveTypeStateofrestbeforedive(Enum):
    NOT_SPECIFIED = 'not-specified'
    RESTED = 'rested'
    TIRED = 'tired'
    EXHAUSTED = 'exhausted'


@dataclass
class LinkType:
    class Meta:
        name = 'linkType'

    ref: str | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )


@dataclass
class OutputType:
    class Meta:
        name = 'outputType'

    lingo: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    fileformat: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    filename: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    headline: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    remark: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


class PersonalTypeSmoking(Enum):
    VALUE_0 = '0'
    VALUE_0_3 = '0-3'
    VALUE_4_10 = '4-10'
    VALUE_11_20 = '11-20'
    VALUE_21_40 = '21-40'
    VALUE_40 = '40+'


@dataclass
class PriceType:
    class Meta:
        name = 'priceType'

    value: float | None = field(
        default=None,
        metadata={
            'required': True,
        },
    )
    currency: str | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'length': 3,
        },
    )


@dataclass
class RatingType:
    class Meta:
        name = 'ratingType'

    datetime: XmlDateTime | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    ratingvalue: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
            'min_inclusive': 1,
            'max_inclusive': 10,
        },
    )


class Setpo2Setby(Enum):
    USER = 'user'
    COMPUTER = 'computer'


class SexType(Enum):
    UNDETERMINED = 'undetermined'
    MALE = 'male'
    FEMALE = 'female'
    HERMAPHRODITE = 'hermaphrodite'


@dataclass
class SimpleNamedType:
    class Meta:
        name = 'simpleNamedType'

    name: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    aliasname: list[object] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


class SiteTypeEnvironment(Enum):
    UNKNOWN = 'unknown '
    OCEAN_SEA = 'ocean-sea'
    LAKE_QUARRY = 'lake-quarry'
    RIVER_SPRING = 'river-spring'
    CAVE_CAVERN = 'cave-cavern'
    POOL = 'pool'
    HYPERBARIC_CHAMBER = 'hyperbaric-chamber'
    UNDER_ICE = 'under-ice'
    OTHER = 'other'


class SpeciesTypeDominance(Enum):
    UNDETERMINED = 'undetermined'
    LESS_THAN_1_20 = 'less-than-1/20'
    VALUE_1_20_UP_TO_1_4 = '1/20-up-to-1/4'
    VALUE_1_4_UP_TO_1_2 = '1/4-up-to-1/2'
    VALUE_1_2_UP_TO_3_4 = '1/2-up-to-3/4'
    GREATER_THAN_3_4 = 'greater-than-3/4'
    SINGLE_INDIVIDUAL = 'single-individual'


class SpeciesTypeLifestage(Enum):
    LARVA = 'larva'
    JUVENILE = 'juvenile'
    ADULT = 'adult'


class SuitTypeSuittype(Enum):
    DIVE_SKIN = 'dive-skin'
    WET_SUIT = 'wet-suit'
    DRY_SUIT = 'dry-suit'
    HOT_WATER_SUIT = 'hot-water-suit'
    OTHER = 'other'


@dataclass
class TablescopeType:
    class Meta:
        name = 'tablescopeType'

    altitude: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    divedepthbegin: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    divedepthend: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    divedepthstep: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    bottomtimemaximum: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    bottomtimeminimum: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    bottomtimestepbegin: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    bottomtimestepend: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


class TankmaterialType(Enum):
    ALUMINIUM = 'aluminium'
    CARBON = 'carbon'
    STEEL = 'steel'


class TissueTypeGas(Enum):
    H2 = 'h2'
    HE = 'he'
    N2 = 'n2'


@dataclass
class WayaltitudeType:
    class Meta:
        name = 'wayaltitudeType'

    value: float | None = field(
        default=None,
        metadata={
            'required': True,
        },
    )
    waytime: float | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )


@dataclass
class BottomtimetableType(IdType):
    class Meta:
        name = 'bottomtimetableType'

    title: object | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    link: list[LinkType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    output: OutputType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    applicationdata: ApplicationdataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    bottomtimetablescope: BottomtimetablescopeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class BuiltType:
    class Meta:
        name = 'builtType'

    shipyard: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    launchingdate: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class DcalarmWithDepthType:
    class Meta:
        name = 'dcalarmWithDepthType'

    dcalarmdepth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    dcalarm: DcalarmType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class DcalarmWithTimeType(EncapsulatedDateTimeType):
    class Meta:
        name = 'dcalarmWithTimeType'

    dcalarm: DcalarmType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class DcdecomodelType(SimpleNamedType):
    class Meta:
        name = 'dcdecomodelType'

    applicationdata: ApplicationdataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class DcdivedepthalarmType:
    class Meta:
        name = 'dcdivedepthalarmType'

    dcalarmdepth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    dcalarm: DcalarmType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class Dcdivepo2AlarmType:
    class Meta:
        name = 'dcdivepo2alarmType'

    maximumpo2: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    dcalarm: DcalarmType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class DcdivetimealarmType:
    class Meta:
        name = 'dcdivetimealarmType'

    timespan: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    dcalarm: DcalarmType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class DcendndtalarmType:
    class Meta:
        name = 'dcendndtalarmType'

    dcalarm: DcalarmType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class DivecomputerdumpType:
    class Meta:
        name = 'divecomputerdumpType'

    link: LinkType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    datetime: XmlDateTime | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    dcdump: bytes | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
            'format': 'base64',
        },
    )


@dataclass
class ExposuretoaltitudeType:
    class Meta:
        name = 'exposuretoaltitudeType'

    surfaceintervalbeforealtitudeexposure: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    transportation: ExposuretoaltitudeTypeTransportation | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    dateofflight: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    altitudeofexposure: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    totallengthofexposure: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class GeographyType:
    class Meta:
        name = 'geographyType'

    location: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    address: AddressType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    latitude: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    longitude: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    altitude: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    timezone: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class GuideType(IdType):
    class Meta:
        name = 'guideType'

    link: LinkType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class LightintensityType:
    class Meta:
        name = 'lightintensityType'

    value: GloballightintensityType | None = field(
        default=None,
        metadata={
            'required': True,
        },
    )
    lux: float | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
        },
    )


@dataclass
class MediaType(IdType):
    class Meta:
        name = 'mediaType'

    title: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    objectname: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class NamedType(IdType):
    class Meta:
        name = 'namedType'

    name: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    aliasname: list[object] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class NotesType:
    class Meta:
        name = 'notesType'

    para: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    link: list[LinkType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class PersonalType:
    class Meta:
        name = 'personalType'

    firstname: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    middlename: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    lastname: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    birthname: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    honorific: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    sex: SexType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    birthdate: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    passport: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    membership: Optional['PersonalType.Membership'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    height: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    weight: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    bloodgroup: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    smoking: PersonalTypeSmoking | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    numberofdives: Optional['PersonalType.Numberofdives'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )

    @dataclass
    class Membership:
        organisation: str | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )
        memberid: str | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
            },
        )

    @dataclass
    class Numberofdives:
        startdate: XmlDateTime | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )
        enddate: XmlDateTime | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )
        dives: int | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )


@dataclass
class PriceperdivepackageType(PriceType):
    class Meta:
        name = 'priceperdivepackageType'

    noofdives: object | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
        },
    )


@dataclass
class TankdataType:
    class Meta:
        name = 'tankdataType'

    link: list[LinkType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tankvolume: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tankpressurebegin: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    tankpressureend: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    breathingconsumptionvolume: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class TissueType:
    class Meta:
        name = 'tissueType'

    gas: TissueTypeGas | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )
    number: int | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )
    halflife: float | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )
    a: float | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )
    b: float | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
            'required': True,
        },
    )


@dataclass
class WaypointType:
    class Meta:
        name = 'waypointType'

    alarm: list['WaypointType.Alarm'] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    batterychargecondition: list['WaypointType.Batterychargecondition'] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    cns: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    decostop: list['WaypointType.Decostop'] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    bodytemperature: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    calculatedpo2: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    depth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    divetime: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    heading: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    heartrate: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    otu: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    pulserate: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    remainingbottomtime: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    remainingo2time: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setmarker: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setpo2: Optional['WaypointType.Setpo2'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    switchmix: LinkType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tankpressure: list['WaypointType.Tankpressure'] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    temperature: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    divemode: Optional['WaypointType.Divemode'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    gradientfactor: Optional['WaypointType.Gradientfactor'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    measuredpo2: list['WaypointType.Measuredpo2'] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    nodecotime: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )

    @dataclass
    class Alarm:
        value: AlarmType | None = field(
            default=None,
            metadata={
                'required': True,
            },
        )
        level: float | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
            },
        )

    @dataclass
    class Batterychargecondition:
        value: float | None = field(
            default=None,
            metadata={
                'required': True,
            },
        )
        deviceref: str | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )
        tankref: str | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
            },
        )

    @dataclass
    class Decostop:
        kind: DecostopKind | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )
        decodepth: float | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )
        duration: float | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )

    @dataclass
    class Setpo2:
        value: float | None = field(
            default=None,
            metadata={
                'required': True,
            },
        )
        setby: Setpo2Setby | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )

    @dataclass
    class Tankpressure:
        value: float | None = field(
            default=None,
            metadata={
                'required': True,
            },
        )
        ref: str | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
            },
        )

    @dataclass
    class Divemode:
        type_value: DivemodeType | None = field(
            default=None,
            metadata={
                'name': 'type',
                'type': 'Attribute',
            },
        )

    @dataclass
    class Gradientfactor:
        value: float | None = field(
            default=None,
            metadata={
                'required': True,
            },
        )
        tissue: int | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
            },
        )

    @dataclass
    class Measuredpo2:
        value: float | None = field(
            default=None,
            metadata={
                'required': True,
            },
        )
        ref: str | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
            },
        )


@dataclass
class AccommodationType(NamedType):
    class Meta:
        name = 'accommodationType'

    category: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    address: AddressType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    contact: ContactType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    rating: list[RatingType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class BuehlmannType(IdType):
    class Meta:
        name = 'buehlmannType'

    tissue: list[TissueType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'min_occurs': 1,
        },
    )
    gradientfactorhigh: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    gradientfactorlow: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class CaveType(NamedType):
    class Meta:
        name = 'caveType'

    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class DivebaseType(NamedType):
    class Meta:
        name = 'divebaseType'

    address: AddressType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    contact: ContactType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    priceperdive: PriceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    pricedivepackage: PriceperdivepackageType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    guide: list[GuideType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    rating: list[RatingType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    link: LinkType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class DrugType(SimpleNamedType):
    class Meta:
        name = 'drugType'

    periodicallytaken: DrugTypePeriodicallytaken | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    timespanbeforedive: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class EquipmentconfigurationType(NamedType):
    class Meta:
        name = 'equipmentconfigurationType'

    link: list[LinkType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'min_occurs': 1,
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class ImageType(MediaType):
    class Meta:
        name = 'imageType'

    imagedata: Optional['ImageType.Imagedata'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    height: int | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
        },
    )
    width: int | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
        },
    )
    format: str | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
        },
    )

    @dataclass
    class Imagedata:
        aperture: float | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )
        datetime: XmlDateTime | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )
        exposurecompensation: float | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )
        filmspeed: int | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )
        focallength: float | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )
        focusingdistance: float | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )
        meteringmethod: ImagedataMeteringmethod | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )
        shutterspeed: float | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )


@dataclass
class IndividualType(IdType):
    class Meta:
        name = 'individualType'

    personal: PersonalType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    address: AddressType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    contact: ContactType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class IndoorType(SimpleNamedType):
    class Meta:
        name = 'indoorType'

    address: AddressType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    contact: ContactType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class InputprofileType:
    class Meta:
        name = 'inputprofileType'

    link: list[LinkType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    waypoint: list[WaypointType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'min_occurs': 1,
        },
    )


@dataclass
class InsuranceType:
    class Meta:
        name = 'insuranceType'

    name: object | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    aliasname: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    issuedate: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    validdate: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class ManufacturerType(NamedType):
    class Meta:
        name = 'manufacturerType'

    address: AddressType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    contact: ContactType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class MixType(NamedType):
    class Meta:
        name = 'mixType'

    o2: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    n2: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    he: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    ar: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    h2: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    priceperlitre: PriceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    maximumpo2: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    maximumoperationdepth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    equivalentairdepth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class MixchangeType:
    class Meta:
        name = 'mixchangeType'

    ascent: Optional['MixchangeType.Ascent'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    descent: Optional['MixchangeType.Descent'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )

    @dataclass
    class Ascent:
        waypoint: list[WaypointType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )

    @dataclass
    class Descent:
        waypoint: list[WaypointType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )


@dataclass
class OperatorType(SimpleNamedType):
    class Meta:
        name = 'operatorType'

    address: AddressType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    contact: ContactType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    rating: list[RatingType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class PermitType:
    class Meta:
        name = 'permitType'

    name: object | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    aliasname: list[str] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    region: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    issuedate: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    validdate: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class PlaceType(SimpleNamedType):
    class Meta:
        name = 'placeType'

    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class RgbmType(IdType):
    class Meta:
        name = 'rgbmType'

    tissue: list[TissueType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'min_occurs': 1,
        },
    )


@dataclass
class SamplesType:
    class Meta:
        name = 'samplesType'

    waypoint: list[WaypointType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'min_occurs': 1,
        },
    )


@dataclass
class SetdcdataType:
    class Meta:
        name = 'setdcdataType'

    setdcalarmtime: list[DcalarmWithTimeType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcaltitude: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcbuddydata: DcbuddydataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcdatetime: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcdecomodel: DcdecomodelType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcdivedepthalarm: list[DcalarmWithDepthType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcdivepo2alarm: list[Dcdivepo2AlarmType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcdivesitedata: DcdivesitedataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcdivetimealarm: list[DcdivetimealarmType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcendndtalarm: DcendndtalarmType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcgasdefinitionsdata: DcgasdefinitionsdataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcownerdata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    setdcpassword: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    setdcgeneratordata: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )


@dataclass
class ShopType(NamedType):
    class Meta:
        name = 'shopType'

    address: AddressType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    contact: ContactType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class SpeciesType(IdType):
    class Meta:
        name = 'speciesType'

    trivialname: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    scientificname: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    abundance: Optional['SpeciesType.Abundance'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    sex: SexType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    lifestage: SpeciesTypeLifestage | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    lightintensity: LightintensityType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    age: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    dominance: SpeciesTypeDominance | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    size: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )

    @dataclass
    class Abundance:
        value: int | None = field(
            default=None,
            metadata={
                'required': True,
            },
        )
        quality: AbundanceQuality | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
            },
        )
        occurrence: AbundanceOccurrence | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
            },
        )


@dataclass
class SurfaceintervalType:
    class Meta:
        name = 'surfaceintervalType'

    infinity: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    passedtime: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    wayaltitude: list[WayaltitudeType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    exposuretoaltitude: ExposuretoaltitudeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class VesselType(NamedType):
    class Meta:
        name = 'vesselType'

    shiptype: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    marina: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    address: AddressType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    contact: ContactType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    shipdimension: DimensionType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    rating: list[RatingType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class VpmType(IdType):
    class Meta:
        name = 'vpmType'

    gamma: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    gc: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    lambda_value: float | None = field(
        default=None,
        metadata={
            'name': 'lambda',
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    r0: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tissue: list[TissueType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'min_occurs': 1,
        },
    )


@dataclass
class WreckType(SimpleNamedType):
    class Meta:
        name = 'wreckType'

    shiptype: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    nationality: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    built: BuiltType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    shipdimension: DimensionType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    sunk: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class BaseCalculationType(IdType):
    class Meta:
        name = 'baseCalculationType'

    title: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    link: list[LinkType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    surfaceintervalafterdive: SurfaceintervalType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    surfaceintervalbeforedive: SurfaceintervalType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    density: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    maximumascendingrate: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    output: OutputType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    applicationdata: ApplicationdataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    decomodel: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    deepstoptime: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    mixchange: MixchangeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    inputprofile: InputprofileType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class Business:
    class Meta:
        name = 'business'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    shop: list[ShopType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
        },
    )


@dataclass
class Divecomputercontrol:
    class Meta:
        name = 'divecomputercontrol'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    setdcdata: SetdcdataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    getdcdata: GetdcdataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    divecomputerdump: list[DivecomputerdumpType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
        },
    )


@dataclass
class ExaminationType(IdType):
    class Meta:
        name = 'examinationType'

    datetime: XmlDateTime | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    doctor: IndividualType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    link: LinkType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    examinationresult: ExaminationTypeExaminationresult | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    totallungcapacity: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    vitalcapacity: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class Gasdefinitions:
    class Meta:
        name = 'gasdefinitions'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    mix: list[MixType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'min_occurs': 1,
        },
    )


@dataclass
class Generator(SimpleNamedType):
    class Meta:
        name = 'generator'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    type_value: GeneratorType | None = field(
        default=None,
        metadata={
            'name': 'type',
            'type': 'Element',
        },
    )
    link: LinkType | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    manufacturer: ManufacturerType | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    version: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    datetime: XmlDateTime | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )


@dataclass
class InformationbeforediveType:
    class Meta:
        name = 'informationbeforediveType'

    link: list[LinkType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    divenumber: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    divenumberofday: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    internaldivenumber: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    datetime: XmlDateTime | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    airtemperature: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    surfaceintervalbeforedive: SurfaceintervalType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    altitude: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    equipmentused: Optional['InformationbeforediveType.Equipmentused'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    apparatus: InformationbeforediveTypeApparatus | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    platform: InformationbeforediveTypePlatform | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    purpose: InformationbeforediveTypePurpose | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    stateofrestbeforedive: InformationbeforediveTypeStateofrestbeforedive | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tripmembership: LinkType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    alcoholbeforedive: Optional['InformationbeforediveType.Alcoholbeforedive'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    medicalbeforedive: Optional['InformationbeforediveType.Medicalbeforedive'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    nosuit: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'length': 0,
        },
    )
    price: PriceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    inputprofile: InputprofileType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    plannedprofile: SamplesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    surfacepressure: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )

    @dataclass
    class Equipmentused:
        leadquantity: float | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )
        link: list[LinkType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
            },
        )

    @dataclass
    class Alcoholbeforedive:
        drink: list[DrugType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )

    @dataclass
    class Medicalbeforedive:
        medicine: list[DrugType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )


@dataclass
class InstructorType(IndividualType):
    class Meta:
        name = 'instructorType'

    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class Maker:
    class Meta:
        name = 'maker'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    manufacturer: list[ManufacturerType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
        },
    )


@dataclass
class Mediadata:
    class Meta:
        name = 'mediadata'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    audio: list[MediaType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
        },
    )
    image: list[ImageType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
        },
    )
    video: list[MediaType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
        },
    )


@dataclass
class PurchaseType:
    class Meta:
        name = 'purchaseType'

    datetime: XmlDateTime | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    price: PriceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    shop: ShopType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class SingleLifeFormType:
    class Meta:
        name = 'singleLifeFormType'

    species: list[SpeciesType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class SitedataType:
    class Meta:
        name = 'sitedataType'

    arealength: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    areawidth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    averagevisibility: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    bottom: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    density: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    difficulty: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'min_inclusive': 1,
            'max_inclusive': 10,
        },
    )
    globallightintensity: GloballightintensityType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    maximumdepth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    maximumvisibility: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    minimumdepth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    minimumvisibility: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    terrain: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    wreck: list[WreckType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    cave: CaveType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    indoor: IndoorType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    lake: PlaceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    river: PlaceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    shore: PlaceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class TrippartType(SimpleNamedType):
    class Meta:
        name = 'trippartType'

    dateoftrip: Optional['TrippartType.Dateoftrip'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    geography: GeographyType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    accommodation: AccommodationType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    operator: OperatorType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    vessel: VesselType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    link: LinkType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    relateddives: Optional['TrippartType.Relateddives'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    pricedivepackage: PriceperdivepackageType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    priceperdive: PriceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    rating: list[RatingType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    type_value: object | None = field(
        default=None,
        metadata={
            'name': 'type',
            'type': 'Attribute',
        },
    )

    @dataclass
    class Dateoftrip:
        startdate: XmlDateTime | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )
        enddate: XmlDateTime | None = field(
            default=None,
            metadata={
                'type': 'Attribute',
                'required': True,
            },
        )

    @dataclass
    class Relateddives:
        link: list[LinkType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )


@dataclass
class CertificationType:
    class Meta:
        name = 'certificationType'

    level: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    specialty: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    certificatenumber: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    organization: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    instructor: InstructorType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    issuedate: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    validdate: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class EquipmentPieceType(NamedType):
    class Meta:
        name = 'equipmentPieceType'

    link: LinkType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    manufacturer: ManufacturerType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    model: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    serialnumber: str | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    purchase: PurchaseType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    serviceinterval: int | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    nextservicedate: EncapsulatedDateTimeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class FloraType:
    class Meta:
        name = 'floraType'

    rhodophyceae: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    phaeophyceae: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    chlorophyceae: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    spermatophyta: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    floravarious: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class InvertebrataType:
    class Meta:
        name = 'invertebrataType'

    porifera: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    coelenterata: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    cnidaria: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    ctenophora: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    plathelminthes: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    bryozoa: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    phoronidea: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    ascidiacea: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    echinodermata: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    mollusca: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    crustacea: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    invertebratavarious: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class TableType(BaseCalculationType):
    class Meta:
        name = 'tableType'

    tablescope: TablescopeType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class TripType(NamedType):
    class Meta:
        name = 'tripType'

    rating: list[RatingType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    trippart: list[TrippartType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'min_occurs': 1,
        },
    )


@dataclass
class VertebrataType:
    class Meta:
        name = 'vertebrataType'

    chondrichthyes: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    osteichthyes: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    mammalia: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    amphibia: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    reptilia: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    vertebratavarious: SingleLifeFormType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class CameraType(IdType):
    class Meta:
        name = 'cameraType'

    body: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    lens: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    housing: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    flash: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class Divetrip:
    class Meta:
        name = 'divetrip'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    trip: list[TripType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'min_occurs': 1,
        },
    )


@dataclass
class FaunaType:
    class Meta:
        name = 'faunaType'

    invertebrata: InvertebrataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    vertebrata: VertebrataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class RebreatherType(EquipmentPieceType):
    class Meta:
        name = 'rebreatherType'

    o2sensor: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class SuitType(EquipmentPieceType):
    class Meta:
        name = 'suitType'

    suittype: SuitTypeSuittype | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class Tablegeneration:
    class Meta:
        name = 'tablegeneration'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    calculateprofile: Optional['Tablegeneration.Calculateprofile'] = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    calculatetable: Optional['Tablegeneration.Calculatetable'] = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    calculatebottomtimetable: Optional['Tablegeneration.Calculatebottomtimetable'] = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )

    @dataclass
    class Calculateprofile:
        profile: list[BaseCalculationType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'min_occurs': 1,
            },
        )

    @dataclass
    class Calculatetable:
        table: list[TableType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'min_occurs': 1,
            },
        )

    @dataclass
    class Calculatebottomtimetable:
        bottomtimetable: list[BottomtimetableType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'min_occurs': 1,
            },
        )


@dataclass
class TankType(EquipmentPieceType):
    class Meta:
        name = 'tankType'

    tankmaterial: TankmaterialType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tankvolume: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class VideocameraType(IdType):
    class Meta:
        name = 'videocameraType'

    body: EquipmentPieceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    lens: EquipmentPieceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    housing: EquipmentPieceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    light: EquipmentPieceType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class EcologyType:
    class Meta:
        name = 'ecologyType'

    fauna: FaunaType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    flora: FloraType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class EquipmentType:
    class Meta:
        name = 'equipmentType'

    boots: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    buoyancycontroldevice: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    camera: list[CameraType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    compass: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    compressor: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    divecomputer: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    equipmentconfiguration: list[EquipmentconfigurationType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    fins: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    gloves: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    knife: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    lead: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    light: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    mask: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    rebreather: list[RebreatherType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    regulator: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    scooter: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    suit: list[SuitType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    tank: list[TankType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    variouspieces: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    videocamera: list[VideocameraType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    watch: list[EquipmentPieceType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class ObservationsType(EcologyType):
    class Meta:
        name = 'observationsType'

    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class PersonType(IndividualType):
    class Meta:
        name = 'personType'

    equipment: EquipmentType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    medical: Optional['PersonType.Medical'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    education: Optional['PersonType.Education'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    divepermissions: Optional['PersonType.Divepermissions'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    diveinsurances: Optional['PersonType.Diveinsurances'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )

    @dataclass
    class Medical:
        examination: list[ExaminationType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )

    @dataclass
    class Education:
        certification: list[CertificationType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )

    @dataclass
    class Divepermissions:
        permit: list[PermitType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )

    @dataclass
    class Diveinsurances:
        insurance: list[InsuranceType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )


@dataclass
class SiteType(NamedType):
    class Meta:
        name = 'siteType'

    environment: SiteTypeEnvironment | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    geography: GeographyType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    ecology: EcologyType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    sitedata: SitedataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    rating: list[RatingType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )


@dataclass
class Diver:
    class Meta:
        name = 'diver'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    owner: PersonType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'required': True,
        },
    )
    buddy: list['Diver.Buddy'] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
        },
    )

    @dataclass
    class Buddy(PersonType):
        student: object | None = field(
            default=None,
            metadata={
                'type': 'Element',
            },
        )


@dataclass
class Divesite:
    class Meta:
        name = 'divesite'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    divebase: list[DivebaseType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
        },
    )
    site: list[SiteType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
        },
    )


@dataclass
class InformationafterdiveType:
    class Meta:
        name = 'informationafterdiveType'

    surfaceintervalafterdive: SurfaceintervalType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    lowesttemperature: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    greatestdepth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    visibility: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    current: InformationafterdiveTypeCurrent | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    diveplan: InformationafterdiveTypeDiveplan | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    equipmentmalfunction: InformationafterdiveTypeEquipmentmalfunction | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    pressuredrop: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    problems: InformationafterdiveTypeProblems | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    program: InformationafterdiveTypeProgram | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    thermalcomfort: InformationafterdiveTypeThermalcomfort | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    workload: InformationafterdiveTypeWorkload | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    desaturationtime: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    noflighttime: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    notes: NotesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    rating: RatingType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    anysymptoms: Optional['InformationafterdiveType.Anysymptoms'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    diveduration: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    divetable: InformationafterdiveTypeDivetable | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    globalalarmsgiven: Optional['InformationafterdiveType.Globalalarmsgiven'] = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    highestpo2: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    observations: ObservationsType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    averagedepth: float | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )

    @dataclass
    class Anysymptoms:
        notes: list[NotesType] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )

    @dataclass
    class Globalalarmsgiven:
        globalalarm: list[GlobalalarmsgivenGlobalalarm] = field(
            default_factory=list,
            metadata={
                'type': 'Element',
                'namespace': 'http://www.streit.cc/uddf/3.2/',
                'min_occurs': 1,
            },
        )


@dataclass
class DiveType(IdType):
    class Meta:
        name = 'diveType'

    applicationdata: ApplicationdataType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    informationbeforedive: InformationbeforediveType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )
    tankdata: list[TankdataType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    samples: SamplesType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
        },
    )
    informationafterdive: InformationafterdiveType | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'required': True,
        },
    )


@dataclass
class RepetitiongroupType(IdType):
    class Meta:
        name = 'repetitiongroupType'

    dive: list[DiveType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'namespace': 'http://www.streit.cc/uddf/3.2/',
            'min_occurs': 1,
        },
    )


@dataclass
class Profiledata:
    class Meta:
        name = 'profiledata'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    repetitiongroup: list[RepetitiongroupType] = field(
        default_factory=list,
        metadata={
            'type': 'Element',
            'min_occurs': 1,
        },
    )


@dataclass
class Uddf:
    class Meta:
        name = 'uddf'
        namespace = 'http://www.streit.cc/uddf/3.2/'

    generator: Generator | None = field(
        default=None,
        metadata={
            'type': 'Element',
            'required': True,
        },
    )
    mediadata: Mediadata | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    maker: Maker | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    business: Business | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    diver: Diver | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    divesite: Divesite | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    divetrip: Divetrip | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    gasdefinitions: Gasdefinitions | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    decomodel: Optional['Uddf.Decomodel'] = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    profiledata: Profiledata | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    tablegeneration: Tablegeneration | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    divecomputercontrol: Divecomputercontrol | None = field(
        default=None,
        metadata={
            'type': 'Element',
        },
    )
    version: object | None = field(
        default=None,
        metadata={
            'type': 'Attribute',
        },
    )

    @dataclass
    class Decomodel:
        buehlmann: BuehlmannType | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'required': True,
            },
        )
        rgbm: RgbmType | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'required': True,
            },
        )
        vpm: VpmType | None = field(
            default=None,
            metadata={
                'type': 'Element',
                'required': True,
            },
        )
