#include<iostream>
#include"workerManager.h"
//#include"worker.h"
//#include"employee.h"
//#include"Boss.h"
//#include"Manager.h"
using namespace std;

//void test1(){
//	Worker* worker = NULL;
//	worker = new Employee(1, "张三", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2,"李四",2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3,"王五",3);
//	worker->showInfo();
//	delete worker;
//}



int main(){
	//测试代码
	//test1();


	//实例化管理者对象
	workerManager wm;

	int choice = 0;//用来存储用户的选项

	while (true){
			//调用展示菜单函数
		wm.show_menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice){
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://添加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}

	return 0;
}