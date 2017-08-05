#include<cstdio>
#include<math.h>
int main()
{
	double n,h;
	double x;
	scanf("%lf%lf",&n,&h);
	for (int i=1;i<n;i++){
		x = sqrt(i/n)*h;
		printf("%.9f ",x);
	}
	return 0;
}
