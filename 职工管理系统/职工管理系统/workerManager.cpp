#include"workerManager.h"

workerManager::workerManager(){
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()){
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
		//��ʹ�ļ��޷��򿪣�����Ҫ�ر� ifstream ������Ϊ������ر��ļ������ļ��ľ���Ի�ռ��ϵͳ��Դ
		//����ܻᵼ����������������޷�ʹ�ø��ļ����޷����������ļ�����ˣ���ʹ�� ifstream �� ofstream ��ʱ
		//������򿪲����Ƿ�ɹ�����Ӧʼ�հ��źùرո��ļ��Ĳ�����
	}

	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;//���ļ��ж�ȡ��һ���ַ���ÿ��һ�����ݣ��±�ͻ�������һ����ֱ���ߵ��ļ�β
	if (ifs.eof()){
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}

	//3.�ļ����ڣ����ұ���ְ������������
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	if (ifs.is_open() && !ifs.eof()){
		this->m_FileIsEmpty = false;
	}

	//���ٿռ�
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	//���ļ������ݶ�ȡ��ŵ�������
	this->init_Emp();

	////���Դ���
	//for (int i = 0; i < this->m_EmpNum; ++i){
	//	cout << "ְ����ţ� " << this->m_EmpArray[i]->m_Id
	//		<< " ������ " << this->m_EmpArray[i]->m_Name
	//		<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}



//��ʾ�˵�
void workerManager::show_menu(){
	cout << "***********************************************************" << endl;
	cout << "**************    ��ӭʹ��ְ������ϵͳ��   ****************" << endl;
	cout << "********************  0.�˳��������  *********************" << endl;
	cout << "********************  1.����ְ����Ϣ  *********************" << endl;
	cout << "********************  2.��ʾְ����Ϣ  *********************" << endl;
	cout << "********************  3.ɾ����ְְ��  *********************" << endl;
	cout << "********************  4.�޸�ְ����Ϣ  *********************" << endl;
	cout << "********************  5.����ְ����Ϣ  *********************" << endl;
	cout << "********************  6.���ձ������  *********************" << endl;
	cout << "********************  7.��������ĵ�  *********************" << endl;
	cout << "***********************************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void workerManager::ExitSystem(){
	cout << "��ӭ�´�ʹ��" << endl;
	//system("pause");
	exit(0);//�˳�
}

