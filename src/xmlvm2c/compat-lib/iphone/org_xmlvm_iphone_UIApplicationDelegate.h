#ifndef __ORG_XMLVM_IPHONE_UIAPPLICATIONDELEGATE__
#define __ORG_XMLVM_IPHONE_UIAPPLICATIONDELEGATE__

#include "xmlvm.h"
#include "org_xmlvm_iphone_NSObject.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSObject
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSObject
XMLVM_FORWARD_DECL(org_xmlvm_iphone_NSObject)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIApplication
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIApplication
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIApplication)
#endif
// Class declarations for org.xmlvm.iphone.UIApplicationDelegate
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_UIApplicationDelegate, 19)

extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIApplicationDelegate;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIApplicationDelegate_ARRAYTYPE;

//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIApplicationDelegate
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_UIApplicationDelegate \
    __INSTANCE_FIELDS_org_xmlvm_iphone_NSObject; \
    struct { \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIApplicationDelegate \
    } org_xmlvm_iphone_UIApplicationDelegate

struct org_xmlvm_iphone_UIApplicationDelegate {
    __TIB_DEFINITION_org_xmlvm_iphone_UIApplicationDelegate* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_UIApplicationDelegate;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIApplicationDelegate
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIApplicationDelegate
typedef struct org_xmlvm_iphone_UIApplicationDelegate org_xmlvm_iphone_UIApplicationDelegate;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_UIApplicationDelegate 19
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIApplicationDelegate_applicationDidFinishLaunching___org_xmlvm_iphone_UIApplication 14
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIApplicationDelegate_applicationWillTerminate___org_xmlvm_iphone_UIApplication 15
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIApplicationDelegate_applicationDidBecomeActive___org_xmlvm_iphone_UIApplication 16
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIApplicationDelegate_applicationWillResignActive___org_xmlvm_iphone_UIApplication 17
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIApplicationDelegate_applicationDidReceiveMemoryWarning___org_xmlvm_iphone_UIApplication 18

void __INIT_org_xmlvm_iphone_UIApplicationDelegate();
void __INIT_IMPL_org_xmlvm_iphone_UIApplicationDelegate();
void __DELETE_org_xmlvm_iphone_UIApplicationDelegate(void* me, void* client_data);
void __INIT_INSTANCE_MEMBERS_org_xmlvm_iphone_UIApplicationDelegate(JAVA_OBJECT me);
JAVA_OBJECT __NEW_org_xmlvm_iphone_UIApplicationDelegate();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_UIApplicationDelegate();
void org_xmlvm_iphone_UIApplicationDelegate___INIT___(JAVA_OBJECT me);
// Vtable index: 14
void org_xmlvm_iphone_UIApplicationDelegate_applicationDidFinishLaunching___org_xmlvm_iphone_UIApplication(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 15
void org_xmlvm_iphone_UIApplicationDelegate_applicationWillTerminate___org_xmlvm_iphone_UIApplication(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 16
void org_xmlvm_iphone_UIApplicationDelegate_applicationDidBecomeActive___org_xmlvm_iphone_UIApplication(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 17
void org_xmlvm_iphone_UIApplicationDelegate_applicationWillResignActive___org_xmlvm_iphone_UIApplication(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 18
void org_xmlvm_iphone_UIApplicationDelegate_applicationDidReceiveMemoryWarning___org_xmlvm_iphone_UIApplication(JAVA_OBJECT me, JAVA_OBJECT n1);

#endif
