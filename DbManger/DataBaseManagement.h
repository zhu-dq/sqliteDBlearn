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
	sqlite3* pdb = nullptr;//Sqlite���ݿ�ľ������
	char *errMsg = 0;//ָ���������Ϣ
	DataBaseManagement();
	bool OpenDB();//�����ݿ�
	bool CreatTable();//�������
	bool CloseDb();//�ر����ݿ�
	virtual ~DataBaseManagement();
};

