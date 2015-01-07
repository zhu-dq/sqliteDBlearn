#ifndef		_DATABASEMANAGEMENT_H
#define    _DATABASEMANAGEMENT_H
	#if defined(_WIN32)
	#include <WinSock2.h>
	#include  <Windows.h>
	#endif
#include <iostream>
#include <string>
#include <vector>
#include "sqlite3.h"
using namespace std;
#pragma once
class DataBaseManagement
{
public:
	/*
		Sqlite数据库的句柄操作
	*/
	sqlite3* pdb = nullptr;
	/*
		指出错误的信息
	*/
	char *errMsg = 0;
	DataBaseManagement();
	/*
		函数：OpenDB()
		功能：打开数据库 29.db
		参数：无
		返回值：bool
	*/
	bool OpenDB();
	/*
	函数：CreatTable()
	功能：创建表Node 、 NodeRelation    、EventRelation
	参数：无
	返回值：bool
	*/
	bool CreatTable();
	/*
	函数：CloseDb()
	功能：关闭数据库
	参数：无
	返回值：bool
	*/
	bool CloseDb();
	virtual ~DataBaseManagement();
};
#endif

