#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"
#include<fstream>

#define FILENAME "empFile.txt"

using namespace std;


class workerManager{
public:
	//构造函数
	workerManager();

	//显示菜单
	void show_menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void Save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中的人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在，如果存在返回职工所在数组中的位置,不存在返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//按职工编号排序
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~workerManager();


};

//用户在批量创建的时候，会有不同种类的员工产生，那么想要将这些不同种类的员工都放在一个不定长数组当中存储，需要将该数组开辟到堆区
//会发现不同种类的员工，其对应的类型也是不同的，那么为了实现上面的条件，就需要用一个整体都适合的指针来维护
//那就是worker类型，所有员工都继承自worker，所以我可以在数组中全部存储的是worker*指针，然后这些指针分别指向的是
//对应的员工类型，然后用worker**指针来维护这个数组，其实是利用了多态，统一了这些指针，统一用父类指针来操作

//虽然我们实现了添加职工后，将数据保存到文件中的操作，但是每次开始运行程序的时候，并没有将文件中的数据加载到程序当中
//而我们程序的功能还有清空文件的需求，因此构造函数初始化数据的情况下分为三种
//1.第一次使用，文件未创建
//2.文件存在，但是数据被用户情况
//3.文件存在，并且保存职工的所有数据