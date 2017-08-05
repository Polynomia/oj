#include<cstdio>

int main()
{	
	int a,b,c,n,ans=0;
	scanf("%d%d%d",&a,&b,&c);
	for(scanf("%d",&n);n>0;n--){
		scanf("%d",&a);
		ans+=(a>b)&&(a<c)?1:0;
	}
	printf("%d",ans);
	return 0;
}
