[!/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Gtm_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\76 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  BSW Module Description : Mcu.xdm                                          **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: 
    [cover parentID=DS_NAS_GTM_PR655,DS_NAS_GTM_PR741,DS_NAS_GTM_PR739,
    DS_NAS_GTM_PR446,SAS_NAS_GTM_PR63_PR65,SAS_NAS_GTM_PR64,SAS_NAS_GTM_PR77
    SAS_NAS_GTM_PR63_1,SAS_NAS_GTM_PR63_2,SAS_NAS_GTM_PR63_3,SAS_NAS_GTM_PR63_4,
    SAS_NAS_GTM_PR63_5,SAS_NAS_GTM_PR63_6,SAS_NAS_GTM_PR63_7,SAS_NAS_GTM_PR63_8,
    SAS_NAS_GTM_PR63_9,SAS_NAS_GTM_PR63_10,SAS_NAS_GTM_PR63_11,
    SAS_NAS_GTM_PR63_12,SAS_NAS_GTM_PR63_13,SAS_NAS_GTM_PR63_14,
    SAS_NAS_GTM_PR63_15,SAS_NAS_GTM_PR63_16,SAS_NAS_GTM_PR63_17,
    SAS_NAS_GTM_PR63_18,SAS_NAS_GTM_PR63_19,SAS_NAS_GTM_PR63_20,
    SAS_NAS_GTM_PR63_21,SAS_NAS_GTM_PR63_22,SAS_NAS_GTM_PR63_23,
    SAS_NAS_GTM_PR63_24,SAS_NAS_GTM_PR63_25,SAS_NAS_GTM_PR63_26,
    SAS_NAS_GTM_PR63_27,SAS_NAS_GTM_PR63_28,SAS_NAS_GTM_PR63_29,
    SAS_NAS_GTM_PR63_30,SAS_NAS_GTM_PR63_31,SAS_NAS_GTM_PR63_32,
    SAS_NAS_GTM_PR63_33,SAS_NAS_GTM_PR63_34,SAS_NAS_GTM_PR63_35,
    SAS_NAS_GTM_PR63_36,SAS_NAS_GTM_PR63_37,SAS_NAS_GTM_PR63_38,
    SAS_NAS_GTM_PR63_39,SAS_NAS_GTM_PR63_40,SAS_NAS_GTM_PR63_41,
    SAS_NAS_GTM_PR63_42,SAS_NAS_GTM_PR63_43,SAS_NAS_GTM_PR63_44,
    SAS_NAS_GTM_PR63_45,SAS_NAS_GTM_PR63_46,SAS_NAS_GTM_PR63_47,
    SAS_NAS_GTM_PR63_48,SAS_NAS_GTM_PR63_49,SAS_NAS_GTM_PR63_50,
    SAS_NAS_GTM_PR63_51,SAS_NAS_GTM_PR63_52,SAS_NAS_GTM_PR63_53,
    SAS_NAS_GTM_PR63_54,SAS_NAS_GTM_PR63_55,SAS_NAS_GTM_PR63_56,
    SAS_NAS_GTM_PR63_57,SAS_NAS_GTM_PR63_58,SAS_NAS_GTM_PR63_59,
    SAS_NAS_GTM_PR63_60,SAS_NAS_GTM_PR63_61,SAS_NAS_GTM_PR63_62,
    SAS_NAS_GTM_PR63_63,SAS_NAS_GTM_PR63_64,SAS_NAS_GTM_PR63_65,
    SAS_NAS_GTM_PR63_66,SAS_NAS_GTM_PR63_67,SAS_NAS_GTM_PR63_68,
    SAS_NAS_GTM_PR63_69,SAS_NAS_GTM_PR63_70,SAS_NAS_GTM_PR63_71,
    SAS_NAS_GTM_PR63_72,SAS_NAS_GTM_PR63_73,SAS_NAS_GTM_PR63_74,
    SAS_NAS_GTM_PR63_75,SAS_NAS_GTM_PR63_76,SAS_NAS_GTM_PR63_77,
    SAS_NAS_GTM_PR63_78,SAS_NAS_GTM_PR63_79,SAS_NAS_GTM_PR63_80,
    SAS_NAS_GTM_PR63_81,SAS_NAS_GTM_PR63_82,SAS_NAS_GTM_PR63_83,
    SAS_NAS_GTM_PR63_84,SAS_NAS_GTM_PR63_85,SAS_NAS_GTM_PR63_86,
    SAS_NAS_GTM_PR63_87,SAS_NAS_GTM_PR63_88,SAS_NAS_GTM_PR63_89,
    SAS_NAS_GTM_PR63_90,SAS_NAS_GTM_PR63_91,SAS_NAS_GTM_PR63_92,
    SAS_NAS_GTM_PR63_93,SAS_NAS_GTM_PR63_94,SAS_NAS_GTM_PR63_95,
    SAS_NAS_GTM_PR63_96,SAS_NAS_GTM_PR63_97,SAS_NAS_GTM_PR63_98,
    SAS_NAS_GTM_PR63_99,SAS_NAS_GTM_PR63_100,SAS_NAS_GTM_PR63_101,
    SAS_NAS_GTM_PR63_102,SAS_NAS_GTM_PR63_103,SAS_NAS_GTM_PR63_104,
    SAS_NAS_GTM_PR63_105,SAS_NAS_GTM_PR63_106,SAS_NAS_GTM_PR63_107,
    SAS_NAS_GTM_PR63_108,SAS_NAS_GTM_PR63_109,SAS_NAS_GTM_PR63_110,
    SAS_NAS_GTM_PR63_111,SAS_NAS_GTM_PR63_112,SAS_NAS_GTM_PR63_113,
    SAS_NAS_GTM_PR63_114,SAS_NAS_GTM_PR63_115,SAS_NAS_GTM_PR63_116,
    SAS_NAS_GTM_PR63_117,SAS_NAS_GTM_PR63_118,SAS_NAS_GTM_PR63_119,
    SAS_NAS_GTM_PR63_120,SAS_NAS_GTM_PR63_121,SAS_NAS_GTM_PR63_122,
    SAS_NAS_GTM_PR63_123,SAS_NAS_GTM_PR63_124,SAS_NAS_GTM_PR63_125,
    SAS_NAS_GTM_PR63_126,SAS_NAS_GTM_PR63_127,SAS_NAS_GTM_PR63_128,
    SAS_NAS_GTM_PR63_129,SAS_NAS_GTM_PR63_130,SAS_NAS_GTM_PR63_131,
    SAS_NAS_GTM_PR63_132,SAS_NAS_GTM_PR63_133,SAS_NAS_GTM_PR63_134,
    SAS_NAS_GTM_PR63_135,SAS_NAS_GTM_PR63_136,SAS_NAS_GTM_PR63_137,
    SAS_NAS_GTM_PR63_138,SAS_NAS_GTM_PR63_139,SAS_NAS_GTM_PR63_140,
    SAS_NAS_GTM_PR63_141,SAS_NAS_GTM_PR63_142,SAS_NAS_GTM_PR63_143,
    SAS_NAS_GTM_PR63_144,SAS_NAS_GTM_PR63_145,SAS_NAS_GTM_PR63_146,
    SAS_NAS_GTM_PR63_147,SAS_NAS_GTM_PR63_148,SAS_NAS_GTM_PR63_149,
    SAS_NAS_GTM_PR63_150,SAS_NAS_GTM_PR63_151,SAS_NAS_GTM_PR63_152,
    SAS_NAS_GTM_PR63_153,SAS_NAS_GTM_PR63_154,SAS_NAS_GTM_PR63_155,
    SAS_NAS_GTM_PR63_156,SAS_NAS_GTM_PR63_157,SAS_NAS_GTM_PR63_158,
    SAS_NAS_GTM_PR63_159,SAS_NAS_GTM_PR63_160,SAS_NAS_GTM_PR63_161,
    SAS_NAS_GTM_PR63_162,SAS_NAS_GTM_PR63_163,SAS_NAS_GTM_PR63_164,
    SAS_NAS_GTM_PR63_165,SAS_NAS_GTM_PR63_166,SAS_NAS_GTM_PR63_167,
    SAS_NAS_GTM_PR63_168,SAS_NAS_GTM_PR63_169,SAS_NAS_GTM_PR63_170,
    SAS_NAS_GTM_PR63_171,SAS_NAS_GTM_PR63_172,SAS_NAS_GTM_PR63_173,
    SAS_NAS_GTM_PR63_174,SAS_NAS_GTM_PR63_175,SAS_NAS_GTM_PR63_176,
    SAS_NAS_GTM_PR63_177,SAS_NAS_GTM_PR63_178,SAS_NAS_GTM_PR63_179,
    SAS_NAS_GTM_PR63_180,SAS_NAS_GTM_PR63_181,SAS_NAS_GTM_PR63_182,
    SAS_NAS_GTM_PR63_183,SAS_NAS_GTM_PR63_184,SAS_NAS_GTM_PR63_185,
    SAS_NAS_GTM_PR63_186,SAS_NAS_GTM_PR63_187,SAS_NAS_GTM_PR63_188,
    SAS_NAS_GTM_PR63_189,SAS_NAS_GTM_PR63_190,SAS_NAS_GTM_PR63_191,
    SAS_NAS_GTM_PR63_192,SAS_NAS_GTM_PR63_193,SAS_NAS_GTM_PR63_194,
    SAS_NAS_GTM_PR63_195,SAS_NAS_GTM_PR63_196,SAS_NAS_GTM_PR63_197,
    SAS_NAS_GTM_PR63_198,SAS_NAS_GTM_PR63_199,SAS_NAS_GTM_PR63_200,
    SAS_NAS_GTM_PR63_201,SAS_NAS_GTM_PR63_202,SAS_NAS_GTM_PR63_203,
    SAS_NAS_GTM_PR63_204,SAS_NAS_GTM_PR63_205,SAS_NAS_GTM_PR63_206,
    SAS_NAS_GTM_PR63_207,SAS_NAS_GTM_PR63_208,SAS_NAS_GTM_PR63_209,
    SAS_NAS_GTM_PR63_210,SAS_NAS_GTM_PR63_211,SAS_NAS_GTM_PR63_212,
    SAS_NAS_GTM_PR63_213,SAS_NAS_GTM_PR63_214,SAS_NAS_GTM_PR63_215,
    SAS_NAS_GTM_PR63_216,SAS_NAS_GTM_PR63_217,SAS_NAS_GTM_PR63_218,
    SAS_NAS_GTM_PR63_219,SAS_NAS_GTM_PR63_220,SAS_NAS_GTM_PR63_221,
    SAS_NAS_GTM_PR63_222,SAS_NAS_GTM_PR63_223,SAS_NAS_GTM_PR63_224,
    SAS_NAS_GTM_PR63_225,SAS_NAS_GTM_PR63_226,SAS_NAS_GTM_PR63_227,
    SAS_NAS_GTM_PR63_228,SAS_NAS_GTM_PR63_229,SAS_NAS_GTM_PR63_230,
    SAS_NAS_GTM_PR63_231,SAS_NAS_GTM_PR63_232,SAS_NAS_GTM_PR63_233,
    SAS_NAS_GTM_PR63_234,SAS_NAS_GTM_PR63_235,SAS_NAS_GTM_PR63_236,
    SAS_NAS_GTM_PR63_237,SAS_NAS_GTM_PR63_238,SAS_NAS_GTM_PR63_239,
    SAS_NAS_GTM_PR63_240,SAS_NAS_GTM_PR63_241,SAS_NAS_GTM_PR63_242,
    SAS_NAS_GTM_PR63_243,SAS_NAS_GTM_PR63_244,SAS_NAS_GTM_PR63_245,
    SAS_NAS_GTM_PR63_246,SAS_NAS_GTM_PR63_247,SAS_NAS_GTM_PR63_248,
    SAS_NAS_GTM_PR63_249,SAS_NAS_GTM_PR63_250,SAS_NAS_GTM_PR63_251,
    SAS_NAS_GTM_PR63_252,SAS_NAS_GTM_PR63_253,SAS_NAS_GTM_PR63_254,
    SAS_NAS_GTM_PR63_255,SAS_NAS_GTM_PR63_256,SAS_NAS_GTM_PR63_257,
    SAS_NAS_GTM_PR63_258,SAS_NAS_GTM_PR63_259,SAS_NAS_GTM_PR63_260,
    SAS_NAS_GTM_PR63_261,SAS_NAS_GTM_PR63_262,SAS_NAS_GTM_PR63_263,
    SAS_NAS_GTM_PR63_264,SAS_NAS_GTM_PR63_265,SAS_NAS_GTM_PR63_266,
    SAS_NAS_GTM_PR63_267,SAS_NAS_GTM_PR63_268,SAS_NAS_GTM_PR63_269,
    SAS_NAS_GTM_PR63_270,SAS_NAS_GTM_PR63_271,SAS_NAS_GTM_PR63_272,
    SAS_NAS_GTM_PR63_273,SAS_NAS_GTM_PR63_274,SAS_NAS_GTM_PR63_275,
    SAS_NAS_GTM_PR63_276,SAS_NAS_GTM_PR63_277,SAS_NAS_GTM_PR63_278,
    SAS_NAS_GTM_PR63_279,SAS_NAS_GTM_PR63_280,SAS_NAS_GTM_PR63_281,
    SAS_NAS_GTM_PR63_282,SAS_NAS_GTM_PR63_283,SAS_NAS_GTM_PR63_284,
    SAS_NAS_GTM_PR63_285,SAS_NAS_GTM_PR63_286,SAS_NAS_GTM_PR63_287,
    SAS_NAS_GTM_PR63_288,SAS_NAS_GTM_PR63_289,SAS_NAS_GTM_PR63_290,
    SAS_NAS_GTM_PR63_291,SAS_NAS_GTM_PR63_292,SAS_NAS_GTM_PR63_293,
    SAS_NAS_GTM_PR63_294,SAS_NAS_GTM_PR63_295,SAS_NAS_GTM_PR63_296,
    SAS_NAS_GTM_PR63_297,SAS_NAS_GTM_PR63_298,SAS_NAS_GTM_PR63_299,
    SAS_NAS_GTM_PR63_300,SAS_NAS_GTM_PR63_301,SAS_NAS_GTM_PR63_302,
    SAS_NAS_GTM_PR63_303,SAS_NAS_GTM_PR63_304,SAS_NAS_GTM_PR63_305,
    SAS_NAS_GTM_PR63_306,SAS_NAS_GTM_PR63_307,SAS_NAS_GTM_PR63_308,
    SAS_NAS_GTM_PR63_309,SAS_NAS_GTM_PR63_310,SAS_NAS_GTM_PR63_311,
    SAS_NAS_GTM_PR63_312,SAS_NAS_GTM_PR63_313,SAS_NAS_GTM_PR63_314,
    SAS_NAS_GTM_PR63_315,SAS_NAS_GTM_PR63_316,SAS_NAS_GTM_PR63_317,
    SAS_NAS_GTM_PR63_318,SAS_NAS_GTM_PR63_319,SAS_NAS_GTM_PR63_320,
    SAS_NAS_GTM_PR63_321,SAS_NAS_GTM_PR63_322,SAS_NAS_GTM_PR63_323,
    SAS_NAS_GTM_PR63_324,SAS_NAS_GTM_PR63_325,SAS_NAS_GTM_PR63_326,
    SAS_NAS_GTM_PR63_327,SAS_NAS_GTM_PR63_328,SAS_NAS_GTM_PR63_329,
    SAS_NAS_GTM_PR63_330,SAS_NAS_GTM_PR63_331,SAS_NAS_GTM_PR63_332,
    SAS_NAS_GTM_PR63_333,SAS_NAS_GTM_PR63_334,SAS_NAS_GTM_PR63_335,
    SAS_NAS_GTM_PR63_336,SAS_NAS_GTM_PR63_337,SAS_NAS_GTM_PR63_338,
    SAS_NAS_GTM_PR63_339,SAS_NAS_GTM_PR63_340,SAS_NAS_GTM_PR63_341,
    SAS_NAS_GTM_PR63_342,SAS_NAS_GTM_PR63_343,SAS_NAS_GTM_PR63_344,
    SAS_NAS_GTM_PR63_345,SAS_NAS_GTM_PR63_346,SAS_NAS_GTM_PR63_347,
    SAS_NAS_GTM_PR63_348,SAS_NAS_GTM_PR63_349,SAS_NAS_GTM_PR63_350,
    SAS_NAS_GTM_PR63_351,SAS_NAS_GTM_PR63_352,SAS_NAS_GTM_PR63_353,
    SAS_NAS_GTM_PR63_354,SAS_NAS_GTM_PR63_355,SAS_NAS_GTM_PR63_356,
    SAS_NAS_GTM_PR63_357,SAS_NAS_GTM_PR63_358,SAS_NAS_GTM_PR63_359,
    SAS_NAS_GTM_PR63_360,SAS_NAS_GTM_PR63_361,SAS_NAS_GTM_PR63_362,
    SAS_NAS_GTM_PR63_363,SAS_NAS_GTM_PR63_364,SAS_NAS_GTM_PR63_365,
    SAS_NAS_GTM_PR63_366,SAS_NAS_GTM_PR63_367,SAS_NAS_GTM_PR63_368,
    SAS_NAS_GTM_PR63_369,SAS_NAS_GTM_PR63_370,SAS_NAS_GTM_PR63_371,
    SAS_NAS_GTM_PR63_372,SAS_NAS_GTM_PR63_373,SAS_NAS_GTM_PR63_374,
    SAS_NAS_GTM_PR63_375,SAS_NAS_GTM_PR63_376,SAS_NAS_GTM_PR63_377,
    SAS_NAS_GTM_PR63_378,SAS_NAS_GTM_PR63_379,SAS_NAS_GTM_PR63_380,
    SAS_NAS_GTM_PR63_381,SAS_NAS_GTM_PR63_382,SAS_NAS_GTM_PR63_383,
    SAS_NAS_GTM_PR63_384,SAS_NAS_GTM_PR63_385,SAS_NAS_GTM_PR63_386,
    SAS_NAS_GTM_PR63_387,SAS_NAS_GTM_PR63_388,SAS_NAS_GTM_PR63_389,
    SAS_NAS_GTM_PR63_390,SAS_NAS_GTM_PR63_391,SAS_NAS_GTM_PR63_392,
    SAS_NAS_GTM_PR63_393,SAS_NAS_GTM_PR63_394,SAS_NAS_GTM_PR63_395,
    SAS_NAS_GTM_PR63_396,SAS_NAS_GTM_PR63_397,SAS_NAS_GTM_PR63_398,
    SAS_NAS_GTM_PR63_399,SAS_NAS_GTM_PR63_400,SAS_NAS_GTM_PR63_401,
    SAS_NAS_GTM_PR63_402,SAS_NAS_GTM_PR63_403,SAS_NAS_GTM_PR63_404,
    SAS_NAS_GTM_PR63_405,SAS_NAS_GTM_PR63_406,SAS_NAS_GTM_PR63_407,
    SAS_NAS_GTM_PR63_408,SAS_NAS_GTM_PR63_409,SAS_NAS_GTM_PR63_410,
    SAS_NAS_GTM_PR63_411,SAS_NAS_GTM_PR63_412,SAS_NAS_GTM_PR63_413,
    SAS_NAS_GTM_PR63_414,SAS_NAS_GTM_PR63_415,SAS_NAS_GTM_PR63_416,
    SAS_NAS_GTM_PR63_417,SAS_NAS_GTM_PR63_418,SAS_NAS_GTM_PR63_419,
    SAS_NAS_GTM_PR63_420,SAS_NAS_GTM_PR63_421,SAS_NAS_GTM_PR63_422,
    SAS_NAS_GTM_PR63_423,SAS_NAS_GTM_PR63_424,SAS_NAS_GTM_PR63_425,
    SAS_NAS_GTM_PR63_426,SAS_NAS_GTM_PR63_427,SAS_NAS_GTM_PR63_428,
    SAS_NAS_GTM_PR63_429,SAS_NAS_GTM_PR63_430,SAS_NAS_GTM_PR63_431,
    SAS_NAS_GTM_PR63_432,SAS_NAS_GTM_PR63_433,SAS_NAS_GTM_PR63_434,
    SAS_NAS_GTM_PR63_435,SAS_NAS_GTM_PR63_436,SAS_NAS_GTM_PR63_437,
    SAS_NAS_GTM_PR63_438,SAS_NAS_GTM_PR63_439,SAS_NAS_GTM_PR63_440,
    SAS_NAS_GTM_PR63_441,SAS_NAS_GTM_PR63_442,SAS_NAS_GTM_PR63_443,
    SAS_NAS_GTM_PR63_444,SAS_NAS_GTM_PR63_445,SAS_NAS_GTM_PR63_446,
    SAS_NAS_GTM_PR63_447,SAS_NAS_GTM_PR63_448,SAS_NAS_GTM_PR63_449,
    SAS_NAS_GTM_PR63_450,SAS_NAS_GTM_PR63_451,SAS_NAS_GTM_PR63_452,
    SAS_NAS_GTM_PR63_453,SAS_NAS_GTM_PR63_454,SAS_NAS_GTM_PR63_455,
    SAS_NAS_GTM_PR63_456,SAS_NAS_GTM_PR63_457,SAS_NAS_GTM_PR63_458,
    SAS_NAS_GTM_PR63_459,SAS_NAS_GTM_PR63_460,SAS_NAS_GTM_PR63_461,
    SAS_NAS_GTM_PR63_462,SAS_NAS_GTM_PR63_463,SAS_NAS_GTM_PR63_464,
    SAS_NAS_GTM_PR63_465,SAS_NAS_GTM_PR63_466,SAS_NAS_GTM_PR63_467,
    SAS_NAS_GTM_PR63_468,SAS_NAS_GTM_PR63_469,SAS_NAS_GTM_PR63_470,
    SAS_NAS_GTM_PR63_471,SAS_NAS_GTM_PR63_472,SAS_NAS_GTM_PR63_473,
    SAS_NAS_GTM_PR63_474,SAS_NAS_GTM_PR63_475,SAS_NAS_GTM_PR63_476,
    SAS_NAS_GTM_PR63_477,SAS_NAS_GTM_PR63_478,SAS_NAS_GTM_PR63_479,
    SAS_NAS_GTM_PR63_480,SAS_NAS_GTM_PR63_481,SAS_NAS_GTM_PR63_482,
    SAS_NAS_GTM_PR63_483,SAS_NAS_GTM_PR63_484,SAS_NAS_GTM_PR63_485,
    SAS_NAS_GTM_PR63_486,SAS_NAS_GTM_PR63_487,SAS_NAS_GTM_PR63_488,
    SAS_NAS_GTM_PR63_489,SAS_NAS_GTM_PR63_490,SAS_NAS_GTM_PR63_491,
    SAS_NAS_GTM_PR63_492,SAS_NAS_GTM_PR63_493,SAS_NAS_GTM_PR63_494,
    SAS_NAS_GTM_PR63_495,SAS_NAS_GTM_PR63_496,SAS_NAS_GTM_PR63_497,
    SAS_NAS_GTM_PR63_498,SAS_NAS_GTM_PR63_499,SAS_NAS_GTM_PR63_500,
    SAS_NAS_GTM_PR63_501,SAS_NAS_GTM_PR63_502,SAS_NAS_GTM_PR63_503,
    SAS_NAS_GTM_PR63_504,SAS_NAS_GTM_PR63_505,SAS_NAS_GTM_PR63_506,
    SAS_NAS_GTM_PR63_507,SAS_NAS_GTM_PR63_508,SAS_NAS_GTM_PR63_509,
    SAS_NAS_GTM_PR63_510,SAS_NAS_GTM_PR63_511,SAS_NAS_GTM_PR63_512,
    SAS_NAS_GTM_PR63_513,SAS_NAS_GTM_PR63_514,SAS_NAS_GTM_PR63_515,
    SAS_NAS_GTM_PR63_516,SAS_NAS_GTM_PR63_517,SAS_NAS_GTM_PR63_518,
    SAS_NAS_GTM_PR63_519,SAS_NAS_GTM_PR63_520,SAS_NAS_GTM_PR63_521,
    SAS_NAS_GTM_PR63_522,SAS_NAS_GTM_PR63_523,SAS_NAS_GTM_PR63_524,
    SAS_NAS_GTM_PR63_525,SAS_NAS_GTM_PR63_526,SAS_NAS_GTM_PR63_527,
    SAS_NAS_GTM_PR63_528,SAS_NAS_GTM_PR63_529,SAS_NAS_GTM_PR63_530,
    SAS_NAS_GTM_PR63_531,SAS_NAS_GTM_PR63_532,SAS_NAS_GTM_PR63_533,
    SAS_NAS_GTM_PR63_534,SAS_NAS_GTM_PR63_535,
    SAS_NAS_GTM_PR63_537,SAS_NAS_GTM_PR63_538,SAS_NAS_GTM_PR63_539,
    SAS_NAS_GTM_PR63_540,SAS_NAS_GTM_PR63_541,SAS_NAS_GTM_PR63_542,
    SAS_NAS_GTM_PR63_543,SAS_NAS_GTM_PR63_544,SAS_NAS_GTM_PR63_545,
    SAS_NAS_GTM_PR63_546,SAS_NAS_GTM_PR63_547,SAS_NAS_GTM_PR63_548,
    SAS_NAS_GTM_PR63_549,SAS_NAS_GTM_PR63_550,SAS_NAS_GTM_PR63_551,
    SAS_NAS_GTM_PR63_552,SAS_NAS_GTM_PR63_553,SAS_NAS_GTM_PR63_554,
    SAS_NAS_GTM_PR63_555,SAS_NAS_GTM_PR63_556,SAS_NAS_GTM_PR63_557,
    SAS_NAS_GTM_PR63_558,SAS_NAS_GTM_PR63_560,SAS_NAS_GTM_PR63_561,
    SAS_NAS_GTM_PR63_562,SAS_NAS_GTM_PR63_563,DS_NAS_GTM_PR78_1,
    DS_NAS_GTM_PR446,DS_NAS_GTM_PR699,DS_NAS_GTM_PR647,DS_NAS_GTM_PR69_PR469,
    DS_NAS_GTM_PR700,DS_NAS_GTM_PR701,DS_NAS_GTM_PR704,DS_NAS_GTM_PR707,
    DS_NAS_GTM_PR708,DS_NAS_GTM_PR712,DS_NAS_GTM_PR713,DS_NAS_GTM_PR716,
    DS_NAS_GTM_PR717,DS_NAS_GTM_PR719,DS_NAS_GTM_PR720,DS_NAS_GTM_PR723,DS_NAS_GTM_PR724,
    DS_NAS_GTM_PR728,DS_NAS_GTM_PR709,DS_NAS_GTM_PR228,
    SAS_NAS_GTM_PR82,SAS_NAS_GTM_PR227,SAS_NAS_GTM_PR640,
    SAS_AS4XX_GTM_PR680,SAS_NAS_GTM_PR916,SAS_NAS_GTM_PR667,SAS_NAS_GTM_PR646,
    SAS_NAS_GTM_PR123,SAS_NAS_HE2_GTM_PR2935_1,SAS_NAS_HE2_GTM_PR2935_2,
    SAS_NAS_HE2_GTM_PR2935_3]
    ASW:1455 to DS_NAS_GTM_PR228 map to Mcu.xdm. It is mapped here to 
    avoid conflicts with MCU traceability
**                                                                            **
**  DESCRIPTION  : Code template for Gtm_PBCfg.c file                         **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
********************************************************************************
** VS          Vinod Shankar                                                  **
** RC          Rashmi Chadaga                                                 **
** KP          Kaushal Purohit                                                **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V2.0.4: 2013-08-19,  KP   : minor correction for compilation errors
 * V2.0.3: 2013-07-23,  KP   : Changed for UTP [AI00198181]
 * V2.0.2: 2013-04-22,  KP   : Changed for UTP [AI00171967]
 * V2.0.1: 2013-03-26,  KP   : updated as per review comments [REV_004335]
 * V2.0.0: 2013-03-14,  KP   : Added Bstep changes
 * V0.0.11: 2012-11-13, VS   : Gtm_kFifoConfig made const
 * V0.0.10: 2012-11-07, VS   : MISRA fix
 * V0.0.9 : 2012-10-30, RC   : Traceability Added 
 * V0.0.8 : 2012-09-25, RC   : CCU corrections. AI00066335 
 * V0.0.7 : 2012-09-10, VS   : Support of CCU. AI00066335 
 * V0.0.6 : 2012-07-04, VS   : Fix for AI00076259 
 * V0.0.5 : 2012-06-14, VS   : Changes done for BMD 
 * V0.0.4 : 2012-04-25, VS   : a) Requirement Traceability Added
 *                            b) GTM Enhancement - Notification Included
 * V0.0.3 : 2011-10-05, VS   : Misra related Changes
 * V0.0.2 : 2011-04-05, VS   : Review Changes
 * V0.0.1 : 2011-02-12, VS   : Initial version
 *                                                                            
