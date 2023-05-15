#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<time.h>
using namespace std;

//公司今天招聘10个员工（ABCDEFGHIJ），10名员工进入公司后，需要指派员工在哪个部门工作
//员工信息有：姓名 工资   部门分为：策划，美术，研发
//随机给10名员工分配部门和工资
//通过multimap进行信息插入 key（部门编号） value（员工）
//分部门显式员工信息

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker{
public:
	string m_Name;
	int m_Salary;
};

void createPerson(vector<Worker>& v){

	string nameseed = "ABCDEFGHIJ";

	for (int i = 0; i <10; ++i){
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameseed[i];

		worker.m_Salary = rand() % 10000 + 10000;

		//每创建好一个员工都应该将其存放进vector容器中
		v.push_back(worker);
	}
}

void SetGroup(vector<Worker>& v,multimap<int ,Worker>& m){
	//先遍历一遍v容器，将遍历到的结果进行分组
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); ++it){
		//首先，我们先创建一个随机数部门编号

		int deptId = rand() % 3;// 0 1 2

		m.insert(make_pair(deptId, *it));
		//现在就需要将每一个员工，以及它对应的部门编号，插入multimap容器中
		//但是别忘了，map和multimap容器内的所有元素都是对组，那么我们穿进去的也应该是对组才行
		//我们使用vector容器遍历的数组，所以*it就代表的是Worker

		//本来的vector容器中顺序是按照ABCDEFGHIJ来排序的，但为什么到了multimap容器中顺序就不一样了呢
		//原因是因为：vector中的确是有序的，遍历数组的时候也的确是有序的从A到J一一遍历的，往multimap中插入的时候也是有序的
		//但是关键就在deptId他是不停的在变的，也就是说A对应的depeId是可能是0，但下一个B对应的deptId可能就变成2了
		//然后就会对每一个deptId进行排序，也是对key值排序，也就最后看到的结果了
	}
}

void ShowWorker(multimap<int,Worker>& m){
	cout << "策划部门：" << endl;
	//找到key值为0的员工们,并用迭代器接收以及用数据计数
	multimap<int, Worker>::iterator pos = m.find(CEHUA);//找到key值为0的起始位置
	int index = m.count(CEHUA);//统计key值为0的总共人数
	for (int count = 0; pos != m.end() && count < index; ++pos, ++count){
		cout << "部门编号：" << pos->first << "  姓名：" << pos->second.m_Name << "  工资：" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------------" << endl;

	cout << "美术部门" << endl;
	pos = m.find(MEISHU);//找到key值为1的起始位置
	index = m.count(MEISHU);//统计key值为1的总共人数
	for (int count = 0; pos != m.end() && count < index; ++pos, ++count){
		cout << "部门编号：" << pos->first << "  姓名：" << pos->second.m_Name << "  工资：" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------------" << endl;

	cout << "研发部门" << endl;
	pos = m.find(YANFA);//找到key值为2的起始位置
	index = m.count(YANFA);//统计key值为2的总共人数
	for (int count = 0; pos != m.end() && count < index; ++pos, ++count){
		cout << "部门编号：" << pos->first << "  姓名：" << pos->second.m_Name << "  工资：" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------------" << endl;
}

void test1(){

	//1.创建员工并存放进容器
	vector<Worker>vworker;//先创建一个存放Person的容器，好将创建的Person存放进容器中
	createPerson(vworker);

	////测试
	//for (vector<Worker>::iterator it = vworker.begin(); it != vworker.end(); ++it){
	//	cout << "姓名：" << (*it).m_Name << "  年龄：" << it->m_Salary << endl;
	//}
	//cout << "-------------------------" << endl;

	//2.员工分组
	multimap<int, Worker>mworker;
	//key - 部门编号    value - Worker具体员工       而最终的目的就是将所有员工以及对应的所有信息都分组存放在multimap容器中
	SetGroup(vworker, mworker);
	//要想对员工进行分组，那么就需要将所有的员工放进去，而现在所有的员工就存放在vworker中，所以第一个参数就是vworker
	//但是我们有需要用key 和 value的方式进行分组，所以就需要用到multimap容器，于是我们就创建一个mworker


	////测试
	//for (multimap<int, Worker>::iterator it = mworker.begin(); it != mworker.end(); ++it){
	//	cout << "部门编号：" << it->first << "  姓名：" << it->second.m_Name << "  工资：" << it->second.m_Salary << endl;
	//}
	//cout << "-------------------------" << endl;


	//3.分组显示员工
	//因为现在员工对应的所有信息全都在mworker当中，所以现在应该将mworker作为参数传进去
	ShowWorker(mworker);
}

int main(){
	srand((unsigned int)time(NULL));
	test1();

	return 0;
}