#ifndef _OBJMANAGEMENT_H
#define	 _OBJMANAGEMENT_H
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
	/*
		Json�ַ���
	*/
	 string JsonStr;
	 /*
		Ŀ��ID
	 */
	 string	stringID;

public:
	ObjManagement();
	/*
	��������callbackselect����
	���ܣ�GetJson()�Ļص���������ȡĿ��ID��
	������para,string�͵�ָ�룬��ȡjson�����Զ��壩
			     n_column,ִ��sql��ȡ��������ϵͳ�Զ����أ�
				 column_name��һ��sql����е��������Ǹ����飨ϵͳ�Զ����أ�
				 column_value����������Ӧ����ֵ���Ǹ����飨ϵͳ�Զ����أ�
	����ֵ���̶�ruturn 0.
	*/
	static int callbackselect(void *para, int n_column, char **column_value, char **column_name);
	/*
	������AddJson����
	���ܣ����Ŀ�����Ϣ
	������JsonStr��һ��json���ݵ��ַ�����
	����ֵ��bool,ture��ʾ��ӳɹ���
	*/
	bool AddJson(string JsonStr);
	/*
	������GetJson����
	����:�õ�Ŀ��ID��json�ַ���
	������strID��Ҫ��ȡ��json�ַ�����ID.
	����ֵ��Ŀ��ID��json�ַ�����
	*/
	string GetJson(string strID);
	/*
		������UpdateJson����
		���ܣ�����Ŀ��ID��json�ַ�����
		������strID��Ŀ��ID
				 jsonmsg,���µ����ݡ�
		����ֵ��bool��ture��ʾ���³ɹ���
	*/
	bool UpdateJson(string strID,string jsonmsg);
	/*
		������DeleteJson����
		���ܣ�ɾ��Ŀ��ID��json���ݡ�
		������strID��Ŀ��ID
		����ֵ��bool,true��ʾɾ���ɹ���
	*/
	bool DeleteJson(string strID);
	/*
	������ClearERCache����
	���ܣ���ջ�����
	��������
	����ֵ����
	*/
	void ClearOMGCache();
	virtual ~ObjManagement();
};

#endif // !_OBJMANAGEMENT_H