*************************************************************************/!][!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Gtm_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\76 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Mcu.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : complex driver implementation                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
[!/* Select MODULE-CONFIGURATION as context-node */!][!/*
*/!][!INCLUDE "Gtm.m"!][!/*
*/!][!SELECT "as:modconf('Mcu')[1]"!][!/*
*/!][!VAR "RelDerivate" = "ecu:get('Rel.Derivate')"!][!/* 
*/!][!IF "($RelDerivate = '_TRICORE_TC297') or ($RelDerivate = '_TRICORE_TC298') or ($RelDerivate = '_TRICORE_TC299')"!][!/*
*/!][!VAR "RelDerivate" = "'TC29x'"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "($RelDerivate = '_TRICORE_TC264') or ($RelDerivate = '_TRICORE_TC265') or ($RelDerivate = '_TRICORE_TC267')"!][!/*
*/!][!VAR "RelDerivate" = "'TC26x'"!][!/*
*/!][!ENDIF!]
[!/*
*/!][!/* Generate this file only if Gtm is configured
*/!][!NOCODE!][!/*
*/!][!/* To Count the Number of Gtm Configurations inside all the Mcu PB Containers */!][!/*
*/!][!VAR "TotalGtmConfig" = "num:i(0)"!][!/*
*/!][!VAR "McuSelect" = "'McuModuleConfiguration'"!][!/*
*/!][!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($McuSelect)/*))- 1)"!][!/*
*/!][!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleIndex + 1,']')"!][!/*
*/!][!VAR "Count" = "num:i(count(node:ref($McuSelectIndex)/GtmConfiguration/*))"!][!/*
*/!][!IF "$Count > num:i(0)"!][!/*    
*/!][!VAR "TotalGtmConfig" = "$TotalGtmConfig + $Count"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TotalGtmConfigInAllContainers" = "num:i(count(McuModuleConfiguration/*/GtmConfiguration/*))"!][!/*
*/!][!ASSERT "($TotalGtmConfigInAllContainers = num:i(0)) or ($TotalGtmConfigInAllContainers =  (num:i(count(McuModuleConfiguration/*))))"!][!/*
*/!]Configuration Error: If any one MCU config set has GTM configured, then all the MCU config sets should have GTM configured
[!ENDASSERT!][!/*
To determine the Post Build Type
*/!][!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$TotalGtmConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!IF "node:exists(EcuMPostBuildConfigType) ='true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
*/!][!ENDNOCODE!][!/*
*/!][!/* Run the Code generator only if there is atleast 1 Gtm Configuration among the containers
*/!][!IF "$TotalGtmConfig > num:i(0)"!][!/*
*/!]
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file, this includes own configuration file also */
#include "Gtm.h"



/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Note:
The user can configure the parameters with the tag Configuration:
The user should not change anything under the tag Configuration Options:
*/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_INTERRUPT_LEVEL_MODE          (0U)
#define GTM_INTERRUPT_PULSE_MODE          (1U)
#define GTM_INTERRUPT_PULSE_NOTIFY_MODE   (2U) 
#define GTM_INTERRUPT_SINGLE_PULSE_MODE   (3U)

#define TSPP1_SUBUNIT_OUTPUT 5

/* For Tbu */
#define BITS_0_TO_23   (0U)
#define BITS_3_TO_26   (1U)
#define FREE_RUNNING_COUNTER_MODE      (0)
#define FORWARD_BACKWARD_COUNTER_MODE  (1)

/*IFX_MISRA_RULE_19_07_STATUS= Function like macros used for simplifacation of
        configuration generation and increase the readability of config file */
#define Gtm_lTbuBuildControl(Bit0, Bit123, Bit5)                              \
 (0x00U | (uint8)(Bit0) | (uint8)((uint8)(Bit123) << 1) |                     \
                                                 (uint8)((uint8)(Bit5) << 5))
                                                 
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lTimerCtrlValue(Word, ClockValue)                                 \
                        ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 12))
                        
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_TimbuildReg(Word, ClockValue)                                     \
                         ((uint32)(Word)| (uint32)((uint32)(ClockValue) << 24))
                         
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_TimTduBuildReg(Word, ClockValue)                                  \
                        ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 28))
                        
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_MapBuildReg(Word, ClockValue)                                     \
                         ((uint32)(Word) | (uint32)((uint32)(ClockValue) << 1))

/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lMoveCcuTo8Bit(Ccu1,Ccu0)                                        \
                             (((uint16)(Ccu0))| (uint16)((uint16)(Ccu1) << 8))

/* For Interrupt Mode Appending */
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lIncludeIntMode8Bit(Bytevalue, IrqMode)                           \
                          ((uint8)(Bytevalue) | (uint8)((uint8)(IrqMode) << 6))
                          
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
#define Gtm_lIncludeIntMode16Bit(Intvalue, IrqMode)                           \
                       ((uint16)(Intvalue) | (uint16)((uint16)(IrqMode) << 14))
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplifacation of
        configuration generation and increase the readability of config file*/
        
#define Gtm_lIncludeIntMode32Bit(Wordvalue, IrqMode)                          \
                      ((uint32)(Wordvalue) | (uint32)((uint32)(IrqMode) << 30))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define MCU_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"

[!NOCODE!][!/*
*/!][!VAR "IsBmdUsed" = "'false'"!][!/*
*/!][!VAR "TotalMcuConfig" = "num:i(count(node:ref($McuSelect)/*))"!][!/*
*/!][!ENDNOCODE!][!/*
*/!][!VAR "PortConfigPresent" = "num:i(0)"!][!/*
*/!][!VAR "ClockConfigExist" = "num:i(0)"!][!/*
*/!][!FOR "ModuleId" ="num:i(0)" TO "(num:i($TotalMcuConfig)-1)"!][!/*
*/!][!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleId + 1,']')"!][!/*
*/!][!SELECT "node:ref($McuSelectIndex)"!][!/*
*/!][!IF "node:exists(GtmConfiguration/*[1]/Cmu/*[1])"!][!/*
*/!][!VAR "ClockConfigExist" = "bit:bitset($ClockConfigExist,$ModuleId)"!][!/*
*/!]static const Gtm_ClockSettingType Gtm_kClockSetting[!"$ModuleId"!] = 
{
[!NOCODE!][!//
[!VAR "BuildReg" = "num:i(0)"!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk0)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk1)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk2)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk3)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 7)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 6)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk4)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 8)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk5)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk6)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 13)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 12)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk7)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 15)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 14)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuEnableExternalClk0)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 17)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 16)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuEnableExternalClk1)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 19)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 18)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuEnableExternalClk2)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 21)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 20)"!][!//	
[!ENDIF!][!//
[!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Cmu/*[1]/CmuFixedClock/CmuEnableAllFixedClocks)"!][!//
[!IF "$BuildRegTemp = 'true'"!][!//
[!VAR "BuildReg" = "bit:bitset($BuildReg, 23)"!][!//
[!ELSE!]
[!VAR "BuildReg" = "bit:bitset($BuildReg, 22)"!][!//	
[!ENDIF!][!//
[!ENDNOCODE!][!//
  [!"num:inttohex($BuildReg,8)"!]U,
  {
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk0Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk1Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk2Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk3Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk4Div, 8)"!]U,
    [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk5Div, 8)"!]U,
[!VAR "BuildReg" = "GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk6Div"!][!/*
*/!][!IF "GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuClk6SourceSelect = 'CMU_SUB_INC2_SIGNAL'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 24)"!][!/*
*/!][!ENDIF!]    [!"num:inttohex($BuildReg, 8)"!]U,
[!VAR "BuildReg" = "GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk7Div"!][!/*
*/!][!IF "GtmConfiguration/*[1]/Cmu/*[1]/CmuConfigurableClock/CmuClk7SourceSelect = 'CMU_SUB_INC1_SIGNAL'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 24)"!][!/*
*/!][!ENDIF!]    [!"num:inttohex($BuildReg, 8)"!]U,
  },
[!IF "./CmuFixedClock/CmuFxdClkSourceSelect = 'GTM_GLOBAL_CLOCK'"!][!/*
*/!][!VAR "ClockVal" = "num:i(0)"!][!/*
*/!][!"num:inttohex($ClockVal,1)"!]U,
  [!ELSE!][!/*
*/!][!VAR "ClockVal" = "text:split(GtmConfiguration/*[1]/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect, '_')[position()-1 = 2]"!]
    [!"num:inttohex(($ClockVal+1),1)"!]U,
[!ENDIF!]
  {
    {[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk0Numerator,8)"!]U,[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk0Denominator,8)"!]U[!/*
*/!]  },
    {[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk1Numerator,8)"!]U,[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk1Denominator,8)"!]U[!/*
*/!]  },
    {[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk2Numerator,8)"!]U,[!/*
*/!]  [!"num:inttohex(GtmConfiguration/*[1]/Cmu/*[1]/CmuExternalClock/CmuExternalClk2Denominator,8)"!]U[!/*
*/!]  }
  }[!/*
*/!]
};
[!ENDIF!][!/* [!IF "node:exists(GtmConfiguration/*[1]/Cmu/*[1])"!]
*/!][!/*
*/!]
static const Gtm_GeneralConfigType Gtm_kGeneralConfig[!"$ModuleId"!] =
{[!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmGeneral/GtmEnRstAndForceIntFunctionality)"!][!/*
*/!][!IF "$BuildRegTemp = 'false'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiTimeOutMode)"!][!/*
*/!][!IF "$BuildRegTemp = 'ABORT'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiTimeOutValue)"!][!/*
*/!][!VAR "BuildRegTemp" = "bit:shl($BuildRegTemp,4)"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg,$BuildRegTemp)"!][!/*
*/!]
  [!"num:inttohex($BuildReg,4)"!]U,[!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiTimeoutExceptionIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiUnsupportedAddressIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiIllegalModuleAddIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiUnsupportedByteEnIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiTimeoutExceptionErrIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiUnsupportedAddressErrIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiIllegalModuleAddErrIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 12)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiUnsupportedByteEnErrIntEn)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 13)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/GtmAeiInterface/GtmAeiInterruptMode)"!][!/*
*/!]
  Gtm_lIncludeIntMode8Bit([!"$BuildReg"!]U,[!"$BuildRegTemp"!])[!/*
*/!]
  };
[!/*
*/!][!IF "node:exists(GtmConfiguration/*[1]/Brc/*[1])"!][!/*
*/!][!VAR "BrcChannelPresent" = "num:i(0)"!][!/*
*/!][!LOOP "(GtmConfiguration/*[1]/Brc/*[1]/BrcChannel/*)"!][!/*
*/!][!IF "node:value(./BrcChannelGeneral/BrcChannelUsage) = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "BrcChannelPresent" = "num:i(1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!/*
*/!][!IF "$BrcChannelPresent = num:i(1)"!][!/*
*/!]

static const Gtm_BrcChannelType Gtm_kBrcChannel[!"$ModuleId"!][GTM_NUMBER_OF_BRC_SOURCE] =
{
[!FOR "LoopCount" ="num:i(0)" TO "num:i(11)"!][!/*
*/!][!VAR "BrcChannelNo" = "concat('BrcChannel_',$LoopCount)"!][!/*
*/!]  {[!/*
*/!][!SELECT "GtmConfiguration/*[1]/Brc/*[1]/BrcChannel/*[@name=$BrcChannelNo]"!][!/*
*/!][!IF "node:value(./BrcChannelGeneral/BrcChannelUsage) = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg" = "node:value(./BrcChannelGeneral/BrcSourceAruAddress)"!][!/*
*/!][!IF "./BrcChannelGeneral/BrcModeSelect = 'MAXIMUM_THROUGHPUT_MODE_MTM'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 12)"!][!/*  
*/!][!ENDIF!][!/*
*/!]  [!"num:inttohex($BuildReg,4)"!]U,[!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr0Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr1Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr2Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr3Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr4Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr5Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr6Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 6)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr7Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 7)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr8Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 8)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr9Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr10Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr11Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr12Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 12)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr13Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 13)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr14Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 14)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr15Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 15)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr16Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 16)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr17Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 17)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr18Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 18)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr19Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 19)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr20Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 20)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./BrcChannelDestinationSelect/BrcChDestinationAddr21Enable)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 21)"!][!/*
*/!][!ENDIF!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U[!/*
*/!][!ELSE!][!/*
*/!]   GTM_SETBRCCHANNELUNUSED , 0UL[!/*[!IF "node:value(./BrcChannelGeneral/BrcChannelUsage) = 'USED_BY_GTM_DRIVER'"
*/!][!ENDIF!][!/*
*/!]}, 
[!ENDSELECT!][!/*
*/!][!ENDFOR!]
};
[!ENDIF!][!/* [!IF "$BrcChannelPresent = num:i(1)"!]
*/!]

