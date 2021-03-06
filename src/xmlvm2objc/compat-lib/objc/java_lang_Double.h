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

#import "xmlvm.h"
#import "java_lang_Number.h"
#import "java_lang_String.h"
#import "java_lang_NumberFormatException.h"
#import "sun_misc_DoubleConsts.h"
#import "sun_misc_FpUtils.h"
#import "java_lang_Long.h"


// java.lang.Double
//----------------------------------------------------------------------------
@interface java_lang_Double : java_lang_Number <NSCopying> {

double number;

}

+ (void) initialize;
- (id) init;
- (id) copyWithZone:(NSZone *)zone;
- (NSUInteger) hash;
+ (java_lang_Class*) _GET_TYPE;
- (void) __init_java_lang_Double___double :(double) d;
- (BOOL)isEqual:(id)anObject;
- (double) doubleValue__;
- (java_lang_String*) toString__;
+ (double) parseDouble___java_lang_String: (java_lang_String *) str;
+ (java_lang_String*) toString___double: (double) d;
+ (java_lang_Double*) valueOf___double: (double) d;
+ (java_lang_Double*) valueOf___java_lang_String: (java_lang_String*) str;

+ (double) longBitsToDouble___long:(long long)d;
+(int)isNaN___double:(double)d;
+ (long long) doubleToLongBits___double:(double)d;
+ (int) isInfinite___double:(double)d;
+ (long long) doubleToRawLongBits___double:(double)d;


@end
