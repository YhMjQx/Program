#include"speechManager.h"

//构造函数
speechManager::speechManager(){

	//初始化容器和属性
	this->InitSpeech();

	//创建12名选手
	this->createSpeaker();

	//加载往届记录
	this->loadRecord();


}

//菜单功能
void speechManager::show_Menu(){
	cout << "**********************************************" << endl;
	cout << "************** 欢迎参加演讲比赛 **************" << endl;
	cout << "**************  1.开始演讲比赛  **************" << endl;
	cout << "**************  2.查看往届记录  **************" << endl;
	cout << "**************  3.清空比赛记录  **************" << endl;
	cout << "**************  0.退出比赛程序  **************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

//退出功能
void speechManager::exitSystem(){
	cout << "欢迎您下次使用！" << endl;
	system("pause");
	exit(0);
}

//初始化容器和属性
void speechManager::InitSpeech(){
	//容器先置空
	this->v1.clear();
	this->v2.clear();
	this->vvictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数，要运行这个函数，说明第一轮的比赛已经开始了，说明这是第一轮比赛
	this->m_Index = 1;

	//初始化记录一届的容器
	this->m_Record.clear();
}

//创建12名选手
void speechManager::createSpeaker(){
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); ++i){
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手信息
		//姓名
		Speaker sp;
		sp.m_Name = name;

		//得分 - 初始化均为0
		for (int j = 0; j < 2; ++j){
			sp.m_score[j] = 0;
		}


		//创选手编号，并插入v1容器中
		this->v1.push_back(i + 10001);


		//然后将创建好的Speaker信息插入map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));


	}
}


//开始比赛 比赛整个流程控制函数
void speechManager::startSpeech(){
	//第一轮比赛开始

	//1.抽签
	this->speechDraw();

	//2.比赛
	this->speechContest();

	//3.显示晋级结果
	this->showScore();

	//第二轮比赛开始
	++this->m_Index;

	//1.抽签
	this->speechDraw();

	//2.比赛
	this->speechContest();

	//3.显示最终结果
	this->showScore();

	//保存分数到文件中
	this->saveRecord();

	//重置比赛
	//初始化属性
	this->InitSpeech();

	//创建选手
	this->createSpeaker();

	//获取往届记录
	this->loadRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");

	//比赛后差找不到本届的比赛记录，没有实时更新
	//是因为虽然将分数保存到了文件中，但是没有重置比赛的内容，也没有重新获取比赛记录
	//具体流程就是先给十二名选手抽签，然后开始比赛，比完赛之后显示比赛结果
	//第二轮比赛再重复以上操作，最后保存到分数文件中，当保存完结果之后就将所有用到的容器给初始化，容器的确是清空了，但是文件可没有清空哦
	//再创建十二名选手的意义是如果要连续比赛的话就重新将12个人重置，文件保存后再读取一次，即可更新查询的内容
	
}

//抽签
void speechManager::speechDraw(){
	cout << "第 << " << this->m_Index << " >> 轮的比赛正在抽签" << endl;
	cout << "-------------------------------" << endl;
	if (this->m_Index == 1){
		cout << "第一轮的抽签结果如下所示：" << endl;
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	else{
		cout << "第二轮的抽签结果如下所示：" << endl;
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------" << endl;
	system("pause");
	cout << endl;
}

//比赛
void speechManager::speechContest(){
	cout << "------------第 " << this->m_Index << " 轮比赛正式开始------------" << endl;

	//创建一个临时容器
	multimap<double, int, greater<double>> groupScore;	//multimap可以防止map在得分一样的时候造成的问题

	int num = 0;	//统计人员人数，以方便用于分组


	//创建一个比赛选手容器
	vector<int>v_Src;
	if (this->m_Index == 1){
		v_Src = v1;
	}
	else{
		v_Src = v2;
	}

	//遍历所有参赛选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); ++it){

		++num;

		//让10个评委打分
		deque<double>q;
		for (int i = 0; i < 10; ++i){
			
			double score = (rand() % 401 + 600) / 10.f;	//rand()%401 - 0到400，起始值为600，最终的分是60到100的小数
			//cout << score << " ";
			q.push_back(score);
		}
		//cout << endl;

		//给分数容器排序
		sort(q.begin(), q.end(), greater<double>());	//用了一个内置的函数对象的降序排列

		q.pop_back();	//去除最低分
		q.pop_front();	//去除最高得分

		double sum = (double)accumulate(q.begin(), q.end(),0.0f);	//起始值为0.0f,获取总分
		double avg = sum / (double)q.size();	//获取平均分

		////测试打印平均分的代码
		//cout << "编号： " << *it << " 姓名：" << this->m_Speaker[*it].m_Name << " 得分： " << avg << endl;

		//将平均分插入到map容器中
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;
		////测试打印平均分的代码
		//cout << "编号： " << *it
		//	<< " 姓名：" << this->m_Speaker[*it].m_Name
		//	<< " 得分： " << *(this->m_Speaker[*it].m_score) << endl;

		//将上面得到的分数，也放进临时容器中
		groupScore.insert(make_pair(avg, *it));		//key是得分，value是具体人员编号

		//现在所有的结果都已经完成了 就让每6人分一组，并取出前三名
		if (num % 6 == 0){
			cout << "第 " << num / 6 << " 组比赛结果如下：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); ++it){
				cout << "编号 ； " << it->second 
					<< "  姓名：" << this->m_Speaker[it->second].m_Name 
					<< "  得分：" << this->m_Speaker[it->second].m_score[this->m_Index-1] << endl;
			}
			cout << endl;

			//取出前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count<3; ++it,++count){
				if (this->m_Index == 1){
					v2.push_back(it->second);
				}
				else{
					vvictory.push_back(it->second);
				}
			}

			//清空临时容器，方柏霓第二组的参赛人员存放进入容器和显示
			groupScore.clear();
		}

	}
	cout << "-------------第" << this->m_Index << "轮比赛结束！-------------"<<endl;
	system("pause");
	//system("cls");
}