static const Gtm_BrcConfigType Gtm_kBrcConfig[!"$ModuleId"!] = 
{
[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnableConfigurationErrorInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc0DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc1DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc2DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc3DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc4DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc5DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 6)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc6DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 7)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc7DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 8)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc8DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc9DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc10DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcEnSrc11DataInconsistencyErrInt)"!][!/*
*/!][!IF "$BuildRegTemp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 12)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcInterrupt/BrcInterruptMode)"!][!/*
*/!]  Gtm_lIncludeIntMode16Bit([!"$BuildReg"!]U,[!"$BuildRegTemp"!]),
[!VAR "BuildRegErrInt" = "num:i(0)"!][!/*   
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDestErrorIntrpt) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd0) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd1) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd2) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd3) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd4) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd5) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 6)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd6) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 7)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd7) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 8)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd8) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 9)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd9) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 10)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd10) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(GtmConfiguration/*[1]/Brc/*[1]/BrcErrorInterrupt/BrcEnableDaInconsistencyDetd11) = 'true'"!][!/*
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 12)"!][!/*
*/!][!ENDIF!][!/*
*/!]  [!"num:inttohex($BuildRegErrInt,4)"!]U,
[!IF "$BrcChannelPresent = num:i(1)"!][!/*
*/!]  &Gtm_kBrcChannel[!"$ModuleId"!][0]
[!ELSE!][!/*
*/!]  NULL_PTR
[!ENDIF!]
};
[!ENDIF!][!/*
*/!][!//
[!/* Fifo Config Structure 
*/!][!IF "node:exists(GtmConfiguration/*[1]/Fifo/*[1])"!][!/*
*/!][!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!VAR "FifoModCount" = "num:i(0)"!][!/*
*/!][!LOOP "Fifo/*"!][!/*
*/!][!VAR "LoopCnt" = "num:i(0)"!][!/*
*/!][!LOOP "FifoChannel/*"!][!/*
*/!][!IF "node:value(./FifoGeneral/FifoChannelUsage) = 'USED_BY_GTM_DRIVER'"!][!/*
*/!]
static const Gtm_FifoConfigType \
                         Gtm_kFifo[!"$FifoModCount"!]Channel[!"$LoopCnt"!]Config[!"$ModuleId"!] =
{

[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./FifoGeneral/FifoChannelModeSelect) = 'FIFO_RING_BUFFER_MODE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*    
*/!][!IF "node:value(./FifoGeneral/FifoRamAccessHighestPriority) = 'AEI_IF_ACCESS'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/* 
*/!][!IF "node:value(./FifoGeneral/FifoEnDirectRamWriteAccess) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!//
  [!"num:inttohex($BuildReg,2)"!]U,
[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./FifoChannelInterrupt/FifoIntEnableOnFifoEmpty) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*  
*/!][!IF "node:value(./FifoChannelInterrupt/FifoIntEnableOnFifoFull) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/* 
*/!][!IF "node:value(./FifoChannelInterrupt/FifoIntEnOnFifoUndrrunLwrWtrmark) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./FifoChannelInterrupt/FifoIntEnOnFifoOvrrunUprWtrmark) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./FifoChannelInterrupt/FifoDmaHysterisisModeEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./FifoChannelInterrupt/FifoHysterisModeDmaDirection) = 'DMA_DIRECTION_WRITE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildRegTemp" = "node:value(./FifoChannelInterrupt/FifoInterruptMode)"!][!//
  Gtm_lIncludeIntMode8Bit([!"$BuildReg"!]U, [!"$BuildRegTemp"!]),
[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./FifoChannelErrorInterrupt/FifoIntEnableOnFifoEmptyErr) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*  
*/!][!IF "node:value(./FifoChannelErrorInterrupt/FifoIntEnableOnFifoFullErr) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*  
*/!][!IF "node:value(./FifoChannelErrorInterrupt/FifoIntEnOnFifoUndrrunLwrWtrmarkErr) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*  
*/!][!IF "node:value(./FifoChannelErrorInterrupt/FifoIntEnOnFifoOvrrunUprWtrmarkErr) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*  
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
  [!"num:inttohex(./FifoGeneral/FifoStartAddress,4)"!]U,
  [!"num:inttohex(./FifoGeneral/FifoEndAddress,4)"!]U,
[!IF "./FifoGeneral/FifoChannelModeSelect = 'FIFO_NORMAL_FIFO_OPERATION'"!][!//
  [!"num:inttohex(./FifoGeneral/FifoUpperWatermarkAddress,4)"!]U,
  [!"num:inttohex(./FifoGeneral/FifoLowerWatermarkAddress,4)"!]U,  
[!ELSE!][!//
  [!"num:inttohex(./FifoGeneral/FifoGatePointerFromSlw2Lwu,4)"!]U,  
  [!"num:inttohex(./FifoGeneral/FifoGatePointerFromLwu2Uwe,4)"!]U, 
[!ENDIF!][!//
};
[!ENDIF!][!/* IF "node:value(./FifoGeneral/FifoChannelUsage) = 'USED_BY_GTM_DRIVER'"
*/!][!VAR "LoopCnt" = "num:i($LoopCnt + 1)"!][!/*
*/!][!ENDLOOP!][!/*[!LOOP "FifoChannel/*"!]
*/!][!VAR "FifoModCount" = "num:i($FifoModCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*[!LOOP "Fifo/*"!]
*/!][!ENDSELECT!][!/*[!SELECT "GtmConfiguration/*[1]"!]
*/!]
static const Gtm_FifoConfigType 
  *const Gtm_kFifoConfig[!"$ModuleId"!][GTM_NO_OF_FIFO_CHANNELS * GTM_NO_OF_FIFO_MODULES] =
{
[!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!VAR "FifoModCount" = "num:i(0)"!][!/*
*/!][!VAR "FifoConfiguredCount" = "num:i(0)"!][!/*
*/!][!LOOP "Fifo/*"!][!/*
*/!][!VAR "LoopCnt" = "num:i(0)"!][!/*
*/!][!LOOP "FifoChannel/*"!][!/*
*/!][!VAR "FifoConfiguredCount" = "num:i($FifoConfiguredCount + 1)"!][!/*
*/!][!IF "node:value(./FifoGeneral/FifoChannelUsage) = 'USED_BY_GTM_DRIVER'"!][!//
  &Gtm_kFifo[!"$FifoModCount"!]Channel[!"$LoopCnt"!]Config[!"$ModuleId"!],
[!ELSE!][!//
  NULL_PTR,
[!ENDIF!][!/*
*/!][!VAR "LoopCnt" = "num:i($LoopCnt + 1)"!][!/*
*/!][!ENDLOOP!][!/*[!LOOP "FifoChannel/*"!]
*/!][!VAR "FifoModCount" = "num:i($FifoModCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*[!LOOP "Fifo/*"!]
*/!][!ENDSELECT!][!/*[!SELECT "GtmConfiguration/*[1]"!]
*/!][!VAR "TotalFifoChannels" = "(num:i(ecu:get('Gtm.NumberOfFifoModules')) * num:i(ecu:get('Gtm.NumberOfFifoChannels')))"!][!/*
*/!][!IF "num:i($FifoConfiguredCount) != num:i($TotalFifoChannels)"!][!//
[!FOR "Count" = "0" TO "((num:i($TotalFifoChannels) - num:i($FifoConfiguredCount))-1)"!][!//
  NULL_PTR,
[!ENDFOR!][!// [!FOR "Count" = "0" TO "(num:i($TotalFifoChannels) - num:i($FifoConfiguredCount))"!]
[!ENDIF!][!// [!IF "$FifoConfiguredCount != (num:i($TotalFifoChannels)"!]
};
[!ENDIF!][!// IF "node:exists(GtmConfiguration/*[1]/Fifo/*[1])
[!// End of Fifo Configuration
[!//F2A Configuration
[!IF "node:exists(GtmConfiguration/*[1]/F2a/*[1])"!][!/*
*/!][!VAR "F2aChannelUsed" = "num:i(0)"!][!/*
*/!][!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!LOOP "F2a/*"!][!/*
*/!][!LOOP "F2aChannel/*"!][!/*
*/!][!IF "./F2aChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "F2aChannelUsed" = "num:i(1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*[!LOOP "F2aChannel/*"!]
*/!][!ENDLOOP!][!/*[!LOOP "Fifo/*"!]
*/!][!ENDSELECT!][!/*[!SELECT "GtmConfiguration/*[1]"!]
*/!][!IF "$F2aChannelUsed = num:i(1)"!][!/*
*/!]static const Gtm_F2aConfigType Gtm_kF2aConfig[!"$ModuleId"!][GTM_NO_OF_F2A_CHANNELS * GTM_NO_OF_FIFO_MODULES] = 
{
[!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!VAR "F2AConfiguredCount" = "num:i(0)"!][!/*
*/!][!LOOP "F2a/*"!][!/*
*/!][!LOOP "F2aChannel/*"!][!/*
*/!][!VAR "F2AConfiguredCount" = "num:i($F2AConfiguredCount + 1)"!][!/*
*/!]  {
[!IF "./F2aChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./F2aChannelEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./F2aAruDataTransferMode) = 'F2A_TRANSFER_UPPER_ARU_WORD'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ELSEIF "node:value(./F2aAruDataTransferMode) = 'F2A_TRANSFER_BOTH_ARU_WORDS'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./F2aAruDataTransferDirection) = 'F2A_TRANSFER_FIFO_TO_ARU'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!]    [!"num:inttohex($BuildReg,2)"!]U,
    [!"num:inttohex(./F2aAruReadAddress,4)"!]U
[!ELSE!][!/*
*/!]    GTM_SETUNUSED8,
    0x0000U
[!ENDIF!][!/* [!IF "./F2aChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!]  },
[!ENDLOOP!][!/*  [!LOOP "F2aChannel/*"!]
*/!][!ENDLOOP!][!/*  [!LOOP "F2a/*"!]
*/!][!VAR "TotalF2aChannels" = "(num:i(ecu:get('Gtm.NumberOfF2AModules')) * num:i(ecu:get('Gtm.NumberOfFifoChannels')))"!][!/*
*/!][!IF "num:i($F2AConfiguredCount) != num:i($TotalF2aChannels)"!][!/*
*/!][!FOR "Count" = "0" TO "((num:i($TotalF2aChannels) - num:i($F2AConfiguredCount))-1)"!][!/*
*/!]  {
    GTM_SETUNUSED8,
    0x0000U
  },
[!ENDFOR!][!/* [!FOR "Count" = "0" TO "(num:i($TotalFifoChannels) - num:i($FifoConfiguredCount))"!]
*/!][!ENDIF!][!/* [!IF "$FifoConfiguredCount != (num:i($TotalFifoChannels)"!]
*/!][!ENDSELECT!][!/*[!SELECT "GtmConfiguration/*[1]"!]
*/!]};[!/*
*/!][!ENDIF!][!/*[!IF "$F2aChannelUsed = num:i(1)"
*/!][!ENDIF!][!/* IF "node:exists(GtmConfiguration/*[1]/F2a/*[1])
*/!][!/* End of F2A
*/!][!/* 
**********************************************************************************************************
**********************************************************************************************************
                                               Configuration of MCS
**********************************************************************************************************
**********************************************************************************************************
*/!][!/*
*/!][!/* MCS Configuration
*/!][!VAR "McsConfigured" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(GtmConfiguration/*[1]/Mcs/*)"!][!/*
*/!][!IF "node:value(./McsGeneral/McsUsage) = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "McsConfigured" = "num:i(1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!IF "$McsConfigured = num:i(1)"!][!/*
*/!]
static const Gtm_McsConfigType Gtm_kMcsConfig[!"$ModuleId"!][GTM_NO_OF_MCS_MODULES]=
{
[!LOOP "node:order(GtmConfiguration/*[1]/Mcs/*)"!][!/*
*/!]  {
[!IF "./McsGeneral/McsUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./McsGeneral/McsSchedulingScheme) = 'ROUND_ROBIN_SCHEDULING_SCHEME'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./McsGeneral/McsHaltOnStackPointerOverflow) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!//
    [!"$BuildReg"!]U,
[!ELSE!][!/*
*/!]    GTM_SETUNUSED8,
[!ENDIF!][!//
    {    
[!LOOP "node:order(./McsChannel/*)"!][!/*
*/!][!IF "./../../McsGeneral/McsUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./McsChannelEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./McsChannelInterruptEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*    
*/!][!IF "node:value(./McsChStackErrorInterruptEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*        
*/!][!IF "node:value(./McsChMemoryErrorInterruptEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!]      Gtm_lIncludeIntMode8Bit([!"$BuildReg"!]U, [!"node:value(./McsChannelInterruptMode)"!]),                
[!ELSE!][!/*
*/!]      0x00U,
[!ENDIF!][!/*
*/!][!ENDLOOP!][!//
    },
    {
[!LOOP "node:order(./McsChannel/*)"!][!/*
*/!][!IF "./../../McsGeneral/McsUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "BuildErrReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./McsChannelInterruptEnableErr) = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./McsChStackErrorInterruptEnableErr) = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 1)"!][!/*
*/!][!ENDIF!][!/*    
*/!][!IF "node:value(./McsChMemoryErrorInterruptEnableErr) = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 2)"!][!/*
*/!][!ENDIF!][!/*        
*/!]    [!"num:inttohex($BuildErrReg,2)"!]U,
[!ELSE!][!/*
*/!]      0x00U,
[!ENDIF!][!/*
*/!][!ENDLOOP!][!//
    }
  },
[!ENDLOOP!][!//

};
[!ENDIF!][!// IF "$McsConfigured = num:i(1)"
[!/* End of MCS 
*/!][!/* 
**********************************************************************************************************
**********************************************************************************************************
          Validation of TOM, ATOM Channels used by PWM, GPT and Complex Driver
**********************************************************************************************************
**********************************************************************************************************
*/!][!/*
*/!][!/* For Port Configuration
*/!][!VAR "ToutSel0" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel1" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel2" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel3" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel4" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel5" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel6" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel7" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel8" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel9" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel10" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel11" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel12" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel13" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel14" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel15" = "num:i(0)"!][!/*
*/!][!VAR "ToutSel16" = "num:i(0)"!][!/*
*/!][!CALL "Gtm_ClearToutSelCheck"!][!/*
*/!][!/* Validation of TOM and ATOM Channels
*/!][!VAR "TomModuleLookUp1"  = "num:i(0)"!][!/*
*/!][!VAR "TomModuleLookUp2"  = "num:i(0)"!][!/*
*/!][!VAR "TomModuleLookUp3"  = "num:i(0)"!][!/*
*/!][!VAR "TomModuleLookUp4"  = "num:i(0)"!][!/*
*/!][!VAR "TomModuleLookUp5"  = "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp1"  = "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp2"  = "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp3"  = "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp4"  = "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp5"  = "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp6"  = "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp7"  = "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp8"  = "num:i(0)"!][!/*
*/!][!VAR "AtomModuleLookUp9"  = "num:i(0)"!][!/*
*/!][!VAR "TomUsage0"  = "num:i(0)"!][!/*
*/!][!VAR "TomUsage1"  = "num:i(0)"!][!/*
*/!][!VAR "TomUsage2"  = "num:i(0)"!][!/*
*/!][!VAR "AtomUsage0"  = "num:i(0)"!][!/*
*/!][!VAR "AtomUsage1"  = "num:i(0)"!][!/*
*/!][!VAR "AtomUsage2"  = "num:i(0)"!][!/*
*/!][!VAR "TomTGCUsage0"  = "num:i(0)"!][!/*
*/!][!VAR "AtomAGCUsage0"  = "num:i(0)"!][!/*
*/!][!VAR "PwmId" = "$ModuleId"!][!/*
*/!][!SELECT "as:modconf('Pwm')[1]"!][!/*
*/!][!SELECT "PwmChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "PwmChannel/*"!][!/*
*/!][!ASSERT "node:refexists(./PwmAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: PWM: PWMAssignedHwUnit is not configured.[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./PwmAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./PwmAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "$ModuleType = 'Tom'"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp1"  = "bit:bitset($TomModuleLookUp1, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp2"  = "bit:bitset($TomModuleLookUp2, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp3"  = "bit:bitset($TomModuleLookUp3, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp4"  = "bit:bitset($TomModuleLookUp4, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp5"  = "bit:bitset($TomModuleLookUp5, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSE!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp1"  = "bit:bitset($AtomModuleLookUp1, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp2"  = "bit:bitset($AtomModuleLookUp2, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp3"  = "bit:bitset($AtomModuleLookUp3, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp4"  = "bit:bitset($AtomModuleLookUp4, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp5"  = "bit:bitset($AtomModuleLookUp5, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(5)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp6, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp6"  = "bit:bitset($AtomModuleLookUp6, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(6)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp7, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp7"  = "bit:bitset($AtomModuleLookUp7, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(7)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp8, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp8"  = "bit:bitset($AtomModuleLookUp8, $SetPosition)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(8)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp9, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: PWM: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "AtomModuleLookUp9"  = "bit:bitset($AtomModuleLookUp9, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*  
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ENDSELECT!][!/*
*/!][!/*
*/!][!/*
*/!][!/* Information from GPT
*/!][!SELECT "as:modconf('Gpt')[1]"!][!/*
*/!][!SELECT "GptChannelConfigSet/*[@index= $PwmId]"!][!/*
*/!][!LOOP "GptChannelConfiguration/*"!][!/*
*/!][!ASSERT "node:refexists(./GptAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: GPT: GptAssignedHwUnit is not configured.[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./GptAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./GptAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "$ModuleType = 'Tom'"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TomModuleLookUp1"  = "bit:bitset($TomModuleLookUp1, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp2"  = "bit:bitset($TomModuleLookUp2, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp3"  = "bit:bitset($TomModuleLookUp3, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp4"  = "bit:bitset($TomModuleLookUp4, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp5"  = "bit:bitset($TomModuleLookUp5, $SetPosition + 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSE!][!/*[!IF "$ModuleType = 'Tom'"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*    
*/!][!VAR "AtomModuleLookUp1"  = "bit:bitset($AtomModuleLookUp1, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp2"  = "bit:bitset($AtomModuleLookUp2, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp3"  = "bit:bitset($AtomModuleLookUp3, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp4"  = "bit:bitset($AtomModuleLookUp4, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp5"  = "bit:bitset($AtomModuleLookUp5, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(5)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp6, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp6"  = "bit:bitset($AtomModuleLookUp6, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(6)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp7, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp7"  = "bit:bitset($AtomModuleLookUp7, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(7)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp8, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp8"  = "bit:bitset($AtomModuleLookUp8, $SetPosition + 1)"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(8)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp9, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: GPT: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp9"  = "bit:bitset($AtomModuleLookUp9, $SetPosition + 1)"!][!/*
*/!][!ENDIF!][!/*  
*/!][!ENDIF!][!/*  
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ENDSELECT!][!/*
*/!][!/*
*/!][!/* Information in GTM as Complex
*/!][!VAR "ComplexDriverTomConfig" = "num:i(0)"!][!/*
*/!][!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!LOOP "Tom/*"!][!/*
*/!][!LOOP "TomChannel/*"!][!/*
*/!][!IF "./TomChannelUsage/TomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "ComplexDriverTomConfig" = "1"!][!/*  
*/!][!VAR "ChannelLocation" = "node:name(.)"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(./../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp1"  = "bit:or($TomModuleLookUp1, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp2"  = "bit:or($TomModuleLookUp2, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp3"  = "bit:or($TomModuleLookUp3, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp4"  = "bit:or($TomModuleLookUp4, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($TomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TomModuleLookUp5"  = "bit:or($TomModuleLookUp5, bit:shl(3,$SetPosition))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*  
*/!][!ENDLOOP!][!/*
*/!][!ENDLOOP!][!/*
*/!][!/* For ATOM
*/!][!VAR "ComplexDriverAtomConfig" = "num:i(0)"!][!/*
*/!][!LOOP "Atom/*"!][!/*
*/!][!LOOP "AtomChannel/*"!][!/*
*/!][!IF "./AtomChannelUsage/AtomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "ComplexDriverAtomConfig" = "1"!][!/*  
*/!][!VAR "ChannelLocation" = "node:name(.)"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(./../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*    
*/!][!VAR "AtomModuleLookUp1"  = "bit:or($AtomModuleLookUp1, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp2"  = "bit:or($AtomModuleLookUp2, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp3"  = "bit:or($AtomModuleLookUp3, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp4"  = "bit:or($AtomModuleLookUp4, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp5"  = "bit:or($AtomModuleLookUp5, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(5)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp6, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp6"  = "bit:or($AtomModuleLookUp6, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(6)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp7, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp7"  = "bit:or($AtomModuleLookUp7, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(7)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp8, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp8"  = "bit:or($AtomModuleLookUp8, bit:shl(3,$SetPosition))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(8)"!][!/*
*/!][!ASSERT "bit:and($AtomModuleLookUp9, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ATOM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "AtomModuleLookUp9"  = "bit:or($AtomModuleLookUp9, bit:shl(3,$SetPosition))"!][!/*
*/!][!ENDIF!][!/*  
*/!][!ENDIF!][!/*  
*/!][!ENDLOOP!][!/*
*/!][!ENDLOOP!][!/*
*/!][!/* For Debug
Tom Lookup1 is [!"num:inttohex($TomModuleLookUp1)"!]
Tom Lookup2 is [!"num:inttohex($TomModuleLookUp2)"!]
Atom Lookup1 is [!"num:inttohex($AtomModuleLookUp1)"!]
Atom Lookup2 is [!"num:inttohex($AtomModuleLookUp2)"!]
*/!][!ENDSELECT!][!/*
*/!][!/* Generating variables for Configuration usage */!][!/*
*/!][!/* TOM Usage Bit Coded Info */!][!/*
*/!][!VAR "TomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "15"!][!/*
*/!][!IF "bit:and($TomModuleLookUp1, bit:shl(3, $TomCount)) != 0"!][!/*
*/!][!VAR "TomUsage0" = "bit:or($TomUsage0, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TomCount" = "num:i($TomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "16" TO "31"!][!/*
*/!][!IF "bit:and($TomModuleLookUp2, bit:shl(3, $TomCount)) != 0"!][!/*
*/!][!VAR "TomUsage0" = "bit:or($TomUsage0, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TomCount" = "num:i($TomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "15"!][!/*
*/!][!IF "bit:and($TomModuleLookUp3, bit:shl(3, $TomCount)) != 0"!][!/*
*/!][!VAR "TomUsage1" = "bit:or($TomUsage1, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TomCount" = "num:i($TomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "16" TO "31"!][!/*
*/!][!IF "bit:and($TomModuleLookUp4, bit:shl(3, $TomCount)) != 0"!][!/*
*/!][!VAR "TomUsage1" = "bit:or($TomUsage1, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TomCount" = "num:i($TomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "15"!][!/*
*/!][!IF "bit:and($TomModuleLookUp5, bit:shl(3, $TomCount)) != 0"!][!/*
*/!][!VAR "TomUsage2" = "bit:or($TomUsage2, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TomCount" = "num:i($TomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
         ATOM Usage Bit Coded Info
*/!][!VAR "AtomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "7"!][!/*
*/!][!IF "bit:and($AtomModuleLookUp1, bit:shl(3, $AtomCount)) != 0"!][!/*
*/!][!VAR "AtomUsage0" = "bit:or($AtomUsage0, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "AtomCount" = "num:i($AtomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "8" TO "15"!][!/*
*/!][!IF "bit:and($AtomModuleLookUp2, bit:shl(3, $AtomCount)) != 0"!][!/*
*/!][!VAR "AtomUsage0" = "bit:or($AtomUsage0, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "AtomCount" = "num:i($AtomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "16" TO "23"!][!/*
*/!][!IF "bit:and($AtomModuleLookUp3, bit:shl(3, $AtomCount)) != 0"!][!/*
*/!][!VAR "AtomUsage0" = "bit:or($AtomUsage0, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "AtomCount" = "num:i($AtomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "24" TO "31"!][!/*
*/!][!IF "bit:and($AtomModuleLookUp4, bit:shl(3, $AtomCount)) != 0"!][!/*
*/!][!VAR "AtomUsage0" = "bit:or($AtomUsage0, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "AtomCount" = "num:i($AtomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "7"!][!/*
*/!][!IF "bit:and($AtomModuleLookUp5, bit:shl(3, $AtomCount)) != 0"!][!/*
*/!][!VAR "AtomUsage1" = "bit:or($AtomUsage1, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "AtomCount" = "num:i($AtomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "8" TO "15"!][!/*
*/!][!IF "bit:and($AtomModuleLookUp6, bit:shl(3, $AtomCount)) != 0"!][!/*
*/!][!VAR "AtomUsage1" = "bit:or($AtomUsage1, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "AtomCount" = "num:i($AtomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "16" TO "23"!][!/*
*/!][!IF "bit:and($AtomModuleLookUp7, bit:shl(3, $AtomCount)) != 0"!][!/*
*/!][!VAR "AtomUsage1" = "bit:or($AtomUsage1, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "AtomCount" = "num:i($AtomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "24" TO "31"!][!/*
*/!][!IF "bit:and($AtomModuleLookUp8, bit:shl(3, $AtomCount)) != 0"!][!/*
*/!][!VAR "AtomUsage1" = "bit:or($AtomUsage1, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "AtomCount" = "num:i($AtomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "7"!][!/*
*/!][!IF "bit:and($AtomModuleLookUp9, bit:shl(3, $AtomCount)) != 0"!][!/*
*/!][!VAR "AtomUsage2" = "bit:or($AtomUsage2, bit:shl(1, $Count))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "AtomCount" = "num:i($AtomCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
         For TOM TGC Usage bit Coded Information 
*/!][!FOR "Count1" = "0" TO "3"!][!/*
*/!][!VAR "BuildTemp" = "num:i(0)"!][!/*
*/!][!FOR "Count2" = "$Count1 * 8" TO "($Count1 * 8) + 7"!][!/*
*/!][!VAR "BuildTemp" = "bit:or($BuildTemp, bit:getbit($TomUsage0,$Count2))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TomTGCUsage0" = "bit:or($TomTGCUsage0, bit:shl($BuildTemp, $Count1))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!FOR "Count1" = "0" TO "3"!][!/*
*/!][!VAR "BuildTemp" = "num:i(0)"!][!/*
*/!][!FOR "Count2" = "$Count1 * 8" TO "($Count1 * 8) + 7"!][!/*
*/!][!VAR "BuildTemp" = "bit:or($BuildTemp, bit:getbit($TomUsage1,$Count2))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TomTGCUsage0" = "bit:or($TomTGCUsage0, bit:shl($BuildTemp, 4 + $Count1))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!FOR "Count1" = "0" TO "3"!][!/* required in case of TC29x only first 16 bits are used in last TomUsage(2) i.e[32(2 TOM)+32(2 TOM)+16(1 TOM)]
*/!][!VAR "BuildTemp" = "num:i(0)"!][!/*
*/!][!FOR "Count2" = "$Count1 * 8" TO "($Count1 * 8) + 7"!][!/*
*/!][!VAR "BuildTemp" = "bit:or($BuildTemp, bit:getbit($TomUsage2,$Count2))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TomTGCUsage0" = "bit:or($TomTGCUsage0, bit:shl($BuildTemp, 8 + $Count1))"!][!/*
*/!][!ENDFOR!][!/*
         For ATOM AGC Usage bit Coded Information 
*/!][!FOR "Count1" = "0" TO "3"!][!/*
*/!][!VAR "BuildTemp" = "num:i(0)"!][!/*
*/!][!FOR "Count2" = "$Count1 * 8" TO "($Count1 * 8) + 7"!][!/*
*/!][!VAR "BuildTemp" = "bit:or($BuildTemp, bit:getbit($AtomUsage0,$Count2))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomAGCUsage0" = "bit:or($AtomAGCUsage0, bit:shl($BuildTemp, $Count1))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!FOR "Count1" = "0" TO "3"!][!/*
*/!][!VAR "BuildTemp" = "num:i(0)"!][!/*
*/!][!FOR "Count2" = "$Count1 * 8" TO "($Count1 * 8) + 7"!][!/*
*/!][!VAR "BuildTemp" = "bit:or($BuildTemp, bit:getbit($AtomUsage1,$Count2))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomAGCUsage0" = "bit:or($AtomAGCUsage0, bit:shl($BuildTemp, 4 + $Count1))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!FOR "Count1" = "0" TO "3"!][!/* required in case of TC29x only first 8 bits are used in last TomUsage(2) i.e[32(4 ATOM)+32(4 ATOM)+8(1 ATOM)]
*/!][!VAR "BuildTemp" = "num:i(0)"!][!/*
*/!][!FOR "Count2" = "$Count1 * 8" TO "($Count1 * 8) + 7"!][!/*
*/!][!VAR "BuildTemp" = "bit:or($BuildTemp, bit:getbit($AtomUsage2,$Count2))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "AtomAGCUsage0" = "bit:or($AtomAGCUsage0, bit:shl($BuildTemp, 8 + $Count1))"!][!/*
*/!][!ENDFOR!][!/*
*/!][!/*
*/!][!/*
*/!][!/* 
*******************************************************************************
*******************************************************************************
                              Configuration for TOM
*******************************************************************************
*******************************************************************************
*/!][!/*
*/!][!/* To decide if TOM structure should be generated or not */!]
[!VAR "TGCBitCodedInfo" = "num:i(0)"!][!/*
*/!][!VAR "AGCBitCodedInfo" = "num:i(0)"!][!/*
*/!][!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!IF "(bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0) or (bit:or($TomModuleLookUp3, $TomModuleLookUp4) != 0) or ($TomModuleLookUp5 != 0)"!][!/* If any TOM Channel is used
*/!][!IF "$ComplexDriverTomConfig = 1"!][!/*
*/!]static const Gtm_TomTgcConfigGroupType Gtm_kTomTgcConfigGroup[!"$ModuleId"!][] =
{
[!/* This structure is available only for those channels configured as Complex Driver
 Handling for Tom Modules 0 and 1   
*/!][!CALL "Gtm_TgcConfigure", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_TgcConfigure", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!][!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_TgcConfigure", "TomModuleLookUp"="$TomModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_TgcConfigure", "TomModuleLookUp"="$TomModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!CALL "Gtm_TgcConfigure", "TomModuleLookUp"="$TomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!]
};

[!/* To generate GTM_TOMChannelConfig structure 
*/!]static const Gtm_TomChannelConfigType Gtm_kTomChannelConfig[!"$ModuleId"!][]=
{
[!CALL "Gtm_TomChannelConfig", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!][!/*  
*/!][!CALL "Gtm_TomChannelConfig", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!][!/*    
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_TomChannelConfig", "TomModuleLookUp"="$TomModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_TomChannelConfig", "TomModuleLookUp"="$TomModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!CALL "Gtm_TomChannelConfig", "TomModuleLookUp"="$TomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!]
};
[!ENDIF!][!/* IF "$ComplexDriverTomConfig = 1"
*/!][!/* Generation of GTM_TOMTGCConfig
*/!]static const Gtm_TomTgcConfigType Gtm_kTomTgcConfig[!"$ModuleId"!][] =
{
[!VAR "TGCConfigureCount" = "num:i(0)"!][!/*
*/!][!CALL "Gtm_TomTgcConfig", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_TomTgcConfig", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!][!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_TomTgcConfig", "TomModuleLookUp"="$TomModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_TomTgcConfig", "TomModuleLookUp"="$TomModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!CALL "Gtm_TomTgcConfig", "TomModuleLookUp"="$TomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!]
};

static const Gtm_TomConfigType Gtm_kTomConfig[!"$ModuleId"!][] = 
{
[!VAR "TomConfigureCount"  = "num:i(-1)"!][!/* To identify the index of the Tom Channel Config structure
*/!][!CALL "Gtm_TomConfig", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_TomConfig", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!][!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_TomConfig", "TomModuleLookUp"="$TomModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_TomConfig", "TomModuleLookUp"="$TomModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!CALL "Gtm_TomConfig", "TomModuleLookUp"="$TomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!][!/*
*/!][!/*
*/!]};
[!ENDIF!][!/* [!IF "(bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0) or (bit:or($TomModuleLookUp3, $TomModuleLookUp4) != 0) or ($TomModuleLookUp5 ! = 0)"!]
*/!][!/* 
*******************************************************************************
*******************************************************************************
                               Configuration for ATOM
*******************************************************************************
*******************************************************************************
*/!][!/* 
*/!][!IF "(bit:or($AtomModuleLookUp1, $AtomModuleLookUp2) != 0) or (bit:or($AtomModuleLookUp3, $AtomModuleLookUp4) != 0) or (bit:or($AtomModuleLookUp5, $AtomModuleLookUp6) != 0) or (bit:or($AtomModuleLookUp7, $AtomModuleLookUp8) != 0) or ($AtomModuleLookUp9 != 0)"!][!/* If any ATOM Channel is used
*/!][!IF "$ComplexDriverAtomConfig = 1"!][!/*
*/!]
static const Gtm_AtomAgcConfigGroupType Gtm_kAtomAgcConfigGroup[!"$ModuleId"!][] =
{
[!/* This structure is available only for those channels configured as Complex Driver
 Handling for Atom Modules   
*/!][!CALL "Gtm_AgcConfigure", "AtomModuleLookUp"="$AtomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_AgcConfigure", "AtomModuleLookUp"="$AtomModuleLookUp2", "ModuleNumber"="1"!][!/*
*/!][!CALL "Gtm_AgcConfigure", "AtomModuleLookUp"="$AtomModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!CALL "Gtm_AgcConfigure", "AtomModuleLookUp"="$AtomModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_AgcConfigure", "AtomModuleLookUp"="$AtomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_AgcConfigure", "AtomModuleLookUp"="$AtomModuleLookUp6", "ModuleNumber"="5"!][!/*
*/!][!CALL "Gtm_AgcConfigure", "AtomModuleLookUp"="$AtomModuleLookUp7", "ModuleNumber"="6"!][!/*
*/!][!CALL "Gtm_AgcConfigure", "AtomModuleLookUp"="$AtomModuleLookUp8", "ModuleNumber"="7"!][!/*
*/!][!CALL "Gtm_AgcConfigure", "AtomModuleLookUp"="$AtomModuleLookUp9", "ModuleNumber"="8"!][!/*
*/!][!ENDIF!]
};
[!/* To generate Gtm_AtomChannelConfig structure 
*/!]
static const Gtm_AtomChannelConfigType Gtm_kAtomChannelConfig[!"$ModuleId"!][]=
{
[!CALL "Gtm_AtomChannelConfig", "AtomModuleLookUp"="$AtomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_AtomChannelConfig", "AtomModuleLookUp"="$AtomModuleLookUp2", "ModuleNumber"="1"!][!/*
*/!][!CALL "Gtm_AtomChannelConfig", "AtomModuleLookUp"="$AtomModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!CALL "Gtm_AtomChannelConfig", "AtomModuleLookUp"="$AtomModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_AtomChannelConfig", "AtomModuleLookUp"="$AtomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_AtomChannelConfig", "AtomModuleLookUp"="$AtomModuleLookUp6", "ModuleNumber"="5"!][!/*
*/!][!CALL "Gtm_AtomChannelConfig", "AtomModuleLookUp"="$AtomModuleLookUp7", "ModuleNumber"="6"!][!/*
*/!][!CALL "Gtm_AtomChannelConfig", "AtomModuleLookUp"="$AtomModuleLookUp8", "ModuleNumber"="7"!][!/*
*/!][!CALL "Gtm_AtomChannelConfig", "AtomModuleLookUp"="$AtomModuleLookUp9", "ModuleNumber"="8"!][!/*
*/!][!ENDIF!]
};
[!ENDIF!][!/* IF "$ComplexDriverAtomConfig = 1"
*/!][!/* Generation of GTM_ATOMAGCConfig
*/!]
static const Gtm_AtomAgcConfigType Gtm_kAtomAgcConfig[!"$ModuleId"!][] =
{
[!VAR "AGCConfigureCount" = "num:i(0)"!][!/* Variable to maintain a running count of the AGC structure index
*/!][!CALL "Gtm_AtomAgcConfig", "AtomModuleLookUp"="$AtomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_AtomAgcConfig", "AtomModuleLookUp"="$AtomModuleLookUp2", "ModuleNumber"="1"!][!/*
*/!][!CALL "Gtm_AtomAgcConfig", "AtomModuleLookUp"="$AtomModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!CALL "Gtm_AtomAgcConfig", "AtomModuleLookUp"="$AtomModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_AtomAgcConfig", "AtomModuleLookUp"="$AtomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_AtomAgcConfig", "AtomModuleLookUp"="$AtomModuleLookUp6", "ModuleNumber"="5"!][!/*
*/!][!CALL "Gtm_AtomAgcConfig", "AtomModuleLookUp"="$AtomModuleLookUp7", "ModuleNumber"="6"!][!/*
*/!][!CALL "Gtm_AtomAgcConfig", "AtomModuleLookUp"="$AtomModuleLookUp8", "ModuleNumber"="7"!][!/*
*/!][!CALL "Gtm_AtomAgcConfig", "AtomModuleLookUp"="$AtomModuleLookUp9", "ModuleNumber"="8"!][!/*
*/!][!ENDIF!]
};

static const Gtm_AtomConfigType Gtm_kAtomConfig[!"$ModuleId"!][] = 
{
[!VAR "AtomConfigureCount"  = "num:i(-1)"!][!/* To identify the index of the Atom Channel Config structure
*/!][!CALL "Gtm_AtomConfig", "AtomModuleLookUp"="$AtomModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_AtomConfig", "AtomModuleLookUp"="$AtomModuleLookUp2", "ModuleNumber"="1"!][!/*
*/!][!CALL "Gtm_AtomConfig", "AtomModuleLookUp"="$AtomModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!CALL "Gtm_AtomConfig", "AtomModuleLookUp"="$AtomModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_AtomConfig", "AtomModuleLookUp"="$AtomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_AtomConfig", "AtomModuleLookUp"="$AtomModuleLookUp6", "ModuleNumber"="5"!][!/*
*/!][!CALL "Gtm_AtomConfig", "AtomModuleLookUp"="$AtomModuleLookUp7", "ModuleNumber"="6"!][!/*
*/!][!CALL "Gtm_AtomConfig", "AtomModuleLookUp"="$AtomModuleLookUp8", "ModuleNumber"="7"!][!/*
*/!][!CALL "Gtm_AtomConfig", "AtomModuleLookUp"="$AtomModuleLookUp9", "ModuleNumber"="8"!][!/*
*/!][!ENDIF!]
};
[!ENDIF!][!/* [!IF "(bit:or($AtomModuleLookUp1, $AtomModuleLookUp2) != 0) or (bit:or($AtomModuleLookUp3, $AtomModuleLookUp4) != 0) or ($AtomModuleLookUp5 != 0)"!][!/* If any ATOM Channel is used
*/!][!/* 

*******************************************************************************
*******************************************************************************
                                Configuration for SPE
*******************************************************************************
*******************************************************************************
*/!][!VAR "SpeConfigured" = "num:i(0)"!][!/*
*/!][!LOOP "(Spe/*)"!][!/*
*/!][!IF "./SpeGeneral/SpeUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "SpeConfigured" = "num:i(1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!IF "$SpeConfigured = num:i(1)"!][!/*
*/!]

static const Gtm_SpeConfigType Gtm_kSpeConfig[!"$ModuleId"!][] =
{
[!LOOP "(Spe/*)"!][!/*
*/!][!IF "./SpeGeneral/SpeUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!]  {[!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "./SpeInterrupt/SpeEnableIntOnNewPatternDetect = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeInterrupt/SpeEnableIntOnSpeDirBitChange = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeInterrupt/SpeEnableIntOnWrongPattern = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeInterrupt/SpeEnableIntOnBouncingInput = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeInterrupt/SpeEnableIntOnRegComp = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,4)"!][!/*
*/!][!ENDIF!][!/*
*/!]
    Gtm_lIncludeIntMode8Bit([!"num:inttohex($BuildReg,2)"!]U, [!"./SpeInterrupt/SpeInterruptMode"!]),[!/*
*/!][!VAR "BuildErrReg" = "num:i(0)"!][!/*
*/!][!IF "./SpeErrorInterrupt/SpeEnableIntOnNewPatternDetectErr = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg,0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeErrorInterrupt/SpeEnableIntOnSpeDirBitChangeErr = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg,1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeErrorInterrupt/SpeEnableIntOnWrongPatternErr = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg,2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeErrorInterrupt/SpeEnableIntOnBouncingInputErr = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg,3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeErrorInterrupt/SpeEnableIntOnRegCompErr = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg,4)"!][!/*
*/!][!ENDIF!][!/*
*/!]
    [!"num:inttohex($BuildErrReg,2)"!]U,[!/*
*/!]
    {
[!LOOP "(./SpeOutputConfig/*)"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "./SpeOutputSelect = 'TOM_CH1_SOUR'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,0)"!][!/*
*/!][!ELSEIF "./SpeOutputSelect = 'LEVEL_0'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,1)"!][!/*
*/!][!ELSEIF "./SpeOutputSelect = 'LEVEL_1'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,1)"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,0)"!][!/*
*/!][!ENDIF!][!/*
*/!]      [!"num:inttohex($BuildReg,4)"!]U,
[!ENDLOOP!][!/* 
*/!]    },
[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "./SpeGeneral/SpeEnableModule = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TempReg" = "text:split(./SpeGeneral/SpeTimChannelsSelect, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "TempReg" = "text:split($TempReg, 'EL')[position()-1 = 1]"!][!/*
*/!][!IF "$TempReg = '1'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,6)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeGeneral/SpeEnableInput0 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeGeneral/SpeEnableInput1 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeGeneral/SpeEnableInput2 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeGeneral/SpeTriggerInputSelect = 'TOM_CH2_TRIG_CCU1'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,5)"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,4)"!][!/*
*/!][!ELSEIF "./SpeGeneral/SpeTriggerInputSelect = 'TOM_CH0_TRIG_CCU1'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,5)"!][!/*
*/!][!ELSEIF "./SpeGeneral/SpeTriggerInputSelect = 'TOM_CH0_TRIG_CCU0'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./SpeGeneral/SpeEnableFastShutOff = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,7)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "Location" = "num:i(24)"!][!/*
*/!][!LOOP "(./SpeOutputConfig/*)"!][!/*
*/!][!IF "./SpeFastShutoffLevel = 'HIGH_LEVEL'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $Location)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "Location" = "num:i($Location + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]    [!"num:inttohex($BuildReg,8)"!]U,
[!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "Location" = "num:i(0)"!][!/*
*/!][!LOOP "(./SpeInputPattern/*)"!][!/*
*/!][!IF "./SpeIsPatternValid = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,$Location)"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(./SpeInputPattern, $Location + 1))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "Location" = "num:i($Location + 4)"!][!/* 
*/!][!ENDLOOP!][!/* 
*/!]    [!"num:inttohex($BuildReg,8)"!]U,
    [!"num:inttohex(node:value(./SpeGeneral/SpeInputSigRevCntr),8)"!]U,
    [!"num:inttohex(node:value(./SpeGeneral/SpeInputSigRevCntrCmpVal),8)"!]U
  },
[!ENDIF!][!/* [!IF "./SpeGeneral/SpeUsage = 'USED_BY_GTM_DRIVER'"!]  
*/!][!ENDLOOP!][!/*
*/!]};
[!ENDIF!][!/*[!IF "$SpeConfigured = num:i(1)"!]
*/!][!/*
*******************************************************************************
*******************************************************************************
                          Configuration for DPLL
*******************************************************************************
*******************************************************************************
*/!][!IF "node:exists(Dpll/*[1])"!]   

static const Gtm_DpllConfigType Gtm_kDpllConfig[!"$ModuleId"!] =
{
[!SELECT "Dpll/*[1]"!][!/*
*/!][!/* DPLL_CTRL_0[!/*
*/!]  [!"num:inttohex(bit:shl(node:value(./DpllStateSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForAdt),2) ,2)"!]U,
  [!"num:inttohex(node:value(./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerSignalNtiCntValue),4)"!]U,
  [!"num:inttohex(bit:shl(node:value(./DpllTriggerSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForAdt),2) ,4)"!]U,
[!VAR "BuildReg" = "num:i(0)"!][!/*  
*/!][!FOR "LoopCount" = "0" TO "7"!][!/*
*/!][!IF "./DpllEnableAction/*[@index= $LoopCount]/DpllEnableAction = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount)"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount + 8)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDFOR!][!/*
*/!]  [!"num:inttohex($BuildReg,4)"!]U,
[!VAR "BuildReg" = "num:i(0)"!][!/*  
*/!][!FOR "LoopCount" = "0" TO "7"!][!/*
*/!][!IF "./DpllEnableAction/*[@index= ($LoopCount + 8)]/DpllEnableAction = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount)"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount + 8)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDFOR!][!/*
*/!]  [!"num:inttohex($BuildReg,4)"!]U,
[!VAR "BuildReg" = "num:i(0)"!][!/*  
*/!][!FOR "LoopCount" = "0" TO "7"!][!/*
*/!][!IF "./DpllEnableAction/*[@index= ($LoopCount + 16)]/DpllEnableAction = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount)"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount + 8)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDFOR!][!/*
*/!]  [!"num:inttohex($BuildReg,4)"!]U,
[!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*  
*/!][!FOR "LoopCount" = "0" TO "7"!][!/*
*/!][!IF "./DpllEnableAction/*[@index= ($LoopCount + 24)]/DpllEnableAction = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount)"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount + 8)"!][!/*
*/!][!ENDIF!][!/* IF "./DpllEnableAction/*[@index= ($LoopCount + 24)]/DpllEnableAction = 'true'"
*/!][!ENDFOR!][!/* FOR "LoopCount" = "0" TO "7"
*/!]  [!"num:inttohex($BuildReg,4)"!]U,
[!ENDIF!][!/*IF "$RelDerivate = 'TC29x'"
*/!]  {
[!FOR "LoopCount" = "0" TO "11"!][!/*  
*/!]
    [!"num:inttohex(node:value(./DpllAruIdToInSigPmtr/*[@index= $LoopCount]/DpllAruIdInfoToInputSignalPmtr),4)"!]U,[!/*    
*/!][!ENDFOR!][!/*  
*/!][!FOR "LoopCount" = "12" TO "23"!][!/*  
*/!]
    [!"num:inttohex(node:value(./DpllAruIdToInSigPmtr/*[@index= $LoopCount]/DpllAruIdInfoToInputSignalPmtr),4)"!]U,[!/*    
*/!][!ENDFOR!][!/*  
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*  
*/!][!FOR "LoopCount" = "24" TO "31"!][!/*  
*/!]
    [!"num:inttohex(node:value(./DpllAruIdToInSigPmtr/*[@index= $LoopCount]/DpllAruIdInfoToInputSignalPmtr),4)"!]U,[!/*    
*/!][!ENDFOR!][!/*IF "$RelDerivate = 'TC29x'"
*/!][!ENDIF!]
  },
[!/*
*/!][!VAR "BuildReg" = "num:i(node:value(./DpllSubInc1SignalConfig/DpllPulseCntBtwnTrigEvntsMlt) - 1) "!][!/* MLT
*/!][!IF "./DpllGeneral/DpllInputFilterPositionContent = 'POSITION_RELATED_VALUES'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,10)"!][!/* IFP
*/!][!ENDIF!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllStateSignal/DpllStateGeneral/DpllStateEventsPerHalfScale) - 1), 11))"!][!/* SNU
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerEventsPerHalfScale) - 1), 16))"!][!/* TNU
*/!][!IF "./DpllStateSignal/DpllStateGeneral/DpllStateUseAdaptMode = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,25)"!][!/* AMS
*/!][!ENDIF!][!/*
*/!][!IF "./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerUseAdaptMode = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,26)"!][!/* AMT
*/!][!ENDIF!][!/*
*/!][!IF "./DpllStateSignal/DpllStateGeneral/DpllStateUseDelayInfo = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,27)"!][!/* IDS
*/!][!ENDIF!][!/*
*/!][!IF "./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerUseDelayInfo = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,28)"!][!/* IDT
*/!][!ENDIF!][!/*
*/!][!IF "./DpllStateSignal/DpllStateGeneral/DpllStateSignalEnable = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,29)"!][!/* SEN
*/!][!ENDIF!][!/*
*/!][!IF "./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerSignalEnable = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,30)"!][!/* TEN
*/!][!ENDIF!][!/*
*/!][!IF "./DpllGeneral/DpllReferenceMode = 'EMERGENCY_MODE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,31)"!][!/* RMO
*/!][!ENDIF!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
[!/* DPLL_CTRL_1
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "./DpllGeneral/DpllModeAndCorrectionStrategySel = 'AUTOENDMODE_WITH_IMMED_PULSES'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,3)"!][!/* COA
*/!][!ELSEIF "./DpllGeneral/DpllModeAndCorrectionStrategySel = 'CONTINUOUS_MODE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,0)"!][!/* DMO
*/!][!ENDIF!][!/*
*/!][!IF "./DpllGeneral/DpllEnable = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,1)"!][!/* DEN
*/!][!ENDIF!][!/*
*/!][!IF "./DpllTriggerSignal/DpllTriggerGeneral/DpllPlausibilityValueContent = 'TIME_RELATED_INFO'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,4)"!][!/* PIT
*/!][!ENDIF!][!/*
*/!][!IF "./DpllSubInc1SignalConfig/DpllEnableSubInc1Generator = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,5)"!][!/* SGE1
*/!][!ENDIF!][!/*
*/!][!IF "./DpllSubInc1SignalConfig/DpllUseDirectLoadMode = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,6)"!][!/* DLM1
*/!][!ENDIF!][!/*
*/!][!IF "./DpllSubInc1SignalConfig/DpllUsePulseCorrectionMode = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,7)"!][!/* PCM1
*/!][!ENDIF!][!/*
*/!][!IF "./DpllSubInc2SignalConfig/DpllEnableSubInc2Generator = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,8)"!][!/* SGE2
*/!][!ENDIF!][!/*
*/!][!IF "./DpllSubInc2SignalConfig/DpllUseDirectLoadMode = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,9)"!][!/* DLM2
*/!][!ENDIF!][!/*
*/!][!IF "./DpllSubInc2SignalConfig/DpllUsePulseCorrectionMode = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,10)"!][!/* PCM2
*/!][!ENDIF!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllStateSignal/DpllStateGeneral/DpllVirtualIncPerHalfScale)), 11))"!][!/* SYN_NS
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllTriggerSignal/DpllTriggerGeneral/DpllVirtualIncrementCount)), 16))"!][!/* SYN_NT
*/!][!IF "./DpllTriggerSignal/DpllTriggerGeneral/DpllVirtualIncrRange = 'VIRT_INCR_FOR_FULL_SCALE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,24)"!][!/* SYSF
*/!][!ENDIF!][!/*
*/!][!IF "./DpllTriggerSignal/DpllTriggerGeneral/DpllTrigSigTimeStampResolution = 'IS_8_TIMES_MORE_THAN_TBU_TS0'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,26)"!][!/* TS0_HRT
*/!][!ENDIF!][!/*
*/!][!IF "./DpllStateSignal/DpllStateGeneral/DpllStateSigTimeStampResolution = 'IS_8_TIMES_MORE_THAN_TBU_TS0'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,25)"!][!/* TS0_HRS
*/!][!ENDIF!][!/*
*/!][!IF "./DpllGeneral/DpllSynchronousMotorControl = 'TRIGGER_IS_COMBINED_SENSOR_SIG'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,27)"!][!/* SMC
*/!][!ENDIF!][!/*
*/!][!IF "./DpllGeneral/DpllInputDirDetStrategy = 'INPUT_DET_USING_TDIR'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,2)"!][!/* IDDS
*/!][!ENDIF!][!/*
*/!][!IF "./DpllGeneral/DpllLockingCondition = 'LC_N_1_MISSING_TRIGGER'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,22)"!][!/* LCD
*/!][!ENDIF!][!/*
*/!][!IF "./DpllStateSignal/DpllStateGeneral/DpllStateSignalActiveEdge = 'BOTH_EDGES'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,28)"!][!/* SSL
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,29)"!][!/* SSL
*/!][!ELSEIF "./DpllStateSignal/DpllStateGeneral/DpllStateSignalActiveEdge = 'FALLING_EDGE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,29)"!][!/* SSL
*/!][!ELSEIF "./DpllStateSignal/DpllStateGeneral/DpllStateSignalActiveEdge = 'RISING_EGDE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,28)"!][!/* SSL
*/!][!ENDIF!][!/*
*/!][!IF "./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerSignalActiveEdge = 'BOTH_EDGES'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,30)"!][!/* TSL
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,31)"!][!/* TSL
*/!][!ELSEIF "./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerSignalActiveEdge = 'FALLING_EDGE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,31)"!][!/* TSL
*/!][!ELSEIF "./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerSignalActiveEdge = 'RISING_EGDE'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,30)"!][!/* TSL
*/!][!ENDIF!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
[!/* DPLL_APT
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "./DpllTriggerSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForDtAndRdt != '0'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,1)"!][!/* WAPT
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllTriggerSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForDtAndRdt)), 2))"!][!/* APT
*/!][!ENDIF!][!/*
*/!][!IF "./DpllTriggerSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForTsf != '0'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,13)"!][!/* WAPT_2b
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllTriggerSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForTsf)), 14))"!][!/* APT_2b
*/!][!ENDIF!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
[!/* DPLL_APS
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "./DpllStateSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForDtAndRdt  != '0'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,1)"!][!/* WAPS
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllStateSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForDtAndRdt)), 2))"!][!/* APS
*/!][!ENDIF!][!/*
*/!][!IF "./DpllStateSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForTsf != '0'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,13)"!][!/* WAPS_1c2
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllStateSignal/DpllActualRamPointerAddress/DpllActRamPtrAddOffForTsf)), 14))"!][!/* APS_1c2
*/!][!ENDIF!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
[!/* DPLL_Assort0
*/!][!VAR "BuildReg" = "./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerSignalNuteValue"!][!/* NUTE
*/!][!IF "./DpllTriggerSignal/DpllTriggerGeneral/DpllTrigIsNuteEqualToFullScale = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!/*FST
*/!][!ENDIF!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllTriggerSignal/DpllTriggerGeneral/DpllTriggerSignalVtnValue)), 11))"!][!/* VTN
*/!][!IF "./DpllRAMRegion2Address/DpllOffsetSizeForRegion2 = 'OFFSET_SIZE_1024'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 17)"!][!/*OSS
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 18)"!][!/*OSS
*/!][!ELSEIF "./DpllRAMRegion2Address/DpllOffsetSizeForRegion2 = 'OFFSET_SIZE_512'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 18)"!][!/*OSS
*/!][!ELSEIF "./DpllRAMRegion2Address/DpllOffsetSizeForRegion2 = 'OFFSET_SIZE_256'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 17)"!][!/*OSS
*/!][!ENDIF!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllStateSignal/DpllStateGeneral/DpllStateSignalNuseValue)), 19))"!][!/* NUSE
*/!][!IF "./DpllStateSignal/DpllStateGeneral/DpllStateIsNuseEqualToFullScale = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 25)"!][!/*FSS
*/!][!ENDIF!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg,bit:shl(num:i(node:value(./DpllStateSignal/DpllStateGeneral/DpllStateSignalVsnValue)), 26))"!][!/* VSN
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
[!/* DPLL_IrqEnable
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnDpllDisable = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnDpllEnable = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTrigMinHoldTimeErr = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTrigMaxHoldTimeErr = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnStateInactiveSlope = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerInactiveSlope = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnMissingStateSignal = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 6)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnMissingTriggerSignal = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 7)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnStateActiveSlope = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 8)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerActiveSlope = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 9)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnPlausWindowViolation = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 10)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnRamWriteAccessToReg2 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnRamWriteAccToReg1b1c = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 12)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnSubInc1LockGet = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 13)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnSubInc1LockLost = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 14)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnError = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 15)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnSubInc2LockGet = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 16)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnSubInc2LockLost = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 17)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerEvent0 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 18)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerEvent1 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 19)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerEvent2 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 20)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerEvent3 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 21)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerEvent4 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 22)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerDurCalcDone = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 23)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnStateDurCalcDone = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 24)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerOutOfRange = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 25)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnStateOutOfRange = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 26)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllInterrupt/DpllEnIntOnTriggerDirChange = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 27)"!][!/*
*/!][!ENDIF!][!/*
*/!]  Gtm_lIncludeIntMode32Bit([!"num:inttohex($BuildReg,8)"!]U,[!"node:value(./DpllInterrupt/DpllInterruptMode)"!]),
[!/* DPLL_ErrIntEnable
*/!][!VAR "BuildErrReg" = "num:i(0)"!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnDpllDisable = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnDpllEnable = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTrigMinHoldTimeErr = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTrigMaxHoldTimeErr = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnStateInactiveSlope = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerInactiveSlope = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnMissingStateSignal = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 6)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnMissingTriggerSignal = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 7)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnStateActiveSlope = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 8)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerActiveSlope = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 9)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnPlausWindowViolation = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 10)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnRamWriteAccessToReg2 = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnRamWriteAccToReg1b1c = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 12)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnSubInc1LockGet = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 13)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnSubInc1LockLost = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 14)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnError = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 15)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnSubInc2LockGet = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 16)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnSubInc2LockLost = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 17)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerEvent0 = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 18)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerEvent1 = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 19)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerEvent2 = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 20)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerEvent3 = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 21)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerEvent4 = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 22)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerDurCalcDone = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 23)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnStateDurCalcDone = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 24)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerOutOfRange = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 25)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnStateOutOfRange = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 26)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./DpllErrorInterrupt/DpllEnErrIntOnTriggerDirChange = 'true'"!][!/*
*/!][!VAR "BuildErrReg" = "bit:bitset($BuildErrReg, 27)"!][!/*
*/!][!ENDIF!][!/*
*/!]  [!"num:inttohex($BuildErrReg,8)"!]U,
  [!"num:inttohex(node:value(./DpllSubInc1SignalConfig/DpllDirectLoadValue),8)"!]U,
  [!"num:inttohex(node:value(./DpllSubInc2SignalConfig/DpllDirectLoadValue),8)"!]U
