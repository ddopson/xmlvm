#import "java_lang_Exception.h"
#import "java_lang_RuntimeException.h"
#import "java_lang_String.h"
#import "java_lang_StringBuilder.h"
#import "java_lang_System.h"
#import "Foundation/NSException.h"

// Automatically generated by xmlvm2obj. Do not edit!


#import "pkg_Main.h"
#import "org_xmlvm_iphone_NSObject.h"


@implementation pkg_Main;

+ (void) initialize
{
}

- (id) init
{
}

- (void) dealloc
{
}

- (void) __init_pkg_Main__
{
}

+ (void) main___java_lang_String_ARRAYTYPE :(XMLVMArray*)n1;
{
}

@end

static void runTest(NSString* name, Class class, SEL method) {
  @try {
    [class performSelector: method withObject: JAVA_NULL];
    NSLog(@"%@ PASS", name);
  } @catch (NSException* e) {
    id stack = [e callStackSymbols];
    NSLog(@"%@ FAIL - %@\n%@", name, e, stack);
    [stack release];
  }
}


int main(int argc, char* argv[])
{
    runTest(@"BitwiseConversion", [pkg_BitwiseConversion class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    /*
    runTest(@"Constants", [pkg_Constants class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"Extrema", [pkg_Extrema class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"NaNInfinityParsing", [pkg_NaNInfinityParsing class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"ParseDouble", [pkg_ParseDouble class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"ParseHexFloatingPoint", [pkg_ParseHexFloatingPoint class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"ToHexString", [pkg_ToHexString class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"ToString", [pkg_ToString class], @selector(testmain___java_lang_String_ARRAYTYPE));
     */
}
  
  
