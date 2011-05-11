
#include "xmlvm.h"
#include "org_apache_harmony_luni_platform_OSNetworkSystem.h"


//XMLVM_BEGIN_NATIVE_IMPLEMENTATION

//#include <fcntl.h>
//#include <errno.h>
//#include <sys/types.h>
//#include <sys/socket.h>
#include "java_io_FileDescriptor.h"
#include "java_net_SocketException.h"
#include "java_net_BindException.h"
#include "java_lang_Thread.h"
#include "xmlvm-sock.h"


void createSocket (JAVA_OBJECT fd, int sockType, JAVA_BOOLEAN preferIPv4Stack)
{
    I_32 result;
    hysocket_t sockdesc;
    int family = HYADDR_FAMILY_AFINET4;
    int supportsIPv6 = 0; //HARMONY_CACHE_GET (env, harmony_supports_ipv6);
    
    if (supportsIPv6 && !(preferIPv4Stack))
    {
        /* We are creating a server socket on the any address */
        family = HYADDR_FAMILY_UNSPEC;
    }

    result = hysock_socket (&sockdesc, family, sockType, HYSOCK_DEFPROTOCOL);

    if (0 != result)
    {
        /* ok now if we tried to create an IPv6 socket and it failed it could be that the
         platform does not have IPv6 enabled.  In this case we should revert back to 
         creating an IPv4 socket */
        if (HYADDR_FAMILY_UNSPEC == family)
        {
            /* now try to create an IPv4 socket */
            family = HYADDR_FAMILY_AFINET4;
            result =
            hysock_socket (&sockdesc, family, sockType, HYSOCK_DEFPROTOCOL);
        }
        
        if (0 != result)
        {
            JAVA_OBJECT exc = __NEW_java_net_SocketException();
            // TODO: Need to pass result to constructor
            java_net_SocketException___INIT___(exc);
            java_lang_Thread* curThread = (java_lang_Thread*)java_lang_Thread_currentThread__();
            curThread->fields.java_lang_Thread.xmlvmException_ = exc;
            XMLVM_LONGJMP(curThread->fields.java_lang_Thread.xmlvmExceptionEnv_);
        }
    }
    
    if (0 == result)
    {
        ((java_io_FileDescriptor*) fd)->fields.java_io_FileDescriptor.descriptor_ = (JAVA_ULONG) sockdesc;
        //setJavaIoFileDescriptorContents (env, thisObjFD, sockdesc);
    }
}

//XMLVM_END_NATIVE_IMPLEMENTATION

