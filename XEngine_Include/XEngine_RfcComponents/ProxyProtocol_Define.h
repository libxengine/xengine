﻿#pragma once
/********************************************************************
//	Created:	2012/10/11  21:43
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_ProxyServer\RfcProxyServer_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_Rfc\NetEngine_RfcProtocol\NetEngine_Rfc_ProxyServer
//	File Base:	RfcProxyServer_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	代理服务器导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////
//                      类型定义
//////////////////////////////////////////////////////////////////////
#define XENGINE_RFCCOMPONENT_PROXY_SOCKS_RESPONSE_SUCCESS 0x00       //成功
#define XENGINE_RFCCOMPONENT_PROXY_SOCKS_RESPONSE_FAILED 0x01        //失败
#define XENGINE_RFCCOMPONENT_PROXY_SOCKS_RESPONSE_ALLOW 0x02         //代理服务器规则集不允许连接
#define XENGINE_RFCCOMPONENT_PROXY_SOCKS_RESPONSE_NETWORK 0x03       //网络无法访问
#define XENGINE_RFCCOMPONENT_PROXY_SOCKS_RESPONSE_DEST 0x04          //目标服务器无法访问（主机名无效）
#define XENGINE_RFCCOMPONENT_PROXY_SOCKS_RESPONSE_CONNECT 0x05       //连接目标服务器被拒绝
#define XENGINE_RFCCOMPONENT_PROXY_SOCKS_RESPONSE_TTL 0x06           //TTL已过期
#define XENGINE_RFCCOMPONENT_PROXY_SOCKS_RESPONSE_COMMAND 0x07       //不支持的命令
#define XENGINE_RFCCOMPONENT_PROXY_SOCKS_RESPONSE_ADDRTYPE 0x08      //不支持的目标服务器地址类型
//////////////////////////////////////////////////////////////////////
//                      枚举类型定义
//////////////////////////////////////////////////////////////////////
//当前客户端状态
typedef enum en_RfcComponents_ProxySocks_Status
{
    ENUM_RFCCOMPONENTS_PROXY_STATUS_CREATE = 0,                  //创建已完毕
    ENUM_RFCCOMPONENTS_PROXY_STATUS_AUTH = 1,                    //请求验证协议协商
    ENUM_RFCCOMPONENTS_PROXY_STATUS_USER = 2,                    //用户验证请求
    ENUM_RFCCOMPONENTS_PROXY_STATUS_FORWARD = 3                  //数据转发请求
}ENUM_RFCCOMPONENTS_PROXY_STATUS;
//支持验证类型
typedef enum en_RfcComponents_ProxySocks_Auth
{
    ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH_ANONYMOUS = 0x00,              //匿名登录
    ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH_GSAPI = 0x01,                  //GSSAPI认证
    ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH_USERPASS = 0x02,               //账号密码认证
    ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH_IANA = 0x03 - 0x7F,            //IANA
    ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH_RESVER = 0x80,                 //保留
    ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH_NOAUTH = 0xFF                  //不支持的登录方法.拒绝登录
}ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH;
//客户端代理类型
typedef enum en_RfcComponents_ProxySocks_Command
{
    ENUM_RFCCOMPONENTS_PROXYSOCKS_COMMAND_CONNECT = 0x01,             //连接到服务器
    ENUM_RFCCOMPONENTS_PROXYSOCKS_COMMAND_BIND = 0x02,                //绑定地址
    ENUM_RFCCOMPONENTS_PROXYSOCKS_COMMAND_UDP = 0x03                  //UDP关联
}ENUM_RFCCOMPONENTS_PROXYSOCKS_COMMAND;
//网络类型
typedef enum en_RfcComponents_ProxySocks_IPAddr
{
    ENUM_RFCCOMPONENTS_PROXYSOCKS_IPADDR_IPV4 = 0x01,                 //IPV4
    ENUM_RFCCOMPONENTS_PROXYSOCKS_IPADDR_DOMAIN = 0x03,               //域名
    ENUM_RFCCOMPONENTS_PROXYSOCKS_IPADDR_IPV6 = 0x04                  //IPV6
}ENUM_RFCCOMPONENTS_PROXYSOCKS_IPADDR;
//////////////////////////////////////////////////////////////////////////////////
//                         导出的函数
//////////////////////////////////////////////////////////////////////////////////
extern "C" BOOL ProxyProtocol_GetLastError(int *pInt_SysError = NULL);
/************************************************************************/
/*                     SOCK代理服务器导出函数                           */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////SOCKS服务器
/********************************************************************
函数名称：ProxyProtocol_SocksCore_Create
函数功能：创建一个客户端
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_Create(LPCSTR lpszClientID);
/********************************************************************
函数名称：ProxyProtocol_SocksCore_Delete
函数功能：删除客户端
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_Delete(LPCSTR lpszClientID);
/********************************************************************
函数名称：ProxyProtocol_SocksCore_SetInfo
函数功能：设置自定义信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：lParam
  In/Out：In
  类型：无类型指针
  可空：N
  意思：输入设置的内容
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要设置内容大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_SetInfo(LPCSTR lpszClientID, LPVOID lParam, int nLen);
/********************************************************************
函数名称：ProxyProtocol_SocksCore_GetInfo
函数功能：获取自定义信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：lParam
  In/Out：Out
  类型：无类型指针
  可空：N
  意思：输出获取到的内容
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出内容大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_GetInfo(LPCSTR lpszClientID, LPVOID lParam, int* pInt_Len = NULL);
/********************************************************************
函数名称：ProxyProtocol_SocksCore_GetStatus
函数功能：获取客户端状态
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
 参数.二：penSocks
  In/Out：Out
  类型：枚举类型
  可空：N
  意思：输出当前客户端状态
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_GetStatus(LPCSTR lpszClientID, ENUM_RFCCOMPONENTS_PROXY_STATUS* penSocks);
/********************************************************************
函数名称：ProxyProtocol_SocksCore_SetStatus
函数功能：设置客户端状态
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
 参数.二：enStatus
  In/Out：In
  类型：枚举类型
  可空：N
  意思：输入客户端状态
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_SetStatus(LPCSTR lpszClientID, ENUM_RFCCOMPONENTS_PROXY_STATUS enStatus);
/********************************************************************
函数名称：ProxyProtocol_SocksCore_ParseAuth
函数功能：解析验证类型
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区内容
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.四：penListAuth
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出客户端支持的验证类型列表,由用户提供内存,最大也就6个数组
 参数.五：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：当状态为ENUM_RFCCOMPONENTS_PROXY_STATUS_CREATE需要做这一步
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_ParseAuth(LPCSTR lpszClientID, LPCSTR lpszMsgBuffer, int nMsgLen, ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH* penListAuth, int* pInt_Count);
/********************************************************************
函数名称：ProxyProtocol_SocksCore_ParseUser
函数功能：解析验证用户信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区内容
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.四：penAuthType
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出客户端请求的验证方法
 参数.五：ptszUser
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出用户名,只有你要求对方用户名密码才会有用户名密码,如果是匿名,是没有这些信息的
 参数.六：ptszPass
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出密码
返回值
  类型：逻辑型
  意思：是否成功
备注：当状态为ENUM_RFCCOMPONENTS_PROXY_STATUS_AUTH需要做这一步
      如果是匿名登录,需要设置跳过此步骤
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_ParseUser(LPCSTR lpszClientID, LPCSTR lpszMsgBuffer, int nMsgLen, ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH* penAuthType, CHAR* ptszUser = NULL, CHAR* ptszPass = NULL);
/********************************************************************
函数名称：ProxyProtocol_SocksCore_ParseConnect
函数功能：解析用户命令连接类型
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的缓冲区内容
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入缓冲区大小
 参数.四：penCommand
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出客户端请求的命令
 参数.五：penIPAddr
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：输出IP类型
 参数.六：ptszClientAddr
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出客户端地址信息
 参数.七：pInt_Port
  In/Out：Out
  类型：字符指针
  可空：Y
  意思：输出端口
返回值
  类型：逻辑型
  意思：是否成功
备注：当状态为ENUM_RFCCOMPONENTS_PROXY_STATUS_USER需要做这一步
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_ParseConnect(LPCSTR lpszClientID, LPCSTR lpszMsgBuffer, int nMsgLen, ENUM_RFCCOMPONENTS_PROXYSOCKS_COMMAND * penCommand, ENUM_RFCCOMPONENTS_PROXYSOCKS_IPADDR * penIPAddr, CHAR * ptszClientAddr, int* pInt_Port);
/********************************************************************
函数名称：ProxyProtocol_SocksCore_HdrPacket
函数功能：打包一条协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的内容
 参数.三：pInt_Len
  In/Out：In
  类型：整数型指针
  可空：N
  意思：输出包大小
 参数.四：byValue
  In/Out：In
  类型：字节型
  可空：N
  意思：输入打包的值
返回值
  类型：逻辑型
  意思：是否成功
备注：根据状态自动打包协议
      ENUM_RFCCOMPONENTS_PROXY_STATUS_AUTH:参数4表示服务器验证类型
      ENUM_RFCCOMPONENTS_PROXY_STATUS_USER:参数4表示验证成功还是失败
      ENUM_RFCCOMPONENTS_PROXY_STATUS_CONNECT:参数4表示处理连接的结果
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksCore_HdrPacket(LPCSTR lpszClientID, CHAR* ptszMsgBuffer, int* pInt_Len, BYTE byValue);
//////////////////////////////////////////////////////////////////////////SOCKS客户端
/********************************************************************
函数名称：ProxyProtocol_SocksClient_AuthPacket
函数功能：创建一个验证请求协议包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出创建好的包
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出包大小
 参数.三：penAuth
  In/Out：In
  类型：枚举型指针
  可空：N
  意思：输入客户端支持的验证类型列表
 参数.四：nCount
  In/Out：In
  类型：整数型
  可空：N
  意思：输入验证类型个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksClient_AuthPacket(CHAR* ptszMsgBuffer, int* pInt_Len, ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH* penAuth, int nCount);
/********************************************************************
函数名称：ProxyProtocol_SocksClient_AuthParse
函数功能：处理验证请求返回的数据
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：服务器返回的数据
 参数.二：penAuth
  In/Out：Out
  类型：枚举型指针
  可空：N
  意思：导出服务器返回需要的验证的类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksClient_AuthParse(LPCSTR lpszMsgBuffer, ENUM_RFCCOMPONENTS_PROXYSOCKS_AUTH * penAuth);
/********************************************************************
函数名称：ProxyProtocol_SocksClient_LoginPacket
函数功能：创建一个登录包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出创建好的包
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出包大小
 参数.三：lpszUserName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：用户名,如果想要匿名登录,最后两个参数可以为NULL
 参数.四：lpszUserPass
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：密码
返回值
  类型：逻辑型
  意思：是否成功
备注：如果是匿名登录,此步骤忽略
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksClient_LoginPacket(CHAR* ptszMsgBuffer, int* pInt_Len, LPCSTR lpszUserName = NULL, LPCSTR lpszUserPass = NULL);
/********************************************************************
函数名称：ProxyProtocol_SocksClient_LoginParse
函数功能：处理用户密码登录后返回的协议数据
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：代理服务器返回的数据
返回值
  类型：逻辑型
  意思：是否成功
备注：登录成功返回真,登录失败返回假
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksClient_LoginParse(LPCSTR lpszMsgBuffer);
/********************************************************************
函数名称：ProxyProtocol_SocksClient_ConnectPacket
函数功能：创建一个最后请求建立代理信息包
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出创建好的包
 参数.二：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出包大小
 参数.三：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：IP地址或者域名,为了服务器处理速度,建议使用IP地址
 参数.四：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：要访问的服务提供的端口
 参数.五：enCommand
  In/Out：In
  类型：枚举型
  可空：Y
  意思：要请求的创建网络类型
 参数.六：enIPAddr
  In/Out：In
  类型：枚举型
  可空：Y
  意思：参数三的类型
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksClient_ConnectPacket(CHAR* ptszMsgBuffer, int* pInt_Len, LPCSTR lpszIPAddr, int nPort, ENUM_RFCCOMPONENTS_PROXYSOCKS_COMMAND enCommand = ENUM_RFCCOMPONENTS_PROXYSOCKS_COMMAND_CONNECT, ENUM_RFCCOMPONENTS_PROXYSOCKS_IPADDR enIPAddr = ENUM_RFCCOMPONENTS_PROXYSOCKS_IPADDR_IPV4);
/********************************************************************
函数名称：ProxyProtocol_SocksClient_ConnectParse
函数功能：处理发送COMMAND连接命令服务器返回的数据
 参数.一：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：代理服务器返回的数据
 参数.二：pInt_ErrorCode
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：失败,参考导出头的类型定义
返回值
  类型：逻辑型
  意思：是否成功
备注：成功参数2不起作用,执行完这一步骤,可以直接转发数据了
*********************************************************************/
extern "C" BOOL ProxyProtocol_SocksClient_ConnectParse(LPCSTR lpszMsgBuffer, int* pInt_ErrorCode = NULL);
/************************************************************************/
/*                     隧道代理服务                                     */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////隧道代理服务端
/********************************************************************
函数名称：ProxyProtocol_TunnelCore_Create
函数功能：创建一个隧道代理客户端
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_TunnelCore_Create(LPCSTR lpszClientID);
/********************************************************************
函数名称：ProxyProtocol_TunnelCore_Delete
函数功能：删除一个指定的客户端
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_TunnelCore_Delete(LPCSTR lpszClientID);
/********************************************************************
函数名称：ProxyProtocol_TunnelCore_SetInfo
函数功能：设置客户端信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：lParam
  In/Out：In
  类型：无类型指针
  可空：N
  意思：输入要设置的内容
 参数.三：nLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入自定义内容大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_TunnelCore_SetInfo(LPCSTR lpszClientID, LPVOID lParam, int nLen);
/********************************************************************
函数名称：ProxyProtocol_TunnelCore_SetInfo
函数功能：设置客户端信息
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：lParam
  In/Out：Out
  类型：无类型指针
  可空：N
  意思：输出获取到的内容
 参数.三：pInt_Len
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出自定义内容大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_TunnelCore_GetInfo(LPCSTR lpszClientID, LPVOID lParam, int* pInt_Len = NULL);
/********************************************************************
函数名称：ProxyProtocol_TunnelCore_Parse
函数功能：解析客户端的隧道代理协议
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入客户端ID
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的内容
 参数.三：nMsgLen
  In/Out：In
  类型：整数型
  可空：N
  意思：输入内容大小
 参数.四：ptszIPAddr
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出解析到的地址,可能是IP或者域名
 参数.五：pInt_Port
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出得到的端口
 参数.六：ptszUserInfo
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出解析到的用户验证信息
 参数.七：pbConnect
  In/Out：Out
  类型：逻辑型指针
  可空：Y
  意思：输出为CONNECT协议,如果返回真表示是正常的代理协议
		但是某些时候有些程序不支持隧道代理会直接请求数据,此值会为假,表示对方没有请求CONNECT代理协议
		那么要不要继续交由调用者来继续
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_TunnelCore_Parse(LPCSTR lpszClientID, LPCSTR lpszMsgBuffer, int nMsgLen, CHAR* ptszIPAddr, int* pInt_Port, CHAR* ptszUserInfo, BOOL * pbConnect = NULL);
/********************************************************************
函数名称：ProxyProtocol_TunnelCore_Packet
函数功能：打包处理结果
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出打好包的内容
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：打包的大小
 参数.三：nHttpCode
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入结果,支持;200,400,401,500
返回值
  类型：逻辑型
  意思：是否成功
备注：xhNet
*********************************************************************/
extern "C" BOOL ProxyProtocol_TunnelCore_Packet(CHAR* ptszMsgBuffer, int* pInt_MsgLen, int nHttpCode = 200);
//////////////////////////////////////////////////////////////////////////隧道代理客户端
/********************************************************************
函数名称：ProxyProtocol_TunnelClient_Packet
函数功能：打包一段隧道代理请求
 参数.一：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出打好包的内容
 参数.二：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出大小
 参数.三：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入请求的地址和端口 ip:port
 参数.四：lpszAuth
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入验证信息,base64编码的 user:pass
 参数.五：lpszUserAgent
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入客户端信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL ProxyProtocol_TunnelClient_Packet(CHAR* ptszMsgBuffer, int* pInt_MsgLen, LPCSTR lpszIPAddr, LPCSTR lpszAuth = NULL, LPCSTR lpszUserAgent = NULL);