#if defined(_WIN32)
#include <WinSock2.h>
#include  <Windows.h>
#endif
#include <iostream>
#include<list>
#include <string>
#include <vector>
#include "sqlite3.h"
#include "DataBaseManagement.h"
#include "json\json.h"
using namespace std;
#pragma once
class ObjManagement :
	public DataBaseManagement
{
private:
	 string JsonStr;//Json字符串
	 string	stringID;//目标ID

public:
	ObjManagement();
	static int callbackselect(void *para, int n_column, char **column_value, char **column_name);//GetJson()的回调函数
	bool AddJson(string JsonStr);//添加目标的信息
	string GetJson(string strID);//得到目标ID的信息
	bool UpdateJson(string strID,string jsonmsg);//更新目标ID的信息
	bool DeleteJson(string strID);//删除目标ID的信息
	virtual ~ObjManagement();
};

