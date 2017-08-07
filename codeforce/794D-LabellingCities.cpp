#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int N = 3e5+5;
int main()
{	
	vector< vector<int> > ve(N);
	int hash[N],p[N],visted[N],used[N],label[N],n,m,i,u,v;
    vector<int>::iterator it;
    vector< vector<int> >::iterator iter;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)p[i]=p[i-1]*3;
	for(i=1;i<=n;i++)hash[i]=p[i];
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		ve[u].push_back(v);
		hash[u]+=p[v];
	}
	
	return 0;
}
