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
	//����Json�ķ���
	Json::Reader reader;
	Json::Value json_object;
	reader.parse(f, json_object, false);
	f.close();
	DataBaseManagement *dbm = new DataBaseManagement();

	//---------------------------------------------------------test     ObjManagement-----------------------------------------------------------------------------
	//ObjManagement  *omg = new ObjManagement();
	//omg->AddJson(json_object.toStyledString());           //���
	//string	strjson1=omg->GetJson("6851999");              //��ȡ
	//cout << "strjson1" << endl;
	//cout << strjson1 << endl;
	//omg->UpdateJson("6851999", json_object.toStyledString());//����
	//string	strjson2 = omg->GetJson("6851999");              //��ȡ
	//cout << "strjson2" << endl;
	//cout << strjson2 << endl;
	//omg->DeleteJson("6851999");//ɾ������
	//string	strjson3 = omg->GetJson("6851999");              //��ȡ
	//cout << "strjson3" << endl;
	//cout << strjson3 << endl;
	//delete(omg);

	//------------------------------------------------------test         RelationManagement
	//RelationManagement *rmg = new RelationManagement();
	//vector<string> v1;
	//v1.push_back("�߶�");
	//v1.push_back("pinlv");
	//v1.push_back("����");
	//v1.push_back(" ");
	//rmg->SetRelation("101","202",v1);//�������Թ�ϵv1
	//vector<string> v12 = rmg->GetRelation("101","202");//��ȡ��ϵ����
	//for (vector<string> ::iterator i = v12.begin(); i !=v12.end(); i++)
	//{
	//	cout << *i << "\t";
	//}
	//vector<string> v2;
	//v2.push_back("juli");
	//v2.push_back("Ƶ��");
	//v2.push_back("����");
	//rmg->UpdateRelation("101","202",v2);//�������Թ�ϵΪv2
	//vector<string> v3;
	//v3.push_back("����");
	//rmg->DeleteRelation("101","202",v3);//ɾ����v3���Ե�ֵ
	//vector<string>v4 =	rmg->GetRelatedJsonID("101");//��ȡ��Ŀ���й�ϵ������ID��
	//cout << "��101�йص�ID" << endl;
	//for (vector<string>::iterator i = v4.begin(); i !=v4.end(); i++)
	//{
	//	cout << *i<<endl;
	//}
	//delete(rmg);
	//-------------------------------------test EventRelationManagement
	EventRelationManagement  * erm = new EventRelationManagement();
	erm->AddEventRelation("101","202",1);//����¼�֮��Ĺ�����ϵ
	bool b1 = erm->GetEventRelation("101","202");//�����¼�֮��Ĺ�����ϵ
	erm->UpdateEventRelation("101","202",1);//�����¼�֮��Ĺ�����ϵ
	erm->DeleteEventRelation("101","202");//ɾ���¼�֮��Ĺ�����ϵ
	delete(dbm);
	getchar();
}