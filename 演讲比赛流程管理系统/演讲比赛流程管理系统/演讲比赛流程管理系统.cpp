#include"speechManager.h"
#include<time.h>
#include<string>

int main(){

	//����һ�����������
	srand((unsigned int)time(NULL));

	//�������������
	speechManager sm;

	////����code
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); ++it){
	//	cout << "ѡ�ֱ�ţ� " << it->first
	//		<< "  ������ " << it->second.m_Name
	//		<< "  �÷֣� " << it->second.m_score
	//		<< endl;
	//}


	int choice = 0;
	while (true){
		sm.show_Menu();

		cout << "����������ѡ�� " << endl;
		cin >> choice;

		switch (choice){
		case 1:		//��ʼ�ݽ�����
			sm.startSpeech();
			break;
		case 2:		//�鿴�����¼
			sm.showRecord();
			break;
		case 3:		//��ձ�����¼
			sm.ClearRecord();
			break;
		case 0:		//�˳���������
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}