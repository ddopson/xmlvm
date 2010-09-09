#ifndef __ORG_XMLVM_IPHONE_UIPICKERVIEWDATASOURCE__
#define __ORG_XMLVM_IPHONE_UIPICKERVIEWDATASOURCE__

#include "xmlvm.h"
#include "org_xmlvm_iphone_NSObject.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSObject
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_NSObject
XMLVM_FORWARD_DECL(org_xmlvm_iphone_NSObject)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIPickerView
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIPickerView
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIPickerView)
#endif
// Class declarations for org.xmlvm.iphone.UIPickerViewDataSource
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_UIPickerViewDataSource, 16)

//XMLVM_BEGIN_MEMBERS
#define __ADDITIONAL_INSTANCE_MEMBERS_org_xmlvm_iphone_UIPickerViewDataSource
//XMLVM_END_MEMBERS

#define __INSTANCE_MEMBERS_org_xmlvm_iphone_UIPickerViewDataSource \
    __INSTANCE_MEMBERS_org_xmlvm_iphone_NSObject; \
    struct { \
        __ADDITIONAL_INSTANCE_MEMBERS_org_xmlvm_iphone_UIPickerViewDataSource \
    } org_xmlvm_iphone_UIPickerViewDataSource

struct org_xmlvm_iphone_UIPickerViewDataSource {
    __CLASS_DEFINITION_org_xmlvm_iphone_UIPickerViewDataSource* __class;
    __INSTANCE_MEMBERS_org_xmlvm_iphone_UIPickerViewDataSource;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIPickerViewDataSource
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIPickerViewDataSource
typedef struct org_xmlvm_iphone_UIPickerViewDataSource org_xmlvm_iphone_UIPickerViewDataSource;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_UIPickerViewDataSource 16
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIPickerViewDataSource_numberOfComponentsInPickerView___org_xmlvm_iphone_UIPickerView 14
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIPickerViewDataSource_numberOfRowsInComponent___org_xmlvm_iphone_UIPickerView_int 15

void __INIT_org_xmlvm_iphone_UIPickerViewDataSource();
JAVA_OBJECT __NEW_org_xmlvm_iphone_UIPickerViewDataSource();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_UIPickerViewDataSource();
void org_xmlvm_iphone_UIPickerViewDataSource___INIT___(JAVA_OBJECT me);
// Vtable index: 14
JAVA_INT org_xmlvm_iphone_UIPickerViewDataSource_numberOfComponentsInPickerView___org_xmlvm_iphone_UIPickerView(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 15
JAVA_INT org_xmlvm_iphone_UIPickerViewDataSource_numberOfRowsInComponent___org_xmlvm_iphone_UIPickerView_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2);

#endif