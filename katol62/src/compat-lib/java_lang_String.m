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

#import "java_lang_String.h"
#import "java_lang_RuntimeException.h"
#import "java_lang_System.h"

// java.lang.String
//----------------------------------------------------------------------------
@implementation NSMutableString (cat_java_lang_String)

+ (java_lang_String *) format___java_lang_String_java_lang_Object_ARRAYTYPE:(java_lang_String *)format :(XMLVMArray *)args;
{
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    NSMutableArray *ar = [[[NSMutableArray alloc] init] autorelease];
    
    for (int i=0; i<[args count]; i++)
    {
        id object = [args objectAtIndex:i];
        [ar addObject:object];
    }
    java_lang_String* ret = (java_lang_String *)[NSString stringWithFormat:(NSString *)format, [(NSArray *)ar componentsJoinedByString:@" "]];
    [ret retain];
    [pool drain];
    return ret;
}

- (void) __init_java_lang_String___java_lang_String: (java_lang_String*) str
{
	[self setString: (NSString *)str];
}

- (void) __init_java_lang_String___byte_ARRAYTYPE: (XMLVMArray*) bytes
{
	for(int i = 0; i < bytes->length; i++) {
		[self appendFormat:@"%c", (char) bytes->array.b[i]];
	}
}

- (void) __init_java_lang_String___byte_ARRAYTYPE_java_lang_String: (XMLVMArray*) bytes :(java_lang_String*) encoding
{
	for(int i = 0; i < bytes->length; i++) {
		[self appendFormat:@"%c", (char) bytes->array.b[i]];
	}
}

- (void) __init_java_lang_String___char_ARRAYTYPE: (XMLVMArray*) chars
{
	for(int i = 0; i < chars->length; i++) {
		[self appendFormat:@"%C", chars->array.c[i]];
	}
}

- (void) __init_java_lang_String___char_ARRAYTYPE_int_int: (XMLVMArray*) chars :(int) offset :(int) count
{
	for(int i = offset; i < offset + count; i++) {
		[self appendFormat:@"%C", chars->array.c[i]];
	}
}

+ (java_lang_String*) valueOf___int: (int) i
{
	NSNumber* n = [NSNumber numberWithInt: i];
	return (java_lang_String*)[[NSString alloc] initWithString: [n stringValue]];
}

+ (java_lang_String*) valueOf___long: (JAVA_LONG) l {
	NSNumber* n = [NSNumber numberWithLong: l];
	return (java_lang_String*)[[NSString alloc] initWithString: [n stringValue]];
}

+ (java_lang_String*) valueOf___float: (float) f
{
	NSNumber* n = [NSNumber numberWithFloat: f];
	return (java_lang_String*)[[NSString alloc] initWithString: [n stringValue]];
}

+ (java_lang_String*) valueOf___double: (double) d
{
	NSNumber* n = [NSNumber numberWithDouble: d];
	return (java_lang_String*)[[NSString alloc] initWithString: [n stringValue]];
}

+ (java_lang_String*) valueOf___java_lang_Object: (java_lang_Object*) o
{
	if ([o isKindOfClass: [NSString class]] == YES) {
		return (java_lang_String*)[[NSString alloc] initWithString: (NSString*) o];
	}
	return (java_lang_String*)[[NSString alloc] initWithString: @"Unkown type in valueOf___java_lang_Object"];
}

- (void) getChars___int_int_char_ARRAYTYPE_int:(int)srcBegin:(int)srcEnd:(XMLVMArray*)dst:(int)dstBegin {
	if (srcBegin < 0) {
		java_lang_RuntimeException* ex = [[java_lang_RuntimeException alloc] init];
		[ex __init_java_lang_RuntimeException___java_lang_String:[NSMutableString stringWithString:@"Out of bounds: srcBegin"]];
		@throw ex;
	}
	if (srcEnd > [self length__]) {
		java_lang_RuntimeException* ex = [[java_lang_RuntimeException alloc] init];
		[ex __init_java_lang_RuntimeException___java_lang_String:[NSMutableString stringWithString:@"Out of bounds: srcEnd"]];
		@throw ex;
	}
	if (srcBegin > srcEnd) {
		java_lang_RuntimeException* ex = [[java_lang_RuntimeException alloc] init];
		[ex __init_java_lang_RuntimeException___java_lang_String:[NSMutableString stringWithString:@"Out of bounds: srcEnd - srcBegin"]];
		@throw ex;
	}

	int j = dstBegin;
	int n = srcEnd - srcBegin;
	int i = srcBegin; //srcPos

	while (i < n) {
		dst->array.c[j++] = [self characterAtIndex:i++];
	}
}

- (XMLVMArray*) getBytes__
{
	XMLVMArray *bytes = [XMLVMArray createSingleDimensionWithType:3 /*BYTES*/ andSize: self.length];
	for (int i = 0; i < self.length; i++) {
		bytes->array.b[i] = [self characterAtIndex:i];
	}
	return bytes;
}

- (XMLVMArray*) toCharArray__
{
	XMLVMArray *chars = [XMLVMArray createSingleDimensionWithType:2 /*CHAR*/ andSize: self.length];
	for (int i = 0; i < self.length; i++) {
		chars->array.c[i] = [self characterAtIndex:i];
	}
	return chars;
}

- (JAVA_CHAR) charAt___int: (int) idx
{
	return [self characterAtIndex: idx];
}

- (int) lastIndexOf___int: (int) ch
{
	int i;
	for (i = [self length] - 1; i >= 0; i--) {
		if ([self characterAtIndex: i] == ch)
			break;
	}
	return i;
}

