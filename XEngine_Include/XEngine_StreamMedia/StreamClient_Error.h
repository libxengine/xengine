﻿#pragma once
/********************************************************************
//	Created:	2020/07/29  10:05:57
//	File Name: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_XClient\XClient_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_XClient
//	File Base:	XClient_Error
//	File Ext:	h
//  Project:    XEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	流媒体客户端导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       实时流推送服务导出错误
//////////////////////////////////////////////////////////////////////////
//原始流推送
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INIT_PARAMENT 0x90E0001       //参数错误
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INIT_MALLOC 0x90E0002         //申请内存失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INIT_CONNECTRTMP 0x90E0003    //连接RTMP服务器失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INIT_OPENSTREAM 0x90E0004     //打开流失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INIT_WRITEHDR 0x90E0005       //写入音视频头失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INITAV_FINDENCODEC 0x90E0010  //查找解码器失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INITAV_ALLOC 0x90E0011        //申请上下文失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INITAV_NEWSTREAM 0x90E0012    //新建流失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INITAV_COPYSTREAM 0x90E0013   //拷贝流信息失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INITAV_OPENCODEC 0x90E0014    //打开编码器失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INITAV_ALLOCFRAME 0x90E0015   //申请帧内存失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INITAV_ALLOCPACKET 0x90E0016  //申请包内存失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_INITAV_FILLBUFFER 0x90E0017   //填充缓冲区失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_PUSH_PARAMENT 0x90E0020       //参数错误,推送流失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_PUSH_NOTFOUND 0x90E0021       //没有找到句柄
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_PUSH_RESAMPLE 0x90E0022       //重采样失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_PUSH_AUDIO 0x90E0023          //音频没有准备好
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_PUSH_SEND 0x90E0024           //发送给编码器失败,不是标准的YUV数据
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_PUSH_RECV 0x90E0025           //接受编码数据失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_PUSH_WRITE 0x90E0026          //推送数据给RTMP服务器失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_RESAMPLE_MALLOC 0x90E0030     //申请内存失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPUSH_RESAMPLE_INIT 0x90E0031       //初始化失败
///裸码流推流
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_INIT_PARAMENT 0x90E0101        //参数错误
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_INIT_MALLOC 0x90E0102          //申请内存失败
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_INIT_OUTPUT 0x90E0103          //初始化输出格式失败
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_INIT_CONNECT 0x90E0104         //连接到流媒体服务失败
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_WRITEHDR_NOTFOUND 0x90E0110    //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_WRITEHDR_WRITEHDR 0x90E0111    //写入头失败
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHVIDEO_PARAMENT 0x90E0120   //推流失败,参数错误
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHVIDEO_NOTFOUND 0x90E0121   //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHVIDEO_MAXBUFFER 0x90E0122  //内部缓冲区已满,无法继续
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHVIDEO_CLOSE 0x90E0123      //推流端被强制关闭
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHAUDIO_PARAMENT 0x90E0130   //参数错误
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHAUDIO_NOTFOUND 0x90E0131   //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHAUDIO_CLOSE 0x90E0132      //推流端被关闭
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHAUDIO_MALLOC 0x90E0133     //申请内存失败
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_PUSHAUDIO_MAXBUFFER 0x90E0134  //最大缓冲区,无法继续
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_WRITETAIL_NOTFOUND 0x90E0140   //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_WRITETAIL_WRITE 0x90E0141      //写入尾部失败
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_OPEN_NOTFOUND 0x90E0150        //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_OPEN_OPEN 0x90E0151            //打开失败
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_OPEN_WRITEHDR 0x90E0152        //写入头失败
#define ERROR_STREAMMEDIA_XCLIENT_CODECPUSH_GETAVEXT_NOTFOUND 0x90E01A0    //获取扩展信息失败,没有找到
//////////////////////////////////////////////////////////////////////////
//                       文件流推送服务导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INIT_PARAMENT 0x90E1001       //参数错误
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INIT_MALLOC 0x90E1002         //申请内存失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INIT_FILTER 0x90E1003         //初始化过滤器失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INPUT_NOTFOUND 0x90E1010      //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INPUT_OPENVIDEO 0x90E1011     //打开视频文件失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INPUT_FINDVIDEO 0x90E1012     //查找视频流失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INPUT_MALLOCVIDEO 0x90E1013   //申请视频内存失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INPUT_OPENAUDIO 0x90E1014     //打开音频文件失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INPUT_FINDAUDIO 0x90E1015     //查找音频流失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_INPUT_MALLOCAUDIO 0x90E1016   //申请音频内存失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_OUTPUT_NOTFOUND 0x90E1020     //输出失败,没有找到
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_OUTPUT_OPENURL 0x90E1021      //打开URL失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_OUTPUT_COPYARGS 0x90E1022     //拷贝参数失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_OUTPUT_COPYTO 0x90E1023       //拷贝到目标失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_OUTPUT_COPYFROM 0x90E1024     //从源拷贝失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_OUTPUT_COPYIN 0x90E1025       //拷贝流参数到编码器失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_OUTPUT_COPYOUT 0x90E1026      //输出流参数失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_OUTPUT_INIT 0x90E1027         //初始化过滤器失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_OUTPUT_CONNECT 0x90E1028      //连接推流服务失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_GETSTATUS_PARAMENT 0x90E1030  //获取状态失败,参数错误
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_GETSTATUS_NOTFOUND 0x90E1031  //没有找到指定的通道
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_START_NOTFOUND 0x90E1040      //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_START_WRITEHDR 0x90E1041      //写入头失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_START_THREAD 0x90E1042        //启用线程失败
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_PUSH_NOTFOUND 0x90E1050       //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_PUSH_MALLOC 0x90E1051         //申请内存
#define ERROR_STREAMMEDIA_XCLIENT_FILEPUSH_PUSH_MOREPKT 0x90E1052        //太多包没有处理
//////////////////////////////////////////////////////////////////////////
//                       流获取服务导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_INIT_PARAMENT 0x90E2001     //参数错误,初始化失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_INIT_MALLOC 0x90E2002       //申请内存失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_INIT_OPENSTREAM 0x90E2003   //打开流失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_INIT_FINDSTREAM 0x90E2004   //查找流失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_INIT_CREATE 0x90E2005       //创建流失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_INIT_MALLOCOUT 0x90E2006    //申请输出内存失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_INIT_NEWSTREAM 0x90E2007    //信件流失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_INIT_COPYSTREAM 0x90E2008   //拷贝流失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_INIT_FILTER 0x90E2009       //初始化分离器失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_GETSTATUS_PARAMENT 0x90E2020//参数错误
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_GETSTATUS_NOTFOUND 0x90E2021//没有找到
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_START_NOTFOUND 0x90E2030     //没有找到指定句柄
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_START_WRITEHDR 0x90E2031     //写入头失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_START_CREATETHREAD 0x90E2032 //创建线程失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_PUSH_NOTFOUND 0x90E2040      //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_PUSH_OPENURL 0x90E2041       //打开URL失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_PUSH_COPYARGS 0x90E2042      //参数拷贝错误
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_PUSH_CONNECT 0x90E2043       //连接到服务器失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_PUSH_WRITEHDR  0x90E2044     //写媒体头失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_PUSH_MALLOC 0x90E2045        //申请内存失败
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_GETSTREAM_NOTFOUND 0x90E2050 //没有找到
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_GETSTREAM_CALLSET 0x90E2051  //回调函数被设置,无法调用此函数
#define ERROR_STREAMMEDIA_XCLIENT_STREAMPULL_GETSTREAM_FAILED 0x90E2052   //内部错误,可能连接已经关闭