void org_apache_harmony_luni_platform_OSNetworkSystem_accept___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_OBJECT n3, JAVA_INT n4)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_accept___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_acceptStreamSocket___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_OBJECT n3, JAVA_INT n4)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_acceptStreamSocket___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_availableStream___java_io_FileDescriptor(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_availableStream___java_io_FileDescriptor]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_bind___java_io_FileDescriptor_java_net_InetAddress_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_bind___java_io_FileDescriptor_java_net_InetAddress_int]
    JAVA_ARRAY_BYTE nlocalAddrBytes[HYSOCK_INADDR6_LEN];
    int length;
    U_16 nPort;
    I_32 result;
    hysocket_t socketP;
    hysockaddr_struct sockaddrP;
    U_32 scope_id = 0;
    java_io_FileDescriptor* fileDescriptor = (java_io_FileDescriptor*) n1;
    java_net_InetAddress* inetAddress = n2;
    JAVA_INT localPort = n3;
    
    socketP = getJavaIoFileDescriptorContentsAsAPointer(fileDescriptor);
    if (!hysock_socketIsValid(socketP)) {
        //throwJavaNetSocketException(env, HYPORT_ERROR_SOCKET_BADSOCKET);
        
        JAVA_OBJECT exc = __NEW_java_net_SocketException();
        // TODO: Need to pass result to constructor
        java_net_SocketException___INIT___(exc);
        java_lang_Thread* curThread = (java_lang_Thread*)java_lang_Thread_currentThread__();
        curThread->fields.java_lang_Thread.xmlvmException_ = exc;
        XMLVM_LONGJMP(curThread->fields.java_lang_Thread.xmlvmExceptionEnv_);
        
        return;
    } else {
        netGetJavaNetInetAddressValue(inetAddress, (U_8*) nlocalAddrBytes, (U_32*) &length);
        
        nPort = hysock_htons((U_16) localPort);
        if (length == HYSOCK_INADDR6_LEN) {
            netGetJavaNetInetAddressScopeId(inetAddress, &scope_id);
            hysock_sockaddr_init6(&sockaddrP, (U_8 *) nlocalAddrBytes, length,
                                  HYADDR_FAMILY_AFINET6, nPort, 0, scope_id,
                                  socketP);
        } else {
            hysock_sockaddr_init6(&sockaddrP, (U_8 *) nlocalAddrBytes, length,
                                  HYADDR_FAMILY_AFINET4, nPort, 0, scope_id,
                                  socketP);
        }
        result = hysock_bind(socketP, &sockaddrP);
        if (0 != result) {
            // throwJavaNetBindException(env, result);
            
            JAVA_OBJECT exc = __NEW_java_net_BindException();
            // TODO: Need to pass result to constructor
            java_net_BindException___INIT___(exc);
            java_lang_Thread* curThread = (java_lang_Thread*)java_lang_Thread_currentThread__();
            curThread->fields.java_lang_Thread.xmlvmException_ = exc;
            XMLVM_LONGJMP(curThread->fields.java_lang_Thread.xmlvmExceptionEnv_);
            return;
        }
    }
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_connect___java_io_FileDescriptor_int_java_net_InetAddress_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2, JAVA_OBJECT n3, JAVA_INT n4)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_connect___java_io_FileDescriptor_int_java_net_InetAddress_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_connectDatagram___java_io_FileDescriptor_int_int_java_net_InetAddress(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2, JAVA_INT n3, JAVA_OBJECT n4)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_connectDatagram___java_io_FileDescriptor_int_int_java_net_InetAddress]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_connectStreamWithTimeoutSocket___java_io_FileDescriptor_int_int_int_java_net_InetAddress(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2, JAVA_INT n3, JAVA_INT n4, JAVA_OBJECT n5)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_connectStreamWithTimeoutSocket___java_io_FileDescriptor_int_int_int_java_net_InetAddress]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_connectWithTimeout___java_io_FileDescriptor_int_int_java_net_InetAddress_int_int_java_lang_Long(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2, JAVA_INT n3, JAVA_OBJECT n4, JAVA_INT n5, JAVA_INT n6, JAVA_OBJECT n7)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_connectWithTimeout___java_io_FileDescriptor_int_int_java_net_InetAddress_int_int_java_lang_Long]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_createDatagramSocket___java_io_FileDescriptor_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_createDatagramSocket___java_io_FileDescriptor_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_createServerStreamSocket___java_io_FileDescriptor_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_createServerStreamSocket___java_io_FileDescriptor_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_createStreamSocket___java_io_FileDescriptor_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_createStreamSocket___java_io_FileDescriptor_boolean]
    createSocket(n1, HYSOCK_STREAM, n2);
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_disconnectDatagram___java_io_FileDescriptor(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_disconnectDatagram___java_io_FileDescriptor]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_OBJECT org_apache_harmony_luni_platform_OSNetworkSystem_getHostByAddr___byte_1ARRAY(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_getHostByAddr___byte_1ARRAY]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_OBJECT org_apache_harmony_luni_platform_OSNetworkSystem_getHostByName___java_lang_String_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_getHostByName___java_lang_String_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_getSocketFlags__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_getSocketFlags__]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_OBJECT org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalAddress___java_io_FileDescriptor_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalAddress___java_io_FileDescriptor_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalPort___java_io_FileDescriptor_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalPort___java_io_FileDescriptor_boolean]
    I_32 result;
    hysockaddr_struct sockaddrP;
    U_16 nPort, hPort;
    java_io_FileDescriptor* fileDescriptor = n1;
    JAVA_BOOLEAN preferIPv6Addresses = n2;
    
    result = netGetSockAddr(fileDescriptor, &sockaddrP, preferIPv6Addresses);
    if (0 != result) {
        /* The java spec does not indicate any exceptions on this call */
        return (JAVA_INT) 0;
    }
    
    nPort = hysock_sockaddr_port(&sockaddrP);
    hPort = hysock_ntohs(nPort);
    return (JAVA_INT) hPort;
    //XMLVM_END_NATIVE
}

