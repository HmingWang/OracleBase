#include <iostream>
#include <string>
#include <occi.h>

using namespace oracle::occi;
using std::string;
using std::cout;
using std::cin;

int main() 
{
	try
	{
		const string userName = "lfcp";
		const string password = "lfcp";
		const string connectString = "168.33.130.16/szfsdb";
		Environment *env = Environment::createEnvironment();
		{
			Connection *conn = env->createConnection(
				userName, password, connectString);
			Statement *stmt = conn->createStatement(
				"SELECT blobcol FROM mytable");
			ResultSet *rs = stmt->executeQuery();
			rs->next();
			Blob b = rs->getBlob(1);
			cout << "Length of BLOB : " << b.length();
			
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