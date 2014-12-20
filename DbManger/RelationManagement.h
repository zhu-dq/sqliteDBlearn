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
	string  stringID;//目标ID
	vector<string> strv;//目标之间的关系
public:
	RelationManagement();
	static int callbackGetRelationCount(void *para, int n_column, char **column_value, char **column_name);//获取ABRelation个数的回调函数
	static int callbackGetRelation(void *para, int n_column, char **column_value, char **column_name);//GetRelation()的回调函数
	static int callbackGetRelatedJsonID(void *para, int n_column, char **column_value, char **column_name);//GetRelatedJsonID()的回调函数
	vector<string> subvector(vector<string> v1, vector<string> v2);//-------------vector相减,V1-V2
	vector<string> split_str(string str, string pattern);//字符串分割函数,即字符串变成vector。
	bool SetRelation(string strID1, string strID2, vector<string> strc);//添加目标之间的关系
	vector<string> GetRelation(string strID1, string strID2);//查询目标之间是否关系
	bool UpdateRelation(string strID1, string strID2, vector<string> strc);//更新目标之间的关系
	bool DeleteRelation(string strID1, string strID2, vector<string> strc);//删除目标之间的关系
	vector<string> GetRelatedJsonID(string StrID);		//获取和目标有关系的所有ID。
	virtual ~RelationManagement();
};

