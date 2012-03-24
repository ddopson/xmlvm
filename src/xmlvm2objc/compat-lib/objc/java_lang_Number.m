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

#import "java_lang_Number.h"

// java.lang.Number
//----------------------------------------------------------------------------
@implementation java_lang_Number

+ (void) initialize
{
}

- (id) init
{
	return self;
}

- (id) copyWithZone:(NSZone *)zone
{
    [self xmlvmSubclassResponsibility];
}

- (NSUInteger) hash
{
    [self xmlvmSubclassResponsibility];
}

- (BOOL)isEqual:(id)anObject
{
    [self xmlvmSubclassResponsibility];
}

- (unsigned char) byteValue__
{
    [self xmlvmSubclassResponsibility];
}

- (double) doubleValue__
{
    [self xmlvmSubclassResponsibility];
}

- (float) floatValue__
{
    [self xmlvmSubclassResponsibility];
}

- (int) intValue__
{
    [self xmlvmSubclassResponsibility];
}

- (long) longValue__
{
    [self xmlvmSubclassResponsibility];
}

- (short) shortValue__
{
    [self xmlvmSubclassResponsibility];
}

- (java_lang_String*) toString__
{
    [self xmlvmSubclassResponsibility];
}

@end
