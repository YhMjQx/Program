#include"Text.h"
int main(){
	Text t ;
	t.Init();
	t.Init(39);
	//t.Init(&t, 39);隐含的this指针实际上这是这样的，不过被省略了，这样就可以让我的函数精准找到执行对象
	t.Display();
	return 0;
}