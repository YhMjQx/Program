#pragma once
#include"worker.h"
using namespace std;

class Manager :public Worker{
public:
	Manager(int id,string name,int deid);

	//��ʾ������Ϣ
	virtual void showInfo() ;

	//��ȡ��λ����
	virtual string getDeptName() ;
};