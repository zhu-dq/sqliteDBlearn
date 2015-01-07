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
		事件标签
	*/
	string str;
	/*
		事件之间是否有关系
	*/
	bool   b;
public:
	EventRelationManagement();
	/*
		函数名：callbackGetERelationCount()
		功能：获取EABRelation个数的回调函数
		参数：para,int型的指针，存取EABRelation个数（自定义）
			     n_column,执行sql获取的行数（系统自动返回）
				 column_name，一行sql结果中的列名，是个数组（系统自动返回）
				 column_value，与列名对应的数值，是个数组（系统自动返回）
	返回值：固定ruturn 0.
	*/
	static int callbackGetERelationCount(void *para, int n_column, char **column_value, char **column_name);
	/*
	函数名：callbackGetERelation()
	功能：获取EAB之间是否有关系的回调函数
	参数：para,string型的指针，存取EAB之间关系（自定义）
	n_column,执行sql获取的行数（系统自动返回）
	column_name，一行sql结果中的列名，是个数组（系统自动返回）
	column_value，与列名对应的数值，是个数组（系统自动返回）
	返回值：固定ruturn 0.
	*/
	static int callbackGetERelation(void *para, int n_column, char **column_value, char **column_name);
	/*
		函数名：AddEventRelation（）
		功能：添加事件之间的关联关系
		参数：strE1，表示事件1的ID.
				 strE2 ，表示事件2的ID.
				 b,事件1与事件2是否存在关系的bool值。ture表示有关系。
		返回值：bool,ture表示插入成功。
	*/
	bool AddEventRelation(string strE1, string strE2,bool b);
	/*
		函数名：GetEventRelation（）
		功能：查找事件之间的关联关系
		参数：strE1，表示事件1的ID.
				 strE2 ，表示事件2的ID.
		返回值：bool类型，ture表示有关系。
	*/
	bool GetEventRelation(string strE1, string strE2);
	/*
	函数名：UpdateEventRelation（）
	功能：更新事件之间的关联关系
		参数：strE1，表示事件1的ID.
				 strE2 ，表示事件2的ID.
				 b,事件1与事件2是否存在关系的bool值。ture表示有关系。
		返回值：bool,ture表示更新成功。
	*/
	bool UpdateEventRelation(string strE1, string strE2,bool b);
	/*
	函数：DeleteEventRelation（）
	功能：删除事件之间的关联关系
	参数：strE1，表示事件1的ID.
				 strE2 ，表示事件2的ID.
		返回值：bool,ture表示删除成功。
	*/
	bool DeleteEventRelation(string strE1, string strE2);
	/*
		函数：ClearERMCache（）
		功能：清空缓存区
		参数：无
		返回值：无
	*/
	void ClearERMCache();
	virtual ~EventRelationManagement();
};

#endif // !_EVENTRELATIONMANAGEMENT_H