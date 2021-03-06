#pragma once
/********************************************************************
//	Created:	2019/4/11   15:58
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVPacket\AVPacket_Define.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_AvCoder\NetEngine_AVPacket
//	File Base:	AVPacket_Define
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	音视频文件封装模块导出函数
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                      回调函数
//////////////////////////////////////////////////////////////////////////
//读写回调,参数:自定义参数,缓冲区,缓冲区大小
typedef int(*CALLBACK_XENGINE_AVCODER_AVPACKET_FILEPACKET_FILERW)(LPVOID lParam, uint8_t* puszMsgBuffer, int nSize);
//转换器回调函数,参数:句柄,当前转换帧类型(-1未指定,0VIDEO,1AUDIO)(UNPack表示当前流索引),当前转换帧编号,当前转换时间,自定义参数
typedef void(CALLBACK *CALLBACK_NETENGINE_AVCODER_AVPACKET_NOTIFY)(XNETHANDLE xhNet, int nCvtType, int nCvtFrame, double dlTime, LPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                      数据结构
//////////////////////////////////////////////////////////////////////////
typedef struct
{
	CHAR tszFileName[MAX_PATH];                                          //文件地址,要获取list后设置这个值,写到文件是哪儿,如果是回调,表示写的媒体格式
	double dlAVTime;                                                      //媒体长度
	int nAVCodecType;                                                     //媒体类型
	int nAVCodecID;                                                       //媒体ID
	int nAVIndex;                                                         //流索引
	CALLBACK_XENGINE_AVCODER_AVPACKET_FILEPACKET_FILERW fpCall_Write;     //回调函数,写文件回调,如果为NULL 不通过数据回调
	LPVOID lParam;                                                        //自定义参数
}AVCODEC_PACKETLIST;
//////////////////////////////////////////////////////////////////////////
//                      导出函数声明
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD AVPacket_GetLastError(int *pInt_SysError = NULL);
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                      文件转换器导出函数                              */
/************************************************************************/
/********************************************************************
函数名称：AVPacket_FileConvert_Init
函数功能：初始化一个转换器
 参数.一：pxhNet
  In/Out：Out
  类型：通道句柄
  可空：N
  意思：导出转换器句柄
 参数.二：fpCall_FileConvert
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：转换器过程信息回调
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileConvert_Init(XNETHANDLE* pxhNet, CALLBACK_NETENGINE_AVCODER_AVPACKET_NOTIFY fpCall_FileConvert = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVPacket_FileConvert_Input
函数功能：输入要转换的媒体文件
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的转换器
 参数.二：lpszFile
  In/Out：In
  类型：常量字符还真
  可空：Y
  意思：输入要操作的文件路径
 参数.三：pdlAVTime
  In/Out：Out
  类型：浮点型指针
  可空：Y
  意思：输出媒体时间
 参数.四：fpCall_AVFile
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：设置为内存读取文件而不是文件方式
 参数.五：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileConvert_Input(XNETHANDLE xhNet, LPCSTR lpszFile = NULL, double* pdlAVTime = NULL, CALLBACK_XENGINE_AVCODER_AVPACKET_FILEPACKET_FILERW fpCall_AVFile = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVPacket_FileConvert_Output
函数功能：输出信息设置
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的转换器
 参数.二：lpszFile
  In/Out：In
  类型：常量字符还真
  可空：Y
  意思：输出的文件路径
 参数.三：fpCall_AVFile
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：输出到内存而不是文件,此函数不为NULL,参数2表示要转换到的文件格式
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileConvert_Output(XNETHANDLE xhNet, LPCSTR lpszFile = NULL, CALLBACK_XENGINE_AVCODER_AVPACKET_FILEPACKET_FILERW fpCall_AVFile = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVPacket_FileConvert_Start
函数功能：开始转换
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的转换器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileConvert_Start(XNETHANDLE xhNet);
/********************************************************************
函数名称：AVPacket_FileConvert_Suspend
函数功能：暂停转换或者继续
 参数.一：xhNet
  In/Out：In
  类型：句柄型
  可空：N
  意思：要操作的句柄
 参数.二：bSuspend
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：真为暂停,假为继续
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileConvert_Suspend(XNETHANDLE xhNet, BOOL bSuspend = TRUE);
/********************************************************************
函数名称：AVPacket_FileConvert_GetStatus
函数功能：获取一个转换器的运行状态
 参数.一：xhNet
  In/Out：In
  类型：通道句柄
  可空：N
  意思：要获取的状态的句柄
 参数.二：pbConvert
  In/Out：Out
  类型：逻辑指针
  可空：N
  意思：导出是否完成,反正真表示正在转换,假表示完成
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileConvert_GetStatus(XNETHANDLE xhNet, BOOL *pbConvert);
/********************************************************************
函数名称：AVPacket_FileConvert_Stop
函数功能：关闭一个文件格式转换器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" BOOL AVPacket_FileConvert_Stop(XNETHANDLE xhNet);
/********************************************************************
函数名称：AVPacket_FileConvert_Seek
函数功能：解码跳转器
 参数.一：xhNet
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的句柄
 参数.二：nTimePos
  In/Out：In
  类型：整数型
  可空：N
  意思：输入跳转时间
返回值
  类型：逻辑型
  意思：是否成功
备注：快进,快退,定位,使用此函数
*********************************************************************/
extern "C" BOOL AVPacket_FileConvert_Seek(XNETHANDLE xhNet, __int64x nTimePos);
/************************************************************************/
/*                      音视频文件封装器导出函数                        */
/************************************************************************/
/********************************************************************
函数名称：AVPacket_FilePacket_Init
函数功能：初始化一个打包器
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出的可操作句柄
 参数.二：fpCall_AVNotify
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：打包通知回调
 参数.三：lPararm
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FilePacket_Init(XNETHANDLE* pxhNet, CALLBACK_NETENGINE_AVCODER_AVPACKET_NOTIFY fpCall_AVNotify = NULL, LPVOID lPararm = NULL);
/********************************************************************
函数名称：AVPacket_FilePacket_Input
函数功能：输入要打包的数据信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的打包器
 参数.二：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入文件路径,也可以是封装好的媒体文件
 参数.三：pdlTime
  In/Out：Out
  类型：浮点型指针
  可空：Y
  意思：输出时长,如果非封包无法获取
 参数.四：fpCall_Read
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：音视频文件读取回调函数(也可以是封装好的媒体文件)
 参数.五：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：输入的音频或者视频数据可以采用文件和回调内存方式,但是不能同时使用
*********************************************************************/
extern "C" BOOL AVPacket_FilePacket_Input(XNETHANDLE xhNet, LPCSTR lpszFile = NULL, double* pdlTime = NULL, CALLBACK_XENGINE_AVCODER_AVPACKET_FILEPACKET_FILERW fpCall_Read = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVPacket_FilePacket_Output
函数功能：打开输出文件信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的打包器
 参数.二：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入要操作的文件
 参数.三：fpCall_FileWrite
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：内存会写数据回调,如果不想输出到文件,可以使用此回调
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：如果使用了回调函数,那么第二个参数的意思为输出的格式,比如:flv.mp4
*********************************************************************/
extern "C" BOOL AVPacket_FilePacket_Output(XNETHANDLE xhNet, LPCSTR lpszFile = NULL, CALLBACK_XENGINE_AVCODER_AVPACKET_FILEPACKET_FILERW fpCall_FileWrite = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVPacket_FilePacket_Start
函数功能：开始进行打包
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的打包器
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FilePacket_Start(XNETHANDLE xhNet);
/********************************************************************
函数名称：AVPacket_FilePacket_GetStatus
函数功能：获取音视频封包状态
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要获取的状态的句柄
 参数.二：pbPacket
  In/Out：Out
  类型：逻辑指针
  可空：N
  意思：导出是否完成,真表示正在执行,假表示完成
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FilePacket_GetStatus(XNETHANDLE xhNet, BOOL *pbPacket);
/********************************************************************
函数名称：AVPacket_FilePacket_Suspend
函数功能：设置暂停还是继续
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：bSuspend
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：为真为暂停,假为继续
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FilePacket_Suspend(XNETHANDLE xhNet, BOOL bSuspend = TRUE);
/********************************************************************
函数名称：AVPacket_FilePacket_Stop
函数功能：关闭一个音视频封装器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" BOOL AVPacket_FilePacket_Stop(XNETHANDLE xhNet);
/************************************************************************/
/*                      音视频文件解封装器导出函数                      */
/************************************************************************/
/********************************************************************
函数名称：AVPacket_FileUNPack_Init
函数功能：初始化一个文件解封包器
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出的可操作句柄
 参数.二：fpCall_AVNotify
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：文件解复用操作进度回调
 参数.三：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileUNPack_Init(XNETHANDLE* pxhNet, CALLBACK_NETENGINE_AVCODER_AVPACKET_NOTIFY fpCall_AVNotify = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVPacket_FileUNPack_Input
函数功能：设置输入数据流
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：lpszFile
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要解封包的文件
 参数.三：fpCall_FileRead
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：如果此值不为NULL,表示从内存读取数据
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileUNPack_Input(XNETHANDLE xhNet, LPCSTR lpszFile, CALLBACK_XENGINE_AVCODER_AVPACKET_FILEPACKET_FILERW fpCall_FileRead = NULL, LPVOID lParam = NULL);
/********************************************************************
函数名称：AVPacket_FileUNPack_GetList
函数功能：获取媒体文件所有流信息
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入可操作句柄
 参数.二：pppSt_ListFile
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出媒体列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileUNPack_GetList(XNETHANDLE xhNet, AVCODEC_PACKETLIST * **pppSt_ListFile, int* pInt_ListCount);
/********************************************************************
函数名称：AVPacket_FileUNPack_Output
函数功能：配置输出数据流
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：pppSt_ListFile
  In/Out：In
  类型：三级指针
  可空：N
  意思：输入文件列表信息
 参数.三：nListCount
  In/Out：In
  类型：整数型
  可空：N
  意思：文件列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileUNPack_Output(XNETHANDLE xhNet, AVCODEC_PACKETLIST * **pppSt_ListFile, int nListCount);
/********************************************************************
函数名称：AVPacket_FileUNPack_Start
函数功能：开始处理
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要操作的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileUNPack_Start(XNETHANDLE xhNet);
/********************************************************************
函数名称：AVPacket_FileUNPack_GetStatus
函数功能：获取音视频解封包状态
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：要获取的状态的句柄
 参数.二：pbPacket
  In/Out：Out
  类型：逻辑指针
  可空：N
  意思：导出是否完成,真表示正在执行,假表示完成
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileUNPack_GetStatus(XNETHANDLE xhNet, BOOL *pbPacket);
/********************************************************************
函数名称：AVPacket_FileUNPack_Suspend
函数功能：设置暂停还是继续
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的句柄
 参数.二：bSuspend
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：为真为暂停,假为继续
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL AVPacket_FileUNPack_Suspend(XNETHANDLE xhNet, BOOL bSuspend = TRUE);
/********************************************************************
函数名称：AVPacket_FileUNPack_Stop
函数功能：关闭一个音视频解封装器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要关闭的句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：销毁资源必须调用
*********************************************************************/
extern "C" BOOL AVPacket_FileUNPack_Stop(XNETHANDLE xhNet);
