package com.AndyYUE.mybatis;

import java.util.List;

import com.AndyYUE.mybatis.PO.User;

public class UserQueryVO {
	// �û���Ϣ
	private User user;
	
	// ��ƷID����
	private List<String> idList;
	
	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}

	public List<String> getIdList() {
		return idList;
	}

	public void setIdList(List<String> idList) {
		this.idList = idList;
	}

	public UserQueryVO(User user) {
		this.user = user;
	}
	
	// ��Ʒ��Ϣ ��������Ӧ��PO������ڴ˶��壩
	
	// ������Ϣ ��������Ӧ��PO������ڴ˶��壩

}
