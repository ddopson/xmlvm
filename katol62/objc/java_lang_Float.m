/* Copyright (c) 2002-2011 by XMLVM.org
 *
 * Project Info:  http://www.xmlvm.org
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

#import "java_lang_Float.h"

//static float NaN = sqrt (-1);

@interface PrimitiveFloat : java_lang_Object
@end

@implementation PrimitiveFloat
@end

static PrimitiveFloat* primitiveFloat;
static java_lang_Class* primitiveFloatClass;

// java.lang.Float
//----------------------------------------------------------------------------
@implementation java_lang_Float

+ (void) initialize
{
  primitiveFloat = [[PrimitiveFloat alloc] init];
  primitiveFloatClass = [primitiveFloat getClass__];
}

- (id) init
{
	[super init];
	number = 0.0f;
	return self;
}

- (id) copyWithZone:(NSZone *)zone
{
    java_lang_Float* other = [[[self class] allocWithZone:zone] init];
    other->number = self->number;
    return other;
}

- (NSUInteger) hash
{
	return number;
}

- (void) __init_java_lang_Float___float :(float) f
{
	number = f;
}

- (BOOL)isEqual:(id)anObject
{
	return [anObject isKindOfClass: [java_lang_Float class]] && ((java_lang_Float*) anObject)-> number == number;
}

- (java_lang_String*) toString__
{
	return [java_lang_Float toString___float:number];
}

+ (java_lang_String*) toString___float: (float) f
{
	return (java_lang_String*)[[[NSNumber numberWithFloat: f] stringValue] retain];
}

- (float) floatValue__
{
	return number;
}

+ (float) parseFloat___java_lang_String: (java_lang_String *) str
{
//	return strtof([str UTF8String], NULL);
//    NSLog(@"str = %@", (NSString *)str);
    NSCharacterSet* whitespace = [NSCharacterSet characterSetWithCharactersInString: @" \t\n\r\f\001\013\037"];
    NSString* trimmed = [str stringByTrimmingCharactersInSet:whitespace];

//    NSLog(@"!str = %@", (NSString *)trimmed);

    float fval;
    BOOL b;
    
    NSRange range = [[trimmed lowercaseString] rangeOfString:@"0x"];
    if (range.location != NSNotFound && (range.location==0 || range.location==1)) {
        NSScanner *scanner = [NSScanner scannerWithString: trimmed];
        b = [scanner scanHexFloat:&fval];
    }
    else
    {
        NSScanner *scanner = [NSScanner scannerWithString: trimmed];
        b = [scanner scanFloat:&fval];
        fval = [trimmed floatValue];
    }

//    float fval = [trimmed floatValue];
    if (b==NO && fval==0)
    {
        if ([trimmed isEqualToString:@"NaN"] || [trimmed isEqualToString:@"+NaN"] || [trimmed isEqualToString:@"-NaN"]) {
            return NaN;
        }
        else if ([trimmed isEqualToString:@"Infinity"] || [trimmed isEqualToString:@"+Infinity"]) {
            return Infinity;//1.0 / 0.0;
        }
        else if ([trimmed isEqualToString:@"-Infinity"]) {
            return -Infinity;//log (0);
        }
        else {
            java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
            [ex __init_java_lang_NumberFormatException__];
            @throw ex;
//            return NAN;// trimmedtof([trimmed UTF8String], NULL);
        }
        
    }
	return fval;
}

+ (java_lang_Class*) _GET_TYPE
{
	return primitiveFloatClass;
}

+ (java_lang_Float*) valueOf___java_lang_String: (java_lang_String*) str
{
  return [java_lang_Float valueOf___float: [self parseFloat___java_lang_String: str]];
}

+ (java_lang_Float*) valueOf___float:(float) value {
    java_lang_Float * f = [[java_lang_Float alloc] init];
    f->number = value;
    return f;
}

+(java_lang_String*)toHexString___float:(double)f
{
    NSString *s;
    if (fabsf(f) < [sun_misc_FloatConsts _GET_MIN_NORMAL] &&  f != 0.0f ) 
    {
        
        int dif = [sun_misc_DoubleConsts _GET_MIN_EXPONENT] - [sun_misc_FloatConsts _GET_MIN_EXPONENT]; 
        double d = (double)[sun_misc_FpUtils scalb___float_int:f:dif];
            
        s = [java_lang_Double toHexString___double:d];
            
        NSString *regexToReplace = @"p-1022$";   
            
        NSError *error = NULL;
        NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:regexToReplace
                                                    options:NSRegularExpressionCaseInsensitive
                                                    error:&error];
            
        s = [regex stringByReplacingMatchesInString:s
                                    options:0
                                    range:NSMakeRange(0, [s length])
                                    withTemplate:@""];
        return (java_lang_String*)s;
            
    }
    else // double string will be the same as float string
    {
        s = [java_lang_Double toHexString___double:f];
    }
    
    return (java_lang_String*)s;

}

+ (JAVA_INT) floatToIntBits___float: (float) f
{
    return (JAVA_INT)*(int *)(long *)&f;
}

+ (float) intBitsToFloat___int: (int) i
{
	return *(float *)(int *)&i;
}

+ (int) isNaN___float: (float) i
{
    return isnan(i);
}

+ (int) isInfinite___float : (float) i
{
    return isinf(i);
}

@end
