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


#import <objc/runtime.h>
#import <Foundation/Foundation.h>

#import <CoreFoundation/CoreFoundation.h>
#import <math.h>


void xmlvm_init();

// Note that even though Java does not define unsigned types (other than byte/char), the JVM does
// Java's Byte and Character types are unsigned

typedef id                 JAVA_OBJECT;
typedef unsigned char      JAVA_BYTE;
typedef unsigned short     JAVA_CHAR;
typedef short              JAVA_SHORT;
typedef unsigned short     JAVA_USHORT;
typedef int                JAVA_INT;
typedef unsigned int       JAVA_UINT;
typedef long long          JAVA_LONG;
typedef unsigned long long JAVA_ULONG;
typedef float              JAVA_FLOAT;
typedef double             JAVA_DOUBLE;
typedef char               JAVA_BOOLEAN;

// These TYPE_* definitions are used with createSingleDimensionWithType
#define TYPE_JAVA_OBJECT    0
#define TYPE_JAVA_BOOLEAN   1
#define TYPE_JAVA_CHAR      2
#define TYPE_JAVA_BYTE      3
#define TYPE_JAVA_SHORT     4
#define TYPE_JAVA_USHORT    14
#define TYPE_JAVA_INT       5
#define TYPE_JAVA_UINT      15
#define TYPE_JAVA_FLOAT     6
#define TYPE_JAVA_DOUBLE    7
#define TYPE_JAVA_LONG      8
#define TYPE_JAVA_ULONG     18
#define TYPE_XMLVMELEM      100

typedef union {
    JAVA_OBJECT     o;
    JAVA_BYTE       b;
    JAVA_CHAR       c;
    JAVA_SHORT      s;
    JAVA_USHORT     us;
    JAVA_INT        i;
    JAVA_UINT       ui;
    JAVA_LONG       l;
    JAVA_ULONG      ul;
    JAVA_FLOAT      f;
    JAVA_DOUBLE     d;
} XMLVMElem;

typedef union {
    JAVA_OBJECT*    o;
    JAVA_BYTE*      b;
    JAVA_CHAR*      c;
    JAVA_SHORT*     s;
    JAVA_USHORT*    us;
    JAVA_INT*       i;
    JAVA_UINT*      ui;
    JAVA_LONG*      l;
    JAVA_ULONG*     ul;
    JAVA_FLOAT*     f;
    JAVA_DOUBLE*    d;
    void*           data;
} XMLVMElemPtr;


extern id JAVA_NULL;

@interface XMLVMArray : NSObject // TODO should be java_lang_Object
{
    @public XMLVMElemPtr array;
    @public int          type;
    @public int          length;
}

+ (XMLVMArray*) createSingleDimensionWithType:(int) type andSize:(int) size;
+ (XMLVMArray*) createSingleDimensionWithType:(int) type size:(int) size andData:(void*) data;
+ (XMLVMArray*) createMultiDimensionsWithType:(int) type dimensions:(XMLVMElem*) dim count:(int)count;
+ (void) fillArray:(XMLVMArray*) array withData:(void*) data;
+ (int) sizeOfBaseTypeInBytes:(int) type;
- (id) objectAtIndex:(int) idx;
- (void) replaceObjectAtIndex:(int) idx withObject:(id) obj;
- (int) count;
- (XMLVMArray*) clone__;

@end

//#define Infinity 0x7f800000
//#define NaN 0x7fc00000
#define Infinity 1.0 / 0.0
#define NaN sqrt (-1)

void ERROR(char* msg);

// Use this macro to safely set a n obj-c value, in case Java has given a null pointer
#define XMLVM_NULL2NIL(VALUE) (((id)(VALUE)==JAVA_NULL)?nil:VALUE)
#define XMLVM_NIL2NULL(VALUE) (VALUE==nil?JAVA_NULL:VALUE)

// Return the value of an obj-c property. This value is retained.  If the value is nil, null is returned to java
#define return_XMLVM(ITEMNAME) return_XMLVM_SELECTOR(self ITEMNAME)
// Same as return_XMLVM_SELECTOR, but also define the actual selector
#define return_XMLVM_SELECTOR(SELECTOR) id __xmlvm_item = [SELECTOR]; return [XMLVM_NIL2NULL(__xmlvm_item) retain] ;

// Set a property and retain it. Usually this is called when a delegate is given as a parameter. This object will automatically be released when this object will be released
#define XMLVM_PROPERTY(PROPERTY,VALUE) XMLVM_PROPERTY_WITHCOMMAND(PROPERTY,VALUE,self.PROPERTY = __retainable)
// Like XMLVM_PROPERTY but specify the exact command to execute to set this property (if any) 
#define XMLVM_PROPERTY_WITHCOMMAND(PROPERTY,VALUE,COMMAND) id __retainable=(VALUE==JAVA_NULL)?nil:VALUE; COMMAND; static char PROPERTY_key; objc_setAssociatedObject(self, &PROPERTY_key, __retainable, OBJC_ASSOCIATION_RETAIN_NONATOMIC);

// Under old iPhone simulator there is a bug, in which associations are not supported. This is a workaround, which actually leaves a memory leak, but it doesn't harm (much).
#if __IPHONE_OS_VERSION_MAX_ALLOWED < 40000
#if TARGET_IPHONE_SIMULATOR
#define objc_setAssociatedObject(A,B,ITEM,D) [ITEM retain];
#define OBJC_ASSOCIATION_RETAIN_NONATOMIC 1
#endif
#endif

// This is used to support optional protocol implementation in Java. Declare that an ObjC selector exists ONLY if the JAVA selector exists. CHECK is the current selector being asked.
#define XMLVM_REROUTE(CHECK,OBJC,JAVA) if (sel_isEqual(CHECK, @selector(OBJC))) return [super respondsToSelector:@selector(JAVA)];
