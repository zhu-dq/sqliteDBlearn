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
using namespace std;
#pragma once
class EventRelationManagement:
	public DataBaseManagement
{
private:
	string str;//事件标签
	bool   b;//事件之间是否有关系
public:
	EventRelationManagement();
	static int callbackGetERelationCount(void *para, int n_column, char **column_value, char **column_name);//获取EABRelation个数的回调函数
	//callbackGetERelation
	static int callbackGetERelation(void *para, int n_column, char **column_value, char **column_name);//获取EAB之间是否有关系 
	bool AddEventRelation(string strE1, string strE2,bool b);//添加事件之间的关联关系
	bool GetEventRelation(string strE1, string strE2);//查找事件之间的关联关系
	bool UpdateEventRelation(string strE1, string strE2,bool b);//更新事件之间的关联关系
	bool DeleteEventRelation(string strE1, string strE2);//删除事件之间的关联关系
	virtual ~EventRelationManagement();
};

