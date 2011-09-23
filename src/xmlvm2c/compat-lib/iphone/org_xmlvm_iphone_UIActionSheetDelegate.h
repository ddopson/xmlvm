#ifndef __ORG_XMLVM_IPHONE_UIACTIONSHEETDELEGATE__
#define __ORG_XMLVM_IPHONE_UIACTIONSHEETDELEGATE__

#include "xmlvm.h"
#include "org_xmlvm_iphone_NSObject.h"

// Preprocessor constants for interfaces:

// Circular references:
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIActionSheet
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIActionSheet
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIActionSheet)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSObject
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSObject
XMLVM_FORWARD_DECL(org_xmlvm_iphone_NSObject)
#endif
// Class declarations for org.xmlvm.iphone.UIActionSheetDelegate
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_UIActionSheetDelegate, 7, XMLVM_ITABLE_SIZE_org_xmlvm_iphone_UIActionSheetDelegate)

extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIActionSheetDelegate;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIActionSheetDelegate_1ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIActionSheetDelegate_2ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIActionSheetDelegate_3ARRAY;
//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIActionSheetDelegate
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_UIActionSheetDelegate \
    __INSTANCE_FIELDS_org_xmlvm_iphone_NSObject; \
    struct { \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIActionSheetDelegate \
    } org_xmlvm_iphone_UIActionSheetDelegate

struct org_xmlvm_iphone_UIActionSheetDelegate {
    __TIB_DEFINITION_org_xmlvm_iphone_UIActionSheetDelegate* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_UIActionSheetDelegate;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIActionSheetDelegate
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIActionSheetDelegate
typedef struct org_xmlvm_iphone_UIActionSheetDelegate org_xmlvm_iphone_UIActionSheetDelegate;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_UIActionSheetDelegate 7

void __INIT_org_xmlvm_iphone_UIActionSheetDelegate();
void __INIT_IMPL_org_xmlvm_iphone_UIActionSheetDelegate();
void __DELETE_org_xmlvm_iphone_UIActionSheetDelegate(void* me, void* client_data);
void __INIT_INSTANCE_MEMBERS_org_xmlvm_iphone_UIActionSheetDelegate(JAVA_OBJECT me, int derivedClassWillRegisterFinalizer);
JAVA_OBJECT __NEW_org_xmlvm_iphone_UIActionSheetDelegate();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_UIActionSheetDelegate();
void org_xmlvm_iphone_UIActionSheetDelegate___INIT___(JAVA_OBJECT me);
void org_xmlvm_iphone_UIActionSheetDelegate_clickedButtonAtIndex___org_xmlvm_iphone_UIActionSheet_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2);
void org_xmlvm_iphone_UIActionSheetDelegate_willPresentActionSheet___org_xmlvm_iphone_UIActionSheet(JAVA_OBJECT me, JAVA_OBJECT n1);
void org_xmlvm_iphone_UIActionSheetDelegate_didPresentActionSheet___org_xmlvm_iphone_UIActionSheet(JAVA_OBJECT me, JAVA_OBJECT n1);
void org_xmlvm_iphone_UIActionSheetDelegate_willDismissWithButtonIndex___org_xmlvm_iphone_UIActionSheet_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2);
void org_xmlvm_iphone_UIActionSheetDelegate_didDismissWithButtonIndex___org_xmlvm_iphone_UIActionSheet_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2);
void org_xmlvm_iphone_UIActionSheetDelegate_actionSheetCancel___org_xmlvm_iphone_UIActionSheet(JAVA_OBJECT me, JAVA_OBJECT n1);

#endif
