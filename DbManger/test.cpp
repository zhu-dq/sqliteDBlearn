#if defined(_WIN32)
#include <WinSock2.h>
#include  <Windows.h>
#endif
//#include <iostream>
//#include<list>
#include <string>
#include <vector>
//#include "sqlite3.h"
#include "json\json.h"
#include "DataBaseManagement.h"
#include "EventRelationManagement.h"
#include "ObjManagement.h"
#include "RelationManagement.h"
#include <fstream>
#include  <sstream>
#include <time.h>
using namespace std;

//��ȡ��ʽ: ��ʶ�ȡ, ��֮���ÿո�����
void ReadDataFromFileWBW()
{
	ifstream fin("relation.txt");
	string s;
	while (fin >> s)
	{
		cout << "Read from file: " << s << endl;
	}
}

//��ȡ��ʽ: ���ж�ȡ, ���ж����ַ���, ��֮���ûس���������
void ReadDataFromFileLBLIntoString()
{
	ifstream fin("data.txt");
	string s;
	int count = 0;
	while (getline(fin, s))
	{
		cout <<"�к�  ��  "<<count++<< "\t: " << s << endl;
	}
}
//
vector<string> subv1(vector<string> v1, vector<string> v2)
{
	for (vector<string>::iterator i = v2.begin(); i != v2.end(); i++)
	{
		for (vector<string>::iterator j = v1.begin(); j != v1.end(); j++)
		{
			if (string(*j) == string(*i))
			{
				v1.erase(j);
				j = v1.begin(); //��erase�󣬾ɵ������ᱻ���������һ���µ�����
			}

		}
	}
	return v1;
}
//�Զ���ֽ��ַ���
vector<string> GetWordFromLine1(string	str, string * ID1, string * ID2)
{
	string pattern = "  ";
	string word;
	std::string::size_type pos;
	vector<string> v1;
	vector<string> v2;
	str += pattern;//��չ�ַ����Է������
	for (int i = 0; i<str.size(); i++)
	{
		pos = str.find(pattern, i);
		if (pos<str.size())
		{
			word = str.substr(i, pos - i);
			v1.push_back(word);
			i = pos + pattern.size() - 1;
		}
	}
	*ID1 = v1[0];
	*ID2 = v1[1];
	v2.push_back(*ID1);
	v2.push_back(*ID2);
	return subv1(v1,v2);
}
//�Զ���ֽ��ַ���
inline vector<string> GetWordFromLine(string	&str, string * ID1, string * ID2)
{
	istringstream stream(str);
	string word;
	int count = 0;
	vector<string> v1;
	while (stream>>word)
	{
		if (count == 0)
		{
			*ID1 = word;
		}
		else if (count == 1)
		{
			*ID2 = word;
		}
		else
		{
			v1.push_back(word);
		}
		count++;
	}
	return v1;
}
//�Զ���  ���vector<string>
void PrintVectorStr(vector<string> v1)
{
	for (vector<string>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		cout << *i << "\t";
	}
}
//�Զ���
void ReadDataLineAndWord()
{
	ifstream fin("relation.txt");
	string s;
	string ID1;
	string ID2;
	vector<string> v1;
	int count = 0;
	while (getline(fin,s)&&(count<15))
	{
		v1 = GetWordFromLine(s, &ID1, &ID2);
		cout << "\n �к�  :  " << count++ << "\t :" << s << endl;
		cout << "�ַ����ֽ��Ľ����" << endl;
		cout << "ID1 : "  << ID1<<"\t ID2 : " <<ID2<< "\n v1 : ";
		PrintVectorStr(v1);

	}
}
int main()
{
	DataBaseManagement * dbm = new DataBaseManagement();
	RelationManagement * rmg = new RelationManagement();
	string	ID1;
	string	ID2;
	string   str;
	vector<string>  feature;
	time_t start, end;
	double cost;
	time(&start);
	ifstream fin("relation.txt");
	while (getline(fin,str))
	{
		feature = GetWordFromLine(str, &ID1, &ID2);
		//cout << ID1 << "\t"<<ID2 << endl;
		rmg->SetRelation(ID1, ID2, feature);
	}
	time(&end);

	cost = difftime(end,start);
	cout << "��ʱ��"<<cost;
	delete rmg;
	delete dbm;
	getchar();
	/*ReadDataLineAndWord();
	getchar();*/
	//ReadDataFromFileLBLIntoString(); //��ʶ����ַ���
	//-----------------------------------------------------------------------------------------------------
	//ifstream fin("data.txt");
	//string str_json;
	//ObjManagement  *omg = new ObjManagement();
	//while (getline(fin,str_json))
	//{
	//	omg->AddJson(str_json);
	//}
	//string	strjson2 = omg->GetJson("6855052");              //��ȡ
	//cout << "strjson2" << endl;
	//cout << strjson2 << endl;
	//delete(omg);
	//getchar();
	//return 0;
//---------------------------------------------------------------------------------------------------------------------
	//fstream outFile;
	//outFile.open("inFile.txt", ios::in);
	//ifstream f;
	//f.open("E:\\data.txt");
	//if (!f)
	//	cout << "error";
	////����Json�ķ���
	//Json::Reader reader;
	//Json::Value json_object;
	//reader.parse(f, json_object, false);
	//f.close();
	//DataBaseManagement *dbm = new DataBaseManagement();

	////---------------------------------------------------------test     ObjManagement-----------------------------------------------------------------------------
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

	////------------------------------------------------------test         RelationManagement
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
	////-------------------------------------test EventRelationManagement
	//EventRelationManagement  * erm = new EventRelationManagement();
	//erm->AddEventRelation("101","202",1);//����¼�֮��Ĺ�����ϵ
	//bool b1 = erm->GetEventRelation("101","202");//�����¼�֮��Ĺ�����ϵ
	//erm->UpdateEventRelation("101","202",1);//�����¼�֮��Ĺ�����ϵ
	//erm->DeleteEventRelation("101","202");//ɾ���¼�֮��Ĺ�����ϵ
	//delete(erm);
	//delete(dbm);
	//getchar();
}