package com.AndyYUE.mybatis;

import java.util.List;

import com.AndyYUE.mybatis.PO.User;

public class UserQueryVO {
	// 用户信息
	private User user;
	
	// 商品ID集合
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
	
	// 商品信息 （定义相应的PO类后再在此定义）
	
	// 订单信息 （定义相应的PO类后再在此定义）

}
