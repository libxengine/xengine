#pragma once
/********************************************************************
//	Created:	2011/11/07  10:20
//	Filename:       ./NetSocketEngine/NetSocketEngine/NetClientEngine/NetClient_XSsl/NetClient_XSsl_Error.h
//	File Path:	./NetSocketEngine/NetSocketEngine/NetClientEngine/NetClient_XSsl/
//	File Base:	NetClient_XSsl
//	File Ext:	h
//      Project:        NetSocketEnginer(网络通信引擎 For Linux)
//	Author:		Dowflyon
//	Purpose:	安全加解密支持客户端模块错误定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                     SSL客户端操作处理导出错误表
//////////////////////////////////////////////////////////////////////////
#define ERROR_XCLIENT_SSL_CLIENT_INIT_UNKNOWPROTOCOL 0x50B0001   //无法识别的协议库
#define ERROR_XCLIENT_SSL_CLIENT_INIT_CACERTLOAD 0x50B0002       //加载CA签名证书失败
#define ERROR_XCLIENT_SSL_CLIENT_INIT_CERTFILELOAD 0x50B0003     //加载自己的证书失败
#define ERROR_XCLIENT_SSL_CLIENT_INIT_KEYFILELOAD 0x50B0004      //加载密钥失败
#define ERROR_XCLIENT_SSL_CLIENT_INIT_NOTMATCH 0x50B0005         //证书和密钥不匹配，无法继续
#define ERROR_XCLIENT_SSL_CLIENT_INIT_CREATESSL 0x50B0006        //新建SSL失败
#define ERROR_XCLIENT_SSL_CLIENT_CONN_PARAMENT 0x50B0010         //参数错误,无法继续连接SSL
#define ERROR_XCLIENT_SSL_CLIENT_CONN_SETMAP 0x50B0011           //设置关联句柄失败
#define ERROR_XCLIENT_SSL_CLIENT_CONN_SSLCONNECT 0x50B0012       //打开SSL安全连接通道失败
#define ERROR_XCLIENT_SSL_CLIENT_CONN_GETSUBJECT 0x50B0013       //获取服务器证书拥有者信息失败
#define ERROR_XCLIENT_SSL_CLIENT_CONN_GETISSUER 0x50B0014        //获取服务器证书颁发者信息失败
#define ERROR_XCLIENT_SSL_CLIENT_CONN_GETALGORITHM 0x50B0015     //获取服务器使用的加密算法失败
#define ERROR_XCLIENT_SSL_CLIENT_SENDMSG_PARAMENT 0x50B0020      //参数错误,无法继续
#define ERROR_XCLIENT_SSL_CLIENT_SENDMSG_CLOSE 0x50B0021         //服务端关闭,无法发送数据
#define ERROR_XCLIENT_SSL_CLIENT_SENDMSG_WRITE 0x50B0022         //发送数据失败
#define ERROR_XCLIENT_SSL_CLIENT_RECVMSG_PARAMENT 0x50B0031      //参数错误,无法继续
#define ERROR_XCLIENT_SSL_CLIENT_RECVMSG_FAILED 0x50B0032        //接受数据失败
#define ERROR_XCLIENT_SSL_CLIENT_RECVMSG_CLOSE 0x50B0033         //服务器关闭
#define ERROR_XCLIENT_SSL_CLIENT_EX_MALLOC 0x50B0040             //申请内存失败
#define ERROR_XCLIENT_SSL_CLIENT_EX_NOTFOUND 0x50B0041           //没有找到指定句柄
/************************************************************************/
/*                     VPN客户端错误                                    */
/************************************************************************/
#define ERROR_XCLIENT_SSL_VPN_STATUS_NOTFOUND 0x50B1000          //获取状态失败，没有这个VPN
#define ERROR_XCLIENT_SSL_VPN_CONNECT_ENTRYPRO 0x50B1012         //设置属性页失败
#define ERROR_XCLIENT_SSL_VPN_CONNECT_SETPARAMS 0x50B1013        //设置RASVPN参数失败
#define ERROR_XCLIENT_SSL_VPN_CONNECT_RASDIAL 0x50B1014          //异步拨号失败
#define ERROR_XCLIENT_SSL_VPN_CONNECT_TIMEDOUT 0x50B1015         //拨号超时
#define ERROR_XCLIENT_SSL_VPN_CLOSE_HANGUP 0x50B1016             //关闭连接失败
#define ERROR_XCLIENT_SSL_VPN_CLOSE_NOTFOUND 0x50B1017           //没有找到需要关闭的索引VPN
#define ERROR_XCLIENT_SSL_VPN_STATUS_ISFAILED 0x50B1018          //获取状态失败