#include<cstdio>
#include<iostream>
using namespace std;

int a[1005],b[1005],freq[1005];
int main(){
	int i,y,n,x,j,cnt;
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		scanf("%d",a+i);
		freq[a[i]]++;
	}
	for(i = 0; i < n; i++){
		scanf("%d",b+i);
		if(freq[i+1] == 0)
			y = i+1;
		if(freq[i+1] == 2)
			{x = i+1;}
	}
	for(i = 0; i < n; i++){
		cnt = 0;
		if(a[i] == x){
			a[i] = y;
			for(j = 0; j < n; j++){
				if(a[j]!=b[j])
					cnt++;
			}
		}
		if(cnt==1)for(int k = 0; k < n;k++)	
			printf("%d ",a[k]);
		if (cnt == 1)return 0;
		if(a[i]==y)	
			a[i] = x;
	}
	return 0;
}
