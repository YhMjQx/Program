#include"speechManager.h"
#include<time.h>
#include<string>

int main(){

	//创建一个随机数种子
	srand((unsigned int)time(NULL));

	//创建管理类对象
	speechManager sm;

	////测试code
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); ++it){
	//	cout << "选手编号： " << it->first
	//		<< "  姓名： " << it->second.m_Name
	//		<< "  得分： " << it->second.m_score
	//		<< endl;
	//}


	int choice = 0;
	while (true){
		sm.show_Menu();

		cout << "请输入您的选择： " << endl;
		cin >> choice;

		switch (choice){
		case 1:		//开始演讲比赛
			sm.startSpeech();
			break;
		case 2:		//查看往届记录
			sm.showRecord();
			break;
		case 3:		//清空比赛记录
			sm.ClearRecord();
			break;
		case 0:		//退出比赛程序
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	return 0;
}