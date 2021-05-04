#pragma once
/********************************************************************
//	Created:	2013/2/1  17:20
//	File Name: 	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthRegCrypt\AuthRegCrypt_Error.h
//	File Path:	G:\U_DISK_Path\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AuthorizeReg\NetEngine_AuthRegCrypt
//	File Base:	AuthRegCrypt_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	密钥库导出错误表
//	History:
*********************************************************************/
/************************************************************************/
/*                          加解密错误导出                              */
/************************************************************************/
#define ERROR_AUTHORIZEREG_CRYPT_ENCODER_ENCODER_PARAMENT 0x30C0010      //加密数据失败，参数错误
#define ERROR_AUTHORIZEREG_CRYPT_DECODER_DECODER_PARAMENT 0x30C0020      //参数错误解密失败
/************************************************************************/
/*                           验证错误导出                               */
/************************************************************************/
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_CREATE 0x30C1000    //创建验证信息本地数据失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_ADDNAME 0x30C1001   //添加应用名称失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_ADDVER 0x30C1002    //添加版本号失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_ADDCONN 0x30C1003   //添加连接信息失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SETPORT 0x30C1004   //设置端口失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_ADDREG 0x30C1005    //添加注册信息失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SETTYPE 0x30C1006   //设置硬件码类型失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SETREGTYPE 0x30C1007//设置注册类型失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_ADDTIMER 0x30C1008  //添加注册时间信息失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SETHAVETIME 0x30C1009//设置拥有时间失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SETLEFTTIME 0x30C100A//设置超时时间失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SETKEYCUSTOM 0x30C100B //设置自定义数据失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SETUSER 0x30C100C   //设置用户信息失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SETCONTACT 0x30C100D//设置联系方式失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SETUSERCUSTOM 0x30C100E//设置自定义用户数据失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEFILE_SAVEDAT 0x30C100F   //保存为数据文件失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_OPENFILE 0x30C1010   //打开目标文件失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_NAME 0x30C1011       //获取名称失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_VER 0x30C1012        //获取版本号失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_CONNADDR 0x30C1013   //获取连接地址失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_CONNPORT 0x30C1014   //获取连接端口失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_AUTHCODE 0x30C1015   //获取硬件码失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_AUTHTIMER 0x30C1016  //获取注册时间失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_AUTHHTIME 0x30C1017  //获取拥有时间失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_AUTHLTIME 0x30C1018  //获取过期时间失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_AUTHKEYCUTOM 0x30C1019  //获取自定义数据失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_AUTHUSER 0x30C101A   //获取用户信息失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_AUTHCONTACT 0x30C101B//获取联系方式失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READFILE_AUTHUSERCUSTOM 0x30C101C//获取用户自定义数据失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_GETLEFT_PARAMENT 0x30C1020    //参数错误
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_GETLEFT_NOTREG 0x30C1021      //没有注册
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_GETLEFT_NOTHASTIME 0x30C1022  //没有可用时间
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_GETLEFT_NOTSUPPORT 0x30C1023  //不支持的获取类型
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_GETLEFT_TIMEOUT 0x30C1024     //CDKEY已经超时,没有可用时间
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEKEY_PARAMENT 0x30C1030   //写到文件失败，参数错误
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEKEY_OPENSRC 0x30C1031    //读取待加密的文件失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEKEY_READLEN 0x30C1032    //待加密的文件长度错误
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEKEY_OPENDST 0x30C1033    //打开文件失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_WRITEKEY_WRITE 0x30C1034      //写加密数据失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READKEY_PARAMENT 0x30C1040    //参数错误，读取数据验证文件失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READKEY_OPENSRC 0x30C1041     //打开文件失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READKEY_READLEN 0x30C1042     //读取文件失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READKEY_OPENDST 0x30C1043     //保存到文件失败
#define ERROR_AUTHORIZEREG_CRYPT_LOCALAUTH_READKEY_WRITE 0x30C1044       //写到文件失败