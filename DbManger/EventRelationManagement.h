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
	string str;//�¼���ǩ
	bool   b;//�¼�֮���Ƿ��й�ϵ
public:
	EventRelationManagement();
	static int callbackGetERelationCount(void *para, int n_column, char **column_value, char **column_name);//��ȡEABRelation�����Ļص�����
	//callbackGetERelation
	static int callbackGetERelation(void *para, int n_column, char **column_value, char **column_name);//��ȡEAB֮���Ƿ��й�ϵ 
	bool AddEventRelation(string strE1, string strE2,bool b);//����¼�֮��Ĺ�����ϵ
	bool GetEventRelation(string strE1, string strE2);//�����¼�֮��Ĺ�����ϵ
	bool UpdateEventRelation(string strE1, string strE2,bool b);//�����¼�֮��Ĺ�����ϵ
	bool DeleteEventRelation(string strE1, string strE2);//ɾ���¼�֮��Ĺ�����ϵ
	virtual ~EventRelationManagement();
};

