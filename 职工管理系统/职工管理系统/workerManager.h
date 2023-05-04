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
	//���캯��
	workerManager();

	//��ʾ�˵�
	void show_menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void Save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ��е�����
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ��,�����ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//��ְ���������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~workerManager();


};

//�û�������������ʱ�򣬻��в�ͬ�����Ա����������ô��Ҫ����Щ��ͬ�����Ա��������һ�����������鵱�д洢����Ҫ�������鿪�ٵ�����
//�ᷢ�ֲ�ͬ�����Ա�������Ӧ������Ҳ�ǲ�ͬ�ģ���ôΪ��ʵ�����������������Ҫ��һ�����嶼�ʺϵ�ָ����ά��
//�Ǿ���worker���ͣ�����Ա�����̳���worker�������ҿ�����������ȫ���洢����worker*ָ�룬Ȼ����Щָ��ֱ�ָ�����
//��Ӧ��Ա�����ͣ�Ȼ����worker**ָ����ά��������飬��ʵ�������˶�̬��ͳһ����Щָ�룬ͳһ�ø���ָ��������

//��Ȼ����ʵ�������ְ���󣬽����ݱ��浽�ļ��еĲ���������ÿ�ο�ʼ���г����ʱ�򣬲�û�н��ļ��е����ݼ��ص�������
//�����ǳ���Ĺ��ܻ�������ļ���������˹��캯����ʼ�����ݵ�����·�Ϊ����
//1.��һ��ʹ�ã��ļ�δ����
//2.�ļ����ڣ��������ݱ��û����
//3.�ļ����ڣ����ұ���ְ������������