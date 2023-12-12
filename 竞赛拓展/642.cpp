
//模拟数字求和

#include <bits/stdc++.h>
using namespace std;

#define LEN 1001//假定该程序处理的数据都是小于1000位的.
/*最长位数1001是为了安全.*/

struct hp{
    char str[LEN];
    int a[LEN];
};//创建结构体hp（high-precision）
//注意使用指针，这样来通过指针形参修改传入的实参.
void init(struct hp *x)//hp初始化函数
{
	for(int i = 0; i < LEN; ++i)
	{
		x->a[i] = 0;
		x->str[i] = '\0';
	}
}
void in(struct hp *x)//输入函数.
{
    scanf("%s", &x->str);
    int len = strlen(x->str);
    for(int i = 0; i < len; ++i)
        x->a[i] = x->str[len - i - 1] - '0';
}
void add(struct hp x, struct hp y, struct hp* ans)//加法函数
{
    int len = 0;
    if(strlen(x.str) > strlen(y.str))
        len = strlen(x.str);
    else len = strlen(y.str);
    for(int i = 0; i < len; ++i)
    {
        ans->a[i] += x.a[i] + y.a[i];
        while(ans->a[i] >= 10)
        {
            ans->a[i] -= 10;
            ans->a[i + 1]++;
        }
    }
}
void show(struct hp ans)//输出函数
{
    int j = LEN - 1;//数组有LEN位，其最后一个下标是LEN-1.
    while(ans.a[j] == 0 && j >= 1)
        --j;//跳过所有前导0.
        /*注：为了确保能输出结果0，前导0最多跳到第一位，
        不检查第0位是否为0，因此加了条件j >= 1.*/
       //现在，j的值是我们要输出的这个结果的最大位的下标.
    while(j >= 0)
    {
        printf("%d", ans.a[j]);
        --j;
    }
    printf("\n");
}
int main()
{
    struct hp x, y, ans;
    init(&x);
    init(&y);
    init(&ans);
    in(&x);
    in(&y);
    add(x, y, &ans);
    show(ans);
    return 0;
}

