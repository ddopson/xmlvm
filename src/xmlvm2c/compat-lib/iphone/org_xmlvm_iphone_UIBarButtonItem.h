#ifndef __ORG_XMLVM_IPHONE_UIBARBUTTONITEM__
#define __ORG_XMLVM_IPHONE_UIBARBUTTONITEM__

#include "xmlvm.h"
#include "org_xmlvm_iphone_UIBarItem.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIView
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIView
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIView)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIImage
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIImage
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIImage)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIBarItem
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIBarItem
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIBarItem)
#endif
#ifndef XMLVM_FORWARD_DECL_java_util_Set
#define XMLVM_FORWARD_DECL_java_util_Set
XMLVM_FORWARD_DECL(java_util_Set)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIBarButtonItemDelegate
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIBarButtonItemDelegate
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIBarButtonItemDelegate)
#endif
#ifndef XMLVM_FORWARD_DECL_java_lang_String
#define XMLVM_FORWARD_DECL_java_lang_String
XMLVM_FORWARD_DECL(java_lang_String)
#endif
// Class declarations for org.xmlvm.iphone.UIBarButtonItem
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_UIBarButtonItem, 37)

extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIBarButtonItem;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIBarButtonItem_ARRAYTYPE;

//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIBarButtonItem
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_UIBarButtonItem \
    __INSTANCE_FIELDS_org_xmlvm_iphone_UIBarItem; \
    struct { \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIBarButtonItem \
    } org_xmlvm_iphone_UIBarButtonItem

struct org_xmlvm_iphone_UIBarButtonItem {
    __TIB_DEFINITION_org_xmlvm_iphone_UIBarButtonItem* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_UIBarButtonItem;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIBarButtonItem
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIBarButtonItem
typedef struct org_xmlvm_iphone_UIBarButtonItem org_xmlvm_iphone_UIBarButtonItem;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_UIBarButtonItem 37
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_setTitle___java_lang_String 23
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_getCustomView__ 27
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_setCustomView___org_xmlvm_iphone_UIView 28
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_getPossibleTitles__ 29
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_setPossibleTitles___java_util_Set 30
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_getStyle__ 31
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_setStyle___int 32
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_getTarget__ 33
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_setTarget___org_xmlvm_iphone_UIBarButtonItemDelegate 34
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_getWidth__ 35
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIBarButtonItem_setWidth___float 36

void __INIT_org_xmlvm_iphone_UIBarButtonItem();
void __DELETE_org_xmlvm_iphone_UIBarButtonItem(void* me, void* client_data);
void __INIT_INSTANCE_MEMBERS_org_xmlvm_iphone_UIBarButtonItem(JAVA_OBJECT me);
JAVA_OBJECT __NEW_org_xmlvm_iphone_UIBarButtonItem();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_UIBarButtonItem();
void org_xmlvm_iphone_UIBarButtonItem___INIT____int_org_xmlvm_iphone_UIBarButtonItemDelegate(JAVA_OBJECT me, JAVA_INT n1, JAVA_OBJECT n2);
void org_xmlvm_iphone_UIBarButtonItem___INIT____org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1);
void org_xmlvm_iphone_UIBarButtonItem___INIT____org_xmlvm_iphone_UIImage_int_org_xmlvm_iphone_UIBarButtonItemDelegate(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2, JAVA_OBJECT n3);
void org_xmlvm_iphone_UIBarButtonItem___INIT____java_lang_String_int_org_xmlvm_iphone_UIBarButtonItemDelegate(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2, JAVA_OBJECT n3);
// Vtable index: 23
void org_xmlvm_iphone_UIBarButtonItem_setTitle___java_lang_String(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 27
JAVA_OBJECT org_xmlvm_iphone_UIBarButtonItem_getCustomView__(JAVA_OBJECT me);
// Vtable index: 28
void org_xmlvm_iphone_UIBarButtonItem_setCustomView___org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 29
JAVA_OBJECT org_xmlvm_iphone_UIBarButtonItem_getPossibleTitles__(JAVA_OBJECT me);
// Vtable index: 30
void org_xmlvm_iphone_UIBarButtonItem_setPossibleTitles___java_util_Set(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 31
JAVA_INT org_xmlvm_iphone_UIBarButtonItem_getStyle__(JAVA_OBJECT me);
// Vtable index: 32
void org_xmlvm_iphone_UIBarButtonItem_setStyle___int(JAVA_OBJECT me, JAVA_INT n1);
// Vtable index: 33
JAVA_OBJECT org_xmlvm_iphone_UIBarButtonItem_getTarget__(JAVA_OBJECT me);
// Vtable index: 34
void org_xmlvm_iphone_UIBarButtonItem_setTarget___org_xmlvm_iphone_UIBarButtonItemDelegate(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 35
JAVA_FLOAT org_xmlvm_iphone_UIBarButtonItem_getWidth__(JAVA_OBJECT me);
// Vtable index: 36
void org_xmlvm_iphone_UIBarButtonItem_setWidth___float(JAVA_OBJECT me, JAVA_FLOAT n1);

#endif
