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


#import "org_xmlvm_iphone_NSXMLParser.h"

// NSXMLParser
//----------------------------------------------------------------------------
@implementation NSXMLParser (cat_NSXMLParser)

- (void) __init_org_xmlvm_iphone_NSXMLParser___org_xmlvm_iphone_NSData: (org_xmlvm_iphone_NSData*) data
{
	[self initWithData: data];
}

- (void) setDelegate___org_xmlvm_iphone_NSXMLParserDelegate: (org_xmlvm_iphone_NSXMLParserDelegate*) delegate
{
	[self setDelegate: delegate];
}

- (void) setShouldProcessNamespaces___boolean: (int) flag
{
	[self setShouldProcessNamespaces: flag];
}

- (void) setShouldReportNamespacePrefixes___boolean: (int) flag
{
	[self setShouldReportNamespacePrefixes: flag];
}

- (BOOL) shouldReportNamespacePrefixes__
{
	return [self shouldReportNamespacePrefixes];
}

- (BOOL) parse__
{
	return [self parse];
}
@end

