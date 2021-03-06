#pragma once
/********************************************************************
//	Created:	2011/10/15   14:22
//	Filename: 	NetSocketEngine/NetSocketHelp/NetGetInfo/NetGetInfo_Define.h
//	File Path:	NetSocketEngine/NetSocketHelp/NetGetInfo/
//	File Base:	NetGetInfo
//	File Ext:	h
//      Project:        血与荣誉网络通信引擎 For Linux
//	Author:		dowflyon
//	Purpose:	获取网络信息导出函数定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                         导出的定义
//////////////////////////////////////////////////////////////////////////
//网络端口占用者信息
#define XENGINE_NETXAPI_SOCKET_NETSTATE_PROTOCOL_TCP 0x0C01               //TCP
#define XENGINE_NETXAPI_SOCKET_NETSTATE_PROTOCOL_UDP 0x0C02               //UDP
#define XENGINE_NETXAPI_SOCKET_NETSTATE_PROTOCOL_RAW 0x0C03               //RAW
#define XENGINE_NETXAPI_SOCKET_NETSTATE_PROTOCOL_UNIX 0x0C04              //UNIX
#define XENGINE_NETXAPI_SOCKET_NETSTATE_PROTOCOL_ICMP 0x0C05              //ICMP
#define XENGINE_NETXAPI_SOCKET_NETSTATE_PROTOCOL_IP 0x0C016               //IP
#define XENGINE_NETXAPI_SOCKET_NETSTATE_PROTOCOL_UNKNOW 0x0C0F            //无法识别的协议类
//网络协议版本号定义
#define XENGINE_NETXAPI_SOCKET_NETSTATE_VERSION_IPV4 0x0C10               //IPV4版本
#define XENGINE_NETXAPI_SOCKET_NETSTATE_VERSION_IPV6 0x0C11               //IPV6版本
#define XENGINE_NETXAPI_SOCKET_NETSTATE_VERSION_UNKNOW 0x0C12             //无法识别的协议版本
//网络状态信息
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_CLOSED 0x0C20                 //网络关闭
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_LISTEN 0x0C21                 //监听
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_SYNSENT 0x0C22                //再收到和发送一个连接请求后等待对方对连接请求的确认
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_SYNRECEIVED 0x0C24
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_ESTABLISHED 0x0C25            //代表一个打开的连接
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_FINWAIT1 0x0C26               //等待远程TCP连接中断请求，或先前的连接中断请求的确认
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_FINWAIT2 0x0C27               //从远程TCP等待连接中断请求
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_CLOSEWAIT 0x0C28              //等待从本地用户发来的连接中断请求
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_CLOSING 0x0C29                //等待远程TCP对连接中断的确认
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_LASTACK 0x0C2A                //等待原来的发向远程TCP的连接中断请求的确认
#define XENGINE_NETXAPI_SOCKET_NETSTATE_NET_TIMEWAIT 0x0C2B               //等待足够的时间以确保远程TCP接收到连接中断请求的确认
//网络连接类型定义
#define XENGINE_NETXAPI_SOCKET_CONNECTTYPE_CONNECNOTNET 0x0C30            //已经连接但是可能并没有网络
#define XENGINE_NETXAPI_SOCKET_CONNECTTYPE_LANTOINTERNET 0x0C31           //通过局域网连接到网络
#define XENGINE_NETXAPI_SOCKET_CONNECTTYPE_MODEMTOINTERNET 0x0C32         //通过MODEM连接到网络
#define XENGINE_NETXAPI_SOCKET_CONNECTTYPE_NOTCONNECTED 0x0C33            //没有连接到网络
#define XENGINE_NETXAPI_SOCKET_CONNECTTYPE_PROXYTOINTERNET 0x0C34         //通过代理连接到网络
//////////////////////////////////////////////////////////////////////////
//                         导出的数据结构
//////////////////////////////////////////////////////////////////////////
//网卡信息结构
typedef struct tag_NetXApi_Sniffer_If
{
    CHAR tszIFName[MAX_PATH];                                            //名称
    CHAR tszIFDes[MAX_PATH];                                             //描述
}NETXAPI_SNIFFERIF,*LPNETXAPI_SNIFFERIF;
//抓包信息结构
typedef struct tag_NetXApi_ProtocolInfo
{
    struct
    {
        CHAR tszSourceMac[64];                                          //源MAC地址
        CHAR tszDestMac[64];                                            //目标MAC地址
        int nETHProtoType;                                               //上层协议.ARP RARP IP
    }st_ETHHdr;

    CHAR tszSourceAddr[32];                                              //源地址
    CHAR tszDestAddr[32];                                                //目标地址,IP协议有效
    int nSourcePort;                                                      //源端口
    int nDestPort;                                                        //目的端口

    int nHdrLen;                                                          //协议大小
    int nMsgLen;                                                          //数据大小

    int nIPProtoType;                                                     //IP或者ARP操作协议类型
    UCHAR uFlags;                                                         //最终操作标记,TCP(FIN,PST等)
}NETXAPI_PROTOCOLINFO, *LPNETXAPI_PROTOCOLINFO;
//获取网卡流量信息
typedef struct tag_NetInfo_Flow_State
{
    CHAR tszDevName[64];                    //设备名称

    struct
    {
        ULONGLONG ullBytes;                  //接受的流量
        ULONGLONG ullPackets;                //接受包个数
        ULONGLONG ullError;                  //错误的包
        ULONGLONG ullDrop;                   //被丢弃的包
        ULONGLONG ullFifo;                   //出入队列
        ULONGLONG ullFrame;                  //帧
        ULONGLONG ullCompress;               //压缩的包
        ULONGLONG ullMultiCast;              //多播包
    }st_RecvPackets;
    struct
    {
        ULONGLONG ullBytes;                  //接受的流量
        ULONGLONG ullPackets;                //接受包个数
        ULONGLONG ullError;                  //错误的包
        ULONGLONG ullDrop;                   //被丢弃的包
        ULONGLONG ullFifo;                   //出入队列
        ULONGLONG ullFrame;                  //帧
        ULONGLONG ullCompress;               //压缩的包
        ULONGLONG ullMultiCast;              //多播包
    }st_SendPackets;
}NETXAPI_FLOWSTATE,*LPNETXAPI_FLOWSTATE;
/************************************************************************/
/*                      网络套接字函数导出结构                          */
/************************************************************************/
//网络信息状态查询
typedef struct
{
	CHAR tszAppName[128];                                                 //应用程序名称
	CHAR tszUserName[32];                                                 //应用程序所属用户
	DWORD dwProVersion;                                                   //协议版本
	DWORD dwProtocol;                                                     //协议类型
	DWORD dwNetState;                                                     //网络状态，UDP无效
	int nPid;                                                             //应用程序PID
}NETXAPI_NETSTATE, * LPNETXAPI_NETSTATE;
//网络参数信息
typedef struct
{
	CHAR tszHostName[64];                                                  //本地电脑的主机名称
	CHAR tszDomainName[64];                                                //本地电脑注册的域名
	int nDNSCount;                                                         //DNS列表个数
	CHAR** pppszListDns;                                                  //DNS服务器列表,this memory must be free...
}NETXAPI_NETPARAM, * LPNETXAPI_NETPARAM;
//IP统计数据导出的结构体，该结构存储在特定计算机上运行的有关IP协议的信息
typedef struct 
{
	DWORD dwForwarding;                                                   //指定IP转发是否有效
	DWORD dwDefaultTTL;                                                   //为从你的电脑出发的数据报指定默认的初始TTL
	DWORD dwInReceives;                                                   //指定接收到的数据报的数量
	DWORD dwInHdrErrors;                                                  //指定接收到的数据报中，协议头出错的数据报的个数
	DWORD dwInAddrErrors;                                                 //指定接收到的数据报中，地址出错的数据报的个数
	DWORD dwForwDatagrams;                                                //指定转发的数据报的数量
	DWORD dwInUnknownProtos;                                              //指定接收数据的数据报中，协议未知的数据报的数量 
	DWORD dwInDiscards;                                                   //指定接收到的数据报中，丢弃的数据报的数量
	DWORD dwInDelivers;                                                   //指定接收到的数据报中，已经传送的数据报的数量
	DWORD dwOutRequests;                                                  //指定外出的数据报中，IP正在请求传输的数据报的数量
	DWORD dwRoutingDiscards;                                              //指定外出的数据报中，丢弃的数据报数量
	DWORD dwOutDiscards;                                                  //指定传输的数据报中，丢弃的数据报的数量
	DWORD dwOutNoRoutes;                                                  //指定没有路由目的地（计算机中没有其他目的地址的路由）的数据报的数量
	DWORD dwReasmTimeout;                                                 //指定一个分段数据报到来的最大时间
	DWORD dwReasmReqds;                                                   //指定需要组合的数据报的数量
	DWORD dwReasmOks;                                                     //指定成功重新组合的数据报的数量
	DWORD dwReasmFails;                                                   //指定不能重新组合的数据报的数量
	DWORD dwFragOks;                                                      //指定成功分段的数据报的数量
	DWORD dwFragFails;                                                    //指定不能分段的数据报的数量
	DWORD dwFragCreates;                                                  //指定已经分段的数据报数量
	DWORD dwNumIf;                                                        //指定接口的数量
	DWORD dwNumAddr;                                                      //指定此电脑关联的IP地址的数量
	DWORD dwNumRoutes;                                                    //指定IP路由表中的可用路由的数量
}NETXAPI_IPSTATICS, * LPNETXAPI_IPSTATICS;
//该结构体检索本地计算机的TCP统计信息。
typedef struct 
{
	DWORD dwRtoAlgorithm;                                                 //指定使用哪个超时重发算法，可能的取值有MIB_TCP_RTO_CONSTANT，MIB_TCP_RTO_RSRE，MIB_TCP_RTO_VANJ等
	DWORD dwRtoMin;                                                       //指定超时重发算法的最小值（以毫秒为单位，下同）        
	DWORD dwRtoMax;                                                       //指定超时重发算法的最大值
	DWORD dwMaxConn;                                                      //指定最大的链接数量，如果为-1，则是系统允许的最大值 
	DWORD dwActiveOpens;                                                  //指定机器向服务器初始化了多少个连接
	DWORD dwPassiveOpens;                                                 //指定机器监听到来多少个客户端连接
	DWORD dwAttemptFails;                                                 //指定多少个连接视图失败了
	DWORD dwEstabResets;                                                  //指定已经被重置的链接数量 
	DWORD dwCurrEstab;                                                    //指定当前连接的数量
	DWORD dwInSegs;                                                       //指定接收到的段的数量
	DWORD dwOutSegs;                                                      //指定发送的段的数量
	DWORD dwRetransSegs;                                                  //指定重发的段的数量
	DWORD dwInErrs;                                                       //指定接收错误的数量
	DWORD dwOutRsts;                                                      //指定重设标志位后，又传输了多少分段数据报
	DWORD dwNumConns;                                                     //指定连接的总数
}NETXAPI_TCPSTATICS, * LPNETXAPI_TCPSTATICS;
//获取UDP统计信息数据
typedef struct 
{
	DWORD dwInDatagrams;                                                  //指定接收到的数据报的数量
	DWORD dwNoPorts;                                                      //指定接收到的数据报中，因为端口号无效而被丢弃的数量
	DWORD dwInErrors;                                                     //指定接收到的错误数据报的数量
	DWORD dwOutDatagrams;                                                 //指定以传输的数据报的数量
	DWORD dwNumAddrs;                                                     //指定UDP监听表中入口的数量
}NETXAPI_UDPSTATICS, * LPNETXAPI_UDPSTATICS;
//ICMP协议统计数据信息
typedef struct 
{
	DWORD dwMsgs;                                                         //消息个数
	DWORD dwErrors;                                                       //错误消息
	DWORD rgdwTypeCount[256];
}NETXAPI_INOUT_ICMPSTATICS, * LPNETXAPI_INOUT_ICMPSTATICS;
//ICMP统计数据相信信息
typedef struct 
{
	//有两个相同的结构体，一个是用来获取发送，一个用来获取接受，使用方法相同
	NETXAPI_INOUT_ICMPSTATICS st_InIcmpStatics;
	NETXAPI_INOUT_ICMPSTATICS st_OutIcmpStatics;
}NETXAPI_ICMPSTATICS, * LPNETXAPI_ICMPSTATICS;
//TCP进程连接列表
typedef struct
{
	DWORD dwProcessID;                                                    //进程ID
	CHAR tszLoaclAddr[16];                                                //本地IP地址
	CHAR tszRemoteAddr[16];                                               //远程IP地址
	int nLocalPort;                                                       //本地端口
	int nRemotePort;                                                      //远程端口
	DWORD dwStatus;                                                       //进程网络状态

	BOOL bFlagNet;                                                        //网络连接类型 TRUE:TCP FALSE:UDP
}NETXAPI_PROCESSTABLE, * LPNETCORE_NET_PROCESSTABLE;
//////////////////////////////////////////////////////////////////////////
//                        导出回调
//////////////////////////////////////////////////////////////////////////
//声明回调函数，参数:抓抱器句柄，导出的信息，上层主协议(IP,ARP等),下层子协议,完整数据包(+nHdrLen 就是数据),自定义参数
typedef void(CALLBACK* CALLBACK_NETXAPI_SNIFFER_DATAPACKET)(XNETHANDLE xhNet, NETXAPI_PROTOCOLINFO* pSt_ProtoInfo, LPCSTR lpszMsgBuffer, LPVOID lParam);
//网络枚举回调函数,源IP地址,源MAC地址
typedef void(CALLBACK *CALLBACK_NETXAPI_LANENUM_RESLIST)(XNETHANDLE xhNet, LPCSTR lpszIPAddr, LPCSTR lpszMacAddr, LPVOID lParam);
//////////////////////////////////////////////////////////////////////
//                        导出函数
//////////////////////////////////////////////////////////////////////
/************************************************************************
函数名称：NetXApi_GetLastError
函数功能：获取最后发生的错误
返回值
  类型：双字
  意思：错误码
备注：
************************************************************************/
extern "C" DWORD NetXApi_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*                     地址查询函数导出                                    */
/************************************************************************/
/********************************************************************
函数名称：NetXApi_Address_OpenQQWry
函数功能：打开QQIP数据库
 参数.一：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：QQWry数据库位置
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetXApi_Address_OpenQQWry(LPCSTR lpszFileName);
/************************************************************************
函数名称：NetXApi_Address_CloseQQWry
函数功能：关闭IP查询文件
返回值
  类型：逻辑型
  意思：是否成功关闭
备注：
************************************************************************/
extern "C" BOOL NetXApi_Address_CloseQQWry();
/********************************************************************
函数名称：NetXApi_Address_IPtoAddr
函数功能：获取IP对应的国家和地址
 参数.一：lpszIPAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：指定文件偏移量
 参数.二：ptszAddrInfo
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出地址信息
 参数.三：ptszISPInfo
  In/Out：Out
  类型：字符指针
  可空：N
  意思：导出运营商信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetXApi_Address_IPtoAddr(LPCSTR lpszIPAddr, CHAR * ptszAddrInfo, CHAR * ptszISPInfo);
/************************************************************************/
/*                     流量获取函数导出                                    */
/************************************************************************/
/************************************************************************
函数名称：NetXApi_NetFlow_GetAll
函数功能：获取网络流量信息
  参数.一：pSt_FlowState
   In/Out：Out
   类型：数据结构指针
   可空：N
   意思：网络流量信息结构体
  参数.二：lpszEth_Name
   In/Out：In
   类型：常量字符指针
   可空：Y
   意思：要获取的网卡名称，比如：eth0
  参数.三：nNumEntries
   In/Out：In
   类型：整数型
   可空：Y
   意思：要获取的网卡编号
返回值
  类型：逻辑型
  意思：是否成功获取
备注：最后两个参数不能同时为空,每秒获取一次,这一次减去上一次的流量就得到当前每秒流量
************************************************************************/
extern "C" BOOL NetXApi_NetFlow_GetAll(NETXAPI_FLOWSTATE *pSt_FlowState,LPCSTR lpszDevName = NULL,int nNumEntries = 0);
/************************************************************************/
/*                     网络流量控制导出函数                             */
/************************************************************************/
/********************************************************************
函数名称：NetXApi_CtrlFlow_Init
函数功能：初始化流量控制程序
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：导出初始化成功的句柄
 参数.二：lpszDevName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入你的网卡名称
 参数.三：bIsClear
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否清理老旧的流量控制服务设定
返回值
  类型：逻辑型
  意思：是否成功
备注：此函数需要管理员权限
*********************************************************************/
extern "C" BOOL NetXApi_CtrlFlow_Init(XNETHANDLE *pxhNet,LPCSTR lpszDevName,BOOL bIsClear = TRUE);
/********************************************************************
函数名称：NetXApi_CtrlFlow_AddFlow
函数功能：为一条连接添加一个流量控制程序
 参数.一：xhNet
  In/Out：n
  类型：网络句柄
  可空：N
  意思：输入要操作的流量控制程序
 参数.二：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出添加的过滤器句柄
 参数.三：nLimitByte
  In/Out：In
  类型：整数型
  可空：N
  意思：设置要限制的速度，每秒Byte,不能超过你的网卡负载大小
 参数.四：nRecvByte
  In/Out：In
  类型：整数型
  可空：N
  意思：Linux版本此参数无效！暂时无效
 参数.五：nDstPort
  In/Out：In
  类型：整数型
  可空：Y
  意思：设置要控制通道的目标端口
 参数.六：nSrcPort
  In/Out：In
  类型：整数型
  可空：Y
  意思：设置要控制流量通道的源端口,可以为空,只用目标端口控制某一条通道流量信息
返回值
  类型：逻辑型
  意思：是否成功
备注：参数5和6不能同时为0
*********************************************************************/
extern "C" BOOL NetXApi_CtrlFlow_AddFlow(XNETHANDLE xhNet,XNETHANDLE *pxhFilter,int nLimitByte, int nRecvByte, int nDstPort = 0, int nSrcPort = 0);
/********************************************************************
函数名称：NetXApi_CtrlFlow_DelFlow
函数功能：删除一条流量控制信息
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要操作的流量控制句柄
 参数.二：xhFilter
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要删除的过滤器句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetXApi_CtrlFlow_DelFlow(XNETHANDLE xhNet,XNETHANDLE xhFilter);
/********************************************************************
函数名称：NetXApi_CtrlFlow_Destory
函数功能：销毁流量控制程序
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要销毁的流量控制句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetXApi_CtrlFlow_Destory(XNETHANDLE xhNet);
/************************************************************************/
/*                     网络嗅探器函数导出                                  */
/************************************************************************/
/********************************************************************
函数名称：NetXApi_Sniffer_Start
函数功能：启动一个网络抓包器
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出网络监听句柄
 参数.二：lpszDevName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要监听哪个网卡
 参数.三：fpCall_NetXSniffer
  In/Out：Out
  类型：回调函数
  可空：N
  意思：设置回调函数地址
 参数.四：lParam
  In/Out：In
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：这个函数在LINUX下需要ROOT权限
*********************************************************************/
extern "C" BOOL NetXApi_Sniffer_Start(XNETHANDLE *pxhNet, LPCSTR lpszDevName, CALLBACK_NETXAPI_SNIFFER_DATAPACKET fpCall_NetXSniffer, LPVOID lParam = NULL);
/********************************************************************
函数名称：NetXApi_Sniffer_Stop
函数功能：停止网络嗅探器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：要释放的嗅探器句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetXApi_Sniffer_Stop(XNETHANDLE xhNet);
/********************************************************************
函数名称：NetXApi_Sniffer_Filter
函数功能：设置网络嗅探过滤器
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入嗅探器句柄
 参数.二：lpszFilter
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入过滤器字符串,参考TCPDUMP格式
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetXApi_Sniffer_Filter(XNETHANDLE xhNet, LPCSTR lpszFilter);
/********************************************************************
函数名称：NetXApi_Sniffer_WriteDump
函数功能：抓包的数据保存为文件
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入嗅探器句柄
 参数.二：lpszFilter
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入要保存的路径
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetXApi_Sniffer_WriteDump(XNETHANDLE xhNet, LPCSTR lpszFileName);
/********************************************************************
函数名称：NetXApi_Sniffer_GetIFAll
函数功能：获取网络嗅探器允许的设备列表名称
 参数.一：pppSt_IFSniffer
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的网卡设备列表名和描述
 参数.二：pInt_IFCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出网卡列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数一必须使用基础库的BaseLib_OperatorMemory_Free释放内存
*********************************************************************/
extern "C" BOOL NetXApi_Sniffer_GetIFAll(NETXAPI_SNIFFERIF * **pppSt_IFSniffer, int* pInt_IFCount);
//////////////////////////////////////////////////////////////////////////
//                                枚举局域网IP和MAC地址
//////////////////////////////////////////////////////////////////////////
/********************************************************************
函数名称：NetXApi_LANEnum_Start
函数功能：启动一个局域网扫描服务
 参数.一：pxhNet
  In/Out：Out
  类型：网络句柄
  可空：N
  意思：导出启动成功的局域网扫描服务
 参数.二：lpszDevName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：网卡名称
 参数.三：lpszStartAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要扫描的IP起始地址
 参数.四：lpszEndAddr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要扫描的IP结束地址
 参数.五：fpCall_ResList
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：枚举资源函数地址
 参数.六：lParam
  In/Out：In/Out
  类型：回调函数
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否成功
备注：这个函数在LINUX下需要ROOT权限
*********************************************************************/
extern "C" BOOL NetXApi_LANEnum_Start(XNETHANDLE *pxhNet, LPCSTR lpszDevName, LPCSTR lpszStartAddr, LPCSTR lpszEndAddr, CALLBACK_NETXAPI_LANENUM_RESLIST fpCall_ResList, LPVOID lParam = NULL);
/********************************************************************
函数名称：NetXApi_LANEnum_Close
函数功能：关闭一个枚举资源
 参数.一：xhNet
  In/Out：In
  类型：网络句柄
  可空：N
  意思：输入要操作的枚举资源句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL NetXApi_LANEnum_Close(XNETHANDLE xhNet);
/************************************************************************/
/*                       网络套接字函数导出接口                         */
/************************************************************************/
/********************************************************************
函数名称：NetXApi_Socket_IsPortOccupation
函数功能：端口是否被使用
 参数.一：nPort
  In/Out：In
  类型：整数型
  可空：N
  意思：要检查的端口号码
 参数.二：nProto
  In/Out：In
  类型：整数型
  可空：Y
  意思：协议类型，要查找端口的所属协议
返回值
  类型：逻辑型
  意思：是否被使用，假为没有
备注：
*********************************************************************/
extern "C" BOOL NetXApi_Socket_IsPortOccupation(int nPort, int nProto);
/********************************************************************
函数名称：NetXApi_Socket_GetPortState
函数功能：获取本地端口状态
 参数.一：uPort
  In/Out：In
  类型：双字
  可空：N
  意思：要检查的端口号
 参数.二：pSt_NetState
  In/Out：Out
  类型：数据结构指针
  可空：N
  意思：导出占用信息
返回值
  类型：逻辑型
  意思：返回假后你需要判断错误码，ERROR_XCORE_NETXAPI_SOCKET_NETSTATE_NOTFOUND 这个表示没有被占用 否则返回真 占用
备注：
*********************************************************************/
extern "C" BOOL NetXApi_Socket_GetPortState(int uPort, NETXAPI_NETSTATE * pSt_NetState);
/********************************************************************
函数名称：NetXApi_Socket_DomainToAddr
函数功能：名称转地址列表
 参数.一：lpszDomain
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：输入一个标准的名称
 参数.二：pppszListAddr
  In/Out：Out
  类型：三级指针
  可空：N
  意思：输出获取到的地址列表
 参数.三：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出列表个数
返回值
  类型：逻辑型
  意思：是否转换成功
备注：
*********************************************************************/
extern "C" BOOL NetXApi_Socket_DomainToAddr(LPCSTR lpszDomain, CHAR * **pppszListAddr, int* pInt_ListCount);
/********************************************************************
函数名称：NetXApi_Socket_GetNetParam
函数功能：获取网络接口信息
 参数.一：pSt_NetParam
  In/Out：Out
  类型：结构体指针
  可空：N
  意思：导出的网络信息，参考结构体定义
返回值
  类型：逻辑型
  意思：是否成功获取
备注：
*********************************************************************/
extern "C" BOOL NetXApi_Socket_GetNetParam(NETXAPI_NETPARAM * pSt_NetParam);
/********************************************************************
函数名称：NetXApi_Socket_GetNetConnectType
函数功能：获取网络连接类型
 参数.一：pdw_Type
  In/Out：Out
  类型：双字
  可空：N
  意思：导出网络连接方式
返回值
  类型：逻辑型
  意思：时候正确获取到连接类型
备注：返回真后通过参数获取
*********************************************************************/
extern "C" BOOL NetXApi_Socket_GetNetConnectType(DWORD * pdw_Type);
/********************************************************************
函数名称：NetXApi_Socket_GetProtocolStatics
函数功能：获取网络协议状态信息
 参数.一：pSt_IpStatics
  In/Out：Out
  类型：结构体指针
  可空：Y
  意思：IP协议统计信息
 参数.二：pSt_TcpStatics
  In/Out：Out
  类型：结构体指针
  可空：Y
  意思：导出TCP协议状态统计信息
 参数.三：pSt_UdpStatics
  In/Out：Out
  类型：结构体指针
  可空：Y
  意思：导出UDP协议状态统计信息
 参数.四：pSt_IcmpStatics
  In/Out：Out
  类型：结构体指针
  可空：Y
  意思：导出ICMP协议状态统计信息
 参数.五：dwProtocolVer
  In/Out：In
  类型：双字
  可空：Y
  意思：要获取的IP版本，默认是IPV4
返回值
  类型：逻辑型
  意思：是否获取到指定协议状态信息
备注：前面的协议结构参数允许多个或者单个为空，那么将不取这些信息
*********************************************************************/
extern "C" BOOL NetXApi_Socket_GetProtocolStatics(NETXAPI_IPSTATICS* pSt_IpStatics, NETXAPI_TCPSTATICS* pSt_TcpStatics, NETXAPI_UDPSTATICS* pSt_UdpStatics, NETXAPI_ICMPSTATICS* pSt_IcmpStatics, DWORD dwProtocolVer = XENGINE_NETXAPI_SOCKET_NETSTATE_VERSION_IPV4);
/********************************************************************
函数名称：NetXApi_Socket_ProcessNet
函数功能：获取进程TCP网络连接列表
 参数.一：pppSt_ListTCPProcess
  In/Out：Out
  类型：指向数据结构指针的指针的指针
  可空：N
  意思：输出网络进程列表TCP连接,此内存必须手动释放
 参数.二：pppSt_ListUDPProcess
  In/Out：Out
  类型：指向数据结构指针的指针的指针
  可空：N
  意思：输出网络进程列表UDP连接,此内存必须手动释放
 参数.三：pInt_TCPCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出TCP连接个数
 参数.四：pInt_UDPCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出UDP连接个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数一和二必须使用基础库的BaseLib_OperatorMemory_Free释放内存
*********************************************************************/
extern "C" BOOL NetXApi_Socket_ProcessNet(NETXAPI_PROCESSTABLE * **pppSt_ListTCPProcess, NETXAPI_PROCESSTABLE * **pppSt_ListUDPProcess, int* pInt_TCPCount, int* pInt_UDPCount);
