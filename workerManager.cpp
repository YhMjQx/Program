#include"workerManager.h"

workerManager::workerManager(){
	//初始化属性
	this->m_EmpNum = 0;

	this->m_EmpArray = NULL;
}

workerManager::~workerManager(){

}

//显示菜单
void workerManager::show_menu(){
	cout << "***********************************************************" << endl;
	cout << "**************    欢迎使用职工管理系统！   ****************" << endl;
	cout << "********************  0.退出管理程序  *********************" << endl;
	cout << "********************  1.增加职工信息  *********************" << endl;
	cout << "********************  2.显示职工信息  *********************" << endl;
	cout << "********************  3.删除离职职工  *********************" << endl;
	cout << "********************  4.修改职工信息  *********************" << endl;
	cout << "********************  5.查找职工信息  *********************" << endl;
	cout << "********************  6.按照编号排序  *********************" << endl;
	cout << "********************  7.清空所有文档  *********************" << endl;
	cout << "***********************************************************" << endl;
	cout << endl;
}

//退出系统
void workerManager::ExitSystem(){
	cout << "欢迎下次使用" << endl;
	//system("pause");
	exit(0);//退出
}

//添加职工
void workerManager::Add_Emp(){
	cout << "请输入添加职工数量： " << endl;
	int addnum = 0;//用addnum来接收要添加职工的个数
	cin >> addnum;

	if (addnum > 0){
		//添加操作
		//计算一下新添加之后的数组大小
		int newSize = this->m_EmpNum + addnum;//新空间的人数 = 原来空间的人数 + 添加的人数

		//开辟新空间
		Worker** newSpace = new Worker*[newSize];

		//如果原来空间不为空，那么将原来空间的数据拷贝到新的空间下
		if (this->m_EmpArray != NULL){
			for (int i = 0; i < this->m_EmpNum; ++i){
				//既然是拷贝原来的数据，那么控制部分一定要用原来空间大小来控制
				//如果用新的数组空间大小，此时一定大于原来的空间大小，就会造成越界访问，就写成BUG了！！！
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addnum; ++i){
			int id;//部门编号
			string name;//员工姓名
			int dSelect;//部门选择

			cout << "请输入第 " << i + 1 << " 个员工编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个员工姓名：" << endl;
			cin >> name;
			cout << "请选择该员工岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//将创建的职工指针，保存到数组当中去
			newSpace[this->m_EmpNum + i] = worker;
			//记住，一定要加上this->m_EmpNum，因为我将原来数据拷到新空间得时候
			//原来的数据也会占用相对应的大小空间，再次添加新数据的时候，就要在原来数据的后面添加

		}

		//释放原来的数据空间
		delete[] this->m_EmpArray;//注意，原来的空间也是一个数组，所以释放的时候要加[]

		//更改新空间的指向
		this->m_EmpArray = newSpace;//newSpace是在站上开辟的成员变量，一出函数，该变量就会被销毁，但是堆区上的空间还在，交给原本的类的成员属性

		//更新职工人数
		this->m_EmpNum = newSize;

		//提示添加成功
		cout << "成功添加" << addnum << "名新职工！" << endl;

		//请按任意键继续后，返回上级目录
		system("pause");
		system("cls");

	}
	else{
		//无法添加
		cout << "数据输入有误" << endl;
	}
}