JAVA_OBJECT org_apache_harmony_luni_platform_OSNetworkSystem_getSocketOption___java_io_FileDescriptor_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_getSocketOption___java_io_FileDescriptor_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_OBJECT org_apache_harmony_luni_platform_OSNetworkSystem_inheritedChannel__(JAVA_OBJECT me)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_inheritedChannel__]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_isReachableByICMPImpl___java_net_InetAddress_java_net_InetAddress_int_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3, JAVA_INT n4)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_isReachableByICMPImpl___java_net_InetAddress_java_net_InetAddress_int_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_listenStreamSocket___java_io_FileDescriptor_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_listenStreamSocket___java_io_FileDescriptor_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_oneTimeInitializationImpl___boolean(JAVA_OBJECT me, JAVA_BOOLEAN n1)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_oneTimeInitializationImpl___boolean]
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_peekDatagram___java_io_FileDescriptor_java_net_InetAddress_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_peekDatagram___java_io_FileDescriptor_java_net_InetAddress_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_read___java_io_FileDescriptor_byte_1ARRAY_int_int_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3, JAVA_INT n4, JAVA_INT n5)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_read___java_io_FileDescriptor_byte_1ARRAY_int_int_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_readDirect___java_io_FileDescriptor_long_int_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_LONG n2, JAVA_INT n3, JAVA_INT n4)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_readDirect___java_io_FileDescriptor_long_int_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_OBJECT n3, JAVA_INT n4, JAVA_INT n5, JAVA_INT n6, JAVA_BOOLEAN n7)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_LONG n3, JAVA_INT n4, JAVA_INT n5, JAVA_INT n6, JAVA_BOOLEAN n7)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_receiveStream___java_io_FileDescriptor_byte_1ARRAY_int_int_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3, JAVA_INT n4, JAVA_INT n5)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_receiveStream___java_io_FileDescriptor_byte_1ARRAY_int_int_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_OBJECT n3, JAVA_INT n4, JAVA_INT n5, JAVA_INT n6, JAVA_BOOLEAN n7)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_LONG n3, JAVA_INT n4, JAVA_INT n5, JAVA_INT n6, JAVA_BOOLEAN n7)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_selectImpl___java_io_FileDescriptor_1ARRAY_java_io_FileDescriptor_1ARRAY_int_int_int_1ARRAY_long(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3, JAVA_INT n4, JAVA_OBJECT n5, JAVA_LONG n6)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_selectImpl___java_io_FileDescriptor_1ARRAY_java_io_FileDescriptor_1ARRAY_int_int_int_1ARRAY_long]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3, JAVA_INT n4, JAVA_BOOLEAN n5)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagramDirect___java_io_FileDescriptor_long_int_int_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_LONG n2, JAVA_INT n3, JAVA_INT n4, JAVA_BOOLEAN n5)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagramDirect___java_io_FileDescriptor_long_int_int_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_int_boolean_int_java_net_InetAddress(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3, JAVA_INT n4, JAVA_INT n5, JAVA_BOOLEAN n6, JAVA_INT n7, JAVA_OBJECT n8)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_int_boolean_int_java_net_InetAddress]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram2___java_io_FileDescriptor_byte_1ARRAY_int_int_int_java_net_InetAddress(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3, JAVA_INT n4, JAVA_INT n5, JAVA_OBJECT n6)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram2___java_io_FileDescriptor_byte_1ARRAY_int_int_int_java_net_InetAddress]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagramDirect___java_io_FileDescriptor_long_int_int_int_boolean_int_java_net_InetAddress(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_LONG n2, JAVA_INT n3, JAVA_INT n4, JAVA_INT n5, JAVA_BOOLEAN n6, JAVA_INT n7, JAVA_OBJECT n8)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagramDirect___java_io_FileDescriptor_long_int_int_int_boolean_int_java_net_InetAddress]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_sendUrgentData___java_io_FileDescriptor_byte(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BYTE n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_sendUrgentData___java_io_FileDescriptor_byte]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_setInetAddress___java_net_InetAddress_byte_1ARRAY(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_setInetAddress___java_net_InetAddress_byte_1ARRAY]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_setNonBlocking___java_io_FileDescriptor_boolean(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_BOOLEAN n2)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_setNonBlocking___java_io_FileDescriptor_boolean]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_setSocketOption___java_io_FileDescriptor_int_java_lang_Object(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_INT n2, JAVA_OBJECT n3)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_setSocketOption___java_io_FileDescriptor_int_java_lang_Object]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_shutdownInput___java_io_FileDescriptor(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_shutdownInput___java_io_FileDescriptor]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_shutdownOutput___java_io_FileDescriptor(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_shutdownOutput___java_io_FileDescriptor]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

