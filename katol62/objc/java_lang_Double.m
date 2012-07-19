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

#import "java_lang_Double.h"

@interface PrimitiveDouble : java_lang_Object
@end

@implementation PrimitiveDouble
@end

static PrimitiveDouble* primitiveDouble;
static java_lang_Class* primitiveDoubleClass;


// java.lang.Double
//----------------------------------------------------------------------------
@implementation java_lang_Double

+ (void) initialize
{
	primitiveDouble = [[PrimitiveDouble alloc] init];
	primitiveDoubleClass = [primitiveDouble getClass__];
}

- (id) init
{
	[super init];
	number = 0;
	return self;
}

- (id) copyWithZone:(NSZone *)zone
{
    java_lang_Double* other = [[[self class] allocWithZone:zone] init];
    other->number = self->number;
    return other;
}

- (NSUInteger) hash
{
	return number;
}

+ (java_lang_Class*) _GET_TYPE
{
	return primitiveDoubleClass;
}

- (void) __init_java_lang_Double___double :(double) d
{
	number = d;
}

- (BOOL)isEqual:(id)anObject
{
	return [anObject isKindOfClass: [java_lang_Double class]] && ((java_lang_Double*) anObject)-> number == number;
}

- (double) doubleValue__
{
	return number;
}

+ (java_lang_Double*) valueOf___java_lang_String: (java_lang_String*) str
{
  return [java_lang_Double valueOf___double: [self parseDouble___java_lang_String: str]];
}

+ (double) parseDouble___java_lang_String: (java_lang_String *) str
{
    
    NSAutoreleasePool *loopPool = [[NSAutoreleasePool alloc] init];
    
    NSCharacterSet* whitespace = [NSCharacterSet characterSetWithCharactersInString: @" \t\n\r\f\001\013\037"];
    NSString* trimmed = [str stringByTrimmingCharactersInSet:whitespace];
    
    NSMutableString *tmp = [[NSMutableString stringWithString:trimmed] autorelease];
    NSRange foundRange = [tmp rangeOfString:@"+0x"];
    if (foundRange.location != NSNotFound)
    {
        [tmp replaceCharactersInRange:foundRange withString:@"0x"];
        trimmed = [NSString stringWithString:tmp];
    }
    
//    NSLog(@"trimmed=%@", trimmed);

    if([trimmed isEqualToString:@"0x1.000000000000001p-1075"])
    {
        NSLog(@"stop");
    }
    
    double fval;
    BOOL b;
    
    const char *c = [trimmed cStringUsingEncoding:NSNonLossyASCIIStringEncoding];
    
    NSRange range = [[trimmed lowercaseString] rangeOfString:@"0x"];
    NSRange range_dec = [[trimmed lowercaseString] rangeOfString:@"."];
    NSScanner *scanner = [NSScanner scannerWithString: trimmed];
    if (range.location != NSNotFound && (range.location==0 || range.location==1)) {
        b = [scanner scanHexDouble:&fval];
        if (range_dec.location != NSNotFound && range_dec.location>1) 
        {
            fval = strtod (c, NULL);
        }
    } else {
        NSScanner *scanner = [NSScanner scannerWithString: trimmed];
        b = [scanner scanDouble:&fval];
        fval = [trimmed doubleValue];
    }
    
    if (b==NO && fval==0)
    {
        if ([trimmed isEqualToString:@"NaN"] || [trimmed isEqualToString:@"+NaN"] || [trimmed isEqualToString:@"-NaN"]) {
            return NaN;
        }
        else if ([trimmed isEqualToString:@"Infinity"] || [trimmed isEqualToString:@"+Infinity"]) {
            return INFINITY;
        }
        else if ([trimmed isEqualToString:@"-Infinity"]) {
            return -INFINITY;
        }
        else {
            java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
            [ex __init_java_lang_NumberFormatException__];
            @throw ex;
        }
        
    }
	return fval;
    [loopPool drain];

}

- (java_lang_String*) toString__
{
	return [java_lang_Double toString___double:number];
}

