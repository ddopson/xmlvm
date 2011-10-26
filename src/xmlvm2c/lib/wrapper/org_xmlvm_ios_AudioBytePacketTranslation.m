
//XMLVM_BEGIN_IMPLEMENTATION
#include "xmlvm-ios.h"

AudioBytePacketTranslation toAudioBytePacketTranslation(void *obj)
{
	org_xmlvm_ios_AudioBytePacketTranslation* cObj = obj;
	AudioBytePacketTranslation toRet;
	toRet.mByte = cObj->fields.org_xmlvm_ios_AudioBytePacketTranslation.mByte_;
	toRet.mPacket = cObj->fields.org_xmlvm_ios_AudioBytePacketTranslation.mPacket_;
	toRet.mByteOffsetInPacket = cObj->fields.org_xmlvm_ios_AudioBytePacketTranslation.mByteOffsetInPacket_;
	toRet.mFlags = cObj->fields.org_xmlvm_ios_AudioBytePacketTranslation.mFlags_;
	return toRet;
}
JAVA_OBJECT fromAudioBytePacketTranslation(AudioBytePacketTranslation obj)
{
	org_xmlvm_ios_AudioBytePacketTranslation* jObj = __NEW_org_xmlvm_ios_AudioBytePacketTranslation();
	org_xmlvm_ios_AudioBytePacketTranslation___INIT___(jObj);
	jObj->fields.org_xmlvm_ios_AudioBytePacketTranslation.mByte_ = obj.mByte;
	jObj->fields.org_xmlvm_ios_AudioBytePacketTranslation.mPacket_ = obj.mPacket;
	jObj->fields.org_xmlvm_ios_AudioBytePacketTranslation.mByteOffsetInPacket_ = obj.mByteOffsetInPacket;
	jObj->fields.org_xmlvm_ios_AudioBytePacketTranslation.mFlags_ = obj.mFlags;
	return jObj;
}
//XMLVM_END_IMPLEMENTATION

//XMLVM_BEGIN_WRAPPER[__NEW_org_xmlvm_ios_AudioBytePacketTranslation]
//XMLVM_END_WRAPPER
