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

+(java_util_regex_Pattern*)compile___java_lang_String: (java_lang_String*)str
{
    java_util_regex_Pattern* pattern = [[[java_util_regex_Pattern alloc] init] autorelease];
    NSError *error = NULL;
    
    // is this needed?
    str = [NSString stringWithFormat:@"^%@$", str];
    
    pattern->regex = [NSRegularExpression regularExpressionWithPattern: (NSString*)str
                                                                options:0
                                                                error:&error];
    return pattern;
}

-(java_util_regex_Matcher*)matcher___java_lang_CharSequence: (NSString *)str
{
    java_util_regex_Matcher* matcher = [[[java_util_regex_Matcher alloc] init] autorelease];
    
    matcher.matches = [regex matchesInString: str
                                options: 0
                                range: NSMakeRange(0, [str length])];
    
    return matcher;
}

@end
