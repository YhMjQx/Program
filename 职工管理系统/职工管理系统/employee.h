#pragma once
#include"worker.h"

//普通员工文件

class Employee :public Worker{
public:
	Employee(int id, string name, int deid);

	//显示个人信息
	virtual void showInfo() ;

	//获取岗位名称
	virtual string getDeptName() ;
};