void org_apache_harmony_luni_platform_OSNetworkSystem_socketClose___java_io_FileDescriptor(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_socketClose___java_io_FileDescriptor]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_BOOLEAN org_apache_harmony_luni_platform_OSNetworkSystem_supportsUrgentData___java_io_FileDescriptor(JAVA_OBJECT me, JAVA_OBJECT n1)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_supportsUrgentData___java_io_FileDescriptor]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_write___java_io_FileDescriptor_byte_1ARRAY_int_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_INT n3, JAVA_INT n4)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_write___java_io_FileDescriptor_byte_1ARRAY_int_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_INT org_apache_harmony_luni_platform_OSNetworkSystem_writeDirect___java_io_FileDescriptor_long_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_LONG n2, JAVA_INT n3)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_writeDirect___java_io_FileDescriptor_long_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}

JAVA_LONG org_apache_harmony_luni_platform_OSNetworkSystem_writev___java_io_FileDescriptor_java_lang_Object_1ARRAY_int_1ARRAY_int_1ARRAY_int(JAVA_OBJECT me, JAVA_OBJECT n1, JAVA_OBJECT n2, JAVA_OBJECT n3, JAVA_OBJECT n4, JAVA_INT n5)
{
    //XMLVM_BEGIN_NATIVE[org_apache_harmony_luni_platform_OSNetworkSystem_writev___java_io_FileDescriptor_java_lang_Object_1ARRAY_int_1ARRAY_int_1ARRAY_int]
    XMLVM_UNIMPLEMENTED_NATIVE_METHOD();
    //XMLVM_END_NATIVE
}


