#include <stdio.h>

int main() 
{
    int M = 0;
    printf("请输入想测试的数字(1<=M<=100000):>\n");
    scanf("%d",&M);
    if(M%5==0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
