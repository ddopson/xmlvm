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

id JAVA_NULL;

void xmlvm_init()
{
      JAVA_NULL = [NSNull null];
}



@implementation XMLVMArray

/* This private method creates a shallow copy of this array */
XMLVMElemPtr copyData(int type, int length, XMLVMElemPtr olddata)
{
    int sizeOfBaseType = [XMLVMArray sizeOfBaseTypeInBytes:type];
    int sizeOfArrayInBytes = sizeOfBaseType * length;
    XMLVMElemPtr array;
    array.data = malloc(sizeOfArrayInBytes);
    if (type == 0) {
        for (int i = 0; i < length; i++) {
            array.o[i] = [olddata.o[i] retain];
        }
    }
    else {
        memcpy(array.data, olddata.data, sizeOfArrayInBytes);
    }
    return array;
}

+ (XMLVMArray*) createSingleDimensionWithType:(int) type andSize:(int) size
{
    XMLVMArray *retval = [[XMLVMArray alloc] init];
    retval->type = type;
    retval->length = size;

    int sizeOfBaseType = [XMLVMArray sizeOfBaseTypeInBytes:type];
    retval->array.data = malloc(sizeOfBaseType * size);
    bzero(retval->array.data, sizeOfBaseType * size);

    if (type == 0) {
        for (int i = 0; i < size; i++) {
            retval->array.o[i] = JAVA_NULL;
        }
    }

    return retval;
}

+ (XMLVMArray*) createSingleDimensionWithType:(int) type size:(int) size andData:(void*) data
{
    XMLVMArray *retval = [[XMLVMArray alloc] init];
    retval->type = type;
    retval->length = size;
    retval->array = copyData(type, size, (XMLVMElemPtr)data);
    return retval;
}

+ (XMLVMArray*) createMultiDimensionsWithType:(int) type dimensions:(XMLVMElem*) dim count:(int)count
{
    int dimensions = dim->i;
    dim++;
    count--;
    if (count == 0) {
        return [XMLVMArray createSingleDimensionWithType:type andSize:dimensions];
    }
    XMLVMArray* slice = [XMLVMArray createSingleDimensionWithType:0 andSize:dimensions];
    for (int i = 0; i < dimensions; i++) {
        id o = [XMLVMArray createMultiDimensionsWithType:type dimensions:dim count:count];
        [slice replaceObjectAtIndex:i withObject:o];
        [o release];
    }
    return slice;
}

+ (void) fillArray:(XMLVMArray*) array withData:(void*) data
{
    int sizeOfBaseType = [XMLVMArray sizeOfBaseTypeInBytes:array->type];
    int n = sizeOfBaseType * array->length;
    memcpy(array->array.data, data, n);
}

+ (int) sizeOfBaseTypeInBytes:(int) type
{
    int sizeOfBaseType;
    
    // 'type' values are defined by vm:sizeOf in xmlvm2objc.xsl
    switch (type) {
    case TYPE_JAVA_OBJECT: // object = 0
        sizeOfBaseType = sizeof(JAVA_OBJECT);
        break;
    case TYPE_JAVA_BOOLEAN: // boolean = 1
        sizeOfBaseType = sizeof(JAVA_BOOLEAN);
        break;
    case TYPE_JAVA_BYTE: // byte = 3
        sizeOfBaseType = sizeof(JAVA_BYTE);
        break;
    case TYPE_JAVA_CHAR: // char = 2
        sizeOfBaseType = sizeof(JAVA_CHAR);
        break;
    case TYPE_JAVA_SHORT: // short = 4
        sizeOfBaseType = sizeof(JAVA_SHORT);
        break;
    case TYPE_JAVA_USHORT: // short = 4
        sizeOfBaseType = sizeof(JAVA_USHORT);
        break;
    case TYPE_JAVA_INT: // int = 5
        sizeOfBaseType = sizeof(JAVA_INT);
        break;
    case TYPE_JAVA_UINT: // uint = 15
        sizeOfBaseType = sizeof(JAVA_UINT);
        break;
    case TYPE_JAVA_FLOAT: // float = 6
        sizeOfBaseType = sizeof(JAVA_FLOAT);
        break;
    case TYPE_JAVA_DOUBLE: // double = 7
        sizeOfBaseType = sizeof(JAVA_DOUBLE);
        break;
    case TYPE_JAVA_LONG: // long = 8
        sizeOfBaseType = sizeof(JAVA_LONG);
        break;
    case TYPE_JAVA_ULONG: // ulong = 18
        sizeOfBaseType = sizeof(JAVA_ULONG);
        break;
    case TYPE_XMLVMELEM: // XMLVMElem = 100
        sizeOfBaseType = sizeof(XMLVMElem);
        break;
    default: // object reference - TODO - this sholud be an error
        sizeOfBaseType = sizeof(id);
        break;
    }
    
    return sizeOfBaseType;
}

- (id) objectAtIndex:(int) idx
{
    id obj = self->array.o[idx];
    return [obj retain];
}

- (void) replaceObjectAtIndex:(int) idx withObject:(id) obj
{
    [obj retain];
    [self->array.o[idx] release];
    self->array.o[idx] = obj;
}

- (int) count
{
    return length;
}

- (void) dealloc
{
    if (self->type == 0) {
        for (int i = 0; i < length; i++) {
            [self->array.o[i] release];
        }
    }
    free(self->array.data);
    [super dealloc];
}


- (XMLVMArray*) clone__
{
    XMLVMArray *retval = [[XMLVMArray alloc] init];
    retval->type = self->type;
    retval->length = self->length;
    retval->array = copyData(self->type, self->length, self->array);
    return retval;
}

@end



void ERROR(char* msg)
{
    NSLog(@"%@", [NSString stringWithUTF8String:msg]);
    @throw [NSException exceptionWithName: @"XMLVM missing byte code instruction" reason:[NSString stringWithUTF8String:msg] userInfo: nil];
}
