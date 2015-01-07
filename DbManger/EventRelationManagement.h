#ifndef  _EVENTRELATIONMANAGEMENT_H
#define	 _EVENTRELATIONMANAGEMENT_H 
#if defined(_WIN32)
	#include <WinSock2.h>
	#include  <Windows.h>
	#endif
#include <iostream>
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
	/*
		�¼���ǩ
	*/
	string str;
	/*
		�¼�֮���Ƿ��й�ϵ
	*/
	bool   b;
public:
	EventRelationManagement();
	/*
		��������callbackGetERelationCount()
		���ܣ���ȡEABRelation�����Ļص�����
		������para,int�͵�ָ�룬��ȡEABRelation�������Զ��壩
			     n_column,ִ��sql��ȡ��������ϵͳ�Զ����أ�
				 column_name��һ��sql����е��������Ǹ����飨ϵͳ�Զ����أ�
				 column_value����������Ӧ����ֵ���Ǹ����飨ϵͳ�Զ����أ�
	����ֵ���̶�ruturn 0.
	*/
	static int callbackGetERelationCount(void *para, int n_column, char **column_value, char **column_name);
	/*
	��������callbackGetERelation()
	���ܣ���ȡEAB֮���Ƿ��й�ϵ�Ļص�����
	������para,string�͵�ָ�룬��ȡEAB֮���ϵ���Զ��壩
	n_column,ִ��sql��ȡ��������ϵͳ�Զ����أ�
	column_name��һ��sql����е��������Ǹ����飨ϵͳ�Զ����أ�
	column_value����������Ӧ����ֵ���Ǹ����飨ϵͳ�Զ����أ�
	����ֵ���̶�ruturn 0.
	*/
	static int callbackGetERelation(void *para, int n_column, char **column_value, char **column_name);
	/*
		��������AddEventRelation����
		���ܣ�����¼�֮��Ĺ�����ϵ
		������strE1����ʾ�¼�1��ID.
				 strE2 ����ʾ�¼�2��ID.
				 b,�¼�1���¼�2�Ƿ���ڹ�ϵ��boolֵ��ture��ʾ�й�ϵ��
		����ֵ��bool,ture��ʾ����ɹ���
	*/
	bool AddEventRelation(string strE1, string strE2,bool b);
	/*
		��������GetEventRelation����
		���ܣ������¼�֮��Ĺ�����ϵ
		������strE1����ʾ�¼�1��ID.
				 strE2 ����ʾ�¼�2��ID.
		����ֵ��bool���ͣ�ture��ʾ�й�ϵ��
	*/
	bool GetEventRelation(string strE1, string strE2);
	/*
	��������UpdateEventRelation����
	���ܣ������¼�֮��Ĺ�����ϵ
		������strE1����ʾ�¼�1��ID.
				 strE2 ����ʾ�¼�2��ID.
				 b,�¼�1���¼�2�Ƿ���ڹ�ϵ��boolֵ��ture��ʾ�й�ϵ��
		����ֵ��bool,ture��ʾ���³ɹ���
	*/
	bool UpdateEventRelation(string strE1, string strE2,bool b);
	/*
	������DeleteEventRelation����
	���ܣ�ɾ���¼�֮��Ĺ�����ϵ
	������strE1����ʾ�¼�1��ID.
				 strE2 ����ʾ�¼�2��ID.
		����ֵ��bool,ture��ʾɾ���ɹ���
	*/
	bool DeleteEventRelation(string strE1, string strE2);
	/*
		������ClearERMCache����
		���ܣ���ջ�����
		��������
		����ֵ����
	*/
	void ClearERMCache();
	virtual ~EventRelationManagement();
};

#endif // !_EVENTRELATIONMANAGEMENT_H