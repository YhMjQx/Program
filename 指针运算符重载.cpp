#include<iostream>
using namespace std;
class DBHelper{
public:
	DBHelper(){
		cout << "DBHepler..." << endl;
	}

	~DBHelper(){
		cout << "~DBHepler..." << endl;
	}

	void Open(){
		cout << "Open..." << endl;
	}

	void Query(){
		cout << "Query..." << endl;
	}

	void Close(){
		cout << "Close..." << endl;
	}
};
class DB{
public:
	DB(){
		//��̬���ݲ����ڳ�ʼ���б��н��г�ʼ��
		db_ = new DBHelper;
	}

	~DB(){
		delete db_;
	}

	//ָ�����������
	DBHelper* operator->(){
		return db_;
	}
private:
	DBHelper* db_;
};

//DB�����Ķ����������ָ��DBHelper��ָ�룬������������ָ�룬����Ч�ض����ݽ��з�װ
//���Һ����ľ����ͷ�DBHepler������󣬵�DB�����������ھͻ��Զ����������������Ӷ��Զ�����DBHelper�ڶ��Ͽ��ٵĿռ�

int main(){
	DB db;
	db->Open();
	db->Query();
	db->Close();

	return 0;
}