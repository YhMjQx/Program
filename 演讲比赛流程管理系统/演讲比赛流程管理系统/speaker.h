#pragma once
#include<iostream>
#include<string>
using namespace std;

//选手类
class Speaker{
public:

	string m_Name;		//	姓名
	double m_score[2];	//得分，每个人最多有两轮比赛
};