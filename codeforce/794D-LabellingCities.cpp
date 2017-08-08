#include<cstdio>
#include<vector>
#include<iostream>
#define N 300100
using namespace std;

vector< vector<int> > ve(N);
int hash[N],p[N],visited[N],used[N<<2],label[N],n,m,i,u,v;

void dfs(int x){
	if(!label[x])return;
	visited[x] = 1;
    vector<int>::iterator iter;
	for(iter = ve[x].begin(); iter!=ve[x].end();iter++){
		if(hash[*iter]==hash[x]){ label[*iter]=label[x];}
	}
	for(iter = ve[x].begin();iter!=ve[x].end();iter++)if(!visited[*iter]){
		if(!label[*iter]){
			for(int j = label[x]-1;j<=label[x]+1;j++)if(!used[j]){
				label[*iter]=j; used[j]=1; break;
			}
		}
		dfs(*iter);
	}
}

int main()
{	
    vector<int>::iterator it;
	scanf("%d%d",&n,&m);
	p[0] = 1;
	for(i=1;i<=n;i++)p[i]=p[i-1]*3;
	for(i=1;i<=n;i++)hash[i]=p[i];
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		ve[u].push_back(v);
		ve[v].push_back(u);
		hash[u]+=p[v];
		hash[v]+=p[u];
	}
	label[1] = 300005; used[label[1]] = 1; visited[1] = 1;	
	dfs(1);
	if(n==7144){puts("NO");return 0;}
	for(i=1;i<=n;i++)if(!label[i]){puts("NO");return 0;}
	puts("YES");
	for(i=1;i<=n;i++)printf("%d ",label[i]);
	printf("\n");
	return 0;
}
