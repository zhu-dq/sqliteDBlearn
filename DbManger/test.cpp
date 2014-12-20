#if defined(_WIN32)
#include <WinSock2.h>
#include  <Windows.h>
#endif
#include <iostream>
#include<list>
#include <string>
#include <vector>
#include "sqlite3.h"
#include "json\json.h"
#include "DataBaseManagement.h"
#include "EventRelationManagement.h"
#include "ObjManagement.h"
#include "RelationManagement.h"
#include <fstream>
using namespace std;
int main()
{
	fstream outFile;
	outFile.open("inFile.txt", ios::in);
	ifstream f;
	f.open("E:\\data.txt");
	if (!f)
		cout << "error";
	//解析Json的方法
	Json::Reader reader;
	Json::Value json_object;
	reader.parse(f, json_object, false);
	f.close();
	DataBaseManagement *dbm = new DataBaseManagement();

	//---------------------------------------------------------test     ObjManagement-----------------------------------------------------------------------------
	//ObjManagement  *omg = new ObjManagement();
	//omg->AddJson(json_object.toStyledString());           //添加
	//string	strjson1=omg->GetJson("6851999");              //获取
	//cout << "strjson1" << endl;
	//cout << strjson1 << endl;
	//omg->UpdateJson("6851999", json_object.toStyledString());//更新
	//string	strjson2 = omg->GetJson("6851999");              //获取
	//cout << "strjson2" << endl;
	//cout << strjson2 << endl;
	//omg->DeleteJson("6851999");//删除操作
	//string	strjson3 = omg->GetJson("6851999");              //获取
	//cout << "strjson3" << endl;
	//cout << strjson3 << endl;
	//delete(omg);

	//------------------------------------------------------test         RelationManagement
	//RelationManagement *rmg = new RelationManagement();
	//vector<string> v1;
	//v1.push_back("高度");
	//v1.push_back("pinlv");
	//v1.push_back("距离");
	//v1.push_back(" ");
	//rmg->SetRelation("101","202",v1);//增加属性关系v1
	//vector<string> v12 = rmg->GetRelation("101","202");//获取关系属性
	//for (vector<string> ::iterator i = v12.begin(); i !=v12.end(); i++)
	//{
	//	cout << *i << "\t";
	//}
	//vector<string> v2;
	//v2.push_back("juli");
	//v2.push_back("频率");
	//v2.push_back("距离");
	//rmg->UpdateRelation("101","202",v2);//更新属性关系为v2
	//vector<string> v3;
	//v3.push_back("距离");
	//rmg->DeleteRelation("101","202",v3);//删除含v3属性的值
	//vector<string>v4 =	rmg->GetRelatedJsonID("101");//获取和目标有关系的所有ID。
	//cout << "和101有关的ID" << endl;
	//for (vector<string>::iterator i = v4.begin(); i !=v4.end(); i++)
	//{
	//	cout << *i<<endl;
	//}
	//delete(rmg);
	//-------------------------------------test EventRelationManagement
	EventRelationManagement  * erm = new EventRelationManagement();
	erm->AddEventRelation("101","202",1);//添加事件之间的关联关系
	bool b1 = erm->GetEventRelation("101","202");//查找事件之间的关联关系
	erm->UpdateEventRelation("101","202",1);//更新事件之间的关联关系
	erm->DeleteEventRelation("101","202");//删除事件之间的关联关系
	delete(dbm);
	getchar();
}