#include <stdlib.h>  
#include <stdio.h>  
#include "mysql.h"  
MYSQL my_connection;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;
int main(int argc, char *argv[])
{
	int res;
	mysql_init(&my_connection);
	if (mysql_real_connect(&my_connection, "localhost", "root", "Andy", "school", 0, NULL, 0))
	{
		printf("Connection success\n");
		res = mysql_query(&my_connection, "SELECT Sno, Sname, Sage FROM student WHERE Sage < 30");
		if (res)
		{
			printf("SELECT error: %s\n", mysql_error(&my_connection));
		}
		else// ok  
		{
			res_ptr = mysql_store_result(&my_connection);
			if (res_ptr)// ok  
			{
				printf("Retrieved %lu rows\n", (unsigned long)mysql_num_rows(res_ptr));// ok  
				unsigned int num_fileds = mysql_num_fields(res_ptr);
				while ((sqlrow = mysql_fetch_row(res_ptr)))
				{
					unsigned long *lengths;
					lengths = mysql_fetch_lengths(res_ptr);
					for (int i = 0; i < num_fileds; i++)
					{
						printf("[%.*s] ", (int)lengths[i], sqlrow[i] ? sqlrow[i] : "NULL");
					}
					printf("\n");

					//printf("student:%s\n",*sqlrow);// ok  
				}
				if (mysql_errno(&my_connection))
				{
					fprintf(stderr, "Retrive error: %s\n", mysql_error(&my_connection));
				}
				mysql_free_result(res_ptr);
			}
		}
		mysql_close(&my_connection);
	}
	else
	{
		fprintf(stderr, "Connection failed\n");
		if (mysql_errno(&my_connection))
		{
			fprintf(stderr, "Connection error %d: %s\n", mysql_errno(&my_connection),
				mysql_error(&my_connection));
		}
	}
	getchar();
	return EXIT_SUCCESS;
}



//#include <WinSock2.h>
//#include <windows.h>
//#include <stdio.h>
//#include <mysql.h>
////#pragma comment(lib,"libmysql.lib")
//int main()
//{
//	MYSQL *conn;
//	char *server = "localhost";
//	char *user = "root";
//	char *password = "Andy";//“******”为你设置的密码
//	char *database = "school";
//	conn = mysql_init(NULL);
//	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
//		printf("连接失败：%sn", mysql_error(conn));
//	else
//		printf("连接成功！");
//	getchar();
//	return 0;
//}


////#include <util.h>
////#include <sqlca.h>
//#include <windows.h>
//#include <string.h>
//#include <conio.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//#include <mysql.h>
////#pragma comment(lib,"libmysql.lib")
//
//EXEC SQL BEGIN DECLARE SECTION; /*主变量说明开始*/
//char deptname[64];
//char HSno[64];
//char HSname[64];
//char HSsex[64];
//int HSage;
//int NEWAGE;
//long SQLCODE;
//EXEC SQL END DECLARE SECTION;     /*主变量说明结束*/
//EXEC SQL INCLUDE sqlca;               /*定义SQL通信区*/
//
///*************************************************************************/
//
//int main(void)                           /*C语言主程序开始*/
//{
//	int count = 0;
//	char yn;                              /*变量yn代表yes或no*/
//	printf("Please choose the department name(CS/MA/IS): ");
//	scanf("%s", deptname);                 /*为主变量deptname赋值*/
//	EXEC SQL CONNECT TO mysql USER root;         /*连接数据库TEST*/
//	EXEC SQL DECLARE SX CURSOR FOR   /*定义游标*/
//		SELECT Sno, Sname, Ssex, Sage   /*SX对应语句的执行结果*/
//		FROM Student
//		WHERE SDept = :deptname;
//	EXEC SQL OPEN SX;        /*打开游标SX便指向查询结果的第一行*/
//
//	for (;;)                       /*用循环结构逐条处理结果集中的记录*/
//	{
//		EXEC SQL FETCH SX INTO : HSno, : HSname, : HSsex, : HSage;
//		/*推进游标，将当前数据放入主变量*/
//		if (sqlca->sqlcode != 0)     /* sqlcode != 0,表示操作不成功*/
//			break;                /*利用SQLCA中的状态信息决定何时退出循环*/
//		if (count++ == 0)             /*如果是第一行的话，先打出行头*/
//			printf("/n%-10s %-20s %-10s %-10s/n", "Sno", "Sname", "Ssex", "Sage");
//		printf("%-10s %-20s %-10s %-10d/n", HSno, HSname, HSsex, HSage);
//		/*打印查询结果*/
//		printf("UPDATE AGE(y/n)?"); /*询问用户是否要更新该学生的年龄*/
//		do{
//			scanf("%c", &yn);
//		} while (yn != 'N' && yn != 'n' && yn != 'Y' && yn != 'y');
//		if (yn == 'y' || yn == 'Y')                 /*如果选择更新操作*/
//		{
//			printf("INPUT NEW AGE:");
//			scanf("%d", &NEWAGE);          /*用户输入新年龄到主变量中*/
//			EXEC SQL UPDATE Student            /*嵌入式SQL*/
//				SET Sage = :NEWAGE
//				WHERE CURRENT OF SX;
//		}                 /*对当前游标指向的学生年龄进行更新*/
//	}
//
//	EXEC SQL CLOSE SX;           /*关闭游标SX不再和查询结果对应*/
//	EXEC SQL COMMIT WORK;                           /*提交更新*/
//	EXEC SQL DISCONNECT TEST;                  /*断开数据库连接*/
//}