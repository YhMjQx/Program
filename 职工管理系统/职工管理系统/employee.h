#pragma once
#include"worker.h"

//��ͨԱ���ļ�

class Employee :public Worker{
public:
	Employee(int id, string name, int deid);

	//��ʾ������Ϣ
	virtual void showInfo() ;

	//��ȡ��λ����
	virtual string getDeptName() ;
};