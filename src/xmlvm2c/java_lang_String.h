/*
 * Copyright (c) 2004-2009 XMLVM --- An XML-based Programming Language
 * 
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any later
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 675 Mass
 * Ave, Cambridge, MA 02139, USA.
 * 
 * For more information, visit the XMLVM Home Page at http://www.xmlvm.org
 */

#ifndef __STRINGX_H__
#define __STRINGX_H__

#include "java_lang_Object.h"
//#include <cstdio.h>
//#include <cstring.h>


typedef struct {
    const char* str;
} java_lang_String;

inline JAVA_OBJECT __NEW_java_lang_String()
{
    java_lang_String* s = (java_lang_String*) malloc(sizeof(java_lang_String));
    s->str = "";
    return s;
}


inline void java_lang_String__INIT___char_ARRAYTYPE(java_lang_String* me, XMLVMArray* s)
{
	int i;
    me->str = (char*) malloc(s->length + 1);
    for (i = 0; i < s->length; i++) {
        ((char*) me->str)[i] = s->array.b[i];
    }
    ((char*) me->str)[s->length] = '\0';
}
  
/*
  static java_lang_String* valueOf___int(int i) {
    java_lang_String* s = new java_lang_String();
    s->str = new char[20];
    sprintf((char*) s->str, "%d", i);
    return s;
  }

  int length__() {
    return strlen(str);
  }


};
*/

#endif
