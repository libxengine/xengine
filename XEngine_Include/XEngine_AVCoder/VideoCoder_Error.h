#pragma once
/********************************************************************
//	Created:	2018/8/31   10:18
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_VideoCoder\VideoCoder_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_VideoCoder
//	File Base:	VideoCoder_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	视频编解码器导出错误定义
//	History:
*********************************************************************/
/************************************************************************/
/*                       实时流编解码错误                               */
/************************************************************************/
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENINIT_PARAMENT 0x40D0000     //初始化失败,参数错误
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENINIT_FINDCODER 0x40D0001    //查找编码器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENINIT_MALLOCCODEC 0x40D0002  //申请内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENINIT_OPEN 0x40D0003         //打开编码器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENINIT_MALLOCFRAME 0x40D0004  //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENINIT_MALLOCPACKET 0x40D0006 //申请PAKCET内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENCODEC_PARAMENT 0x40D0010    //参数错误
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENCODEC_NOTFOUND 0x40D0011    //没有找到句柄
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENCODEC_VIDEO 0x40D0011       //编码视频失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENCODEC_NOFINISH 0x40D0012    //没有完成
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_ENCODEC_EAGAIN 0x40D0013      //缓冲区不足够编码,请继续压入数据
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DEINIT_PARAMENT 0x40D0020     //参数错误,初始化解码器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DEINIT_FINDCODER 0x40D0021    //没有找到指定解码器
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DEINIT_PARERS 0x40D0022       //解析解码器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DEINIT_MALLOCCODEC 0x40D0023  //申请解码器内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DEINIT_OPEN 0x40D0024         //打开解码器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DEINIT_MALLOCFRAME 0x40D0025  //申请帧内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DEINIT_MALLOCPACKET 0x40D0026 //申请报内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DEINIT_HWCONFIG 0x40D0027     //配置失败,可能你的电脑不支持硬件编解码
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DEINIT_HWCREATE 0x40D0028     //创建硬件编解码器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DECODEC_PARAMENT 0x40D0020    //解码失败,参数错误
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DECODEC_NOTFOUND 0x40D0021    //没有找到句柄解码失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DECODEC_PARSE 0x40D0021       //解析失败,可能不是一个完整的视频包
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_DECODEC_MALLOC 0x40D0022      //申请解码器内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_GETINFO_PARAMENT 0x40D0030    //获取信息失败,参数错误
#define ERROR_XENGINE_AVCODEC_VIDEO_STREAM_GETINFO_NOTFOUND 0x40D0031    //没有找到句柄
/************************************************************************/
/*                       帮助函数错误                                   */
/************************************************************************/
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_GETLIST_PARAMENT 0x40D1000     //参数错误,获取失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_CVTINIT_PARAMENT 0x40D1010     //没有找到句柄
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_CVTINIT_SRCMALLOC 0x40D1011    //申请内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_CVTINIT_DSTMALLOC 0x40D1012    //申请内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_CVTINIT_GETCTX 0x40D1013       //获取转换上下文失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_CVT_NOTFOUND 0x40D1020         //没有找到
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_CVT_FAILED 0x40D1021           //转换失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_CVT_LEN 0x40D1022              //缓冲区太小了
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERINIT_PARAMENT 0x40D1030  //参数错误
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERINIT_MALLOC 0x40D1031    //申请内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERINIT_SRCCREATE 0x40D1031 //创建原始过滤器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERINIT_DSTCREATE 0x40D1032 //创建目标过滤器失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERINIT_PARSE 0x40D1033     //解释失败,无法继续
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERINIT_CHECK 0x40D1034     //检查参数错误,无法继续
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERCVT_PARAMENT 0x40D1040   //参数错误
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERCVT_NOTFOUND 0x40D1041   //没有找到指定句柄
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERCVT_ADDFRAME 0x40D1042   //添加过滤器到帧失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERCVT_GETFRAME 0x40D1043   //从添加的过滤器帧中获取新帧失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERCVT_MALLOC 0x40D1044     //申请内存失败
#define ERROR_XENGINE_AVCODEC_VIDEO_HELP_FILTERCVT_LEN 0x40D1045        //提供的缓冲区太小
