#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<algorithm>
#include<numeric>
#include<functional>
#include<string>
#include<fstream>
#include"speaker.h"

using namespace std;

//创建管理类
//提供菜单界面与用户交互
//对演讲比赛流程进行控制
//与文件的读写交互



class speechManager{
public:

	//构造函数
	speechManager();

	//菜单功能
	void show_Menu();

	//退出功能
	void exitSystem();

	//初始化容器和属性
	void InitSpeech();

	//创建12名选手
	void createSpeaker();

	//保存第一轮比赛选手编号容器
	vector<int>v1;

	//第一轮晋级选手编号容器
	vector<int>v2;

	//胜出的前三名选手编号容器
	vector<int>vvictory;

	//存放编号以及对应的具体选手的容器
	map<int, Speaker>m_Speaker;

	//开始比赛 比赛整个流程控制函数
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示得分
	void showScore();

	//保存记录
	void saveRecord();
	
	//读取数据
	void loadRecord();

	 //判断文件是否为空
	bool fileIsEmpty;

	//暂时存放往届一届记录的容器，往届记录应该要一直存放在文件中
	map<int, vector<string>>m_Record;

	//显示往届记录
	void showRecord();

	//清空文件
	void ClearRecord();

	//析构函数
	~speechManager();


	//成员属性
	//存放比赛轮数
	int m_Index;

};