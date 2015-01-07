#ifndef _RELATTIONMANAGEMENT_H
#define _RELATTIONMANAGEMENT_H
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
class RelationManagement :
	public DataBaseManagement
{
private:
	/*
		Ŀ��ID
	*/
	string  stringID;
	/*
		Ŀ��֮��Ĺ�ϵ
	*/
	vector<string> strv;
public:
	RelationManagement();
	/*
		������callbackGetRelationCount����
		���ܣ���ȡABRelation�����Ļص�����
		������para,int�͵�ָ�룬��ȡABRelation�������Զ��壩
				 n_column,ִ��sql��ȡ��������ϵͳ�Զ����أ�
				 column_name��һ��sql����е��������Ǹ����飨ϵͳ�Զ����أ�
				 column_value����������Ӧ����ֵ���Ǹ����飨ϵͳ�Զ����أ�
		����ֵ���̶�ruturn 0.
	*/
	static int callbackGetRelationCount(void *para, int n_column, char **column_value, char **column_name);
	/*
	��������callbackGetRelation()
	���ܣ���ȡAB֮���Ƿ��й�ϵ�Ļص�����,��ȡ��Ŀ���й�ϵ������ID
	������para,string�͵�ָ�룬��ȡAB֮���ϵ���Զ��壩
		      n_column,ִ��sql��ȡ��������ϵͳ�Զ����أ�
	          column_name��һ��sql����е��������Ǹ����飨ϵͳ�Զ����أ�
	          column_value����������Ӧ����ֵ���Ǹ����飨ϵͳ�Զ����أ�
	����ֵ���̶�ruturn 0.
	*/
	static int callbackGetRelation(void *para, int n_column, char **column_value, char **column_name);
	/*
	��������callbackGetRelatedJsonID()
	���ܣ�GetRelatedJsonID()�Ļص�����
	������para,string�͵�ָ�룬��ȡAB֮���й�ϵ��json��ID���Զ��壩
			  n_column,ִ��sql��ȡ��������ϵͳ�Զ����أ�
			  column_name��һ��sql����е��������Ǹ����飨ϵͳ�Զ����أ�
			  column_value����������Ӧ����ֵ���Ǹ����飨ϵͳ�Զ����أ�
	����ֵ���̶�ruturn 0.
	*/
	static int callbackGetRelatedJsonID(void *para, int n_column, char **column_value, char **column_name);
	/*
	��������addvector����
	���ܣ�ʹ����vector���ӷ�
	������V1,������
			  V2,����
	����ֵ��V1+V2���vector
	*/
	vector<string>& addvector(vector<string> &v1, vector<string> &v2);
	/*
		��������subvector����
		���ܣ�ʹ����vector������
		������V1,������
				  V2,����
		����ֵ��V1-V2���vector
	*/
	vector<string> subvector(vector<string> &v1, vector<string> &v2);
	/*
	������split_str����
	���ܣ����ַ����䰴��ʶ��','��'*'���ո� �ȣ����ָ��ַ������ָ����ַ�������vector
	������str,Ҫ�ָ���ַ���
			  pattern����ʶ��','��'*'���ո� �ȣ�
	����ֵ������ָ�����ݵ�vector
	*/
	vector<string> split_str(string str, string pattern);
	/*
		������SetRelation����
		���ܣ����Ŀ��֮��Ĺ�ϵ
		������ strID1��Ŀ��ID1
				  strID2��Ŀ��ID2
				  strc,���Ŀ��ID֮���ϵ��vector
		����ֵ��bool,ture��ʾ����ɹ���
	*/
	bool SetRelation(string strID1, string strID2, vector<string> strc);
	/*
		������GetRelation����
		���ܣ���ѯĿ��֮���Ƿ��ϵ
		������strID1��Ŀ��ID1
				 strID2 ,  Ŀ��ID2
		����ֵ�����Ŀ��ID֮���ϵ��vector
	*/
	vector<string> GetRelation(string strID1, string strID2);
	/*
		������UpdateRelation����
		���ܣ�����Ŀ��֮��Ĺ�ϵ
		������ strID1��Ŀ��ID1
				  strID2��Ŀ��ID2
				  strc,���Ҫ���µ�Ŀ��ID֮���ϵ��vector
		����ֵ��bool��ture��ʾ���³ɹ���
	*/
	bool UpdateRelation(string strID1, string strID2, vector<string> strc);
	/*
	������AppendRelation����
	���ܣ�����Ŀ��֮��Ĺ�ϵ
	������ strID1��Ŀ��ID1
			  strID2��Ŀ��ID2
			  strc,���Ҫ�����Ŀ��ID֮���ϵ��vector
	����ֵ��bool��ture��ʾ����ɹ���
	*/
	bool AppendRelation(string strID1, string strID2, vector<string> strc);
	/*
		������DeleteRelation����
		���ܣ�ɾ��Ŀ��֮��Ĺ�ϵ
		������ strID1��Ŀ��ID1
				  strID2��Ŀ��ID2
				  strc,���Ҫɾ����Ŀ��ID֮���ϵ��vector
		����ֵ��bool��ture��ʾɾ���ɹ���
	*/
	bool DeleteRelation(string strID1, string strID2, vector<string> strc);
	/*
		������GetRelatedJsonID����
		���ܣ���ȡ��Ŀ���й�ϵ������ID
		������StrID��Ŀ��ID
		����ֵ����Ŀ��ID�й�ϵ��json��ID
	*/
	vector<string> GetRelatedJsonID(string StrID);	
	/*
	������ClearERMCache����
	���ܣ���ջ�����
	��������
	����ֵ����
	*/
	void  ClearRMCache();
	virtual ~RelationManagement();
};

#endif // !_RELATTIONMANAGEMENT_H