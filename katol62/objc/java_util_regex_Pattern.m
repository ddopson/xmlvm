//
//  java_util_regex_Pattern.m
//  HelloResources
//
//  Created by apple on 08.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "java_util_regex_Pattern.h"

@implementation java_util_regex_Pattern

NSRegularExpression *regex;
java_util_regex_Matcher* matcher;

+(java_util_regex_Pattern*)compile___java_lang_String:(java_lang_String*)str
{
    NSAutoreleasePool *loopPool = [[NSAutoreleasePool alloc] init];

    java_util_regex_Pattern* pattern = [[[java_util_regex_Pattern alloc] init] autorelease];
    NSError *error = NULL;
    
//    str = (java_lang_String*)[(NSString *)str stringByReplacingOccurrencesOfString:@"(\\p{XDigit}+)"
//                                                     withString:@"[0-9A-Fa-f]+"];
//    str = (java_lang_String*)[(NSString *)str stringByReplacingOccurrencesOfString:@"(\\p{Digit}+)"
//                                                     withString:@"[0-9a-f.-]+"];
    
    str = (java_lang_String*)[(NSString *)str stringByReplacingOccurrencesOfString:@"(((\\p{Digit}+)(\\.)?((\\p{Digit}+)?)([eE][+-]?(\\p{Digit}+))?)|(\\.((\\p{Digit}+))([eE][+-]?(\\p{Digit}+))?))|(((0[xX](\\p{XDigit}+)(\\.)?)|(0[xX](\\p{XDigit}+)?(\\.)(\\p{XDigit}+)))[pP][+-]?(\\p{Digit}+))"
                                                     withString:@"(((0[xX](\\p{XDigit}+)(\\.)?)|(0[xX](\\p{XDigit}+)?(\\.)(\\p{XDigit}+)))[pP][+-]?(\\p{Digit}+))|(((\\p{Digit}+)(\\.)?((\\p{Digit}+)?)([eE][+-]?(\\p{Digit}+))?)|(\\.((\\p{Digit}+))([eE][+-]?(\\p{Digit}+))?))"];

    
    pattern->regex = [NSRegularExpression regularExpressionWithPattern:(NSString*)str
//                                                              options:NSRegularExpressionCaseInsensitive
                                                                options:0
                                                                error:&error];
    return pattern;
    
    [loopPool drain];
}

-(java_util_regex_Matcher*)matcher___java_lang_CharSequence:(NSString *)chr
{
    NSAutoreleasePool *loopPool = [[NSAutoreleasePool alloc] init];

    NSLog(@"chr=%@", chr);
    NSCharacterSet* whitespace = [NSCharacterSet characterSetWithCharactersInString: @" \t\n\r\f\001\013\037"];
    NSString* trimmed = [chr stringByTrimmingCharactersInSet:whitespace];

    matcher = [[[java_util_regex_Matcher alloc] init] autorelease];
    
    matcher.matches = [regex matchesInString:trimmed
                                options:0
                                range:NSMakeRange(0, [trimmed length])];
    
    return matcher;
    [loopPool drain];
}

@end
