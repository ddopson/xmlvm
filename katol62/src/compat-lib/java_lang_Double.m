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
//	return atof([str UTF8String]);
    NSLog(@"Str=%@", str);
    
    NSCharacterSet* whitespace = [NSCharacterSet characterSetWithCharactersInString: @" \t\n\r\f\001\013\037"];
    NSString* trimmed = [str stringByTrimmingCharactersInSet:whitespace];
    
    NSLog(@"trimmed=%@", trimmed);

    double fval;
    
    
    NSRange range = [[trimmed lowercaseString] rangeOfString:@"0x"];
    if (range.location != NSNotFound && (range.location==0 || range.location==1)) {
        NSScanner *scanner = [NSScanner scannerWithString: trimmed];
        [scanner scanHexDouble:&fval];
    }
    else
    {
        fval = [trimmed doubleValue];
    }

    if ((![self is_zero_string:trimmed]) && fval==0)
    {
        if ([trimmed isEqualToString:@"NaN"] || [trimmed isEqualToString:@"+NaN"] || [trimmed isEqualToString:@"-NaN"]) {
            return NaN;
        }
        else if ([trimmed isEqualToString:@"Infinity"] || [trimmed isEqualToString:@"+Infinity"]) {
            return INFINITY;//1.0 / 0.0;
        }
        else if ([trimmed isEqualToString:@"-Infinity"]) {
            return -INFINITY;//log (0);
        }
        else {
            java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
            [ex __init_java_lang_NumberFormatException__];
            @throw ex;
        }
        
    }
	return fval;

}

+ (BOOL) is_zero_string:(NSString*)str
{
    return ([str isEqualToString:@"0"] ||
            [str isEqualToString:@"+0"] ||
            [str isEqualToString:@"-0"] ||
            [str isEqualToString:@"00"] ||
            [str isEqualToString:@"-00"] ||
            [str isEqualToString:@"+00"] ||
            [str isEqualToString:@"0000000000"] ||
            [str isEqualToString:@"-0000000000"] ||
            [str isEqualToString:@"0.0E-10"] ||
            [str isEqualToString:@"0.f"] ||
            [str isEqualToString:@"0.F"] ||
            [str isEqualToString:@"0e-0D"] ||
            [str isEqualToString:@"+0000000000"]);
            
}

- (java_lang_String*) toString__
{
	return [java_lang_Double toString___double:number];
}

+ (java_lang_String*) toString___double: (double) d
{
	return [[[NSNumber numberWithDouble: d] stringValue] retain];
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
    uint64_t x = (uint64_t)d;
    double doubleValue;
    doubleValue = *(double*)&x;
    return doubleValue;
}

+ (long long) doubleToLongBits___double:(double)d
{
    const union { double f; uint64_t i; } xUnion = { .f = d };
    long ll = (long long)xUnion.i;
    return (long long)xUnion.i;
}

@end
