#include"speechManager.h"

//���캯��
speechManager::speechManager(){

	//��ʼ������������
	this->InitSpeech();

	//����12��ѡ��
	this->createSpeaker();

	//���������¼
	this->loadRecord();


}

//�˵�����
void speechManager::show_Menu(){
	cout << "**********************************************" << endl;
	cout << "************** ��ӭ�μ��ݽ����� **************" << endl;
	cout << "**************  1.��ʼ�ݽ�����  **************" << endl;
	cout << "**************  2.�鿴�����¼  **************" << endl;
	cout << "**************  3.��ձ�����¼  **************" << endl;
	cout << "**************  0.�˳���������  **************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

//�˳�����
void speechManager::exitSystem(){
	cout << "��ӭ���´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//��ʼ������������
void speechManager::InitSpeech(){
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vvictory.clear();
	this->m_Speaker.clear();

	//��ʼ������������Ҫ�������������˵����һ�ֵı����Ѿ���ʼ�ˣ�˵�����ǵ�һ�ֱ���
	this->m_Index = 1;

	//��ʼ����¼һ�������
	this->m_Record.clear();
}

//����12��ѡ��
void speechManager::createSpeaker(){
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); ++i){
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ����Ϣ
		//����
		Speaker sp;
		sp.m_Name = name;

		//�÷� - ��ʼ����Ϊ0
		for (int j = 0; j < 2; ++j){
			sp.m_score[j] = 0;
		}


		//��ѡ�ֱ�ţ�������v1������
		this->v1.push_back(i + 10001);


		//Ȼ�󽫴����õ�Speaker��Ϣ����map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));


	}
}


//��ʼ���� �����������̿��ƺ���
void speechManager::startSpeech(){
	//��һ�ֱ�����ʼ

	//1.��ǩ
	this->speechDraw();

	//2.����
	this->speechContest();

	//3.��ʾ�������
	this->showScore();

	//�ڶ��ֱ�����ʼ
	++this->m_Index;

	//1.��ǩ
	this->speechDraw();

	//2.����
	this->speechContest();

	//3.��ʾ���ս��
	this->showScore();

	//����������ļ���
	this->saveRecord();

	//���ñ���
	//��ʼ������
	this->InitSpeech();

	//����ѡ��
	this->createSpeaker();

	//��ȡ�����¼
	this->loadRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");

	//��������Ҳ�������ı�����¼��û��ʵʱ����
	//����Ϊ��Ȼ���������浽���ļ��У�����û�����ñ��������ݣ�Ҳû�����»�ȡ������¼
	//�������̾����ȸ�ʮ����ѡ�ֳ�ǩ��Ȼ��ʼ������������֮����ʾ�������
	//�ڶ��ֱ������ظ����ϲ�������󱣴浽�����ļ��У�����������֮��ͽ������õ�����������ʼ����������ȷ������ˣ������ļ���û�����Ŷ
	//�ٴ���ʮ����ѡ�ֵ����������Ҫ���������Ļ������½�12�������ã��ļ�������ٶ�ȡһ�Σ����ɸ��²�ѯ������
	
}

//��ǩ
void speechManager::speechDraw(){
	cout << "�� << " << this->m_Index << " >> �ֵı������ڳ�ǩ" << endl;
	cout << "-------------------------------" << endl;
	if (this->m_Index == 1){
		cout << "��һ�ֵĳ�ǩ���������ʾ��" << endl;
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}
	else{
		cout << "�ڶ��ֵĳ�ǩ���������ʾ��" << endl;
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

//����
void speechManager::speechContest(){
	cout << "------------�� " << this->m_Index << " �ֱ�����ʽ��ʼ------------" << endl;

	//����һ����ʱ����
	multimap<double, int, greater<double>> groupScore;	//multimap���Է�ֹmap�ڵ÷�һ����ʱ����ɵ�����

	int num = 0;	//ͳ����Ա�������Է������ڷ���


	//����һ������ѡ������
	vector<int>v_Src;
	if (this->m_Index == 1){
		v_Src = v1;
	}
	else{
		v_Src = v2;
	}

	//�������в���ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); ++it){

		++num;

		//��10����ί���
		deque<double>q;
		for (int i = 0; i < 10; ++i){
			
			double score = (rand() % 401 + 600) / 10.f;	//rand()%401 - 0��400����ʼֵΪ600�����յķ���60��100��С��
			//cout << score << " ";
			q.push_back(score);
		}
		//cout << endl;

		//��������������
		sort(q.begin(), q.end(), greater<double>());	//����һ�����õĺ�������Ľ�������

		q.pop_back();	//ȥ����ͷ�
		q.pop_front();	//ȥ����ߵ÷�

		double sum = (double)accumulate(q.begin(), q.end(),0.0f);	//��ʼֵΪ0.0f,��ȡ�ܷ�
		double avg = sum / (double)q.size();	//��ȡƽ����

		////���Դ�ӡƽ���ֵĴ���
		//cout << "��ţ� " << *it << " ������" << this->m_Speaker[*it].m_Name << " �÷֣� " << avg << endl;

		//��ƽ���ֲ��뵽map������
		this->m_Speaker[*it].m_score[this->m_Index - 1] = avg;
		////���Դ�ӡƽ���ֵĴ���
		//cout << "��ţ� " << *it
		//	<< " ������" << this->m_Speaker[*it].m_Name
		//	<< " �÷֣� " << *(this->m_Speaker[*it].m_score) << endl;

		//������õ��ķ�����Ҳ�Ž���ʱ������
		groupScore.insert(make_pair(avg, *it));		//key�ǵ÷֣�value�Ǿ�����Ա���

		//�������еĽ�����Ѿ������ ����ÿ6�˷�һ�飬��ȡ��ǰ����
		if (num % 6 == 0){
			cout << "�� " << num / 6 << " �����������£�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); ++it){
				cout << "��� �� " << it->second 
					<< "  ������" << this->m_Speaker[it->second].m_Name 
					<< "  �÷֣�" << this->m_Speaker[it->second].m_score[this->m_Index-1] << endl;
			}
			cout << endl;

			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count<3; ++it,++count){
				if (this->m_Index == 1){
					v2.push_back(it->second);
				}
				else{
					vvictory.push_back(it->second);
				}
			}

			//�����ʱ�����������޵ڶ���Ĳ�����Ա��Ž�����������ʾ
			groupScore.clear();
		}

	}
	cout << "-------------��" << this->m_Index << "�ֱ���������-------------"<<endl;
	system("pause");
	//system("cls");
}

