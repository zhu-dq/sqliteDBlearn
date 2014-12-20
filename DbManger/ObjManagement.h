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
	 string JsonStr;//Json�ַ���
	 string	stringID;//Ŀ��ID

public:
	ObjManagement();
	static int callbackselect(void *para, int n_column, char **column_value, char **column_name);//GetJson()�Ļص�����
	bool AddJson(string JsonStr);//���Ŀ�����Ϣ
	string GetJson(string strID);//�õ�Ŀ��ID����Ϣ
	bool UpdateJson(string strID,string jsonmsg);//����Ŀ��ID����Ϣ
	bool DeleteJson(string strID);//ɾ��Ŀ��ID����Ϣ
	virtual ~ObjManagement();
};