[!ENDSELECT!][!/*
*/!]};
[!ENDIF!][!/*
*******************************************************************************
*******************************************************************************
                          Configuration for CMP
*******************************************************************************
*******************************************************************************
*/!][!IF "node:exists(./Cmp/*[1])"!][!/*
*/!]
static const Gtm_CmpConfigType Gtm_kCmpConfig[!"$ModuleId"!] = 
{
[!VAR "BuildReg" = "num:i(0)"!][!/*  
*/!][!VAR "BuildRegInt" = "num:i(0)"!][!/*  
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "(./Cmp/*[1]/CmpTomChanComparator/*)"!][!/*
*/!][!IF "./CmpEnableComparator = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount + 12)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./CmpEnableInterruptOnError = 'true'"!][!/*
*/!][!VAR "BuildRegInt" = "bit:bitset($BuildRegInt, $LoopCount + 12)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "(./Cmp/*[1]/CmpAtomChanComparator/*)"!][!/*
*/!][!IF "./CmpEnableComparator = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./CmpEnableInterruptOnError = 'true'"!][!/*
*/!][!VAR "BuildRegInt" = "bit:bitset($BuildRegInt, $LoopCount)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
  Gtm_lIncludeIntMode32Bit([!"num:inttohex($BuildRegInt,8)"!]U,[!"node:value(./Cmp/*[1]/CmpInterrupt/CmpInterruptMode)"!]),
[!VAR "BuildRegErrInt" = "num:i(0)"!][!/*   
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC0InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC1InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC2InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 2)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC3InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC4InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC5InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 5)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC6InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 6)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC7InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 7)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC8InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 8)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC9InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 9)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC10InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 10)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableABWC11InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 11)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC0InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 12)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC1InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 13)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC2InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 14)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC3InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 15)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC4InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 16)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC5InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 17)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC6InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 18)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC7InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 19)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC8InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 20)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC9InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 21)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC10InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 22)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Cmp/*[1]/CmpErrorInterrupt/CmpEnableTBWC11InterruptSource) = 'true'"!][!/*  
*/!][!VAR "BuildRegErrInt" = "bit:bitset($BuildRegErrInt, 23)"!][!/*
*/!][!ENDIF!][!/*
*/!]  [!"num:inttohex($BuildRegErrInt,8)"!]U
};
[!ENDIF!][!/*
*******************************************************************************
*******************************************************************************
                          Configuration for TIM
*******************************************************************************
*******************************************************************************
*/!][!/* Validation of TIM from ICU */!][!/*
*/!][!VAR "IcuId" = "$ModuleId"!][!/*
*/!][!VAR "TimModuleLookUp1" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp2" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp3" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp4" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp5" = "num:i(0)"!][!/*
*/!][!VAR "TimModuleLookUp6" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup1" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup2" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup3" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup4" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup5" = "num:i(0)"!][!/*
*/!][!VAR "TimTimeStampLookup6" = "num:i(0)"!][!/*
*/!][!SELECT "as:modconf('Icu')[1]"!][!/*
*/!][!LOOP "IcuConfigSet/*[@index= $IcuId]/IcuChannel/*"!][!/*
*/!][!ASSERT "node:refexists(./IcuAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: ICU: Reference cell [!"@name"!] not provided - configure AssignedHwUnit
[!ENDASSERT!][!/*
*/!][!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!IF "contains($ChannelLocation, "TimChannel") = 'true'"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./IcuAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp1"  = "bit:bitset($TimModuleLookUp1, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup1"  = "bit:bitset($TimTimeStampLookup1, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp2"  = "bit:bitset($TimModuleLookUp2, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup2"  = "bit:bitset($TimTimeStampLookup2, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp3"  = "bit:bitset($TimModuleLookUp3, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup3"  = "bit:bitset($TimTimeStampLookup3, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp4"  = "bit:bitset($TimModuleLookUp4, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup4"  = "bit:bitset($TimTimeStampLookup4, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp5"  = "bit:bitset($TimModuleLookUp5, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup5"  = "bit:bitset($TimTimeStampLookup5, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(5)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp6, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: ICU: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "TimModuleLookUp6"  = "bit:bitset($TimModuleLookUp6, $SetPosition)"!][!/*
*/!][!IF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!/*
*/!][!VAR "TimTimeStampLookup6"  = "bit:bitset($TimTimeStampLookup6, $SetPosition)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/* IF "contains($ChannelLocation, "TimChannel") = 'true'"
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!/* Validation of TIM from Complex */!][!/*
*/!][!VAR "ComplexDriverTimConfig" = "num:i(0)"!][!/*
*/!][!LOOP "Tim/*"!][!/*
*/!][!LOOP "TimChannel/*"!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "ComplexDriverTimConfig" = "1"!][!/*  
*/!][!VAR "ChannelLocation" = "node:name(.)"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(./../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SetPosition" = "(2 * $ChannelNumber)"!][!/*
*/!][!IF "$ModuleNumber = num:i(0)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp1, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TimModuleLookUp1"  = "bit:bitset($TimModuleLookUp1, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(1)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp2, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TimModuleLookUp2"  = "bit:bitset($TimModuleLookUp2, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(2)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp3, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TimModuleLookUp3"  = "bit:bitset($TimModuleLookUp3, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(3)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp4, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TimModuleLookUp4"  = "bit:bitset($TimModuleLookUp4, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(4)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp5, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TimModuleLookUp5"  = "bit:bitset($TimModuleLookUp5, num:i($SetPosition + 1))"!][!/*
*/!][!ELSEIF "$ModuleNumber = num:i(5)"!][!/*
*/!][!ASSERT "bit:and($TimModuleLookUp6, bit:shl(3,$SetPosition)) = 0"!][!/*
*/!]ERROR: TIM[!"$ModuleNumber"!] Channel[!"$ChannelNumber"!] is configured more than once[!/*
*/!][!ENDASSERT!][!/*  
*/!][!VAR "TimModuleLookUp6"  = "bit:bitset($TimModuleLookUp6, num:i($SetPosition + 1))"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDLOOP!][!/*
*/!][!/*
*/!][!/* Generating variables for Configuration usage */!][!/*
*/!][!/* TIM Usage Bit Coded Info */!][!/*
*/!][!VAR "TimCount" = "num:i(0)"!][!/*
*/!][!VAR "TimFltCount" = "num:i(0)"!][!/*
*/!][!VAR "TimUsage0" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "7"!][!/*
*/!][!IF "bit:and($TimModuleLookUp1, bit:shl(3, $TimCount)) != 0"!][!/*
*/!][!VAR "TimUsage0" = "bit:bitset($TimUsage0,$Count)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TimCount" = "num:i($TimCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TimCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "8" TO "15"!][!/*
*/!][!IF "bit:and($TimModuleLookUp2, bit:shl(3, $TimCount)) != 0"!][!/*
*/!][!VAR "TimUsage0" = "bit:bitset($TimUsage0,$Count)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TimCount" = "num:i($TimCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TimCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "16" TO "23"!][!/*
*/!][!IF "bit:and($TimModuleLookUp3, bit:shl(3, $TimCount)) != 0"!][!/*
*/!][!VAR "TimUsage0" = "bit:bitset($TimUsage0,$Count)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TimCount" = "num:i($TimCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TimCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "24" TO "31"!][!/*
*/!][!IF "bit:and($TimModuleLookUp4, bit:shl(3, $TimCount)) != 0"!][!/*
*/!][!VAR "TimUsage0" = "bit:bitset($TimUsage0,$Count)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TimCount" = "num:i($TimCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TimCount" = "num:i(0)"!][!/*
*/!][!VAR "TimUsage1" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "0" TO "7"!][!/*
*/!][!IF "bit:and($TimModuleLookUp5, bit:shl(3, $TimCount)) != 0"!][!/*
*/!][!VAR "TimUsage1" = "bit:bitset($TimUsage1,$Count)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TimCount" = "num:i($TimCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!VAR "TimCount" = "num:i(0)"!][!/*
*/!][!FOR "Count" = "8" TO "15"!][!/*
*/!][!IF "bit:and($TimModuleLookUp6, bit:shl(3, $TimCount)) != 0"!][!/*
*/!][!VAR "TimUsage1" = "bit:bitset($TimUsage1,$Count)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "TimCount" = "num:i($TimCount + 2)"!][!/*
*/!][!ENDFOR!][!/*
*/!][!/* Generating TIM Filter Structure 
*/!][!IF "(bit:or($TimModuleLookUp1, $TimModuleLookUp2) != 0) or (bit:or($TimModuleLookUp3, $TimModuleLookUp4) != 0) or (bit:or($TimModuleLookUp5, $TimModuleLookUp6) != 0)"!][!/*
*/!][!VAR "TimFltFirstTime" = "num:i(0)"!][!/*
*/!][!CALL "Gtm_TimFltConfig", "TimModuleLookUp"="$TimModuleLookUp1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_TimFltConfig", "TimModuleLookUp"="$TimModuleLookUp2", "ModuleNumber"="1"!][!/*
*/!][!CALL "Gtm_TimFltConfig", "TimModuleLookUp"="$TimModuleLookUp3", "ModuleNumber"="2"!][!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_TimFltConfig", "TimModuleLookUp"="$TimModuleLookUp4", "ModuleNumber"="3"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_TimFltConfig", "TimModuleLookUp"="$TimModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!CALL "Gtm_TimFltConfig", "TimModuleLookUp"="$TimModuleLookUp6", "ModuleNumber"="5"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$TimFltFirstTime = num:i(1)"!][!/*
*/!]};
[!ENDIF!][!/* IF "$TimFltFirstTime = num:i(1)
*/!][!ENDIF!][!/* IF "(bit:or($TimModuleLookUp1, $TimModuleLookUp2) != 0) or (bit:or($TimModuleLookUp3, $TimModuleLookUp4) != 0  or (bit:or($TimModuleLookUp5, $TimModuleLookUp6) != 0
*/!][!/* TIM Config Structure */
*/!][!VAR "TimSel0" = "num:i(0)"!][!/* For Port Configuration
*/!][!VAR "TimSel1" = "num:i(0)"!][!/* For Port Configuration
*/!][!VAR "TimSel2" = "num:i(0)"!][!/* For Port Configuration
*/!][!VAR "TimSel3" = "num:i(0)"!][!/* For Port Configuration
*/!][!VAR "TimSel4" = "num:i(0)"!][!/* For Port Configuration
*/!][!VAR "TimSel5" = "num:i(0)"!][!/* For Port Configuration
*/!][!VAR "TbuUsageInTim" = "num:i(0)"!][!/* For Port Configuration
*/!][!IF "(bit:or($TimModuleLookUp1, $TimModuleLookUp2) != 0) or (bit:or($TimModuleLookUp3, $TimModuleLookUp4) != 0) or (bit:or($TimModuleLookUp5, $TimModuleLookUp6) != 0)"!][!/*
*/!]


static const Gtm_TimConfigType Gtm_kTimConfig[!"$ModuleId"!][] =
{
[!CALL "Gtm_TimConfig", "TimModuleLookUp"="$TimModuleLookUp1", "TimTimeStampLookup"="$TimTimeStampLookup1", "ModuleNumber"="0"!][!/*
*/!][!CALL "Gtm_TimConfig", "TimModuleLookUp"="$TimModuleLookUp2", "TimTimeStampLookup"="$TimTimeStampLookup2", "ModuleNumber"="1"!][!/*
*/!][!CALL "Gtm_TimConfig", "TimModuleLookUp"="$TimModuleLookUp3", "TimTimeStampLookup"="$TimTimeStampLookup3", "ModuleNumber"="2"!][!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!][!CALL "Gtm_TimConfig", "TimModuleLookUp"="$TimModuleLookUp4", "TimTimeStampLookup"="$TimTimeStampLookup4", "ModuleNumber"="3"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!][!CALL "Gtm_TimConfig", "TimModuleLookUp"="$TimModuleLookUp5", "TimTimeStampLookup"="$TimTimeStampLookup5", "ModuleNumber"="4"!][!/*
*/!][!CALL "Gtm_TimConfig", "TimModuleLookUp"="$TimModuleLookUp6", "TimTimeStampLookup"="$TimTimeStampLookup6", "ModuleNumber"="5"!]
[!ENDIF!]
};
[!ENDIF!]
static const Gtm_ModUsageConfigType Gtm_kModUsage[!"$ModuleId"!] =
{  
  { /*TIM Module Usage */
    
     /*TIM0 Module Usage*/[!/*
*/!][!VAR "TotalGtmTimConf" = "num:i(-1)"!][!/* Holds the no of Tim channels configured for GTM complex driver
*/!][!CALL "Gtm_TimUsageByOtherMod", "TimModuleLookUp"="$TimModuleLookUp1", "ModuleNumber"="0"!],[!/*
*/!]
     /*TIM1 Module Usage*/[!/*
*/!]
[!CALL "Gtm_TimUsageByOtherMod", "TimModuleLookUp"="$TimModuleLookUp2", "ModuleNumber"="1"!],[!/*
*/!]
     /*TIM2 Module Usage*/[!/*
*/!]
[!CALL "Gtm_TimUsageByOtherMod", "TimModuleLookUp"="$TimModuleLookUp3", "ModuleNumber"="2"!],[!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!]
     /*TIM3 Module Usage*/[!/*
*/!]
[!CALL "Gtm_TimUsageByOtherMod", "TimModuleLookUp"="$TimModuleLookUp4", "ModuleNumber"="3"!],[!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!]
     /*TIM4 Module Usage*/[!/*
*/!]
[!CALL "Gtm_TimUsageByOtherMod", "TimModuleLookUp"="$TimModuleLookUp5", "ModuleNumber"="4"!],[!/*
*/!]
     /*TIM5 Module Usage*/[!/*
*/!][!CALL "Gtm_TimUsageByOtherMod", "TimModuleLookUp"="$TimModuleLookUp6", "ModuleNumber"="5"!]
[!ENDIF!]
  },
  {   /*TOM module Usage */[!/*
*/!]
     /*TOM Module 0 Usage*/[!/*
*/!][!VAR "TotalGtmTomConf" = "num:i(-1)"!][!/* Holds the no of Tim channels configured for GTM complex driver
*/!][!CALL "Gtm_TomUsageByOtherMod", "TomModuleLookUp"="$TomModuleLookUp1", "ModuleNumber"="0"!],[!/*
*/!]
     /*TOM Module 1 Usage*/[!/*
*/!]
[!CALL "Gtm_TomUsageByOtherMod", "TomModuleLookUp"="$TomModuleLookUp2", "ModuleNumber"="1"!],[!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!]
     /*TOM Module 2 Usage*/[!/*
*/!]
[!CALL "Gtm_TomUsageByOtherMod", "TomModuleLookUp"="$TomModuleLookUp3", "ModuleNumber"="2"!],[!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!]
     /*TOM Module 3 Usage*/[!/*
*/!]
[!CALL "Gtm_TomUsageByOtherMod", "TomModuleLookUp"="$TomModuleLookUp4", "ModuleNumber"="3"!],[!/*
*/!]
     /*TOM Module 4 Usage*/[!/*
*/!]
[!CALL "Gtm_TomUsageByOtherMod", "TomModuleLookUp"="$TomModuleLookUp5", "ModuleNumber"="4"!][!/*
*/!][!ENDIF!][!/*
*/!]
  },[!//
[!VAR "MutiNotifUsed" = "num:i(0)"!][!/* 

  Holds whether multiple CCU notifications are used for ATOM or not 
  0 = single notification function is used for all the atom channels
  1 = Seperate notification functions are used for all/some the atom channels
  
  
  Note: If there is atleast one channel configured for multiple notifications the 
  generated Gtm_ModUsageConfigType structure will have 16 bit data member for ATOM 
  index reference to Gtm_kNotifConfig0 (atom notification member). [decided by MutiNotifUsed]
  
  In that case for each channel value the MSB will signify whether that particular 
  channel is configured for single channel notification (0) or multiple notifications (1).
  
  If MSB is one(multiple notifications are used for this channel) then 0-7 bits will hold 
  the index number for CCU0 member of  Gtm_kNotifConfig0 structure and 8-14 will hold the 
  index number for CCU1 member of Gtm_kNotifConfig0.  (LCFG file)
  
  If MSB is zero (single notification is used for this channel) then all bits 0-15 will hold 
  the value of index number for CCU0 member of Gtm_kNotifConfig0. (LCFG file)
  
  The check of single/multiple notification call for a channel and check for which CCU0 has 
  caused the interrupt is included in ISR.
  
  Otherwise if there are no channels configured with multiple notification and all the channels 
  have single notification function for CCU0 and CCU1 the structure will be of 8bits and it will
  signify the index for Atom notification function for Gtm_kNotifConfig0 structure. (LCFG file)
  
  This was implemeted for valeo request please refer UTP : AI00238938
  
*/!][!CALL "IsMultiNotifUsed"!][!//
[!IF "$MutiNotifUsed = num:i(0)"!][!//
  {     /*ATOM module Usage */
[!VAR "TotalGtmAtomConf"  = "num:i(-1)"!][!/* Holds the index of Atom channels configured for GTM complex driver
*/!]
[!VAR "AtomConfigureCount"  = "num:i(-1)"!][!/* To identify the index of the Atom Channel Config structure
*/!]
     /*ATOM Module 0 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp1", "ModuleNumber"="0"!],[!/*
*/!]
     /*ATOM Module 1 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp2", "ModuleNumber"="1"!],[!/*
*/!]
     /*ATOM Module 2 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp3", "ModuleNumber"="2"!],
     /*ATOM Module 3 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp4", "ModuleNumber"="3"!],[!/*
*/!]
[!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!]
   /*ATOM Module 4 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp5", "ModuleNumber"="4"!],[!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!]
     /*ATOM Module 5 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp6", "ModuleNumber"="5"!],[!/*
*/!]
     /*ATOM Module 6 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp7", "ModuleNumber"="6"!],[!/*
*/!]
     /*ATOM Module 7 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp8", "ModuleNumber"="7"!],[!/*
*/!]
     /*ATOM Module 8 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp9", "ModuleNumber"="8"!][!/*
*/!]
[!ENDIF!][!/*
*/!]
  }[!/*
*/!]
[!ELSE!][!//
  {     /*ATOM module Usage */
[!VAR "TotalGtmCCU0AtomConf"  = "num:i(-1)"!][!/* Holds the index of Atom channels configured for GTM complex driver
*/!]
[!VAR "TotalGtmCCU1AtomConf"  = "num:i(-1)"!][!/* Holds the index of Atom channels configured for GTM complex driver
*/!]
     /*ATOM Module 0 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp1", "ModuleNumber"="0"!],[!/*
*/!]
     /*ATOM Module 1 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp2", "ModuleNumber"="1"!],[!/*
*/!]
     /*ATOM Module 2 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp3", "ModuleNumber"="2"!],
     /*ATOM Module 3 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp4", "ModuleNumber"="3"!],[!/*
*/!]
[!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!]
   /*ATOM Module 4 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp5", "ModuleNumber"="4"!],[!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!]
     /*ATOM Module 5 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp6", "ModuleNumber"="5"!],[!/*
*/!]
     /*ATOM Module 6 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp7", "ModuleNumber"="6"!],[!/*
*/!]
     /*ATOM Module 7 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp8", "ModuleNumber"="7"!],[!/*
*/!]
     /*ATOM Module 8 Usage*/[!/*
*/!]
[!CALL "Gtm_AtomCCUUsageByOtherMod", "AtomModuleLookUp"="$AtomModuleLookUp9", "ModuleNumber"="8"!][!/*
*/!]
[!ENDIF!][!/*
*/!]
  }
[!ENDIF!]
};

[!/*
*******************************************************************************
*******************************************************************************
                  Configuration for TBU Connection
*******************************************************************************
*******************************************************************************
*/!][!/*
*/!][!VAR "TbuPresent" = "num:i(0)"!][!/*
*/!][!IF "node:exists(Tbu/*[1])"!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(Tbu/*[1]/TbuChannel/*)"!][!/*
*/!][!IF "(node:value(./TbuChannelUsage) = 'USED_BY_GTM_DRIVER') or (bit:getbit($TbuUsageInTim, $LoopCount))"!][!/*
*/!][!VAR "TbuPresent" = "num:i(1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDIF!][!/*


*/!][!IF "$TbuPresent = num:i(1)"!][!/*
*/!]
static const Gtm_TbuConfigType Gtm_kTbuConfig[!"$ModuleId"!][GTM_NO_OF_TBU_CHANNELS] = 
{
[!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(Tbu/*[1]/TbuChannel/*)"!][!/*
*/!]  {[!/*
*/!][!IF "(node:value(./TbuChannelUsage) = 'USED_BY_GTM_DRIVER') or (bit:getbit($TbuUsageInTim, $LoopCount))"!][!/*
*/!][!IF "node:value(./TbuEnableChannel) = 'true'"!][!/*
*/!][!VAR "TempTbuVal" = "num:i(1)"!][!/*   
*/!][!ELSE!][!/*
*/!][!VAR "TempTbuVal" = "num:i(0)"!][!/*     
*/!][!ENDIF!][!/*
*/!][!IF "contains(node:name(.), 0)"!][!/* If Tbu Channel 0 */!][!/*
*/!]  Gtm_lTbuBuildControl([!"./TbuChannelResolution"!], [!"./TbuChannelClockSource"!], [!"$TempTbuVal"!]U),[!/* 
*/!][!ELSE!][!/*
*/!]  Gtm_lTbuBuildControl([!"./TbuChannelModeSelect"!], [!"./TbuChannelClockSource"!], [!"$TempTbuVal"!]U),[!/* 
*/!][!ENDIF!][!/*
*/!]  [!"./TbuTimebaseValue"!]U[!/*  
*/!][!ELSE!][!/*
*/!]  GTM_SETUNUSED8 ,0x00000000U [!/*
*/!][!ENDIF!][!/*  
*/!]  },
[!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]};[!/*
*/!][!ENDIF!][!/*
*/!]
[!/*
*******************************************************************************
*******************************************************************************
                   Configuration for DSADC Connection
*******************************************************************************
*******************************************************************************
*/!][!/* 
*/!][!IF "node:exists(./GtmConnections/*[1])"!][!/*
*/!][!IF "node:exists(./GtmConnections/*[1]/GtmConnectionToDsadc/*[1])"!][!/*
*/!]
static const Gtm_DsadcConnectionsType Gtm_kDsadcConnections[!"$ModuleId"!] = 
{

[!/* To Display Insel 1 
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./GtmConnections/*[1]/GtmConnectionToDsadc/*[1]/GtmDsadcInputToTim0Ch/*)"!][!/*
*/!][!VAR "SelectNumber" = "text:split(./GtmDsadcInputToTim0Channel, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "SelectNumber" = "text:split($SelectNumber, 'L')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($SelectNumber, $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 4)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
[!/* To Display Insel 1 
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./GtmConnections/*[1]/GtmConnectionToDsadc/*[1]/GtmDsadcInputToTim1Ch/*)"!][!/*
*/!][!VAR "SelectNumber" = "text:split(./GtmDsadcInputToTim1Channel, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "SelectNumber" = "text:split($SelectNumber, 'L')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($SelectNumber, $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 4)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
[!/* To Display Insel 2 
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./GtmConnections/*[1]/GtmConnectionToDsadc/*[1]/GtmDsadcInputToTim2Ch/*)"!][!/*
*/!][!VAR "SelectNumber" = "text:split(./GtmDsadcInputToTim2Channel, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "SelectNumber" = "text:split($SelectNumber, 'L')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($SelectNumber, $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 4)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
[!/* To Display Outsel 00 
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./GtmConnections/*[1]/GtmConnectionToDsadc/*[1]/GtmOutputSelForDsadc/*)"!][!/*
*/!][!VAR "SelectNumber" = "text:split(./GtmDsadcTrigger0Select, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "SelectNumber" = "text:split($SelectNumber, 'L')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($SelectNumber, $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 4)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
[!/* To Display Outsel 10 
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./GtmConnections/*[1]/GtmConnectionToDsadc/*[1]/GtmOutputSelForDsadc/*)"!][!/*
*/!][!VAR "SelectNumber" = "text:split(./GtmDsadcTrigger1Select, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "SelectNumber" = "text:split($SelectNumber, 'L')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($SelectNumber, $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 4)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,
};
[!ENDIF!][!/*
*/!][!ENDIF!][!/*
*/!][!/*
*******************************************************************************
*******************************************************************************
                        Configuration for ADC Connection
*******************************************************************************
*******************************************************************************
*/!][!IF "node:exists(./GtmConnections/*[1])"!][!/*
*/!][!VAR "AdcCount" = "num:i(0)"!][!/*
*/!][!VAR "AdcCount1" = "num:i(count(./GtmConnections/*[1]/GtmTriggerForAdc/*))- 1"!][!/*
*/!][!VAR "AdcCount1" = "num:i($AdcCount1 + 0)"!]
static const uint8 Gtm_kAdcConnections[!"$ModuleId"!][GTM_NO_OF_ADC_MODULES] = 
{
[!FOR "AdcCount" = "0" TO "(num:i($AdcCount1))"!][!//
[!VAR "AdcChName" = "concat('GtmTriggerForAdc_',$AdcCount)"!][!//
[!SELECT "./GtmConnections/*[1]/GtmTriggerForAdc/*[@name=$AdcChName]"!][!//
[!VAR "SelectTrigger0" = "text:split(./GtmTrigger0Select, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "SelectTrigger1" = "text:split(./GtmTrigger1Select, '_')[position()-1 = 1]"!][!/*
*/!] [!"num:inttohex(bit:or(num:i($SelectTrigger0), bit:shl(num:i($SelectTrigger1), 4)),2)"!]U,[!/*
*/!][!ENDSELECT!][!//
[!ENDFOR!]
};
[!ENDIF!][!/*
*/!][!/*
*******************************************************************************
*******************************************************************************
                       Configuration for MSC Connections
*******************************************************************************
*******************************************************************************
*/!][!IF "node:exists(./GtmConnections/*[1])"!][!/*
*/!][!IF "node:exists(./GtmConnections/*[1]/GtmConnectionToMsc/*[1])"!][!/*
*/!]
static const Gtm_MscSetType Gtm_kMscSet[!"$ModuleId"!][GTM_NO_OF_MSC_SETS]= 
{
  {
    {
[!/* For Set 1
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg1" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg2" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg3" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg4" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "num:i(0)"!][!/*
*/!][!LOOP "./GtmConnections/*[1]/GtmConnectionToMsc/*[1]/GtmSelectSet1Output/*"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split(node:value(./GtmSelectSet1Output), '_')[position()-1 = 0]"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split($BuildRegTemp, 'ONTROL')[position()-1 = 1]"!][!/*
*/!][!IF "$LoopCount < 4"!][!/*
*/!][!VAR "BuildReg1" = "bit:or($BuildReg1, bit:shl($BuildRegTemp, ($LoopCount * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 8"!][!/*
*/!][!VAR "BuildReg2" = "bit:or($BuildReg2, bit:shl($BuildRegTemp, (num:i($LoopCount - 4) * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 12"!][!/*
*/!][!VAR "BuildReg3" = "bit:or($BuildReg3, bit:shl($BuildRegTemp, (num:i($LoopCount - 8) * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 16"!][!/*
*/!][!VAR "BuildReg4" = "bit:or($BuildReg4, bit:shl($BuildRegTemp, (num:i($LoopCount - 12) * 8)))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]      [!"num:inttohex($BuildReg1,8)"!]U,
      [!"num:inttohex($BuildReg2,8)"!]U,
      [!"num:inttohex($BuildReg3,8)"!]U,
      [!"num:inttohex($BuildReg4,8)"!]U
    }
  },
  {
    {  
[!/* For Set 2
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg1" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg2" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg3" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg4" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "num:i(0)"!][!/*
*/!][!LOOP "./GtmConnections/*[1]/GtmConnectionToMsc/*[1]/GtmSelectSet2Output/*"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split(node:value(./GtmSelectSet2Output), '_')[position()-1 = 0]"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split($BuildRegTemp, 'ONTROL')[position()-1 = 1]"!][!/*
*/!][!IF "$LoopCount < 4"!][!/*
*/!][!VAR "BuildReg1" = "bit:or($BuildReg1, bit:shl($BuildRegTemp, ($LoopCount * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 8"!][!/*
*/!][!VAR "BuildReg2" = "bit:or($BuildReg2, bit:shl($BuildRegTemp, (num:i($LoopCount - 4) * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 12"!][!/*
*/!][!VAR "BuildReg3" = "bit:or($BuildReg3, bit:shl($BuildRegTemp, (num:i($LoopCount - 8) * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 16"!][!/*
*/!][!VAR "BuildReg4" = "bit:or($BuildReg4, bit:shl($BuildRegTemp, (num:i($LoopCount - 12) * 8)))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]      [!"num:inttohex($BuildReg1,8)"!]U,
      [!"num:inttohex($BuildReg2,8)"!]U,
      [!"num:inttohex($BuildReg3,8)"!]U,
      [!"num:inttohex($BuildReg4,8)"!]U
    }
  },
  {
    {  
[!/* For Set 3
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg1" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg2" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg3" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg4" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "num:i(0)"!][!/*
*/!][!LOOP "./GtmConnections/*[1]/GtmConnectionToMsc/*[1]/GtmSelectSet3Output/*"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split(node:value(./GtmSelectSet3Output), '_')[position()-1 = 0]"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split($BuildRegTemp, 'ONTROL')[position()-1 = 1]"!][!/*
*/!][!IF "$LoopCount < 4"!][!/*
*/!][!VAR "BuildReg1" = "bit:or($BuildReg1, bit:shl($BuildRegTemp, ($LoopCount * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 8"!][!/*
*/!][!VAR "BuildReg2" = "bit:or($BuildReg2, bit:shl($BuildRegTemp, (num:i($LoopCount - 4) * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 12"!][!/*
*/!][!VAR "BuildReg3" = "bit:or($BuildReg3, bit:shl($BuildRegTemp, (num:i($LoopCount - 8) * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 16"!][!/*
*/!][!VAR "BuildReg4" = "bit:or($BuildReg4, bit:shl($BuildRegTemp, (num:i($LoopCount - 12) * 8)))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]      [!"num:inttohex($BuildReg1,8)"!]U,
      [!"num:inttohex($BuildReg2,8)"!]U,
      [!"num:inttohex($BuildReg3,8)"!]U,
      [!"num:inttohex($BuildReg4,8)"!]U
    }
  },
  {
    {  
[!/* For Set 4
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg1" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg2" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg3" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg4" = "num:i(0)"!][!/*
*/!][!VAR "BuildRegTemp" = "num:i(0)"!][!/*
*/!][!LOOP "./GtmConnections/*[1]/GtmConnectionToMsc/*[1]/GtmSelectSet4Output/*"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split(node:value(./GtmSelectSet4Output), '_')[position()-1 = 0]"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split($BuildRegTemp, 'ONTROL')[position()-1 = 1]"!][!/*
*/!][!IF "$LoopCount < 4"!][!/*
*/!][!VAR "BuildReg1" = "bit:or($BuildReg1, bit:shl($BuildRegTemp, ($LoopCount * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 8"!][!/*
*/!][!VAR "BuildReg2" = "bit:or($BuildReg2, bit:shl($BuildRegTemp, (num:i($LoopCount - 4) * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 12"!][!/*
*/!][!VAR "BuildReg3" = "bit:or($BuildReg3, bit:shl($BuildRegTemp, (num:i($LoopCount - 8) * 8)))"!][!/*
*/!][!ELSEIF "$LoopCount < 16"!][!/*
*/!][!VAR "BuildReg4" = "bit:or($BuildReg4, bit:shl($BuildRegTemp, (num:i($LoopCount - 12) * 8)))"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]      [!"num:inttohex($BuildReg1,8)"!]U,
      [!"num:inttohex($BuildReg2,8)"!]U,
      [!"num:inttohex($BuildReg3,8)"!]U,
      [!"num:inttohex($BuildReg4,8)"!]U
    }
  }  
};

static const Gtm_MscInputCtrlType Gtm_kMscInputCtrl[!"$ModuleId"!][GTM_NO_OF_MSC_MODULES]=
{
[!LOOP "./GtmConnections/*[1]/GtmConnectionToMsc/*[1]/GtmConnectionToMsc/*"!][!/*
*/!]  {
[!VAR "LoopCount" = "num:i(0)"!][!/*    
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*    
*/!][!LOOP "./GtmOutSelForMscInLow/*"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split(node:value(./GtmOutSelForMscInputLow), '_')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split($BuildRegTemp, 'ET')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl(num:i($BuildRegTemp - 1), $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/*  
*/!][!ENDLOOP!][!/*
*/!]    [!"num:inttohex($BuildReg,8)"!]U,
[!VAR "LoopCount" = "num:i(0)"!][!/*    
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*   
*/!][!LOOP "./GtmOutSelForMscInHigh/*"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split(node:value(./GtmOutSelForMscInHigh), '_')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildRegTemp" = "text:split($BuildRegTemp, 'ET')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl(num:i($BuildRegTemp - 1), $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 2)"!][!/* 
*/!][!ENDLOOP!][!/*
*/!]    [!"num:inttohex($BuildReg,8)"!]U,
  },
[!ENDLOOP!][!/*
*/!]};

static const Gtm_MscConnectionsType Gtm_kMscConnections[!"$ModuleId"!] = 
{
  &Gtm_kMscSet[!"$ModuleId"!][0],
  &Gtm_kMscInputCtrl[!"$ModuleId"!][0]
};
[!ENDIF!][!/* [!IF "node:exists(./GtmConnections/*[1]/GtmConnectionToMsc/*[1])
*/!][!ENDIF!][!/*[!IF "node:exists(./GtmConnections/*[1])"
*/!][!/*
******************************************************************************
******************************************************************************
                       Configuration for Port Configuration
******************************************************************************
******************************************************************************
*/!][!/*
*/!][!IF "(bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0) or (bit:or($TomModuleLookUp3, $TomModuleLookUp4) != 0) or ($TomModuleLookUp5 != 0) or  (bit:or($AtomModuleLookUp1, $AtomModuleLookUp2) != 0) or (bit:or($AtomModuleLookUp3, $AtomModuleLookUp4) != 0) or (bit:or($AtomModuleLookUp5, $AtomModuleLookUp6) != 0) or (bit:or($AtomModuleLookUp7, $AtomModuleLookUp8) != 0) or ($AtomModuleLookUp9 != 0) or (bit:or($TimModuleLookUp1, $TimModuleLookUp2) != 0) or (bit:or($TimModuleLookUp3, $TimModuleLookUp4) != 0) or (bit:or($TimModuleLookUp5, $TimModuleLookUp6) != 0)"!][!/*
*/!][!IF "$IsBmdUsed = 'true'"!][!/*
*/!][!VAR "ToutValue" = "num:i(0)"!][!/*
*/!][!VAR "PrepareString" = "num:i(0)"!][!/*
*/!][!IF "node:exists(./GtmConnections/*[1])"!][!/*
*/!][!IF "node:empty(./GtmConnections/*[1]/GtmToutConnections/*[1])"!][!/*
*/!][!VAR "ToutMajorCount" = "num:i(0)"!][!/*  
*/!][!LOOP "(./GtmConnections/*[1]/GtmToutConnections/*)"!][!/*
*/!][!VAR "ToutCount" = "num:i(0)"!][!/*
*/!][!LOOP "(./GtmToutSelect/*)"!][!/*
SELECT_TIMER_A
*/!][!VAR "ToutValue" = "text:split(node:value(./GtmTimerSelect), '_')[position()-1 = 2]"!][!/*
*/!][!IF "$ToutValue = 'A'"!][!/*
*/!][!VAR "ToutValue" = "num:i(0)"!][!/*
*/!][!ELSEIF "$ToutValue = 'B'"!][!/*
*/!][!VAR "ToutValue" = "num:i(1)"!][!/*
*/!][!ELSEIF "$ToutValue = 'C'"!][!/*
*/!][!VAR "ToutValue" = "num:i(2)"!][!/*
*/!][!ELSEIF "$ToutValue = 'D'"!][!/*
*/!][!VAR "ToutValue" = "num:i(3)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "PrepareString" = "bit:or($PrepareString , bit:shl($ToutValue,($ToutCount * 2)))"!][!/*
*/!][!VAR "ToutCount" = "$ToutCount + 1"!][!/*
*/!][!ENDLOOP!][!/* "(./GtmToutSelect/*)"
*/!][!VAR "TempStore" = "var:set(concat('ToutSel', num:i($ToutMajorCount)),$PrepareString)"!][!/*
*/!][!VAR "PrepareString" = "num:i(0)"!][!/*
*/!][!VAR "ToutMajorCount" = "$ToutMajorCount + 1"!][!/*
*/!][!ENDLOOP!][!/* "(./GtmConnections/*[1]/GtmToutConnections/*)"
*/!][!ENDIF!][!/* "node:empty(./GtmConnections/*[1]/GtmToutConnections/*[1])"
*/!][!ENDIF!][!/* "node:exists(./GtmConnections/*[1])"
*/!][!ENDIF!][!/* "$IsBmdUsed = 'true'"
*/!]

static const Gtm_PortConfigType Gtm_kPortConfig[!"$ModuleId"!] =
{
  {
    [!"num:inttohex($TimSel0,8)"!]U,
    [!"num:inttohex($TimSel1,8)"!]U,
    [!"num:inttohex($TimSel2,8)"!]U,[!/* 
*/!][!IF "$RelDerivate != 'TC26x'"!]
    [!"num:inttohex($TimSel3,8)"!]U,[!/* 
*/!][!ENDIF!][!/* 
*/!][!IF "$RelDerivate = 'TC29x'"!]
    [!"num:inttohex($TimSel4,8)"!]U,
    [!"num:inttohex($TimSel5,8)"!]U[!/* 
*/!][!ENDIF!]
  },
  {
    [!"num:inttohex($ToutSel0,8)"!]U,
    [!"num:inttohex($ToutSel1,8)"!]U,
    [!"num:inttohex($ToutSel2,8)"!]U,
    [!"num:inttohex($ToutSel3,8)"!]U,
    [!"num:inttohex($ToutSel4,8)"!]U,
    [!"num:inttohex($ToutSel5,8)"!]U,
    [!"num:inttohex($ToutSel6,8)"!]U,
    [!"num:inttohex($ToutSel7,8)"!]U,
    [!"num:inttohex($ToutSel8,8)"!]U,
    [!"num:inttohex($ToutSel9,8)"!]U,[!/* 
*/!][!IF "$RelDerivate != 'TC26x'"!]
    [!"num:inttohex($ToutSel10,8)"!]U,
    [!"num:inttohex($ToutSel11,8)"!]U,
    [!"num:inttohex($ToutSel12,8)"!]U,
    [!"num:inttohex($ToutSel13,8)"!]U,
    [!"num:inttohex($ToutSel14,8)"!]U,[!/* 
*/!][!ENDIF!][!/* 
*/!][!IF "$RelDerivate = 'TC29x'"!]
    [!"num:inttohex($ToutSel15,8)"!]U,
    [!"num:inttohex($ToutSel16,8)"!]U[!/* 
*/!][!ENDIF!]

  }
};
[!ENDIF!][!/*
*/!][!/*
********************************************************************************
********************************************************************************
                         Configuration for Module Configuration
********************************************************************************
********************************************************************************
*/!][!/* 
*/!]
static const Gtm_ModuleConfigType Gtm_kModuleConfig[!"$ModuleId"!] =
{
[!IF "node:exists(./Aru/*[1])"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "node:value(./Aru/*[1]/AruInterrupt/AruNewData0InterruptEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Aru/*[1]/AruInterrupt/AruNewData1InterruptEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "node:value(./Aru/*[1]/AruInterrupt/AruAccAckInterruptEnable) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg,2)"!][!/*
*/!][!ENDIF!][!/*
*/!]  /* ARU Configuration */[!/*
*/!]
  Gtm_lIncludeIntMode8Bit([!"$BuildReg"!]U,[!"node:value(./Aru/*[1]/AruInterrupt/AruInterruptMode)"!]),
[!ELSE!][!/*
*/!]  0x00U | (uint8)((uint8)1U << 5), [!/*Unused*/!] /* ARU Configuration */
[!ENDIF!][!/*
*/!][!IF "node:exists(./Mcfg/*[1])"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!VAR "Position" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./Mcfg/*[1]/McfgMemConfigForMcs/*)"!][!/*
*/!][!VAR "BuildRegTemp" = "num:i(0)"!][!/*
*/!][!IF "./McfgMemoryLayoutConfiguration  = 'SWAP'"!][!/*
*/!][!VAR "BuildRegTemp" = "bit:bitset($BuildRegTemp, 0)"!][!/*
*/!][!ELSEIF "./McfgMemoryLayoutConfiguration  = 'BORROW'"!][!/*
*/!][!VAR "BuildRegTemp" = "bit:bitset($BuildRegTemp, 1)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($BuildRegTemp,$Position))"!][!/*
*/!][!VAR "Position" = "num:i($Position + 2)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,2)"!]U,  /* Mcfg Configuration*/
[!ELSE!][!/*
*/!]  (uint8)GTM_ZERO_U,  /* Mcfg Configuration*/
[!ENDIF!]  [!"node:value(GtmGeneral/GtmSleepMode)"!],  /* Module Sleep Mode */
  [!"GtmGeneral/GtmGlobalClkDivNumerator"!]U,  /* Global Clock Configuration - Numerator */
  [!"GtmGeneral/GtmGlobalClkDivDenominator"!]U,/* Global Clock Configuration - Denominator */
[!IF "node:exists(GtmAccessEnable/*[1])"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*  
*/!][!VAR "LoopCount" = "num:i(0)"!][!/*  
*/!][!LOOP "(GtmAccessEnable/*[1]/GtmEnableAccForTagId/*)"!][!/*  
*/!][!IF "node:value(./GtmEnableAccessForTagId) = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, $LoopCount)"!][!/*
*/!][!ENDIF!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,  /* Access Enable 0 */
  0UL,  /* Access Enable 1 */
[!ELSE!][!/*
*/!]  0xFFFFFFFFU,  /* Access Enable 0 */
  0UL,  /* Access Enable 1 */
[!ENDIF!][!/*
*/!][!IF "(bit:or($TimModuleLookUp1, $TimModuleLookUp2) != 0) or (bit:or($TimModuleLookUp3, $TimModuleLookUp4) != 0) or (bit:or($TimModuleLookUp5, $TimModuleLookUp6) != 0)"!][!/*
*/!][!VAR "TimMergeLookUp1" = "bit:or($TimModuleLookUp1, bit:shl($TimModuleLookUp2, 16))"!][!/*
*/!][!VAR "TimMergeLookUp2" = "bit:or($TimModuleLookUp3, bit:shl($TimModuleLookUp4, 16))"!][!/*
*/!][!VAR "TimMergeLookUp3" = "bit:or($TimModuleLookUp5, bit:shl($TimModuleLookUp6, 16))"!][!//
  {  [!"num:inttohex($TimMergeLookUp1, 8)"!]U, 
     [!"num:inttohex($TimMergeLookUp2, 8)"!]U,
[!IF "$RelDerivate = 'TC29x'"!][!/*
*/!]     [!"num:inttohex($TimMergeLookUp3, 8)"!]U
    [!ENDIF!][!/*
*/!]  },    /* TIM Module Usage by GTM and ICU driver*/
  {  [!"num:inttohex($TimUsage0,8)"!]U,
[!IF "$RelDerivate = 'TC29x'"!][!/*
*/!]     [!"num:inttohex($TimUsage1, 8)"!]U
[!ENDIF!][!/*
*/!]  },  /* TIM Usage */
  &Gtm_kTimConfig[!"$ModuleId"!][0],  /* TIM Configuration Pointer */
[!ELSE!][!/*  
*/!]  {0U,0U},
  {0U},  /* TIM Usage */  
  NULL_PTR,  /* TIM Configuration Pointer */
[!ENDIF!][!/*
*/!][!IF "(bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0) or (bit:or($TomModuleLookUp3, $TomModuleLookUp4) != 0) or ($TomModuleLookUp5 != 0)"!][!/* If any TOM Channel is used
*/!]  {[!"num:inttohex($TomTGCUsage0,8)"!]U},  /* TOM TGC Usage */
  &Gtm_kTomTgcConfig[!"$ModuleId"!][0],  /* TOM TGC Configuration Pointer */
  {[!"num:inttohex($TomModuleLookUp1, 8)"!]U,
   [!"num:inttohex($TomModuleLookUp2,8)"!]U,[!/* 
   */!][!IF "$RelDerivate != 'TC26x'"!][!/*
   */!][!"num:inttohex($TomModuleLookUp3, 8)"!]U, [!/* 
   */!][!ENDIF!][!/* 
   */!][!IF "$RelDerivate = 'TC29x'"!][!/*
   */!][!"num:inttohex($TomModuleLookUp4, 8)"!]U, [!/* 
   */!][!"num:inttohex($TomModuleLookUp5, 8)"!]U [!/* 
   */!][!ENDIF!] 
   },
  {[!"num:inttohex($TomUsage0,8)"!]U,[!/* 
*/!][!IF "$RelDerivate != 'TC26x'"!]
   [!"num:inttohex($TomUsage1,8)"!]U,[!/* 
*/!][!ENDIF!]
[!IF "$RelDerivate = 'TC29x'"!]
   [!"num:inttohex($TomUsage2,8)"!]U[!/* 
*/!][!ENDIF!]
  },  /* TOM Usage */
  &Gtm_kTomConfig[!"$ModuleId"!][0],  /* TOM Configuration Pointer */
[!ELSE!][!/*
*/!]  {0U},  /* TOM TGC Usage */
  NULL_PTR,  /* TOM TGC Configuration Pointer */
  {[!/*
*/!][!VAR "TomCount" = "ecu:get('Gtm.NumberOfTomModules')"!][!/*
*/!][!VAR "TomChannelCount" = "ecu:get('Gtm.NumberOfTomChannels')"!][!/*
*/!][!VAR "TotalTomChannel" = "$TomCount * $TomChannelCount"!][!/*
*/!][!FOR "ModuleIndex" = "1" TO "(($TotalTomChannel - 1) div 16) + 1"!][!/*
*/!]  0U,[!/*
*/!][!ENDFOR!][!/*
*/!]},  
  {
[!FOR "ModuleIndex" = "1" TO "(($TotalTomChannel - 1) div 32) + 1"!][!/*
*/!]  0U,[!/*
*/!][!ENDFOR!][!/*
*/!]
  },  /* TOM Usage */
  NULL_PTR,  /* TOM Configuration Pointer */  
[!ENDIF!][!/*
*/!][!IF "(bit:or($AtomModuleLookUp1, $AtomModuleLookUp2) != 0) or (bit:or($AtomModuleLookUp3, $AtomModuleLookUp4) != 0) or ($AtomModuleLookUp5 != 0) or ($AtomModuleLookUp6 != 0) or ($AtomModuleLookUp7 != 0) or ($AtomModuleLookUp8 != 0) or ($AtomModuleLookUp9 != 0)"!][!/* If any ATOM Channel is used
*/!]  {[!"num:inttohex($AtomAGCUsage0,8)"!]U},  /* ATOM AGC Usage */
  &Gtm_kAtomAgcConfig[!"$ModuleId"!][0],  /* ATOM AGC Configuration Pointer */  
[!VAR "AtomMergeLookUp1" = "bit:or($AtomModuleLookUp1, bit:shl($AtomModuleLookUp2, 16))"!][!/*
*/!][!VAR "AtomMergeLookUp2" = "bit:or($AtomModuleLookUp3, bit:shl($AtomModuleLookUp4, 16))"!][!/*
*/!][!VAR "AtomMergeLookUp3" = "bit:or($AtomModuleLookUp5, bit:shl($AtomModuleLookUp6, 16))"!][!/*
*/!][!VAR "AtomMergeLookUp4" = "bit:or($AtomModuleLookUp7, bit:shl($AtomModuleLookUp8, 16))"!][!/*
*/!][!VAR "AtomMergeLookUp5" = "$AtomModuleLookUp9"!][!//
  { [!"num:inttohex($AtomMergeLookUp1, 8)"!]U, [!/*
*/!]
    [!"num:inttohex($AtomMergeLookUp2, 8)"!]U, [!/*
*/!][!IF "$RelDerivate != 'TC26x'"!][!/*
*/!]
    [!"num:inttohex($AtomMergeLookUp3, 8)"!]U,[!/*
*/!][!ENDIF!][!/*
*/!][!IF "$RelDerivate = 'TC29x'"!][!/*
*/!]
    [!"num:inttohex($AtomMergeLookUp4, 8)"!]U,[!/*
*/!]
    [!"num:inttohex($AtomMergeLookUp5, 8)"!]U[!/*
*/!][!ENDIF!]
  },
  {[!"num:inttohex($AtomUsage0,8)"!]U,
    [!IF "$RelDerivate != 'TC26x'"!]
    [!"num:inttohex($AtomUsage1,8)"!]U,
    [!ENDIF!]
    [!IF "$RelDerivate = 'TC29x'"!]
    [!"num:inttohex($AtomUsage2,8)"!]U
    [!ENDIF!]
    },  /* ATOM Usage */
  &Gtm_kAtomConfig[!"$ModuleId"!][0],  /* ATOM Configuration Pointer */   
[!ELSE!][!/*
*/!]  {0U},  /* ATOM AGC Usage */
  NULL_PTR,  /* ATOM AGC Configuration Pointer */
  {[!/*
*/!][!VAR "ATomCount" = "ecu:get('Gtm.NumberOfAtomModules')"!][!/*
*/!][!VAR "ATomChannelCount" = "ecu:get('Gtm.NumberOfAtomChannels')"!][!/*
*/!][!VAR "TotalATomChannel" = "$ATomCount * $ATomChannelCount"!][!/*
*/!][!FOR "ModuleIndex" = "1" TO "(($TotalATomChannel - 1) div 16) + 1"!][!/*
*/!]  0U,[!/*
*/!][!ENDFOR!][!/*
*/!]},  
  
  {
[!FOR "ModuleIndex" = "1" TO "(($TotalATomChannel - 1) div 32) + 1"!][!/*
*/!]  0U,[!/*
*/!][!ENDFOR!][!/*
*/!]  },  /* ATOM Usage */
  NULL_PTR,  /* ATOM Configuration Pointer */   
[!ENDIF!][!/*
*/!]    [!IF "$AtomUsage0 = num:i(1) or  $AtomUsage1 = num:i(1) or $AtomUsage2 = num:i(1) or $TomUsage0 = num:i(1) or $TomUsage1 = num:i(1) or $TomUsage2 = num:i(1) or $TimUsage0 = num:i(1) or $TimUsage1 = num:i(1)"!]
  
[!ENDIF!]

  &Gtm_kModUsage[!"$ModuleId"!], /* Configuration for GTM Usage by other modules */
  &Gtm_kGeneralConfig[!"$ModuleId"!],  /* GTM General Configuration */
[!IF "$TbuPresent = num:i(1)"!][!/*
*/!]  &Gtm_kTbuConfig[!"$ModuleId"!][0],  /* TBU Configuration Pointer */
[!ELSE!][!/*
*/!]  NULL_PTR,  /* TBU Configuration Pointer */
[!ENDIF!][!/*
*/!][!IF "node:exists(./Brc/*[1])"!][!/*
*/!]  &Gtm_kBrcConfig[!"$ModuleId"!],  /* BRC Configuration Pointer*/
[!ELSE!][!/*
*/!]  NULL_PTR,  /* BRC Configuration Pointer*/
[!ENDIF!][!/*
*/!][!IF "node:exists(./Fifo/*[1])"!][!/*
*/!]  &Gtm_kFifoConfig[!"$ModuleId"!][0],  /* Fifo Configuration Pointer*/
[!ELSE!][!/*
*/!]  NULL_PTR,  /* Fifo Configuration Pointer*/
[!ENDIF!][!/*
*/!][!IF "(node:exists(./F2a/*[1])) and ($F2aChannelUsed = num:i(1))"!][!/*
*/!]  &Gtm_kF2aConfig[!"$ModuleId"!][0],  /* F2a Configuration Pointer*/
[!ELSE!][!/*
*/!]  NULL_PTR,  /* F2a Configuration Pointer*/
[!ENDIF!][!/*
*/!][!IF "$McsConfigured = num:i(1)"!][!/*
*/!]  &Gtm_kMcsConfig[!"$ModuleId"!][0],  /* Mcs Configuration Pointer*/
[!ELSE!][!/*
*/!]  NULL_PTR,  /* Mcs Configuration Pointer*/
[!ENDIF!][!/*
*/!][!IF "node:exists(./Map/*[1])"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!IF "./Map/*[1]/MapTriggerSignal/MapTriggerSignalSelect = 'TSPP0_SUBUNIT_OUTPUT'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 0)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapTriggerSignal/MapEnableTspp0SubUnit = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 16)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapTriggerSignal/MapDisableTim0Ch0InputToTspp0 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 20)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapTriggerSignal/MapDisableTim0Ch1InputToTspp0 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 21)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapTriggerSignal/MapDisableTim0Ch2InputToTspp0 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 22)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapTriggerSignal/MapTspp0DirSignalLevelDefinition = 'INVERT_OF_SPE0_DIR'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 17)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapTriggerSignal/MapTim0Ch6InputLevelSel = 'TIM0_IN6_LEVEL1'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 4)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapStateSignal/MapTspp1DirSignalLevelDefinition = 'INVERT_OF_SPE1_DIR'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 25)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapStateSignal/MapStateSignalSelect = 'TSPP1_SUBUNIT_OUTPUT'"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl(5,1))"!][!/*
*/!][!ENDIF!][!/*  
*/!][!IF "./Map/*[1]/MapStateSignal/MapEnableTspp1SubUnit = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 24)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapStateSignal/MapDisableTim0Ch3InputToTspp1 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 28)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapStateSignal/MapDisableTim0Ch4InputToTspp1 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 29)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapStateSignal/MapDisableTim0Ch5InputToTspp1 = 'true'"!][!/*
*/!][!VAR "BuildReg" = "bit:bitset($BuildReg, 30)"!][!/*
*/!][!ENDIF!][!/*
*/!][!IF "./Map/*[1]/MapStateSignal/MapStateSignalSelect != 'TSPP1_SUBUNIT_OUTPUT'"!][!/*
*/!]  Gtm_MapBuildReg([!"num:inttohex($BuildReg,8)"!]U, [!"./Map/*[1]/MapStateSignal/MapStateSignalSelect"!]),  /* Map Configuration*/  
[!ELSE!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,  /* Map Configuration*/  
[!ENDIF!][!/*
*/!][!ELSE!][!/*
*/!]  GTM_SETUNUSED32,  /* Map Configuration*/
[!ENDIF!][!/*
*/!][!IF "node:exists(./Dpll/*[1])"!][!/*
*/!]  &Gtm_kDpllConfig[!"$ModuleId"!],  /* Dpll Configuration Pointer*/
[!ELSE!][!/*
*/!]  NULL_PTR,  /* Dpll Configuration Pointer*/
[!ENDIF!][!/*
*/!]  { /* Spe Configurations*/
[!VAR "SpeCount" = "num:i(0)"!][!/*
*/!][!LOOP "(Spe/*)"!][!/*
*/!][!IF "./SpeGeneral/SpeUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!]    &Gtm_kSpeConfig[!"$ModuleId"!][[!"$SpeCount"!]],  /* Spe Configuration Pointer*/
[!VAR "SpeCount" = "num:i($SpeCount + 1)"!][!/*
*/!][!ELSE!][!/*
*/!]    NULL_PTR,  /* Spe Configuration Pointer*/
[!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!]  },
[!IF "node:exists(./Cmp/*[1])"!][!/*
*/!]  &Gtm_kCmpConfig[!"$ModuleId"!],  /* Cmp Configuration Pointer*/
[!ELSE!][!/*
*/!]  NULL_PTR,  /* Cmp Configuration Pointer*/
[!ENDIF!][!/*
*/!][!IF "node:exists(./GtmConnections/*[1])"!][!/*
*/!][!IF "node:exists(./GtmConnections/*[1]/GtmConnectionToMsc/*[1])"!][!/*
*/!]  &Gtm_kMscConnections[!"$ModuleId"!],  /* Msc Configuration Pointer*/
[!ELSE!][!/*
*/!]  NULL_PTR,  /* Msc Connections Configuration Pointer*/
[!ENDIF!][!/*
*/!][!IF "node:exists(./GtmConnections/*[1]/GtmConnectionToDsadc/*[1])"!][!/*
*/!]  &Gtm_kDsadcConnections[!"$ModuleId"!],  /* Dsadc Connections Configuration Pointer*/
[!ELSE!][!/*
*/!]  NULL_PTR,  /* Dsadc Connections Configuration Pointer*/
[!ENDIF!][!/*
*/!]  &Gtm_kAdcConnections[!"$ModuleId"!][0],  /* Adc Connections Configuration Pointer*/
[!ELSE!][!/*
*/!]  NULL_PTR,  /* Msc Connections Configuration Pointer*/
  NULL_PTR,  /* Dsadc Connections Configuration Pointer*/
  NULL_PTR,  /* Adc Connections Configuration Pointer*/
[!ENDIF!][!/*
*/!]  {
[!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./GtmConnections/*[1]/GtmTtcanTrigger/*)"!][!/*
*/!][!VAR "TriggerNumber" = "text:split(./GtmTriggerSelect, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "TriggerNumber" = "text:split($TriggerNumber, 'EL')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($TriggerNumber, $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount +  4)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]    [!"num:inttohex($BuildReg,8)"!]U,  /* Ttcan Connections Configuration*/
  },
[!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./GtmConnections/*[1]/GtmPsi5Triggers/*[1]/GtmPsi5Trigger/*)"!][!/*
*/!][!VAR "TriggerNumber" = "text:split(./GtmPsi5Trigger, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "TriggerNumber" = "text:split($TriggerNumber, 'EL')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($TriggerNumber, $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount +  4)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U,  /* Psi5 Connections Configuration Pointer*/
[!VAR "LoopCount" = "num:i(0)"!][!/*
*/!][!VAR "BuildReg" = "num:i(0)"!][!/*
*/!][!LOOP "node:order(./GtmConnections/*[1]/GtmPsi5Triggers/*[1]/GtmPsi5STrigger/*)"!][!/*
*/!][!VAR "TriggerNumber" = "text:split(./GtmPsi5STrigger, '_')[position()-1 = 0]"!][!/*
*/!][!VAR "TriggerNumber" = "text:split($TriggerNumber, 'EL')[position()-1 = 1]"!][!/*
*/!][!VAR "BuildReg" = "bit:or($BuildReg, bit:shl($TriggerNumber, $LoopCount))"!][!/*
*/!][!VAR "LoopCount" = "num:i($LoopCount +  4)"!][!/*
*/!][!ENDLOOP!][!/*
*/!]  [!"num:inttohex($BuildReg,8)"!]U  /* Psi5S Connections Configuration Pointer*/
};
[!/*
*/!][!ENDSELECT!][!/* SELECT "GtmConfiguration/*[1] 
*/!][!IF "(bit:or($TomModuleLookUp1, $TomModuleLookUp2) != 0) or (bit:or($TomModuleLookUp3, $TomModuleLookUp4) != 0) or ($TomModuleLookUp5 != 0) or  (bit:or($AtomModuleLookUp1, $AtomModuleLookUp2) != 0) or (bit:or($AtomModuleLookUp3, $AtomModuleLookUp4) != 0) or (bit:or($AtomModuleLookUp5, $AtomModuleLookUp6) != 0) or (bit:or($AtomModuleLookUp7, $AtomModuleLookUp8) != 0) or ($AtomModuleLookUp9 != 0) or (bit:or($TimModuleLookUp1, $TimModuleLookUp2) != 0) or (bit:or($TimModuleLookUp3, $TimModuleLookUp4) != 0) or (bit:or($TimModuleLookUp5, $TimModuleLookUp6) != 0)"!][!/*
*/!][!VAR "PortConfigPresent" = "bit:bitset($PortConfigPresent, $ModuleId)"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDSELECT!][!// [!SELECT "node:ref($McuSelectIndex)"!]
[!ENDFOR!][!/* FOR "ModuleId" ="num:i(0)" TO "(num:i($TotalMcuConfig)-1)"
*/!][!/*
********************************************************************************
********************************************************************************
               Configuration for Config Root Structure
********************************************************************************
********************************************************************************
*/!][!/* 
*/!]const Gtm_ConfigType Gtm_ConfigRoot[]  =
{
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($McuSelect)/*))- 1)"!][!/*
*/!]  {
    /*  GTM Module Clock Settings  */
[!IF "bit:getbit($ClockConfigExist,$ModuleIndex) = num:i(1)"!][!/*
*/!]    &Gtm_kClockSetting[!"$ModuleIndex"!],
[!ELSE!][!/*
*/!]    NULL_PTR, 
[!ENDIF!][!/*
*/!]    /*  Pointer to Gtm Configuration structure  */
[!IF "bit:getbit($PortConfigPresent, $ModuleIndex) = 1"!][!/*
*/!]    &Gtm_kPortConfig[!"$ModuleIndex"!],
[!ELSE!][!/*
*/!]    NULL_PTR,
[!ENDIF!][!/*  
*/!]    &Gtm_kModuleConfig[!"$ModuleIndex"!],
  },
[!ENDFOR!][!/*
*/!]};
#define MCU_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"

[!ELSE!][!//
/*******************************************************************************
**                      GTM Not Configured                                    **
*******************************************************************************/
[!ENDIF!][!//  [!IF "$TotalGtmConfig > num:i(0)"!]
[!ENDSELECT!][!//[!SELECT "as:modconf('Mcu')[1]"!][!//

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

