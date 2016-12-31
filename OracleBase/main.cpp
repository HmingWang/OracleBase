#include <iostream>
#include <string>
#include <occi.h>

#define SQL(TXT)  #TXT

using namespace oracle::occi;
using std::string;
using std::cout;
using std::cin;

int main() 
{
	try
	{
		const string userName = "CPAP2";
		const string password = "CPAP2";
		const string connectString = "168.33.131.19/sjjdb";
		Environment *env = Environment::createEnvironment();
		{
			
			Connection *conn = env->createConnection(
				userName, password, connectString);
			Statement *stmt = conn->createStatement(
				SQL(SELECT *  FROM func));
			ResultSet *rs = stmt->executeQuery();
			rs->next();
			string b = rs->getString(1);
			cout <<  b;
			
			stmt->closeResultSet(rs);
			conn->terminateStatement(stmt);
			env->terminateConnection(conn);
		}
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& e)
	{
		std::cout << e.getErrorCode()<<"|"<<e.getMessage() << std::endl;
	}
	
	system("pause");
	return 0;
}