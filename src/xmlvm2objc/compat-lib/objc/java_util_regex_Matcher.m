//
//  java_util_regex_Matcher.m
//  HelloResources
//

#import "xmlvm.h"
#import "java_util_regex_Matcher.h"

@implementation java_util_regex_Matcher

@synthesize charSequence, matches;

- (JAVA_BOOLEAN) matches__
{
    return [matches count] > 0;
}

@end
