#ifndef __ORG_XMLVM_IPHONE_UICONTROLEVENT__
#define __ORG_XMLVM_IPHONE_UICONTROLEVENT__

#include "xmlvm.h"

// Preprocessor constants for interfaces:
// Implemented interfaces:
// Super Class:
#include "java_lang_Object.h"

// Circular references:
// Class declarations for org.xmlvm.iphone.UIControlEvent
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_UIControlEvent, 6, XMLVM_ITABLE_SIZE_org_xmlvm_iphone_UIControlEvent)

extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIControlEvent;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIControlEvent_1ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIControlEvent_2ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIControlEvent_3ARRAY;
//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIControlEvent
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_UIControlEvent \
    __INSTANCE_FIELDS_java_lang_Object; \
    struct { \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIControlEvent \
    } org_xmlvm_iphone_UIControlEvent

struct org_xmlvm_iphone_UIControlEvent {
    __TIB_DEFINITION_org_xmlvm_iphone_UIControlEvent* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_UIControlEvent;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIControlEvent
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIControlEvent
typedef struct org_xmlvm_iphone_UIControlEvent org_xmlvm_iphone_UIControlEvent;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_UIControlEvent 6

void __INIT_org_xmlvm_iphone_UIControlEvent();
void __INIT_IMPL_org_xmlvm_iphone_UIControlEvent();
void __DELETE_org_xmlvm_iphone_UIControlEvent(void* me, void* client_data);
void __INIT_INSTANCE_MEMBERS_org_xmlvm_iphone_UIControlEvent(JAVA_OBJECT me, int derivedClassWillRegisterFinalizer);
JAVA_OBJECT __NEW_org_xmlvm_iphone_UIControlEvent();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_UIControlEvent();
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_TouchDown();
void org_xmlvm_iphone_UIControlEvent_PUT_TouchDown(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_TouchDownRepeat();
void org_xmlvm_iphone_UIControlEvent_PUT_TouchDownRepeat(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_TouchDragInside();
void org_xmlvm_iphone_UIControlEvent_PUT_TouchDragInside(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_TouchDragOutside();
void org_xmlvm_iphone_UIControlEvent_PUT_TouchDragOutside(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_TouchDragEnter();
void org_xmlvm_iphone_UIControlEvent_PUT_TouchDragEnter(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_TouchDragExit();
void org_xmlvm_iphone_UIControlEvent_PUT_TouchDragExit(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_TouchUpInside();
void org_xmlvm_iphone_UIControlEvent_PUT_TouchUpInside(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_TouchUpOutside();
void org_xmlvm_iphone_UIControlEvent_PUT_TouchUpOutside(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_TouchCancel();
void org_xmlvm_iphone_UIControlEvent_PUT_TouchCancel(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_ValueChanged();
void org_xmlvm_iphone_UIControlEvent_PUT_ValueChanged(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_EditingDidBegin();
void org_xmlvm_iphone_UIControlEvent_PUT_EditingDidBegin(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_EditingChanged();
void org_xmlvm_iphone_UIControlEvent_PUT_EditingChanged(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_EditingDidEnd();
void org_xmlvm_iphone_UIControlEvent_PUT_EditingDidEnd(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_EditingDidEndOnExit();
void org_xmlvm_iphone_UIControlEvent_PUT_EditingDidEndOnExit(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_AllTouchEvents();
void org_xmlvm_iphone_UIControlEvent_PUT_AllTouchEvents(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_AllEditingEvents();
void org_xmlvm_iphone_UIControlEvent_PUT_AllEditingEvents(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_ApplicationReserved();
void org_xmlvm_iphone_UIControlEvent_PUT_ApplicationReserved(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_SystemReserved();
void org_xmlvm_iphone_UIControlEvent_PUT_SystemReserved(JAVA_INT v);
JAVA_INT org_xmlvm_iphone_UIControlEvent_GET_AllEvents();
void org_xmlvm_iphone_UIControlEvent_PUT_AllEvents(JAVA_INT v);

#endif
