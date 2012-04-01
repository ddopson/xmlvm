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

#import "java_util_Set.h"


// java.util.Set
//----------------------------------------------------------------------------
@implementation java_util_Set
- (id) init
{
  self->internalSet = [[NSMutableSet alloc] init];
  return self;
}

- (NSUInteger) count
{
  return [self->internalSet count];
}

- (id) member: (id) object
{
  return [self->internalSet member: object];
}

- (NSEnumerator *) objectEnumerator
{
  return [self->internalSet objectEnumerator];
}

- (void) addObject: (id) object
{
  [self->internalSet addObject: object];
}

- (void) removeObject: (id) object
{
  [self->internalSet removeObject: object];
}
@end

@implementation NSMutableSet (cat_java_util_Set)

- (java_util_Iterator*) iterator__
{
	return [[java_util_IteratorImpl alloc] init: [self objectEnumerator]];
}

- (void) clear__
{
	[self removeAllObjects];
}

- (BOOL) add___java_lang_Object: (java_lang_Object*) obj
{
	BOOL hasObj = [self containsObject:obj];
	[self addObject:obj];
	return hasObj;
}

- (BOOL) remove___java_lang_Object:(java_lang_Object*) obj
{
	BOOL hasObj = [self containsObject:obj];
	[self removeObject:obj];
	return hasObj;
}

- (int) size__
{
	return [self count];
}

- (BOOL) isEmpty__
{
	return [self count]<1;
}

// TODO move this to AbstractCollection where it really belongs
- (BOOL) addAll___java_util_Collection: (java_util_Collection*) c
{
	int origSize = [self size__];
	java_util_Iterator* iter = [c iterator__];
	while ([iter hasNext__]) {
		java_lang_Object* obj = [iter next__];
		[self add___java_lang_Object:obj];
		[obj release];
	}
	[iter release];
	return origSize == [self size__];
}

- (BOOL) contains___java_lang_Object: (java_lang_Object*) o
{
	// TODO: wow, this is inefficient
     java_util_Iterator* iter = [self iterator__];
	while ([iter hasNext__]) {
		java_lang_Object* obj = [iter next__];
		if (o == JAVA_NULL ? obj == JAVA_NULL : [o equals___java_lang_Object:obj]) {
			[obj release];
			[iter release];
			return TRUE;
		}
		[obj release];
	}
	[iter release];
	return FALSE;
}


@end