+ (java_lang_String*) toHexString___double:(double)d
{
    NSAutoreleasePool *loopPool = [[NSAutoreleasePool alloc] init];
    NSString *ret = [NSString string];
    
    NSString *s = [[[NSNumber numberWithDouble:d] stringValue] autorelease];

    if (d==INFINITY) {
        ret = [NSString stringWithString:@"Infinity"];
    }
    else if (d==-INFINITY) {
        ret = [NSString stringWithString:@"-Infinity"];
    }
    else if ([self isNaN___double:d]) {
        ret = [NSString stringWithString:@"NaN"];
    }
    else {
        
        NSString *start = [[NSString stringWithFormat:@"%@", [[NSNumber numberWithDouble:d] stringValue]] substringWithRange:NSMakeRange(0,1)]; 
        
        if ([start isEqualToString:@"-"]) {
            ret = [ret stringByAppendingString:@"-"];
        }
        
        ret = [ret stringByAppendingString:@"0x"];
        
        d = fabs(d);
        if (d==0) {
            ret = [ret stringByAppendingString:@"0.0p0"];
        }
        else {
            BOOL subnormal = d < [sun_misc_DoubleConsts _GET_MIN_NORMAL];// 2.2250738585072014E-308;
            
            unsigned long long l1 = [self doubleToLongBits___double:d];
            
            unsigned long long l2 = l1 & (unsigned long long)[sun_misc_DoubleConsts _GET_SIGNIF_BIT_MASK];
            unsigned long long ll = l2 | (unsigned long long)0x1000000000000000L;
            
            ret = [ret stringByAppendingString:(subnormal ? @"0." : @"1.")];
            
            NSString *temp = [java_lang_Long toHexString___long:ll];
            
            NSString *signif = [temp substringWithRange:NSMakeRange(3, 13)];
            NSString *add = [NSString string];
            if ([signif isEqualToString:@"0000000000000"])
            {
                add = [add stringByAppendingString:@"0"];
            }
            else {
                
                add = (NSString *)[(java_lang_String *)signif replaceFirst___java_lang_String_java_lang_String:(java_lang_String*)@"0{1,12}$":(java_lang_String*)@""];
                
            }

            ret = [ret stringByAppendingString:add];
            int addd = subnormal ? [sun_misc_DoubleConsts _GET_MIN_EXPONENT] : [sun_misc_FpUtils getExponent___double:d];
            NSString *str = [[NSNumber numberWithInt:addd] stringValue];
            NSString *str1 = [NSString stringWithFormat:@"%d", addd];
            ret = [ret stringByAppendingFormat:@"p%d", addd];
            
        }
        
    }
    return (java_lang_String*)ret;
    [loopPool drain];
}

+ (java_lang_String*) toString___double: (double) d
{
	return (java_lang_String*)[[[NSNumber numberWithDouble: d] stringValue] retain];
}

+ (java_lang_Double*) valueOf___double: (double) d
{
	java_lang_Double* o = [[java_lang_Double alloc] init];
	[o __init_java_lang_Double___double:d];
	return o;
}

+(int)isNaN___double:(double)d
{
    return isnan(d);
}

+ (int) isInfinite___double:(double)d
{
    return isinf(d);
}

+ (double) longBitsToDouble___long:(long long)d
{
//    double doubleValue = *(double*)&d;
    return *(double*)&d;
}

+ (long long) doubleToLongBits___double:(double)d
{
    long long llValue = *((long long*)(&d));
    
    const union { double f; uint64_t i; } xUnion = { .f = d };
    
    if (((llValue & [sun_misc_DoubleConsts _GET_EXP_BIT_MASK])==[sun_misc_DoubleConsts _GET_EXP_BIT_MASK]) && (llValue & [sun_misc_DoubleConsts _GET_SIGNIF_BIT_MASK])!=0L) {
        return 9221120237041090560;
    }
    return llValue;
}

+ (long long) doubleToRawLongBits___double:(double)d
{
    long long llValue = *((long long*)(&d));
    return llValue;//*((long long*)(&d));
}

+ (int) compare___double_double:(double)d1:(double)d2
{
//    if (d1 < d2)
//        return -1;           // Neither val is NaN, thisVal is smaller
//    if (d1 > d2)
//        return 1;            // Neither val is NaN, thisVal is larger
    
    // Cannot use doubleToRawLongBits because of possibility of NaNs.
    long long thisBits    = [self doubleToLongBits___double:d1];
    long long anotherBits = [self doubleToLongBits___double:d2];
    
    return (thisBits == anotherBits ?  0 : // Values are equal
            (thisBits < anotherBits ? -1 : // (-0.0, 0.0) or (!NaN, NaN)
             1));                          //
    
    /*
    NSLog(@"diff=%f", fabsf(d1 - d2));
    
    if(fabsf(d1 - d2) < 0.000001)
        return 1;
    else
        return 0;
     */
}

@end
