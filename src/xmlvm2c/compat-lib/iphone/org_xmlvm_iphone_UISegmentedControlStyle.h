#ifndef __ORG_XMLVM_IPHONE_UISEGMENTEDCONTROLSTYLE__
#define __ORG_XMLVM_IPHONE_UISEGMENTEDCONTROLSTYLE__

#include "xmlvm.h"
#include "java_lang_Object.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_java_lang_Object
#define XMLVM_FORWARD_DECL_java_lang_Object
XMLVM_FORWARD_DECL(java_lang_Object)
#endif
// Class declarations for org.xmlvm.iphone.UISegmentedControlStyle
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_UISegmentedControlStyle, 11)

extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UISegmentedControlStyle;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UISegmentedControlStyle_ARRAYTYPE;

//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UISegmentedControlStyle
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_UISegmentedControlStyle \
    __INSTANCE_FIELDS_java_lang_Object; \
    struct { \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UISegmentedControlStyle \
    } org_xmlvm_iphone_UISegmentedControlStyle

struct org_xmlvm_iphone_UISegmentedControlStyle {
    __TIB_DEFINITION_org_xmlvm_iphone_UISegmentedControlStyle* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_UISegmentedControlStyle;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UISegmentedControlStyle
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UISegmentedControlStyle
typedef struct org_xmlvm_iphone_UISegmentedControlStyle org_xmlvm_iphone_UISegmentedControlStyle;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_UISegmentedControlStyle 11

void __INIT_org_xmlvm_iphone_UISegmentedControlStyle();
void __DELETE_org_xmlvm_iphone_UISegmentedControlStyle(void* me, void* client_data);
JAVA_OBJECT __NEW_org_xmlvm_iphone_UISegmentedControlStyle();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_UISegmentedControlStyle();
JAVA_INT org_xmlvm_iphone_UISegmentedControlStyle_GET_Plain();
void org_xmlvm_iphone_UISegmentedControlStyle_PUT_Plain(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UISegmentedControlStyle_GET_Bordered();
void org_xmlvm_iphone_UISegmentedControlStyle_PUT_Bordered(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UISegmentedControlStyle_GET_Bar();
void org_xmlvm_iphone_UISegmentedControlStyle_PUT_Bar(JAVA_INT v);
void org_xmlvm_iphone_UISegmentedControlStyle___INIT___(JAVA_OBJECT me);

#endif
