#pragma once
/********************************************************************
//	Created:	2019/8/27   17:23
//	Filename: 	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtpProtocol\RTPProtocol_Error.h
//	File Path:	E:\NetEngine_Windows\NetEngine_SourceCode\NetEngine_StreamMedia\StreamMedia_RtpProtocol
//	File Base:	RTPProtocol_Error
//	File Ext:	h
//  Project:    NetEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	RTP协议模块导出错误
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                            RTP打包处理器错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_INIT_PARAMENT 0x140C0001     //已经存在的源标识符
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_INIT_MALLOC 0x140C0002       //申请内存失败
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_SEND_PARAMENT 0x140C0010     //投递数据失败,参数错误
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_SEND_NOTFOUND 0x140C0011     //没有找到指定句柄
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_SEND_MAXBUFFER 0x140C0012    //最大缓冲区大小,无法继续,内部处理未完成
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_RECV_PARAMENT 0x140C0020     //参数错误,获取RTP包失败
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_RECV_NOTFOUND 0x140C0021     //没有找到指定句柄
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_RECV_EMPTY 0x140C0022        //指定句柄队列为空,没有RTP包
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_RECV_BUFFER 0x140C0023       //缓冲区被破坏,已经释放
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_GETSR_PARAMENT 0x140C0031    //参数错误
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_GETSR_NOTFOUND 0x140C0032    //没有找到指定句柄
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_SETMODE_NOTFOUND 0x140C0040  //没有找到句柄
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_SETINFO_NOTFOUND 0x140C0050  //没有找到指定包
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_RTPTIME_PARAMENT 0x140C0060  //参数错误
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_RTPTIME_NOTFOUND 0x140C0061  //没有找到
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PACKET_PARSEAAC_MALLOC 0x140C00A0   //解析AAC失败,内存申请失败
//////////////////////////////////////////////////////////////////////////
//                            RTP解析器导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_INIT_PARAMENT 0x140C1001      //参数错误
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_INIT_MALLOC 0x140C1001        //申请内存失败
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_SEND_PARAMENT 0x140C1010      //投递数据给解析器失败
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_SEND_NOTFOUND 0x140C1011      //没有找到指定句柄
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_SEND_MALLOC 0x140C1012        //申请内存失败
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_RECV_PARAMENT 0x140C1020      //参数错误
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_RECV_NOTFOUND 0x140C1021      //没有找到指定句柄
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_RECV_EMPTY 0x140C1022         //队列为空,没有解析好的RTP数据包
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_RECV_NOTPACKET 0x140C1023     //没有找到可用包,可能分片包还没接受完成
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_RECV_LEN 0x140C1024           //提供的缓冲区不够
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_GETCOUNT_PARAMENT 0x140C1030  //参数错误
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_GETCOUNT_NOTFOUND 0x140C1031  //没有找到指定句柄
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_SETMODE_NOTFOUND 0x140C0040  //没有找到句柄
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_PACKET_PARAMENT 0x140C10A0    //参数错误,解析包失败
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_PACKET_NOTSUPPORT 0x140C10A1  //不支持的类型解
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_PUSH_FLAGS 0x140C10B0         //压入数据报错误,标志错误,不是RTP包
#define ERROR_STREAMMEDIA_RTPPROTOCOL_PARSE_PUSH_MALLOC 0x140C10B1        //申请内存失败
//////////////////////////////////////////////////////////////////////////
//                            RTP帮助器导出错误
//////////////////////////////////////////////////////////////////////////
#define ERROR_STREAMMEDIA_RTPPROTOCOL_HELP_GETRTPTIME_PARAMENT 0x140C2001 //参数错误
