#if defined(_WIN32)
#include <WinSock2.h>
#include  <Windows.h>
#endif
#include <iostream>
#include<list>
#include <string>
#include <vector>
#include "sqlite3.h"
using namespace std;
#pragma once
class DataBaseManagement
{
public:
	sqlite3* pdb = nullptr;//Sqlite数据库的句柄操作
	char *errMsg = 0;//指出错误的信息
	DataBaseManagement();
	bool OpenDB();//打开数据库
	bool CreatTable();//创建表格
	bool CloseDb();//关闭数据库
	virtual ~DataBaseManagement();
};

