#pragma once
/********************************************************************
//	Created:	2012/5/19  16:23
//	File Name: 	J:\U_DISK_Path\NetSocketEngine\NetEngine_HelpComponents\NetComponents_DataBase\DataBase_Error.h
//	File Path:	J:\U_DISK_Path\NetSocketEngine\NetEngine_HelpComponents\NetComponents_DataBase
//	File Base:	DataBase_Error
//	File Ext:	h
//  Project:    NetSocketEngine(网络通信引擎)
//	Author:		dowflyon
//	Purpose:	数据库错误码导出表
//	History:
*********************************************************************/
//////////////////////////////////////////////////////////////////////////
//                       数据库错误
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/*                       SQLITE数据库错误表                             */
/************************************************************************/
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_OPEN_NOTEXIST 0x70C0000     //文件不存在，打开失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_OPEN_ISFAILED 0x70C0001     //打开数据库失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_OPEN_MALLOC 0x70C0002       //申请内存失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_CLOSE_ISFAILED 0x70C0010    //关闭失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_CLOSE_NOTFOUND 0x70C0011    //没有找到指定句柄
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_CREATE_ISEXIST 0x70C0020    //文件已经存在，请删除后继续
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_CREATE_ISFAILED 0x70C0021   //创建数据库失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_EXEC_PARAMENT 0x70C0030     //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_EXEC_ISFAILED 0x70C0031     //执行SQL语句失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_EXEC_NOTFOUND 0x70C0032     //没有找打指定句柄
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_GETTABLE_PARAMENT 0x70C0040 //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_GETTABLE_NOTFOUND 0x70C0041 //没有找到
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_GETTABLE_ISFAILED 0x70C0042 //执行失败,内部错误
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_EXEQUERY_PARAMENT 0x70C0050 //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_EXEQUERY_NOTFOUND 0x70C0051 //没有找到
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_EXEQUERY_ISFAILED 0x70C0052 //执行失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_DBEXIST_PARAMENT 0x70C0060  //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_DBEXIST_NOTFOUND 0x70C0061  //没有找到
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_DBEXIST_PREPARE 0x70C0062   //解析参数失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_DBEXIST_STEP 0x70C0063      //单步执行失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_DBEXIST_FINAL 0x70C0064     //完成解析失败
#define ERROR_HELPCOMPONENTS_DATABASE_SQLITE_DBEXIST_NOTRECORD 0x70C0065 //没有记录集
/************************************************************************/
/*                       MYSQL数据库错误表                              */
/************************************************************************/
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CONNECT_MYSQL 0x70C1001      //初始化MYSQL内存失败0x70C1001
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CONNECT_SETTIMEOUT 0x70C1002 //设置连接超时时间失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CONNECT_RECONNECT 0x70C1003  //设置自动连接失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CONNECT_ISFAILED 0x70C1004   //连接到MYSQL数据库服务器失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CONNECT_SETCHAR 0x70C1005    //设置字符集失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CONNECT_MULTISTREAM 0x70C1006//设置多语句支持失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CONNECT_MALLOC 0x70C1007     //申请内存失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_EXEC_PARAMENT 0x70C1010      //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_EXEC_NOTFOUND 0x70C1011      //没有找到句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_EXEC_QUERY 0x70C1013         //执行非查询语句失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_EXECQUERY_PARAMENT 0x70C1020 //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_EXECQUERY_NOTFOUND 0x70C1021 //没有找到句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_EXECQUERY_ISFAILED 0x70C1022 //执行查询语句失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_EXECQUERY_NODATA 0x70C1023   //没有数据，查询失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_EXECQUERY_ISNULL 0x70C1024   //获取结果集错误，无法继续
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_GETRESULT_NOTFOUND 0x70C1030 //获取失败，句柄错误
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_GETRESULT_ISNULL 0x70C1031   //获取查询结果集失败，为空
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_GETRESULT_NOTRESULT 0x70C1032//没有找到记录集句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_GETLENGTH_NOTFOUND 0x70C1040 //获取失败，句柄错误
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_GETLENGTH_ISNULL 0x70C1041   //获取查询结果集失败，为空
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_GETLENGTH_NOTRESULT 0x70C1042//没有找到记录集句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_FREERESULT_NOTFOUND 0x70C1050//没有找到句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_GETRESULT_NOTREULT 0x70C1051 //没有找到记录集句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CHANGEUSER_NOTFOUND 0x70C1060//没有找到句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CHANGEUSER_ISFAILED 0x70C1061//改变错误，可能用户名和密码不正确
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CHANGEDB_NOTFOUND 0x70C1070  //没有找到句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CHANGEDB_ISFAILED 0x70C1071  //改变失败，可能DB不存在
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CODER_PARAMENT 0x70C1080     //参数错误，无法继续转换
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CODER_NOTFOUND 0x70C1081     //没有找到句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_CODER_CODER 0x70C1082        //转换失败。内部错误
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_QUERY_PARAMENT 0x70C1090     //执行影响查询失败，参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_QUERY_NOTFOUND 0x70C1091     //没有找到指定句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_QUERY_ISFAILED 0x70C1092     //执行查询语句失败
#define ERROR_HELPCOMPONENTS_DATABASE_MYSQL_QUERY_NODATA 0x70C1093       //没有数据，没有被影响的数据
/************************************************************************/
/*                       MYSQL数据库错误表                                */
/************************************************************************/
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_CONNECT_PARAMENT 0x70C4000   //参数错误，无法继续
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_CONNECT_MALLOC 0x70C4001     //申请内存失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_CONNECT_FAILED 0x70C4002     //链接服务器失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_CONNECT_POOL 0x70C4003       //创建连接池失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_EXECMD_PARAMENT 0x70C4010    //参数错误，执行命令失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_EXECMD_NOTFOUND 0x70C4011    //没有找到
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_EXECMD_GETREPLY 0x70C4012    //获取回复失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_INSERT_PARAMENT 0x70C4020    //参数错误，无法继续
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_INSERT_NOTFOUND 0x70C4021    //没有找到指定的句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_INSERT_GETCOLL 0x70C4022     //获取集合失败，可能数据库或者表不存在
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_INSERT_FAILED 0x70C4023      //插入失败，内部错误
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_FIND_PARAMENT 0x70C4030      //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_FIND_NOTFOUND 0x70C4031      //没有句柄
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_FIND_GETCOLL 0x70C4032       //获取集合失败，可能数据库或者表不存在
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_FIND_FAILED 0x70C4033        //查找失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_UPDATE_PARAMENT 0x70C4040    //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_UPDATE_NOTFOUND 0x70C4041    //没有找到
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_UPDATE_GETCOLL 0x70C4042     //获取集合失败，可能数据库或者表不存在
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_UPDATE_FAILED 0x70C4043      //更新失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_DELETE_PARAMENT 0x70C4050    //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_DELETE_NOTFOUND 0x70C4051    //没有找到
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_DELETE_GETCOLL 0x70C4052     //获取集合失败，可能数据库或者表不存在
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_DELETE_FAILED 0x70C4053      //删除失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_COUNT_PARAMENT 0x70C4060     //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_COUNT_NOTFOUND 0x70C4061     //没有找到
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_COUNT_GETCOLL 0x70C4062      //获取集合失败，可能数据库或者表不存在
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_DELCOLL_PARAMENT 0x70C4070   //参数错误，删除集合失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_DELCOLL_NOTFOUND 0x70C4071   //没有找到
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_DELCOLL_GETCOLL 0x70C4072    //获取集合失败
#define ERROR_HELPCOMPONENTS_DATABASE_MONGO_DELCOLL_FAILED 0x70C4073     //删除集合失败，可能不存在
/************************************************************************/
/*                       POSTGRE数据库错误表                              */
/************************************************************************/
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_CONNECT_PARAMENT 0x70C5000  //参数错误，无法继续
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_CONNECT_MALLOC 0x70C5001    //申请内存失败，无法继续
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_CONNECT_FAILED 0x70C5002    //链接服务器失败
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_EXEC_PARAMENT 0x70C5010     //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_EXEC_NOTFOUND 0x70C5011     //没有找到，无法继续
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_EXEC_FAILED 0x70C5012       //执行命令失败
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_QUERY_PARAMENT 0x70C5020    //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_QUERY_NOTFOUND 0x70C5021    //没有找到，无法继续
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_QUERY_MALLOC 0x70C5022      //申请内存失败
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_QUERY_FAILED 0x70C5023      //执行命令失败
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_GET_PARAMENT 0x70C5030      //参数错误
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_GET_NOTDB 0x70C5031         //没有找到句柄
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_GET_NOTRESULT 0x70C5032     //没有这个记录集指针
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_GET_NODATA 0x70C5033        //没有数据
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_FREE_NOTFOUND 0x70C5040     //没有找到数据库句柄
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFYSTART_PARAMENT 0x70C5050  //参数错误，无法继续
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFYSTART_NOTFOUND 0x70C5051  //没有找到数据库句柄
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFYSTART_FAILED 0x70C5052    //启动监听失败
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFYSTART_MALLOC 0x70C5053    //申请内存失败
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFYSTART_SOCKET 0x70C5054    //创建监听套接字失败
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFYSTART_THREAD 0x70C5055    //创建监听线程失败
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFYSTOP_NOTDB 0x70C5060      //没有数据库句柄
#define ERROR_HELPCOMPONENTS_DATABASE_POSTGRE_NOTIFYSTOP_NOTNOTIFY 0x70C5061  //没有通知句柄
/************************************************************************/
/*                       MSSQL数据库错误导出                            */
/************************************************************************/
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_INIT_PARAMENT 0x70C3001
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_INIT_CREATEINSTANCE 0x70C3002
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_INIT_CONNECT 0x70C3003
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_SELECT_PARAMENT 0x70C3010
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_SELECT_CREATEINSTANCE 0x70C3011
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_SELECT_QUERY 0x70C3012
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_GETNEXT_PARAMENT 0x70C3020
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_GETNEXT_ISNULL 0x70C3021
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_GETNEXT_MOVEREC 0x70C3022
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_CLOSE_RECORDSET 0x70C3030
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_CLOSE_CONNECT 0x70C3031
//////////////////////////////////////////////////////////////////////////
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_EX_INIT_CREATEGUID 0x70C3100
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_EX_INIT_NEWCLASS 0x70C3101
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_EX_SELECT_NOTFOUND 0x70C3101
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_EX_GETNEXT_NOTFOUND 0x70C3101
#define ERROR_HELPCOMPONENTS_DATABASE_MSSQL_EX_CLOSE_NOTFOUND 0x70C3101