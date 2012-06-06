#import "java_lang_Exception.h"
#import "java_lang_RuntimeException.h"
#import "java_lang_String.h"
#import "java_lang_StringBuilder.h"
#import "java_lang_System.h"
#import "Foundation/NSException.h"

// Automatically generated by xmlvm2obj. Do not edit!


#import "pkg_Main.h"
#import "pkg_BitwiseConversion.h"
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
    
    
    
    /* java_lang_Float
    runTest(@"BitwiseConversion", [pkg_BitwiseConversion class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"Constants", [pkg_Constants class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"Extrema", [pkg_Extrema class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"NaNInfinityParsing", [pkg_NaNInfinityParsing class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    //   runTest(@"ParseFloat", [pkg_ParseFloat class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"ParseFloat/rudimentary", [pkg_ParseFloat class], @selector(rudimentaryTest__));
    runTest(@"ParseFloat/good", [pkg_ParseFloat class], @selector(testParseGood__));
    runTest(@"ParseFloat/paddedGood", [pkg_ParseFloat class], @selector(testParsePaddedGood__));
    runTest(@"ParseFloat/bad", [pkg_ParseFloat class], @selector(testParseBad__));
    runTest(@"ParseFloat/paddedBad", [pkg_ParseFloat class], @selector(testParsePaddedBad__));
 */

/* java_lang_String
    runTest(@"CaseConvertSameInstance", [pkg_CaseConvertSameInstance class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"CompareIC", [pkg_CompareIC class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"ContentEquals", [pkg_ContentEquals class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"Encodings", [pkg_Encodings class], @selector(testmain___java_lang_String_ARRAYTYPE:));
    runTest(@"Exceptions", [pkg_Exceptions class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"ICCBasher", [pkg_ICCBasher class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"IndexOfEmptyInEmpty", [pkg_IndexOfEmptyInEmpty class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"IsEmpty", [pkg_IsEmpty class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"NonCharacterMapping", [pkg_NonCharacterMapping class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"Regex", [pkg_Regex class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"RegionMatches", [pkg_RegionMatches class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"SBConstructor", [pkg_SBConstructor class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"Split", [pkg_Split class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"Supplementary", [pkg_Supplementary class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"ToLowerCase", [pkg_ToLowerCase class], @selector(testmain___java_lang_String_ARRAYTYPE));
    runTest(@"ToUpperCase", [pkg_ToUpperCase class], @selector(testmain___java_lang_String_ARRAYTYPE));
*/
}
  
  
