//
//  java_math_BigDecimal.m
//  HelloResources
//
//  Created by apple on 08.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "java_math_BigDecimal.h"
#import "java_lang_Double.h"

@implementation java_math_BigDecimal

NSDecimalNumber* decNumber;

+ (void) initialize
{
}

- (id) init
{
    if (self==[super init]) {
    }
	return self;
}

- (void) __init_java_math_BigDecimal___double:(JAVA_DOUBLE)d
{
    NSString *value = [[NSNumber numberWithDouble:d] stringValue];
    NSDecimalNumber *ret = [NSDecimalNumber decimalNumberWithString:value];
    decNumber = ret;
}

+ (java_math_BigDecimal*) valueOf___long: (JAVA_LONG) l
{
    NSString *value = [[NSNumber numberWithLong:l] stringValue];
    NSDecimalNumber *ret = [NSDecimalNumber decimalNumberWithString:value];
    decNumber = ret;
    return (java_math_BigDecimal*)ret;
}

-(java_math_BigDecimal*)divide___java_math_BigDecimal:(java_math_BigDecimal*)d
{
    NSDecimalNumber *ret = [decNumber decimalNumberByDividingBy:(NSDecimalNumber*)d];
    return (java_math_BigDecimal*)ret;
}

-(java_math_BigDecimal*)subtract___java_math_BigDecimal:(java_math_BigDecimal*)d
{
    NSDecimalNumber *ret = [decNumber decimalNumberBySubtracting:(NSDecimalNumber*)d];
    return (java_math_BigDecimal*)ret;
}

-(java_math_BigDecimal*)add___java_math_BigDecimal:(java_math_BigDecimal*)d
{
    NSDecimalNumber *ret = [decNumber decimalNumberByAdding:(NSDecimalNumber*)d];
    return (java_math_BigDecimal*)ret;
}

@end
