#ifndef __ORG_XMLVM_IPHONE_NSERRORHOLDER__
#define __ORG_XMLVM_IPHONE_NSERRORHOLDER__

#include "xmlvm.h"
#include "org_xmlvm_iphone_NSObject.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSObject
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSObject
XMLVM_FORWARD_DECL(org_xmlvm_iphone_NSObject)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSError
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSError
XMLVM_FORWARD_DECL(org_xmlvm_iphone_NSError)
#endif
#ifndef XMLVM_FORWARD_DECL_java_lang_String
#define XMLVM_FORWARD_DECL_java_lang_String
XMLVM_FORWARD_DECL(java_lang_String)
#endif
// Class declarations for org.xmlvm.iphone.NSErrorHolder
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_NSErrorHolder, 15)

//XMLVM_BEGIN_FIELDS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_NSErrorHolder
//XMLVM_END_FIELDS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_NSErrorHolder \
    __INSTANCE_FIELDS_org_xmlvm_iphone_NSObject; \
    struct { \
        JAVA_OBJECT error_; \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_NSErrorHolder \
    } org_xmlvm_iphone_NSErrorHolder

struct org_xmlvm_iphone_NSErrorHolder {
    __TIB_DEFINITION_org_xmlvm_iphone_NSErrorHolder* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_NSErrorHolder;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSErrorHolder
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSErrorHolder
typedef struct org_xmlvm_iphone_NSErrorHolder org_xmlvm_iphone_NSErrorHolder;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_NSErrorHolder 15
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_NSErrorHolder_description__ 14

void __INIT_org_xmlvm_iphone_NSErrorHolder();
JAVA_OBJECT __NEW_org_xmlvm_iphone_NSErrorHolder();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_NSErrorHolder();
void org_xmlvm_iphone_NSErrorHolder___INIT___(JAVA_OBJECT me);
// Vtable index: 14
JAVA_OBJECT org_xmlvm_iphone_NSErrorHolder_description__(JAVA_OBJECT me);

#endif