//显示得分
void speechManager::showScore(){

	cout << "-------------第 " << this->m_Index << " 轮晋级选手信息如下：--------------" << endl;

	vector<int>v;
	if (this->m_Index == 1){
		v = v2;
	}
	else{
		v = vvictory;
	}

	//利用for循环输出晋级人员信息
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << "编号： " << *it
			<< "  姓名：" << this->m_Speaker[*it].m_Name
			<< "  得分：" << this->m_Speaker[*it].m_score[this->m_Index-1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();

}

//保存记录
void speechManager::saveRecord(){
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); //追加写文件

	//将每个信息写入文件当中
	for (vector<int>::iterator it = vvictory.begin(); it != vvictory.end(); ++it){
		//因为.csv是表格文件，每个单元之间的内容是靠逗号来分割的
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();
	cout << "记录已经保存" << endl;

	//既然文件已经保存，说明，闲杂文件已经不为空了
	this->fileIsEmpty = false;
}

//读取数据
void speechManager::loadRecord(){
	ifstream ifs("speech.csv", ios::in);	//读文件

	//文件不存在的情况
	if (!ifs.is_open()){
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件为空的情况
	char ch;
	ifs >> ch;
	if (ifs.eof()){
		//ifs.eof说明读取一个字节读到了文件尾为真
		//此时说明文件为空
		this->fileIsEmpty = true;
		//cout << "文件为空" << endl;
		ifs.close();
		return;
	}

	//文件存在且不为空的情况 - 主要就是截取字符串
	//先用find找到截取的位置，然后用substr截取字符串
	//首先需要将之前读走的ch，放回文件中，不然文件中就会少一个字符
	this->fileIsEmpty = false;

	ifs.putback(ch);

	string data;	//将每一个读到的数据存放在data中

	int Index = 0;	//默认是第0届，这是map容器中的第一个参数,这个变量一定要放在循环外面
					//否则放在循环内部的话，每进入一次循环，也就是说每读一行数据，我都会重置Index
					//导致我查看往届记录的时候永远都只有一届，但事实上，文件中却有很多届
					//然后，每进行一次循环++Index就好了


	while (ifs >> data){	//这里会一行一行的读取
		//cout << data << endl;

		vector<string>v;	//每一届使用一个容器来存储


		int pos = -1;	//用来接收是否查到“，”位置的变量

		int start = 0;	//这是查询“，”的起始位置，默认为0

		while (true){
			pos = data.find(",", start);

			if (pos == -1){
				//没有找到的情况
				break;
			}

			string temp = data.substr(start, pos - start);	//从start位置开始截取，截取pos-start的字符长度
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;	//最后一次找不到的时候就变成了文件尾，就是-1
		}

		//让m_Record(存放往届数据的容器)添加数据
		
		this->m_Record.insert(make_pair(Index, v));
		++Index;


	}
	ifs.close();
		//for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); ++it){
		//	cout << it->first << "冠军编号：" << it->second[0] << "  分数：" << it->second[1] << endl;

		//}
}

//显示往届记录
void speechManager::showRecord(){

	if (this->fileIsEmpty){
		cout << "文件为空或文件不存在" << endl;

	}
	else{
		for (int i = 0; i < this->m_Record.size(); ++i){
			//this->m_Record[i][j]
			//[i] - 通过下标i索引m_Record的每一行
			//[j] - 通过下标j索引m_Record的当前行的每一串字符串
			cout << "第" << i + 1 << "届  "
				<< "冠军编号：" << this->m_Record[i][0] << "  得分：" << this->m_Record[i][1] << "  "
				<< "亚军编号：" << this->m_Record[i][2] << "  得分：" << this->m_Record[i][3] << "  "
				<< "季军编号：" << this->m_Record[i][4] << "  得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}


//清空文件
void speechManager::ClearRecord(){
	cout << "是否确定清空文件：" << endl;
	cout << " 1.是       2.否 " << endl;
	int select = 0;
	cin >> select;
	if (select == 1){
		//确认清空
		ofstream ofs("speech.csv", ios::trunc);//如果文件存在就删除文件再重新创建一个
		ofs.close();

		//初始化容器和属性
		this->InitSpeech();

		//创建12名选手
		this->createSpeaker();

		//加载往届记录
		this->loadRecord();
	}

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}


//析构函数
speechManager::~speechManager(){

}