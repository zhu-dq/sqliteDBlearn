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
class RelationManagement :
	public DataBaseManagement
{
private:
	string  stringID;//Ŀ��ID
	vector<string> strv;//Ŀ��֮��Ĺ�ϵ
public:
	RelationManagement();
	static int callbackGetRelationCount(void *para, int n_column, char **column_value, char **column_name);//��ȡABRelation�����Ļص�����
	static int callbackGetRelation(void *para, int n_column, char **column_value, char **column_name);//GetRelation()�Ļص�����
	static int callbackGetRelatedJsonID(void *para, int n_column, char **column_value, char **column_name);//GetRelatedJsonID()�Ļص�����
	vector<string> subvector(vector<string> v1, vector<string> v2);//-------------vector���,V1-V2
	vector<string> split_str(string str, string pattern);//�ַ����ָ��,���ַ������vector��
	bool SetRelation(string strID1, string strID2, vector<string> strc);//���Ŀ��֮��Ĺ�ϵ
	vector<string> GetRelation(string strID1, string strID2);//��ѯĿ��֮���Ƿ��ϵ
	bool UpdateRelation(string strID1, string strID2, vector<string> strc);//����Ŀ��֮��Ĺ�ϵ
	bool DeleteRelation(string strID1, string strID2, vector<string> strc);//ɾ��Ŀ��֮��Ĺ�ϵ
	vector<string> GetRelatedJsonID(string StrID);		//��ȡ��Ŀ���й�ϵ������ID��
	virtual ~RelationManagement();
};

