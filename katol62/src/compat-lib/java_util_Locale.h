/* Copyright (c) 2002-2011 by XMLVM.org
 *
 * Project Info:  http://www.xmlvm.org
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

#import "xmlvm.h"
#import "java_lang_Object.h"

// java.util.Locale
//----------------------------------------------------------------------------
@interface java_util_Locale : java_lang_Object {
	java_lang_String *language;
	NSUInteger        languageHash;
	java_lang_String* country;
	NSUInteger        countryHash;
}

+ (void) initialize;
- (id) init;
- (void) __init_java_util_Locale___java_lang_String: (java_lang_String*) theLanguage;
- (void) __init_java_util_Locale___java_lang_String_java_lang_String:(java_lang_String*) theLanguage
                                                                    :(java_lang_String*) theCountry;
- (void) dealloc;
+ (java_util_Locale*) getDefault__;
- (int) equals___java_lang_Object:(java_lang_Object*) obj;
- (java_lang_String*) toString__;
- (java_lang_String*) getLanguage__;
- (java_lang_String*) getCountry__;
	
@end
