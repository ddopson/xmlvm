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

#import "java_lang_Character.h"

@interface PrimitiveCharacter : java_lang_Object
@end

@implementation PrimitiveCharacter
@end

static PrimitiveCharacter* primitiveCharacter;
static java_lang_Class* primitiveCharacterClass;


// java.lang.Character
//----------------------------------------------------------------------------

static int MIN_RADIX = 2;
static int MAX_RADIX = 36;

@implementation java_lang_Character

- (void) __init_java_lang_Character___char :(JAVA_CHAR) charParm {
	self->c = charParm;
}

- (JAVA_CHAR) charValue__ {
	return self->c;
}

+ (void) initialize
{
	primitiveCharacter = [[PrimitiveCharacter alloc] init];
	primitiveCharacterClass = [primitiveCharacter getClass__];
}

+ (java_lang_Class*) _GET_TYPE
{
	return primitiveCharacterClass;
}

+ (java_lang_String*) toString___char: (JAVA_CHAR) c
{
	NSString* s = [NSString stringWithFormat:@"%C", c];
	return [s retain];
}

+ (java_lang_Character*) valueOf___char: (JAVA_CHAR) c {
	java_lang_Character* result = [[java_lang_Character alloc] init];
	[result __init_java_lang_Character___char:c];
	return result;	
}

+ (int) digit___char_int:(int)chr:(int)radix
{
    int value = -1;
    if (radix >= MIN_RADIX && radix <= MAX_RADIX)
    {
        value = [[[NSNumber numberWithInt:chr] stringValue] intValue];
    }
    return value;
}

+ (java_lang_Character*) forDigit___int_int:(int)digit:(int)radix
{
    if ((digit >= radix) || (digit < 0)) {
        return '\0';
    }
    if ((radix < MIN_RADIX) || (radix > MAX_RADIX)) {
        return '\0';
    }
    if (digit < 10) {
        return (java_lang_Character*)(unichar)('0' + digit);
    }
    return (java_lang_Character*)(unichar)('a' - 10 + digit);
}


@end
