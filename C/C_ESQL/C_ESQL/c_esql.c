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
//	char *password = "Andy";//��******��Ϊ�����õ�����
//	char *database = "school";
//	conn = mysql_init(NULL);
//	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
//		printf("����ʧ�ܣ�%sn", mysql_error(conn));
//	else
//		printf("���ӳɹ���");
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
//EXEC SQL BEGIN DECLARE SECTION; /*������˵����ʼ*/
//char deptname[64];
//char HSno[64];
//char HSname[64];
//char HSsex[64];
//int HSage;
//int NEWAGE;
//long SQLCODE;
//EXEC SQL END DECLARE SECTION;     /*������˵������*/
//EXEC SQL INCLUDE sqlca;               /*����SQLͨ����*/
//
///*************************************************************************/
//
//int main(void)                           /*C����������ʼ*/
//{
//	int count = 0;
//	char yn;                              /*����yn����yes��no*/
//	printf("Please choose the department name(CS/MA/IS): ");
//	scanf("%s", deptname);                 /*Ϊ������deptname��ֵ*/
//	EXEC SQL CONNECT TO mysql USER root;         /*�������ݿ�TEST*/
//	EXEC SQL DECLARE SX CURSOR FOR   /*�����α�*/
//		SELECT Sno, Sname, Ssex, Sage   /*SX��Ӧ����ִ�н��*/
//		FROM Student
//		WHERE SDept = :deptname;
//	EXEC SQL OPEN SX;        /*���α�SX��ָ���ѯ����ĵ�һ��*/
//
//	for (;;)                       /*��ѭ���ṹ�������������еļ�¼*/
//	{
//		EXEC SQL FETCH SX INTO : HSno, : HSname, : HSsex, : HSage;
//		/*�ƽ��α꣬����ǰ���ݷ���������*/
//		if (sqlca->sqlcode != 0)     /* sqlcode != 0,��ʾ�������ɹ�*/
//			break;                /*����SQLCA�е�״̬��Ϣ������ʱ�˳�ѭ��*/
//		if (count++ == 0)             /*����ǵ�һ�еĻ����ȴ����ͷ*/
//			printf("/n%-10s %-20s %-10s %-10s/n", "Sno", "Sname", "Ssex", "Sage");
//		printf("%-10s %-20s %-10s %-10d/n", HSno, HSname, HSsex, HSage);
//		/*��ӡ��ѯ���*/
//		printf("UPDATE AGE(y/n)?"); /*ѯ���û��Ƿ�Ҫ���¸�ѧ��������*/
//		do{
//			scanf("%c", &yn);
//		} while (yn != 'N' && yn != 'n' && yn != 'Y' && yn != 'y');
//		if (yn == 'y' || yn == 'Y')                 /*���ѡ����²���*/
//		{
//			printf("INPUT NEW AGE:");
//			scanf("%d", &NEWAGE);          /*�û����������䵽��������*/
//			EXEC SQL UPDATE Student            /*Ƕ��ʽSQL*/
//				SET Sage = :NEWAGE
//				WHERE CURRENT OF SX;
//		}                 /*�Ե�ǰ�α�ָ���ѧ��������и���*/
//	}
//
//	EXEC SQL CLOSE SX;           /*�ر��α�SX���ٺͲ�ѯ�����Ӧ*/
//	EXEC SQL COMMIT WORK;                           /*�ύ����*/
//	EXEC SQL DISCONNECT TEST;                  /*�Ͽ����ݿ�����*/
//}