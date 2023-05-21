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

//����������
//�ṩ�˵��������û�����
//���ݽ��������̽��п���
//���ļ��Ķ�д����



class speechManager{
public:

	//���캯��
	speechManager();

	//�˵�����
	void show_Menu();

	//�˳�����
	void exitSystem();

	//��ʼ������������
	void InitSpeech();

	//����12��ѡ��
	void createSpeaker();

	//�����һ�ֱ���ѡ�ֱ������
	vector<int>v1;

	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;

	//ʤ����ǰ����ѡ�ֱ������
	vector<int>vvictory;

	//��ű���Լ���Ӧ�ľ���ѡ�ֵ�����
	map<int, Speaker>m_Speaker;

	//��ʼ���� �����������̿��ƺ���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();
	
	//��ȡ����
	void loadRecord();

	 //�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��ʱ�������һ���¼�������������¼Ӧ��Ҫһֱ������ļ���
	map<int, vector<string>>m_Record;

	//��ʾ�����¼
	void showRecord();

	//����ļ�
	void ClearRecord();

	//��������
	~speechManager();


	//��Ա����
	//��ű�������
	int m_Index;

};