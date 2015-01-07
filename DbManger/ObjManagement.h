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
		Json字符串
	*/
	 string JsonStr;
	 /*
		目标ID
	 */
	 string	stringID;

public:
	ObjManagement();
	/*
	函数名：callbackselect（）
	功能：GetJson()的回调函数，获取目标ID。
	参数：para,string型的指针，存取json对象（自定义）
			     n_column,执行sql获取的行数（系统自动返回）
				 column_name，一行sql结果中的列名，是个数组（系统自动返回）
				 column_value，与列名对应的数值，是个数组（系统自动返回）
	返回值：固定ruturn 0.
	*/
	static int callbackselect(void *para, int n_column, char **column_value, char **column_name);
	/*
	函数：AddJson（）
	功能：添加目标的信息
	参数：JsonStr，一条json数据的字符串。
	返回值：bool,ture表示添加成功。
	*/
	bool AddJson(string JsonStr);
	/*
	函数：GetJson（）
	功能:得到目标ID的json字符串
	参数：strID，要获取的json字符串发ID.
	返回值：目标ID的json字符串。
	*/
	string GetJson(string strID);
	/*
		函数：UpdateJson（）
		功能：更新目标ID的json字符串。
		参数：strID，目标ID
				 jsonmsg,更新的内容。
		返回值：bool，ture表示更新成功。
	*/
	bool UpdateJson(string strID,string jsonmsg);
	/*
		函数：DeleteJson（）
		功能：删除目标ID的json数据。
		参数：strID，目标ID
		返回值：bool,true表示删除成功。
	*/
	bool DeleteJson(string strID);
	/*
	函数：ClearERCache（）
	功能：清空缓存区
	参数：无
	返回值：无
	*/
	void ClearOMGCache();
	virtual ~ObjManagement();
};

#endif // !_OBJMANAGEMENT_H