- (int) contains___java_lang_CharSequence: (java_lang_CharSequence*) str
{
	return [self rangeOfString:(NSString *)str].location != NSNotFound;
}

- (int) endsWith___java_lang_String: (java_lang_String*) s
{
	return [self hasSuffix: (NSString *)s] == YES ? 1 : 0;
}

- (java_lang_String*) substring___int_int: (int) from :(int) to
{
	NSRange range;
	range.location = from;
	range.length = to - from;
	return_XMLVM(substringWithRange: range)
}

- (java_lang_String*) substring___int: (int) from
{
	return_XMLVM(substringFromIndex: from)
}

- (int) compareTo___java_lang_String: (java_lang_String*) str
{
	return [self compare: (NSString *)str];
}

- (int) equals___java_lang_Object: (java_lang_Object*) o
{
	if ([o isKindOfClass: [NSString class]] == NO) {
		return 0;
	}
	return [self compare: (NSString*) o] == 0;
}

- (int) equalsIgnoreCase___java_lang_String: (java_lang_String*) s
{
	return [self caseInsensitiveCompare: (NSString *)s] == 0;
}

- (java_lang_String*) toString__
{
	return_XMLVM(self)
}

- (java_lang_String*) toLowerCase__
{
	return_XMLVM(lowercaseString)
}

 - (java_lang_String*) toUpperCase__
 {
	return_XMLVM(uppercaseString)
 }

- (int) startsWith___java_lang_String: (java_lang_String*) s {
	return [self hasPrefix: (NSString *)s] == YES ? 1 : 0;
}

- (int) lastIndexOf___java_lang_String: (java_lang_String*) s {
	NSRange range = [self rangeOfString: (NSString *)s options:NSBackwardsSearch];
	if (range.location == NSNotFound) {
		return -1;
	}

	return range.location;
}

- (int) indexOf___int: (int) ch {
	int i;
	
	for (i = 0; i < [self length]; i++) {
		if ([self characterAtIndex: i] == ch)
			return i;
	}
	
	return -1;
}
	
- (int) indexOf___java_lang_String: (java_lang_String*) s {
	NSRange range = [self rangeOfString: (NSString *)s];
	if (range.location == NSNotFound) {
		return -1;
	}
	return range.location;
}

- (int) length__
{
	return [self length];
}

- (java_lang_String*) replace___char_char:(JAVA_CHAR)from :(JAVA_CHAR)to
{
	NSString * res = [self stringByReplacingOccurrencesOfString:[NSString stringWithFormat:@"%C",from] withString:[NSString stringWithFormat:@"%C",to]];
	return (java_lang_String*)[res retain];
}

- (java_lang_String*) replace___java_lang_CharSequence_java_lang_CharSequence:(java_lang_CharSequence*)from :(java_lang_CharSequence*)to
{
	NSString * res = [self stringByReplacingOccurrencesOfString:(NSString *)from withString:(NSString *)to];
	return (java_lang_String*)[res retain];
}

- (java_lang_String*) replaceFirst___java_lang_String_java_lang_String:(java_lang_String*)regex :(java_lang_String*)replacement
{
#if __IPHONE_OS_VERSION_MIN_REQUIRED <= __IPHONE_3_1
#define NSRegularExpressionSearch NSLiteralSearch
	NSLog(@"String.replaceFirst() not supported");
#endif
	NSRange found = [self rangeOfString:(NSString *)regex options:NSRegularExpressionSearch];
	if (found.location == NSNotFound) {
		return_XMLVM(self);
	}
	NSString * res = [NSString stringWithFormat:@"%@%@%@", 
					  [self substringToIndex:found.location],
					  replacement,
					  [self substringFromIndex:(found.location+found.length)]];
	return (java_lang_String*)[res retain];
}

- (java_lang_String*) replaceAll___java_lang_String_java_lang_String :(java_lang_String*)a :(java_lang_String*)b {
	NSMutableString *m = [[NSMutableString alloc] initWithString:self];
	NSRange range;
	range.location = 0;
	range.length = [m length__];

	[m replaceOccurrencesOfString:(NSString *)a withString:(NSString *)b options:(NSLiteralSearch) range:range];
	return (java_lang_String*)m;
}

- (int) matches___java_lang_String:(java_lang_String*)regex
{
//#if __IPHONE_OS_VERSION_MIN_REQUIRED <= __IPHONE_3_1
//#define NSRegularExpressionSearch NSLiteralSearch
//	NSLog(@"String.replaceFirst() not supported");
//#endif
	NSRange found = [self rangeOfString:(NSString *)regex options:NSRegularExpressionSearch];
	return found.location != NSNotFound;
}

- (XMLVMArray*) split___java_lang_String :(java_lang_String*)s
{
	NSArray *chunks = [self componentsSeparatedByString:(NSString *)s];
	int length = [chunks count];

	XMLVMArray *result = [XMLVMArray createSingleDimensionWithType: 0 andSize: length]; // object reference array
	for (int i=0; i<length; i++) {
		result->array.o[i] = [[chunks objectAtIndex: i] retain];
	}

	return result;
}

- (java_lang_String*) trim__ {
	int len = [self length];
	int st = 0;
	int off = 0; //this should be initialized from "offset"

	while (st < len && [self charAt___int:off + st] <= ' ') {
		st++;
	}
	while (st < len && [self charAt___int:off + len - 1] <= ' ') {
		len--;
	}
	return (st > 0 || len < [self length]) ? (java_lang_String*)[self substring___int_int:st:len] : (java_lang_String*)[self retain];
}

- (int) isEmpty__
{
	return [self length] == 0;
}

@end
