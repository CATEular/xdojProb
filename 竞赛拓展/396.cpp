//图灵机模拟

#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j=0,b;
	scanf("%d",&n);
	char yz[n][21]={'\0'},xz[n][21]={'\0'},ip[n],op[n],md[n],sr[101]={'\0'};
	for(i=0;i<n;i++) scanf("%s %c %c %c %s",yz[i],&ip[i],&op[i],&md[i],xz[i]);
	scanf("%s",sr);
	i=99;
	while(sr[i]!='*') i--;
	i--;
	b=1;
	back:
		j=0;
	    while(!(strcmp(xz[b],yz[j])==0&&ip[j]==sr[i])) j++;
	    sr[i]=op[j];
	    if(md[j]=='R') i--;
	    if(md[j]=='L') i++;
	    b=j;
	    if(strcmp("STOP",xz[j])!=0)
		goto back;
	for(i=0;i<100;i++)
	{
		if(sr[i]<='9'&&sr[i]>='0') printf("%c",sr[i]);
	}
    return 0;
}
