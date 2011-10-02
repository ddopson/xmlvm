#ifndef __ORG_XMLVM_IPHONE_ADBANNERVIEWDELEGATE__
#define __ORG_XMLVM_IPHONE_ADBANNERVIEWDELEGATE__

#include "xmlvm.h"

// Preprocessor constants for interfaces:
// Implemented interfaces:
// Super Class:
#include "org_xmlvm_iphone_NSObject.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_ADBannerView
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_ADBannerView
XMLVM_FORWARD_DECL(org_xmlvm_iphone_ADBannerView)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSError
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSError
XMLVM_FORWARD_DECL(org_xmlvm_iphone_NSError)
#endif
// Class declarations for org.xmlvm.iphone.ADBannerViewDelegate
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_ADBannerViewDelegate, 7, XMLVM_ITABLE_SIZE_org_xmlvm_iphone_ADBannerViewDelegate)

extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_ADBannerViewDelegate;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_ADBannerViewDelegate_1ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_ADBannerViewDelegate_2ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_ADBannerViewDelegate_3ARRAY;
//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_ADBannerViewDelegate
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_ADBannerViewDelegate \
    __INSTANCE_FIELDS_org_xmlvm_iphone_NSObject; \
    struct { \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_ADBannerViewDelegate \
    } org_xmlvm_iphone_ADBannerViewDelegate

struct org_xmlvm_iphone_ADBannerViewDelegate {
    __TIB_DEFINITION_org_xmlvm_iphone_ADBannerViewDelegate* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_ADBannerViewDelegate;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_ADBannerViewDelegate
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_ADBannerViewDelegate
typedef struct org_xmlvm_iphone_ADBannerViewDelegate org_xmlvm_iphone_ADBannerViewDelegate;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_ADBannerViewDelegate 7

void __INIT_org_xmlvm_iphone_ADBannerViewDelegate();
void __INIT_IMPL_org_xmlvm_iphone_ADBannerViewDelegate();
void __DELETE_org_xmlvm_iphone_ADBannerViewDelegate(void* me, void* client_data);
void __INIT_INSTANCE_MEMBERS_org_xmlvm_iphone_ADBannerViewDelegate(JAVA_OBJECT me, int derivedClassWillRegisterFinalizer);
JAVA_OBJECT __NEW_org_xmlvm_iphone_ADBannerViewDelegate();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_ADBannerViewDelegate();
void org_xmlvm_iphone_ADBannerViewDelegate___INIT___(JAVA_OBJECT me);
void org_xmlvm_iphone_ADBannerViewDelegate_didLoadAd___org_xmlvm_iphone_ADBannerView(JAVA_OBJECT me, JAVA_OBJECT n1);
JAVA_BOOLEAN org_xmlvm_iphone_ADBannerViewDelegate_shouldBegin___org_xmlvm_iphone_ADBannerView_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2);
void org_xmlvm_iphone_ADBannerViewDelegate_didFailToReceiveAdWithError___org_xmlvm_iphone_ADBannerView_org_xmlvm_iphone_NSError(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2);
void org_xmlvm_iphone_ADBannerViewDelegate_didFinish___org_xmlvm_iphone_ADBannerView(JAVA_OBJECT me, JAVA_OBJECT n1);

#endif
