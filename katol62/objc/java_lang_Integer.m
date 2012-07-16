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

#import "java_lang_Integer.h"
#import "java_lang_RuntimeException.h"
#import "java_lang_NumberFormatException.h"

@interface PrimitiveInt : java_lang_Object
@end

@implementation PrimitiveInt
@end

static PrimitiveInt* primitiveInt;
static java_lang_Class* primitiveIntClass;


// java.lang.Integer
//----------------------------------------------------------------------------
@implementation java_lang_Integer


static int MIN_VALUE = 0x80000000;
static int MAX_VALUE = 0x7fffffff;


+ (void) initialize
{
	primitiveInt = [[PrimitiveInt alloc] init];
	primitiveIntClass = [primitiveInt getClass__];
}

- (id) init
{
	[super init];
	number = 0;
	return self;
}

- (id) copyWithZone:(NSZone *)zone
{
    java_lang_Integer* other = [[[self class] allocWithZone:zone] init];
    other->number = self->number;
    return other;
}

- (NSUInteger) hash
{
	return number;
}

+ (java_lang_Class*) _GET_TYPE
{
	return primitiveIntClass;
}

- (void) __init_java_lang_Integer___int :(int) i
{
	number = i;
}

- (BOOL)isEqual:(id)anObject
{
	return [anObject isKindOfClass: [java_lang_Integer class]] && ((java_lang_Integer*) anObject)-> number == number;
}

- (BOOL)equals___java_lang_Object:(java_lang_Object*)anObject
{
	return [anObject isKindOfClass: [java_lang_Integer class]] && ((java_lang_Integer*) anObject)-> number == number;
}

- (int) intValue__
{
	return number;
}

+ (java_lang_Integer*) valueOf___java_lang_String: (java_lang_String*) str
{
  return [java_lang_Integer valueOf___int: [self parseInteger___java_lang_String: str]];
}

+ (int) parseInt___java_lang_String: (java_lang_String *) str
{
	int result = 0;
	if (str == JAVA_NULL || [str length__] == 0) {
		java_lang_NumberFormatException* ex = [[java_lang_NumberFormatException alloc] init];
		[ex __init_java_lang_NumberFormatException__];
		@throw ex;
	} else {
		result = atoi([str UTF8String]);
		// If the result was 0, there was probably an error
		// Every character before a decimal point should be '0' ('-' excluded) or we throw an exception
		if (result == 0) {
			BOOL ok = TRUE;
			int i = 0;
			if ([str charAt___int:0] == '-') {
				if ([str length__] == 1) {
					ok = FALSE;
				} else {
					i++;
				}
			}
			while (ok && i < [str length__]) {
				char c = [str charAt___int:i++];
				if (c != '0') {
					ok = FALSE;
				}
			}
			if (!ok) {
				java_lang_NumberFormatException* ex = [[java_lang_NumberFormatException alloc] init];
				[ex __init_java_lang_NumberFormatException__];
				@throw ex;
			}
		}
// TODO throw a NumberFormatException for e.g. values "1.0" and "-1.01" instead of returning 1 and -1 respectively
	}
	return result;
}


- (java_lang_String*) toString__
{
	return [java_lang_Integer toString___int:number];
}

+ (java_lang_String*) toString___int: (int) i
{
	return [[[NSNumber numberWithInt: i] stringValue] retain];
}

+ (java_lang_Integer*) valueOf___int: (int) i
{
	java_lang_Integer* o = [[java_lang_Integer alloc] init];
	[o __init_java_lang_Integer___int:i];
	return o;
}

static BOOL instanceof(id obj, const char *className) {
	return obj != JAVA_NULL &&
		([obj isKindOfClass: objc_getClass(className)] ||
			[obj conformsToProtocol: objc_getProtocol(className)]);	
}

//Signature from java_lang_Comparable
- (int) compareTo___java_lang_Object: (java_lang_Object*) obj {
	if (!instanceof(obj, "java_lang_Integer")) {
//TODO throw a java_lang_ClassCastException (doesn't exist yet) instead of a java_lang_RuntimeException
		java_lang_RuntimeException* ex = [[java_lang_RuntimeException alloc] init];
		[ex __init_java_lang_RuntimeException___java_lang_String:[NSMutableString stringWithString:@"ClassCastException"]];
		@throw ex;
	}
	return [self compareTo___java_lang_Integer:(java_lang_Integer*)obj];
}

- (int) compareTo___java_lang_Integer: (java_lang_Integer*) i {
	long thisVal = [self intValue__];
	long anotherVal = [i intValue__];
	return (thisVal < anotherVal ? -1 : (thisVal == anotherVal ? 0 : 1));
}

+ (int) parseInt___java_lang_String_int:(java_lang_String *)str:(int)ii
{

    NSString *s = (NSString*)str;
    int radix = ii;
    
    if (s == nil) {
        java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
        [ex __init_java_lang_NumberFormatException___java_lang_String:(java_lang_String*)@"null"];
        @throw ex;
    }
    
    if (radix < [java_lang_Character _GET_MIN_RADIX]) {
        java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
        [ex __init_java_lang_NumberFormatException___java_lang_String:(java_lang_String*)[NSString stringWithFormat:@"radix %d less than Character.MIN_RADIX"]];
        @throw ex;
    }
    
    if (radix > [java_lang_Character _GET_MAX_RADIX]) {
        java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
        [ex __init_java_lang_NumberFormatException___java_lang_String:(java_lang_String*)[NSString stringWithFormat:@"radix %d greater than Character.MAX_RADIX"]];
        @throw ex;
    }
    
    int result = 0;
    BOOL negative = false;
    int i = 0;
    int len = [s length];
    int limit = -MAX_VALUE;
    int multmin;
    int digit;
    
    if (len > 0) {
        int firstChar = [s characterAtIndex:0];
        if (firstChar < '0') { // Possible leading "-"
            if (firstChar == '-') {
                negative = true;
                limit = MIN_VALUE;
            } 
            else
            {
                java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
                [ex __init_java_lang_NumberFormatException___java_lang_String:(java_lang_String*)s];
                @throw ex;
            }
            
            if (len == 1) // Cannot have lone "-"
            {
                java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
                [ex __init_java_lang_NumberFormatException___java_lang_String:(java_lang_String*)s];
                @throw ex;
            }
            i++;
        }
        multmin = limit / radix;
        while (i < len) {
            // Accumulating negatively avoids surprises near MAX_VALUE
            digit = [java_lang_Character digit___char_int:[s characterAtIndex:i++] :radix];//Character.digit(s.charAt(i++),radix);
            if (digit < 0) {
                java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
                [ex __init_java_lang_NumberFormatException___java_lang_String:(java_lang_String*)s];
                @throw ex;
            }
            if (result < multmin) {
                java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
                [ex __init_java_lang_NumberFormatException___java_lang_String:(java_lang_String*)s];
                @throw ex;
            }
            result *= radix;
            if (result < limit + digit) {
                java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
                [ex __init_java_lang_NumberFormatException___java_lang_String:(java_lang_String*)s];
                @throw ex;
            }
            result -= digit;
        }
    } else {
        java_lang_NumberFormatException *ex = [[[java_lang_NumberFormatException alloc] init] autorelease];
        [ex __init_java_lang_NumberFormatException___java_lang_String:(java_lang_String*)s];
        @throw ex;
    }
    
    
    return negative ? result : -result;
    
//    return (int)[(NSString*)str integerValue];
}

@end
