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
	//-------------������Node �� NodeRelation    ��EventRelation
	string sqlCreate1 = "CREATE TABLE Node(ID STRING PRIMARY KEY,NODE  STRING)";
	string sqlCreate2 = "CREATE TABLE NodeRelation(IDA STRING ,IDB STRING,RelationAB STRING,FOREIGN KEY(IDA) REFERENCES Node(ID),FOREIGN KEY(IDB) REFERENCES Node(ID))";
	string sqlCreate3 = "CREATE TABLE EventRelation(EVENTA STRING ,EVENTB STRING,RelationEAB INTEGER )";
	sqlite3_exec(pdb, sqlCreate1.c_str(), 0, 0, &errMsg);
		if (errMsg)
		{
			cout << "sqlCreate1" << errMsg << endl;
			return false;
		}
		sqlite3_exec(pdb, sqlCreate2.c_str(), 0, 0, &errMsg);
		if (errMsg)
		{
			cout <<"sqlCreate2" <<errMsg << endl;
			return false;
		}
		sqlite3_exec(pdb, sqlCreate3.c_str(), 0, 0, &errMsg);
		if (errMsg)
		{
			cout << "sqlCreate3" << errMsg << endl;
			return false;
		}
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
