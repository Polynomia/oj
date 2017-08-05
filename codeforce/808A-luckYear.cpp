/*************************************************************************
    > File Name: luckYear.cpp
    > Author: Polynomia
    > Mail: wyrsjtu@163.com 
    > Created Time: 日  7/16 14:15:34 2017
 ************************************************************************/

// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
// 	int a,lg,b;
// 	lg=0;
// 	cin>>a;
// 	b=a;
// 	if(a==0){cout<<1;return 0;}
// 	while(b>0){
// 		b/=10;
// 		lg++;}
// 	b=1;
// 	b=int(pow(10,lg-1));
// 	//for(int i=0;i<lg;i++){b*=10;}
// 	int ans=b-a%b;
// 	cout<<ans;
// 	return 0;
// }
#include<cstdio>
int main()
{
    int n,ans = 1;
    scanf("%d",&n);
    int m = n;
    while(m >= 10)
        ans *= 10,m /= 10;
    ans *= m % 10 + 1;
    printf("%d\n",ans - n);
    return 0;
}
