#pragma once
/********************************************************************
//	Created:	2012/11/24  1:03
//	File Name: 	G:\U_DISK_Path\NetSocketEngine\NetEngine_HelpComponents\HelpComponents_XLog\XLog_Define.h
//	File Path:	G:\U_DISK_Path\NetSocketEngine\NetEngine_HelpComponents\HelpComponents_XLog
//	File Base:	XLog_Define
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		qyt
//	Purpose:	血与荣誉网络通信引擎——日志操作模块导出头文件
//	History:
*********************************************************************/
typedef void* XLOG;
//消息日志类型以及优先级，只有大于等于设置的优先级类型后才会被记录，越大优先级越高
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_ALL    0x00000000    //所有日志都打印
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_ALERT  0x00000001    //系统必须采取措施
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_CRIT   0x00000002    //系统已经达到临界值
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_ERROR  0x00000004    //错误级别日志
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_WARN   0x00000008    //警告级别日志
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_NOTICE 0x00000010    //正常但重要的条件
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_INFO   0x00000020    //常规信息
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_DEBUG  0x00000040    //调试信息
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_FATAL  0x00000080    //失败日志 SYSLOG不支持
#define XENGINE_HELPCOMPONENTS_XLOG_IN_LOGLEVEL_OFF    1000          //全部关闭 SYSLOG不支持
//日志颜色设置
#define XENGINE_HELPCOMPONENTS_XLOG_COLOR_CLEAR 0                    //清楚所有样式
#define XENGINE_HELPCOMPONENTS_XLOG_TEXT_BLUE 0x0001                 //文本为蓝色
#define XENGINE_HELPCOMPONENTS_XLOG_TEXT_GREEN 0x0002                //文本为绿色
#define XENGINE_HELPCOMPONENTS_XLOG_TEXT_RED 0x0004                  //文本为红色
#define XENGINE_HELPCOMPONENTS_XLOG_BACK_BLUE 0x0010                 //背景为蓝色
#define XENGINE_HELPCOMPONENTS_XLOG_BACK_GREEN 0x0020                //背景为绿色
#define XENGINE_HELPCOMPONENTS_XLOG_BACK_RED 0x0040                  //背景为红色
//////////////////////////////////////////////////////////////////////////
//日志输出类型
typedef enum en_HelpComponents_XLog_OutType
{
    HELPCOMPONENTS_XLOG_OUTTYPE_FILE = 0x0000001,                         //文件(支持)
    HELPCOMPONENTS_XLOG_OUTTYPE_STD = 0x0000010,                          //控制台(支持)
    HELPCOMPONENTS_XLOG_OUTTYPE_SOCKET = 0x0000100,                       //套接字(支持)每条日志发送都是 协议头+XLOG协议体+数据 的方式
    HELPCOMPONENTS_XLOG_OUTTYPE_SYSLOG = 0x0001000,                       //LINUX为SYSLOG服务器,WINDOWS为系统事件日志
    HELPCOMPONENTS_XLOG_OUTTYPE_DEBUGAPP = 0x0010000,                     //默认调试器(仅WINDOWS支持)
}HELPCOMPONENTS_XLOG_OUTTYPE,*LPHELPCOMPONENTS_XLOG_OUTTYPE;
//备份文件类型
typedef enum en_HelpComponents_XLog_BackType
{
    HELPCOMPONENTS_XLOG_BACKTYPE_NUMBER = 0,                              //按照文件名顺序
    HELPCOMPONENTS_XLOG_BACKTYPE_TIME = 1                                 //按照时间
}HELPCOMPONENTS_XLOG_BACKTYPE, * LPHELPCOMPONENTS_XLOG_BACKTYPE;
//////////////////////////////////////////////////////////////////////////
//配色方案结构体,可以设置他们的配色方案
typedef struct tag_HelpComponents_XLog_Color
{
    DWORD wAlert;
    DWORD wCrit;
    DWORD wError;
    DWORD wWarn;
    DWORD wNotice;
    DWORD wInfo;
    DWORD wDebug;
    DWORD wFatal;
}HELPCOMPONENTS_XLOG_COLOR;
typedef struct tag_HelpComponents_XLog_Configure
{
    CHAR tszFileName[256];                                                //日志文件保存路径，你必须保证日志目录存在
    int XLog_MaxSize;                                                     //日志文件最大大小，单位KB
    int XLog_MaxBackupFile;                                               //日志文件备份个数,备份满了,将会覆盖
    struct
    {
        CHAR tszBackDir[MAX_PATH];                                       //备份文件目录,如果为\0表示不备份文件到指定目录,必须初始化memset
        HELPCOMPONENTS_XLOG_BACKTYPE enBackType;                          //备份文件类型
    }st_BackInfo;
}HELPCOMPONENTS_XLOG_CONFIGURE,*LPHELPCOMPONENTS_XLOG_CONFIGURE;
//////////////////////////////////////////////////////////////////////////
//                    导出函数
//////////////////////////////////////////////////////////////////////////
extern "C" DWORD XLog_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*                       日志模块导出函数                               */
/************************************************************************/
/********************************************************************
函数名称：HelpComponents_XLog_Init
函数功能：初始化XLOG日志系统
 参数.一：dwOutType
  In/Out：In
  类型：双字
  可空：N
  意思：日志输出类型，可以用 | 符号包含
 参数.二：pSt_XLogConfigure
  In/Out：In
  类型：数据结构
  可空：N
  意思：配置日志系统属性
 参数.三：bIsCache
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：写日志文件是否使用缓存功能
返回值
  类型：日志句柄
  意思：返回此日志操作句柄
备注：缓存功能属于高级IO,你将没有权限访问这个日志文件,除非你程序关闭后才能打开日志文件
*********************************************************************/
extern "C" XLOG HelpComponents_XLog_Init(DWORD dwOutType,HELPCOMPONENTS_XLOG_CONFIGURE *pSt_XLogConfigure, BOOL bIsCache = FALSE);
/********************************************************************
函数名称：HelpComponents_XLog_Destroy
函数功能：销毁XLOG日志系统
 参数.一：xhLog
  In/Out：In
  类型：日志句柄
  可空：N
  意思：要销毁的日志句柄
返回值
  类型：逻辑型
  意思：是否成功销毁
备注：
*********************************************************************/
extern "C" BOOL HelpComponents_XLog_Destroy(XLOG xhLog);
/********************************************************************
函数名称：HelpComponents_XLog_GetIdleTime
函数功能：获取距离上次打印日志依赖的间隔时间
 参数.一：xhLog
  In/Out：In
  类型：日志句柄
  可空：N
  意思：要获取的日志
 参数.二：pInt_Time
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出获取到的时间，单位秒
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HelpComponents_XLog_GetIdleTime(XLOG xhLog,int *pInt_Time);
/********************************************************************
函数名称：HelpComponents_XLog_SetLogPriority
函数功能：设置日志消息类型优先级
 参数.一：dwOutType
  In/Out：In
  类型：双字
  可空：N
  意思：要打印的消息类型
 参数.二：dwAllowLog
  In/Out：In
  类型：双字
  可空：N
  意思：要设置的日志类型
返回值
  类型：逻辑型
  意思：是否设置成功
备注：
*********************************************************************/
extern "C" BOOL HelpComponents_XLog_SetLogPriority(XLOG xhLog,DWORD dwAllowLog);
/********************************************************************
函数名称：HelpComponents_XLog_SetLogColor
函数功能：设置日志输出颜色,仅仅控制台有效
 参数.一：xhLog
  In/Out：In
  类型：日志句柄
  可空：N
  意思：输入要操作的日志句柄
 参数.二：pSt_XLogColor
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：要设置的打印的颜色
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HelpComponents_XLog_SetLogColor(XLOG xhLog, HELPCOMPONENTS_XLOG_COLOR *pSt_XLogColor);
/********************************************************************
函数名称：HelpComponents_XLog_SetLogAllow
函数功能：设置允许输出的日志类型
 参数.一：xhLog
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的日志句柄
 参数.二：dwAllowLog
  In/Out：In
  类型：双字
  可空：N
  意思：输入允许输出的日志类型,使用|连接
 参数.三：bSingle
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：如果为真,日志级别将不起作用.如果为假,那么将在日志级别允许的范围类进行判断
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" BOOL HelpComponents_XLog_SetLogAllow(XLOG xhLog, DWORD dwAllowLog, BOOL bSingle = TRUE);
/********************************************************************
函数名称：HelpComponents_XLog_GetLogBuffer
函数功能：获取日志队列缓冲区
 参数.一：xhLog
  In/Out：In
  类型：句柄
  可空：N
  意思：输入要操作的日志句柄
 参数.二：ptszMsgBuffer
  In/Out：Out
  类型：字符指针
  可空：N
  意思：输出获取到的日志打包协议
 参数.三：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小,输出获取到的缓冲区大小
返回值
  类型：逻辑型
  意思：是否成功
备注：如果启用了套接字,那么这个函数必须调用,否则会造成日志模块内存溢出
      每次获取一条缓冲区日志,这个协议是组好包的可以直接发送
      如果只想取得日志,而不带协议,那么需要参考协议文档来移动固定指针大小即可
*********************************************************************/
extern "C" BOOL HelpComponents_XLog_GetLogBuffer(XLOG xhLog, CHAR* ptszMsgBuffer, int* pInt_Len);
/********************************************************************
函数名称：HelpComponents_XLog_Print
函数功能：打印日志
 参数.一：dwOutType
  In/Out：In
  类型：双字
  可空：N
  意思：要打印的消息类型
 参数.二：dwOutType
  In/Out：In
  类型：双字
  可空：N
  意思：要打印的消息类型
 参数.三：lpszFunction
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：日志所在函数
 参数.四：nLine
  In/Out：In
  类型：整数型
  可空：N
  意思：打印日志所在行数
 参数.五：bIsLine
  In/Out：In
  类型：逻辑型
  可空：N
  意思：为真换行,为假不换行,假将不会进行日志文件写入
 参数.六：lpszLog
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要打印的日志
返回值
  类型：逻辑型
  意思：是否成功打印了这条消息
备注：日志缓冲区大小不能大于10KB(10000)
*********************************************************************/
extern "C" BOOL HelpComponents_XLog_Print(XLOG xhLog,DWORD dwOutType, LPCSTR lpszFunction, int nLine, BOOL bIsLine, LPCSTR lpszLog, ...);
//////////////////////////////////////////////////////////////////////////
//操作字符串，定义的，方便大家使用
#define XLOG_PRINT(X,Y,Z,...) HelpComponents_XLog_Print(X,Y,__FUNCTION__,__LINE__,TRUE,Z,##__VA_ARGS__)
#define XLOG_FPRINT(X,Y,Z,...) HelpComponents_XLog_Print(X,Y,__FILE__,__LINE__,TRUE,Z,##__VA_ARGS__)
#define XLOG_LPRINT(X,Y,Z,...) HelpComponents_XLog_Print(X,Y,__FUNCTION__,__LINE__,FALSE,Z,##__VA_ARGS__)
