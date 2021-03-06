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

#import "org_xmlvm_iphone_UINavigationBarDelegate.h"


@implementation org_xmlvm_iphone_UINavigationBarDelegate 

- (void) org_xmlvm_iphone_UINavigationBarDelegate__
{    
}

- (BOOL)navigationBar:(UINavigationBar *)navigationBar shouldPushItem:(UINavigationItem *)item 
{
    return [self shouldPushItem___org_xmlvm_iphone_UINavigationBar_org_xmlvm_iphone_UINavigationItem:navigationBar :item];
}

- (void)navigationBar:(UINavigationBar *)navigationBar didPushItem:(UINavigationItem *)item 
{
    [self didPushItem___org_xmlvm_iphone_UINavigationBar_org_xmlvm_iphone_UINavigationItem:navigationBar :item];
}

- (BOOL)navigationBar:(UINavigationBar *)navigationBar shouldPopItem:(UINavigationItem *)item 
{
    return [self shouldPopItem___org_xmlvm_iphone_UINavigationBar_org_xmlvm_iphone_UINavigationItem:navigationBar :item];
}

- (void)navigationBar:(UINavigationBar *)navigationBar didPopItem:(UINavigationItem *)item 
{
    [self didPopItem___org_xmlvm_iphone_UINavigationBar_org_xmlvm_iphone_UINavigationItem:navigationBar :item];
}

- (int) shouldPushItem___org_xmlvm_iphone_UINavigationBar_org_xmlvm_iphone_UINavigationItem :(org_xmlvm_iphone_UINavigationBar*)bar :(org_xmlvm_iphone_UINavigationItem*)item 
{
	return YES;
}

- (void) didPushItem___org_xmlvm_iphone_UINavigationBar_org_xmlvm_iphone_UINavigationItem :(org_xmlvm_iphone_UINavigationBar*)bar :(org_xmlvm_iphone_UINavigationItem*)item 
{
}

- (int) shouldPopItem___org_xmlvm_iphone_UINavigationBar_org_xmlvm_iphone_UINavigationItem :(org_xmlvm_iphone_UINavigationBar*)bar :(org_xmlvm_iphone_UINavigationItem*)item 
{
	return YES;
}

- (void) didPopItem___org_xmlvm_iphone_UINavigationBar_org_xmlvm_iphone_UINavigationItem :(org_xmlvm_iphone_UINavigationBar*)bar :(org_xmlvm_iphone_UINavigationItem*)item 
{
}


@end
