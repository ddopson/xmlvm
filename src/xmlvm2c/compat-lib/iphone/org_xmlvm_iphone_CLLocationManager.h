#ifndef __ORG_XMLVM_IPHONE_CLLOCATIONMANAGER__
#define __ORG_XMLVM_IPHONE_CLLOCATIONMANAGER__

#include "xmlvm.h"

// Preprocessor constants for interfaces:
// Implemented interfaces:
// Super Class:
#include "org_xmlvm_iphone_NSObject.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_java_lang_String
#define XMLVM_FORWARD_DECL_java_lang_String
XMLVM_FORWARD_DECL(java_lang_String)
#endif
#ifndef XMLVM_FORWARD_DECL_java_util_Set
#define XMLVM_FORWARD_DECL_java_util_Set
XMLVM_FORWARD_DECL(java_util_Set)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLHeading
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLHeading
XMLVM_FORWARD_DECL(org_xmlvm_iphone_CLHeading)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLLocation
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLLocation
XMLVM_FORWARD_DECL(org_xmlvm_iphone_CLLocation)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLLocationManagerDelegate
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLLocationManagerDelegate
XMLVM_FORWARD_DECL(org_xmlvm_iphone_CLLocationManagerDelegate)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLRegion
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLRegion
XMLVM_FORWARD_DECL(org_xmlvm_iphone_CLRegion)
#endif
// Class declarations for org.xmlvm.iphone.CLLocationManager
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_CLLocationManager, 7, XMLVM_ITABLE_SIZE_org_xmlvm_iphone_CLLocationManager)

extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_CLLocationManager;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_CLLocationManager_1ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_CLLocationManager_2ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_CLLocationManager_3ARRAY;
//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_CLLocationManager
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_CLLocationManager \
    __INSTANCE_FIELDS_org_xmlvm_iphone_NSObject; \
    struct { \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_CLLocationManager \
    } org_xmlvm_iphone_CLLocationManager

struct org_xmlvm_iphone_CLLocationManager {
    __TIB_DEFINITION_org_xmlvm_iphone_CLLocationManager* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_CLLocationManager;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLLocationManager
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_CLLocationManager
typedef struct org_xmlvm_iphone_CLLocationManager org_xmlvm_iphone_CLLocationManager;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_CLLocationManager 7

void __INIT_org_xmlvm_iphone_CLLocationManager();
void __INIT_IMPL_org_xmlvm_iphone_CLLocationManager();
void __DELETE_org_xmlvm_iphone_CLLocationManager(void* me, void* client_data);
void __INIT_INSTANCE_MEMBERS_org_xmlvm_iphone_CLLocationManager(JAVA_OBJECT me, int derivedClassWillRegisterFinalizer);
JAVA_OBJECT __NEW_org_xmlvm_iphone_CLLocationManager();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_CLLocationManager();
void org_xmlvm_iphone_CLLocationManager___INIT___(JAVA_OBJECT me);
JAVA_BOOLEAN org_xmlvm_iphone_CLLocationManager_locationServicesEnabled__();
JAVA_BOOLEAN org_xmlvm_iphone_CLLocationManager_significantLocationChangeMonitoringAvailable__();
JAVA_BOOLEAN org_xmlvm_iphone_CLLocationManager_headingAvailable__();
JAVA_BOOLEAN org_xmlvm_iphone_CLLocationManager_regionMonitoringAvailable__();
JAVA_BOOLEAN org_xmlvm_iphone_CLLocationManager_regionMonitoringEnabled__();
void org_xmlvm_iphone_CLLocationManager_startUpdatingLocation__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_stopUpdatingLocation__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_startMonitoringSignificantLocationChanges__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_stopMonitoringSignificantLocationChanges__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_startUpdatingHeading__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_stopUpdatingHeading__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_dismissHeadingCalibrationDisplay__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_startMonitoringForRegion___org_xmlvm_iphone_CLRegion_double(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_DOUBLE n2);
void org_xmlvm_iphone_CLLocationManager_stopMonitoringForRegion___org_xmlvm_iphone_CLRegion(JAVA_OBJECT me, JAVA_OBJECT n1);
JAVA_OBJECT org_xmlvm_iphone_CLLocationManager_getDelegate__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_setDelegate___org_xmlvm_iphone_CLLocationManagerDelegate(JAVA_OBJECT me, JAVA_OBJECT n1);
JAVA_DOUBLE org_xmlvm_iphone_CLLocationManager_getDesiredAccuracy__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_setDesiredAccuracy___double(JAVA_OBJECT me, JAVA_DOUBLE n1);
JAVA_DOUBLE org_xmlvm_iphone_CLLocationManager_getDistanceFilter__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_setDistanceFilter___double(JAVA_OBJECT me, JAVA_DOUBLE n1);
JAVA_DOUBLE org_xmlvm_iphone_CLLocationManager_getHeadingFilter__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_setHeadingFilter___double(JAVA_OBJECT me, JAVA_DOUBLE n1);
JAVA_INT org_xmlvm_iphone_CLLocationManager_getHeadingOrientation__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_setHeadingOrientation___int(JAVA_OBJECT me, JAVA_INT n1);
JAVA_OBJECT org_xmlvm_iphone_CLLocationManager_getMonitoredRegions__(JAVA_OBJECT me);
JAVA_DOUBLE org_xmlvm_iphone_CLLocationManager_getMaximumRegionMonitoringDistance__(JAVA_OBJECT me);
JAVA_OBJECT org_xmlvm_iphone_CLLocationManager_getHeading__(JAVA_OBJECT me);
JAVA_OBJECT org_xmlvm_iphone_CLLocationManager_getLocation__(JAVA_OBJECT me);
JAVA_OBJECT org_xmlvm_iphone_CLLocationManager_getPurpose__(JAVA_OBJECT me);
void org_xmlvm_iphone_CLLocationManager_setPurpose___java_lang_String(JAVA_OBJECT me, JAVA_OBJECT n1);

// Define a Macro for the method declarations of the Obj-C wrapper class so that subclass wrappers may easily include these too
#define XMLVM_OBJC_OVERRIDE_CLASS_DECLARATIONS_org_xmlvm_iphone_CLLocationManager \
XMLVM_OBJC_OVERRIDE_CLASS_DECLARATIONS_org_xmlvm_iphone_NSObject \

// Define a Macro for the entire contents of the Obj-C wrapper class
#define XMLVM_OBJC_OVERRIDE_CLASS_DEFINITIONS_org_xmlvm_iphone_CLLocationManager \
XMLVM_OBJC_OVERRIDE_CLASS_DEFINITIONS_org_xmlvm_iphone_NSObject \


#endif
