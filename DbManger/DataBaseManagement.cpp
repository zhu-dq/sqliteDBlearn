#include "DataBaseManagement.h"


DataBaseManagement::DataBaseManagement()
{
	OpenDB();
	CreatTable();
}
bool DataBaseManagement::OpenDB()
{
	cout << "数据库打开" << endl;
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
		创建表Node，两个属性：ID(主键)、NODE
	*/
	string sqlCreate1 = "CREATE TABLE Node(ID STRING PRIMARY KEY,NODE  STRING)";
	/*
		创建表NodeRelation,三个属性：IDA、IDB、RelationAB。IDA、IDB和NODE(ID)形成外键关系，(IDA、IDB)做联合主键
	*/
	string sqlCreate2 = "CREATE TABLE NodeRelation(IDA STRING ,IDB STRING,RelationAB STRING,FOREIGN KEY(IDA) REFERENCES Node(ID),FOREIGN KEY(IDB) REFERENCES Node(ID),PRIMARY KEY(IDA,IDB))";
	/*
		创建表EventRelation。三个属性：EVENTA、EVENTB、RelationEAB。(EVENTA、EVENTB)做联合主键。
	*/
	string sqlCreate3 = "CREATE TABLE EventRelation(EVENTA STRING ,EVENTB STRING,RelationEAB INTEGER,PRIMARY KEY(EVENTA,EVENTB) )";
	sqlite3_exec(pdb, sqlCreate1.c_str(), 0, 0, &errMsg);
		sqlite3_exec(pdb, sqlCreate2.c_str(), 0, 0, &errMsg);
		sqlite3_exec(pdb, sqlCreate3.c_str(), 0, 0, &errMsg);
		return true;
}
bool DataBaseManagement::CloseDb()
{
	cout<<"数据库关闭\t"<<sqlite3_close(pdb);
	return true;
}
DataBaseManagement::~DataBaseManagement()
{
}
