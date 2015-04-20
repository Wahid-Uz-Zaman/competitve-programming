#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define i64  long long
i64 X, Y;
    i64 d;
i64 gcd (i64 a, i64 b, i64 &x, i64 &y) {//copy
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	i64 x1, y1;
	i64 d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}



i64 solve(i64 a, i64 b, i64 c, i64 x1, i64 x2, i64 y1, i64 y2)
{

    d= gcd (a, b, X, Y);
    //printf(" a,b,d,x,y= %lld %lld %lld %lld %lld\n", a, b, d, X, Y);


    if (!a && !b){
        if (c!=0)
                return 0;
        return (x2-x1+1)*(i64)(y2-y1+1);

    }

    if (!a){
        if (c%b!=0){
            return 0;
        }
        if (-c/b>=y1 && -c/b<=y2) return (x2-x1+1);
        else return 0;

    }

    if (!b){
        if (c%a!=0){
            return 0;
        }
        if (-c/a>=x1 && -c/a<=x2) return (y2-y1+1);
        else return 0;

    }

    if (c%d!=0) return 0;

    X=X*(-c/d);
    Y=Y*(-c/d);

    double rightx= (X- x1)/ (double)(b/d);//upper bound
    double leftx=  (X- x2)/ (double) (b/d); //lower bound


    double righty= (y2- Y)/ (double) (a/d);
    double lefty=  (y1- Y)/ (double) (a/d);

    if (rightx<leftx)
            swap(rightx, leftx);//now surely upper an dlower bound of t
    if (righty<lefty)
            swap(righty, lefty);

    i64 rightxLL= (i64) floor(rightx);
    i64 rightyLL= (i64) floor(righty);
    i64 leftxLL= (i64) ceil(leftx);
    i64 leftyLL= (i64) ceil(lefty);
    i64 right= min( rightxLL, rightyLL );
    i64 left = max( leftxLL, leftyLL );

    i64 ret= max(0LL, right -left +1);

    return ret;


}


int main(){
    //freopen("in.txt","r",stdin);
   // freopen("outami.txt", "w", stdout);

    i64 cs,csno=1, a, b, c, x1,x2, y1, y2;
    i64 ans;

    cin>>cs;
    while(cs--)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x1, &x2, &y1, &y2);

        ans=solve(a,b,c,x1,x2,y1,y2);

        printf("Case %lld: %lld\n",csno++, ans);
    }



}
