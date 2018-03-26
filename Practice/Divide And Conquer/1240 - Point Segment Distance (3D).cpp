/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			 printf("\n")
#define nl			 cout<<'\n'
#define sf(N)        scanf("%lld",&N)
#define pf(N)        printf("%lld",N)
#define sf1(N1,N2)    scanf("%lld %lld",&N1,&N2)
#define pf1(N1,N2)    printf("%lld %lld",N1,N2)
#define sf2(N1,N2,N3) scanf("%lld %lld %lld",&N1,&N2,&N3)
#define pf2(N1,N2,N3) printf("%lld %lld %lld",N1,N2,N3)

#define sl          cout<<' '
#define ps          printf(" ")

#define rep(i,a,b)	for(i=a;i<b;i++)
#define repr(i,a,b)	for(i=a;i>b;i--)
#define elif		else if
#define mset(a,b)	memset(a,b,sizeof(a))

#define pb		push_back
#define pob		pop_back
#define itr		iterator
#define sz()	size()
#define szof    sizeof
#define lb		lower_bound
#define ub		upper_bound
#define mp		make_pair
#define vlli    vector<lli>
#define plli	pair<lli,lli>
#define vplli	vector<plli >
#define F   	first
#define S		second
#define Dup     erase(unique(V.begin(),V.end()),V.end())

#define bs      binary_search
#define ub      upper_bound
#define lb      lower_bound

#define ALL(V)  V.begin(),V.end()

#define MX1     100000LL
#define MX2     1000000LL
#define Inf     1000000000000000LL
#define mod		1000000007LL
using namespace std;

lli x[2],y[2],z[2],p1,p2,p3;

double Calc(double Slope)
{
    double Sum=0;

    Sum+=(x[0]+(x[1]-x[0])*Slope-p1)*(x[0]+(x[1]-x[0])*Slope-p1);
    Sum+=(y[0]+(y[1]-y[0])*Slope-p2)*(y[0]+(y[1]-y[0])*Slope-p2);
    Sum+=(z[0]+(z[1]-z[0])*Slope-p3)*(z[0]+(z[1]-z[0])*Slope-p3);

    return Sum;
}

lli Power(lli a,lli b)
{
    lli result=1;

    while(b)
    {
        if(b%2)
        {
            result=(result*a)%mod;
        }

        b=b>>1;
        a=(a*a)%mod;
    }

 return result;
}

int main()
{
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli i;

        rep(i,0,2)
        {
            sf2(x[i],y[i],z[i]);
        }

        sf2(p1,p2,p3);

        double low=0,high=1,Store;

        while(high-low >= 0.000000001)
        {
            double mid1=(2*low+high)/3,mid2=(low+2*high)/3;

            if(Calc(mid1) < Calc(mid2))
            {
                high=mid2;
                Store=mid2;
            }
            else
            {
                low=mid1;
                Store=mid1;
            }
        }

        printf("Case %lld: %.8lf\n",t++,sqrt(Calc(Store)));
    }








 return 0;
}