//��ʾ�÷�
void speechManager::showScore(){

	cout << "-------------�� " << this->m_Index << " �ֽ���ѡ����Ϣ���£�--------------" << endl;

	vector<int>v;
	if (this->m_Index == 1){
		v = v2;
	}
	else{
		v = vvictory;
	}

	//����forѭ�����������Ա��Ϣ
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << "��ţ� " << *it
			<< "  ������" << this->m_Speaker[*it].m_Name
			<< "  �÷֣�" << this->m_Speaker[*it].m_score[this->m_Index-1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();

}

//�����¼
void speechManager::saveRecord(){
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); //׷��д�ļ�

	//��ÿ����Ϣд���ļ�����
	for (vector<int>::iterator it = vvictory.begin(); it != vvictory.end(); ++it){
		//��Ϊ.csv�Ǳ���ļ���ÿ����Ԫ֮��������ǿ��������ָ��
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;

	//��Ȼ�ļ��Ѿ����棬˵���������ļ��Ѿ���Ϊ����
	this->fileIsEmpty = false;
}

//��ȡ����
void speechManager::loadRecord(){
	ifstream ifs("speech.csv", ios::in);	//���ļ�

	//�ļ������ڵ����
	if (!ifs.is_open()){
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�ļ�Ϊ�յ����
	char ch;
	ifs >> ch;
	if (ifs.eof()){
		//ifs.eof˵����ȡһ���ֽڶ������ļ�βΪ��
		//��ʱ˵���ļ�Ϊ��
		this->fileIsEmpty = true;
		//cout << "�ļ�Ϊ��" << endl;
		ifs.close();
		return;
	}

	//�ļ������Ҳ�Ϊ�յ���� - ��Ҫ���ǽ�ȡ�ַ���
	//����find�ҵ���ȡ��λ�ã�Ȼ����substr��ȡ�ַ���
	//������Ҫ��֮ǰ���ߵ�ch���Ż��ļ��У���Ȼ�ļ��оͻ���һ���ַ�
	this->fileIsEmpty = false;

	ifs.putback(ch);

	string data;	//��ÿһ�����������ݴ����data��

	int Index = 0;	//Ĭ���ǵ�0�죬����map�����еĵ�һ������,�������һ��Ҫ����ѭ������
					//�������ѭ���ڲ��Ļ���ÿ����һ��ѭ����Ҳ����˵ÿ��һ�����ݣ��Ҷ�������Index
					//�����Ҳ鿴�����¼��ʱ����Զ��ֻ��һ�죬����ʵ�ϣ��ļ���ȴ�кܶ��
					//Ȼ��ÿ����һ��ѭ��++Index�ͺ���


	while (ifs >> data){	//�����һ��һ�еĶ�ȡ
		//cout << data << endl;

		vector<string>v;	//ÿһ��ʹ��һ���������洢


		int pos = -1;	//���������Ƿ�鵽������λ�õı���

		int start = 0;	//���ǲ�ѯ����������ʼλ�ã�Ĭ��Ϊ0

		while (true){
			pos = data.find(",", start);

			if (pos == -1){
				//û���ҵ������
				break;
			}

			string temp = data.substr(start, pos - start);	//��startλ�ÿ�ʼ��ȡ����ȡpos-start���ַ�����
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;	//���һ���Ҳ�����ʱ��ͱ�����ļ�β������-1
		}

		//��m_Record(����������ݵ�����)�������
		
		this->m_Record.insert(make_pair(Index, v));
		++Index;


	}
	ifs.close();
		//for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); ++it){
		//	cout << it->first << "�ھ���ţ�" << it->second[0] << "  ������" << it->second[1] << endl;

		//}
}

//��ʾ�����¼
void speechManager::showRecord(){

	if (this->fileIsEmpty){
		cout << "�ļ�Ϊ�ջ��ļ�������" << endl;

	}
	else{
		for (int i = 0; i < this->m_Record.size(); ++i){
			//this->m_Record[i][j]
			//[i] - ͨ���±�i����m_Record��ÿһ��
			//[j] - ͨ���±�j����m_Record�ĵ�ǰ�е�ÿһ���ַ���
			cout << "��" << i + 1 << "��  "
				<< "�ھ���ţ�" << this->m_Record[i][0] << "  �÷֣�" << this->m_Record[i][1] << "  "
				<< "�Ǿ���ţ�" << this->m_Record[i][2] << "  �÷֣�" << this->m_Record[i][3] << "  "
				<< "������ţ�" << this->m_Record[i][4] << "  �÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}


//����ļ�
void speechManager::ClearRecord(){
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << " 1.��       2.�� " << endl;
	int select = 0;
	cin >> select;
	if (select == 1){
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);//����ļ����ھ�ɾ���ļ������´���һ��
		ofs.close();

		//��ʼ������������
		this->InitSpeech();

		//����12��ѡ��
		this->createSpeaker();

		//���������¼
		this->loadRecord();
	}

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}


//��������
speechManager::~speechManager(){

}