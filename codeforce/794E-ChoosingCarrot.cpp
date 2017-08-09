#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int N = 3e5+100;
int n,a[N],ans[N];
int main(){
	int i,l,r,x;
	scanf("%d",&n);
	for(i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	if(n == 1){
		printf("%d\n",a[1]);
		return 0;
	}
	for(i = 1; i < n;i++){
		x = max(a[i],a[i+1]);
		l = i; r = n - i;
		ans[abs(l-r)] = max(ans[abs(l-r)],x);
	}
	for(i = 2; i < n ;i++){
		x = min(a[i], max(a[i-1],a[i+1]));
		l = i -1; r = n - i;
		ans[abs(l-r)] = max(ans[abs(l-r)],x);
	}
	for(i = 3;i<n;i++){
		ans[i] = max(ans[i],ans[i-2]);
	}
	ans[n-1] = ans[n-2];
	for(i = 0; i < n ; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}
