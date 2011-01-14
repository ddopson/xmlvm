#include "org_xmlvm_iphone_CGPoint.h"
#include "org_xmlvm_iphone_UIWindow.h"
#include "org_xmlvm_iphone_CGAffineTransform.h"
#include "org_xmlvm_iphone_CALayer.h"
#include "java_util_List.h"
#include "org_xmlvm_iphone_CGSize.h"
#include "org_xmlvm_iphone_CGRect.h"
#include "org_xmlvm_iphone_UIColor.h"

#include "org_xmlvm_iphone_UIView.h"

__TIB_DEFINITION_org_xmlvm_iphone_UIView __TIB_org_xmlvm_iphone_UIView = {
    0, // classInitialized
    "org.xmlvm.iphone.UIView", // className
    (__TIB_DEFINITION_TEMPLATE*) &__TIB_org_xmlvm_iphone_UIResponder, // extends
};

JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIView;
//TODO _ARRAYTYPE not initialized
JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIView_ARRAYTYPE;

//XMLVM_BEGIN_IMPLEMENTATION

/********************************************************************************
 * README: There are several places marked with README throughout this file that
 *         contain some explanation on how to implement C wrappers.
 *
 * This file serves as a sample on how to implement wrappers for the C backend.
 * The skeleton for this file was automatically generated by XMLVM via
 * --target=gen-c-wrappers. The Java class org.xmlvm.iphone.UIView was used as
 * a template to create this file. The gen-c-wrapper option creates the 'boiler-
 * plate' code for the C-version of class UIView (i.e., class definition, vtable
 * definition, etc). It needs to be re-generated whenever the API of the Java class
 * org.xmlvm.iphone.UIView changes (this is actually important! If you don't do that,
 * the vtables used by an application using UIView and the ones computed in this
 * file will be inconsistent). To help with the re-generation of the C wrappers,
 * you can invoke the ant-target "ant gen-c-wrappers" of the toplevel build.xml.
 *
 * When XMLVM generates the wrappers, it will also insert special comments that
 * begin with XMLVM_BEGIN_* and XMLVM_END_*. These are special markers that
 * denote places where the programmer may inject manually written code. These
 * code-injection points are placed in strategic places where the programmer may
 * want to insert code. When the wrappers are re-generated, the manually written
 * code will automatically be copied over so that an update will not override
 * injected code.
 *
 * The basic idea of these wrappers is that they are skeleton classes implemented
 * in C that wrap Objective-C classes. The first injection point is the one you
 * are looking at right now. It is marked by XMLVM_BEGIN_IMPLEMENTATION and
 * is defined on global level where we can define some global definitions. We need
 * to be able to intercept the drawRect: message of the Objective-C class UIView in
 * order to delegate this to the C code. We do this by defining an Objective-C
 * class called UIViewWrapper:
 */

#import <UIKit/UIView.h>
#import <UIKit/UIViewController.h>
#include "xmlvm-util.h"


@interface UIViewWrapper : UIView 
{
	// A pointer back to the C object
	org_xmlvm_iphone_UIView *wrappedCObj;
}
- (void) drawRect:(CGRect) rect;
- (void) setWrappedCObj: (org_xmlvm_iphone_UIView*) obj;
@end

@implementation UIViewWrapper : UIView

- (void) setWrappedCObj: (org_xmlvm_iphone_UIView*) obj;
{
	self->wrappedCObj = obj;
}

- (void) drawRect:(CGRect) rect
{
	// Convert the Objective-C CGRect to a C CGRect
	org_xmlvm_iphone_CGRect* r = __NEW_org_xmlvm_iphone_CGRect();
	org_xmlvm_iphone_CGRect___INIT____float_float_float_float(r, rect.origin.x, rect.origin.y , rect.size.width, rect.size.height);
	
	// Get the function pointer to method drawRect by accessing the vtable of the C object
	Func_VOO drawRect = 
	self->wrappedCObj->tib->vtable[XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIView_drawRect___org_xmlvm_iphone_CGRect];
    drawRect(self->wrappedCObj, r);
}

@end

