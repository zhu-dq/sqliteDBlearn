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
		目标ID
	*/
	string  stringID;
	/*
		目标之间的关系
	*/
	vector<string> strv;
public:
	RelationManagement();
	/*
		函数：callbackGetRelationCount（）
		功能：获取ABRelation个数的回调函数
		参数：para,int型的指针，存取ABRelation个数（自定义）
				 n_column,执行sql获取的行数（系统自动返回）
				 column_name，一行sql结果中的列名，是个数组（系统自动返回）
				 column_value，与列名对应的数值，是个数组（系统自动返回）
		返回值：固定ruturn 0.
	*/
	static int callbackGetRelationCount(void *para, int n_column, char **column_value, char **column_name);
	/*
	函数名：callbackGetRelation()
	功能：获取AB之间是否有关系的回调函数,获取和目标有关系的所有ID
	参数：para,string型的指针，存取AB之间关系（自定义）
		      n_column,执行sql获取的行数（系统自动返回）
	          column_name，一行sql结果中的列名，是个数组（系统自动返回）
	          column_value，与列名对应的数值，是个数组（系统自动返回）
	返回值：固定ruturn 0.
	*/
	static int callbackGetRelation(void *para, int n_column, char **column_value, char **column_name);
	/*
	函数名：callbackGetRelatedJsonID()
	功能：GetRelatedJsonID()的回调函数
	参数：para,string型的指针，存取AB之间有关系的json的ID（自定义）
			  n_column,执行sql获取的行数（系统自动返回）
			  column_name，一行sql结果中的列名，是个数组（系统自动返回）
			  column_value，与列名对应的数值，是个数组（系统自动返回）
	返回值：固定ruturn 0.
	*/
	static int callbackGetRelatedJsonID(void *para, int n_column, char **column_value, char **column_name);
	/*
	函数名：addvector（）
	功能：使连个vector做加法
	参数：V1,被加数
			  V2,加数
	返回值：V1+V2后的vector
	*/
	vector<string>& addvector(vector<string> &v1, vector<string> &v2);
	/*
		函数名：subvector（）
		功能：使连个vector做减法
		参数：V1,被减数
				  V2,减数
		返回值：V1-V2后的vector
	*/
	vector<string> subvector(vector<string> &v1, vector<string> &v2);
	/*
	函数：split_str（）
	功能：将字符串变按标识（','、'*'、空格 等），分割字符串，分割后的字符串存入vector
	参数：str,要分割的字符串
			  pattern，标识（','、'*'、空格 等）
	返回值：存入分割后数据的vector
	*/
	vector<string> split_str(string str, string pattern);
	/*
		函数：SetRelation（）
		功能：添加目标之间的关系
		参数： strID1，目标ID1
				  strID2，目标ID2
				  strc,存放目标ID之间关系的vector
		返回值：bool,ture表示插入成功。
	*/
	bool SetRelation(string strID1, string strID2, vector<string> strc);
	/*
		函数：GetRelation（）
		功能：查询目标之间是否关系
		参数：strID1，目标ID1
				 strID2 ,  目标ID2
		返回值：存放目标ID之间关系的vector
	*/
	vector<string> GetRelation(string strID1, string strID2);
	/*
		函数：UpdateRelation（）
		功能：更新目标之间的关系
		参数： strID1，目标ID1
				  strID2，目标ID2
				  strc,存放要更新的目标ID之间关系的vector
		返回值：bool，ture表示更新成功。
	*/
	bool UpdateRelation(string strID1, string strID2, vector<string> strc);
	/*
	函数：AppendRelation（）
	功能：增添目标之间的关系
	参数： strID1，目标ID1
			  strID2，目标ID2
			  strc,存放要增添的目标ID之间关系的vector
	返回值：bool，ture表示增添成功。
	*/
	bool AppendRelation(string strID1, string strID2, vector<string> strc);
	/*
		函数：DeleteRelation（）
		功能：删除目标之间的关系
		参数： strID1，目标ID1
				  strID2，目标ID2
				  strc,存放要删除的目标ID之间关系的vector
		返回值：bool，ture表示删除成功。
	*/
	bool DeleteRelation(string strID1, string strID2, vector<string> strc);
	/*
		函数：GetRelatedJsonID（）
		功能：获取和目标有关系的所有ID
		参数：StrID，目标ID
		返回值：与目标ID有关系的json的ID
	*/
	vector<string> GetRelatedJsonID(string StrID);	
	/*
	函数：ClearERMCache（）
	功能：清空缓存区
	参数：无
	返回值：无
	*/
	void  ClearRMCache();
	virtual ~RelationManagement();
};

#endif // !_RELATTIONMANAGEMENT_H