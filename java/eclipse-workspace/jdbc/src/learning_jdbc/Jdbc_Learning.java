package learning_jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Jdbc_Learning {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Connection connection = null;
		PreparedStatement preparedstatement = null;
		ResultSet resultset =null;
		
		try {
			// 1�� �������ݿ������
			Class.forName("com.mysql.jdbc.Driver");
			// 2�� ͨ�����������ȡ���ݿ�����
			connection=DriverManager.getConnection("jdbc:mysql://localhost:3306/school","root","Andy");
			// 3�� ����SQL���
			String sql="select * from student";
			// 4�� ��ȡԤ����statement
			preparedstatement=connection.prepareStatement(sql);
			// 5�� ���ò�������һ������Ϊsql����е���ţ���1��ʼ���ڶ�������ΪҪ���õĲ���ֵ
			//preparedstatement.setString(1, "200215121");
			// 6�� �����ݿⷢ�ͳ�sql��ѯ����ѯ�������
			resultset=preparedstatement.executeQuery();
			// 7�� ������ѯ�����
			while(resultset.next())
			{
				System.out.println(resultset.getString("Sno")+" "+resultset.getString("Sname")+" "+resultset.getString("Ssex")+" "+resultset.getString("Sage")+" "+resultset.getString("Sdept"));
			}
			
			
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally
		{
			// 8�� �ͷ���Դ
			if(resultset!=null)
			{
				try {
					resultset.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
		}
		

	}

}
