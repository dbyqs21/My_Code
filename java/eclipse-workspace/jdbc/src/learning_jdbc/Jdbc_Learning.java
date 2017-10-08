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
			// 1、 加载数据库的驱动
			Class.forName("com.mysql.jdbc.Driver");
			// 2、 通过驱动管理获取数据库链接
			connection=DriverManager.getConnection("jdbc:mysql://localhost:3306/school","root","Andy");
			// 3、 定义SQL语句
			String sql="select * from student";
			// 4、 获取预处理statement
			preparedstatement=connection.prepareStatement(sql);
			// 5、 设置参数，第一个参数为sql语句中的序号（从1开始）第二个参数为要设置的参数值
			//preparedstatement.setString(1, "200215121");
			// 6、 向数据库发送出sql查询，查询出结果集
			resultset=preparedstatement.executeQuery();
			// 7、 遍历查询结果集
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
			// 8、 释放资源
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
