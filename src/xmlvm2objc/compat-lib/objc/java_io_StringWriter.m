#import "java_io_StringWriter.h"
#import "java_lang_NullPointerException.h"

@implementation java_io_StringWriter;

- (id) init
{
	[super init];
	self->lock = (java_lang_Object*) JAVA_NULL;
	writeBuffer = (XMLVMArray*) JAVA_NULL;
	return self;
}

- (java_lang_Object*) getProtectedLock
{
	return self->lock;
}

- (void) __init_java_io_Writer__
{
	[self __init_java_io_Writer__java_lang_Object:self];
}

- (void) __init_java_io_Writer__java_lang_Object: (java_lang_Object*)lockObject
{
	if (lockObject == (java_lang_Object*) JAVA_NULL) {
		java_lang_NullPointerException* ex = [[java_lang_NullPointerException alloc] init];
//		[ex __init_java_lang_NullPointerException___java_lang_String:@"Locking object cannot be NULL!"];
		@throw ex;
	}

	self->lock = lockObject;
	// Avoid cyclic dependency where self is never released if it references itself in self->lock. Similar logic is in "dealloc".
	// If self were to be retained again, the "retainCount" would never get to 0 and would not be deallocated.
	if (self != self->lock) {
		[self->lock retain];
	}
}


- (void) close__
{
}

- (void) flush__
{
}

- (void) write___char_ARRAYTYPE: (XMLVMArray *) cbuf
{
	[self write___char_ARRAYTYPE_int_int:cbuf:0:[cbuf count]];
}

- (void) write___char_ARRAYTYPE_int_int: (XMLVMArray *) cbuf: (int) off: (int) len
{
  for(int i = off; i < off + len; i++) {
    [self->data appendFormat: @"%C": cbuf->array.c[i]];
  }
}

- (java_io_Writer*) append___char: (JAVA_CHAR) c
{
  [self write___int: c];
  return self;
}

- (java_io_Writer*) append___java_lang_CharSequence: (java_lang_CharSequence *) csq;
{
  [self write___java_lang_String: csq];
  return self;
}

- (java_io_Writer*) append___java_lang_CharSequence_int_int: (java_lang_CharSequence *) csq: (int) start: (int) end;
{
  [self write___java_lang_String_int_int: csq: start: end];
  return self;
}

- (void) write___int: (int) c
{
  [self->data appendFormat: @"%C": c];
}

- (void) write___java_lang_String: (java_lang_String*) str
{
  [self->data appendString: str];
}

- (void) write___java_lang_String_int_int: (java_lang_String*) str: (int) off: (int) len
{
  [self->data appendString: [str substringWithRange: NSMakeRange(off, len)]]; 
}

- (void) dealloc
{
	// In order to avoid cyclic dependency, self->lock was NOT retained during initialization if it was equal to self.
	// Otherwise, the "retainCount" would never get to 0 and this "dealloc" method wouldn't even be called, causing a memory leak.
	// Since it was not retained, it should not be released either. It already has a "retainCount" of 0 right now.
	if (self != self->lock) {
		[self->lock release];
	}
	[writeBuffer release];
	[super dealloc];
}

@end
