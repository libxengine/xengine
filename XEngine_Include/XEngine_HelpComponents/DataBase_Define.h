﻿#pragma once
/********************************************************************
//	Created:	2011/3/21   13:25
//	Filename: 	d:\U_DISK_Path\NetSocketEngine\DataBaseCtrl\DabaBase_Define.h
//	File Path:	d:\U_DISK_Path\NetSocketEngine\DataBaseCtrl
//	File Base:	DabaBase_Define
//	File Ext:	h
//  Project:    NetSocketEnginer(网络通信引擎)
//	Author:		Dowflyon
//	Purpose:	数据库导出导入定义
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                   导出的回调函数
//////////////////////////////////////////////////////////////////////////
//SQLITE查询回调函数，如果你不使用回调方式查询数据，可以不用设置，参数意思：有多少个字段
typedef void(CALLBACK* CALLBACK_HELPCOMPONENTS_DATABASE_SQLITE_QUERY)(int nNumColumn,LPCXSTR lpszColumnName,LPCXSTR lpszColumnValue,XPVOID lParam);
//POSTGRE数据库通知回调，参数：数据库句柄，通知句柄，通知的服务进程ID，通知的名称，扩展数据，自定义参数
typedef void(CALLBACK* CALLBACK_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFY)(XNETHANDLE xhNet,XNETHANDLE xhNotify,int nPid,LPCXSTR lpszName,LPCXSTR lpszEx,XPVOID lParam);
//////////////////////////////////////////////////////////////////////////
//                   数据结构导出
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                   MYSQL数据结构                                      */
/************************************************************************/
//连接信息结构
typedef struct tag_DataBase_MySQL_ConnectInfo
{
	XCHAR tszSQLAddr[128];                                                 //主机地址
	XCHAR tszSQLName[128];                                                 //用户名
	XCHAR tszSQLPass[128];                                                 //密码
	XCHAR tszDBName[128];                                                  //数据库名称
    int nPort;                                                            //SQL端口
}DATABASE_MYSQL_CONNECTINFO,*LPDATABASE_MYSQL_CONNECTINFO;
//POSTGRE数据结构
typedef struct
{
    XCHAR *ptszName;                                                      //获取到的NAME
    XCHAR *ptszValue;                                                     //获取到的VALUE
    XUINT unLen;                                                           //获取数据大小
    XUINT unOidType;                                                       //获取到的数据类型
}DATABASE_POSTGRE_DATAINFO,*LPDATABASE_POSTGRE_DATAINFO;
//////////////////////////////////////////////////////////////////////////
//                   导出的函数
//////////////////////////////////////////////////////////////////////////
//获取错误码
extern "C" XLONG DataBase_GetLastError(int *pInt_ErrorCode = NULL);
/************************************************************************/
/*                   SQLITE数据库函数导出操作                           */
/************************************************************************/
/********************************************************************
函数名称：DataBase_SQLite_Create
函数功能：创建一个SQLITE数据库
 参数.一：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要创建的路径
返回值
  类型：逻辑型
  意思：是否创建成功
备注：
*********************************************************************/
extern "C" bool DataBase_SQLite_Create(LPCXSTR lpszFileName);
/********************************************************************
函数名称：DataBase_SQLite_Open
函数功能：打开一个SQLITE数据库
 参数.一：pxhData
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：导出一个分配后的数据库句柄，以后你需要通过此来操作数据库
 参数.二：lpszFileName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：SQLITE数据库路径
返回值
  类型：逻辑型
  意思：是否打开成功
备注：不能重复打开，你需要自己判断是否重复打开一个数据库
*********************************************************************/
extern "C" bool DataBase_SQLite_Open(XNETHANDLE *pxhData,LPCXSTR lpszFileName);
/********************************************************************
函数名称：DataBase_SQLite_Close
函数功能：关闭数据库
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要关闭的数据库句柄
返回值
  类型：逻辑型
  意思：是否关闭成功
备注：
*********************************************************************/
extern "C" bool DataBase_SQLite_Close(XNETHANDLE xhData);
/********************************************************************
函数名称：DataBase_SQLite_Exec
函数功能：执行一条语句,非查询语句
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要操作的数据库句柄
 参数.二：lpszSQLExec
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要执行的SQL语句
返回值
  类型：逻辑型
  意思：是否执行成功
备注：
*********************************************************************/
extern "C" bool DataBase_SQLite_Exec(XNETHANDLE xhData,LPCXSTR lpszSQLExec);
/********************************************************************
函数名称：DataBase_SQLite_GetTable
函数功能：获取查询语句返回的值
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要对哪个数据库进行操作
 参数.二：lpszSQL
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要执行的SQL语句
 参数.三：ppTszString
  In/Out：Out
  类型：指向字符指针的指针的指针
  可空：N
  意思：保存结果的记录集数据  ppTszString[i]
 参数.四：pInt_Row
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：执行后影响的行数
 参数.五：pInt_Column
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：执行后影响的列数
返回值
  类型：逻辑型
  意思：是否执行成功
备注：
*********************************************************************/
extern "C" bool DataBase_SQLite_GetTable(XNETHANDLE xhData,LPCXSTR lpszSQL,char ***ppTszString,int *pInt_Row,int *pInt_Column);
/********************************************************************
函数名称：DataBase_SQLite_FreeTable
函数功能：释放查询的记录集内存
 参数.一：ppTszString
  In/Out：In
  类型：字符指针
  可空：N
  意思：要释放的内存
返回值
  类型：逻辑型
  意思：是否释放成功
备注：DataBase_SQLite_GetTable 查询成功后必须使用此函数释放，否则不允许下次查询
*********************************************************************/
extern "C" bool DataBase_SQLite_FreeTable(char **ppTszString);
/********************************************************************
函数名称：DataBase_SQLite_ExecQuery
函数功能：通过回调来查询内容
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要查询的指定数据库
 参数.二：lpszSQL
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要查询的数据库语句
 参数.三：lpCall_SQLiteQuery
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：查询到的数据回调，失败将无作用
 参数.四：lParam
  In/Out：In/Out
  类型：无类型指针
  可空：Y
  意思：回调函数自定义参数
返回值
  类型：逻辑型
  意思：是否查询成功
备注：
*********************************************************************/
extern "C" bool DataBase_SQLite_ExecQuery(XNETHANDLE xhData,LPCXSTR lpszSQL,CALLBACK_HELPCOMPONENTS_DATABASE_SQLITE_QUERY fpCall_SQLiteQuery,XPVOID lParam = NULL);
/********************************************************************
函数名称：DataBase_SQLite_DBExist
函数功能：查询指定表中的字段是否存在
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要查询哪个数据库
 参数.二：lpszTable
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要查询的表
 参数.三：lpszField
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要查询的字段
 参数.四：pInt_Count
  In/Out：In
  类型：整数型指针
  可空：Y
  意思：获取查询到的记录个数，如果为NULL，表示不关心
返回值
  类型：逻辑型
  意思：是否获取成功，返回错误ERROR_HELPCOMPONENTS_DATABASE_SQLITE_DBEXIST_NOTRECORD 表示没有记录，返回真 第四个参数将有作用（如果你第四个参数不为NULL的话！）
备注：
*********************************************************************/
extern "C" bool DataBase_SQLite_DBExist(XNETHANDLE xhData,LPCXSTR lpszTable,LPCXSTR lpszField,int *pInt_Count = NULL);
/************************************************************************/
/*                   MYSQL数据库函数导出操作                            */
/************************************************************************/
/********************************************************************
函数名称：DataBase_MySQL_Connect
函数功能：连接到MYSQL服务器
 参数.一：pxhData
  In/Out：Out
  类型：数据库句柄
  可空：N
  意思：导出分配后的MYSQL数据库句柄
 参数.二：pSt_MySQLConnector
  In/Out：In
  类型：结构体指针
  可空：N
  意思：连接客户端信息结构
 参数.三：nTimeOut
  In/Out：In
  类型：整数型
  可空：Y
  意思：连接超时时间，默认5秒
 参数.四：bAutoReconnect
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：是否在检测到断开与服务器连接后自动连接，默认为真
 参数.五：lpszCharSet
  In/Out：In
  类型：常量字符指针
  可空：Y
  意思：输入链接的数据库的字符集，默认utf8
返回值
  类型：逻辑型
  意思：是否连接成功
备注：
*********************************************************************/
extern "C" bool DataBase_MySQL_Connect(XNETHANDLE *pxhData,DATABASE_MYSQL_CONNECTINFO *pSt_MySQLConnector,int nTimeOut = 5,bool bAutoReconnect = true,LPCXSTR lpszCharSet = ("utf8"));
/********************************************************************
函数名称：DataBase_MySQL_Execute
函数功能：执行非查询语句
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要对哪个SQL客户端执行
 参数.二：lpszSQLQuery
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要执行的SQL语句
 参数.三：pInt_Rows
  In/Out：In/Out
  类型：整数型指针
  可空：Y
  意思：输入数据大小,输出受影响的行数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_MySQL_Execute(XNETHANDLE xhData,LPCXSTR lpszSQLQuery, __int64u *pInt_Rows = NULL);
/********************************************************************
函数名称：DataBase_MySQL_QueryEffect
函数功能：执行查询语句并且获得影响的行数
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要对哪个SQL客户端执行
 参数.二：lpszSQLQuery
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：SQL语句
 参数.三：pulField
  In/Out：Out
  类型：双字64位
  可空：N
  意思：导出执行后被影响的行数
返回值
  类型：逻辑型
  意思：是否执行成功
备注：
*********************************************************************/
extern "C" bool DataBase_MySQL_QueryEffect(XNETHANDLE xhData,LPCXSTR lpszSQLQuery,XLONG *pulField);
/********************************************************************
函数名称：DataBase_MySQL_ExecuteQuery
函数功能：执行查询语句
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要对哪个SQL客户端执行
 参数.二：pxhResult
  In/Out：Out
  类型：记录集句柄
  可空：N
  意思：导出查询的数据库记录集
 参数.三：lpszSQLQuery
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：SQL语句
 参数.四：pullLine
  In/Out：Out
  类型：双字64位
  可空：N
  意思：结果集的行数
 参数.五：pullField
  In/Out：Out
  类型：双字64位
  可空：N
  意思：结果集的列数
返回值
  类型：逻辑型
  意思：是否执行成功
备注：
*********************************************************************/
extern "C" bool DataBase_MySQL_ExecuteQuery(XNETHANDLE xhData,XNETHANDLE *pxhResult,LPCXSTR lpszSQLQuery,__int64u *pullLine,__int64u *pullField);
/********************************************************************
函数名称：DataBase_MySQL_GetResult
函数功能：获取结果集
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要对哪个SQL客户端执行
 参数.二：xhResult
  In/Out：In
  类型：记录集句柄
  可空：N
  意思：要对哪个记录集进行操作
返回值
  类型：指向字符指针的指针
  意思：返回获取到的结果集
备注：
*********************************************************************/
extern "C" XCHAR** DataBase_MySQL_GetResult(XNETHANDLE xhData, XNETHANDLE xhResult);
/********************************************************************
函数名称：DataBase_MySQL_GetLength
函数功能：获得结果集的长度
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要对哪个SQL客户端执行
 参数.二：xhResult
  In/Out：In
  类型：记录集句柄
  可空：N
  意思：要对哪个记录集进行操作
返回值
  类型：双字指针
  意思：返回获取到的每个结果集长度Len = XLONG[i]
备注：
*********************************************************************/
extern "C" XLONG* DataBase_MySQL_GetLength(XNETHANDLE xhData, XNETHANDLE xhResult);
/********************************************************************
函数名称：DataBase_MySQL_FreeResult
函数功能：释放查询的结果集
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要对哪个SQL客户端执行
 参数.二：xhResult
  In/Out：In
  类型：记录集句柄
  可空：Y
  意思：要对哪个记录集操作，默认释放所有相关联记录集
返回值
  类型：逻辑型
  意思：是否释放成功
备注：
*********************************************************************/
extern "C" bool DataBase_MySQL_FreeResult(XNETHANDLE xhData,XNETHANDLE xhResult = 0);
/********************************************************************
函数名称：DataBase_MySQL_ChangeUser
函数功能：改变用户
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要对哪个SQL客户端执行
 参数.二：st_MySQLConnector
  In/Out：In
  类型：结构体
  可空：N
  意思：用户信息结构
返回值
  类型：逻辑型
  意思：是否改变成功
备注：第二个参数只有用户名，密码和数据库名有效，其他成员必须与之前保持一致
*********************************************************************/
extern "C" bool DataBase_MySQL_ChangeUser(XNETHANDLE xhData,DATABASE_MYSQL_CONNECTINFO st_MySQLConnector);
/********************************************************************
函数名称：DataBase_MySQL_ChangeDB
函数功能：以当前身份改变数据库
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要对哪个SQL客户端执行
 参数.二：st_MySQLConnector
  In/Out：In
  类型：结构体
  可空：N
  意思：用户信息结构
返回值
  类型：逻辑型
  意思：是否改变成功
备注：第二个参数只有DBNAME有效，其他成员必须与之前保持一致
*********************************************************************/
extern "C" bool DataBase_MySQL_ChangeDB(XNETHANDLE xhData,DATABASE_MYSQL_CONNECTINFO st_MySQLConnector);
/********************************************************************
函数名称：DataBase_MySQL_Close
函数功能：关闭与MYSQL的连接并且释放资源
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要关闭的数据库
返回值
  类型：逻辑型
  意思：是否成功关闭
备注：
*********************************************************************/
extern "C" bool DataBase_MySQL_Close(XNETHANDLE xhData);
/********************************************************************
函数名称：DataBase_MySQL_Coder
函数功能：编码一段SQL语句用于自动处理一些特殊符号
 参数.一：xhData
  In/Out：In
  类型：数据库句柄
  可空：N
  意思：要操作的数据库句柄
 参数.二：lpszSourceString
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：待转换的SQL语句
 参数.三：ptszDestString
  In/Out：Out
  类型：指向字符的指针
  可空：N
  意思：导出转换后的语句
 参数.四：pInt_Len
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入待转换语句长度，输出转换后语句长度
返回值
  类型：逻辑型
  意思：是否执行成功
备注：
*********************************************************************/
extern "C" bool DataBase_MySQL_Coder(XNETHANDLE xhData,LPCXSTR lpszSourceString,XCHAR *ptszDestString,int *pInt_Len);
/************************************************************************/
/*                     MONGO 数据库函数导出操作                            */
/************************************************************************/
/********************************************************************
函数名称：DataBase_Mongo_Connect
函数功能：链接到一个MONGODB服务器
 参数.一：pxhNet
  In/Out：Out
  类型：句柄指针
  可空：N
  意思：导出数据库句柄
 参数.二：lpszDBUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要链接的地址，如：mongodb://localhost:27017
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Mongo_Connect(XNETHANDLE *pxhNet,LPCXSTR lpszDBUrl);
/********************************************************************
函数名称：DataBase_Mongo_Close
函数功能：关闭数据库链接并且清理资源
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Mongo_Close(XNETHANDLE xhNet);
/********************************************************************
函数名称：DataBase_Mongo_ExecCmd
函数功能：执行一条命令并且获得回复
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：lpszDBName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的数据库名
 参数.三：lpszBsonDoc
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的BSON结构
 参数.四：ptszJsonBuffer
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：导出服务器的返回内容，JSON格式。
 参数.五：pInt_JsonLen
  In/Out：In/Out
  类型：整数型指针
  可空：N
  意思：输入提供的缓冲区大小，输出获取到的缓冲区大小
 参数.六：bBson
  In/Out：In
  类型：逻辑型
  可空：Y
  意思：输入数据是BSON还是JSON格式，默认BSON
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Mongo_ExecCmd(XNETHANDLE xhNet,LPCXSTR lpszDBName,LPCXSTR lpszBsonDoc,XCHAR *ptszJsonBuffer,int *pInt_JsonLen,bool bBson = true);
/********************************************************************
函数名称：DataBase_Mongo_InsertBson
函数功能：通过BSON插入一条数据到数据库
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：lpszDBName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的数据库
 参数.三：lpszCollName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的集合
 参数.四：lpszBSonDoc
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的BSON结构
返回值
  类型：逻辑型
  意思：是否成功
备注：用户自己管理BSON结构和内存，构建完毕后传递给参数四。
*********************************************************************/
extern "C" bool DataBase_Mongo_InsertBson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszBSonDoc);
extern "C" bool DataBase_Mongo_InsertJson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszJSonDoc);
/********************************************************************
函数名称：DataBase_Mongo_FindBson
函数功能：通过BSON查找一条数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：lpszDBName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的数据库
 参数.三：lpszCollName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的集合
 参数.四：lpszBSonDoc
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：BSON查询语句,可以为NULL
 参数.五：lpszBsonOpt
  In/Out：Out
  类型：常量字符指针
  可空：N
  意思：BSON查询选项,可以为NULL
 参数.六：pppnListData
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的数据JSON结构
 参数.七：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：获取到的列表个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数六需要调用基础库的BaseLib_OperatorMemory_Free函数进行内存释放
*********************************************************************/
extern "C" bool DataBase_Mongo_FindBson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszBSonDoc, LPCXSTR lpszBsonOpt, XCHAR * **pppnListData, int* pInt_ListCount);
extern "C" bool DataBase_Mongo_FindJson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszJSonDoc, LPCXSTR lpszJsonOpt, XCHAR * **pppnListData, int* pInt_ListCount);
/********************************************************************
函数名称：DataBase_Mongo_UPDateBson
函数功能：更新一条数据通过BSON
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：lpszDBName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的数据库
 参数.三：lpszCollName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的集合
 参数.四：lpszBSonSelect
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：待更新的数据BSON
 参数.五：lpszBsonUPdate
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：更新到的BSON结构
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Mongo_UPDateBson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszBSonSelect, LPCXSTR lpszBsonUPdate);
extern "C" bool DataBase_Mongo_UPDateJson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszJSonSelect, LPCXSTR lpszJsonUPdate);
/********************************************************************
函数名称：DataBase_Mongo_DeleteBson
函数功能：删除一条数据通过BSON
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：lpszDBName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的数据库
 参数.三：lpszCollName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的集合
 参数.四：lpszBSonDoc
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：待删除的BSON结构数据
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Mongo_DeleteBson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszBSonDoc);
extern "C" bool DataBase_Mongo_DeleteJson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszJSonDoc);
/********************************************************************
函数名称：DataBase_Mongo_CountBson
函数功能：文档统计通过BSON
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：lpszDBName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的数据库
 参数.三：lpszCollName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的集合
 参数.四：lpszBSonDoc
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要统计的数据BSON格式
 参数.五：pInt_Count
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：输出统计的个数
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Mongo_CountBson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszBSonDoc, int *pInt_Count);
extern "C" bool DataBase_Mongo_CountJson(XNETHANDLE xhNet, LPCXSTR lpszDBName, LPCXSTR lpszCollName, LPCXSTR lpszJSonDoc, int *pInt_Count);
/********************************************************************
函数名称：DataBase_Mongo_DeleteCollection
函数功能：删除采集器
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：lpszDBName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的数据库
 参数.三：lpszCollName
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要操作的集合
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Mongo_DeleteCollection(XNETHANDLE xhNet,LPCXSTR lpszDBName,LPCXSTR lpszCollName);
/************************************************************************/
/*                     POSTGRE数据库函数导出操作                           */
/************************************************************************/
/********************************************************************
函数名称：DataBase_Postgre_Connect
函数功能：链接到一个POSTGRE服务器
 参数.一：pxhNet
  In/Out：Out
  类型：句柄指针
  可空：N
  意思：导出数据库句柄
 参数.二：lpszDBUrl
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要链接的地址，如：hostaddr=192.168.0.101 user=postgres dbname=testdb1
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Postgre_Connect(XNETHANDLE *pxhNet,LPCXSTR lpszDBUrl);
/********************************************************************
函数名称：DataBase_Postgre_ConnectWithStruct
函数功能：通过结构体连接到PG数据库
 参数.一：pxhNet
  In/Out：Out
  类型：句柄
  可空：N
  意思：输出成功后的操作句柄
 参数.二：pSt_DBConnector
  In/Out：In
  类型：数据结构指针
  可空：N
  意思：输入数据库信息
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Postgre_ConnectWithStruct(XNETHANDLE* pxhNet, DATABASE_MYSQL_CONNECTINFO* pSt_DBConnector);
/********************************************************************
函数名称：DataBase_Postgre_Close
函数功能：关闭一个PG数据库句柄的链接
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：关闭之前需要先把记录集和通知关闭
*********************************************************************/
extern "C" bool DataBase_Postgre_Close(XNETHANDLE xhNet);
/********************************************************************
函数名称：DataBase_Postgre_Exec
函数功能：执行一条PG数据库非查询语句或者执行一条PG命令
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：lpszQuery
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要执行的数据库语句
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Postgre_Exec(XNETHANDLE xhNet,LPCXSTR lpszQuery);
/********************************************************************
函数名称：DataBase_Postgre_QueryResult
函数功能：执行一条PG数据库查询语句
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：pxhResult
  In/Out：Out
  类型：句柄指针
  可空：N
  意思：导出记录集句柄
 参数.三：lpszQuery
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：要执行的查询语句
 参数.四：pullLine
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出记录集个数
 参数.五：pullField
  In/Out：Out
  类型：整数型指针
  可空：Y
  意思：导出字段个数
返回值
  类型：逻辑型
  意思：是否成功
备注：通过这个函数可以查询内容，导出的一个句柄可以操作记录集，不使用必须释放
*********************************************************************/
extern "C" bool DataBase_Postgre_QueryResult(XNETHANDLE xhNet, XNETHANDLE * pxhResult, LPCXSTR lpszQuery, int* pullLine = NULL, int* pullField = NULL);
/********************************************************************
函数名称：DataBase_Postgre_QueryResult
函数功能：获取查询语句执行的数据
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：xhResult
  In/Out：In
  类型：句柄
  可空：N
  意思：输入记录集句柄
 参数.三：pppSt_ListData
  In/Out：Out
  类型：三级指针
  可空：N
  意思：导出获取到的数据
 参数.四：pInt_ListCount
  In/Out：Out
  类型：整数型指针
  可空：N
  意思：导出数据个数
 参数.五：ullLine
  In/Out：In
  类型：整数型
  可空：N
  意思：输入记录集行数
 参数.六：ullField
  In/Out：In
  类型：整数型
  可空：N
  意思：输入记录集字段个数
返回值
  类型：逻辑型
  意思：是否成功
备注：参数三需要调用基础库的BaseLib_OperatorMemory_Free函数进行内存释放
*********************************************************************/
extern "C" bool DataBase_Postgre_GetResult(XNETHANDLE xhNet, XNETHANDLE xhResult, DATABASE_POSTGRE_DATAINFO * **pppSt_ListData, int* pInt_ListCount, int ullLine, int ullField);
/********************************************************************
函数名称：DataBase_Postgre_FreeResult
函数功能：释放一个记录集句柄资源
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：xhResult
  In/Out：In
  类型：句柄
  可空：N
  意思：输入记录集句柄
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Postgre_FreeResult(XNETHANDLE xhNet,XNETHANDLE xhResult);
/********************************************************************
函数名称：DataBase_Postgre_NotifyStart
函数功能：启动一个数据库监听服务
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：pxhNotify
  In/Out：Out
  类型：句柄指针
  可空：N
  意思：导出通知句柄指针
 参数.三：lpszListenStr
  In/Out：In
  类型：常量字符指针
  可空：N
  意思：监听的数据，比如：LISTEN TBL2，监听TBL2表的更改
 参数.四：fpCall_Notify
  In/Out：In/Out
  类型：回调函数
  可空：N
  意思：导出监听到的数据变化名称
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
extern "C" bool DataBase_Postgre_NotifyStart(XNETHANDLE xhNet,XNETHANDLE *pxhNotify,LPCXSTR lpszListenStr,CALLBACK_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFY fpCall_Notify,XPVOID lParam = NULL);
/********************************************************************
函数名称：DataBase_Postgre_NotifyStop
函数功能：停止一个数据库监听服务
 参数.一：xhNet
  In/Out：In
  类型：句柄
  可空：N
  意思：输入数据库句柄
 参数.二：xhNotify
  In/Out：In
  类型：句柄
  可空：N
  意思：输入通知句柄指针
返回值
  类型：逻辑型
  意思：是否成功
备注：
*********************************************************************/
extern "C" bool DataBase_Postgre_NotifyStop(XNETHANDLE xhNet,XNETHANDLE xhNotify);
