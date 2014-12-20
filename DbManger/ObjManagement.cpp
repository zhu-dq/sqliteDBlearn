#include "ObjManagement.h"

ObjManagement::ObjManagement() 
{
}
int ObjManagement::callbackselect(void *para, int n_column, char **column_value, char **column_name)
{
	string *strjson = (string *)para;
	*strjson = string(column_value[0]);
	return 0;
}
bool ObjManagement::AddJson(string JsonStr)
{
	Json::Reader reader;
	Json::Value json_object;
	reader.parse(JsonStr, json_object, false);
	string jsonID = json_object["ID"].toStyledString();
	string sqlInsert = "insert into  node values(" + jsonID + ",\'" + JsonStr + "\');";
	sqlite3_exec(pdb, sqlInsert.c_str(), 0, 0, &errMsg);
	if (errMsg)
	{
		cout << "ObjManagement: \t sqlInsert:\t" << errMsg << endl;
		return false;
	}
	return true;
}
string ObjManagement::GetJson(string strID)
{
	string strjson;
	string sqlSelect = "select NODE from node where ID=\'" + strID + "\'";
	sqlite3_exec(pdb, sqlSelect.c_str(), callbackselect, &strjson, &errMsg);
	if (errMsg)
	{
		cout << "ObjManagement: \t sqlSelect:\t" << errMsg << endl;
	}
	return	strjson;
}
bool ObjManagement::UpdateJson(string strID, string jsonmsg)
{
	bool flag = true;
	string sqlupdate = "update node set NODE = \'"+jsonmsg+"\' where ID = \'"+strID+"\'";
	sqlite3_exec(pdb, sqlupdate.c_str(), 0, 0, &errMsg);
	if (errMsg)
	{
		cout << "ObjManagement: \t sqlupdate:\t" << errMsg << endl;
		flag = false;
	}
	return flag;
}
bool ObjManagement::DeleteJson(string strID)
{
	bool flag = true;
	string sqldelete = "delete from node where ID = \'"+strID+"\'";
	sqlite3_exec(pdb, sqldelete.c_str(), 0, 0, &errMsg);
	if (errMsg)
	{
		cout << "ObjManagement: \t sqldelete:\t" << errMsg << endl;
		flag = false;
	}
	return flag;
}
ObjManagement::~ObjManagement()
{
}
