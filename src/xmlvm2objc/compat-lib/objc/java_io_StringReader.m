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

#import "java_io_StringReader.h"

// java.io.StringReader
//----------------------------------------------------------------------------
@implementation java_io_StringReader

- (void) __init_java_io_StringReader___java_lang_String:(java_lang_String*)s
{
	self->str = s;
	self->pos = 0;
}

- (int) read__
{
	if ([str length] == pos) {
		return -1;
	}
	return [str characterAtIndex: pos++];
}

- (int) read___char_ARRAYTYPE_int_int: (XMLVMArray *) buffer: (int) pos: (int) len
{
    for(int p = pos; p < pos + len; p++) {
      int c = [self read__];
      NSLog(@"Reading Char: %C", c);
      if (c == -1) {
        return p - pos;
      }
      buffer->array.c[p] = c;
    }
    return len;
}
@end

