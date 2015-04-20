#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double Sq(double a){return a*a;}
double ABS(double x){return (x<0)?-1*x:x;}
double x,y,c,l,r,mid;
double f(double a)
{
	double v1=sqrt(Sq(x)-Sq(a))*sqrt(Sq(y)-Sq(a)),v2=sqrt(Sq(x)-Sq(a))+sqrt(Sq(y)-Sq(a)),v;
	v=v1/v2;
	return v;
}

int main()
{
	int i,t;
	scanf("%d",&t);
	double Y,ans;
	for(int j=1;j<=t;j++)
	{
	    scanf("%lf%lf%lf",&x,&y,&c);

		l=0;
		r=y;
		for(i=1;i<=300;i++)
		{
			mid=(l+r)/2;
			Y=f(mid);
			if(ABS(c-Y)<1e-6){ans=mid;break;}
			if(c>Y){r=mid;}
			else{l=mid;}
		}
		printf("Case %d: %.6lf\n",j,ans);
	}
	return 0;
}
