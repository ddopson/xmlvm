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

static int UNASSIGNED = 0;
static int UPPERCASE_LETTER = 1;
static int LOWERCASE_LETTER = 2;
static int TITLECASE_LETTER = 3;
static int MODIFIER_LETTER = 4;
static int OTHER_LETTER = 5;
static int NON_SPACING_MARK = 6;
static int ENCLOSING_MARK = 7;
static int COMBINING_SPACING_MARK = 8;
static int DECIMAL_DIGIT_NUMBER = 9;
static int LETTER_NUMBER = 10;
static int OTHER_NUMBER = 11;
static int SPACE_SEPARATOR = 12;
static int LINE_SEPARATOR = 13;
static int PARAGRAPH_SEPARATOR = 14;
static int CONTROL = 15;
static int FORMAT = 16;
static int PRIVATE_USE = 18;
static int SURROGATE = 19;
static int DASH_PUNCTUATION = 20;
static int START_PUNCTUATION = 21;
static int END_PUNCTUATION = 22;
static int CONNECTOR_PUNCTUATION = 23;
static int OTHER_PUNCTUATION = 24;
static int MATH_SYMBOL = 25;
static int CURRENCY_SYMBOL = 26;
static int MODIFIER_SYMBOL = 27;
static int OTHER_SYMBOL = 28;
static int INITIAL_QUOTE_PUNCTUATION = 29;
static int FINAL_QUOTE_PUNCTUATION = 30;

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
    /*
    int value = -1;
    if (radix >= MIN_RADIX && radix <= MAX_RADIX)
    {
        value = [[[NSNumber numberWithInt:chr] stringValue] intValue];
    }
    return value;
     */
    int ch = chr;
    
    int value = -1;
    if (radix >= MIN_RADIX && radix <= MAX_RADIX) {
        NSCharacterSet *numericSet = [NSCharacterSet decimalDigitCharacterSet];
        if ([numericSet characterIsMember:ch]) {
            value = (int)(ch-'0');
        }
        else {
            NSCharacterSet *lowercaseSet = [NSCharacterSet lowercaseLetterCharacterSet];
            NSCharacterSet *uppercaseSet = [NSCharacterSet uppercaseLetterCharacterSet];
            if ([lowercaseSet characterIsMember:ch]) {
                value = (int)(ch - 'a' + 10);
            }
            if ([uppercaseSet characterIsMember:ch]) {
                value = (int)(ch - 'A' + 10);
            }
            
            
        }
        
        
    }
    return value;//(value < radix) ? value : -1;

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

+ (int) _GET_MIN_RADIX
{
    return MIN_RADIX;
}

+ (int) _GET_MAX_RADIX
{
    return MAX_RADIX;
}

@end
