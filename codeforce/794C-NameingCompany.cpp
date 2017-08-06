#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n,index,index_a,index_b;
	char a[300300],b[300300],c[300300];
	scanf("%s",a);
	scanf("%s",b);
	n = strlen(a);
	sort(a,a+n);
    sort(b,b+n);
    reverse(b,b+n);
	int rb = (n>>1)-1;
	int ra = n - rb-2;
	int l = n-1;
	c[n]=0;
	index = index_a = index_b = 0;
	for(int i=0;i<n;i++){
		if(a[index_a]>=b[index_b]){
			c[l--]=(i&1)?b[rb--]:a[ra--];
		}
		else{
			c[index++] =(i&1)?b[index_b++]:a[index_a++];
		}
	}
	cout<<c<<endl;
	return 0;
}
