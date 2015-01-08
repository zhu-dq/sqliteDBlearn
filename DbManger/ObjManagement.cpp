#include "ObjManagement.h"

static int count_OMG = 0;
static vector<string> v_OMG;
ObjManagement::ObjManagement() 
{
	if (v_OMG.size()>0)
	{
		ClearOMGCache();
	}
}
int ObjManagement::callbackselect(void *para, int n_column, char **column_value, char **column_name)
{
	string *strjson = (string *)para;
	*strjson = string(column_value[0]);
	return 0;
}
int ObjManagement::callbackNodeCount(void *para, int n_column, char **column_value, char **column_name)
{  
	string *strjson = (string *)para;
	*strjson = string(column_value[0]);
	return 0;
}
void ObjManagement::ClearOMGCache()
{
	sqlite3_exec(pdb, "BEGIN;", 0, 0, &errMsg);
	for (vector<string>::iterator i = v_OMG.begin(); i != v_OMG.end(); i++)
		sqlite3_exec(pdb, (*i).c_str(), 0, 0, &errMsg);
	sqlite3_exec(pdb, "COMMIT;", 0, 0, &errMsg);
	count_OMG = 0;
	v_OMG.clear();
}
bool ObjManagement::AddJson(string JsonStr)
{
	Json::Reader reader;
	Json::Value json_object;
	reader.parse(JsonStr, json_object, false);
	string jsonID = json_object["ID"].toStyledString();
	string sqlInsert = "insert into  node values(" + jsonID + ",\'" + JsonStr + "\');";
	if (count_OMG<10000)
	{
		v_OMG.push_back(sqlInsert);
		count_OMG++;
		return true;
	}
	else
	{
		sqlite3_exec(pdb, "BEGIN;", 0, 0, &errMsg);
		for (vector<string>::iterator i = v_OMG.begin(); i != v_OMG.end(); i++)
			sqlite3_exec(pdb, (*i).c_str(), 0, 0, &errMsg);
		sqlite3_exec(pdb, "COMMIT;", 0, 0, &errMsg);
		count_OMG = 0;
		v_OMG.clear();
	}
	if (errMsg)
	{
		cout << "ObjManagement: \t sqlInsert:\t" << errMsg << endl;
		return false;
	}
	return true;
}
string ObjManagement::GetJson(string strID)
{
	if (v_OMG.size()>0)
	{
		ClearOMGCache();
	}
	string strjson;
	string sqlSelect = "select NODE from node where ID=\'" + strID + "\'";
	sqlite3_exec(pdb, sqlSelect.c_str(), callbackselect, &strjson, &errMsg);
	if (errMsg)
	{
		cout << "ObjManagement: \t sqlSelect:\t" << errMsg << endl;
	}
	return	strjson;
}
long ObjManagement::GetNodeCount()
{
	if (v_OMG.size()>0)
	{
		ClearOMGCache();
	}
	long count;
	string strjson;
	string sqlGetCount = "select count(*) from  node";
	sqlite3_exec(pdb, sqlGetCount.c_str(), callbackselect, &strjson, &errMsg);
	count = atoi(strjson.c_str());
	return count;
}
bool ObjManagement::insertAttributeToNode(string ID, string key, string value)
{
	if (v_OMG.size()>0)
	{
		ClearOMGCache();
	}
	bool flag = true;
		string jsonstr = ObjManagement::GetJson(ID);
		if (jsonstr==" ")
		{
			flag = false;
		}
		Json::Reader reader;
		Json::Value json_object;
		Json::Value json_object1;
		Json::Value json_object2;
		Json::Value attribute;//Ҫ���µ�����
		attribute["ATTRIBUTE"] = key;
		attribute["VALUE"] = value;
		reader.parse(jsonstr, json_object, false);
		json_object1 = json_object["AVP_LIST"];
		json_object2 = json_object["ID"];
		 json_object1.append(attribute);//��"AVP_LIST"�����Ҫ���µ�����
		 json_object.removeMember("AVP_LIST");//ɾ��ԭ���ġ�AVP_LIST��
		 json_object["AVP_LIST"].append(json_object1);//����µġ�AVP_LIST��
		 ObjManagement::UpdateJson(json_object2.toStyledString(), json_object.toStyledString());
		 return flag;
}
bool ObjManagement::UpdateJson(string strID, string jsonmsg)
{
	if (v_OMG.size()>0)
	{
		ClearOMGCache();
	}
	bool flag = true;
	string sqlupdate = "update node set NODE = \'"+jsonmsg+"\' where ID = "+strID+"";
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
	if (v_OMG.size()>0)
	{
		ClearOMGCache();
	}
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
	if (v_OMG.size()>0)
	{
		ClearOMGCache();
	}
}
