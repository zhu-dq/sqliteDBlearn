#include "EventRelationManagement.h"


EventRelationManagement::EventRelationManagement()
{
}
int EventRelationManagement::callbackGetERelationCount(void *para, int n_column, char **column_value, char **column_name)
{

	int *count1 = (int *)para;
	count1[0] = atoi(column_value[0]);
	return 0;
}
int EventRelationManagement::callbackGetERelation(void *para, int n_column, char **column_value, char **column_name)
{
	string *strbool = (string *)para;
	*strbool = column_value[0];
	return 0;
}
bool	EventRelationManagement::AddEventRelation(string strE1, string strE2, bool b)
{
	//--------------------------------------------获取EA和EB之间数据个数---------------------------------------------------
	int count = 0;
	string sqlGetCount = "  select count(*) from noderelation where (IDA = \"" + strE2 + "\" and IDB =\" " + strE1 + "\") or (IDA = \"" + strE1 + "\" and IDB =\" " + strE2 + "\")";
	sqlite3_exec(pdb, sqlGetCount.c_str(), callbackGetERelationCount, &count, &errMsg);
	//--------------------------------------------------------------------------------------------------------------------------
	if (count != 0)
	{
		cout << "已经存在EA和EB之间的关系，你是否是想执行更新操作" << endl;
		return  false;
	}
	bool flag = true;
	string s1 = "0";
	if (b)
	{
		s1 = "1";
	}
	string sqlInsert = " insert into eventrelation values(\"" + strE1 + "\",\"" + strE2 + "\","+s1+")";
	sqlite3_exec(pdb, sqlInsert.c_str(), 0, 0, &errMsg);
	if (errMsg)
	{
		cout << "EventRelationManagement:\t sqlInsert:\t" << errMsg << endl;
		flag = false;
	}
	return flag;
}
bool EventRelationManagement::GetEventRelation(string strE1, string strE2)
{
	string strbool;
	//select RelationEAB from eventrelation where EVENTA = "leida1" and EVENTB = "leida2"
	string sqlSelect = "select RelationEAB  from eventrelation  where (EVENTA  = \"" + strE2 + "\" and EVENTB  = \"" + strE1 + "\") or (EVENTA =\" " + strE1 + "\" and EVENTB =\" " + strE2 + "\")";
	sqlite3_exec(pdb, sqlSelect.c_str(), callbackGetERelation, &strbool, &errMsg);
	if (errMsg)
	{
		cout << "RelationManagement:  \t  sqlSelect: \t" << errMsg << endl;
	}
	if (string(strbool)==string("1"))
	{
		return true;
	}
	return false;
}
bool EventRelationManagement::UpdateEventRelation(string strE1, string strE2, bool b)
{

	bool flag = true;
	string strbool ="0";
	if (b)
	{
		strbool = "1";
	}
	//update eventrelation set RelationEAB = 0  where (EVENTA = "leida4" and EVENTB = "leida3") or (EVENTA = "leida1" and EVENTB = "leida3")
	string sqlupdate = "update eventrelation set RelationEAB = "+strbool+"  where (EVENTA = \""+strE1+"\" and EVENTB = \""+strE2+"\") or (EVENTA = \""+strE2+"\" and EVENTB = \""+strE1+"\")";
	sqlite3_exec(pdb, sqlupdate.c_str(), 0, 0, &errMsg);
	if (errMsg)
	{
		cout << "EventRelationManagement: \t sqlupdate:\t" << errMsg << endl;
		flag = false;
	}
	return flag;
}
bool EventRelationManagement::DeleteEventRelation(string strE1, string strE2)
{
	bool flag = true;
	//delete  from eventrelation where (EVENTA = "leida4" and EVENTB = "leida3") or (EVENTA = "leida1" and EVENTB = "leida3")
	string sqldelete = "delete  from eventrelation where (EVENTA = \""+strE1+"\" and EVENTB = \""+strE2+"\") or (EVENTA = \""+strE2+"\" and EVENTB = \""+strE1+"\")";
	sqlite3_exec(pdb, sqldelete.c_str(), 0, 0, &errMsg);
	if (errMsg)
	{
		cout << "EventRelationManagement: \t sqldelete:\t" << errMsg << endl;
	}
	return flag;
}
EventRelationManagement::~EventRelationManagement()
{
}
