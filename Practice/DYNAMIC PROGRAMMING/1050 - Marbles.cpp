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

#define MX1     100000
#define MX2     1000000
#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

double dp[501][501];

double Marbles(lli R,lli B)
{
    if(R<=0 and B<=0) return 0.0;
    if(R<=0 and B>0) return 1.0;
    if(B<=0 and R>0) return 0.0;

    if(dp[R][B]>=0.0) return dp[R][B];

    double Sum=0;

    Sum=((R*1.0)/(R+B))*Marbles(R-1,B-1)+((B*1.0)/(R+B))*Marbles(R,B-2);

    dp[R][B]=Sum;

    return Sum;//dp[R][B];
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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/

    lli T,t=1;
    cin>>T;

    lli i,j;
    rep(i,0,500+1)
    {
        rep(j,0,500+1)
        {
            dp[i][j]=-1.0;
        }
    }
    rep(i,0,500+1)
    {
        rep(j,0,500+1)
        {
            dp[i][j]=Marbles(i,j);
        }
    }
    while(T--)
    {
        lli R,B;
        cin>>R>>B;

        cout<<"Case "<<t++<<": ";

        cout<<setprecision(10)<<dp[R][B]<<endl;
    }






 return 0;
}
