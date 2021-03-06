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
#import "java_util_IteratorImpl.h"
#import "java_util_List.h"
#import "java_util_Collection.h"

// java.util.ArrayList
//----------------------------------------------------------------------------
//
// We extend the native NSArray / NSMWutableArray objects with categories so that they respond like Java object
// We create a new class java_util_ArrayList that HAS_A NSMutableDictionary so that this class can be extended safely (not true of the native classes which are actually "class clusters" and can't be easily extended)
// java_util_ArrayList actually gets it's Java methods from the categories attached to the native classes
// This means that NSArray objects can be passed to Java methods and will "appear" to be java_util_ArrayList objects in most respects (major caveat is 'instanceof' and reflection)

@interface NSArray (cat_java_util_ArrayList)
- (int) size__;
- (int) contains___java_lang_Object :(java_lang_Object*) item;
- (BOOL) isEmpty__;
- (java_util_Iterator*) iterator__;
- (int) indexOf___java_lang_Object :(java_lang_Object*) item;
- (java_lang_Object*) get___int :(int) idx;
@end

@interface NSMutableArray (cat_java_util_ArrayList) <java_util_List>
- (void) __init_java_util_ArrayList__;
- (void) __init_java_util_ArrayList___int:(int)initialCapacity;
- (void) __init_java_util_ArrayList___java_util_Collection:(java_util_Collection*)c;
- (BOOL) add___java_lang_Object :(java_lang_Object*) item;
- (void) add___int_java_lang_Object :(int) idx :(java_lang_Object*) item;
- (BOOL) addAll___java_util_Collection:(java_util_Collection*)c;
- (java_lang_Object*) set___int_java_lang_Object :(int) idx: (java_lang_Object*) item;
- (java_lang_Object*) remove___int :(int) idx;
- (BOOL) remove___java_lang_Object :(java_lang_Object*) item;
- (BOOL) removeAll___java_util_Collection:(java_util_Collection*) c;
- (void) clear__;
- (XMLVMArray*) toArray__;
- (XMLVMArray*) toArray___java_lang_Object_ARRAYTYPE:(XMLVMArray*) contents;
@end

@interface java_util_ArrayList : NSMutableArray
{
  @private NSMutableArray* internalArray;
}
- (id) init;
// NSArray Overrides
- (NSUInteger) count;
- (id) objectAtIndex: (NSUInteger) index;
// NSMutableArray Overrides
- (void) insertObject: (id) anObject atIndex: (NSUInteger) index;
- (void) removeObjectAtIndex: (NSUInteger) index;
- (void) addObject: (id) anObject;
- (void) removeLastObject;
- (void) replaceObjectAtIndex: (NSUInteger) index withObject: (id) anObject;

@end
