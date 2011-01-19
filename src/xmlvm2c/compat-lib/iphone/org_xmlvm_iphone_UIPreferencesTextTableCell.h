#ifndef __ORG_XMLVM_IPHONE_UIPREFERENCESTEXTTABLECELL__
#define __ORG_XMLVM_IPHONE_UIPREFERENCESTEXTTABLECELL__

#include "xmlvm.h"
#include "org_xmlvm_iphone_UIPreferencesTableCell.h"

// Circular references:
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIPreferencesTableCell
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIPreferencesTableCell
XMLVM_FORWARD_DECL(org_xmlvm_iphone_UIPreferencesTableCell)
#endif
#ifndef XMLVM_FORWARD_DECL_java_lang_String
#define XMLVM_FORWARD_DECL_java_lang_String
XMLVM_FORWARD_DECL(java_lang_String)
#endif
// Class declarations for org.xmlvm.iphone.UIPreferencesTextTableCell
XMLVM_DEFINE_CLASS(org_xmlvm_iphone_UIPreferencesTextTableCell, 78)

extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIPreferencesTextTableCell;
extern JAVA_OBJECT __CLASS_org_xmlvm_iphone_UIPreferencesTextTableCell_ARRAYTYPE;

//XMLVM_BEGIN_DECLARATIONS
#define __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIPreferencesTextTableCell
//XMLVM_END_DECLARATIONS

#define __INSTANCE_FIELDS_org_xmlvm_iphone_UIPreferencesTextTableCell \
    __INSTANCE_FIELDS_org_xmlvm_iphone_UIPreferencesTableCell; \
    struct { \
        __ADDITIONAL_INSTANCE_FIELDS_org_xmlvm_iphone_UIPreferencesTextTableCell \
    } org_xmlvm_iphone_UIPreferencesTextTableCell

struct org_xmlvm_iphone_UIPreferencesTextTableCell {
    __TIB_DEFINITION_org_xmlvm_iphone_UIPreferencesTextTableCell* tib;
    struct {
        __INSTANCE_FIELDS_org_xmlvm_iphone_UIPreferencesTextTableCell;
    } fields;
};
#ifndef XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIPreferencesTextTableCell
#define XMLVM_FORWARD_DECL_org_xmlvm_iphone_UIPreferencesTextTableCell
typedef struct org_xmlvm_iphone_UIPreferencesTextTableCell org_xmlvm_iphone_UIPreferencesTextTableCell;
#endif

#define XMLVM_VTABLE_SIZE_org_xmlvm_iphone_UIPreferencesTextTableCell 78
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIPreferencesTextTableCell_setValue___java_lang_String 75
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIPreferencesTextTableCell_getValue__ 76
#define XMLVM_VTABLE_IDX_org_xmlvm_iphone_UIPreferencesTextTableCell_xmlvmKeyTyped___char 77

void __INIT_org_xmlvm_iphone_UIPreferencesTextTableCell();
void __DELETE_org_xmlvm_iphone_UIPreferencesTextTableCell(void* me, void* client_data);
JAVA_OBJECT __NEW_org_xmlvm_iphone_UIPreferencesTextTableCell();
JAVA_OBJECT __NEW_INSTANCE_org_xmlvm_iphone_UIPreferencesTextTableCell();
void org_xmlvm_iphone_UIPreferencesTextTableCell___INIT___(JAVA_OBJECT me);
// Vtable index: 75
void org_xmlvm_iphone_UIPreferencesTextTableCell_setValue___java_lang_String(JAVA_OBJECT me, JAVA_OBJECT n1);
// Vtable index: 76
JAVA_OBJECT org_xmlvm_iphone_UIPreferencesTextTableCell_getValue__(JAVA_OBJECT me);
// Vtable index: 77
void org_xmlvm_iphone_UIPreferencesTextTableCell_xmlvmKeyTyped___char(JAVA_OBJECT me, JAVA_CHAR n1);

#endif
