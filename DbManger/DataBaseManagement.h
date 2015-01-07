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
		Sqlite���ݿ�ľ������
	*/
	sqlite3* pdb = nullptr;
	/*
		ָ���������Ϣ
	*/
	char *errMsg = 0;
	DataBaseManagement();
	/*
		������OpenDB()
		���ܣ������ݿ� 29.db
		��������
		����ֵ��bool
	*/
	bool OpenDB();
	/*
	������CreatTable()
	���ܣ�������Node �� NodeRelation    ��EventRelation
	��������
	����ֵ��bool
	*/
	bool CreatTable();
	/*
	������CloseDb()
	���ܣ��ر����ݿ�
	��������
	����ֵ��bool
	*/
	bool CloseDb();
	virtual ~DataBaseManagement();
};
#endif

