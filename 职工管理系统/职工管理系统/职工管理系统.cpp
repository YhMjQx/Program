#include<iostream>
#include"workerManager.h"
//#include"worker.h"
//#include"employee.h"
//#include"Boss.h"
//#include"Manager.h"
using namespace std;

//void test1(){
//	Worker* worker = NULL;
//	worker = new Employee(1, "����", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2,"����",2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3,"����",3);
//	worker->showInfo();
//	delete worker;
//}



int main(){
	//���Դ���
	//test1();


	//ʵ���������߶���
	workerManager wm;

	int choice = 0;//�����洢�û���ѡ��

	while (true){
			//����չʾ�˵�����
		wm.show_menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice){
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://���ְ��
			wm.Add_Emp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����ְ��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");//����
			break;
		}
	}

	return 0;
}