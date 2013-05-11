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
    java_util_regex_Pattern* pattern = [[[java_util_regex_Pattern alloc] init] autorelease];
    NSError *error = NULL;
    pattern->regex = [NSRegularExpression regularExpressionWithPattern:(NSString*)str
//                                                              options:NSRegularExpressionCaseInsensitive
                                                                options:0
                                                                error:&error];
    return pattern;
}

-(java_util_regex_Matcher*)matcher___java_lang_CharSequence:(NSString *)chr
{
    NSLog(@"chr=%@", chr);
    NSCharacterSet* whitespace = [NSCharacterSet characterSetWithCharactersInString: @" \t\n\r\f\001\013\037"];
    NSString* trimmed = [chr stringByTrimmingCharactersInSet:whitespace];

    matcher = [[[java_util_regex_Matcher alloc] init] autorelease];
    
    matcher.matches = [regex matchesInString:trimmed
                                options:0
                                range:NSMakeRange(0, [trimmed length])];
    
    return matcher;
}

@end