/*
 * README: All public constructors of org.xmlvm.iphone.UIView also instantiate
 * Objective-C class UIView. The problem arises when a class such as UILabel is
 * derived from UIView. The constructor of org.xmlvm.iphone.UILabel itself instantiates
 * a UILabel. At the same time UILabel needs to call a base-class constructor (UIView's
 * constructor in this case). We need a constructor for UIView that does not create its
 * Objective-C counterpart since this was already done in the derived class UILabel. For
 * this reason we introduce a new constructor that may only be used internally (i.e.,
 * it is not accessible from Java).
 */
void org_xmlvm_iphone_UIView_INTERNAL_CONSTRUCTOR(JAVA_OBJECT me, NSObject* wrappedCObj)
{
    org_xmlvm_iphone_UIResponder_INTERNAL_CONSTRUCTOR(me, wrappedCObj);
    org_xmlvm_iphone_UIView* thiz = (org_xmlvm_iphone_UIView*) me;
    thiz->fields.org_xmlvm_iphone_UIView.subviews = XMLVMUtil_NEW_ArrayList();
}

//XMLVM_END_IMPLEMENTATION


static XMLVM_FIELD_REFLECTION_DATA __field_reflection_data[] = {
};

void __INIT_org_xmlvm_iphone_UIView()
{
    __TIB_org_xmlvm_iphone_UIView.classInitialized = 1;
    // Initialize base class if necessary
    if (!__TIB_org_xmlvm_iphone_UIResponder.classInitialized) __INIT_org_xmlvm_iphone_UIResponder();
    __TIB_org_xmlvm_iphone_UIView.newInstanceFunc = __NEW_INSTANCE_org_xmlvm_iphone_UIView;
    // Copy vtable from base class
    XMLVM_MEMCPY(__TIB_org_xmlvm_iphone_UIView.vtable, __TIB_org_xmlvm_iphone_UIResponder.vtable, sizeof(__TIB_org_xmlvm_iphone_UIResponder.vtable));
    // Initialize vtable for this class
    __TIB_org_xmlvm_iphone_UIView.vtable[21] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setFrame___org_xmlvm_iphone_CGRect;
    __TIB_org_xmlvm_iphone_UIView.vtable[22] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getFrame__;
    __TIB_org_xmlvm_iphone_UIView.vtable[23] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getCenter__;
    __TIB_org_xmlvm_iphone_UIView.vtable[24] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setCenter___org_xmlvm_iphone_CGPoint;
    __TIB_org_xmlvm_iphone_UIView.vtable[25] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setLocation___float_float;
    __TIB_org_xmlvm_iphone_UIView.vtable[26] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setSize___float_float;
    __TIB_org_xmlvm_iphone_UIView.vtable[27] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_addSubview___org_xmlvm_iphone_UIView;
    __TIB_org_xmlvm_iphone_UIView.vtable[28] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_sendSubviewToBack___org_xmlvm_iphone_UIView;
    __TIB_org_xmlvm_iphone_UIView.vtable[29] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_insertSubview___org_xmlvm_iphone_UIView_int;
    __TIB_org_xmlvm_iphone_UIView.vtable[30] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_bringSubviewToFront___org_xmlvm_iphone_UIView;
    __TIB_org_xmlvm_iphone_UIView.vtable[31] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_removeFromSuperview__;
    __TIB_org_xmlvm_iphone_UIView.vtable[32] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getSubviews__;
    __TIB_org_xmlvm_iphone_UIView.vtable[33] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getSuperview__;
    __TIB_org_xmlvm_iphone_UIView.vtable[34] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getWindow__;
    __TIB_org_xmlvm_iphone_UIView.vtable[35] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_layoutSubviews__;
    __TIB_org_xmlvm_iphone_UIView.vtable[36] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getBounds__;
    __TIB_org_xmlvm_iphone_UIView.vtable[37] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setBounds___org_xmlvm_iphone_CGRect;
    __TIB_org_xmlvm_iphone_UIView.vtable[38] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setNeedsDisplay__;
    __TIB_org_xmlvm_iphone_UIView.vtable[39] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setOpaque___boolean;
    __TIB_org_xmlvm_iphone_UIView.vtable[40] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_isOpaque__;
    __TIB_org_xmlvm_iphone_UIView.vtable[41] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setClearsContextBeforeDrawing___boolean;
    __TIB_org_xmlvm_iphone_UIView.vtable[42] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getBackgroundColor__;
    __TIB_org_xmlvm_iphone_UIView.vtable[43] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setBackgroundColor___org_xmlvm_iphone_UIColor;
    __TIB_org_xmlvm_iphone_UIView.vtable[44] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getAlpha__;
    __TIB_org_xmlvm_iphone_UIView.vtable[45] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setAlpha___float;
    __TIB_org_xmlvm_iphone_UIView.vtable[46] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_isHidden__;
    __TIB_org_xmlvm_iphone_UIView.vtable[47] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setHidden___boolean;
    __TIB_org_xmlvm_iphone_UIView.vtable[48] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setContentMode___int;
    __TIB_org_xmlvm_iphone_UIView.vtable[49] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getContentMode__;
    __TIB_org_xmlvm_iphone_UIView.vtable[50] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_isUserInteractionEnabled__;
    __TIB_org_xmlvm_iphone_UIView.vtable[51] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setUserInteractionEnabled___boolean;
    __TIB_org_xmlvm_iphone_UIView.vtable[52] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getTransform__;
    __TIB_org_xmlvm_iphone_UIView.vtable[53] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setTransform___org_xmlvm_iphone_CGAffineTransform;
    __TIB_org_xmlvm_iphone_UIView.vtable[54] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_clipsToBounds__;
    __TIB_org_xmlvm_iphone_UIView.vtable[55] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setClipsToBounds___boolean;
    __TIB_org_xmlvm_iphone_UIView.vtable[56] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getTag__;
    __TIB_org_xmlvm_iphone_UIView.vtable[57] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setTag___int;
    __TIB_org_xmlvm_iphone_UIView.vtable[58] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_convertPointToView___org_xmlvm_iphone_CGPoint_org_xmlvm_iphone_UIView;
    __TIB_org_xmlvm_iphone_UIView.vtable[59] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_convertPointFromView___org_xmlvm_iphone_CGPoint_org_xmlvm_iphone_UIView;
    __TIB_org_xmlvm_iphone_UIView.vtable[60] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_convertRectToView___org_xmlvm_iphone_CGRect_org_xmlvm_iphone_UIView;
    __TIB_org_xmlvm_iphone_UIView.vtable[61] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_convertRectFromView___org_xmlvm_iphone_CGRect_org_xmlvm_iphone_UIView;
    __TIB_org_xmlvm_iphone_UIView.vtable[62] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getLayer__;
    __TIB_org_xmlvm_iphone_UIView.vtable[63] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_getAutoresizingMask__;
    __TIB_org_xmlvm_iphone_UIView.vtable[64] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setAutoresizingMask___int;
    __TIB_org_xmlvm_iphone_UIView.vtable[65] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_isAutoresizesSubviews__;
    __TIB_org_xmlvm_iphone_UIView.vtable[66] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_setAutoresizesSubviews___boolean;
    __TIB_org_xmlvm_iphone_UIView.vtable[67] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_sizeThatFits___org_xmlvm_iphone_CGSize;
    __TIB_org_xmlvm_iphone_UIView.vtable[68] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_sizeToFit__;
    __TIB_org_xmlvm_iphone_UIView.vtable[69] = (VTABLE_PTR) &org_xmlvm_iphone_UIView_drawRect___org_xmlvm_iphone_CGRect;
    // Initialize vtable for implementing interfaces
    __TIB_org_xmlvm_iphone_UIView.numImplementedInterfaces = 0;
    __TIB_org_xmlvm_iphone_UIView.implementedInterfaces = (__TIB_DEFINITION_TEMPLATE* (*)[1]) XMLVM_MALLOC(sizeof(__TIB_DEFINITION_TEMPLATE*) * 0);

    __TIB_org_xmlvm_iphone_UIView.declaredFields = &__field_reflection_data[0];
    __TIB_org_xmlvm_iphone_UIView.numDeclaredFields = sizeof(__field_reflection_data) / sizeof(XMLVM_FIELD_REFLECTION_DATA);
    __CLASS_org_xmlvm_iphone_UIView = __NEW_XMLVMClass(&__TIB_org_xmlvm_iphone_UIView);
    __TIB_org_xmlvm_iphone_UIView.clazz = __CLASS_org_xmlvm_iphone_UIView;

    //XMLVM_BEGIN_WRAPPER[__INIT_org_xmlvm_iphone_UIView]
    //XMLVM_END_WRAPPER
}

