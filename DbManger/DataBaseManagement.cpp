#include "DataBaseManagement.h"


DataBaseManagement::DataBaseManagement()
{
	OpenDB();
	CreatTable();
}
bool DataBaseManagement::OpenDB()
{
	cout << "���ݿ��" << endl;
	int r = sqlite3_open("29.db", &pdb);
	if (r)
	{
		cout << "open error" << endl;
		return false;
	}
	return true;
}
bool DataBaseManagement::CreatTable()
{
	/*
		������Node���������ԣ�ID(����)��NODE
	*/
	string sqlCreate1 = "CREATE TABLE Node(ID STRING PRIMARY KEY,NODE  STRING)";
	/*
		������NodeRelation,�������ԣ�IDA��IDB��RelationAB��IDA��IDB��NODE(ID)�γ������ϵ��(IDA��IDB)����������
	*/
	string sqlCreate2 = "CREATE TABLE NodeRelation(IDA STRING ,IDB STRING,RelationAB STRING,FOREIGN KEY(IDA) REFERENCES Node(ID),FOREIGN KEY(IDB) REFERENCES Node(ID),PRIMARY KEY(IDA,IDB))";
	/*
		������EventRelation���������ԣ�EVENTA��EVENTB��RelationEAB��(EVENTA��EVENTB)������������
	*/
	string sqlCreate3 = "CREATE TABLE EventRelation(EVENTA STRING ,EVENTB STRING,RelationEAB INTEGER,PRIMARY KEY(EVENTA,EVENTB) )";
	sqlite3_exec(pdb, sqlCreate1.c_str(), 0, 0, &errMsg);
		sqlite3_exec(pdb, sqlCreate2.c_str(), 0, 0, &errMsg);
		sqlite3_exec(pdb, sqlCreate3.c_str(), 0, 0, &errMsg);
		return true;
}
bool DataBaseManagement::CloseDb()
{
	cout<<"���ݿ�ر�\t"<<sqlite3_close(pdb);
	return true;
}
DataBaseManagement::~DataBaseManagement()
{
}
