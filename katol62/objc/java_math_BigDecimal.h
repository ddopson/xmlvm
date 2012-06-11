//
//  java_math_BigDecimal.h
//  HelloResources
//
//  Created by apple on 08.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "java_lang_Number.h"
#import "java_lang_NumberFormatException.h"

@interface java_math_BigDecimal : java_lang_Number
{
    java_math_BigDecimal *intVal;
    int _precision;
    long long _intCompact;
}

- (void) __init_java_math_BigDecimal___double:(JAVA_DOUBLE)d;
+ (java_math_BigDecimal*) valueOf___long: (JAVA_LONG) l;
-(java_math_BigDecimal*)divide___java_math_BigDecimal:(java_math_BigDecimal*)d;
-(java_math_BigDecimal*)subtract___java_math_BigDecimal:(java_math_BigDecimal*)d;
-(java_math_BigDecimal*)add___java_math_BigDecimal:(java_math_BigDecimal*)d;

@end
