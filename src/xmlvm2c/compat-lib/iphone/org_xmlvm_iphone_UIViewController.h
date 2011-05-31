#ifndef __ORG_XMLVM_IPHONE_UIVIEWCONTROLLER__
#define __ORG_XMLVM_IPHONE_UIVIEWCONTROLLER__

#include "xmlvm.h"
#include "org_xmlvm_iphone_UIResponder.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIView
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIView
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIView)
#endif
#ifndef XMLVM_FORWARD_DECL_java_util_ArrayList
#define XMLVM_FORWARD_DECL_java_util_ArrayList
XMLVM_FORWARD_DECL(java_util_ArrayList)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UITabBarController
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UITabBarController
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UITabBarController)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIResponder
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIResponder
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIResponder)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UITabBarItem
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UITabBarItem
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UITabBarItem)
#endif
#ifndef XMLVM_FORWARD_DECL_java_lang_String
#define XMLVM_FORWARD_DECL_java_lang_String
XMLVM_FORWARD_DECL(java_lang_String)
#endif
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIViewController
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIViewController
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIViewController)
#endif
// Class declarations for org.xmlvm.iphone.UIViewController
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_UIViewController, 11, XMLVM_ITABLE_SIZE_org_xmlvm_iphone_UIViewController)

extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIViewController;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIViewController_1ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIViewController_2ARRAY;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIViewController_3ARRAY;
//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIViewController

void org_xmlvm_iphone_UIViewController_INTERNAL_CONSTRUCTOR(JAVA_OBJECT me, NSObject* wrappedCObj);

//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_UIViewController \
    __INSTANCE_FIELDS_org_xmlvm_iphone_UIResponder; \
    struct { \
        JAVA_OBJECT pcontroller_; \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIViewController \
    } org_xmlvm_iphone_UIViewController

struct org_xmlvm_iphone_UIViewController {
    __TIB_DEFINITION_org_xmlvm_iphone_UIViewController* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_UIViewController;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIViewController
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIViewController
typedef struct org_xmlvm_iphone_UIViewController org_xmlvm_iphone_UIViewController;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_UIViewController 11
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIViewController_loadView__ 8
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIViewController_requestInternalFrame__ 9
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIViewController_updateViews__ 10

void __INIT_org_xmlvm_iphone_UIViewController();
void __INIT_IMPL_org_xmlvm_iphone_UIViewController();
void __DELETE_org_xmlvm_iphone_UIViewController(void* me, void* client_data);
void __INIT_INSTANCE_MEMBERS_org_xmlvm_iphone_UIViewController(JAVA_OBJECT me);
JAVA_OBJECT __NEW_org_xmlvm_iphone_UIViewController();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_UIViewController();
void org_xmlvm_iphone_UIViewController_dummyMethod___org_xmlvm_iphone_UITabBarController(JAVA_OBJECT me, JAVA_OBJECT n1);
void org_xmlvm_iphone_UIViewController___INIT___(JAVA_OBJECT me);
// Vtable index: 8
void org_xmlvm_iphone_UIViewController_loadView__(JAVA_OBJECT me);
JAVA_BOOLEAN org_xmlvm_iphone_UIViewController_isViewLoaded__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_viewDidLoad__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_viewDidUnload__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_viewWillAppearInternal___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1);
// Vtable index: 9
JAVA_OBJECT org_xmlvm_iphone_UIViewController_requestInternalFrame__(JAVA_OBJECT me);
// Vtable index: 10
void org_xmlvm_iphone_UIViewController_updateViews__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_viewWillAppear___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1);
void org_xmlvm_iphone_UIViewController_viewDidAppear___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1);
void org_xmlvm_iphone_UIViewController_viewWillDisappear___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1);
void org_xmlvm_iphone_UIViewController_viewDidDisappear___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1);
JAVA_BOOLEAN org_xmlvm_iphone_UIViewController_shouldAutorotateToInterfaceOrientation___int(JAVA_OBJECT me, JAVA_INT n1);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_rotatingHeaderView__(JAVA_OBJECT me);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_rotatingFooterView__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_willRotateToInterfaceOrientation___int_double(JAVA_OBJECT me, JAVA_INT n1, JAVA_DOUBLE n2);
void org_xmlvm_iphone_UIViewController_willAnimateRotationToInterfaceOrientation___int_double(JAVA_OBJECT me, JAVA_INT n1, JAVA_DOUBLE n2);
void org_xmlvm_iphone_UIViewController_didRotateFromInterfaceOrientation___int(JAVA_OBJECT me, JAVA_INT n1);
void org_xmlvm_iphone_UIViewController_willAnimateFirstHalfOfRotationToInterfaceOrientation___int_double(JAVA_OBJECT me, JAVA_INT n1, JAVA_DOUBLE n2);
void org_xmlvm_iphone_UIViewController_didAnimateFirstHalfOfRotationToInterfaceOrientation___int(JAVA_OBJECT me, JAVA_INT n1);
void org_xmlvm_iphone_UIViewController_willAnimateSecondHalfOfRotationFromInterfaceOrientation___int_double(JAVA_OBJECT me, JAVA_INT n1, JAVA_DOUBLE n2);
void org_xmlvm_iphone_UIViewController_didReceiveMemoryWarning__(JAVA_OBJECT me);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_getView__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_setView___org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_getTitle__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_setTitle___java_lang_String(JAVA_OBJECT me, JAVA_OBJECT n1);
JAVA_BOOLEAN org_xmlvm_iphone_UIViewController_wantsFullScreenLayout__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_setWantsFullScreenLayout___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1);
JAVA_INT org_xmlvm_iphone_UIViewController_getInterfaceOrientation__(JAVA_OBJECT me);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_getNavigationController__(JAVA_OBJECT me);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_getNavigationItem__(JAVA_OBJECT me);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_editButtonItem__(JAVA_OBJECT me);
JAVA_BOOLEAN org_xmlvm_iphone_UIViewController_isEditing__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_setEditing___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1);
void org_xmlvm_iphone_UIViewController_setEditing___boolean_boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1, JAVA_BOOLEAN n2);
JAVA_BOOLEAN org_xmlvm_iphone_UIViewController_hidesBottomBarWhenPushed__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_setHidesBottomBarWhenPushed___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_getTabBarController__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_setParentController___org_xmlvm_iphone_UIViewController(JAVA_OBJECT me, JAVA_OBJECT n1);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_getTabBarItem__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_setTabBarItem___org_xmlvm_iphone_UITabBarItem(JAVA_OBJECT me, JAVA_OBJECT n1);
JAVA_OBJECT org_xmlvm_iphone_UIViewController_getToolbarItems__(JAVA_OBJECT me);
void org_xmlvm_iphone_UIViewController_setToolbarItems___java_util_ArrayList(JAVA_OBJECT me, JAVA_OBJECT n1);
void org_xmlvm_iphone_UIViewController_setToolbarItems___java_util_ArrayList_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2);
void org_xmlvm_iphone_UIViewController_presentModalViewController___org_xmlvm_iphone_UIViewController_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2);
void org_xmlvm_iphone_UIViewController_dismissModalViewControllerAnimated___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1);

#endif
