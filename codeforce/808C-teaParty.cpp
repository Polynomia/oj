/*************************************************************************
    > File Name: teaParty.cpp
    > Author: Polynomia
    > Mail: wyrsjtu@163.com 
    > Created Time: 五  8/ 4 23:30:45 2017
 ************************************************************************/
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,x,w,a[101],b[101];
	scanf("%d%d",&n,&w);
	for(int i = 0; i<n; i++){
		scanf("%d",&a[i]);
		b[i]=(a[i]+1)>>1;
		w-=b[i];
	}
	int i,max=0;
	if(w<0)return puts("-1"),0;
	while(w){;
		for(i = 0; i<n;i++){
			if(a[i]>a[max])
				max = i;
			}
		x = min(a[max]-b[max],w);
		b[max]+=x;
		a[max]=0;
		w-=x;
	}
	for(int i=0;i<n;++i) printf("%d ",b[i]);
	return 0;
}
