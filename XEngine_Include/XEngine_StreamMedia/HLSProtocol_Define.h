﻿#pragma once
/********************************************************************
//	Created:	2020/08/14  15:52:57
//	File Name: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_HLSProtocol\HLSProtocol_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_HLSProtocol
//	File Base:	HLSProtocol_Define
//	File Ext:	h
//  Project:    XEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	HLS协议模块导出
//	History:
*********************************************************************/
///////////////////////////////////////////////////////////////////////////////
//                               导出的定义
///////////////////////////////////////////////////////////////////////////////
#define XENGINE_STREAMMEDIA_HLS_TSPID_PAT 0x0000                               //PAT表定义了我们当前TS流中所有的节目
#define XENGINE_STREAMMEDIA_HLS_TSPID_CAT 0x0001
#define XENGINE_STREAMMEDIA_HLS_TSPID_TSDT 0x0002
//0003-000F预留
#define XENGINE_STREAMMEDIA_HLS_TSPID_NIT 0x0010                               //NIT,ST
#define XENGINE_STREAMMEDIA_HLS_TSPID_SDT 0x0011                               //SDT,BAT,ST
#define XENGINE_STREAMMEDIA_HLS_TSPID_EIT 0x0012                               //EIT,ST
#define XENGINE_STREAMMEDIA_HLS_TSPID_RST 0x0013                               //RST,ST
#define XENGINE_STREAMMEDIA_HLS_TSPID_TDT 0x0014                               //TDT,TOT,ST
#define XENGINE_STREAMMEDIA_HLS_TSPID_SYNCNET 0x0015                           //网络同步
//0016-001B预留
#define XENGINE_STREAMMEDIA_HLS_TSPID_TUP 0x001C                               //带内信令
#define XENGINE_STREAMMEDIA_HLS_TSPID_DIT 0x001E                               //
#define XENGINE_STREAMMEDIA_HLS_TSPID_SIT 0x001F                               //
///////////////////////////////////////////////////////////////////////////////
//                               导出的函数
///////////////////////////////////////////////////////////////////////////////
extern "C" XLONG HLSProtocol_GetLastError(int *pInt_SysError = NULL);
/******************************************************************************
                             M3U8文件处理导出函数
******************************************************************************/
/********************************************************************
函数名称：HLSProtocol_M3u8File_Create
函数功能：初始化M3U8文件
 参数.一：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出创建成功的M3U8文件句柄
 参数.二：lpszFileName
  In/Out：In
  类型：输入
  可空：N
  意思：输入要创建的主M3U8文件路径
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_M3u8File_Create(XNETHANDLE* pxhToken, LPCXSTR lpszFileName);
/********************************************************************
函数名称：HLSProtocol_M3u8File_Delete
函数功能：删除一个流
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：要删除的流句柄
 参数.二：xhSub
  In/Out：In
  类型：句柄
  可空：Y
  意思：要删除的流的子句柄,如果为0,表示全部删除
 参数.三：bDelFile
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否删除文件
返回值
  类型：逻辑型
  意思：是否成功
备注：你需要先关闭HLS的块句柄删除文件才有效
*********************************************************************/
extern "C" bool HLSProtocol_M3u8File_Delete(XNETHANDLE xhToken, XNETHANDLE xhSub = 0, bool bDelFile = false);
/********************************************************************
函数名称：HLSProtocol_M3u8File_AddStream
函数功能：添加一个流
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要为哪个M3U8添加流
 参数.二：pxhToken
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出的流句柄
 参数.三：lpszSubFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入流文件位置
 参数.四：nBindWidth
  In/Out：In
  类型：整数型
  可空：N
  意思：输入此流的带宽大小,用于标示此为标清,高清,等
 参数.五：nSeq
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入开始的序列号
 参数.六：nTimeSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：输入此流最大分片时间.时间越长延迟越高
 参数.七：nListSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：列表最大个数
 参数.八：bVod
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是文件还是实时流
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_M3u8File_AddStream(XNETHANDLE xhToken, XNETHANDLE* pxhToken, LPCXSTR lpszSubFile, LPCXSTR lpszUrl, int nBindWidth, int nSeq = 1, int nTimeSize = 10, int nListSize = 100, bool bVod = true);
/********************************************************************
函数名称：HLSProtocol_M3u8File_AddFile
函数功能：添加TS文件到指定流中
 参数.一：xhToken
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的主文件
 参数.二：xhSub
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的流
 参数.三：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：文件名称
 参数.四：dlTime
  In/Out：In
  类型：浮点型
  可空：Y
  意思：输入此视频文件的时长
 参数.五：bEndFile
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：添加是否结束,结束最后三个参数无效
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_M3u8File_AddFile(XNETHANDLE xhToken, XNETHANDLE xhSub, LPCXSTR lpszFileName = NULL, double dlTime = 0, bool bEndFile = true);
/******************************************************************************
                             TS解析处理导出函数
******************************************************************************/
/********************************************************************
函数名称：HLSProtocol_TSParse_Init
函数功能：初始化包解析工具
 参数.一：nPoolCount
  In/Out：In
  类型：整数型
  可空：N
  意思：创建的分布式任务池个数
 参数.二：bPKTCount
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：包导出方式,真为获取完整的包导出,假为每次都导出
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_TSParse_Init(int nPoolCount, bool bPKTCount = true);
/********************************************************************
函数名称：RTMPProtocol_Parse_Destory
函数功能：销毁包队列解析器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_TSParse_Destory();
/********************************************************************
函数名称：HLSProtocol_TSParse_Insert
函数功能：插入一个客户端到TS解析器中
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_TSParse_Insert(LPCXSTR lpszClientID);
/********************************************************************
函数名称：HLSProtocol_TSParse_delete
函数功能：删除一个客户端从TS解析器中
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_TSParse_delete(LPCXSTR lpszClientID);
/********************************************************************
函数名称：HLSProtocol_TSParse_Send
函数功能：发送一段数据给解析器解析
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：lpszMsgBuffer
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的数据
 参数.三：nMsgLen
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要解析的大小
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_TSParse_Send(LPCXSTR lpszClientID, LPCXSTR lpszMsgBuffer, int nMsgLen);
/********************************************************************
函数名称：HLSProtocol_TSParse_Recv
函数功能：接受获取一段数据
 参数.一：lpszClientID
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要操作的客户端
 参数.二：pptszMsgBuffer
  In/Out：Out
  类型：字符指针的指针
  可空：N
  意思：输出获取到的数据,需要手动释放内存
 参数.三：pInt_MsgLen
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出数据大小
 参数.四：pbyAVType
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出类型,0,视频,1音频
 参数.五：pInt_PTSTime
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出PTS时间戳
 参数.六：pInt_DTSTime
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：输出DTS时间戳
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_TSParse_Recv(LPCXSTR lpszClientID, XCHAR* ptszMsgBuffer, int* pInt_MsgLen, XBYTE * pbyAVType, __int64u * pInt_PTSTime = NULL, __int64u * pInt_DTSTime = NULL);
/********************************************************************
函数名称：HLSProtocol_TSParse_GetPool
函数功能：通过任务池获取可处理的列表
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：N
  意思：输入要处理的索引
 参数.二：pppSt_ListAddr
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出待处理的列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：指数型指针
  可空：N
  意思：导出列表的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_TSParse_GetPool(int nPoolIndex, XENGINE_MANAGEPOOL_TASKEVENT*** pppSt_ListAddr, int* pInt_ListCount);
/************************************************************************
函数名称：HLSProtocol_TSParse_WaitEvent
函数功能：等待一个数据事件发生
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布式池索引
 参数.二：nTimeOut
  In/Out：In
  类型：整数型
  可空：Y
  意思：超时时间,单位毫秒 -1 不超时,0立即返回 > 0等待事件
返回值
  类型：逻辑型
  意思：是否等待成功
备注：
************************************************************************/
extern "C" bool HLSProtocol_TSParse_WaitEvent(int nPoolIndex, int nTimeOut = -1);
/********************************************************************
函数名称：HLSProtocol_TSParse_ActiveEvent
函数功能：手动触发一次事件
 参数.一：nPoolIndex
  In/Out：In
  类型：整数型
  可空：Y
  意思：分布池索引
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool HLSProtocol_TSParse_ActiveEvent(int nPoolIndex);