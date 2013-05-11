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
#import "java_lang_Object.h"
#import "java_util_IteratorImpl.h"
#import "java_util_Collection.h"

// java.util.Set
//----------------------------------------------------------------------------
@interface NSMutableSet (cat_java_util_Set)

- (java_util_Iterator*) iterator__;
- (int) size__;
- (BOOL) isEmpty__;
- (BOOL) add___java_lang_Object: (java_lang_Object*) obj;
- (BOOL) addAll___java_util_Collection: (java_util_Collection*) c;
- (BOOL) remove___java_lang_Object:(java_lang_Object*) obj;
- (void) clear__;
- (BOOL) contains___java_lang_Object: (java_lang_Object*) o;

@end

@interface java_util_Set : NSMutableSet
{
  @private NSMutableSet* internalSet;
}

- (id) init;
// NSSet Overrides
- (NSUInteger) count;
- (id) member: (id) object;
- (NSEnumerator *) objectEnumerator;
// NSMutableSet Overrides
- (void) addObject: (id) object;
- (void) removeObject: (id) object;

@end


