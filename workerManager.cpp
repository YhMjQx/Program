#include"workerManager.h"

workerManager::workerManager(){
	//��ʼ������
	this->m_EmpNum = 0;

	this->m_EmpArray = NULL;
}

workerManager::~workerManager(){

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