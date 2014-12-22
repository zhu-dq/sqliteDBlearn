#include "RelationManagement.h"


RelationManagement::RelationManagement()
{
}
int RelationManagement::callbackGetRelatedJsonID(void *para, int n_column, char **column_value, char **column_name)
{
	vector<string> *strRelate = (vector<string> *)para;
	string StrID = (*strRelate)[1];
	if (string(StrID) == string(column_value[0]))
	{
		(*strRelate)[0] = (*strRelate)[0] + column_value[1];
		(*strRelate)[0] = (*strRelate)[0] + ",";
	}
	else
	{
		(*strRelate)[0] = (*strRelate)[0] + column_value[0];
		(*strRelate)[0] = (*strRelate)[0] + ",";
	}
	return 0;
}
int RelationManagement::callbackGetRelationCount(void *para, int n_column, char **column_value, char **column_name)
{
	int *count1 = (int *)para;
	*count1= atoi(column_value[0]);
	return 0; 
}
int RelationManagement::callbackGetRelation(void *para, int n_column, char **column_value, char **column_name)
{
	string *strRelation = (string *)para;
	*strRelation = column_value[0];
	return 0;
}
//strҪ�ָ���ַ�����patternָ�ָ��ַ����磨����������*����
vector<string> RelationManagement::split_str(string str, string pattern)
{

	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;//��չ�ַ����Է������
	int size = str.size();

	for (int i = 0; i<size; i++)
	{
		pos = str.find(pattern, i);
		if (pos<size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}
//vector���,V1-V2  ,ע�� V1����V2��˳���ܷ���
vector<string> RelationManagement::subvector(vector<string> v1, vector<string> v2)
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
bool RelationManagement::SetRelation(string strID1, string strID2, vector<string> strc)
{	//--------------------------------------------��ȡA��B֮�����ݸ���------------------------------------------------------
	int count = 0;
	string sqlGetCount = "  select count(*) from noderelation where (IDA = \'" + strID2 + "\' and IDB =\'" + strID1 + "\') or (IDA = \'" + strID1 + "\' and IDB =\'" + strID2 + "\')";
	sqlite3_exec(pdb, sqlGetCount.c_str(), callbackGetRelationCount, &count, &errMsg);
	//--------------------------------------------------------------------------------------------------------------------------
	if (count!=0)
	{
		cout << "�Ѿ�����"+strID1+"��"+strID2+"֮��Ĺ�ϵ�����Ƿ�����ִ�и��²���" << endl;
		return  false;		
	}
	string str10;//strcת��string֮���ֵ
	bool	flag = true;
	//��strc���һ���ַ���str10
	for (unsigned i = 0; i<strc.size(); i++)
	{
		str10 = str10 + strc[i] + ",";
	}
	str10 = str10.substr(0, str10.length() - 2);//ȥ�����һ������
	string sqlInsert = "insert into noderelation values(\""+strID1+"\",\""+strID2+"\",\""+str10+"\")";
	sqlite3_exec(pdb, sqlInsert.c_str(), 0, 0, &errMsg);
	if (errMsg)
	{
		cout << "RelationManagement: \t sqlInsert:\t" << errMsg << endl;
		flag= false;
	}
	return flag;

}
vector<string> RelationManagement::GetRelation(string strID1, string strID2)
{
	vector<string> text;
	string strRelation;
	string sqlSelect;
	sqlSelect = "select RelationAB from noderelation where (IDA = \'" + strID2 + "\' and IDB = \'" + strID1 + "\') or (IDA =\'" + strID1 + "\' and IDB =\'" + strID2 + "\')";
	sqlite3_exec(pdb, sqlSelect.c_str(), callbackGetRelation, &strRelation, &errMsg);
	if (errMsg)
	{
		cout << "RelationManagement:  \t  sqlSelect: \t" << errMsg << endl;
	}
	cout << strRelation << endl;
	text = split_str(strRelation,",");
	return text;
}
//--------���������µ�vector<string> strc �滻ԭ���� vector<string> strc  ��
bool RelationManagement::UpdateRelation(string strID1, string strID2, vector<string> strc)
{
	string str10;//strcת��string֮���ֵ
	bool	flag = true;
	//��strc���һ���ַ���str10
	for (unsigned i = 0; i<strc.size(); i++)
	{
		str10 = str10 + strc[i] + ",";
	}
	str10 = str10.substr(0, str10.length() - 1);//
	string sqlupdate = "update noderelation set RelationAB = \'" + str10 + "\' where (IDA =\'" + strID2 + "\' and  IDB = \'" + strID1 + "\') or (IDA = \'" + strID1 + "\' and IDB =\'" + strID2 + "\')";
	sqlite3_exec(pdb, sqlupdate.c_str(), 0, 0, &errMsg);
	if (errMsg)
	{
		cout << "RelationManagement: \t sqlupdate:\t" << errMsg << endl;
		flag = false;
	}

	return flag;
}
bool	RelationManagement::DeleteRelation(string strID1, string strID2, vector<string> strc)
{
	vector<string> v1 = RelationManagement::GetRelation(strID1, strID2);
	vector<string> substrc = RelationManagement:: subvector(v1, strc);
	RelationManagement::UpdateRelation(strID1, strID2, substrc);
	return true;
}
vector<string> RelationManagement::GetRelatedJsonID(string StrID)
{
	vector<string> text;
	vector<string> strRelate;
	string strRelation;
	strRelate.push_back(strRelation);
	strRelate.push_back(StrID);
	string sqlGetRelatedJsonID = "select IDA,IDB from noderelation where IDA = \"" + StrID + "\" or IDB = \"" + StrID + "\"";
	sqlite3_exec(pdb, sqlGetRelatedJsonID.c_str(), callbackGetRelatedJsonID, &strRelate, &errMsg);
	if (errMsg)
	{
		cout << "RelationManagement:  \t  sqlGetRelatedJsonID: \t" << errMsg << endl;
	}
	strRelation = strRelate[0];
	strRelation = strRelation.substr(0, strRelation.length() - 1);
	text = split_str(strRelation, ",");
	return text;
}
RelationManagement::~RelationManagement()
{
}
