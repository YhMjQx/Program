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
		//动态数据不能在初始化列表中进行初始化
		db_ = new DBHelper;
	}

	~DB(){
		delete db_;
	}

	//指针运算符重载
	DBHelper* operator->(){
		return db_;
	}
private:
	DBHelper* db_;
};

//DB创建的对象的数据是指向DBHelper的指针，这类似于智能指针，可有效地对数据进行封装
//并且很灵活的就能释放DBHepler这个对象，当DB出了生命周期就会自动调用析构函数，从而自动销毁DBHelper在堆上开辟的空间

int main(){
	DB db;
	db->Open();
	db->Query();
	db->Close();

	return 0;
}