void xmlvm_init_native_org_apache_harmony_luni_platform_OSNetworkSystem()
{
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_accept___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_accept___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_accept___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_acceptStreamSocket___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_acceptStreamSocket___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_acceptStreamSocket___java_io_FileDescriptor_java_net_SocketImpl_java_io_FileDescriptor_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_availableStream___java_io_FileDescriptor
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_availableStream___java_io_FileDescriptor] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_availableStream___java_io_FileDescriptor;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_bind___java_io_FileDescriptor_java_net_InetAddress_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_bind___java_io_FileDescriptor_java_net_InetAddress_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_bind___java_io_FileDescriptor_java_net_InetAddress_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_connect___java_io_FileDescriptor_int_java_net_InetAddress_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_connect___java_io_FileDescriptor_int_java_net_InetAddress_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_connect___java_io_FileDescriptor_int_java_net_InetAddress_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_connectDatagram___java_io_FileDescriptor_int_int_java_net_InetAddress
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_connectDatagram___java_io_FileDescriptor_int_int_java_net_InetAddress] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_connectDatagram___java_io_FileDescriptor_int_int_java_net_InetAddress;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_connectStreamWithTimeoutSocket___java_io_FileDescriptor_int_int_int_java_net_InetAddress
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_connectStreamWithTimeoutSocket___java_io_FileDescriptor_int_int_int_java_net_InetAddress] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_connectStreamWithTimeoutSocket___java_io_FileDescriptor_int_int_int_java_net_InetAddress;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_connectWithTimeout___java_io_FileDescriptor_int_int_java_net_InetAddress_int_int_java_lang_Long
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_connectWithTimeout___java_io_FileDescriptor_int_int_java_net_InetAddress_int_int_java_lang_Long] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_connectWithTimeout___java_io_FileDescriptor_int_int_java_net_InetAddress_int_int_java_lang_Long;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_createDatagramSocket___java_io_FileDescriptor_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_createDatagramSocket___java_io_FileDescriptor_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_createDatagramSocket___java_io_FileDescriptor_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_createServerStreamSocket___java_io_FileDescriptor_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_createServerStreamSocket___java_io_FileDescriptor_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_createServerStreamSocket___java_io_FileDescriptor_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_createStreamSocket___java_io_FileDescriptor_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_createStreamSocket___java_io_FileDescriptor_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_createStreamSocket___java_io_FileDescriptor_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_disconnectDatagram___java_io_FileDescriptor
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_disconnectDatagram___java_io_FileDescriptor] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_disconnectDatagram___java_io_FileDescriptor;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getHostByAddr___byte_1ARRAY
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getHostByAddr___byte_1ARRAY] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_getHostByAddr___byte_1ARRAY;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getHostByName___java_lang_String_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getHostByName___java_lang_String_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_getHostByName___java_lang_String_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getSocketFlags__
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getSocketFlags__] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_getSocketFlags__;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalAddress___java_io_FileDescriptor_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalAddress___java_io_FileDescriptor_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalAddress___java_io_FileDescriptor_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalPort___java_io_FileDescriptor_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalPort___java_io_FileDescriptor_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_getSocketLocalPort___java_io_FileDescriptor_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getSocketOption___java_io_FileDescriptor_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_getSocketOption___java_io_FileDescriptor_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_getSocketOption___java_io_FileDescriptor_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_inheritedChannel__
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_inheritedChannel__] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_inheritedChannel__;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_listenStreamSocket___java_io_FileDescriptor_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_listenStreamSocket___java_io_FileDescriptor_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_listenStreamSocket___java_io_FileDescriptor_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_peekDatagram___java_io_FileDescriptor_java_net_InetAddress_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_peekDatagram___java_io_FileDescriptor_java_net_InetAddress_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_peekDatagram___java_io_FileDescriptor_java_net_InetAddress_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_read___java_io_FileDescriptor_byte_1ARRAY_int_int_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_read___java_io_FileDescriptor_byte_1ARRAY_int_int_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_read___java_io_FileDescriptor_byte_1ARRAY_int_int_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_readDirect___java_io_FileDescriptor_long_int_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_readDirect___java_io_FileDescriptor_long_int_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_readDirect___java_io_FileDescriptor_long_int_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_receiveDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_receiveStream___java_io_FileDescriptor_byte_1ARRAY_int_int_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_receiveStream___java_io_FileDescriptor_byte_1ARRAY_int_int_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_receiveStream___java_io_FileDescriptor_byte_1ARRAY_int_int_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagram___java_io_FileDescriptor_java_net_DatagramPacket_byte_1ARRAY_int_int_int_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_recvConnectedDatagramDirect___java_io_FileDescriptor_java_net_DatagramPacket_long_int_int_int_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagramDirect___java_io_FileDescriptor_long_int_int_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagramDirect___java_io_FileDescriptor_long_int_int_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_sendConnectedDatagramDirect___java_io_FileDescriptor_long_int_int_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_int_boolean_int_java_net_InetAddress
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_int_boolean_int_java_net_InetAddress] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram___java_io_FileDescriptor_byte_1ARRAY_int_int_int_boolean_int_java_net_InetAddress;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram2___java_io_FileDescriptor_byte_1ARRAY_int_int_int_java_net_InetAddress
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram2___java_io_FileDescriptor_byte_1ARRAY_int_int_int_java_net_InetAddress] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagram2___java_io_FileDescriptor_byte_1ARRAY_int_int_int_java_net_InetAddress;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagramDirect___java_io_FileDescriptor_long_int_int_int_boolean_int_java_net_InetAddress
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagramDirect___java_io_FileDescriptor_long_int_int_int_boolean_int_java_net_InetAddress] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_sendDatagramDirect___java_io_FileDescriptor_long_int_int_int_boolean_int_java_net_InetAddress;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendUrgentData___java_io_FileDescriptor_byte
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_sendUrgentData___java_io_FileDescriptor_byte] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_sendUrgentData___java_io_FileDescriptor_byte;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_setInetAddress___java_net_InetAddress_byte_1ARRAY
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_setInetAddress___java_net_InetAddress_byte_1ARRAY] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_setInetAddress___java_net_InetAddress_byte_1ARRAY;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_setNonBlocking___java_io_FileDescriptor_boolean
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_setNonBlocking___java_io_FileDescriptor_boolean] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_setNonBlocking___java_io_FileDescriptor_boolean;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_setSocketOption___java_io_FileDescriptor_int_java_lang_Object
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_setSocketOption___java_io_FileDescriptor_int_java_lang_Object] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_setSocketOption___java_io_FileDescriptor_int_java_lang_Object;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_shutdownInput___java_io_FileDescriptor
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_shutdownInput___java_io_FileDescriptor] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_shutdownInput___java_io_FileDescriptor;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_shutdownOutput___java_io_FileDescriptor
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_shutdownOutput___java_io_FileDescriptor] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_shutdownOutput___java_io_FileDescriptor;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_socketClose___java_io_FileDescriptor
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_socketClose___java_io_FileDescriptor] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_socketClose___java_io_FileDescriptor;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_supportsUrgentData___java_io_FileDescriptor
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_supportsUrgentData___java_io_FileDescriptor] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_supportsUrgentData___java_io_FileDescriptor;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_write___java_io_FileDescriptor_byte_1ARRAY_int_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_write___java_io_FileDescriptor_byte_1ARRAY_int_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_write___java_io_FileDescriptor_byte_1ARRAY_int_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_writeDirect___java_io_FileDescriptor_long_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_writeDirect___java_io_FileDescriptor_long_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_writeDirect___java_io_FileDescriptor_long_int;
#endif
#ifdef XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_writev___java_io_FileDescriptor_java_lang_Object_1ARRAY_int_1ARRAY_int_1ARRAY_int
    __TIB_org_apache_harmony_luni_platform_OSNetworkSystem.vtable[XMLVM_VTABLE_IDX_org_apache_harmony_luni_platform_OSNetworkSystem_writev___java_io_FileDescriptor_java_lang_Object_1ARRAY_int_1ARRAY_int_1ARRAY_int] = 
        (VTABLE_PTR) org_apache_harmony_luni_platform_OSNetworkSystem_writev___java_io_FileDescriptor_java_lang_Object_1ARRAY_int_1ARRAY_int_1ARRAY_int;
#endif
}
