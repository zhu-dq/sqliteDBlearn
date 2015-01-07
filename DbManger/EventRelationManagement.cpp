#include "EventRelationManagement.h"

static int count_ERM = 0;
static vector<string> v_ERM;
EventRelationManagement::EventRelationManagement()
{
	if (v_ERM.size()>0)
	{
		ClearERMCache();
	}
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
void  EventRelationManagement::ClearERMCache()
{
	sqlite3_exec(pdb, "BEGIN;", 0, 0, &errMsg);
	for (vector<string>::iterator i = v_ERM.begin(); i != v_ERM.end(); i++)
		sqlite3_exec(pdb, (*i).c_str(), 0, 0, &errMsg);
	sqlite3_exec(pdb, "COMMIT;", 0, 0, &errMsg);
	count_ERM = 0;
	v_ERM.clear();
	cout << "Çå¿ÕÁË»º´æÇø" << endl;
}
bool	EventRelationManagement::AddEventRelation(string strE1, string strE2, bool b)
{
	bool flag = true;
	string s1 = "0";
	if (b)
	{
		s1 = "1";
	}
	string sqlInsert = " insert into eventrelation values(\"" + strE1 + "\",\"" + strE2 + "\","+s1+")";
	if (strE1 > strE2)
	{
		sqlInsert = " insert into eventrelation values(\"" + strE2 + "\",\"" + strE1 + "\"," + s1 + ")";
	}
	if (count_ERM<10000)
	{
		v_ERM.push_back(sqlInsert);
		count_ERM++;
		return flag;
	}
	else
	{
		sqlite3_exec(pdb, "BEGIN;", 0, 0, &errMsg);
		for (vector<string>::iterator i = v_ERM.begin(); i != v_ERM.end(); i++)
			sqlite3_exec(pdb, (*i).c_str(), 0, 0, &errMsg);
		sqlite3_exec(pdb, "COMMIT;", 0, 0, &errMsg);
		count_ERM = 0;
		v_ERM.clear();
	}
	if (errMsg)
	{
		cout << "EventRelationManagement:\t sqlInsert:\t" << errMsg << endl;
		flag = false;
	}
	return flag;
}
bool EventRelationManagement::GetEventRelation(string strE1, string strE2)
{
	if (v_ERM.size()>0)
	{
		ClearERMCache();
	}
	string strbool;
	string sqlSelect = "select RelationEAB  from eventrelation  where (EVENTA  = \'" + strE2 + "\' and EVENTB  = \'" + strE1 + "\') or (EVENTA =\'" + strE1 + "\' and EVENTB =\'" + strE2 + "\')";
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
	if (v_ERM.size()>0)
	{
		ClearERMCache();
	}
	bool flag = true;
	string strbool ="0";
	if (b)
	{
		strbool = "1";
	}
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
	if (v_ERM.size()>0)
	{
		ClearERMCache();
	}
	bool flag = true;
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
	if (v_ERM.size()>0)
	{
		ClearERMCache();
	}
}