//���ְ��
void workerManager::Add_Emp(){
	cout << "���������ְ�������� " << endl;
	int addnum = 0;//��addnum������Ҫ���ְ���ĸ���
	cin >> addnum;

	if (addnum > 0){
		//��Ӳ���
		//����һ�������֮��������С
		int newSize = this->m_EmpNum + addnum;//�¿ռ������ = ԭ���ռ������ + ��ӵ�����

		//�����¿ռ�
		Worker** newSpace = new Worker*[newSize];

		//���ԭ���ռ䲻Ϊ�գ���ô��ԭ���ռ�����ݿ������µĿռ���
		if (this->m_EmpArray != NULL){
			for (int i = 0; i < this->m_EmpNum; ++i){
				//��Ȼ�ǿ���ԭ�������ݣ���ô���Ʋ���һ��Ҫ��ԭ���ռ��С������
				//������µ�����ռ��С����ʱһ������ԭ���Ŀռ��С���ͻ����Խ����ʣ���д��BUG�ˣ�����
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addnum; ++i){
			int id;//���ű��
			string name;//Ա������
			int dSelect;//����ѡ��

			cout << "������� " << i + 1 << " ��Ա����ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ��Ա��������" << endl;
			cin >> name;
			cout << "��ѡ���Ա����λ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			//��������ְ��ָ�룬���浽���鵱��ȥ
			newSpace[this->m_EmpNum + i] = worker;
			//��ס��һ��Ҫ����this->m_EmpNum����Ϊ�ҽ�ԭ�����ݿ����¿ռ��ʱ��
			//ԭ��������Ҳ��ռ�����Ӧ�Ĵ�С�ռ䣬�ٴ���������ݵ�ʱ�򣬾�Ҫ��ԭ�����ݵĺ������

		}

		//�ͷ�ԭ�������ݿռ�
		delete[] this->m_EmpArray;//ע�⣬ԭ���Ŀռ�Ҳ��һ�����飬�����ͷŵ�ʱ��Ҫ��[]

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;//newSpace����վ�Ͽ��ٵĳ�Ա������һ���������ñ����ͻᱻ���٣����Ƕ����ϵĿռ仹�ڣ�����ԭ������ĳ�Ա����

		//����ְ������
		this->m_EmpNum = newSize;

		//��ӳɹ�֮�󣬱������ݵ��ļ���
		this->Save();

		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addnum << "����ְ����" << endl;

		//�밴����������󣬷����ϼ�Ŀ¼
		system("pause");
		system("cls");

	}
	else{
		//�޷����
		cout << "������������" << endl;
	}
}

//�����ļ�
void workerManager::Save(){
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ� - д�ļ�

	//��ÿ������д���ļ�����
	for (int i = 0; i < this->m_EmpNum; ++i){
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}


//ͳ���ļ��е�����
int workerManager::get_EmpNum(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ���ļ�

	int id;
	string name;
	int deid;
	
	int num = 0;
	while (ifs >> id&&ifs >> name&&ifs >> deid){
		//��ȡһ�еĲ���,֮ǰ���Ŀո���Ϊ�ָ�������ȡʱ���Զ�����
		//���û�пո���Ϊ�ָ�������ô��ȡ�Ľ��ֻ����һ����
		++num;
	}
	return num;
	//ifs.close();
}

//��ʼ��Ա��
void workerManager::init_Emp(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ��ж�ȡ���ݵ�������
	
	//����Ҫ�����ݶ���������ô�϶���Ҫ�������������ݴ���ڱ�����
	int id;
	string name;
	int deid;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deid){
		// >> - �������������ʶ�ȡ�������֮��ո����֣���ֱ�Ӹ�ֵ������
		Worker* worker = NULL;

		if (deid == 1){//��ͨԱ��
			worker = new Employee(id, name, deid);
		}

		else if (deid == 2){//����
			worker = new Manager(id, name, deid);
		}

		else{//�ϰ�
			worker = new Boss(id, name, deid);
		}

		this->m_EmpArray[index] = worker;
		++index;
	}

	//�ر��ļ�
	ifs.close();
}


//��ʾְ��
void  workerManager::Show_Emp(){
	//�ж��ļ��Ƿ�Ϊ�ջ��߲�����
	if (this->m_FileIsEmpty){
		cout << "�ļ������ڻ����ļ�Ϊ�գ�" << endl;
	}
	else{
		for (int i = 0; i < this->m_EmpNum; ++i){
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�����������
	system("pause");
	system("cls");
}


//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ��,�����ڷ���-1
int  workerManager::IsExist(int id){
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; ++i){
		if (this->m_EmpArray[i]->m_Id == id){
			index = id;
			break;
		}
	}
	return index-1;
	//index��Ҫ��Ϊ�±� �����������ģ���ô�ܺ�idһ���أ��϶���Ҫ��idСһ�����
}

//ɾ��ְ��
void  workerManager::Del_Emp(){
	//���ж������Ƿ�Ϊ��
	if (this->m_FileIsEmpty){
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else{
		//����ְ�����ɾ��ְ��
		cout << "������ְ����ţ� " << endl;
		int id = 0;
		cin >> id;

		//�жϸñ�ŵ�Ա���Ƿ����
		int index = this->IsExist(id);
		if (index != -1){
			//��ʱ˵���ñ�ŵ�ְ�����ڣ���ô��Ҫɾ���ñ�ŵ�ְ��
			for (int i = index; i < this->m_EmpNum - 1; ++i){
				//����ǰ��
				this->m_EmpArray[index] = this->m_EmpArray[index + 1];
			}
			--this->m_EmpNum;
			//����ͬ�����µ��ļ���
			this->Save();

			cout << "ɾ���ɹ���" << endl;
		}
		else{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա����" << endl;
		}
	}

	//����������� ����
	system("pause");
	system("cls");

}


//�޸�ְ��
void  workerManager::Mod_Emp(){
	//���ж��ļ��Ƿ����
	if (this->m_FileIsEmpty){
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}

	else{
		cout << "������Ҫ�޸ĵ�ְ���ı�ţ� " << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1){
			//���ҵ�Ҫ�޸ĵ�Ա��
			delete this->m_EmpArray[ret];
			int newid = 0;
			string newname = " ";
			int newdeid = 0;

			cout << "���ҵ�ԭ " << id << " ��ְ������������ְ���ţ� " << endl;
			cin >> newid;

			cout << "�������µ������� " << endl;
			cin >> newname;

			cout << "�������µĸ�λ�� " << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newdeid;
			
			Worker* worker = NULL;//��׼��һ������ָ�룬�Ա�����switch������

			switch (newdeid){
			case 1:
				worker = new Employee(newid, newname, newdeid);

				break;
			case 2:
				worker = new Manager(newid, newname, newdeid);

				break;
			case 3:
				worker = new Boss(newid, newname, newdeid);

				break;
			default:
				break;
			}

			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;

			//�������ݵ��ļ�
			this->Save();
		}

		else{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}

	}
	system("pause");
	system("cls");
}

//����ְ��
void workerManager::Find_Emp(){
	//������Ҫ�жϸ��ļ��Ƿ����
	if (this->m_FileIsEmpty){
		cout << "���ļ������ڻ��¼Ϊ�գ�" << endl;
	}

	else{
		cout << "��������ҷ�ʽ�� " << endl;
		cout << "1��ְ����Ų��� " << endl;
		cout << "2.��ְ���������� " << endl;

		int select = 0;
		cin >> select;
		
		if (select == 1){
			//����Ų���
			int id;
			cout << "������Ҫ���ҵ�ְ����ţ� " << endl;
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1){
				//�ҵ�ְ��
				cout << "���ҳɹ�����ְ����Ϣ���£� " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2){
			//����������
			string name;
			cout << "��������ҵ������� " << endl;
			cin >> name;

			//���һ���Ƿ���ҵĵı�־
			bool flag = false;//Ĭ��δ�ҵ�ְ��


			for (int i = 0; i < this->m_EmpNum; ++i){
				if (this->m_EmpArray[i]->m_Name == name){
					cout << "���ҳɹ���ְ�����Ϊ�� " << this->m_EmpArray[i]->m_Id
						<< " �ŵ�ְ����Ϣ���£� " << endl;

					flag = true;
					this->m_EmpArray[i]->showInfo();
					
				}
			}

			if (flag == false){
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}

		}
		else{
			cout << "��������" << endl;
		}
	}
	system("pause");
	system("cls");
}


//��ְ���������
void workerManager::Sort_Emp(){
	//���ж��ļ��Ƿ����
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ����Ž�������" << endl;
		cout << "2����ְ����Ž��н���" << endl;

		int select = 0;
		cin >> select;

		//����һ��ѡ�������㷨
		for (int i = 0; i < this->m_EmpNum; ++i)
		{
			int minOrmax = i;//����һ����Сֵ �� һ�����ֵ��ÿ�δ������Сֵ�������ֵ��ʼ����ͬʱ���������������Ĵ����Ǻ��кô���
			for (int j = i + 1; j < this->m_EmpNum; ++j)
			{
				if (select == 1)
				{
					//��ʱ�û�ѡ����������
					if (this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}

				else if (select == 2)
				{
					//��ʱ�û�ѡ��������
					if (this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}
			}

			//�ж� minOrmax�����ڲ�forѭ��֮���Ƿ����˸ı䣬��������˸ı䣬˵���ҵ��˱�ԭ��minOrmax�����ʵ��±꣬��ô��Ҫ������н���
			if (minOrmax != i)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
		cout << "����ɹ��������Ľ�����£� " << endl;
		this->Save();//�������Ľ�����浽�ļ�����
		this->Show_Emp();//��ʽ����ְ����Ϣ

	}
}


//����ļ�
void workerManager::Clean_File()
{
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	//��һ��if����ɾ���ļ��е�����
	if (select == 1)
	{
		//˵���û���ȷ������ļ��������� ios::trunc - ɾ���ļ�֮�������´������ļ�
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		//�ڶ���if����ɾ�����������������
		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; ++i)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			//ɾ������������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;

	}

	system("pause");
	system("cls");
}

workerManager::~workerManager(){
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; ++i)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				//ɾ��������ÿ��ְ������
				delete this->m_EmpArray[i];//������鲻Ϊ��,���������ڵĳ�ԱҲ��Ϊ�գ����Ƚ������ڵ�ÿһ����Ա���ͷŵ�
				this->m_EmpArray[i] = NULL;
			}
		}

		//�������� �ڲ���Ա�����ٵĿռ��ͷŸɾ�֮�����ͷ�����Ŀռ�
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}