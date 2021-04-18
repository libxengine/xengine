#pragma once
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
typedef int(*CALLBACK_XENGINE_STREAMMEDIA_HLSPROTOCOL_FILEREAD)(LPVOID lParam, uint8_t* puszMsgBuffer, int nSize);
typedef void(CALLBACK* CALLBACK_XENGINE_STREAMMEDIA_HLSPROTOCOL_FILENOTIFY)(LPCSTR lpszFileName, double dlTime, int nIndex, LPVOID lParam);
///////////////////////////////////////////////////////////////////////////////
//                               导出的函数
///////////////////////////////////////////////////////////////////////////////
extern "C" DWORD HLSProtocol_GetLastError(int *pInt_SysError = NULL);
/******************************************************************************
                             TS封装处理导出函数
******************************************************************************/
/********************************************************************
函数名称：HLSProtocol_Section_Init
函数功能：推送一个H264文件到服务器中去
 参数.一：pxhNet
  In/Out：Out
  类型：通道句柄
  可空：N
  意思：推送后导出这个通道的唯一句柄
 参数.二：nTimeSize
  In/Out：In
  类型：整数型
  可空：Y
  意思：分割时间大小,越大延迟越高
 参数.三：fpCall_FileNotify
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：当有文件被创建成功,这个回调被触发
 参数.四：lPNotify
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HLSProtocol_Section_Init(XNETHANDLE* pxhNet, int nTimeSize = 10, CALLBACK_XENGINE_STREAMMEDIA_HLSPROTOCOL_FILENOTIFY fpCall_FileNotify = NULL, LPVOID lPNotify = NULL);
/********************************************************************
函数名称：HLSProtocol_Section_Input
函数功能：输入数据信息设置
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的句柄
 参数.二：lpszVideoFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：视频编码文件位置
 参数.三：lpszAudioFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：音频编码文件位置
 参数.四：fpCall_VideoRead
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：如果不为NULL,表示视频数据从回调函数读取(只能是编码好的数据)
 参数.五：fpCall_AudioRead
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：如果不为NULL,表示音频数据从回调函数读取(只能是编码好的数据)
 参数.六：lPVideo
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
 参数.七：lPAudio
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HLSProtocol_Section_Input(XNETHANDLE xhNet, LPCSTR lpszVideoFile = NULL, LPCSTR lpszAudioFile = NULL, CALLBACK_XENGINE_STREAMMEDIA_HLSPROTOCOL_FILEREAD fpCall_VideoRead = NULL, CALLBACK_XENGINE_STREAMMEDIA_HLSPROTOCOL_FILEREAD fpCall_AudioRead = NULL, LPVOID lPVideo = NULL, LPVOID lPAudio = NULL);
/********************************************************************
函数名称：HLSProtocol_Section_Output
函数功能：输出媒体数据信息设置
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的HLS流
 参数.二：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要输出到的位置
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HLSProtocol_Section_Output(XNETHANDLE xhNet, LPCSTR lpszFile);
/********************************************************************
函数名称：HLSProtocol_Section_Start
函数功能：开始进行推流
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的HLS流
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HLSProtocol_Section_Start(XNETHANDLE xhNet);
/********************************************************************
函数名称：HLSProtocol_Section_GetStatus
函数功能：获取一个通道的传输状态
 参数.一：xhNet
  In/Out：In
  类型：通道句柄
  可空：N
  意思：要获取的通道状态的句柄
 参数.二：pbPush
  In/Out：Out
  类型：逻辑指针
  可空：N
  意思：导出是否正在传输,真是,假否
 参数.三：pInt_FrameIndex
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出当前帧
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HLSProtocol_Section_GetStatus(XNETHANDLE xhNet, BOOL* pbPush, int* pInt_FrameIndex = NULL);
/********************************************************************
函数名称：HLSProtocol_Section_Close
函数功能：关闭一个文件推流通道
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的通道句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" BOOL HLSProtocol_Section_Close(XNETHANDLE xhNet);
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
extern "C" BOOL HLSProtocol_M3u8File_Create(XNETHANDLE* pxhToken, LPCSTR lpszFileName);
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
extern "C" BOOL HLSProtocol_M3u8File_Delete(XNETHANDLE xhToken, XNETHANDLE xhSub = 0, BOOL bDelFile = FALSE);
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
extern "C" BOOL HLSProtocol_M3u8File_AddStream(XNETHANDLE xhToken, XNETHANDLE* pxhToken, LPCSTR lpszSubFile, LPCSTR lpszUrl, int nBindWidth, int nSeq = 1, int nTimeSize = 10, int nListSize = 100, BOOL bVod = TRUE);
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
extern "C" BOOL HLSProtocol_M3u8File_AddFile(XNETHANDLE xhToken, XNETHANDLE xhSub, LPCSTR lpszFileName = NULL, double dlTime = 0, BOOL bEndFile = TRUE);
