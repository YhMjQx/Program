#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

//案例描述：选手ABCDE，10个评委分别对每一个选手打分，去除最高分，去除最低分，取平均分

//步骤实现：
//1.创建5名选手，放到vector中
//2.遍历vector容器，取出来每一个选手，执行for循环，将10个评委的打分存放到deque容器中
//3.sort算法对deque进行排序，去除最高分和最低分
//4.deque容器遍历一遍，叠加总分
//5.获取平均分

//选手类
class Person{
public:

	Person(string name, int score) :m_Name(name), m_score(score){

	}

	string m_Name;
	int m_score;
};

void creatPerson(vector<Person>&v){
	//需要使用for循环来创建
	string namesed = "ABCDE";
	for (int i = 0; i < 5; ++i){

		string name = "选手";
		name += namesed[i];
		//利用字符串拼接技巧分别获取五个选手的名字
		int score = 0;//分数先都默认为0

		Person p(name, score);
		//创建完毕选手记得将选手存放在vector容器中
		v.push_back(p);
	}
}

void Setscore(vector<Person>&v){
	//创建一个deque容器用以存放分数
	for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it){
		//将分数存放进deque容器
		deque<int>d;
		//总共有10个评委，因此该for循环有十次
		for (int i = 0; i < 10; ++i){
			int score = rand() % 41 + 60;
			//rand() % 41 - 这个结果为0 到 40
			d.push_back(score);
		}

		//当分数已经全部存储完了之后，对d容器排序
		sort(d.begin(), d.end());

		////测试代码
		//cout << "选手：" << it->m_Name << " 的打分： " << endl;
		//for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); ++dit){
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//去掉最高分和最低分
		d.pop_back();
		d.pop_front();

		//计算平均分
		int sum = 0;
		for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); ++dit){
			//累加每个评委的分数
			sum += *dit;
		}

		int avg = sum / d.size();

		//最后将这个平均分赋给该选手的属性
		it->m_score = avg;
	}
}

void showScore(vector<Person>v){
	for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it){
		cout << "姓名：" << it->m_Name << "  得分：" << it->m_score << endl;
	}
}

int main(){

	//添加随机数种子
	srand((unsigned int)time(NULL));


	//创建五个选手
	vector<Person>v1;//存放选手的容器
	creatPerson(v1);
	////测试代码
	//for (vector<Person>::const_iterator it = v1.begin(); it != v1.end(); ++it){
	//	cout << "姓名： " << (*it).m_Name << "  分数： " << (*it).m_score << endl;
	//}

	//给选手打分
	Setscore(v1);

	//最终得分
	showScore(v1);

	return 0;
}