#import "xmlvm.h"
#import "java_lang_Object.h"
#import "java_lang_CharSequence.h"

@class java_io_Appendable;

@protocol java_io_Appendable <NSObject>

- (java_io_Appendable*) append___char: (JAVA_CHAR) c;
- (java_io_Appendable*) append___java_lang_CharSequence: (java_lang_CharSequence *) csq;
- (java_io_Appendable*) append___java_lang_CharSequence_int_int: (java_lang_CharSequence *) csq: (int) start: (int) end;

@end

