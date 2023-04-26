#include<iostream>
#include<fstream>
using namespace std;

//文本文件 - 写文件
void test1(){
	//创建流对象
	ofstream ofs;

	//指定打开方式
	ofs.open("test.txt",ios::out);

	//写内容
	ofs << "姓名：杨明强" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	ofs << "---------------------" << endl;
	ofs << "姓名：胡佳欣" << endl;
	ofs << "性别：女" << endl;
	ofs << "年龄：18" << endl;

	//关闭文件
	ofs.close();

}

int main(){

	test1(); 
	return 0;
}