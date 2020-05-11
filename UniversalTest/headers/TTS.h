#ifndef _SPEECHLIB_H
#define _SPEECHLIB_H

#include <cviauto.h>

#ifdef __cplusplus
    extern "C" {
#endif
/* NICDBLD_BEGIN> Type Library Specific Types */

enum SpeechLibEnum_SpeechDataKeyLocation
{
	SpeechLibConst_SDKLDefaultLocation = 0,
	SpeechLibConst_SDKLCurrentUser = 1,
	SpeechLibConst_SDKLLocalMachine = 2,
	SpeechLibConst_SDKLCurrentConfig = 5,
	_SpeechLib_SpeechDataKeyLocationForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPDATAKEYLOCATION
{
	SpeechLibConst_SPDKL_DefaultLocation = 0,
	SpeechLibConst_SPDKL_CurrentUser = 1,
	SpeechLibConst_SPDKL_LocalMachine = 2,
	SpeechLibConst_SPDKL_CurrentConfig = 5,
	_SpeechLib_SPDATAKEYLOCATIONForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechTokenContext
{
	SpeechLibConst_STCInprocServer = 1,
	SpeechLibConst_STCInprocHandler = 2,
	SpeechLibConst_STCLocalServer = 4,
	SpeechLibConst_STCRemoteServer = 16,
	SpeechLibConst_STCAll = 23,
	_SpeechLib_SpeechTokenContextForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechTokenShellFolder
{
	SpeechLibConst_STSF_AppData = 26,
	SpeechLibConst_STSF_LocalAppData = 28,
	SpeechLibConst_STSF_CommonAppData = 35,
	SpeechLibConst_STSF_FlagCreate = 32768,
	_SpeechLib_SpeechTokenShellFolderForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechStreamSeekPositionType
{
	SpeechLibConst_SSSPTRelativeToStart = 0,
	SpeechLibConst_SSSPTRelativeToCurrentPosition = 1,
	SpeechLibConst_SSSPTRelativeToEnd = 2,
	_SpeechLib_SpeechStreamSeekPositionTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechAudioState
{
	SpeechLibConst_SASClosed = 0,
	SpeechLibConst_SASStop = 1,
	SpeechLibConst_SASPause = 2,
	SpeechLibConst_SASRun = 3,
	_SpeechLib_SpeechAudioStateForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum__SPAUDIOSTATE
{
	SpeechLibConst_SPAS_CLOSED = 0,
	SpeechLibConst_SPAS_STOP = 1,
	SpeechLibConst_SPAS_PAUSE = 2,
	SpeechLibConst_SPAS_RUN = 3,
	_SpeechLib__SPAUDIOSTATEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechVoiceEvents
{
	SpeechLibConst_SVEStartInputStream = 2,
	SpeechLibConst_SVEEndInputStream = 4,
	SpeechLibConst_SVEVoiceChange = 8,
	SpeechLibConst_SVEBookmark = 16,
	SpeechLibConst_SVEWordBoundary = 32,
	SpeechLibConst_SVEPhoneme = 64,
	SpeechLibConst_SVESentenceBoundary = 128,
	SpeechLibConst_SVEViseme = 256,
	SpeechLibConst_SVEAudioLevel = 512,
	SpeechLibConst_SVEPrivate = 32768,
	SpeechLibConst_SVEAllEvents = 33790,
	_SpeechLib_SpeechVoiceEventsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechVoicePriority
{
	SpeechLibConst_SVPNormal = 0,
	SpeechLibConst_SVPAlert = 1,
	SpeechLibConst_SVPOver = 2,
	_SpeechLib_SpeechVoicePriorityForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechVoiceSpeakFlags
{
	SpeechLibConst_SVSFDefault = 0,
	SpeechLibConst_SVSFlagsAsync = 1,
	SpeechLibConst_SVSFPurgeBeforeSpeak = 2,
	SpeechLibConst_SVSFIsFilename = 4,
	SpeechLibConst_SVSFIsXML = 8,
	SpeechLibConst_SVSFIsNotXML = 16,
	SpeechLibConst_SVSFPersistXML = 32,
	SpeechLibConst_SVSFNLPSpeakPunc = 64,
	SpeechLibConst_SVSFParseSapi = 128,
	SpeechLibConst_SVSFParseSsml = 256,
	SpeechLibConst_SVSFParseAutodetect = 0,
	SpeechLibConst_SVSFNLPMask = 64,
	SpeechLibConst_SVSFParseMask = 384,
	SpeechLibConst_SVSFVoiceMask = 511,
	SpeechLibConst_SVSFUnusedFlags = -512,
	_SpeechLib_SpeechVoiceSpeakFlagsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPVPRIORITY
{
	SpeechLibConst_SPVPRI_NORMAL = 0,
	SpeechLibConst_SPVPRI_ALERT = 1,
	SpeechLibConst_SPVPRI_OVER = 2,
	_SpeechLib_SPVPRIORITYForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPEVENTENUM
{
	SpeechLibConst_SPEI_UNDEFINED = 0,
	SpeechLibConst_SPEI_START_INPUT_STREAM = 1,
	SpeechLibConst_SPEI_END_INPUT_STREAM = 2,
	SpeechLibConst_SPEI_VOICE_CHANGE = 3,
	SpeechLibConst_SPEI_TTS_BOOKMARK = 4,
	SpeechLibConst_SPEI_WORD_BOUNDARY = 5,
	SpeechLibConst_SPEI_PHONEME = 6,
	SpeechLibConst_SPEI_SENTENCE_BOUNDARY = 7,
	SpeechLibConst_SPEI_VISEME = 8,
	SpeechLibConst_SPEI_TTS_AUDIO_LEVEL = 9,
	SpeechLibConst_SPEI_TTS_PRIVATE = 15,
	SpeechLibConst_SPEI_MIN_TTS = 1,
	SpeechLibConst_SPEI_MAX_TTS = 15,
	SpeechLibConst_SPEI_END_SR_STREAM = 34,
	SpeechLibConst_SPEI_SOUND_START = 35,
	SpeechLibConst_SPEI_SOUND_END = 36,
	SpeechLibConst_SPEI_PHRASE_START = 37,
	SpeechLibConst_SPEI_RECOGNITION = 38,
	SpeechLibConst_SPEI_HYPOTHESIS = 39,
	SpeechLibConst_SPEI_SR_BOOKMARK = 40,
	SpeechLibConst_SPEI_PROPERTY_NUM_CHANGE = 41,
	SpeechLibConst_SPEI_PROPERTY_STRING_CHANGE = 42,
	SpeechLibConst_SPEI_FALSE_RECOGNITION = 43,
	SpeechLibConst_SPEI_INTERFERENCE = 44,
	SpeechLibConst_SPEI_REQUEST_UI = 45,
	SpeechLibConst_SPEI_RECO_STATE_CHANGE = 46,
	SpeechLibConst_SPEI_ADAPTATION = 47,
	SpeechLibConst_SPEI_START_SR_STREAM = 48,
	SpeechLibConst_SPEI_RECO_OTHER_CONTEXT = 49,
	SpeechLibConst_SPEI_SR_AUDIO_LEVEL = 50,
	SpeechLibConst_SPEI_SR_RETAINEDAUDIO = 51,
	SpeechLibConst_SPEI_SR_PRIVATE = 52,
	SpeechLibConst_SPEI_ACTIVE_CATEGORY_CHANGED = 53,
	SpeechLibConst_SPEI_RESERVED5 = 54,
	SpeechLibConst_SPEI_RESERVED6 = 55,
	SpeechLibConst_SPEI_MIN_SR = 34,
	SpeechLibConst_SPEI_MAX_SR = 55,
	SpeechLibConst_SPEI_RESERVED1 = 30,
	SpeechLibConst_SPEI_RESERVED2 = 33,
	SpeechLibConst_SPEI_RESERVED3 = 63,
	_SpeechLib_SPEVENTENUMForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechVisemeFeature
{
	SpeechLibConst_SVF_None = 0,
	SpeechLibConst_SVF_Stressed = 1,
	SpeechLibConst_SVF_Emphasis = 2,
	_SpeechLib_SpeechVisemeFeatureForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechVisemeType
{
	SpeechLibConst_SVP_0 = 0,
	SpeechLibConst_SVP_1 = 1,
	SpeechLibConst_SVP_2 = 2,
	SpeechLibConst_SVP_3 = 3,
	SpeechLibConst_SVP_4 = 4,
	SpeechLibConst_SVP_5 = 5,
	SpeechLibConst_SVP_6 = 6,
	SpeechLibConst_SVP_7 = 7,
	SpeechLibConst_SVP_8 = 8,
	SpeechLibConst_SVP_9 = 9,
	SpeechLibConst_SVP_10 = 10,
	SpeechLibConst_SVP_11 = 11,
	SpeechLibConst_SVP_12 = 12,
	SpeechLibConst_SVP_13 = 13,
	SpeechLibConst_SVP_14 = 14,
	SpeechLibConst_SVP_15 = 15,
	SpeechLibConst_SVP_16 = 16,
	SpeechLibConst_SVP_17 = 17,
	SpeechLibConst_SVP_18 = 18,
	SpeechLibConst_SVP_19 = 19,
	SpeechLibConst_SVP_20 = 20,
	SpeechLibConst_SVP_21 = 21,
	_SpeechLib_SpeechVisemeTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechInterference
{
	SpeechLibConst_SINone = 0,
	SpeechLibConst_SINoise = 1,
	SpeechLibConst_SINoSignal = 2,
	SpeechLibConst_SITooLoud = 3,
	SpeechLibConst_SITooQuiet = 4,
	SpeechLibConst_SITooFast = 5,
	SpeechLibConst_SITooSlow = 6,
	_SpeechLib_SpeechInterferenceForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechRecoEvents
{
	SpeechLibConst_SREStreamEnd = 1,
	SpeechLibConst_SRESoundStart = 2,
	SpeechLibConst_SRESoundEnd = 4,
	SpeechLibConst_SREPhraseStart = 8,
	SpeechLibConst_SRERecognition = 16,
	SpeechLibConst_SREHypothesis = 32,
	SpeechLibConst_SREBookmark = 64,
	SpeechLibConst_SREPropertyNumChange = 128,
	SpeechLibConst_SREPropertyStringChange = 256,
	SpeechLibConst_SREFalseRecognition = 512,
	SpeechLibConst_SREInterference = 1024,
	SpeechLibConst_SRERequestUI = 2048,
	SpeechLibConst_SREStateChange = 4096,
	SpeechLibConst_SREAdaptation = 8192,
	SpeechLibConst_SREStreamStart = 16384,
	SpeechLibConst_SRERecoOtherContext = 32768,
	SpeechLibConst_SREAudioLevel = 65536,
	SpeechLibConst_SREPrivate = 262144,
	SpeechLibConst_SREAllEvents = 393215,
	_SpeechLib_SpeechRecoEventsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechRecoContextState
{
	SpeechLibConst_SRCS_Disabled = 0,
	SpeechLibConst_SRCS_Enabled = 1,
	_SpeechLib_SpeechRecoContextStateForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechRetainedAudioOptions
{
	SpeechLibConst_SRAONone = 0,
	SpeechLibConst_SRAORetainAudio = 1,
	_SpeechLib_SpeechRetainedAudioOptionsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechBookmarkOptions
{
	SpeechLibConst_SBONone = 0,
	SpeechLibConst_SBOPause = 1,
	_SpeechLib_SpeechBookmarkOptionsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPAUDIOOPTIONS
{
	SpeechLibConst_SPAO_NONE = 0,
	SpeechLibConst_SPAO_RETAIN_AUDIO = 1,
	_SpeechLib_SPAUDIOOPTIONSForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPBOOKMARKOPTIONS
{
	SpeechLibConst_SPBO_NONE = 0,
	SpeechLibConst_SPBO_PAUSE = 1,
	SpeechLibConst_SPBO_AHEAD = 2,
	SpeechLibConst_SPBO_TIME_UNITS = 4,
	_SpeechLib_SPBOOKMARKOPTIONSForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPCONTEXTSTATE
{
	SpeechLibConst_SPCS_DISABLED = 0,
	SpeechLibConst_SPCS_ENABLED = 1,
	_SpeechLib_SPCONTEXTSTATEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechRecognitionType
{
	SpeechLibConst_SRTStandard = 0,
	SpeechLibConst_SRTAutopause = 1,
	SpeechLibConst_SRTEmulated = 2,
	SpeechLibConst_SRTSMLTimeout = 4,
	SpeechLibConst_SRTExtendableParse = 8,
	SpeechLibConst_SRTReSent = 16,
	_SpeechLib_SpeechRecognitionTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechRecognizerState
{
	SpeechLibConst_SRSInactive = 0,
	SpeechLibConst_SRSActive = 1,
	SpeechLibConst_SRSActiveAlways = 2,
	SpeechLibConst_SRSInactiveWithPurge = 3,
	_SpeechLib_SpeechRecognizerStateForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechFormatType
{
	SpeechLibConst_SFTInput = 0,
	SpeechLibConst_SFTSREngine = 1,
	_SpeechLib_SpeechFormatTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPRECOSTATE
{
	SpeechLibConst_SPRST_INACTIVE = 0,
	SpeechLibConst_SPRST_ACTIVE = 1,
	SpeechLibConst_SPRST_ACTIVE_ALWAYS = 2,
	SpeechLibConst_SPRST_INACTIVE_WITH_PURGE = 3,
	SpeechLibConst_SPRST_NUM_STATES = 4,
	_SpeechLib_SPRECOSTATEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPWAVEFORMATTYPE
{
	SpeechLibConst_SPWF_INPUT = 0,
	SpeechLibConst_SPWF_SRENGINE = 1,
	_SpeechLib_SPWAVEFORMATTYPEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPCATEGORYTYPE
{
	SpeechLibConst_SPCT_COMMAND = 0,
	SpeechLibConst_SPCT_DICTATION = 1,
	SpeechLibConst_SPCT_SLEEP = 2,
	SpeechLibConst_SPCT_SUB_COMMAND = 3,
	SpeechLibConst_SPCT_SUB_DICTATION = 4,
	_SpeechLib_SPCATEGORYTYPEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechLexiconType
{
	SpeechLibConst_SLTUser = 1,
	SpeechLibConst_SLTApp = 2,
	_SpeechLib_SpeechLexiconTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechPartOfSpeech
{
	SpeechLibConst_SPSNotOverriden = -1,
	SpeechLibConst_SPSUnknown = 0,
	SpeechLibConst_SPSNoun = 4096,
	SpeechLibConst_SPSVerb = 8192,
	SpeechLibConst_SPSModifier = 12288,
	SpeechLibConst_SPSFunction = 16384,
	SpeechLibConst_SPSInterjection = 20480,
	SpeechLibConst_SPSLMA = 28672,
	SpeechLibConst_SPSSuppressWord = 61440,
	_SpeechLib_SpeechPartOfSpeechForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechAudioFormatType
{
	SpeechLibConst_SAFTDefault = -1,
	SpeechLibConst_SAFTNoAssignedFormat = 0,
	SpeechLibConst_SAFTText = 1,
	SpeechLibConst_SAFTNonStandardFormat = 2,
	SpeechLibConst_SAFTExtendedAudioFormat = 3,
	SpeechLibConst_SAFT8kHz8BitMono = 4,
	SpeechLibConst_SAFT8kHz8BitStereo = 5,
	SpeechLibConst_SAFT8kHz16BitMono = 6,
	SpeechLibConst_SAFT8kHz16BitStereo = 7,
	SpeechLibConst_SAFT11kHz8BitMono = 8,
	SpeechLibConst_SAFT11kHz8BitStereo = 9,
	SpeechLibConst_SAFT11kHz16BitMono = 10,
	SpeechLibConst_SAFT11kHz16BitStereo = 11,
	SpeechLibConst_SAFT12kHz8BitMono = 12,
	SpeechLibConst_SAFT12kHz8BitStereo = 13,
	SpeechLibConst_SAFT12kHz16BitMono = 14,
	SpeechLibConst_SAFT12kHz16BitStereo = 15,
	SpeechLibConst_SAFT16kHz8BitMono = 16,
	SpeechLibConst_SAFT16kHz8BitStereo = 17,
	SpeechLibConst_SAFT16kHz16BitMono = 18,
	SpeechLibConst_SAFT16kHz16BitStereo = 19,
	SpeechLibConst_SAFT22kHz8BitMono = 20,
	SpeechLibConst_SAFT22kHz8BitStereo = 21,
	SpeechLibConst_SAFT22kHz16BitMono = 22,
	SpeechLibConst_SAFT22kHz16BitStereo = 23,
	SpeechLibConst_SAFT24kHz8BitMono = 24,
	SpeechLibConst_SAFT24kHz8BitStereo = 25,
	SpeechLibConst_SAFT24kHz16BitMono = 26,
	SpeechLibConst_SAFT24kHz16BitStereo = 27,
	SpeechLibConst_SAFT32kHz8BitMono = 28,
	SpeechLibConst_SAFT32kHz8BitStereo = 29,
	SpeechLibConst_SAFT32kHz16BitMono = 30,
	SpeechLibConst_SAFT32kHz16BitStereo = 31,
	SpeechLibConst_SAFT44kHz8BitMono = 32,
	SpeechLibConst_SAFT44kHz8BitStereo = 33,
	SpeechLibConst_SAFT44kHz16BitMono = 34,
	SpeechLibConst_SAFT44kHz16BitStereo = 35,
	SpeechLibConst_SAFT48kHz8BitMono = 36,
	SpeechLibConst_SAFT48kHz8BitStereo = 37,
	SpeechLibConst_SAFT48kHz16BitMono = 38,
	SpeechLibConst_SAFT48kHz16BitStereo = 39,
	SpeechLibConst_SAFTTrueSpeech_8kHz1BitMono = 40,
	SpeechLibConst_SAFTCCITT_ALaw_8kHzMono = 41,
	SpeechLibConst_SAFTCCITT_ALaw_8kHzStereo = 42,
	SpeechLibConst_SAFTCCITT_ALaw_11kHzMono = 43,
	SpeechLibConst_SAFTCCITT_ALaw_11kHzStereo = 44,
	SpeechLibConst_SAFTCCITT_ALaw_22kHzMono = 45,
	SpeechLibConst_SAFTCCITT_ALaw_22kHzStereo = 46,
	SpeechLibConst_SAFTCCITT_ALaw_44kHzMono = 47,
	SpeechLibConst_SAFTCCITT_ALaw_44kHzStereo = 48,
	SpeechLibConst_SAFTCCITT_uLaw_8kHzMono = 49,
	SpeechLibConst_SAFTCCITT_uLaw_8kHzStereo = 50,
	SpeechLibConst_SAFTCCITT_uLaw_11kHzMono = 51,
	SpeechLibConst_SAFTCCITT_uLaw_11kHzStereo = 52,
	SpeechLibConst_SAFTCCITT_uLaw_22kHzMono = 53,
	SpeechLibConst_SAFTCCITT_uLaw_22kHzStereo = 54,
	SpeechLibConst_SAFTCCITT_uLaw_44kHzMono = 55,
	SpeechLibConst_SAFTCCITT_uLaw_44kHzStereo = 56,
	SpeechLibConst_SAFTADPCM_8kHzMono = 57,
	SpeechLibConst_SAFTADPCM_8kHzStereo = 58,
	SpeechLibConst_SAFTADPCM_11kHzMono = 59,
	SpeechLibConst_SAFTADPCM_11kHzStereo = 60,
	SpeechLibConst_SAFTADPCM_22kHzMono = 61,
	SpeechLibConst_SAFTADPCM_22kHzStereo = 62,
	SpeechLibConst_SAFTADPCM_44kHzMono = 63,
	SpeechLibConst_SAFTADPCM_44kHzStereo = 64,
	SpeechLibConst_SAFTGSM610_8kHzMono = 65,
	SpeechLibConst_SAFTGSM610_11kHzMono = 66,
	SpeechLibConst_SAFTGSM610_22kHzMono = 67,
	SpeechLibConst_SAFTGSM610_44kHzMono = 68,
	_SpeechLib_SpeechAudioFormatTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechStreamFileMode
{
	SpeechLibConst_SSFMOpenForRead = 0,
	SpeechLibConst_SSFMOpenReadWrite = 1,
	SpeechLibConst_SSFMCreate = 2,
	SpeechLibConst_SSFMCreateForWrite = 3,
	_SpeechLib_SpeechStreamFileModeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechRunState
{
	SpeechLibConst_SRSEDone = 1,
	SpeechLibConst_SRSEIsSpeaking = 2,
	_SpeechLib_SpeechRunStateForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechGrammarState
{
	SpeechLibConst_SGSEnabled = 1,
	SpeechLibConst_SGSDisabled = 0,
	SpeechLibConst_SGSExclusive = 3,
	_SpeechLib_SpeechGrammarStateForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechLoadOption
{
	SpeechLibConst_SLOStatic = 0,
	SpeechLibConst_SLODynamic = 1,
	_SpeechLib_SpeechLoadOptionForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechRuleState
{
	SpeechLibConst_SGDSInactive = 0,
	SpeechLibConst_SGDSActive = 1,
	SpeechLibConst_SGDSActiveWithAutoPause = 3,
	SpeechLibConst_SGDSActiveUserDelimited = 4,
	_SpeechLib_SpeechRuleStateForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechWordPronounceable
{
	SpeechLibConst_SWPUnknownWordUnpronounceable = 0,
	SpeechLibConst_SWPUnknownWordPronounceable = 1,
	SpeechLibConst_SWPKnownWordPronounceable = 2,
	_SpeechLib_SpeechWordPronounceableForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechRuleAttributes
{
	SpeechLibConst_SRATopLevel = 1,
	SpeechLibConst_SRADefaultToActive = 2,
	SpeechLibConst_SRAExport = 4,
	SpeechLibConst_SRAImport = 8,
	SpeechLibConst_SRAInterpreter = 16,
	SpeechLibConst_SRADynamic = 32,
	SpeechLibConst_SRARoot = 64,
	_SpeechLib_SpeechRuleAttributesForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechGrammarWordType
{
	SpeechLibConst_SGDisplay = 0,
	SpeechLibConst_SGLexical = 1,
	SpeechLibConst_SGPronounciation = 2,
	SpeechLibConst_SGLexicalNoSpecialChars = 3,
	_SpeechLib_SpeechGrammarWordTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechSpecialTransitionType
{
	SpeechLibConst_SSTTWildcard = 1,
	SpeechLibConst_SSTTDictation = 2,
	SpeechLibConst_SSTTTextBuffer = 3,
	_SpeechLib_SpeechSpecialTransitionTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechGrammarRuleStateTransitionType
{
	SpeechLibConst_SGRSTTEpsilon = 0,
	SpeechLibConst_SGRSTTWord = 1,
	SpeechLibConst_SGRSTTRule = 2,
	SpeechLibConst_SGRSTTDictation = 3,
	SpeechLibConst_SGRSTTWildcard = 4,
	SpeechLibConst_SGRSTTTextBuffer = 5,
	_SpeechLib_SpeechGrammarRuleStateTransitionTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechDiscardType
{
	SpeechLibConst_SDTProperty = 1,
	SpeechLibConst_SDTReplacement = 2,
	SpeechLibConst_SDTRule = 4,
	SpeechLibConst_SDTDisplayText = 8,
	SpeechLibConst_SDTLexicalForm = 16,
	SpeechLibConst_SDTPronunciation = 32,
	SpeechLibConst_SDTAudio = 64,
	SpeechLibConst_SDTAlternates = 128,
	SpeechLibConst_SDTAll = 255,
	_SpeechLib_SpeechDiscardTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechDisplayAttributes
{
	SpeechLibConst_SDA_No_Trailing_Space = 0,
	SpeechLibConst_SDA_One_Trailing_Space = 2,
	SpeechLibConst_SDA_Two_Trailing_Spaces = 4,
	SpeechLibConst_SDA_Consume_Leading_Spaces = 8,
	_SpeechLib_SpeechDisplayAttributesForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechEngineConfidence
{
	SpeechLibConst_SECLowConfidence = -1,
	SpeechLibConst_SECNormalConfidence = 0,
	SpeechLibConst_SECHighConfidence = 1,
	_SpeechLib_SpeechEngineConfidenceForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechWordType
{
	SpeechLibConst_SWTAdded = 1,
	SpeechLibConst_SWTDeleted = 2,
	_SpeechLib_SpeechWordTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPXMLRESULTOPTIONS
{
	SpeechLibConst_SPXRO_SML = 0,
	SpeechLibConst_SPXRO_Alternates_SML = 1,
	_SpeechLib_SPXMLRESULTOPTIONSForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPRULESTATE
{
	SpeechLibConst_SPRS_INACTIVE = 0,
	SpeechLibConst_SPRS_ACTIVE = 1,
	SpeechLibConst_SPRS_ACTIVE_WITH_AUTO_PAUSE = 3,
	SpeechLibConst_SPRS_ACTIVE_USER_DELIMITED = 4,
	_SpeechLib_SPRULESTATEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPGRAMMARSTATE
{
	SpeechLibConst_SPGS_DISABLED = 0,
	SpeechLibConst_SPGS_ENABLED = 1,
	SpeechLibConst_SPGS_EXCLUSIVE = 3,
	_SpeechLib_SPGRAMMARSTATEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechDataKey
{
	SpeechLibConst_DISPID_SDKSetBinaryValue = 1,
	SpeechLibConst_DISPID_SDKGetBinaryValue = 2,
	SpeechLibConst_DISPID_SDKSetStringValue = 3,
	SpeechLibConst_DISPID_SDKGetStringValue = 4,
	SpeechLibConst_DISPID_SDKSetLongValue = 5,
	SpeechLibConst_DISPID_SDKGetlongValue = 6,
	SpeechLibConst_DISPID_SDKOpenKey = 7,
	SpeechLibConst_DISPID_SDKCreateKey = 8,
	SpeechLibConst_DISPID_SDKDeleteKey = 9,
	SpeechLibConst_DISPID_SDKDeleteValue = 10,
	SpeechLibConst_DISPID_SDKEnumKeys = 11,
	SpeechLibConst_DISPID_SDKEnumValues = 12,
	_SpeechLib_DISPID_SpeechDataKeyForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechObjectToken
{
	SpeechLibConst_DISPID_SOTId = 1,
	SpeechLibConst_DISPID_SOTDataKey = 2,
	SpeechLibConst_DISPID_SOTCategory = 3,
	SpeechLibConst_DISPID_SOTGetDescription = 4,
	SpeechLibConst_DISPID_SOTSetId = 5,
	SpeechLibConst_DISPID_SOTGetAttribute = 6,
	SpeechLibConst_DISPID_SOTCreateInstance = 7,
	SpeechLibConst_DISPID_SOTRemove = 8,
	SpeechLibConst_DISPID_SOTGetStorageFileName = 9,
	SpeechLibConst_DISPID_SOTRemoveStorageFileName = 10,
	SpeechLibConst_DISPID_SOTIsUISupported = 11,
	SpeechLibConst_DISPID_SOTDisplayUI = 12,
	SpeechLibConst_DISPID_SOTMatchesAttributes = 13,
	_SpeechLib_DISPID_SpeechObjectTokenForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechObjectTokens
{
	SpeechLibConst_DISPID_SOTsCount = 1,
	SpeechLibConst_DISPID_SOTsItem = 0,
	SpeechLibConst_DISPID_SOTs_NewEnum = -4,
	_SpeechLib_DISPID_SpeechObjectTokensForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechObjectTokenCategory
{
	SpeechLibConst_DISPID_SOTCId = 1,
	SpeechLibConst_DISPID_SOTCDefault = 2,
	SpeechLibConst_DISPID_SOTCSetId = 3,
	SpeechLibConst_DISPID_SOTCGetDataKey = 4,
	SpeechLibConst_DISPID_SOTCEnumerateTokens = 5,
	_SpeechLib_DISPID_SpeechObjectTokenCategoryForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechAudioFormat
{
	SpeechLibConst_DISPID_SAFType = 1,
	SpeechLibConst_DISPID_SAFGuid = 2,
	SpeechLibConst_DISPID_SAFGetWaveFormatEx = 3,
	SpeechLibConst_DISPID_SAFSetWaveFormatEx = 4,
	_SpeechLib_DISPID_SpeechAudioFormatForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechBaseStream
{
	SpeechLibConst_DISPID_SBSFormat = 1,
	SpeechLibConst_DISPID_SBSRead = 2,
	SpeechLibConst_DISPID_SBSWrite = 3,
	SpeechLibConst_DISPID_SBSSeek = 4,
	_SpeechLib_DISPID_SpeechBaseStreamForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechAudio
{
	SpeechLibConst_DISPID_SAStatus = 200,
	SpeechLibConst_DISPID_SABufferInfo = 201,
	SpeechLibConst_DISPID_SADefaultFormat = 202,
	SpeechLibConst_DISPID_SAVolume = 203,
	SpeechLibConst_DISPID_SABufferNotifySize = 204,
	SpeechLibConst_DISPID_SAEventHandle = 205,
	SpeechLibConst_DISPID_SASetState = 206,
	_SpeechLib_DISPID_SpeechAudioForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechMMSysAudio
{
	SpeechLibConst_DISPID_SMSADeviceId = 300,
	SpeechLibConst_DISPID_SMSALineId = 301,
	SpeechLibConst_DISPID_SMSAMMHandle = 302,
	_SpeechLib_DISPID_SpeechMMSysAudioForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechFileStream
{
	SpeechLibConst_DISPID_SFSOpen = 100,
	SpeechLibConst_DISPID_SFSClose = 101,
	_SpeechLib_DISPID_SpeechFileStreamForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechCustomStream
{
	SpeechLibConst_DISPID_SCSBaseStream = 100,
	_SpeechLib_DISPID_SpeechCustomStreamForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechMemoryStream
{
	SpeechLibConst_DISPID_SMSSetData = 100,
	SpeechLibConst_DISPID_SMSGetData = 101,
	_SpeechLib_DISPID_SpeechMemoryStreamForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechAudioStatus
{
	SpeechLibConst_DISPID_SASFreeBufferSpace = 1,
	SpeechLibConst_DISPID_SASNonBlockingIO = 2,
	SpeechLibConst_DISPID_SASState = 3,
	SpeechLibConst_DISPID_SASCurrentSeekPosition = 4,
	SpeechLibConst_DISPID_SASCurrentDevicePosition = 5,
	_SpeechLib_DISPID_SpeechAudioStatusForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechAudioBufferInfo
{
	SpeechLibConst_DISPID_SABIMinNotification = 1,
	SpeechLibConst_DISPID_SABIBufferSize = 2,
	SpeechLibConst_DISPID_SABIEventBias = 3,
	_SpeechLib_DISPID_SpeechAudioBufferInfoForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechWaveFormatEx
{
	SpeechLibConst_DISPID_SWFEFormatTag = 1,
	SpeechLibConst_DISPID_SWFEChannels = 2,
	SpeechLibConst_DISPID_SWFESamplesPerSec = 3,
	SpeechLibConst_DISPID_SWFEAvgBytesPerSec = 4,
	SpeechLibConst_DISPID_SWFEBlockAlign = 5,
	SpeechLibConst_DISPID_SWFEBitsPerSample = 6,
	SpeechLibConst_DISPID_SWFEExtraData = 7,
	_SpeechLib_DISPID_SpeechWaveFormatExForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechVoice
{
	SpeechLibConst_DISPID_SVStatus = 1,
	SpeechLibConst_DISPID_SVVoice = 2,
	SpeechLibConst_DISPID_SVAudioOutput = 3,
	SpeechLibConst_DISPID_SVAudioOutputStream = 4,
	SpeechLibConst_DISPID_SVRate = 5,
	SpeechLibConst_DISPID_SVVolume = 6,
	SpeechLibConst_DISPID_SVAllowAudioOuputFormatChangesOnNextSet = 7,
	SpeechLibConst_DISPID_SVEventInterests = 8,
	SpeechLibConst_DISPID_SVPriority = 9,
	SpeechLibConst_DISPID_SVAlertBoundary = 10,
	SpeechLibConst_DISPID_SVSyncronousSpeakTimeout = 11,
	SpeechLibConst_DISPID_SVSpeak = 12,
	SpeechLibConst_DISPID_SVSpeakStream = 13,
	SpeechLibConst_DISPID_SVPause = 14,
	SpeechLibConst_DISPID_SVResume = 15,
	SpeechLibConst_DISPID_SVSkip = 16,
	SpeechLibConst_DISPID_SVGetVoices = 17,
	SpeechLibConst_DISPID_SVGetAudioOutputs = 18,
	SpeechLibConst_DISPID_SVWaitUntilDone = 19,
	SpeechLibConst_DISPID_SVSpeakCompleteEvent = 20,
	SpeechLibConst_DISPID_SVIsUISupported = 21,
	SpeechLibConst_DISPID_SVDisplayUI = 22,
	_SpeechLib_DISPID_SpeechVoiceForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechVoiceStatus
{
	SpeechLibConst_DISPID_SVSCurrentStreamNumber = 1,
	SpeechLibConst_DISPID_SVSLastStreamNumberQueued = 2,
	SpeechLibConst_DISPID_SVSLastResult = 3,
	SpeechLibConst_DISPID_SVSRunningState = 4,
	SpeechLibConst_DISPID_SVSInputWordPosition = 5,
	SpeechLibConst_DISPID_SVSInputWordLength = 6,
	SpeechLibConst_DISPID_SVSInputSentencePosition = 7,
	SpeechLibConst_DISPID_SVSInputSentenceLength = 8,
	SpeechLibConst_DISPID_SVSLastBookmark = 9,
	SpeechLibConst_DISPID_SVSLastBookmarkId = 10,
	SpeechLibConst_DISPID_SVSPhonemeId = 11,
	SpeechLibConst_DISPID_SVSVisemeId = 12,
	_SpeechLib_DISPID_SpeechVoiceStatusForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechVoiceEvent
{
	SpeechLibConst_DISPID_SVEStreamStart = 1,
	SpeechLibConst_DISPID_SVEStreamEnd = 2,
	SpeechLibConst_DISPID_SVEVoiceChange = 3,
	SpeechLibConst_DISPID_SVEBookmark = 4,
	SpeechLibConst_DISPID_SVEWord = 5,
	SpeechLibConst_DISPID_SVEPhoneme = 6,
	SpeechLibConst_DISPID_SVESentenceBoundary = 7,
	SpeechLibConst_DISPID_SVEViseme = 8,
	SpeechLibConst_DISPID_SVEAudioLevel = 9,
	SpeechLibConst_DISPID_SVEEnginePrivate = 10,
	_SpeechLib_DISPID_SpeechVoiceEventForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechRecognizer
{
	SpeechLibConst_DISPID_SRRecognizer = 1,
	SpeechLibConst_DISPID_SRAllowAudioInputFormatChangesOnNextSet = 2,
	SpeechLibConst_DISPID_SRAudioInput = 3,
	SpeechLibConst_DISPID_SRAudioInputStream = 4,
	SpeechLibConst_DISPID_SRIsShared = 5,
	SpeechLibConst_DISPID_SRState = 6,
	SpeechLibConst_DISPID_SRStatus = 7,
	SpeechLibConst_DISPID_SRProfile = 8,
	SpeechLibConst_DISPID_SREmulateRecognition = 9,
	SpeechLibConst_DISPID_SRCreateRecoContext = 10,
	SpeechLibConst_DISPID_SRGetFormat = 11,
	SpeechLibConst_DISPID_SRSetPropertyNumber = 12,
	SpeechLibConst_DISPID_SRGetPropertyNumber = 13,
	SpeechLibConst_DISPID_SRSetPropertyString = 14,
	SpeechLibConst_DISPID_SRGetPropertyString = 15,
	SpeechLibConst_DISPID_SRIsUISupported = 16,
	SpeechLibConst_DISPID_SRDisplayUI = 17,
	SpeechLibConst_DISPID_SRGetRecognizers = 18,
	SpeechLibConst_DISPID_SVGetAudioInputs = 19,
	SpeechLibConst_DISPID_SVGetProfiles = 20,
	_SpeechLib_DISPID_SpeechRecognizerForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SpeechEmulationCompareFlags
{
	SpeechLibConst_SECFIgnoreCase = 1,
	SpeechLibConst_SECFIgnoreKanaType = 65536,
	SpeechLibConst_SECFIgnoreWidth = 131072,
	SpeechLibConst_SECFNoSpecialChars = 536870912,
	SpeechLibConst_SECFEmulateResult = 1073741824,
	SpeechLibConst_SECFDefault = 196609,
	_SpeechLib_SpeechEmulationCompareFlagsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechRecognizerStatus
{
	SpeechLibConst_DISPID_SRSAudioStatus = 1,
	SpeechLibConst_DISPID_SRSCurrentStreamPosition = 2,
	SpeechLibConst_DISPID_SRSCurrentStreamNumber = 3,
	SpeechLibConst_DISPID_SRSNumberOfActiveRules = 4,
	SpeechLibConst_DISPID_SRSClsidEngine = 5,
	SpeechLibConst_DISPID_SRSSupportedLanguages = 6,
	_SpeechLib_DISPID_SpeechRecognizerStatusForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechRecoContext
{
	SpeechLibConst_DISPID_SRCRecognizer = 1,
	SpeechLibConst_DISPID_SRCAudioInInterferenceStatus = 2,
	SpeechLibConst_DISPID_SRCRequestedUIType = 3,
	SpeechLibConst_DISPID_SRCVoice = 4,
	SpeechLibConst_DISPID_SRAllowVoiceFormatMatchingOnNextSet = 5,
	SpeechLibConst_DISPID_SRCVoicePurgeEvent = 6,
	SpeechLibConst_DISPID_SRCEventInterests = 7,
	SpeechLibConst_DISPID_SRCCmdMaxAlternates = 8,
	SpeechLibConst_DISPID_SRCState = 9,
	SpeechLibConst_DISPID_SRCRetainedAudio = 10,
	SpeechLibConst_DISPID_SRCRetainedAudioFormat = 11,
	SpeechLibConst_DISPID_SRCPause = 12,
	SpeechLibConst_DISPID_SRCResume = 13,
	SpeechLibConst_DISPID_SRCCreateGrammar = 14,
	SpeechLibConst_DISPID_SRCCreateResultFromMemory = 15,
	SpeechLibConst_DISPID_SRCBookmark = 16,
	SpeechLibConst_DISPID_SRCSetAdaptationData = 17,
	_SpeechLib_DISPID_SpeechRecoContextForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPIDSPRG
{
	SpeechLibConst_DISPID_SRGId = 1,
	SpeechLibConst_DISPID_SRGRecoContext = 2,
	SpeechLibConst_DISPID_SRGState = 3,
	SpeechLibConst_DISPID_SRGRules = 4,
	SpeechLibConst_DISPID_SRGReset = 5,
	SpeechLibConst_DISPID_SRGCommit = 6,
	SpeechLibConst_DISPID_SRGCmdLoadFromFile = 7,
	SpeechLibConst_DISPID_SRGCmdLoadFromObject = 8,
	SpeechLibConst_DISPID_SRGCmdLoadFromResource = 9,
	SpeechLibConst_DISPID_SRGCmdLoadFromMemory = 10,
	SpeechLibConst_DISPID_SRGCmdLoadFromProprietaryGrammar = 11,
	SpeechLibConst_DISPID_SRGCmdSetRuleState = 12,
	SpeechLibConst_DISPID_SRGCmdSetRuleIdState = 13,
	SpeechLibConst_DISPID_SRGDictationLoad = 14,
	SpeechLibConst_DISPID_SRGDictationUnload = 15,
	SpeechLibConst_DISPID_SRGDictationSetState = 16,
	SpeechLibConst_DISPID_SRGSetWordSequenceData = 17,
	SpeechLibConst_DISPID_SRGSetTextSelection = 18,
	SpeechLibConst_DISPID_SRGIsPronounceable = 19,
	_SpeechLib_DISPIDSPRGForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechRecoContextEvents
{
	SpeechLibConst_DISPID_SRCEStartStream = 1,
	SpeechLibConst_DISPID_SRCEEndStream = 2,
	SpeechLibConst_DISPID_SRCEBookmark = 3,
	SpeechLibConst_DISPID_SRCESoundStart = 4,
	SpeechLibConst_DISPID_SRCESoundEnd = 5,
	SpeechLibConst_DISPID_SRCEPhraseStart = 6,
	SpeechLibConst_DISPID_SRCERecognition = 7,
	SpeechLibConst_DISPID_SRCEHypothesis = 8,
	SpeechLibConst_DISPID_SRCEPropertyNumberChange = 9,
	SpeechLibConst_DISPID_SRCEPropertyStringChange = 10,
	SpeechLibConst_DISPID_SRCEFalseRecognition = 11,
	SpeechLibConst_DISPID_SRCEInterference = 12,
	SpeechLibConst_DISPID_SRCERequestUI = 13,
	SpeechLibConst_DISPID_SRCERecognizerStateChange = 14,
	SpeechLibConst_DISPID_SRCEAdaptation = 15,
	SpeechLibConst_DISPID_SRCERecognitionForOtherContext = 16,
	SpeechLibConst_DISPID_SRCEAudioLevel = 17,
	SpeechLibConst_DISPID_SRCEEnginePrivate = 18,
	_SpeechLib_DISPID_SpeechRecoContextEventsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechGrammarRule
{
	SpeechLibConst_DISPID_SGRAttributes = 1,
	SpeechLibConst_DISPID_SGRInitialState = 2,
	SpeechLibConst_DISPID_SGRName = 3,
	SpeechLibConst_DISPID_SGRId = 4,
	SpeechLibConst_DISPID_SGRClear = 5,
	SpeechLibConst_DISPID_SGRAddResource = 6,
	SpeechLibConst_DISPID_SGRAddState = 7,
	_SpeechLib_DISPID_SpeechGrammarRuleForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechGrammarRules
{
	SpeechLibConst_DISPID_SGRsCount = 1,
	SpeechLibConst_DISPID_SGRsDynamic = 2,
	SpeechLibConst_DISPID_SGRsAdd = 3,
	SpeechLibConst_DISPID_SGRsCommit = 4,
	SpeechLibConst_DISPID_SGRsCommitAndSave = 5,
	SpeechLibConst_DISPID_SGRsFindRule = 6,
	SpeechLibConst_DISPID_SGRsItem = 0,
	SpeechLibConst_DISPID_SGRs_NewEnum = -4,
	_SpeechLib_DISPID_SpeechGrammarRulesForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechGrammarRuleState
{
	SpeechLibConst_DISPID_SGRSRule = 1,
	SpeechLibConst_DISPID_SGRSTransitions = 2,
	SpeechLibConst_DISPID_SGRSAddWordTransition = 3,
	SpeechLibConst_DISPID_SGRSAddRuleTransition = 4,
	SpeechLibConst_DISPID_SGRSAddSpecialTransition = 5,
	_SpeechLib_DISPID_SpeechGrammarRuleStateForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechGrammarRuleStateTransitions
{
	SpeechLibConst_DISPID_SGRSTsCount = 1,
	SpeechLibConst_DISPID_SGRSTsItem = 0,
	SpeechLibConst_DISPID_SGRSTs_NewEnum = -4,
	_SpeechLib_DISPID_SpeechGrammarRuleStateTransitionsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechGrammarRuleStateTransition
{
	SpeechLibConst_DISPID_SGRSTType = 1,
	SpeechLibConst_DISPID_SGRSTText = 2,
	SpeechLibConst_DISPID_SGRSTRule = 3,
	SpeechLibConst_DISPID_SGRSTWeight = 4,
	SpeechLibConst_DISPID_SGRSTPropertyName = 5,
	SpeechLibConst_DISPID_SGRSTPropertyId = 6,
	SpeechLibConst_DISPID_SGRSTPropertyValue = 7,
	SpeechLibConst_DISPID_SGRSTNextState = 8,
	_SpeechLib_DISPID_SpeechGrammarRuleStateTransitionForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPIDSPTSI
{
	SpeechLibConst_DISPIDSPTSI_ActiveOffset = 1,
	SpeechLibConst_DISPIDSPTSI_ActiveLength = 2,
	SpeechLibConst_DISPIDSPTSI_SelectionOffset = 3,
	SpeechLibConst_DISPIDSPTSI_SelectionLength = 4,
	_SpeechLib_DISPIDSPTSIForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechRecoResult
{
	SpeechLibConst_DISPID_SRRRecoContext = 1,
	SpeechLibConst_DISPID_SRRTimes = 2,
	SpeechLibConst_DISPID_SRRAudioFormat = 3,
	SpeechLibConst_DISPID_SRRPhraseInfo = 4,
	SpeechLibConst_DISPID_SRRAlternates = 5,
	SpeechLibConst_DISPID_SRRAudio = 6,
	SpeechLibConst_DISPID_SRRSpeakAudio = 7,
	SpeechLibConst_DISPID_SRRSaveToMemory = 8,
	SpeechLibConst_DISPID_SRRDiscardResultInfo = 9,
	_SpeechLib_DISPID_SpeechRecoResultForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechXMLRecoResult
{
	SpeechLibConst_DISPID_SRRGetXMLResult = 10,
	SpeechLibConst_DISPID_SRRGetXMLErrorInfo = 11,
	_SpeechLib_DISPID_SpeechXMLRecoResultForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechRecoResult2
{
	SpeechLibConst_DISPID_SRRSetTextFeedback = 12,
	_SpeechLib_DISPID_SpeechRecoResult2ForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseBuilder
{
	SpeechLibConst_DISPID_SPPBRestorePhraseFromMemory = 1,
	_SpeechLib_DISPID_SpeechPhraseBuilderForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechRecoResultTimes
{
	SpeechLibConst_DISPID_SRRTStreamTime = 1,
	SpeechLibConst_DISPID_SRRTLength = 2,
	SpeechLibConst_DISPID_SRRTTickCount = 3,
	SpeechLibConst_DISPID_SRRTOffsetFromStart = 4,
	_SpeechLib_DISPID_SpeechRecoResultTimesForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseAlternate
{
	SpeechLibConst_DISPID_SPARecoResult = 1,
	SpeechLibConst_DISPID_SPAStartElementInResult = 2,
	SpeechLibConst_DISPID_SPANumberOfElementsInResult = 3,
	SpeechLibConst_DISPID_SPAPhraseInfo = 4,
	SpeechLibConst_DISPID_SPACommit = 5,
	_SpeechLib_DISPID_SpeechPhraseAlternateForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseAlternates
{
	SpeechLibConst_DISPID_SPAsCount = 1,
	SpeechLibConst_DISPID_SPAsItem = 0,
	SpeechLibConst_DISPID_SPAs_NewEnum = -4,
	_SpeechLib_DISPID_SpeechPhraseAlternatesForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseInfo
{
	SpeechLibConst_DISPID_SPILanguageId = 1,
	SpeechLibConst_DISPID_SPIGrammarId = 2,
	SpeechLibConst_DISPID_SPIStartTime = 3,
	SpeechLibConst_DISPID_SPIAudioStreamPosition = 4,
	SpeechLibConst_DISPID_SPIAudioSizeBytes = 5,
	SpeechLibConst_DISPID_SPIRetainedSizeBytes = 6,
	SpeechLibConst_DISPID_SPIAudioSizeTime = 7,
	SpeechLibConst_DISPID_SPIRule = 8,
	SpeechLibConst_DISPID_SPIProperties = 9,
	SpeechLibConst_DISPID_SPIElements = 10,
	SpeechLibConst_DISPID_SPIReplacements = 11,
	SpeechLibConst_DISPID_SPIEngineId = 12,
	SpeechLibConst_DISPID_SPIEnginePrivateData = 13,
	SpeechLibConst_DISPID_SPISaveToMemory = 14,
	SpeechLibConst_DISPID_SPIGetText = 15,
	SpeechLibConst_DISPID_SPIGetDisplayAttributes = 16,
	_SpeechLib_DISPID_SpeechPhraseInfoForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseElement
{
	SpeechLibConst_DISPID_SPEAudioTimeOffset = 1,
	SpeechLibConst_DISPID_SPEAudioSizeTime = 2,
	SpeechLibConst_DISPID_SPEAudioStreamOffset = 3,
	SpeechLibConst_DISPID_SPEAudioSizeBytes = 4,
	SpeechLibConst_DISPID_SPERetainedStreamOffset = 5,
	SpeechLibConst_DISPID_SPERetainedSizeBytes = 6,
	SpeechLibConst_DISPID_SPEDisplayText = 7,
	SpeechLibConst_DISPID_SPELexicalForm = 8,
	SpeechLibConst_DISPID_SPEPronunciation = 9,
	SpeechLibConst_DISPID_SPEDisplayAttributes = 10,
	SpeechLibConst_DISPID_SPERequiredConfidence = 11,
	SpeechLibConst_DISPID_SPEActualConfidence = 12,
	SpeechLibConst_DISPID_SPEEngineConfidence = 13,
	_SpeechLib_DISPID_SpeechPhraseElementForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseElements
{
	SpeechLibConst_DISPID_SPEsCount = 1,
	SpeechLibConst_DISPID_SPEsItem = 0,
	SpeechLibConst_DISPID_SPEs_NewEnum = -4,
	_SpeechLib_DISPID_SpeechPhraseElementsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseReplacement
{
	SpeechLibConst_DISPID_SPRDisplayAttributes = 1,
	SpeechLibConst_DISPID_SPRText = 2,
	SpeechLibConst_DISPID_SPRFirstElement = 3,
	SpeechLibConst_DISPID_SPRNumberOfElements = 4,
	_SpeechLib_DISPID_SpeechPhraseReplacementForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseReplacements
{
	SpeechLibConst_DISPID_SPRsCount = 1,
	SpeechLibConst_DISPID_SPRsItem = 0,
	SpeechLibConst_DISPID_SPRs_NewEnum = -4,
	_SpeechLib_DISPID_SpeechPhraseReplacementsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseProperty
{
	SpeechLibConst_DISPID_SPPName = 1,
	SpeechLibConst_DISPID_SPPId = 2,
	SpeechLibConst_DISPID_SPPValue = 3,
	SpeechLibConst_DISPID_SPPFirstElement = 4,
	SpeechLibConst_DISPID_SPPNumberOfElements = 5,
	SpeechLibConst_DISPID_SPPEngineConfidence = 6,
	SpeechLibConst_DISPID_SPPConfidence = 7,
	SpeechLibConst_DISPID_SPPParent = 8,
	SpeechLibConst_DISPID_SPPChildren = 9,
	_SpeechLib_DISPID_SpeechPhrasePropertyForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseProperties
{
	SpeechLibConst_DISPID_SPPsCount = 1,
	SpeechLibConst_DISPID_SPPsItem = 0,
	SpeechLibConst_DISPID_SPPs_NewEnum = -4,
	_SpeechLib_DISPID_SpeechPhrasePropertiesForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseRule
{
	SpeechLibConst_DISPID_SPRuleName = 1,
	SpeechLibConst_DISPID_SPRuleId = 2,
	SpeechLibConst_DISPID_SPRuleFirstElement = 3,
	SpeechLibConst_DISPID_SPRuleNumberOfElements = 4,
	SpeechLibConst_DISPID_SPRuleParent = 5,
	SpeechLibConst_DISPID_SPRuleChildren = 6,
	SpeechLibConst_DISPID_SPRuleConfidence = 7,
	SpeechLibConst_DISPID_SPRuleEngineConfidence = 8,
	_SpeechLib_DISPID_SpeechPhraseRuleForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhraseRules
{
	SpeechLibConst_DISPID_SPRulesCount = 1,
	SpeechLibConst_DISPID_SPRulesItem = 0,
	SpeechLibConst_DISPID_SPRules_NewEnum = -4,
	_SpeechLib_DISPID_SpeechPhraseRulesForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechLexicon
{
	SpeechLibConst_DISPID_SLGenerationId = 1,
	SpeechLibConst_DISPID_SLGetWords = 2,
	SpeechLibConst_DISPID_SLAddPronunciation = 3,
	SpeechLibConst_DISPID_SLAddPronunciationByPhoneIds = 4,
	SpeechLibConst_DISPID_SLRemovePronunciation = 5,
	SpeechLibConst_DISPID_SLRemovePronunciationByPhoneIds = 6,
	SpeechLibConst_DISPID_SLGetPronunciations = 7,
	SpeechLibConst_DISPID_SLGetGenerationChange = 8,
	_SpeechLib_DISPID_SpeechLexiconForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechLexiconWords
{
	SpeechLibConst_DISPID_SLWsCount = 1,
	SpeechLibConst_DISPID_SLWsItem = 0,
	SpeechLibConst_DISPID_SLWs_NewEnum = -4,
	_SpeechLib_DISPID_SpeechLexiconWordsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechLexiconWord
{
	SpeechLibConst_DISPID_SLWLangId = 1,
	SpeechLibConst_DISPID_SLWType = 2,
	SpeechLibConst_DISPID_SLWWord = 3,
	SpeechLibConst_DISPID_SLWPronunciations = 4,
	_SpeechLib_DISPID_SpeechLexiconWordForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechLexiconProns
{
	SpeechLibConst_DISPID_SLPsCount = 1,
	SpeechLibConst_DISPID_SLPsItem = 0,
	SpeechLibConst_DISPID_SLPs_NewEnum = -4,
	_SpeechLib_DISPID_SpeechLexiconPronsForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechLexiconPronunciation
{
	SpeechLibConst_DISPID_SLPType = 1,
	SpeechLibConst_DISPID_SLPLangId = 2,
	SpeechLibConst_DISPID_SLPPartOfSpeech = 3,
	SpeechLibConst_DISPID_SLPPhoneIds = 4,
	SpeechLibConst_DISPID_SLPSymbolic = 5,
	_SpeechLib_DISPID_SpeechLexiconPronunciationForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_DISPID_SpeechPhoneConverter
{
	SpeechLibConst_DISPID_SPCLangId = 1,
	SpeechLibConst_DISPID_SPCPhoneToId = 2,
	SpeechLibConst_DISPID_SPCIdToPhone = 3,
	_SpeechLib_DISPID_SpeechPhoneConverterForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPFILEMODE
{
	SpeechLibConst_SPFM_OPEN_READONLY = 0,
	SpeechLibConst_SPFM_OPEN_READWRITE = 1,
	SpeechLibConst_SPFM_CREATE = 2,
	SpeechLibConst_SPFM_CREATE_ALWAYS = 3,
	SpeechLibConst_SPFM_NUM_MODES = 4,
	_SpeechLib_SPFILEMODEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPVISEMES
{
	SpeechLibConst_SP_VISEME_0 = 0,
	SpeechLibConst_SP_VISEME_1 = 1,
	SpeechLibConst_SP_VISEME_2 = 2,
	SpeechLibConst_SP_VISEME_3 = 3,
	SpeechLibConst_SP_VISEME_4 = 4,
	SpeechLibConst_SP_VISEME_5 = 5,
	SpeechLibConst_SP_VISEME_6 = 6,
	SpeechLibConst_SP_VISEME_7 = 7,
	SpeechLibConst_SP_VISEME_8 = 8,
	SpeechLibConst_SP_VISEME_9 = 9,
	SpeechLibConst_SP_VISEME_10 = 10,
	SpeechLibConst_SP_VISEME_11 = 11,
	SpeechLibConst_SP_VISEME_12 = 12,
	SpeechLibConst_SP_VISEME_13 = 13,
	SpeechLibConst_SP_VISEME_14 = 14,
	SpeechLibConst_SP_VISEME_15 = 15,
	SpeechLibConst_SP_VISEME_16 = 16,
	SpeechLibConst_SP_VISEME_17 = 17,
	SpeechLibConst_SP_VISEME_18 = 18,
	SpeechLibConst_SP_VISEME_19 = 19,
	SpeechLibConst_SP_VISEME_20 = 20,
	SpeechLibConst_SP_VISEME_21 = 21,
	_SpeechLib_SPVISEMESForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPSEMANTICFORMAT
{
	SpeechLibConst_SPSMF_SAPI_PROPERTIES = 0,
	SpeechLibConst_SPSMF_SRGS_SEMANTICINTERPRETATION_MS = 1,
	SpeechLibConst_SPSMF_SRGS_SAPIPROPERTIES = 2,
	SpeechLibConst_SPSMF_UPS = 4,
	SpeechLibConst_SPSMF_SRGS_SEMANTICINTERPRETATION_W3C = 8,
	_SpeechLib_SPSEMANTICFORMATForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPGRAMMARWORDTYPE
{
	SpeechLibConst_SPWT_DISPLAY = 0,
	SpeechLibConst_SPWT_LEXICAL = 1,
	SpeechLibConst_SPWT_PRONUNCIATION = 2,
	SpeechLibConst_SPWT_LEXICAL_NO_SPECIAL_CHARS = 3,
	_SpeechLib_SPGRAMMARWORDTYPEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPLOADOPTIONS
{
	SpeechLibConst_SPLO_STATIC = 0,
	SpeechLibConst_SPLO_DYNAMIC = 1,
	_SpeechLib_SPLOADOPTIONSForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPWORDPRONOUNCEABLE
{
	SpeechLibConst_SPWP_UNKNOWN_WORD_UNPRONOUNCEABLE = 0,
	SpeechLibConst_SPWP_UNKNOWN_WORD_PRONOUNCEABLE = 1,
	SpeechLibConst_SPWP_KNOWN_WORD_PRONOUNCEABLE = 2,
	_SpeechLib_SPWORDPRONOUNCEABLEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPINTERFERENCE
{
	SpeechLibConst_SPINTERFERENCE_NONE = 0,
	SpeechLibConst_SPINTERFERENCE_NOISE = 1,
	SpeechLibConst_SPINTERFERENCE_NOSIGNAL = 2,
	SpeechLibConst_SPINTERFERENCE_TOOLOUD = 3,
	SpeechLibConst_SPINTERFERENCE_TOOQUIET = 4,
	SpeechLibConst_SPINTERFERENCE_TOOFAST = 5,
	SpeechLibConst_SPINTERFERENCE_TOOSLOW = 6,
	SpeechLibConst_SPINTERFERENCE_LATENCY_WARNING = 7,
	SpeechLibConst_SPINTERFERENCE_LATENCY_TRUNCATE_BEGIN = 8,
	SpeechLibConst_SPINTERFERENCE_LATENCY_TRUNCATE_END = 9,
	_SpeechLib_SPINTERFERENCEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPADAPTATIONRELEVANCE
{
	SpeechLibConst_SPAR_Unknown = 0,
	SpeechLibConst_SPAR_Low = 1,
	SpeechLibConst_SPAR_Medium = 2,
	SpeechLibConst_SPAR_High = 3,
	_SpeechLib_SPADAPTATIONRELEVANCEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPLEXICONTYPE
{
	SpeechLibConst_eLEXTYPE_USER = 1,
	SpeechLibConst_eLEXTYPE_APP = 2,
	SpeechLibConst_eLEXTYPE_VENDORLEXICON = 4,
	SpeechLibConst_eLEXTYPE_LETTERTOSOUND = 8,
	SpeechLibConst_eLEXTYPE_MORPHOLOGY = 16,
	SpeechLibConst_eLEXTYPE_RESERVED4 = 32,
	SpeechLibConst_eLEXTYPE_USER_SHORTCUT = 64,
	SpeechLibConst_eLEXTYPE_RESERVED6 = 128,
	SpeechLibConst_eLEXTYPE_RESERVED7 = 256,
	SpeechLibConst_eLEXTYPE_RESERVED8 = 512,
	SpeechLibConst_eLEXTYPE_RESERVED9 = 1024,
	SpeechLibConst_eLEXTYPE_RESERVED10 = 2048,
	SpeechLibConst_eLEXTYPE_PRIVATE1 = 4096,
	SpeechLibConst_eLEXTYPE_PRIVATE2 = 8192,
	SpeechLibConst_eLEXTYPE_PRIVATE3 = 16384,
	SpeechLibConst_eLEXTYPE_PRIVATE4 = 32768,
	SpeechLibConst_eLEXTYPE_PRIVATE5 = 65536,
	SpeechLibConst_eLEXTYPE_PRIVATE6 = 131072,
	SpeechLibConst_eLEXTYPE_PRIVATE7 = 262144,
	SpeechLibConst_eLEXTYPE_PRIVATE8 = 524288,
	SpeechLibConst_eLEXTYPE_PRIVATE9 = 1048576,
	SpeechLibConst_eLEXTYPE_PRIVATE10 = 2097152,
	SpeechLibConst_eLEXTYPE_PRIVATE11 = 4194304,
	SpeechLibConst_eLEXTYPE_PRIVATE12 = 8388608,
	SpeechLibConst_eLEXTYPE_PRIVATE13 = 16777216,
	SpeechLibConst_eLEXTYPE_PRIVATE14 = 33554432,
	SpeechLibConst_eLEXTYPE_PRIVATE15 = 67108864,
	SpeechLibConst_eLEXTYPE_PRIVATE16 = 134217728,
	SpeechLibConst_eLEXTYPE_PRIVATE17 = 268435456,
	SpeechLibConst_eLEXTYPE_PRIVATE18 = 536870912,
	SpeechLibConst_eLEXTYPE_PRIVATE19 = 1073741824,
	SpeechLibConst_eLEXTYPE_PRIVATE20 = -2147483648,
	_SpeechLib_SPLEXICONTYPEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPPARTOFSPEECH
{
	SpeechLibConst_SPPS_NotOverriden = -1,
	SpeechLibConst_SPPS_Unknown = 0,
	SpeechLibConst_SPPS_Noun = 4096,
	SpeechLibConst_SPPS_Verb = 8192,
	SpeechLibConst_SPPS_Modifier = 12288,
	SpeechLibConst_SPPS_Function = 16384,
	SpeechLibConst_SPPS_Interjection = 20480,
	SpeechLibConst_SPPS_Noncontent = 24576,
	SpeechLibConst_SPPS_LMA = 28672,
	SpeechLibConst_SPPS_SuppressWord = 61440,
	_SpeechLib_SPPARTOFSPEECHForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPWORDTYPE
{
	SpeechLibConst_eWORDTYPE_ADDED = 1,
	SpeechLibConst_eWORDTYPE_DELETED = 2,
	_SpeechLib_SPWORDTYPEForceSizeToFourBytes = 0xFFFFFFFF
};
enum SpeechLibEnum_SPSHORTCUTTYPE
{
	SpeechLibConst_SPSHT_NotOverriden = -1,
	SpeechLibConst_SPSHT_Unknown = 0,
	SpeechLibConst_SPSHT_EMAIL = 4096,
	SpeechLibConst_SPSHT_OTHER = 8192,
	SpeechLibConst_SPPS_RESERVED1 = 12288,
	SpeechLibConst_SPPS_RESERVED2 = 16384,
	SpeechLibConst_SPPS_RESERVED3 = 20480,
	SpeechLibConst_SPPS_RESERVED4 = 61440,
	_SpeechLib_SPSHORTCUTTYPEForceSizeToFourBytes = 0xFFFFFFFF
};
typedef CAObjHandle SpeechLibObj_ISpeechDataKey;
typedef CAObjHandle SpeechLibObj_ISpeechObjectTokens;
typedef CAObjHandle SpeechLibObj_ISpDataKey;
typedef CAObjHandle SpeechLibObj_ISpeechObjectTokenCategory;
typedef CAObjHandle SpeechLibObj_ISpObjectTokenCategory;
typedef CAObjHandle SpeechLibObj_IStream;
typedef CAObjHandle SpeechLibObj_ISpStreamFormat;
typedef CAObjHandle SpeechLibObj_ISpObjectToken;
typedef CAObjHandle SpeechLibObj_IEnumSpObjectTokens;
typedef CAObjHandle SpeechLibObj_ISpeechAudioFormat;
typedef CAObjHandle SpeechLibObj_ISpeechAudioStatus;
typedef CAObjHandle SpeechLibObj_ISpeechAudioBufferInfo;
typedef CAObjHandle SpeechLibObj_ISpNotifySink;
typedef long SpeechLibType_SPAUDIOSTATE;
typedef CAObjHandle SpeechLibObj_ISpeechVoiceStatus;
typedef CAObjHandle SpeechLibObj_ISpeechObjectToken;
typedef CAObjHandle SpeechLibObj_ISpeechBaseStream;
typedef CAObjHandle SpeechLibObj_ISpeechRecognizer;
typedef CAObjHandle SpeechLibObj_ISpeechVoice;
typedef CAObjHandle SpeechLibObj_ISpeechRecoGrammar;
typedef CAObjHandle SpeechLibObj_ISpeechRecoResult;
typedef CAObjHandle SpeechLibObj_ISpRecognizer;
typedef CAObjHandle SpeechLibObj_ISpVoice;
typedef CAObjHandle SpeechLibObj_ISpeechRecognizerStatus;
typedef CAObjHandle SpeechLibObj_ISpeechRecoContext;
typedef CAObjHandle SpeechLibObj_ISpRecoContext;
typedef long SpeechLibType_SPSTREAMFORMATTYPE;
typedef CAObjHandle SpeechLibObj_ISpPhrase;
typedef CAObjHandle SpeechLibObj_ISpRecoCategory;
typedef CAObjHandle SpeechLibObj_ISpeechLexiconWords;
typedef CAObjHandle SpeechLibObj_ISpeechLexiconPronunciations;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseInfo;
typedef CAObjHandle SpeechLibObj_ISpeechWaveFormatEx;
typedef CAObjHandle SpeechLibObj_ISpeechGrammarRules;
typedef CAObjHandle SpeechLibObj_ISpeechTextSelectionInformation;
typedef CAObjHandle SpeechLibObj_ISpeechGrammarRule;
typedef CAObjHandle SpeechLibObj_ISpeechGrammarRuleState;
typedef CAObjHandle SpeechLibObj_ISpeechGrammarRuleStateTransitions;
typedef CAObjHandle SpeechLibObj_ISpeechGrammarRuleStateTransition;
typedef CAObjHandle SpeechLibObj_ISpeechRecoResultTimes;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseAlternates;
typedef CAObjHandle SpeechLibObj_ISpeechMemoryStream;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseRule;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseProperties;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseElements;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseReplacements;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseRules;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseProperty;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseElement;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseReplacement;
typedef CAObjHandle SpeechLibObj_ISpeechPhraseAlternate;
typedef CAObjHandle SpeechLibObj_ISpeechLexiconWord;
typedef CAObjHandle SpeechLibObj_ISpeechLexiconPronunciation;
typedef CAObjHandle SpeechLibObj_ISpPhraseAlt;
typedef CAObjHandle SpeechLibObj_ISpeechResourceLoader;
typedef CAObjHandle SpeechLibObj_IInternetSecurityManager;
typedef CAObjHandle SpeechLibObj_IInternetSecurityMgrSite;
typedef CAObjHandle SpeechLibObj_IEnumString;
typedef unsigned long SpeechLibType_UINT_PTR;
typedef long SpeechLibType_LONG_PTR;
typedef unsigned long SpeechLibType_ULONG_PTR;
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnStartStream_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 long  streamNumber,
                                                                                 VARIANT  streamPosition);
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnEndStream_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               long  streamNumber,
                                                                               VARIANT  streamPosition);
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnVoiceChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 long  streamNumber,
                                                                                 VARIANT  streamPosition,
                                                                                 SpeechLibObj_ISpeechObjectToken  voiceObjectToken);
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnBookmark_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  streamNumber,
                                                                              VARIANT  streamPosition,
                                                                              char *bookmark,
                                                                              long  bookmarkId);
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnWord_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          long  streamNumber,
                                                                          VARIANT  streamPosition,
                                                                          long  characterPosition,
                                                                          long  length);
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnSentence_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  streamNumber,
                                                                              VARIANT  streamPosition,
                                                                              long  characterPosition,
                                                                              long  length);
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnPhoneme_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             long  streamNumber,
                                                                             VARIANT  streamPosition,
                                                                             long  duration,
                                                                             short  nextPhoneId,
                                                                             enum SpeechLibEnum_SpeechVisemeFeature  feature,
                                                                             short  currentPhoneId);
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnViseme_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            long  streamNumber,
                                                                            VARIANT  streamPosition,
                                                                            long  duration,
                                                                            enum SpeechLibEnum_SpeechVisemeType  nextVisemeId,
                                                                            enum SpeechLibEnum_SpeechVisemeFeature  feature,
                                                                            enum SpeechLibEnum_SpeechVisemeType  currentVisemeId);
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnAudioLevel_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                long  streamNumber,
                                                                                VARIANT  streamPosition,
                                                                                long  audioLevel);
typedef HRESULT (CVICALLBACK *_ISpeechVoiceEventsRegOnEnginePrivate_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                   void *caCallbackData,
                                                                                   long  streamNumber,
                                                                                   long  streamPosition,
                                                                                   VARIANT  engineData);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnStartStream_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                       void *caCallbackData,
                                                                                       long  streamNumber,
                                                                                       VARIANT  streamPosition);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnEndStream_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                     void *caCallbackData,
                                                                                     long  streamNumber,
                                                                                     VARIANT  streamPosition,
                                                                                     VBOOL  streamReleased);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnBookmark_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                    void *caCallbackData,
                                                                                    long  streamNumber,
                                                                                    VARIANT  streamPosition,
                                                                                    VARIANT  bookmarkId,
                                                                                    enum SpeechLibEnum_SpeechBookmarkOptions  options);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnSoundStart_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                      void *caCallbackData,
                                                                                      long  streamNumber,
                                                                                      VARIANT  streamPosition);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnSoundEnd_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                    void *caCallbackData,
                                                                                    long  streamNumber,
                                                                                    VARIANT  streamPosition);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnPhraseStart_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                       void *caCallbackData,
                                                                                       long  streamNumber,
                                                                                       VARIANT  streamPosition);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnRecognition_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                       void *caCallbackData,
                                                                                       long  streamNumber,
                                                                                       VARIANT  streamPosition,
                                                                                       enum SpeechLibEnum_SpeechRecognitionType  recognitionType,
                                                                                       SpeechLibObj_ISpeechRecoResult  result);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnHypothesis_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                      void *caCallbackData,
                                                                                      long  streamNumber,
                                                                                      VARIANT  streamPosition,
                                                                                      SpeechLibObj_ISpeechRecoResult  result);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnPropertyNumberChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                                void *caCallbackData,
                                                                                                long  streamNumber,
                                                                                                VARIANT  streamPosition,
                                                                                                char *propertyName,
                                                                                                long  newNumberValue);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnPropertyStringChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                                void *caCallbackData,
                                                                                                long  streamNumber,
                                                                                                VARIANT  streamPosition,
                                                                                                char *propertyName,
                                                                                                char *newStringValue);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnFalseRecognition_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                            void *caCallbackData,
                                                                                            long  streamNumber,
                                                                                            VARIANT  streamPosition,
                                                                                            SpeechLibObj_ISpeechRecoResult  result);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnInterference_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                        void *caCallbackData,
                                                                                        long  streamNumber,
                                                                                        VARIANT  streamPosition,
                                                                                        enum SpeechLibEnum_SpeechInterference  interference);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnRequestUI_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                     void *caCallbackData,
                                                                                     long  streamNumber,
                                                                                     VARIANT  streamPosition,
                                                                                     char *UIType);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnRecognizerStateChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                                 void *caCallbackData,
                                                                                                 long  streamNumber,
                                                                                                 VARIANT  streamPosition,
                                                                                                 enum SpeechLibEnum_SpeechRecognizerState  newState);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnAdaptation_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                      void *caCallbackData,
                                                                                      long  streamNumber,
                                                                                      VARIANT  streamPosition);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnRecognitionForOtherContext_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                                      void *caCallbackData,
                                                                                                      long  streamNumber,
                                                                                                      VARIANT  streamPosition);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnAudioLevel_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                      void *caCallbackData,
                                                                                      long  streamNumber,
                                                                                      VARIANT  streamPosition,
                                                                                      long  audioLevel);
typedef HRESULT (CVICALLBACK *_ISpeechRecoContextEventsRegOnEnginePrivate_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                         void *caCallbackData,
                                                                                         long  streamNumber,
                                                                                         VARIANT  streamPosition,
                                                                                         VARIANT  engineData);
/* NICDBLD_END> Type Library Specific Types */

/* NICDBLD_BEGIN> Type Library Modules */
/* NICDBLD_BEGIN> Module Name: SpeechStringConstants */
#define SpeechLibConst_SpeechRegistryUserRoot                  "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech"
#define SpeechLibConst_SpeechRegistryLocalMachineRoot          "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech"
#define SpeechLibConst_SpeechCategoryAudioOut                  "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioOutput"
#define SpeechLibConst_SpeechCategoryAudioIn                   "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AudioInput"
#define SpeechLibConst_SpeechCategoryVoices                    "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices"
#define SpeechLibConst_SpeechCategoryRecognizers               "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Recognizers"
#define SpeechLibConst_SpeechCategoryAppLexicons               "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\AppLexicons"
#define SpeechLibConst_SpeechCategoryPhoneConverters           "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\PhoneConverters"
#define SpeechLibConst_SpeechCategoryRecoProfiles              "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\RecoProfiles"
#define SpeechLibConst_SpeechTokenIdUserLexicon                "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Speech\CurrentUserLexicon"
#define SpeechLibConst_SpeechTokenValueCLSID                   "CLSID"
#define SpeechLibConst_SpeechTokenKeyFiles                     "Files"
#define SpeechLibConst_SpeechTokenKeyUI                        "UI"
#define SpeechLibConst_SpeechTokenKeyAttributes                "Attributes"
#define SpeechLibConst_SpeechVoiceCategoryTTSRate              "DefaultTTSRate"
#define SpeechLibConst_SpeechPropertyResourceUsage             "ResourceUsage"
#define SpeechLibConst_SpeechPropertyHighConfidenceThreshold   "HighConfidenceThreshold"
#define SpeechLibConst_SpeechPropertyNormalConfidenceThreshold "NormalConfidenceThreshold"
#define SpeechLibConst_SpeechPropertyLowConfidenceThreshold    "LowConfidenceThreshold"
#define SpeechLibConst_SpeechPropertyResponseSpeed             "ResponseSpeed"
#define SpeechLibConst_SpeechPropertyComplexResponseSpeed      "ComplexResponseSpeed"
#define SpeechLibConst_SpeechPropertyAdaptationOn              "AdaptationOn"
#define SpeechLibConst_SpeechDictationTopicSpelling            "Spelling"
#define SpeechLibConst_SpeechGrammarTagWildcard                "..."
#define SpeechLibConst_SpeechGrammarTagDictation               "*"
#define SpeechLibConst_SpeechGrammarTagUnlimitedDictation      "*+"
#define SpeechLibConst_SpeechEngineProperties                  "EngineProperties"
#define SpeechLibConst_SpeechAddRemoveWord                     "AddRemoveWord"
#define SpeechLibConst_SpeechUserTraining                      "UserTraining"
#define SpeechLibConst_SpeechMicTraining                       "MicTraining"
#define SpeechLibConst_SpeechRecoProfileProperties             "RecoProfileProperties"
#define SpeechLibConst_SpeechAudioProperties                   "AudioProperties"
#define SpeechLibConst_SpeechAudioVolume                       "AudioVolume"
#define SpeechLibConst_SpeechVoiceSkipTypeSentence             "Sentence"
#define SpeechLibConst_SpeechAudioFormatGUIDWave               "{C31ADBAE-527F-4ff5-A230-F62BB61FF70C}"
#define SpeechLibConst_SpeechAudioFormatGUIDText               "{7CEEF9F9-3D13-11d2-9EE7-00C04F797396}"
/* NICDBLD_END> Module Name: SpeechStringConstants */

/* NICDBLD_BEGIN> Module Name: SpeechConstants */
#define SpeechLibConst_Speech_Default_Weight     1
#define SpeechLibConst_Speech_Max_Word_Length    128
#define SpeechLibConst_Speech_Max_Pron_Length    384
#define SpeechLibConst_Speech_StreamPos_Asap     0
#define SpeechLibConst_Speech_StreamPos_RealTime -1
#define SpeechLibConst_SpeechAllElements         -1
/* NICDBLD_END> Module Name: SpeechConstants */
/* NICDBLD_END> Type Library Modules */

extern const IID SpeechLib_IID_ISpNotifyTranslator;
extern const IID SpeechLib_IID_ISpeechObjectTokenCategory;
extern const IID SpeechLib_IID_ISpObjectTokenCategory;
extern const IID SpeechLib_IID_ISpeechObjectToken;
extern const IID SpeechLib_IID_ISpObjectToken;
extern const IID SpeechLib_IID_ISpStreamFormatConverter;
extern const IID SpeechLib_IID_IEnumSpObjectTokens;
extern const IID SpeechLib_IID_ISpeechMMSysAudio;
extern const IID SpeechLib_IID_ISpEventSource;
extern const IID SpeechLib_IID_ISpObjectWithToken;
extern const IID SpeechLib_IID_ISpMMSysAudio;
extern const IID SpeechLib_IID_ISpStream;
extern const IID SpeechLib_IID_ISpeechVoice;
extern const IID SpeechLib_IID_ISpVoice;
extern const IID SpeechLib_IID_ISpPhoneticAlphabetSelection;
extern const IID SpeechLib_IID_ISpeechRecoContext;
extern const IID SpeechLib_IID_ISpRecoContext;
extern const IID SpeechLib_IID_ISpRecoContext2;
extern const IID SpeechLib_IID_ISpeechRecognizer;
extern const IID SpeechLib_IID_ISpRecognizer;
extern const IID SpeechLib_IID_ISpRecognizer2;
extern const IID SpeechLib_IID_ISpRecognizer3;
extern const IID SpeechLib_IID_ISpSerializeState;
extern const IID SpeechLib_IID_ISpeechLexicon;
extern const IID SpeechLib_IID_ISpLexicon;
extern const IID SpeechLib_IID_ISpShortcut;
extern const IID SpeechLib_IID_ISpeechPhoneConverter;
extern const IID SpeechLib_IID_ISpPhoneConverter;
extern const IID SpeechLib_IID_ISpPhoneticAlphabetConverter;
extern const IID SpeechLib_IID_ISpeechTextSelectionInformation;
extern const IID SpeechLib_IID_ISpeechPhraseInfoBuilder;
extern const IID SpeechLib_IID_ISpeechAudioFormat;
extern const IID SpeechLib_IID_ISpeechWaveFormatEx;
extern const IID SpeechLib_IID_ISpeechCustomStream;
extern const IID SpeechLib_IID_ISpeechFileStream;
extern const IID SpeechLib_IID_ISpeechMemoryStream;
extern const IID SpeechLib_IID__ISpeechVoiceEvents;
extern const IID SpeechLib_IID__ISpeechRecoContextEvents;
extern const IID SpeechLib_IID_ISpeechDataKey;
extern const IID SpeechLib_IID_ISpeechObjectTokens;
extern const IID SpeechLib_IID_ISpeechAudioBufferInfo;
extern const IID SpeechLib_IID_ISpeechAudioStatus;
extern const IID SpeechLib_IID_ISpeechBaseStream;
extern const IID SpeechLib_IID_ISpeechAudio;
extern const IID SpeechLib_IID_ISpeechVoiceStatus;
extern const IID SpeechLib_IID_ISpeechRecognizerStatus;
extern const IID SpeechLib_IID_ISpeechRecoGrammar;
extern const IID SpeechLib_IID_ISpeechGrammarRules;
extern const IID SpeechLib_IID_ISpeechGrammarRule;
extern const IID SpeechLib_IID_ISpeechGrammarRuleState;
extern const IID SpeechLib_IID_ISpeechGrammarRuleStateTransitions;
extern const IID SpeechLib_IID_ISpeechGrammarRuleStateTransition;
extern const IID SpeechLib_IID_ISpeechRecoResult;
extern const IID SpeechLib_IID_ISpeechRecoResultTimes;
extern const IID SpeechLib_IID_ISpeechPhraseInfo;
extern const IID SpeechLib_IID_ISpeechPhraseRule;
extern const IID SpeechLib_IID_ISpeechPhraseRules;
extern const IID SpeechLib_IID_ISpeechPhraseProperties;
extern const IID SpeechLib_IID_ISpeechPhraseProperty;
extern const IID SpeechLib_IID_ISpeechPhraseElements;
extern const IID SpeechLib_IID_ISpeechPhraseElement;
extern const IID SpeechLib_IID_ISpeechPhraseReplacements;
extern const IID SpeechLib_IID_ISpeechPhraseReplacement;
extern const IID SpeechLib_IID_ISpeechPhraseAlternates;
extern const IID SpeechLib_IID_ISpeechPhraseAlternate;
extern const IID SpeechLib_IID_ISpeechRecoResult2;
extern const IID SpeechLib_IID_ISpeechLexiconWords;
extern const IID SpeechLib_IID_ISpeechLexiconWord;
extern const IID SpeechLib_IID_ISpeechLexiconPronunciations;
extern const IID SpeechLib_IID_ISpeechLexiconPronunciation;
extern const IID SpeechLib_IID_ISpeechXMLRecoResult;
extern const IID SpeechLib_IID_ISpeechRecoResultDispatch;
extern const IID SpeechLib_IID_ISpNotifySink;
extern const IID SpeechLib_IID_ISpStreamFormat;
extern const IID SpeechLib_IID_IStream;
extern const IID SpeechLib_IID_ISequentialStream;
extern const IID SpeechLib_IID_ISpNotifySource;
extern const IID SpeechLib_IID_ISpAudio;
extern const IID SpeechLib_IID_ISpPhrase;
extern const IID SpeechLib_IID_ISpRecoGrammar;
extern const IID SpeechLib_IID_ISpGrammarBuilder;
extern const IID SpeechLib_IID_ISpRecoResult;
extern const IID SpeechLib_IID_ISpPhraseAlt;
extern const IID SpeechLib_IID_ISpRecoCategory;
extern const IID SpeechLib_IID_ISpXMLRecoResult;
extern const IID SpeechLib_IID_ISpRecoGrammar2;
extern const IID SpeechLib_IID_ISpeechResourceLoader;
extern const IID SpeechLib_IID_IInternetSecurityManager;
extern const IID SpeechLib_IID_IInternetSecurityMgrSite;
extern const IID SpeechLib_IID_IEnumString;

HRESULT CVIFUNC SpeechLib_NewISpNotifyTranslator (const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpNotifyTranslator (const char *fileName,
                                                   const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpNotifyTranslator (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpNotifyTranslatorNotify (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpNotifyTranslatorInitWin32Event (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             void *hEvent,
                                                             long fCloseHandleOnRelease);

HRESULT CVIFUNC SpeechLib_ISpNotifyTranslatorWait (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned long dwMilliseconds);

HRESULT CVIFUNC SpeechLib_ISpNotifyTranslatorGetEventHandle (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_NewISpeechObjectTokenCategory (const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechObjectTokenCategory (const char *fileName,
                                                          const char *server,
                                                          int supportMultithreading,
                                                          LCID locale,
                                                          int reserved,
                                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechObjectTokenCategory (const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenCategoryGetId (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **id);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenCategorySetDefault (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                const char *tokenId);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenCategoryGetDefault (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                char **tokenId);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenCategorySetId (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *id,
                                                           VBOOL createIfNotExist);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenCategoryGetDataKey (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                enum SpeechLibEnum_SpeechDataKeyLocation location,
                                                                SpeechLibObj_ISpeechDataKey *dataKey);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenCategoryEnumerateTokens (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     const char *requiredAttributes,
                                                                     const char *optionalAttributes,
                                                                     SpeechLibObj_ISpeechObjectTokens *tokens);

HRESULT CVIFUNC SpeechLib_NewISpObjectTokenCategory (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpObjectTokenCategory (const char *fileName,
                                                      const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpObjectTokenCategory (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpObjectTokenCategoryGetDataKey (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum SpeechLibEnum_SPDATAKEYLOCATION spdkl,
                                                            SpeechLibObj_ISpDataKey *ppDataKey);

HRESULT CVIFUNC SpeechLib_NewISpeechObjectToken (const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechObjectToken (const char *fileName,
                                                  const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechObjectToken (const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenGetId (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **objectId);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenGetDataKey (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpeechDataKey *dataKey);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenGetCategory (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         SpeechLibObj_ISpeechObjectTokenCategory *category);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenGetDescription (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long locale,
                                                            char **description);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenSetId (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *id,
                                                   const char *categoryID,
                                                   VBOOL createIfNotExist);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenGetAttribute (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *attributeName,
                                                          char **attributeValue);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenCreateInstance (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            LPUNKNOWN pUnkOuter,
                                                            enum SpeechLibEnum_SpeechTokenContext clsContext,
                                                            LPUNKNOWN *object);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenRemove (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *objectStorageCLSID);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenGetStorageFileName (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                const char *objectStorageCLSID,
                                                                const char *keyName,
                                                                const char *fileName,
                                                                enum SpeechLibEnum_SpeechTokenShellFolder folder,
                                                                char **filePath);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenRemoveStorageFileName (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   const char *objectStorageCLSID,
                                                                   const char *keyName,
                                                                   VBOOL deleteFile);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenIsUISupported (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *typeOfUI,
                                                           VARIANT extraData,
                                                           LPUNKNOWN object,
                                                           VBOOL *supported);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenDisplayUI (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long hWnd,
                                                       const char *title,
                                                       const char *typeOfUI,
                                                       VARIANT extraData,
                                                       LPUNKNOWN object);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokenMatchesAttributes (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               const char *attributes,
                                                               VBOOL *matches);

HRESULT CVIFUNC SpeechLib_NewISpObjectToken (const char *server,
                                             int supportMultithreading,
                                             LCID locale, int reserved,
                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpObjectToken (const char *fileName,
                                              const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpObjectToken (const char *server,
                                                int supportMultithreading,
                                                LCID locale, int reserved,
                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpObjectTokenGetCategory (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     SpeechLibObj_ISpObjectTokenCategory *ppTokenCategory);

HRESULT CVIFUNC SpeechLib_NewISpStreamFormatConverter (const char *server,
                                                       int supportMultithreading,
                                                       LCID locale, int reserved,
                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpStreamFormatConverter (const char *fileName,
                                                        const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpStreamFormatConverter (const char *server,
                                                          int supportMultithreading,
                                                          LCID locale,
                                                          int reserved,
                                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatConverterRemoteRead (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              unsigned char *pv,
                                                              unsigned long cb,
                                                              unsigned long *pcbRead);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatConverterRemoteWrite (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned char *pv,
                                                               unsigned long cb,
                                                               unsigned long *pcbWritten);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatConverterCommit (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          unsigned long grfCommitFlags);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatConverterRevert (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatConverterClone (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         SpeechLibObj_IStream *ppstm);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatConverterSetBaseStream (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 SpeechLibObj_ISpStreamFormat pStream,
                                                                 long fSetFormatToBaseStreamFormat,
                                                                 long fWriteToBaseStream);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatConverterGetBaseStream (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 SpeechLibObj_ISpStreamFormat *ppStream);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatConverterResetSeekPosition (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_NewIEnumSpObjectTokens (const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenIEnumSpObjectTokens (const char *fileName,
                                                   const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveIEnumSpObjectTokens (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_IEnumSpObjectTokensNext (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned long celt,
                                                   SpeechLibObj_ISpObjectToken *pelt,
                                                   unsigned long *pceltFetched);

HRESULT CVIFUNC SpeechLib_IEnumSpObjectTokensSkip (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned long celt);

HRESULT CVIFUNC SpeechLib_IEnumSpObjectTokensReset (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_IEnumSpObjectTokensClone (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    SpeechLibObj_IEnumSpObjectTokens *ppEnum);

HRESULT CVIFUNC SpeechLib_IEnumSpObjectTokensItem (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned long index,
                                                   SpeechLibObj_ISpObjectToken *ppToken);

HRESULT CVIFUNC SpeechLib_IEnumSpObjectTokensGetCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       unsigned long *pCount);

HRESULT CVIFUNC SpeechLib_NewSpMMAudioInISpeechMMSysAudio (const char *server,
                                                           int supportMultithreading,
                                                           LCID locale,
                                                           int reserved,
                                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpMMAudioInISpeechMMSysAudio (const char *fileName,
                                                            const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpMMAudioInISpeechMMSysAudio (const char *server,
                                                              int supportMultithreading,
                                                              LCID locale,
                                                              int reserved,
                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpMMAudioOutISpeechMMSysAudio (const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpMMAudioOutISpeechMMSysAudio (const char *fileName,
                                                             const char *server,
                                                             int supportMultithreading,
                                                             LCID locale,
                                                             int reserved,
                                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpMMAudioOutISpeechMMSysAudio (const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetFormat (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechAudioFormat *audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioSetByRefFormat (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechAudioFormat audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioRead (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT *buffer,
                                                 long numberOfBytes,
                                                 long *bytesRead);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioWrite (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT buffer,
                                                  long *bytesWritten);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioSeek (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT position,
                                                 enum SpeechLibEnum_SpeechStreamSeekPositionType origin,
                                                 VARIANT *newPosition);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetStatus (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechAudioStatus *status);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetBufferInfo (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          SpeechLibObj_ISpeechAudioBufferInfo *bufferInfo);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetDefaultFormat (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             SpeechLibObj_ISpeechAudioFormat *streamFormat);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetVolume (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *volume);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioSetVolume (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long volume);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetBufferNotifySize (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *bufferNotifySize);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioSetBufferNotifySize (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long bufferNotifySize);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetEventHandle (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *eventHandle);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioSetState (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum SpeechLibEnum_SpeechAudioState state);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetDeviceId (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *deviceId);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioSetDeviceId (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long deviceId);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetLineId (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *lineId);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioSetLineId (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long lineId);

HRESULT CVIFUNC SpeechLib_ISpeechMMSysAudioGetMMHandle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *handle);

HRESULT CVIFUNC SpeechLib_NewSpMMAudioInISpEventSource (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpMMAudioInISpEventSource (const char *fileName,
                                                         const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpMMAudioInISpEventSource (const char *server,
                                                           int supportMultithreading,
                                                           LCID locale,
                                                           int reserved,
                                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpMMAudioOutISpEventSource (const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpMMAudioOutISpEventSource (const char *fileName,
                                                          const char *server,
                                                          int supportMultithreading,
                                                          LCID locale,
                                                          int reserved,
                                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpMMAudioOutISpEventSource (const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpEventSourceSetNotifySink (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       SpeechLibObj_ISpNotifySink pNotifySink);

HRESULT CVIFUNC SpeechLib_ISpEventSourceSetNotifyWin32Event (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpEventSourceWaitForNotifyEvent (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long dwMilliseconds);

HRESULT CVIFUNC SpeechLib_ISpEventSourceGetNotifyEventHandle (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_NewSpMMAudioInISpObjectWithToken (const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpMMAudioInISpObjectWithToken (const char *fileName,
                                                             const char *server,
                                                             int supportMultithreading,
                                                             LCID locale,
                                                             int reserved,
                                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpMMAudioInISpObjectWithToken (const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpMMAudioOutISpObjectWithToken (const char *server,
                                                             int supportMultithreading,
                                                             LCID locale,
                                                             int reserved,
                                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpMMAudioOutISpObjectWithToken (const char *fileName,
                                                              const char *server,
                                                              int supportMultithreading,
                                                              LCID locale,
                                                              int reserved,
                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpMMAudioOutISpObjectWithToken (const char *server,
                                                                int supportMultithreading,
                                                                LCID locale,
                                                                int reserved,
                                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpUnCompressedLexiconISpObjectWithToken (const char *server,
                                                                      int supportMultithreading,
                                                                      LCID locale,
                                                                      int reserved,
                                                                      CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpUnCompressedLexiconISpObjectWithToken (const char *fileName,
                                                                       const char *server,
                                                                       int supportMultithreading,
                                                                       LCID locale,
                                                                       int reserved,
                                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpUnCompressedLexiconISpObjectWithToken (const char *server,
                                                                         int supportMultithreading,
                                                                         LCID locale,
                                                                         int reserved,
                                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpCompressedLexiconISpObjectWithToken (const char *server,
                                                                    int supportMultithreading,
                                                                    LCID locale,
                                                                    int reserved,
                                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpCompressedLexiconISpObjectWithToken (const char *fileName,
                                                                     const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpCompressedLexiconISpObjectWithToken (const char *server,
                                                                       int supportMultithreading,
                                                                       LCID locale,
                                                                       int reserved,
                                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpShortcutISpObjectWithToken (const char *server,
                                                           int supportMultithreading,
                                                           LCID locale,
                                                           int reserved,
                                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpShortcutISpObjectWithToken (const char *fileName,
                                                            const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpShortcutISpObjectWithToken (const char *server,
                                                              int supportMultithreading,
                                                              LCID locale,
                                                              int reserved,
                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpObjectWithTokenSetObjectToken (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpObjectToken pToken);

HRESULT CVIFUNC SpeechLib_ISpObjectWithTokenGetObjectToken (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpObjectToken *ppToken);

HRESULT CVIFUNC SpeechLib_NewSpMMAudioInISpMMSysAudio (const char *server,
                                                       int supportMultithreading,
                                                       LCID locale, int reserved,
                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpMMAudioInISpMMSysAudio (const char *fileName,
                                                        const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpMMAudioInISpMMSysAudio (const char *server,
                                                          int supportMultithreading,
                                                          LCID locale,
                                                          int reserved,
                                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpMMAudioOutISpMMSysAudio (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpMMAudioOutISpMMSysAudio (const char *fileName,
                                                         const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpMMAudioOutISpMMSysAudio (const char *server,
                                                           int supportMultithreading,
                                                           LCID locale,
                                                           int reserved,
                                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioRemoteRead (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned char *pv,
                                                   unsigned long cb,
                                                   unsigned long *pcbRead);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioRemoteWrite (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    unsigned char *pv,
                                                    unsigned long cb,
                                                    unsigned long *pcbWritten);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioCommit (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned long grfCommitFlags);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioRevert (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioClone (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              SpeechLibObj_IStream *ppstm);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioEventHandle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioGetVolumeLevel (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       unsigned long *pLevel);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioSetVolumeLevel (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       unsigned long level);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioGetBufferNotifySize (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long *pcbSize);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioSetBufferNotifySize (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long cbSize);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioGetDeviceId (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    unsigned long *puDeviceId);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioSetDeviceId (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    unsigned long uDeviceId);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioGetLineId (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  unsigned long *puLineId);

HRESULT CVIFUNC SpeechLib_ISpMMSysAudioSetLineId (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  unsigned long uLineId);

HRESULT CVIFUNC SpeechLib_NewSpStreamISpStream (const char *server,
                                                int supportMultithreading,
                                                LCID locale, int reserved,
                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpStreamISpStream (const char *fileName,
                                                 const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpStreamISpStream (const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpCustomStreamISpStream (const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpCustomStreamISpStream (const char *fileName,
                                                       const char *server,
                                                       int supportMultithreading,
                                                       LCID locale, int reserved,
                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpCustomStreamISpStream (const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpFileStreamISpStream (const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpFileStreamISpStream (const char *fileName,
                                                     const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpFileStreamISpStream (const char *server,
                                                       int supportMultithreading,
                                                       LCID locale, int reserved,
                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpMemoryStreamISpStream (const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpMemoryStreamISpStream (const char *fileName,
                                                       const char *server,
                                                       int supportMultithreading,
                                                       LCID locale, int reserved,
                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpMemoryStreamISpStream (const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpStreamRemoteRead (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned char *pv,
                                               unsigned long cb,
                                               unsigned long *pcbRead);

HRESULT CVIFUNC SpeechLib_ISpStreamRemoteWrite (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                unsigned char *pv,
                                                unsigned long cb,
                                                unsigned long *pcbWritten);

HRESULT CVIFUNC SpeechLib_ISpStreamCommit (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           unsigned long grfCommitFlags);

HRESULT CVIFUNC SpeechLib_ISpStreamRevert (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpStreamClone (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          SpeechLibObj_IStream *ppstm);

HRESULT CVIFUNC SpeechLib_ISpStreamGetBaseStream (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  SpeechLibObj_IStream *ppStream);

HRESULT CVIFUNC SpeechLib_ISpStreamClose (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_NewISpeechVoice (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechVoice (const char *fileName,
                                            const char *server,
                                            int supportMultithreading,
                                            LCID locale, int reserved,
                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechVoice (const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetStatus (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 SpeechLibObj_ISpeechVoiceStatus *status);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetVoice (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                SpeechLibObj_ISpeechObjectToken *voice);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetByRefVoice (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     SpeechLibObj_ISpeechObjectToken voice);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetAudioOutput (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechObjectToken *audioOutput);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetByRefAudioOutput (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechObjectToken audioOutput);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetAudioOutputStream (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpeechBaseStream *audioOutputStream);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetByRefAudioOutputStream (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 SpeechLibObj_ISpeechBaseStream audioOutputStream);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetRate (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long *rate);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetRate (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo, long rate);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetVolume (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *volume);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetVolume (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long volume);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetAllowAudioOutputFormatChangesOnNextSet (CAObjHandle objectHandle,
                                                                                 ERRORINFO *errorInfo,
                                                                                 VBOOL allow);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetAllowAudioOutputFormatChangesOnNextSet (CAObjHandle objectHandle,
                                                                                 ERRORINFO *errorInfo,
                                                                                 VBOOL *allow);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetEventInterests (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum SpeechLibEnum_SpeechVoiceEvents *eventInterestFlags);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetEventInterests (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum SpeechLibEnum_SpeechVoiceEvents eventInterestFlags);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetPriority (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum SpeechLibEnum_SpeechVoicePriority priority);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetPriority (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum SpeechLibEnum_SpeechVoicePriority *priority);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetAlertBoundary (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum SpeechLibEnum_SpeechVoiceEvents boundary);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetAlertBoundary (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum SpeechLibEnum_SpeechVoiceEvents *boundary);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSetSynchronousSpeakTimeout (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long msTimeout);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetSynchronousSpeakTimeout (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long *msTimeout);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSpeak (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             const char *text,
                                             enum SpeechLibEnum_SpeechVoiceSpeakFlags flags,
                                             long *streamNumber);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSpeakStream (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   SpeechLibObj_ISpeechBaseStream stream,
                                                   enum SpeechLibEnum_SpeechVoiceSpeakFlags flags,
                                                   long *streamNumber);

HRESULT CVIFUNC SpeechLib_ISpeechVoicePause (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceResume (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSkip (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            const char *type, long numItems,
                                            long *numSkipped);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetVoices (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *requiredAttributes,
                                                 const char *optionalAttributes,
                                                 SpeechLibObj_ISpeechObjectTokens *objectTokens);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceGetAudioOutputs (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *requiredAttributes,
                                                       const char *optionalAttributes,
                                                       SpeechLibObj_ISpeechObjectTokens *objectTokens);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceWaitUntilDone (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long msTimeout, VBOOL *done);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceSpeakCompleteEvent (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *handle);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceIsUISupported (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *typeOfUI,
                                                     VARIANT extraData,
                                                     VBOOL *supported);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceDisplayUI (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long hWndParent,
                                                 const char *title,
                                                 const char *typeOfUI,
                                                 VARIANT extraData);

HRESULT CVIFUNC SpeechLib_NewISpVoice (const char *server,
                                       int supportMultithreading, LCID locale,
                                       int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpVoice (const char *fileName, const char *server,
                                        int supportMultithreading, LCID locale,
                                        int reserved, CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpVoice (const char *server,
                                          int supportMultithreading, LCID locale,
                                          int reserved,
                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpVoiceSetNotifySink (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 SpeechLibObj_ISpNotifySink pNotifySink);

HRESULT CVIFUNC SpeechLib_ISpVoiceSetNotifyWin32Event (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpVoiceWaitForNotifyEvent (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      unsigned long dwMilliseconds);

HRESULT CVIFUNC SpeechLib_ISpVoiceGetNotifyEventHandle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpVoiceSetOutput (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             CAObjHandle pUnkOutput,
                                             long fAllowFormatChanges);

HRESULT CVIFUNC SpeechLib_ISpVoiceGetOutputObjectToken (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpObjectToken *ppObjectToken);

HRESULT CVIFUNC SpeechLib_ISpVoiceGetOutputStream (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   SpeechLibObj_ISpStreamFormat *ppStream);

HRESULT CVIFUNC SpeechLib_ISpVoicePause (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpVoiceResume (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpVoiceSetVoice (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            SpeechLibObj_ISpObjectToken pToken);

HRESULT CVIFUNC SpeechLib_ISpVoiceGetVoice (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            SpeechLibObj_ISpObjectToken *ppToken);

HRESULT CVIFUNC SpeechLib_ISpVoiceSpeakStream (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               SpeechLibObj_IStream pStream,
                                               unsigned long dwFlags,
                                               unsigned long *pulStreamNumber);

HRESULT CVIFUNC SpeechLib_ISpVoiceSetPriority (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum SpeechLibEnum_SPVPRIORITY ePriority);

HRESULT CVIFUNC SpeechLib_ISpVoiceGetPriority (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum SpeechLibEnum_SPVPRIORITY *pePriority);

HRESULT CVIFUNC SpeechLib_ISpVoiceSetAlertBoundary (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum SpeechLibEnum_SPEVENTENUM eBoundary);

HRESULT CVIFUNC SpeechLib_ISpVoiceGetAlertBoundary (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum SpeechLibEnum_SPEVENTENUM *peBoundary);

HRESULT CVIFUNC SpeechLib_ISpVoiceSetRate (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, long rateAdjust);

HRESULT CVIFUNC SpeechLib_ISpVoiceGetRate (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           long *pRateAdjust);

HRESULT CVIFUNC SpeechLib_ISpVoiceSetVolume (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             unsigned short usVolume);

HRESULT CVIFUNC SpeechLib_ISpVoiceGetVolume (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             unsigned short *pusVolume);

HRESULT CVIFUNC SpeechLib_ISpVoiceWaitUntilDone (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 unsigned long msTimeout);

HRESULT CVIFUNC SpeechLib_ISpVoiceSetSyncSpeakTimeout (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       unsigned long msTimeout);

HRESULT CVIFUNC SpeechLib_ISpVoiceGetSyncSpeakTimeout (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       unsigned long *pmsTimeout);

HRESULT CVIFUNC SpeechLib_ISpVoiceSpeakCompleteEvent (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_NewSpVoiceISpPhoneticAlphabetSelection (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpVoiceISpPhoneticAlphabetSelection (const char *fileName,
                                                                   const char *server,
                                                                   int supportMultithreading,
                                                                   LCID locale,
                                                                   int reserved,
                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpVoiceISpPhoneticAlphabetSelection (const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpSharedRecoContextISpPhoneticAlphabetSelection (const char *server,
                                                                              int supportMultithreading,
                                                                              LCID locale,
                                                                              int reserved,
                                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpSharedRecoContextISpPhoneticAlphabetSelection (const char *fileName,
                                                                               const char *server,
                                                                               int supportMultithreading,
                                                                               LCID locale,
                                                                               int reserved,
                                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpSharedRecoContextISpPhoneticAlphabetSelection (const char *server,
                                                                                 int supportMultithreading,
                                                                                 LCID locale,
                                                                                 int reserved,
                                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpLexiconISpPhoneticAlphabetSelection (const char *server,
                                                                    int supportMultithreading,
                                                                    LCID locale,
                                                                    int reserved,
                                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpLexiconISpPhoneticAlphabetSelection (const char *fileName,
                                                                     const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpLexiconISpPhoneticAlphabetSelection (const char *server,
                                                                       int supportMultithreading,
                                                                       LCID locale,
                                                                       int reserved,
                                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpUnCompressedLexiconISpPhoneticAlphabetSelection (const char *server,
                                                                                int supportMultithreading,
                                                                                LCID locale,
                                                                                int reserved,
                                                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpUnCompressedLexiconISpPhoneticAlphabetSelection (const char *fileName,
                                                                                 const char *server,
                                                                                 int supportMultithreading,
                                                                                 LCID locale,
                                                                                 int reserved,
                                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpUnCompressedLexiconISpPhoneticAlphabetSelection (const char *server,
                                                                                   int supportMultithreading,
                                                                                   LCID locale,
                                                                                   int reserved,
                                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpPhoneConverterISpPhoneticAlphabetSelection (const char *server,
                                                                           int supportMultithreading,
                                                                           LCID locale,
                                                                           int reserved,
                                                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpPhoneConverterISpPhoneticAlphabetSelection (const char *fileName,
                                                                            const char *server,
                                                                            int supportMultithreading,
                                                                            LCID locale,
                                                                            int reserved,
                                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpPhoneConverterISpPhoneticAlphabetSelection (const char *server,
                                                                              int supportMultithreading,
                                                                              LCID locale,
                                                                              int reserved,
                                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpInProcRecoContextISpPhoneticAlphabetSelection (const char *server,
                                                                              int supportMultithreading,
                                                                              LCID locale,
                                                                              int reserved,
                                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpInProcRecoContextISpPhoneticAlphabetSelection (const char *fileName,
                                                                               const char *server,
                                                                               int supportMultithreading,
                                                                               LCID locale,
                                                                               int reserved,
                                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpInProcRecoContextISpPhoneticAlphabetSelection (const char *server,
                                                                                 int supportMultithreading,
                                                                                 LCID locale,
                                                                                 int reserved,
                                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpPhoneticAlphabetSelectionIsAlphabetUPS (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     long *pfIsUPS);

HRESULT CVIFUNC SpeechLib_ISpPhoneticAlphabetSelectionSetAlphabetToUPS (CAObjHandle objectHandle,
                                                                        ERRORINFO *errorInfo,
                                                                        long fForceUPS);

HRESULT CVIFUNC SpeechLib_NewSpSharedRecoContextISpeechRecoContext (const char *server,
                                                                    int supportMultithreading,
                                                                    LCID locale,
                                                                    int reserved,
                                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpSharedRecoContextISpeechRecoContext (const char *fileName,
                                                                     const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpSharedRecoContextISpeechRecoContext (const char *server,
                                                                       int supportMultithreading,
                                                                       LCID locale,
                                                                       int reserved,
                                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpInProcRecoContextISpeechRecoContext (const char *server,
                                                                    int supportMultithreading,
                                                                    LCID locale,
                                                                    int reserved,
                                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpInProcRecoContextISpeechRecoContext (const char *fileName,
                                                                     const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpInProcRecoContextISpeechRecoContext (const char *server,
                                                                       int supportMultithreading,
                                                                       LCID locale,
                                                                       int reserved,
                                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetRecognizer (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechRecognizer *recognizer);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetAudioInputInterferenceStatus (CAObjHandle objectHandle,
                                                                             ERRORINFO *errorInfo,
                                                                             enum SpeechLibEnum_SpeechInterference *interference);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetRequestedUIType (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                char **UIType);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextSetByRefVoice (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechVoice voice);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetVoice (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechVoice *voice);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextSetAllowVoiceFormatMatchingOnNextSet (CAObjHandle objectHandle,
                                                                                  ERRORINFO *errorInfo,
                                                                                  VBOOL pAllow);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetAllowVoiceFormatMatchingOnNextSet (CAObjHandle objectHandle,
                                                                                  ERRORINFO *errorInfo,
                                                                                  VBOOL *pAllow);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextSetVoicePurgeEvent (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                enum SpeechLibEnum_SpeechRecoEvents eventInterest);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetVoicePurgeEvent (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                enum SpeechLibEnum_SpeechRecoEvents *eventInterest);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextSetEventInterests (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum SpeechLibEnum_SpeechRecoEvents eventInterest);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetEventInterests (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum SpeechLibEnum_SpeechRecoEvents *eventInterest);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextSetCmdMaxAlternates (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 long maxAlternates);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetCmdMaxAlternates (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 long *maxAlternates);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextSetState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum SpeechLibEnum_SpeechRecoContextState state);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum SpeechLibEnum_SpeechRecoContextState *state);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextSetRetainedAudio (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              enum SpeechLibEnum_SpeechRetainedAudioOptions option);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetRetainedAudio (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              enum SpeechLibEnum_SpeechRetainedAudioOptions *option);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextSetByRefRetainedAudioFormat (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         SpeechLibObj_ISpeechAudioFormat format);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextGetRetainedAudioFormat (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    SpeechLibObj_ISpeechAudioFormat *format);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextPause (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextResume (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextCreateGrammar (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VARIANT grammarId,
                                                           SpeechLibObj_ISpeechRecoGrammar *grammar);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextCreateResultFromMemory (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VARIANT resultBlock,
                                                                    SpeechLibObj_ISpeechRecoResult *result);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextBookmark (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum SpeechLibEnum_SpeechBookmarkOptions options,
                                                      VARIANT streamPos,
                                                      VARIANT bookmarkId);

HRESULT CVIFUNC SpeechLib_ISpeechRecoContextSetAdaptationData (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               const char *adaptationString);

HRESULT CVIFUNC SpeechLib_NewSpSharedRecoContextISpRecoContext (const char *server,
                                                                int supportMultithreading,
                                                                LCID locale,
                                                                int reserved,
                                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpSharedRecoContextISpRecoContext (const char *fileName,
                                                                 const char *server,
                                                                 int supportMultithreading,
                                                                 LCID locale,
                                                                 int reserved,
                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpSharedRecoContextISpRecoContext (const char *server,
                                                                   int supportMultithreading,
                                                                   LCID locale,
                                                                   int reserved,
                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpInProcRecoContextISpRecoContext (const char *server,
                                                                int supportMultithreading,
                                                                LCID locale,
                                                                int reserved,
                                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpInProcRecoContextISpRecoContext (const char *fileName,
                                                                 const char *server,
                                                                 int supportMultithreading,
                                                                 LCID locale,
                                                                 int reserved,
                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpInProcRecoContextISpRecoContext (const char *server,
                                                                   int supportMultithreading,
                                                                   LCID locale,
                                                                   int reserved,
                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpRecoContextSetNotifySink (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       SpeechLibObj_ISpNotifySink pNotifySink);

HRESULT CVIFUNC SpeechLib_ISpRecoContextSetNotifyWin32Event (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpRecoContextWaitForNotifyEvent (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long dwMilliseconds);

HRESULT CVIFUNC SpeechLib_ISpRecoContextGetNotifyEventHandle (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpRecoContextGetRecognizer (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       SpeechLibObj_ISpRecognizer *ppRecognizer);

HRESULT CVIFUNC SpeechLib_ISpRecoContextGetMaxAlternates (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          unsigned long *pcAlternates);

HRESULT CVIFUNC SpeechLib_ISpRecoContextSetMaxAlternates (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          unsigned long cAlternates);

HRESULT CVIFUNC SpeechLib_ISpRecoContextPause (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned long dwReserved);

HRESULT CVIFUNC SpeechLib_ISpRecoContextResume (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                unsigned long dwReserved);

HRESULT CVIFUNC SpeechLib_ISpRecoContextSetVoice (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  SpeechLibObj_ISpVoice pVoice,
                                                  long fAllowFormatChanges);

HRESULT CVIFUNC SpeechLib_ISpRecoContextGetVoice (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  SpeechLibObj_ISpVoice *ppVoice);

HRESULT CVIFUNC SpeechLib_ISpRecoContextSetContextState (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum SpeechLibEnum_SPCONTEXTSTATE eContextState);

HRESULT CVIFUNC SpeechLib_ISpRecoContextGetContextState (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum SpeechLibEnum_SPCONTEXTSTATE *peContextState);

HRESULT CVIFUNC SpeechLib_NewSpSharedRecoContextISpRecoContext2 (const char *server,
                                                                 int supportMultithreading,
                                                                 LCID locale,
                                                                 int reserved,
                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpSharedRecoContextISpRecoContext2 (const char *fileName,
                                                                  const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpSharedRecoContextISpRecoContext2 (const char *server,
                                                                    int supportMultithreading,
                                                                    LCID locale,
                                                                    int reserved,
                                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpInProcRecoContextISpRecoContext2 (const char *server,
                                                                 int supportMultithreading,
                                                                 LCID locale,
                                                                 int reserved,
                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpInProcRecoContextISpRecoContext2 (const char *fileName,
                                                                  const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpInProcRecoContextISpRecoContext2 (const char *server,
                                                                    int supportMultithreading,
                                                                    LCID locale,
                                                                    int reserved,
                                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpRecoContext2SetGrammarOptions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long eGrammarOptions);

HRESULT CVIFUNC SpeechLib_ISpRecoContext2GetGrammarOptions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long *peGrammarOptions);

HRESULT CVIFUNC SpeechLib_NewSpInprocRecognizerISpeechRecognizer (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpInprocRecognizerISpeechRecognizer (const char *fileName,
                                                                   const char *server,
                                                                   int supportMultithreading,
                                                                   LCID locale,
                                                                   int reserved,
                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpInprocRecognizerISpeechRecognizer (const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpSharedRecognizerISpeechRecognizer (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpSharedRecognizerISpeechRecognizer (const char *fileName,
                                                                   const char *server,
                                                                   int supportMultithreading,
                                                                   LCID locale,
                                                                   int reserved,
                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpSharedRecognizerISpeechRecognizer (const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerSetByRefRecognizer (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               SpeechLibObj_ISpeechObjectToken recognizer);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetRecognizer (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          SpeechLibObj_ISpeechObjectToken *recognizer);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerSetAllowAudioInputFormatChangesOnNextSet (CAObjHandle objectHandle,
                                                                                     ERRORINFO *errorInfo,
                                                                                     VBOOL allow);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetAllowAudioInputFormatChangesOnNextSet (CAObjHandle objectHandle,
                                                                                     ERRORINFO *errorInfo,
                                                                                     VBOOL *allow);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerSetByRefAudioInput (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               SpeechLibObj_ISpeechObjectToken audioInput);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetAudioInput (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          SpeechLibObj_ISpeechObjectToken *audioInput);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerSetByRefAudioInputStream (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     SpeechLibObj_ISpeechBaseStream audioInputStream);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetAudioInputStream (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                SpeechLibObj_ISpeechBaseStream *audioInputStream);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetIsShared (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *shared);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerSetState (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum SpeechLibEnum_SpeechRecognizerState state);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetState (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum SpeechLibEnum_SpeechRecognizerState *state);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetStatus (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechRecognizerStatus *status);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerSetByRefProfile (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpeechObjectToken profile);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetProfile (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       SpeechLibObj_ISpeechObjectToken *profile);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerEmulateRecognition (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VARIANT textElements,
                                                               VARIANT elementDisplayAttributes,
                                                               long languageId);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerCreateRecoContext (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              SpeechLibObj_ISpeechRecoContext *newContext);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetFormat (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum SpeechLibEnum_SpeechFormatType type,
                                                      SpeechLibObj_ISpeechAudioFormat *format);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerSetPropertyNumber (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              const char *name,
                                                              long value,
                                                              VBOOL *supported);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetPropertyNumber (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              const char *name,
                                                              long *value,
                                                              VBOOL *supported);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerSetPropertyString (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              const char *name,
                                                              const char *value,
                                                              VBOOL *supported);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetPropertyString (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              const char *name,
                                                              char **value,
                                                              VBOOL *supported);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerIsUISupported (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *typeOfUI,
                                                          VARIANT extraData,
                                                          VBOOL *supported);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerDisplayUI (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long hWndParent,
                                                      const char *title,
                                                      const char *typeOfUI,
                                                      VARIANT extraData);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetRecognizers (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *requiredAttributes,
                                                           const char *optionalAttributes,
                                                           SpeechLibObj_ISpeechObjectTokens *objectTokens);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetAudioInputs (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *requiredAttributes,
                                                           const char *optionalAttributes,
                                                           SpeechLibObj_ISpeechObjectTokens *objectTokens);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerGetProfiles (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *requiredAttributes,
                                                        const char *optionalAttributes,
                                                        SpeechLibObj_ISpeechObjectTokens *objectTokens);

HRESULT CVIFUNC SpeechLib_NewSpInprocRecognizerISpRecognizer (const char *server,
                                                              int supportMultithreading,
                                                              LCID locale,
                                                              int reserved,
                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpInprocRecognizerISpRecognizer (const char *fileName,
                                                               const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpInprocRecognizerISpRecognizer (const char *server,
                                                                 int supportMultithreading,
                                                                 LCID locale,
                                                                 int reserved,
                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpSharedRecognizerISpRecognizer (const char *server,
                                                              int supportMultithreading,
                                                              LCID locale,
                                                              int reserved,
                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpSharedRecognizerISpRecognizer (const char *fileName,
                                                               const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpSharedRecognizerISpRecognizer (const char *server,
                                                                 int supportMultithreading,
                                                                 LCID locale,
                                                                 int reserved,
                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpRecognizerSetRecognizer (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpObjectToken pRecognizer);

HRESULT CVIFUNC SpeechLib_ISpRecognizerGetRecognizer (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpObjectToken *ppRecognizer);

HRESULT CVIFUNC SpeechLib_ISpRecognizerSetInput (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CAObjHandle pUnkInput,
                                                 long fAllowFormatChanges);

HRESULT CVIFUNC SpeechLib_ISpRecognizerGetInputObjectToken (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpObjectToken *ppToken);

HRESULT CVIFUNC SpeechLib_ISpRecognizerGetInputStream (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       SpeechLibObj_ISpStreamFormat *ppStream);

HRESULT CVIFUNC SpeechLib_ISpRecognizerCreateRecoContext (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          SpeechLibObj_ISpRecoContext *ppNewCtxt);

HRESULT CVIFUNC SpeechLib_ISpRecognizerGetRecoProfile (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       SpeechLibObj_ISpObjectToken *ppToken);

HRESULT CVIFUNC SpeechLib_ISpRecognizerSetRecoProfile (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       SpeechLibObj_ISpObjectToken pToken);

HRESULT CVIFUNC SpeechLib_ISpRecognizerIsSharedInstance (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpRecognizerGetRecoState (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum SpeechLibEnum_SPRECOSTATE *pState);

HRESULT CVIFUNC SpeechLib_ISpRecognizerSetRecoState (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum SpeechLibEnum_SPRECOSTATE newState);

HRESULT CVIFUNC SpeechLib_ISpRecognizerEmulateRecognition (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpPhrase pPhrase);

HRESULT CVIFUNC SpeechLib_NewSpInprocRecognizerISpRecognizer2 (const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpInprocRecognizerISpRecognizer2 (const char *fileName,
                                                                const char *server,
                                                                int supportMultithreading,
                                                                LCID locale,
                                                                int reserved,
                                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpInprocRecognizerISpRecognizer2 (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpSharedRecognizerISpRecognizer2 (const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpSharedRecognizerISpRecognizer2 (const char *fileName,
                                                                const char *server,
                                                                int supportMultithreading,
                                                                LCID locale,
                                                                int reserved,
                                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpSharedRecognizerISpRecognizer2 (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpRecognizer2EmulateRecognitionEx (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              SpeechLibObj_ISpPhrase pPhrase,
                                                              unsigned long dwCompareFlags);

HRESULT CVIFUNC SpeechLib_ISpRecognizer2SetTrainingState (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long fDoingTraining,
                                                          long fAdaptFromTrainingData);

HRESULT CVIFUNC SpeechLib_ISpRecognizer2ResetAcousticModelAdaptation (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_NewSpInprocRecognizerISpRecognizer3 (const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpInprocRecognizerISpRecognizer3 (const char *fileName,
                                                                const char *server,
                                                                int supportMultithreading,
                                                                LCID locale,
                                                                int reserved,
                                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpInprocRecognizerISpRecognizer3 (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpSharedRecognizerISpRecognizer3 (const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpSharedRecognizerISpRecognizer3 (const char *fileName,
                                                                const char *server,
                                                                int supportMultithreading,
                                                                LCID locale,
                                                                int reserved,
                                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpSharedRecognizerISpRecognizer3 (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpRecognizer3GetCategory (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum SpeechLibEnum_SPCATEGORYTYPE categoryType,
                                                     SpeechLibObj_ISpRecoCategory *ppCategory);

HRESULT CVIFUNC SpeechLib_ISpRecognizer3SetActiveCategory (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpRecoCategory pCategory);

HRESULT CVIFUNC SpeechLib_ISpRecognizer3GetActiveCategory (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpRecoCategory *ppCategory);

HRESULT CVIFUNC SpeechLib_NewSpInprocRecognizerISpSerializeState (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpInprocRecognizerISpSerializeState (const char *fileName,
                                                                   const char *server,
                                                                   int supportMultithreading,
                                                                   LCID locale,
                                                                   int reserved,
                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpInprocRecognizerISpSerializeState (const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpSharedRecognizerISpSerializeState (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpSharedRecognizerISpSerializeState (const char *fileName,
                                                                   const char *server,
                                                                   int supportMultithreading,
                                                                   LCID locale,
                                                                   int reserved,
                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpSharedRecognizerISpSerializeState (const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpSerializeStateSetSerializedState (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned char *pbData,
                                                               unsigned long ulSize,
                                                               unsigned long dwReserved);

HRESULT CVIFUNC SpeechLib_NewSpLexiconISpeechLexicon (const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpLexiconISpeechLexicon (const char *fileName,
                                                       const char *server,
                                                       int supportMultithreading,
                                                       LCID locale, int reserved,
                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpLexiconISpeechLexicon (const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpUnCompressedLexiconISpeechLexicon (const char *server,
                                                                  int supportMultithreading,
                                                                  LCID locale,
                                                                  int reserved,
                                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpUnCompressedLexiconISpeechLexicon (const char *fileName,
                                                                   const char *server,
                                                                   int supportMultithreading,
                                                                   LCID locale,
                                                                   int reserved,
                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpUnCompressedLexiconISpeechLexicon (const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconGetGenerationId (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *generationId);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconGetWords (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum SpeechLibEnum_SpeechLexiconType flags,
                                                  long *generationId,
                                                  SpeechLibObj_ISpeechLexiconWords *words);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconAddPronunciation (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *bstrWord,
                                                          long langId,
                                                          enum SpeechLibEnum_SpeechPartOfSpeech partOfSpeech,
                                                          const char *bstrPronunciation);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconAddPronunciationByPhoneIds (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    const char *bstrWord,
                                                                    long langId,
                                                                    enum SpeechLibEnum_SpeechPartOfSpeech partOfSpeech,
                                                                    VARIANT phoneIds);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconRemovePronunciation (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *bstrWord,
                                                             long langId,
                                                             enum SpeechLibEnum_SpeechPartOfSpeech partOfSpeech,
                                                             const char *bstrPronunciation);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconRemovePronunciationByPhoneIds (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       const char *bstrWord,
                                                                       long langId,
                                                                       enum SpeechLibEnum_SpeechPartOfSpeech partOfSpeech,
                                                                       VARIANT phoneIds);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconGetPronunciations (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *bstrWord,
                                                           long langId,
                                                           enum SpeechLibEnum_SpeechLexiconType typeFlags,
                                                           SpeechLibObj_ISpeechLexiconPronunciations *ppPronunciations);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconGetGenerationChange (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *generationId,
                                                             SpeechLibObj_ISpeechLexiconWords *ppWords);

HRESULT CVIFUNC SpeechLib_NewSpLexiconISpLexicon (const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpLexiconISpLexicon (const char *fileName,
                                                   const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpLexiconISpLexicon (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpUnCompressedLexiconISpLexicon (const char *server,
                                                              int supportMultithreading,
                                                              LCID locale,
                                                              int reserved,
                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpUnCompressedLexiconISpLexicon (const char *fileName,
                                                               const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpUnCompressedLexiconISpLexicon (const char *server,
                                                                 int supportMultithreading,
                                                                 LCID locale,
                                                                 int reserved,
                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpCompressedLexiconISpLexicon (const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpCompressedLexiconISpLexicon (const char *fileName,
                                                             const char *server,
                                                             int supportMultithreading,
                                                             LCID locale,
                                                             int reserved,
                                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpCompressedLexiconISpLexicon (const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpLexiconGetGeneration (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned long *pdwGeneration);

HRESULT CVIFUNC SpeechLib_NewISpShortcut (const char *server,
                                          int supportMultithreading, LCID locale,
                                          int reserved,
                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpShortcut (const char *fileName,
                                           const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpShortcut (const char *server,
                                             int supportMultithreading,
                                             LCID locale, int reserved,
                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpShortcutGetGeneration (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    unsigned long *pdwGeneration);

HRESULT CVIFUNC SpeechLib_NewISpeechPhoneConverter (const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechPhoneConverter (const char *fileName,
                                                     const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechPhoneConverter (const char *server,
                                                       int supportMultithreading,
                                                       LCID locale, int reserved,
                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechPhoneConverterGetLanguageId (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *languageId);

HRESULT CVIFUNC SpeechLib_ISpeechPhoneConverterSetLanguageId (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long languageId);

HRESULT CVIFUNC SpeechLib_ISpeechPhoneConverterPhoneToId (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *phonemes,
                                                          VARIANT *idArray);

HRESULT CVIFUNC SpeechLib_ISpeechPhoneConverterIdToPhone (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT idArray,
                                                          char **phonemes);

HRESULT CVIFUNC SpeechLib_NewSpPhoneConverterISpPhoneConverter (const char *server,
                                                                int supportMultithreading,
                                                                LCID locale,
                                                                int reserved,
                                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpPhoneConverterISpPhoneConverter (const char *fileName,
                                                                 const char *server,
                                                                 int supportMultithreading,
                                                                 LCID locale,
                                                                 int reserved,
                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpPhoneConverterISpPhoneConverter (const char *server,
                                                                   int supportMultithreading,
                                                                   LCID locale,
                                                                   int reserved,
                                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_NewSpNullPhoneConverterISpPhoneConverter (const char *server,
                                                                    int supportMultithreading,
                                                                    LCID locale,
                                                                    int reserved,
                                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenSpNullPhoneConverterISpPhoneConverter (const char *fileName,
                                                                     const char *server,
                                                                     int supportMultithreading,
                                                                     LCID locale,
                                                                     int reserved,
                                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveSpNullPhoneConverterISpPhoneConverter (const char *server,
                                                                       int supportMultithreading,
                                                                       LCID locale,
                                                                       int reserved,
                                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpPhoneConverterSetObjectToken (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpObjectToken pToken);

HRESULT CVIFUNC SpeechLib_ISpPhoneConverterGetObjectToken (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpObjectToken *ppToken);

HRESULT CVIFUNC SpeechLib_NewISpPhoneticAlphabetConverter (const char *server,
                                                           int supportMultithreading,
                                                           LCID locale,
                                                           int reserved,
                                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpPhoneticAlphabetConverter (const char *fileName,
                                                            const char *server,
                                                            int supportMultithreading,
                                                            LCID locale,
                                                            int reserved,
                                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpPhoneticAlphabetConverter (const char *server,
                                                              int supportMultithreading,
                                                              LCID locale,
                                                              int reserved,
                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpPhoneticAlphabetConverterGetLangId (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 unsigned short *pLangID);

HRESULT CVIFUNC SpeechLib_ISpPhoneticAlphabetConverterSetLangId (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 unsigned short langId);

HRESULT CVIFUNC SpeechLib_ISpPhoneticAlphabetConverterSAPI2UPS (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned short *pszSAPIId,
                                                                unsigned short *pszUPSId,
                                                                unsigned long cMaxLength);

HRESULT CVIFUNC SpeechLib_ISpPhoneticAlphabetConverterUPS2SAPI (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned short *pszUPSId,
                                                                unsigned short *pszSAPIId,
                                                                unsigned long cMaxLength);

HRESULT CVIFUNC SpeechLib_ISpPhoneticAlphabetConverterGetMaxConvertLength (CAObjHandle objectHandle,
                                                                           ERRORINFO *errorInfo,
                                                                           unsigned long cSrcLength,
                                                                           long bSAPI2UPS,
                                                                           unsigned long *pcMaxDestLength);

HRESULT CVIFUNC SpeechLib_NewISpeechTextSelectionInformation (const char *server,
                                                              int supportMultithreading,
                                                              LCID locale,
                                                              int reserved,
                                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechTextSelectionInformation (const char *fileName,
                                                               const char *server,
                                                               int supportMultithreading,
                                                               LCID locale,
                                                               int reserved,
                                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechTextSelectionInformation (const char *server,
                                                                 int supportMultithreading,
                                                                 LCID locale,
                                                                 int reserved,
                                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechTextSelectionInformationSetActiveOffset (CAObjHandle objectHandle,
                                                                          ERRORINFO *errorInfo,
                                                                          long activeOffset);

HRESULT CVIFUNC SpeechLib_ISpeechTextSelectionInformationGetActiveOffset (CAObjHandle objectHandle,
                                                                          ERRORINFO *errorInfo,
                                                                          long *activeOffset);

HRESULT CVIFUNC SpeechLib_ISpeechTextSelectionInformationSetActiveLength (CAObjHandle objectHandle,
                                                                          ERRORINFO *errorInfo,
                                                                          long activeLength);

HRESULT CVIFUNC SpeechLib_ISpeechTextSelectionInformationGetActiveLength (CAObjHandle objectHandle,
                                                                          ERRORINFO *errorInfo,
                                                                          long *activeLength);

HRESULT CVIFUNC SpeechLib_ISpeechTextSelectionInformationSetSelectionOffset (CAObjHandle objectHandle,
                                                                             ERRORINFO *errorInfo,
                                                                             long selectionOffset);

HRESULT CVIFUNC SpeechLib_ISpeechTextSelectionInformationGetSelectionOffset (CAObjHandle objectHandle,
                                                                             ERRORINFO *errorInfo,
                                                                             long *selectionOffset);

HRESULT CVIFUNC SpeechLib_ISpeechTextSelectionInformationSetSelectionLength (CAObjHandle objectHandle,
                                                                             ERRORINFO *errorInfo,
                                                                             long selectionLength);

HRESULT CVIFUNC SpeechLib_ISpeechTextSelectionInformationGetSelectionLength (CAObjHandle objectHandle,
                                                                             ERRORINFO *errorInfo,
                                                                             long *selectionLength);

HRESULT CVIFUNC SpeechLib_NewISpeechPhraseInfoBuilder (const char *server,
                                                       int supportMultithreading,
                                                       LCID locale, int reserved,
                                                       CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechPhraseInfoBuilder (const char *fileName,
                                                        const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechPhraseInfoBuilder (const char *server,
                                                          int supportMultithreading,
                                                          LCID locale,
                                                          int reserved,
                                                          CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoBuilderRestorePhraseFromMemory (CAObjHandle objectHandle,
                                                                           ERRORINFO *errorInfo,
                                                                           VARIANT phraseInMemory,
                                                                           SpeechLibObj_ISpeechPhraseInfo *phraseInfo);

HRESULT CVIFUNC SpeechLib_NewISpeechAudioFormat (const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechAudioFormat (const char *fileName,
                                                  const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechAudioFormat (const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechAudioFormatGetType (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum SpeechLibEnum_SpeechAudioFormatType *audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechAudioFormatSetType (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum SpeechLibEnum_SpeechAudioFormatType audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechAudioFormatGetGuid (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **guid);

HRESULT CVIFUNC SpeechLib_ISpeechAudioFormatSetGuid (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *guid);

HRESULT CVIFUNC SpeechLib_ISpeechAudioFormatGetWaveFormatEx (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             SpeechLibObj_ISpeechWaveFormatEx *speechWaveFormatEx);

HRESULT CVIFUNC SpeechLib_ISpeechAudioFormatSetWaveFormatEx (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             SpeechLibObj_ISpeechWaveFormatEx speechWaveFormatEx);

HRESULT CVIFUNC SpeechLib_NewISpeechWaveFormatEx (const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechWaveFormatEx (const char *fileName,
                                                   const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechWaveFormatEx (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExGetFormatTag (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           short *formatTag);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExSetFormatTag (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           short formatTag);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExGetChannels (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          short *channels);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExSetChannels (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          short channels);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExGetSamplesPerSec (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *samplesPerSec);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExSetSamplesPerSec (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long samplesPerSec);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExGetAvgBytesPerSec (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *avgBytesPerSec);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExSetAvgBytesPerSec (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long avgBytesPerSec);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExGetBlockAlign (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            short *blockAlign);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExSetBlockAlign (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            short blockAlign);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExGetBitsPerSample (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               short *bitsPerSample);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExSetBitsPerSample (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               short bitsPerSample);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExGetExtraData (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VARIANT *extraData);

HRESULT CVIFUNC SpeechLib_ISpeechWaveFormatExSetExtraData (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VARIANT extraData);

HRESULT CVIFUNC SpeechLib_NewISpeechCustomStream (const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechCustomStream (const char *fileName,
                                                   const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechCustomStream (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechCustomStreamGetFormat (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpeechAudioFormat *audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechCustomStreamSetByRefFormat (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             SpeechLibObj_ISpeechAudioFormat audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechCustomStreamRead (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT *buffer,
                                                   long numberOfBytes,
                                                   long *bytesRead);

HRESULT CVIFUNC SpeechLib_ISpeechCustomStreamWrite (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT buffer,
                                                    long *bytesWritten);

HRESULT CVIFUNC SpeechLib_ISpeechCustomStreamSeek (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT position,
                                                   enum SpeechLibEnum_SpeechStreamSeekPositionType origin,
                                                   VARIANT *newPosition);

HRESULT CVIFUNC SpeechLib_ISpeechCustomStreamGetBaseStream (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            LPUNKNOWN *ppUnkStream);

HRESULT CVIFUNC SpeechLib_ISpeechCustomStreamSetByRefBaseStream (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 LPUNKNOWN ppUnkStream);

HRESULT CVIFUNC SpeechLib_NewISpeechFileStream (const char *server,
                                                int supportMultithreading,
                                                LCID locale, int reserved,
                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechFileStream (const char *fileName,
                                                 const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechFileStream (const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechFileStreamGetFormat (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechAudioFormat *audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechFileStreamSetByRefFormat (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechAudioFormat audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechFileStreamRead (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT *buffer,
                                                 long numberOfBytes,
                                                 long *bytesRead);

HRESULT CVIFUNC SpeechLib_ISpeechFileStreamWrite (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT buffer,
                                                  long *bytesWritten);

HRESULT CVIFUNC SpeechLib_ISpeechFileStreamSeek (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT position,
                                                 enum SpeechLibEnum_SpeechStreamSeekPositionType origin,
                                                 VARIANT *newPosition);

HRESULT CVIFUNC SpeechLib_ISpeechFileStreamOpen (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *fileName,
                                                 enum SpeechLibEnum_SpeechStreamFileMode fileMode,
                                                 VBOOL doEvents);

HRESULT CVIFUNC SpeechLib_ISpeechFileStreamClose (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_NewISpeechMemoryStream (const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_OpenISpeechMemoryStream (const char *fileName,
                                                   const char *server,
                                                   int supportMultithreading,
                                                   LCID locale, int reserved,
                                                   CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ActiveISpeechMemoryStream (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC SpeechLib_ISpeechMemoryStreamGetFormat (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpeechAudioFormat *audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechMemoryStreamSetByRefFormat (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             SpeechLibObj_ISpeechAudioFormat audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechMemoryStreamRead (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT *buffer,
                                                   long numberOfBytes,
                                                   long *bytesRead);

HRESULT CVIFUNC SpeechLib_ISpeechMemoryStreamWrite (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT buffer,
                                                    long *bytesWritten);

HRESULT CVIFUNC SpeechLib_ISpeechMemoryStreamSeek (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT position,
                                                   enum SpeechLibEnum_SpeechStreamSeekPositionType origin,
                                                   VARIANT *newPosition);

HRESULT CVIFUNC SpeechLib_ISpeechMemoryStreamSetData (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT data);

HRESULT CVIFUNC SpeechLib_ISpeechMemoryStreamGetData (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT *pData);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeySetBinaryValue (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *valueName,
                                                        VARIANT value);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeyGetBinaryValue (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *valueName,
                                                        VARIANT *value);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeySetStringValue (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *valueName,
                                                        const char *value);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeyGetStringValue (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *valueName,
                                                        char **value);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeySetLongValue (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *valueName,
                                                      long value);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeyGetLongValue (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *valueName,
                                                      long *value);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeyOpenKey (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *subKeyName,
                                                 SpeechLibObj_ISpeechDataKey *subKey);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeyCreateKey (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *subKeyName,
                                                   SpeechLibObj_ISpeechDataKey *subKey);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeyDeleteKey (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *subKeyName);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeyDeleteValue (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *valueName);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeyEnumKeys (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long index, char **subKeyName);

HRESULT CVIFUNC SpeechLib_ISpeechDataKeyEnumValues (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long index, char **valueName);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokensGetCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *count);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokensItem (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long index,
                                                   SpeechLibObj_ISpeechObjectToken *token);

HRESULT CVIFUNC SpeechLib_ISpeechObjectTokensGet_NewEnum (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          LPUNKNOWN *ppEnumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechAudioBufferInfoGetMinNotification (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    long *minNotification);

HRESULT CVIFUNC SpeechLib_ISpeechAudioBufferInfoSetMinNotification (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    long minNotification);

HRESULT CVIFUNC SpeechLib_ISpeechAudioBufferInfoGetBufferSize (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *bufferSize);

HRESULT CVIFUNC SpeechLib_ISpeechAudioBufferInfoSetBufferSize (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long bufferSize);

HRESULT CVIFUNC SpeechLib_ISpeechAudioBufferInfoGetEventBias (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *eventBias);

HRESULT CVIFUNC SpeechLib_ISpeechAudioBufferInfoSetEventBias (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long eventBias);

HRESULT CVIFUNC SpeechLib_ISpeechAudioStatusGetFreeBufferSpace (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *freeBufferSpace);

HRESULT CVIFUNC SpeechLib_ISpeechAudioStatusGetNonBlockingIO (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *nonBlockingIO);

HRESULT CVIFUNC SpeechLib_ISpeechAudioStatusGetState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum SpeechLibEnum_SpeechAudioState *state);

HRESULT CVIFUNC SpeechLib_ISpeechAudioStatusGetCurrentSeekPosition (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VARIANT *currentSeekPosition);

HRESULT CVIFUNC SpeechLib_ISpeechAudioStatusGetCurrentDevicePosition (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VARIANT *currentDevicePosition);

HRESULT CVIFUNC SpeechLib_ISpeechBaseStreamGetFormat (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechAudioFormat *audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechBaseStreamSetByRefFormat (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechAudioFormat audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechBaseStreamRead (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT *buffer,
                                                 long numberOfBytes,
                                                 long *bytesRead);

HRESULT CVIFUNC SpeechLib_ISpeechBaseStreamWrite (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT buffer,
                                                  long *bytesWritten);

HRESULT CVIFUNC SpeechLib_ISpeechBaseStreamSeek (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT position,
                                                 enum SpeechLibEnum_SpeechStreamSeekPositionType origin,
                                                 VARIANT *newPosition);

HRESULT CVIFUNC SpeechLib_ISpeechAudioGetFormat (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 SpeechLibObj_ISpeechAudioFormat *audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechAudioSetByRefFormat (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechAudioFormat audioFormat);

HRESULT CVIFUNC SpeechLib_ISpeechAudioRead (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            VARIANT *buffer, long numberOfBytes,
                                            long *bytesRead);

HRESULT CVIFUNC SpeechLib_ISpeechAudioWrite (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VARIANT buffer, long *bytesWritten);

HRESULT CVIFUNC SpeechLib_ISpeechAudioSeek (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            VARIANT position,
                                            enum SpeechLibEnum_SpeechStreamSeekPositionType origin,
                                            VARIANT *newPosition);

HRESULT CVIFUNC SpeechLib_ISpeechAudioGetStatus (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 SpeechLibObj_ISpeechAudioStatus *status);

HRESULT CVIFUNC SpeechLib_ISpeechAudioGetBufferInfo (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     SpeechLibObj_ISpeechAudioBufferInfo *bufferInfo);

HRESULT CVIFUNC SpeechLib_ISpeechAudioGetDefaultFormat (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpeechAudioFormat *streamFormat);

HRESULT CVIFUNC SpeechLib_ISpeechAudioGetVolume (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long *volume);

HRESULT CVIFUNC SpeechLib_ISpeechAudioSetVolume (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 long volume);

HRESULT CVIFUNC SpeechLib_ISpeechAudioGetBufferNotifySize (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *bufferNotifySize);

HRESULT CVIFUNC SpeechLib_ISpeechAudioSetBufferNotifySize (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long bufferNotifySize);

HRESULT CVIFUNC SpeechLib_ISpeechAudioGetEventHandle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *eventHandle);

HRESULT CVIFUNC SpeechLib_ISpeechAudioSetState (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                enum SpeechLibEnum_SpeechAudioState state);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetCurrentStreamNumber (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    long *streamNumber);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetLastStreamNumberQueued (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       long *streamNumber);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetLastHResult (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *HResult);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetRunningState (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             enum SpeechLibEnum_SpeechRunState *state);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetInputWordPosition (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long *position);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetInputWordLength (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *length);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetInputSentencePosition (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      long *position);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetInputSentenceLength (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    long *length);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetLastBookmark (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             char **bookmark);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetLastBookmarkId (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *bookmarkId);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetPhonemeId (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          short *phoneId);

HRESULT CVIFUNC SpeechLib_ISpeechVoiceStatusGetVisemeId (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         short *visemeId);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerStatusGetAudioStatus (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 SpeechLibObj_ISpeechAudioStatus *audioStatus);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerStatusGetCurrentStreamPosition (CAObjHandle objectHandle,
                                                                           ERRORINFO *errorInfo,
                                                                           VARIANT *pCurrentStreamPos);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerStatusGetCurrentStreamNumber (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         long *streamNumber);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerStatusGetNumberOfActiveRules (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         long *numberOfActiveRules);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerStatusGetClsidEngine (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 char **clsidEngine);

HRESULT CVIFUNC SpeechLib_ISpeechRecognizerStatusGetSupportedLanguages (CAObjHandle objectHandle,
                                                                        ERRORINFO *errorInfo,
                                                                        VARIANT *supportedLanguages);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarGetId (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT *id);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarGetRecoContext (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpeechRecoContext *recoContext);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarSetState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum SpeechLibEnum_SpeechGrammarState state);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarGetState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum SpeechLibEnum_SpeechGrammarState *state);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarGetRules (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechGrammarRules *rules);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarReset (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long newLanguage);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarCmdLoadFromFile (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *fileName,
                                                             enum SpeechLibEnum_SpeechLoadOption loadOption);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarCmdLoadFromObject (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               const char *classId,
                                                               const char *grammarName,
                                                               enum SpeechLibEnum_SpeechLoadOption loadOption);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarCmdLoadFromResource (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 long hModule,
                                                                 VARIANT resourceName,
                                                                 VARIANT resourceType,
                                                                 long languageId,
                                                                 enum SpeechLibEnum_SpeechLoadOption loadOption);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarCmdLoadFromMemory (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VARIANT grammarData,
                                                               enum SpeechLibEnum_SpeechLoadOption loadOption);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarCmdLoadFromProprietaryGrammar (CAObjHandle objectHandle,
                                                                           ERRORINFO *errorInfo,
                                                                           const char *proprietaryGuid,
                                                                           const char *proprietaryString,
                                                                           VARIANT proprietaryData,
                                                                           enum SpeechLibEnum_SpeechLoadOption loadOption);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarCmdSetRuleState (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *name,
                                                             enum SpeechLibEnum_SpeechRuleState state);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarCmdSetRuleIdState (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long ruleId,
                                                               enum SpeechLibEnum_SpeechRuleState state);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarDictationLoad (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *topicName,
                                                           enum SpeechLibEnum_SpeechLoadOption loadOption);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarDictationUnload (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarDictationSetState (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum SpeechLibEnum_SpeechRuleState state);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarSetWordSequenceData (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 const char *text,
                                                                 long textLength,
                                                                 SpeechLibObj_ISpeechTextSelectionInformation info);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarSetTextSelection (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              SpeechLibObj_ISpeechTextSelectionInformation info);

HRESULT CVIFUNC SpeechLib_ISpeechRecoGrammarIsPronounceable (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *word,
                                                             enum SpeechLibEnum_SpeechWordPronounceable *wordPronounceable);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRulesGetCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *count);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRulesFindRule (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT ruleNameOrId,
                                                       SpeechLibObj_ISpeechGrammarRule *rule);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRulesItem (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long index,
                                                   SpeechLibObj_ISpeechGrammarRule *rule);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRulesGet_NewEnum (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          LPUNKNOWN *enumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRulesGetDynamic (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *dynamic);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRulesAdd (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  const char *ruleName,
                                                  enum SpeechLibEnum_SpeechRuleAttributes attributes,
                                                  long ruleId,
                                                  SpeechLibObj_ISpeechGrammarRule *rule);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRulesCommit (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRulesCommitAndSave (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            char **errorText,
                                                            VARIANT *saveStream);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleGetAttributes (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           enum SpeechLibEnum_SpeechRuleAttributes *attributes);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleGetInitialState (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             SpeechLibObj_ISpeechGrammarRuleState *state);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleGetName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **name);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleGetId (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *id);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleClear (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleAddResource (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *resourceName,
                                                         const char *resourceValue);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleAddState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechGrammarRuleState *state);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateGetRule (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          SpeechLibObj_ISpeechGrammarRule *rule);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateGetTransitions (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 SpeechLibObj_ISpeechGrammarRuleStateTransitions *transitions);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateAddWordTransition (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    SpeechLibObj_ISpeechGrammarRuleState destState,
                                                                    const char *words,
                                                                    const char *separators,
                                                                    enum SpeechLibEnum_SpeechGrammarWordType type,
                                                                    const char *propertyName,
                                                                    long propertyId,
                                                                    VARIANT propertyValue,
                                                                    float weight);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateAddRuleTransition (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    SpeechLibObj_ISpeechGrammarRuleState destinationState,
                                                                    SpeechLibObj_ISpeechGrammarRule rule,
                                                                    const char *propertyName,
                                                                    long propertyId,
                                                                    VARIANT propertyValue,
                                                                    float weight);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateAddSpecialTransition (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       SpeechLibObj_ISpeechGrammarRuleState destinationState,
                                                                       enum SpeechLibEnum_SpeechSpecialTransitionType type,
                                                                       const char *propertyName,
                                                                       long propertyId,
                                                                       VARIANT propertyValue,
                                                                       float weight);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionsGetCount (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      long *count);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionsItem (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long index,
                                                                  SpeechLibObj_ISpeechGrammarRuleStateTransition *transition);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionsGet_NewEnum (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         LPUNKNOWN *enumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionGetType (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum SpeechLibEnum_SpeechGrammarRuleStateTransitionType *type);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionGetText (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    char **text);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionGetRule (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    SpeechLibObj_ISpeechGrammarRule *rule);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionGetWeight (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VARIANT *weight);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionGetPropertyName (CAObjHandle objectHandle,
                                                                            ERRORINFO *errorInfo,
                                                                            char **propertyName);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionGetPropertyId (CAObjHandle objectHandle,
                                                                          ERRORINFO *errorInfo,
                                                                          long *propertyId);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionGetPropertyValue (CAObjHandle objectHandle,
                                                                             ERRORINFO *errorInfo,
                                                                             VARIANT *propertyValue);

HRESULT CVIFUNC SpeechLib_ISpeechGrammarRuleStateTransitionGetNextState (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         SpeechLibObj_ISpeechGrammarRuleState *nextState);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultGetRecoContext (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechRecoContext *recoContext);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultGetTimes (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     SpeechLibObj_ISpeechRecoResultTimes *times);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultSetByRefAudioFormat (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                SpeechLibObj_ISpeechAudioFormat format);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultGetAudioFormat (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechAudioFormat *format);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultGetPhraseInfo (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          SpeechLibObj_ISpeechPhraseInfo *phraseInfo);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultAlternates (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long requestCount,
                                                       long startElement,
                                                       long elements,
                                                       SpeechLibObj_ISpeechPhraseAlternates *alternates);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultAudio (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long startElement,
                                                  long elements,
                                                  SpeechLibObj_ISpeechMemoryStream *stream);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultSpeakAudio (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long startElement,
                                                       long elements,
                                                       enum SpeechLibEnum_SpeechVoiceSpeakFlags flags,
                                                       long *streamNumber);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultSaveToMemory (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *resultBlock);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDiscardResultInfo (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              enum SpeechLibEnum_SpeechDiscardType valueTypes);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultTimesGetStreamTime (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VARIANT *time);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultTimesGetLength (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VARIANT *length);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultTimesGetTickCount (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *tickCount);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultTimesGetOffsetFromStart (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VARIANT *offsetFromStart);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetLanguageId (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *languageId);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetGrammarId (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *grammarId);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetStartTime (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *startTime);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetAudioStreamPosition (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VARIANT *audioStreamPosition);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetAudioSizeBytes (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pAudioSizeBytes);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetRetainedSizeBytes (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 long *retainedSizeBytes);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetAudioSizeTime (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *audioSizeTime);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetRule (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    SpeechLibObj_ISpeechPhraseRule *rule);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetProperties (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          SpeechLibObj_ISpeechPhraseProperties *properties);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetElements (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpeechPhraseElements *elements);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetReplacements (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpeechPhraseReplacements *replacements);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetEngineId (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **engineIdGuid);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetEnginePrivateData (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VARIANT *privateData);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoSaveToMemory (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *phraseBlock);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetText (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long startElement,
                                                    long elements,
                                                    VBOOL useReplacements,
                                                    char **text);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseInfoGetDisplayAttributes (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 long startElement,
                                                                 long elements,
                                                                 VBOOL useReplacements,
                                                                 enum SpeechLibEnum_SpeechDisplayAttributes *displayAttributes);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRuleGetName (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **name);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRuleGetId (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo, long *id);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRuleGetFirstElement (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *firstElement);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRuleGetNumberOfElements (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *numberOfElements);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRuleGetParent (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechPhraseRule *parent);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRuleGetChildren (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpeechPhraseRules *children);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRuleGetConfidence (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum SpeechLibEnum_SpeechEngineConfidence *actualConfidence);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRuleGetEngineConfidence (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                float *engineConfidence);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRulesGetCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *count);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRulesItem (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long index,
                                                  SpeechLibObj_ISpeechPhraseRule *rule);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseRulesGet_NewEnum (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         LPUNKNOWN *enumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertiesGetCount (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *count);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertiesItem (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long index,
                                                       SpeechLibObj_ISpeechPhraseProperty *property);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertiesGet_NewEnum (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              LPUNKNOWN *enumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertyGetName (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **name);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertyGetId (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *id);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertyGetValue (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *value);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertyGetFirstElement (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *firstElement);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertyGetNumberOfElements (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    long *numberOfElements);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertyGetEngineConfidence (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    float *confidence);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertyGetConfidence (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              enum SpeechLibEnum_SpeechEngineConfidence *confidence);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertyGetParent (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          SpeechLibObj_ISpeechPhraseProperty *parentProperty);

HRESULT CVIFUNC SpeechLib_ISpeechPhrasePropertyGetChildren (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpeechPhraseProperties *children);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementsGetCount (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *count);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementsItem (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long index,
                                                     SpeechLibObj_ISpeechPhraseElement *element);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementsGet_NewEnum (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            LPUNKNOWN *enumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetAudioTimeOffset (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long *audioTimeOffset);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetAudioSizeTime (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *audioSizeTime);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetAudioStreamOffset (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    long *audioStreamOffset);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetAudioSizeBytes (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 long *audioSizeBytes);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetRetainedStreamOffset (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       long *retainedStreamOffset);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetRetainedSizeBytes (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    long *retainedSizeBytes);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetDisplayText (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              char **displayText);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetLexicalForm (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              char **lexicalForm);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetPronunciation (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT *pronunciation);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetDisplayAttributes (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum SpeechLibEnum_SpeechDisplayAttributes *displayAttributes);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetRequiredConfidence (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     enum SpeechLibEnum_SpeechEngineConfidence *requiredConfidence);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetActualConfidence (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   enum SpeechLibEnum_SpeechEngineConfidence *actualConfidence);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseElementGetEngineConfidence (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   float *engineConfidence);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseReplacementsGetCount (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *count);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseReplacementsItem (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long index,
                                                         SpeechLibObj_ISpeechPhraseReplacement *reps);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseReplacementsGet_NewEnum (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                LPUNKNOWN *enumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseReplacementGetDisplayAttributes (CAObjHandle objectHandle,
                                                                        ERRORINFO *errorInfo,
                                                                        enum SpeechLibEnum_SpeechDisplayAttributes *displayAttributes);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseReplacementGetText (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **text);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseReplacementGetFirstElement (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   long *firstElement);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseReplacementGetNumberOfElements (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       long *numberOfElements);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseAlternatesGetCount (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *count);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseAlternatesItem (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long index,
                                                       SpeechLibObj_ISpeechPhraseAlternate *phraseAlternate);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseAlternatesGet_NewEnum (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              LPUNKNOWN *enumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseAlternateGetRecoResult (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               SpeechLibObj_ISpeechRecoResult *recoResult);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseAlternateGetStartElementInResult (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         long *startElement);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseAlternateGetNumberOfElementsInResult (CAObjHandle objectHandle,
                                                                             ERRORINFO *errorInfo,
                                                                             long *numberOfElements);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseAlternateGetPhraseInfo (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               SpeechLibObj_ISpeechPhraseInfo *phraseInfo);

HRESULT CVIFUNC SpeechLib_ISpeechPhraseAlternateCommit (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2GetRecoContext (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpeechRecoContext *recoContext);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2GetTimes (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      SpeechLibObj_ISpeechRecoResultTimes *times);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2SetByRefAudioFormat (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 SpeechLibObj_ISpeechAudioFormat format);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2GetAudioFormat (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            SpeechLibObj_ISpeechAudioFormat *format);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2GetPhraseInfo (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechPhraseInfo *phraseInfo);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2Alternates (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long requestCount,
                                                        long startElement,
                                                        long elements,
                                                        SpeechLibObj_ISpeechPhraseAlternates *alternates);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2Audio (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long startElement,
                                                   long elements,
                                                   SpeechLibObj_ISpeechMemoryStream *stream);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2SpeakAudio (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long startElement,
                                                        long elements,
                                                        enum SpeechLibEnum_SpeechVoiceSpeakFlags flags,
                                                        long *streamNumber);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2SaveToMemory (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT *resultBlock);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2DiscardResultInfo (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum SpeechLibEnum_SpeechDiscardType valueTypes);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResult2SetTextFeedback (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *feedback,
                                                             VBOOL wasSuccessful);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconWordsGetCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *count);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconWordsItem (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long index,
                                                   SpeechLibObj_ISpeechLexiconWord *word);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconWordsGet_NewEnum (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          LPUNKNOWN *enumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconWordGetLangId (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *langId);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconWordGetType (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum SpeechLibEnum_SpeechWordType *wordType);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconWordGetWord (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **word);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconWordGetPronunciations (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               SpeechLibObj_ISpeechLexiconPronunciations *pronunciations);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconPronunciationsGetCount (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *count);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconPronunciationsItem (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long index,
                                                            SpeechLibObj_ISpeechLexiconPronunciation *pronunciation);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconPronunciationsGet_NewEnum (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   LPUNKNOWN *enumVARIANT);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconPronunciationGetType (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              enum SpeechLibEnum_SpeechLexiconType *lexiconType);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconPronunciationGetLangId (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *langId);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconPronunciationGetPartOfSpeech (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      enum SpeechLibEnum_SpeechPartOfSpeech *partOfSpeech);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconPronunciationGetPhoneIds (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VARIANT *phoneIds);

HRESULT CVIFUNC SpeechLib_ISpeechLexiconPronunciationGetSymbolic (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  char **symbolic);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultGetRecoContext (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              SpeechLibObj_ISpeechRecoContext *recoContext);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultGetTimes (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpeechRecoResultTimes *times);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultSetByRefAudioFormat (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   SpeechLibObj_ISpeechAudioFormat format);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultGetAudioFormat (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              SpeechLibObj_ISpeechAudioFormat *format);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultGetPhraseInfo (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             SpeechLibObj_ISpeechPhraseInfo *phraseInfo);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultAlternates (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long requestCount,
                                                          long startElement,
                                                          long elements,
                                                          SpeechLibObj_ISpeechPhraseAlternates *alternates);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultAudio (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long startElement,
                                                     long elements,
                                                     SpeechLibObj_ISpeechMemoryStream *stream);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultSpeakAudio (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long startElement,
                                                          long elements,
                                                          enum SpeechLibEnum_SpeechVoiceSpeakFlags flags,
                                                          long *streamNumber);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultSaveToMemory (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT *resultBlock);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultDiscardResultInfo (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum SpeechLibEnum_SpeechDiscardType valueTypes);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultGetXMLResult (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum SpeechLibEnum_SPXMLRESULTOPTIONS options,
                                                            char **pResult);

HRESULT CVIFUNC SpeechLib_ISpeechXMLRecoResultGetXMLErrorInfo (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *lineNumber,
                                                               char **scriptLine,
                                                               char **source,
                                                               char **description,
                                                               long *resultCode,
                                                               VBOOL *isError);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchGetRecoContext (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   SpeechLibObj_ISpeechRecoContext *recoContext);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchGetTimes (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             SpeechLibObj_ISpeechRecoResultTimes *times);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchSetByRefAudioFormat (CAObjHandle objectHandle,
                                                                        ERRORINFO *errorInfo,
                                                                        SpeechLibObj_ISpeechAudioFormat format);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchGetAudioFormat (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   SpeechLibObj_ISpeechAudioFormat *format);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchGetPhraseInfo (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  SpeechLibObj_ISpeechPhraseInfo *phraseInfo);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchAlternates (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long requestCount,
                                                               long startElement,
                                                               long elements,
                                                               SpeechLibObj_ISpeechPhraseAlternates *alternates);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchAudio (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long startElement,
                                                          long elements,
                                                          SpeechLibObj_ISpeechMemoryStream *stream);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchSpeakAudio (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long startElement,
                                                               long elements,
                                                               enum SpeechLibEnum_SpeechVoiceSpeakFlags flags,
                                                               long *streamNumber);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchSaveToMemory (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VARIANT *resultBlock);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchDiscardResultInfo (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      enum SpeechLibEnum_SpeechDiscardType valueTypes);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchGetXMLResult (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum SpeechLibEnum_SPXMLRESULTOPTIONS options,
                                                                 char **pResult);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchGetXMLErrorInfo (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    long *lineNumber,
                                                                    char **scriptLine,
                                                                    char **source,
                                                                    char **description,
                                                                    long *resultCode,
                                                                    VBOOL *isError);

HRESULT CVIFUNC SpeechLib_ISpeechRecoResultDispatchSetTextFeedback (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    const char *feedback,
                                                                    VBOOL wasSuccessful);

HRESULT CVIFUNC SpeechLib_ISpNotifySinkNotify (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatRemoteRead (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     unsigned char *pv,
                                                     unsigned long cb,
                                                     unsigned long *pcbRead);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatRemoteWrite (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      unsigned char *pv,
                                                      unsigned long cb,
                                                      unsigned long *pcbWritten);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatCommit (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 unsigned long grfCommitFlags);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatRevert (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpStreamFormatClone (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                SpeechLibObj_IStream *ppstm);

HRESULT CVIFUNC SpeechLib_IStreamRemoteRead (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             unsigned char *pv, unsigned long cb,
                                             unsigned long *pcbRead);

HRESULT CVIFUNC SpeechLib_IStreamRemoteWrite (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              unsigned char *pv,
                                              unsigned long cb,
                                              unsigned long *pcbWritten);

HRESULT CVIFUNC SpeechLib_IStreamCommit (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo,
                                         unsigned long grfCommitFlags);

HRESULT CVIFUNC SpeechLib_IStreamRevert (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_IStreamClone (CAObjHandle objectHandle,
                                        ERRORINFO *errorInfo,
                                        SpeechLibObj_IStream *ppstm);

HRESULT CVIFUNC SpeechLib_ISequentialStreamRemoteRead (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       unsigned char *pv,
                                                       unsigned long cb,
                                                       unsigned long *pcbRead);

HRESULT CVIFUNC SpeechLib_ISequentialStreamRemoteWrite (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        unsigned char *pv,
                                                        unsigned long cb,
                                                        unsigned long *pcbWritten);

HRESULT CVIFUNC SpeechLib_ISpNotifySourceSetNotifySink (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpNotifySink pNotifySink);

HRESULT CVIFUNC SpeechLib_ISpNotifySourceSetNotifyWin32Event (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpNotifySourceWaitForNotifyEvent (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             unsigned long dwMilliseconds);

HRESULT CVIFUNC SpeechLib_ISpNotifySourceGetNotifyEventHandle (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpAudioRemoteRead (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              unsigned char *pv,
                                              unsigned long cb,
                                              unsigned long *pcbRead);

HRESULT CVIFUNC SpeechLib_ISpAudioRemoteWrite (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned char *pv,
                                               unsigned long cb,
                                               unsigned long *pcbWritten);

HRESULT CVIFUNC SpeechLib_ISpAudioCommit (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo,
                                          unsigned long grfCommitFlags);

HRESULT CVIFUNC SpeechLib_ISpAudioRevert (CAObjHandle objectHandle,
                                          ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpAudioClone (CAObjHandle objectHandle,
                                         ERRORINFO *errorInfo,
                                         SpeechLibObj_IStream *ppstm);

HRESULT CVIFUNC SpeechLib_ISpAudioEventHandle (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpAudioGetVolumeLevel (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  unsigned long *pLevel);

HRESULT CVIFUNC SpeechLib_ISpAudioSetVolumeLevel (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  unsigned long level);

HRESULT CVIFUNC SpeechLib_ISpAudioGetBufferNotifySize (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       unsigned long *pcbSize);

HRESULT CVIFUNC SpeechLib_ISpAudioSetBufferNotifySize (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       unsigned long cbSize);

HRESULT CVIFUNC SpeechLib_ISpPhraseDiscard (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            unsigned long dwValueTypes);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammarResetGrammar (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      unsigned short newLanguage);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammarClearRule (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   void *hState);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammarCommit (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                unsigned long dwReserved);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammarGetRecoContext (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        SpeechLibObj_ISpRecoContext *ppRecoCtxt);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammarSetRuleIdState (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        unsigned long ulRuleId,
                                                        enum SpeechLibEnum_SPRULESTATE newState);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammarUnloadDictation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammarSetDictationState (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           enum SpeechLibEnum_SPRULESTATE newState);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammarSetGrammarState (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum SpeechLibEnum_SPGRAMMARSTATE eGrammarState);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammarGetGrammarState (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum SpeechLibEnum_SPGRAMMARSTATE *peGrammarState);

HRESULT CVIFUNC SpeechLib_ISpGrammarBuilderResetGrammar (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         unsigned short newLanguage);

HRESULT CVIFUNC SpeechLib_ISpGrammarBuilderClearRule (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      void *hState);

HRESULT CVIFUNC SpeechLib_ISpGrammarBuilderCommit (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned long dwReserved);

HRESULT CVIFUNC SpeechLib_ISpRecoResultDiscard (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                unsigned long dwValueTypes);

HRESULT CVIFUNC SpeechLib_ISpRecoResultGetAlternates (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      unsigned long ulStartElement,
                                                      unsigned long cElements,
                                                      unsigned long ulRequestCount,
                                                      SpeechLibObj_ISpPhraseAlt *ppPhrases,
                                                      unsigned long *pcPhrasesReturned);

HRESULT CVIFUNC SpeechLib_ISpRecoResultGetAudio (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 unsigned long ulStartElement,
                                                 unsigned long cElements,
                                                 SpeechLibObj_ISpStreamFormat *ppStream);

HRESULT CVIFUNC SpeechLib_ISpRecoResultSpeakAudio (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned long ulStartElement,
                                                   unsigned long cElements,
                                                   unsigned long dwFlags,
                                                   unsigned long *pulStreamNumber);

HRESULT CVIFUNC SpeechLib_ISpRecoResultGetRecoContext (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       SpeechLibObj_ISpRecoContext *ppRecoContext);

HRESULT CVIFUNC SpeechLib_ISpPhraseAltDiscard (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               unsigned long dwValueTypes);

HRESULT CVIFUNC SpeechLib_ISpPhraseAltGetAltInfo (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  SpeechLibObj_ISpPhrase *ppParent,
                                                  unsigned long *pulStartElementInParent,
                                                  unsigned long *pcElementsInParent,
                                                  unsigned long *pcElementsInAlt);

HRESULT CVIFUNC SpeechLib_ISpPhraseAltCommit (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_ISpRecoCategoryGetType (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum SpeechLibEnum_SPCATEGORYTYPE *peCategoryType);

HRESULT CVIFUNC SpeechLib_ISpXMLRecoResultDiscard (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   unsigned long dwValueTypes);

HRESULT CVIFUNC SpeechLib_ISpXMLRecoResultGetAlternates (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         unsigned long ulStartElement,
                                                         unsigned long cElements,
                                                         unsigned long ulRequestCount,
                                                         SpeechLibObj_ISpPhraseAlt *ppPhrases,
                                                         unsigned long *pcPhrasesReturned);

HRESULT CVIFUNC SpeechLib_ISpXMLRecoResultGetAudio (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    unsigned long ulStartElement,
                                                    unsigned long cElements,
                                                    SpeechLibObj_ISpStreamFormat *ppStream);

HRESULT CVIFUNC SpeechLib_ISpXMLRecoResultSpeakAudio (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      unsigned long ulStartElement,
                                                      unsigned long cElements,
                                                      unsigned long dwFlags,
                                                      unsigned long *pulStreamNumber);

HRESULT CVIFUNC SpeechLib_ISpXMLRecoResultGetRecoContext (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          SpeechLibObj_ISpRecoContext *ppRecoContext);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammar2SetDictationWeight (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             float flWeight);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammar2SetGrammarLoader (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           SpeechLibObj_ISpeechResourceLoader pLoader);

HRESULT CVIFUNC SpeechLib_ISpRecoGrammar2SetSMLSecurityManager (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                SpeechLibObj_IInternetSecurityManager pSMLSecurityManager);

HRESULT CVIFUNC SpeechLib_ISpeechResourceLoaderLoadResource (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *bstrResourceUri,
                                                             VBOOL fAlwaysReload,
                                                             LPUNKNOWN *pStream,
                                                             char **pbstrMIMEType,
                                                             VBOOL *pfModified,
                                                             char **pbstrRedirectUrl);

HRESULT CVIFUNC SpeechLib_ISpeechResourceLoaderGetLocalCopy (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             const char *bstrResourceUri,
                                                             char **pbstrLocalPath,
                                                             char **pbstrMIMEType,
                                                             char **pbstrRedirectUrl);

HRESULT CVIFUNC SpeechLib_ISpeechResourceLoaderReleaseLocalCopy (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 const char *pbstrLocalPath);

HRESULT CVIFUNC SpeechLib_IInternetSecurityManagerSetSecuritySite (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   SpeechLibObj_IInternetSecurityMgrSite pSite);

HRESULT CVIFUNC SpeechLib_IInternetSecurityManagerGetSecuritySite (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   SpeechLibObj_IInternetSecurityMgrSite *ppSite);

HRESULT CVIFUNC SpeechLib_IInternetSecurityManagerGetZoneMappings (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   unsigned long dwZone,
                                                                   SpeechLibObj_IEnumString *ppenumString,
                                                                   unsigned long dwFlags);

HRESULT CVIFUNC SpeechLib_IInternetSecurityMgrSiteEnableModeless (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long fEnable);

HRESULT CVIFUNC SpeechLib_IEnumStringSkip (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           unsigned long celt);

HRESULT CVIFUNC SpeechLib_IEnumStringReset (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC SpeechLib_IEnumStringClone (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo,
                                            SpeechLibObj_IEnumString *ppEnum);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnStartStream (CAObjHandle serverObject,
                                                               _ISpeechVoiceEventsRegOnStartStream_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnEndStream (CAObjHandle serverObject,
                                                             _ISpeechVoiceEventsRegOnEndStream_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnVoiceChange (CAObjHandle serverObject,
                                                               _ISpeechVoiceEventsRegOnVoiceChange_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnBookmark (CAObjHandle serverObject,
                                                            _ISpeechVoiceEventsRegOnBookmark_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnWord (CAObjHandle serverObject,
                                                        _ISpeechVoiceEventsRegOnWord_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnSentence (CAObjHandle serverObject,
                                                            _ISpeechVoiceEventsRegOnSentence_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnPhoneme (CAObjHandle serverObject,
                                                           _ISpeechVoiceEventsRegOnPhoneme_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnViseme (CAObjHandle serverObject,
                                                          _ISpeechVoiceEventsRegOnViseme_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnAudioLevel (CAObjHandle serverObject,
                                                              _ISpeechVoiceEventsRegOnAudioLevel_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechVoiceEventsRegOnEnginePrivate (CAObjHandle serverObject,
                                                                 _ISpeechVoiceEventsRegOnEnginePrivate_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnStartStream (CAObjHandle serverObject,
                                                                     _ISpeechRecoContextEventsRegOnStartStream_CallbackType callbackFunction,
                                                                     void *callbackData,
                                                                     int enableCallbacks,
                                                                     int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnEndStream (CAObjHandle serverObject,
                                                                   _ISpeechRecoContextEventsRegOnEndStream_CallbackType callbackFunction,
                                                                   void *callbackData,
                                                                   int enableCallbacks,
                                                                   int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnBookmark (CAObjHandle serverObject,
                                                                  _ISpeechRecoContextEventsRegOnBookmark_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnSoundStart (CAObjHandle serverObject,
                                                                    _ISpeechRecoContextEventsRegOnSoundStart_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnSoundEnd (CAObjHandle serverObject,
                                                                  _ISpeechRecoContextEventsRegOnSoundEnd_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnPhraseStart (CAObjHandle serverObject,
                                                                     _ISpeechRecoContextEventsRegOnPhraseStart_CallbackType callbackFunction,
                                                                     void *callbackData,
                                                                     int enableCallbacks,
                                                                     int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnRecognition (CAObjHandle serverObject,
                                                                     _ISpeechRecoContextEventsRegOnRecognition_CallbackType callbackFunction,
                                                                     void *callbackData,
                                                                     int enableCallbacks,
                                                                     int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnHypothesis (CAObjHandle serverObject,
                                                                    _ISpeechRecoContextEventsRegOnHypothesis_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnPropertyNumberChange (CAObjHandle serverObject,
                                                                              _ISpeechRecoContextEventsRegOnPropertyNumberChange_CallbackType callbackFunction,
                                                                              void *callbackData,
                                                                              int enableCallbacks,
                                                                              int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnPropertyStringChange (CAObjHandle serverObject,
                                                                              _ISpeechRecoContextEventsRegOnPropertyStringChange_CallbackType callbackFunction,
                                                                              void *callbackData,
                                                                              int enableCallbacks,
                                                                              int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnFalseRecognition (CAObjHandle serverObject,
                                                                          _ISpeechRecoContextEventsRegOnFalseRecognition_CallbackType callbackFunction,
                                                                          void *callbackData,
                                                                          int enableCallbacks,
                                                                          int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnInterference (CAObjHandle serverObject,
                                                                      _ISpeechRecoContextEventsRegOnInterference_CallbackType callbackFunction,
                                                                      void *callbackData,
                                                                      int enableCallbacks,
                                                                      int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnRequestUI (CAObjHandle serverObject,
                                                                   _ISpeechRecoContextEventsRegOnRequestUI_CallbackType callbackFunction,
                                                                   void *callbackData,
                                                                   int enableCallbacks,
                                                                   int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnRecognizerStateChange (CAObjHandle serverObject,
                                                                               _ISpeechRecoContextEventsRegOnRecognizerStateChange_CallbackType callbackFunction,
                                                                               void *callbackData,
                                                                               int enableCallbacks,
                                                                               int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnAdaptation (CAObjHandle serverObject,
                                                                    _ISpeechRecoContextEventsRegOnAdaptation_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnRecognitionForOtherContext (CAObjHandle serverObject,
                                                                                    _ISpeechRecoContextEventsRegOnRecognitionForOtherContext_CallbackType callbackFunction,
                                                                                    void *callbackData,
                                                                                    int enableCallbacks,
                                                                                    int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnAudioLevel (CAObjHandle serverObject,
                                                                    _ISpeechRecoContextEventsRegOnAudioLevel_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId);

HRESULT CVIFUNC SpeechLib__ISpeechRecoContextEventsRegOnEnginePrivate (CAObjHandle serverObject,
                                                                       _ISpeechRecoContextEventsRegOnEnginePrivate_CallbackType callbackFunction,
                                                                       void *callbackData,
                                                                       int enableCallbacks,
                                                                       int *callbackId);

#ifdef __cplusplus
    }
#endif
#endif /* _SPEECHLIB_H */