
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

int a[2],b[2],c[2],d[2];

double Calc(double t)
{
    double Sum=0;

    Sum=(c[0]-a[0]+(d[0]-c[0]-b[0]+a[0])*t)*(c[0]-a[0]+(d[0]-c[0]-b[0]+a[0])*t);
    Sum+=(c[1]-a[1]+(d[1]-c[1]-b[1]+a[1])*t)*(c[1]-a[1]+(d[1]-c[1]-b[1]+a[1])*t);

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

    int T,t=1;
    scanf("%d",&T);

    while(T--)
    {
        int i;

        rep(i,0,2)
        {
            scanf("%d",&a[i]);
        }

        rep(i,0,2)
        {
            scanf("%d",&b[i]);
        }

        rep(i,0,2)
        {
            scanf("%d",&c[i]);
        }

        rep(i,0,2)
        {
            scanf("%d",&d[i]);
        }

        double low=0,high=1,Store;

        while(high-low>=0.000000001)
        {
            double mid1=(low*2+high)/3,mid2=(low+2*high)/3;

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

        printf("Case %d: %.8lf\n",t++,sqrt(Calc(Store)));
    }



 return 0;
}
