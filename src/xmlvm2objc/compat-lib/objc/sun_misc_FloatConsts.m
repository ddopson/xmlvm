
// Automatically generated by xmlvm2obj. Do not edit!


#import "sun_misc_FloatConsts.h"
#import "org_xmlvm_iphone_NSObject.h"

float _STATIC_sun_misc_FloatConsts_POSITIVE_INFINITY = Infinity;
float _STATIC_sun_misc_FloatConsts_NEGATIVE_INFINITY = -Infinity;
float _STATIC_sun_misc_FloatConsts_NaN = NaN;
float _STATIC_sun_misc_FloatConsts_MAX_VALUE = 3.4028235E38;
float _STATIC_sun_misc_FloatConsts_MIN_VALUE = 1.4E-45;
float _STATIC_sun_misc_FloatConsts_MIN_NORMAL = 1.17549435E-38;
int _STATIC_sun_misc_FloatConsts_SIGNIFICAND_WIDTH = 24;
int _STATIC_sun_misc_FloatConsts_MAX_EXPONENT = 127;
int _STATIC_sun_misc_FloatConsts_MIN_EXPONENT = -126;
int _STATIC_sun_misc_FloatConsts_MIN_SUB_EXPONENT = -149;
int _STATIC_sun_misc_FloatConsts_EXP_BIAS = 127;
int _STATIC_sun_misc_FloatConsts_SIGN_BIT_MASK = -2147483648;
int _STATIC_sun_misc_FloatConsts_EXP_BIT_MASK = 2139095040;
int _STATIC_sun_misc_FloatConsts_SIGNIF_BIT_MASK = 8388607;

@implementation sun_misc_FloatConsts;

+ (void) initialize
{
    if (strcmp(class_getName(self), "sun_misc_FloatConsts") == 0) {
        [sun_misc_FloatConsts __clinit_sun_misc_FloatConsts];
    }
}

- (id) init
{
    if (self = [super init]) {
    }
    return self;
}

- (void) dealloc
{
    if (strcmp(object_getClassName(self), "sun_misc_FloatConsts") == 0) {
        [self dealloc__];
    }
    [super dealloc];
}

+ (float) _GET_POSITIVE_INFINITY
{
    return _STATIC_sun_misc_FloatConsts_POSITIVE_INFINITY;
}

+ (void) _PUT_POSITIVE_INFINITY: (float) v
{
    _STATIC_sun_misc_FloatConsts_POSITIVE_INFINITY = v;
}

+ (float) _GET_NEGATIVE_INFINITY
{
    return _STATIC_sun_misc_FloatConsts_NEGATIVE_INFINITY;
}

+ (void) _PUT_NEGATIVE_INFINITY: (float) v
{
    _STATIC_sun_misc_FloatConsts_NEGATIVE_INFINITY = v;
}

+ (float) _GET_NaN
{
    return _STATIC_sun_misc_FloatConsts_NaN;
}

+ (void) _PUT_NaN: (float) v
{
    _STATIC_sun_misc_FloatConsts_NaN = v;
}

+ (float) _GET_MAX_VALUE
{
    return _STATIC_sun_misc_FloatConsts_MAX_VALUE;
}

+ (void) _PUT_MAX_VALUE: (float) v
{
    _STATIC_sun_misc_FloatConsts_MAX_VALUE = v;
}

+ (float) _GET_MIN_VALUE
{
    return _STATIC_sun_misc_FloatConsts_MIN_VALUE;
}

+ (void) _PUT_MIN_VALUE: (float) v
{
    _STATIC_sun_misc_FloatConsts_MIN_VALUE = v;
}

+ (float) _GET_MIN_NORMAL
{
    return _STATIC_sun_misc_FloatConsts_MIN_NORMAL;
}

+ (void) _PUT_MIN_NORMAL: (float) v
{
    _STATIC_sun_misc_FloatConsts_MIN_NORMAL = v;
}

+ (int) _GET_SIGNIFICAND_WIDTH
{
    return _STATIC_sun_misc_FloatConsts_SIGNIFICAND_WIDTH;
}

+ (void) _PUT_SIGNIFICAND_WIDTH: (int) v
{
    _STATIC_sun_misc_FloatConsts_SIGNIFICAND_WIDTH = v;
}

+ (int) _GET_MAX_EXPONENT
{
    return _STATIC_sun_misc_FloatConsts_MAX_EXPONENT;
}

+ (void) _PUT_MAX_EXPONENT: (int) v
{
    _STATIC_sun_misc_FloatConsts_MAX_EXPONENT = v;
}

+ (int) _GET_MIN_EXPONENT
{
    return _STATIC_sun_misc_FloatConsts_MIN_EXPONENT;
}

+ (void) _PUT_MIN_EXPONENT: (int) v
{
    _STATIC_sun_misc_FloatConsts_MIN_EXPONENT = v;
}

+ (int) _GET_MIN_SUB_EXPONENT
{
    return _STATIC_sun_misc_FloatConsts_MIN_SUB_EXPONENT;
}

+ (void) _PUT_MIN_SUB_EXPONENT: (int) v
{
    _STATIC_sun_misc_FloatConsts_MIN_SUB_EXPONENT = v;
}

+ (int) _GET_EXP_BIAS
{
    return _STATIC_sun_misc_FloatConsts_EXP_BIAS;
}

+ (void) _PUT_EXP_BIAS: (int) v
{
    _STATIC_sun_misc_FloatConsts_EXP_BIAS = v;
}

+ (int) _GET_SIGN_BIT_MASK
{
    return _STATIC_sun_misc_FloatConsts_SIGN_BIT_MASK;
}

+ (void) _PUT_SIGN_BIT_MASK: (int) v
{
    _STATIC_sun_misc_FloatConsts_SIGN_BIT_MASK = v;
}

+ (int) _GET_EXP_BIT_MASK
{
    return _STATIC_sun_misc_FloatConsts_EXP_BIT_MASK;
}

+ (void) _PUT_EXP_BIT_MASK: (int) v
{
    _STATIC_sun_misc_FloatConsts_EXP_BIT_MASK = v;
}

+ (int) _GET_SIGNIF_BIT_MASK
{
    return _STATIC_sun_misc_FloatConsts_SIGNIF_BIT_MASK;
}

+ (void) _PUT_SIGNIF_BIT_MASK: (int) v
{
    _STATIC_sun_misc_FloatConsts_SIGNIF_BIT_MASK = v;
}

- (void) __init_sun_misc_FloatConsts__
{
    XMLVMElem _r0;
    _r0.o = self;
    [_r0.o retain];
    [((java_lang_Object*) _r0.o) __init_java_lang_Object__];
    [_r0.o release];
    return;
}
+ (void) __clinit_sun_misc_FloatConsts
{
    return;
}

@end

