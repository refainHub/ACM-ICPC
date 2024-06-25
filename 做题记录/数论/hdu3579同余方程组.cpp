//解同余方程组，也可用中国剩余定理。同hdu1573
#include <cstdio>
#define N 15
__int64 aa[N],rr[N];
__int64 gcd(__int64 a,__int64 b)
{
	return b==0?a:gcd(b,a%b);
}
void exgcd(__int64 a,__int64 b,__int64 &d,__int64&x,__int64 &y)
{
	if(!b)
		x=1,y=0,d=a;
	else
	{
	    exgcd(b,a%b,d,y,x),y-=x*(a/b);
	}

}
int  main()
{
	__int64 n=0,m,a,b,c,d,x0,y0,lcm;
	int ca,i;
	scanf("%d",&ca);
	while(ca--)
	{
		scanf("%I64d",&m);
		bool flag=1;
		lcm=1;
		for(i=1;i<=m;i++)
		{
			scanf("%I64d",&aa[i]);
			lcm=lcm*aa[i]/gcd(lcm,aa[i]);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%I64d",&rr[i]);
		}
		for(i=2;i<=m;i++)
		{
			a=aa[1],b=aa[i],c=rr[i]-rr[1];
			exgcd(a,b,d,x0,y0);
			if(c%d)
			{
				flag=0;
				break;
			}
			__int64 t=b/d;
			x0=(x0*(c/d)%t+t)%t;
			rr[1]=aa[1]*x0+rr[1];
			aa[1]=aa[1]*(aa[i]/d);
		}
		n++;
		printf("Case %I64d: ",n);
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		__int64 ans=0;
		if(rr[1]!=0)
			{
				printf("%I64d\n",rr[1]);
				continue;
			}
		printf("%I64d\n",lcm);
	}
}
