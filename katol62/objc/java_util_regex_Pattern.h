//
//  java_util_regex_Pattern.h
//  HelloResources
//
//  Created by apple on 08.06.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "java_lang_Object.h"
#import "java_util_regex_Matcher.h"

@interface java_util_regex_Pattern : java_lang_Object
{
    NSRegularExpression *regex;
    java_util_regex_Matcher* matcher;
}

+(java_util_regex_Pattern*)compile___java_lang_String:(java_lang_String*)str;
-(java_util_regex_Matcher*)matcher___java_lang_CharSequence:(NSString *)chr;

@end
