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

#import "org_xmlvm_iphone_UIToolbar.h"



@implementation UIToolbar (cat_org_xmlvm_iphone_UIToolbar)

- (void) __init_org_xmlvm_iphone_UIToolbar__ {
}

- (void) __init_org_xmlvm_iphone_UIToolbar___org_xmlvm_iphone_CGRect :(org_xmlvm_iphone_CGRect*)n1 {
	[self setFrame:[n1 getCGRect]];
}

- (int) getBarStyle__ {
	return self.barStyle;
}

- (void) setBarStyle___int :(int)n1 {
	self.barStyle = n1;
}

- (org_xmlvm_iphone_UIColor*) getTintColor__ {
	return_XMLVM(tintColor)
}

- (void) setTintColor___org_xmlvm_iphone_UIColor :(org_xmlvm_iphone_UIColor*)n1 {
	self.tintColor = n1;
}

- (int) isTranslucent__ {
	return self.translucent;
}

- (void) setTranslucent___boolean :(int)n1 {
	self.translucent = n1;
}

- (java_util_ArrayList*) getItems__ {
	return_XMLVM(items)
}

- (void) setItems___java_util_ArrayList :(java_util_ArrayList*)itms {
	self.items = itms;
}

- (void) setItems___java_util_ArrayList_boolean :(java_util_ArrayList*)itms :(int)anim {
	[self setItems:itms animated:anim];
}


@end
