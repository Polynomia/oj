#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[27][1505];
char s[1505];
int main(){
	int c,n,q,i,j,replace,m_i;
	char c_i;
	scanf("%d",&n);
	scanf("%s",s);
	for(c = 0; c < 26; c++){
		for(i = 0; i < n; i++){
			replace = 0;
			for(j = i ; j < n ;j++){
				if(int(s[j]) != 'a'+c){
					replace++;
				}
				a[c][replace] = max(a[c][replace],j-i+1);
			}
		}
		for(i = 1; i <= n; i++)
			a[c][i] = max(a[c][i], a[c][i -1]);
	}
	scanf("%d",&q);
	for(i = 0;i < q; i++){
		scanf("%d %c",&m_i,&c_i);
		printf("%d\n",a[int(c_i)-'a'][m_i]);
	}
	
	return 0;
}
