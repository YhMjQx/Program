#pragma once
#include"worker.h"

using namespace std;


class Boss :public Worker{
public:
	Boss(int id, string name, int deid);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};
