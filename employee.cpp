#include"employee.h"

Employee::Employee(int id, string name, int deid){
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deid;
}


//��ʾ������Ϣ
void Employee::showInfo(){
	cout << "ְ����ţ�" << this->m_Id
		<< " \tְ��������" << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ����ɾ�����������" << endl;
}

//��ȡ��λ����
string Employee::getDeptName(){
	return string("Ա��");
}