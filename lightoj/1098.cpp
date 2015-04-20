#include <cstdio>
#define llu unsigned long long

int main(void){
	int t,c=0;
	scanf("%d",&t);
	while(c<t)

	{
		llu ans = 0,n;
		scanf("%llu",&n);
		llu i, y, z;
		for(i = 2, y = n; i <= n / i; ++i){
			z = y;
			y = n / i;
			ans += i * (y - 1);
			ans +=(i - 2) * (y + 1 + z) * (z - y) / 2;
		}
		for(;i <= y;i++)
		{

		 ans += i * (n / i - 1);
		}
		printf("Case %d: %llu\n", ++c, ans);
	}
	return 0;
}
