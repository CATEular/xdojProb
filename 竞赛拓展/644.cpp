
//全排列

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,i;
    scanf("%d",&n);
    int num[n];                         
    for(i=0;i<n;i++)
        num[i]=i+1;
    do{
        for(i=0;i<n;i++)
            printf("%d ",num[i]);        
        printf("\n");
    }while(next_permutation(num,num+n));
    return 0;
}