void __DELETE_org_xmlvm_iphone_UIView(void* me, void* client_data)
{
    //XMLVM_BEGIN_WRAPPER[__DELETE_org_xmlvm_iphone_UIView]
	
	/*********************************************************************************************
	 * README: each class has a generated __DELETE_* method where some cleanup can be done.
	 * This method will be called by the garbage collector whenever the object is deleted.
	 * Since the C version of class UIView is a wrapper for the Objective-C class UIView,
	 * we need to make sure the wrapped Objective-C object gets properly deleted by sending
	 * it the 'release' message.
	 */
	org_xmlvm_iphone_UIView *thiz = me;
	[((UIView*) thiz->fields.org_xmlvm_iphone_NSObject.wrappedObjCObj) release];
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT __NEW_org_xmlvm_iphone_UIView()
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    org_xmlvm_iphone_UIView* me = (org_xmlvm_iphone_UIView*) XMLVM_MALLOC(sizeof(org_xmlvm_iphone_UIView));
    me->tib = &__TIB_org_xmlvm_iphone_UIView;
    //XMLVM_BEGIN_WRAPPER[__NEW_org_xmlvm_iphone_UIView]
    me->fields.org_xmlvm_iphone_UIView.subviews = XMLVMUtil_NEW_ArrayList();
	/*********************************************************************************************
	 * README: Ordinarily the garbage collector will just silently release the memory of
	 * garbage collected objects. If some cleanup needs to be done before this happens, we
	 * need to register a so-called finalizer for this object with the garbage collector.
	 * Since the finalization mechanism is relatively expensive, we only do it for those
	 * objects for which this is necessary. The finalizer to be invoked should always be
	 * the respective __DELETE_* function.
	 */
	// Tell the GC to finalize us
    XMLVM_FINALIZE(me, __DELETE_org_xmlvm_iphone_UIView);
    //XMLVM_END_WRAPPER
    return me;
}

JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_UIView()
{
    JAVA_OBJECT me = JAVA_NULL;
    me = __NEW_org_xmlvm_iphone_UIView();
    org_xmlvm_iphone_UIView___INIT___(me);
    return me;
}

void org_xmlvm_iphone_UIView___INIT____org_xmlvm_iphone_CGRect(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView___INIT____org_xmlvm_iphone_CGRect]
	
	/*********************************************************************************************
	 * README: All C functions whose name contains the string __INIT__ are constructors. Since
	 * the C version of class UIView is merely a wrapper for the Objective-C counterpart, what
	 * needs to happen in the constructor is to create the Objective-C instance via the regular
	 * alloc/init messages and then save a pointer to the newly created Objective-C object.
	 * This pointer is saved in a field inherited from class NSObject called wrappedObjCObj
	 * (wrapped Objective-C Object). Note that because we need to intercept UIView.drawRect,
	 * we don't instantiate a UIView directly, but UIViewWrapper as defined earlier in this
	 * file.
	 */
	UIViewWrapper* obj = [[UIViewWrapper alloc] initWithFrame: toCGRect(n1)];
	[obj setWrappedCObj:me];
    org_xmlvm_iphone_UIResponder_INTERNAL_CONSTRUCTOR(me, obj);
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView___INIT___(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView___INIT___]
	UIViewWrapper* obj = [[UIViewWrapper alloc] init];
	[obj setWrappedCObj:me];
    org_xmlvm_iphone_UIResponder_INTERNAL_CONSTRUCTOR(me, obj);
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setFrame___org_xmlvm_iphone_CGRect(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setFrame___org_xmlvm_iphone_CGRect]
	
	/*********************************************************************************************
	 * README: The following shows a typical pattern for forwarding a Java invocation to a
	 * corresponding Objective-C method. First we retrieve the wrapped Objective-C object
	 * via field wrappedObjCObj inherited from NSObject and then do a regular Objective-C
	 * invocation. Note that helper function toCGRect() converts the CGRect parameter to
	 * a value-type as required by the signature of setFrame.
	 */
	org_xmlvm_iphone_UIView* thiz = me;
	UIView* wrappedObjCObj = thiz->fields.org_xmlvm_iphone_NSObject.wrappedObjCObj;
	[wrappedObjCObj setFrame: toCGRect(n1)];
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_getFrame__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getFrame__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_getCenter__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getCenter__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setCenter___org_xmlvm_iphone_CGPoint(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setCenter___org_xmlvm_iphone_CGPoint]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setLocation___float_float(JAVA_OBJECT me, JAVA_FLOAT n1, JAVA_FLOAT n2)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setLocation___float_float]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setSize___float_float(JAVA_OBJECT me, JAVA_FLOAT n1, JAVA_FLOAT n2)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setSize___float_float]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_addSubview___org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_addSubview___org_xmlvm_iphone_UIView]
    org_xmlvm_iphone_UIView* view = me;
    XMLVMUtil_ArrayList_add(view->fields.org_xmlvm_iphone_UIView.subviews, n1);
    UIView* realViewParent = view->fields.org_xmlvm_iphone_NSObject.wrappedObjCObj;
    org_xmlvm_iphone_UIView *otherView = n1;
    UIView* realViewChild = otherView->fields.org_xmlvm_iphone_NSObject.wrappedObjCObj;
    [realViewParent addSubview: realViewChild];
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_sendSubviewToBack___org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_sendSubviewToBack___org_xmlvm_iphone_UIView]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_insertSubview___org_xmlvm_iphone_UIView_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_insertSubview___org_xmlvm_iphone_UIView_int]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_bringSubviewToFront___org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_bringSubviewToFront___org_xmlvm_iphone_UIView]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_removeFromSuperview__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_removeFromSuperview__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_getSubviews__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getSubviews__]
    org_xmlvm_iphone_UIView* thiz = me;
    return thiz->fields.org_xmlvm_iphone_UIView.subviews;
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_getSuperview__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getSuperview__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_getWindow__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getWindow__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_layoutSubviews__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_layoutSubviews__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_getBounds__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getBounds__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setBounds___org_xmlvm_iphone_CGRect(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setBounds___org_xmlvm_iphone_CGRect]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setNeedsDisplay__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setNeedsDisplay__]
	org_xmlvm_iphone_UIView *view = me;
	UIView *realView = view->fields.org_xmlvm_iphone_NSObject.wrappedObjCObj;
	[realView setNeedsDisplay];
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setOpaque___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setOpaque___boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_BOOLEAN org_xmlvm_iphone_UIView_isOpaque__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_isOpaque__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setClearsContextBeforeDrawing___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setClearsContextBeforeDrawing___boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_getBackgroundColor__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getBackgroundColor__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setBackgroundColor___org_xmlvm_iphone_UIColor(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setBackgroundColor___org_xmlvm_iphone_UIColor]
	UIView* view = (UIView*) ((org_xmlvm_iphone_UIView*) me)->fields.org_xmlvm_iphone_NSObject.wrappedObjCObj;
	UIColor* color = (UIColor*) ((org_xmlvm_iphone_UIColor*) n1)->fields.org_xmlvm_iphone_NSObject.wrappedObjCObj;
	[view setBackgroundColor: color];
    //XMLVM_END_WRAPPER
}

