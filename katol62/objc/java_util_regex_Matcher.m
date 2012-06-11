//
//  java_util_regex_Matcher.m
//  HelloResources
//
//  Created by apple on 08.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "java_util_regex_Matcher.h"

@implementation java_util_regex_Matcher

@synthesize charSequence, matches;

-(int)matches__
{
    int n = 0;
    for (NSTextCheckingResult *match in matches) {
        NSRange matchRange = [match range];
        NSRange firstHalfRange = [match rangeAtIndex:n];
        n++;
    }
    return [matches count];
}

@end
