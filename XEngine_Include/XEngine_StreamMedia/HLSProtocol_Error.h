#pragma once
/********************************************************************
//	Created:	2020/08/14  15:52:38
//	File Name: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_HLSProtocol\HLSProtocol_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_HLSProtocol
//	File Base:	HLSProtocol_Error
//	File Ext:	h
//  Project:    XEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	HLS切片打包模块导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       HLS切片导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_INIT_PARAMENT 0x140B0001     //参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_INIT_MALLOC 0x140B0002       //申请内存失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_INPUT_NOTFOUND 0x140B0010    //没有找到
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_INPUT_OPENFILE 0x140B0011    //打开文件失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_INPUT_NOTSTREAM 0x140B0012   //查找流失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_INPUT_MALLOC 0x140B0013      //申请内存失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_OUTPUT_NOTFOUND 0x140B0020   //没有找到
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_OUTPUT_OPENTS 0x140B0021     //打开TS转换器失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_START_NOTFOUND 0x140B0030    //没有找到
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_START_NESSTREAM 0x140B0031   //信件流失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_START_COPYPARAM 0x140B0032   //拷贝参数失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_START_CREATETHREAD 0x140B0033//创建线程失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_GETSTATUS_PARAMENT 0x140B0040//参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_SEG_GETSTATUS_NOTFOUND 0x140B0041//没有找到
//////////////////////////////////////////////////////////////////////////
//                       M3U8文件处理导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_CREATE_PARAMENT 0x140B1001//参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_CREATE_MALLOC 0x140B1002  //申请内存失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDSTREAM_PARAMENT 0x140B1010 //参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDSTREAM_NOTFOUND 0x140B1011 //查找失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDSTREAM_MALLOC 0x140B1012   //申请内存失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDSTREAM_CREATEFILE 0x140B1013//创建文件失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDFILE_PARAMENT 0x140B1020   //参数错误
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDFILE_NOTFOUND 0x140B1021   //没有找到句柄
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_ADDFILE_NOTSUB 0x140B1022     //没有找到流
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_CLEAR_CREATEFILE 0x140B10A0   //创建文件失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_CLEAR_WRITE 0x140B10A1        //写入数据失败
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_DELETE_NOTROOT 0x140B10B0     //没有主句柄
#define ERROR_STREAMMEDIA_HLSPROTOCOL_M3U8_DELETE_NOTSUB 0x140B10B1      //没有子句柄