JAVA_FLOAT org_xmlvm_iphone_UIView_getAlpha__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getAlpha__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAlpha___float(JAVA_OBJECT me, JAVA_FLOAT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAlpha___float]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_BOOLEAN org_xmlvm_iphone_UIView_isHidden__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_isHidden__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setHidden___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setHidden___boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setContentMode___int(JAVA_OBJECT me, JAVA_INT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setContentMode___int]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_INT org_xmlvm_iphone_UIView_getContentMode__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getContentMode__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_BOOLEAN org_xmlvm_iphone_UIView_isUserInteractionEnabled__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_isUserInteractionEnabled__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setUserInteractionEnabled___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setUserInteractionEnabled___boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_getTransform__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getTransform__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setTransform___org_xmlvm_iphone_CGAffineTransform(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setTransform___org_xmlvm_iphone_CGAffineTransform]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_BOOLEAN org_xmlvm_iphone_UIView_clipsToBounds__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_clipsToBounds__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setClipsToBounds___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setClipsToBounds___boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_INT org_xmlvm_iphone_UIView_getTag__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getTag__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setTag___int(JAVA_OBJECT me, JAVA_INT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setTag___int]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_convertPointToView___org_xmlvm_iphone_CGPoint_org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_convertPointToView___org_xmlvm_iphone_CGPoint_org_xmlvm_iphone_UIView]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_convertPointFromView___org_xmlvm_iphone_CGPoint_org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_convertPointFromView___org_xmlvm_iphone_CGPoint_org_xmlvm_iphone_UIView]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_convertRectToView___org_xmlvm_iphone_CGRect_org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_convertRectToView___org_xmlvm_iphone_CGRect_org_xmlvm_iphone_UIView]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_convertRectFromView___org_xmlvm_iphone_CGRect_org_xmlvm_iphone_UIView(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_convertRectFromView___org_xmlvm_iphone_CGRect_org_xmlvm_iphone_UIView]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_getLayer__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getLayer__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_INT org_xmlvm_iphone_UIView_getAutoresizingMask__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_getAutoresizingMask__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAutoresizingMask___int(JAVA_OBJECT me, JAVA_INT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAutoresizingMask___int]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_BOOLEAN org_xmlvm_iphone_UIView_isAutoresizesSubviews__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_isAutoresizesSubviews__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAutoresizesSubviews___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAutoresizesSubviews___boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_beginAnimations___java_lang_String(JAVA_OBJECT n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_beginAnimations___java_lang_String]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_commitAnimations__()
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_commitAnimations__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationStartDate___org_xmlvm_iphone_NSDate(JAVA_OBJECT n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationStartDate___org_xmlvm_iphone_NSDate]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationsEnabled___boolean(JAVA_BOOLEAN n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationsEnabled___boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationDuration___double(JAVA_DOUBLE n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationDuration___double]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationDelay___double(JAVA_DOUBLE n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationDelay___double]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationCurve___int(JAVA_INT n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationCurve___int]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationRepeatCount___float(JAVA_FLOAT n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationRepeatCount___float]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationRepeatAutoreverses___boolean(JAVA_BOOLEAN n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationRepeatAutoreverses___boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationBeginsFromCurrentState___boolean(JAVA_BOOLEAN n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationBeginsFromCurrentState___boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationTransitionForView___int_org_xmlvm_iphone_UIView_boolean(JAVA_INT n1, JAVA_OBJECT n2, JAVA_BOOLEAN n3)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationTransitionForView___int_org_xmlvm_iphone_UIView_boolean]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_BOOLEAN org_xmlvm_iphone_UIView_areAnimationsEnabled__()
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_areAnimationsEnabled__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_setAnimationDelegate___org_xmlvm_iphone_UIViewAnimationDelegate(JAVA_OBJECT n1)
{
    if (!__TIB_org_xmlvm_iphone_UIView.classInitialized) __INIT_org_xmlvm_iphone_UIView();
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_setAnimationDelegate___org_xmlvm_iphone_UIViewAnimationDelegate]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

JAVA_OBJECT org_xmlvm_iphone_UIView_sizeThatFits___org_xmlvm_iphone_CGSize(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_sizeThatFits___org_xmlvm_iphone_CGSize]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_sizeToFit__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_sizeToFit__]
    XMLVM_NOT_IMPLEMENTED();
    //XMLVM_END_WRAPPER
}

void org_xmlvm_iphone_UIView_drawRect___org_xmlvm_iphone_CGRect(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_WRAPPER[org_xmlvm_iphone_UIView_drawRect___org_xmlvm_iphone_CGRect]
    // Do nothing. Will be overwritten in derived classes
    //XMLVM_END_WRAPPER
}

