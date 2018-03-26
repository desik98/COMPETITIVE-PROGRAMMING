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

lli Array[101];
lli Prefix[101];
lli Value=-MX2*100LL;
lli dp[101][101];

lli Easy_Game(lli x,lli y)
{
    if(x > y)
    {
        return 0;
    }

    if(x == y)
    {
        return Array[x];
    }

    if(dp[x][y] == Value)
    {
        lli Max=-Inf,i;

        rep(i,x,y+1)
        {
            if(x == 0)
            {
                Max = max(Max,Prefix[i]-Easy_Game(i+1,y));
            }
            else
            {
                Max = max(Max,Prefix[i]-Prefix[x-1]-Easy_Game(i+1,y));
            }
        }

        rep(i,x,y+1)
        {
            if(i > 0)
            {
                Max = max(Max,Prefix[y]-Prefix[i-1]-Easy_Game(x,i-1));
            }
            else
            {
                Max = max(Max,Prefix[y]-Easy_Game(x,i-1));
            }
        }

        dp[x][y] = Max;
    }

    return dp[x][y];
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
    //opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli N,i,j;
        sf(N);

        rep(i,0,N)
        {
            rep(j,0,N)
            {
                dp[i][j]=Value;
            }
        }

        rep(i,0,N)
        {
            sf(Array[i]);
        }

        Prefix[0]=Array[0];
        rep(i,1,N)
        {
            Prefix[i]=Prefix[i-1]+Array[i];
        }

        printf("Case %lld: %lld\n",t++,Easy_Game(0,N-1));
    }







 return 0;
}
