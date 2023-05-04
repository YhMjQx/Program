#include"workerManager.h"

workerManager::workerManager(){
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()){
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;

		//初始化数组指针
		this->m_EmpArray = NULL;

		//初始化文件是否为空
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
		//即使文件无法打开，仍需要关闭 ifstream 对象。因为如果不关闭文件，该文件的句柄仍会占用系统资源
		//这可能会导致其他操作或程序无法使用该文件或无法访问其他文件。因此，在使用 ifstream 或 ofstream 类时
		//无论其打开操作是否成功，都应始终安排好关闭该文件的操作。
	}

	//2.文件存在，数据为空
	char ch;
	ifs >> ch;//在文件中读取了一个字符，每读一个内容，下标就会往后走一个，直到走到文件尾
	if (ifs.eof()){
		//文件为空
		cout << "文件为空" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;

		//初始化数组指针
		this->m_EmpArray = NULL;

		//初始化文件是否为空
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//3.文件存在，并且保存职工的所有数据
	int num = this->get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	if (ifs.is_open() && !ifs.eof()){
		this->m_FileIsEmpty = false;
	}

	//开辟空间
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//将文件中数据读取存放到数组中
	this->init_Emp();

	////测试代码
	//for (int i = 0; i < this->m_EmpNum; ++i){
	//	cout << "职工编号： " << this->m_EmpArray[i]->m_Id
	//		<< " 姓名： " << this->m_EmpArray[i]->m_Name
	//		<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	//}

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

		//添加成功之后，保存数据到文件中
		this->Save();

		//更新职工不为空的标志
		this->m_FileIsEmpty = false;

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

//保存文件
void workerManager::Save(){
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件 - 写文件

	//将每个数据写到文件当中
	for (int i = 0; i < this->m_EmpNum; ++i){
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}


//统计文件中的人数
int workerManager::get_EmpNum(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件 打开文件

	int id;
	string name;
	int deid;
	
	int num = 0;
	while (ifs >> id&&ifs >> name&&ifs >> deid){
		//读取一行的操作,之前六的空格作为分隔符，读取时会自动跳过
		//如果没有空格作为分隔符，那么读取的结果只会是一个人
		++num;
	}
	return num;
	//ifs.close();
}

//初始化员工
void workerManager::init_Emp(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//从文件中读取数据到程序当中
	
	//由于要将数据读出来，那么肯定需要将读出来的数据存放在变量中
	int id;
	string name;
	int deid;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deid){
		// >> - 右移运算符，逐词读取，词与词之间空格区分，可直接赋值给变量
		Worker* worker = NULL;

		if (deid == 1){//普通员工
			worker = new Employee(id, name, deid);
		}

		else if (deid == 2){//经理
			worker = new Manager(id, name, deid);
		}

		else{//老板
			worker = new Boss(id, name, deid);
		}

		this->m_EmpArray[index] = worker;
		++index;
	}

	//关闭文件
	ifs.close();
}


//显示职工
void  workerManager::Show_Emp(){
	//判断文件是否为空或者不存在
	if (this->m_FileIsEmpty){
		cout << "文件不存在或者文件为空！" << endl;
	}
	else{
		for (int i = 0; i < this->m_EmpNum; ++i){
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键继续
	system("pause");
	system("cls");
}


//判断职工是否存在，如果存在返回职工所在数组中的位置,不存在返回-1
int  workerManager::IsExist(int id){
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; ++i){
		if (this->m_EmpArray[i]->m_Id == id){
			index = id;
			break;
		}
	}
	return index-1;
	//index是要作为下标 来进行索引的，怎么能和id一样呢，肯定是要比id小一个的喽
}

//删除职工
void  workerManager::Del_Emp(){
	//先判断数组是否为空
	if (this->m_FileIsEmpty){
		cout << "文件不存在或记录为空" << endl;
	}
	else{
		//按照职工编号删除职工
		cout << "请输入职工编号： " << endl;
		int id = 0;
		cin >> id;

		//判断该编号的员工是否存在
		int index = this->IsExist(id);
		if (index != -1){
			//此时说明该编号的职工存在，那么就要删除该编号的职工
			for (int i = index; i < this->m_EmpNum - 1; ++i){
				//数据前移
				this->m_EmpArray[index] = this->m_EmpArray[index + 1];
			}
			--this->m_EmpNum;
			//数据同步更新到文件中
			this->Save();

			cout << "删除成功！" << endl;
		}
		else{
			cout << "删除失败，未找到该员工！" << endl;
		}
	}

	//按任意键继续 清屏
	system("pause");
	system("cls");

}


//修改职工
void  workerManager::Mod_Emp(){
	//先判断文件是否存在
	if (this->m_FileIsEmpty){
		cout << "文件不存在或记录为空！" << endl;
	}

	else{
		cout << "请输入要修改的职工的编号： " << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1){
			//查找到要修改的员工
			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = " ";
			int newdeid = 0;

			cout << "查找到原 " << id << " 的职工，请输入新职工号： " << endl;
			cin >> newid;

			cout << "请输入新的姓名： " << endl;
			cin >> newname;

			cout << "请输入新的岗位： " << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newdeid;
			
			Worker* worker = NULL;//先准备一个父类指针，以便下面switch语句操作

			switch (newdeid){
			case 1:
				worker = new Employee(newid, newname, newdeid);

				break;
			case 2:
				worker = new Manager(newid, newname, newdeid);

				break;
			case 3:
				worker = new Boss(newid, newname, newdeid);

				break;
			default:
				break;
			}

			//更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;

			//保存数据到文件
			this->Save();
		}

		else{
			cout << "修改失败，查无此人！" << endl;
		}

	}
	system("pause");
	system("cls");
}

//查找职工
void workerManager::Find_Emp(){
	//首先需要判断改文件是否存在
	if (this->m_FileIsEmpty){
		cout << "改文件不存在或记录为空！" << endl;
	}

	else{
		cout << "请输入查找方式： " << endl;
		cout << "1按职工编号查找 " << endl;
		cout << "2.按职工姓名查找 " << endl;

		int select = 0;
		cin >> select;
		
		if (select == 1){
			//按编号查找
			int id;
			cout << "请输入要查找的职工编号： " << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1){
				//找到职工
				cout << "查找成功！该职工信息如下： " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2){
			//按姓名查找
			string name;
			cout << "请输入查找的姓名： " << endl;
			cin >> name;

			//添加一个是否查找的的标志
			bool flag = false;//默认未找到职工


			for (int i = 0; i < this->m_EmpNum; ++i){
				if (this->m_EmpArray[i]->m_Name == name){
					cout << "查找成功，职工编号为： " << this->m_EmpArray[i]->m_Id
						<< " 号的职工信息如下： " << endl;

					flag = true;
					this->m_EmpArray[i]->showInfo();
					
				}
			}

			if (flag == false){
				cout << "查找失败，查无此人！" << endl;
			}

		}
		else{
			cout << "输入有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}


//按职工编号排序
void workerManager::Sort_Emp(){
	//先判断文件是否存在
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工编号进行升序" << endl;
		cout << "2、按职工编号进行降序" << endl;

		int select = 0;
		cin >> select;

		//这是一个选择排序算法
		for (int i = 0; i < this->m_EmpNum; ++i)
		{
			int minOrmax = i;//声明一个最小值 或 一个最大值，每次从这个最小值或者最大值开始排序，同时，这个变量对下面的代码是很有好处的
			for (int j = i + 1; j < this->m_EmpNum; ++j)
			{
				if (select == 1)
				{
					//此时用户选择升序排序
					if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}

				else if (select == 2)
				{
					//此时用户选择降序排序
					if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}
			}

			//判断 minOrmax经过内层for循环之后，是否发生了改变，如果发生了改变，说明找到了比原来minOrmax更合适的下标，那么就要对其进行交换
			if (minOrmax != i)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
		cout << "排序成功！排序后的结果如下： " << endl;
		this->Save();//将排序后的结果保存到文件当中
		this->Show_Emp();//显式所有职工信息

	}
}


//清空文件
void workerManager::Clean_File()
{
	cout << "是否确认清空文件？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	//第一个if是在删除文件中的数据
	if (select == 1)
	{
		//说明用户的确像清空文件，则利用 ios::trunc - 删除文件之后再重新创建该文件
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		//第二个if是在删除程序中数组的数据
		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; ++i)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			//删除堆区的数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;

	}

	system("pause");
	system("cls");
}

workerManager::~workerManager(){
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; ++i)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				//删除堆区的每个职工对象
				delete this->m_EmpArray[i];//如果数组不为空,并且数组内的成员也不为空，就先将数组内的每一个成员先释放掉
				this->m_EmpArray[i] = NULL;
			}
		}

		//待将数组 内部成员所开辟的空间释放干净之后，再释放数组的空间
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}