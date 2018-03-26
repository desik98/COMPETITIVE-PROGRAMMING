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

lli dp[501][501];
lli Powers_Numbers[501][501];
vlli Prime;
bool isprime[4001];

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

void Sieves()
{
    lli N=4000,i,j;

    Prime.pb(0);
    for(i=2*2;i<=N;i+=2)
    {
        isprime[i]=1;
    }

    lli z=sqrt(N);

    for(i=3;i<=z;i+=2)
    {
        if(isprime[i])
        {
            continue;
        }

        for(j=2*i;j<=N;j+=i)
        {
            isprime[j]=1;
        }
    }

    rep(i,2,N+1)
    {
        if(!isprime[i])
        {
            Prime.pb(i);
        }
    }
}

void Precompute_Powers()
{
    lli P=500,K=500,i,j;

    rep(i,1,P+1)
    {
        Powers_Numbers[i][0]=1LL;
        lli Value=1LL;

        rep(j,1,K+1)
        {
            Powers_Numbers[i][j]=Value;

            Value*=Prime[i];
            Value%=mod;
        }
    }
}

void Precompute_dp_table()
{
    lli P=500,K=500,i,j,k;

    dp[1][0]=1;
    rep(i,1,K+1)
    {
        dp[1][i]=Powers_Numbers[1][i];
    }

    rep(i,2,P+1)
    {
        dp[i][0]=1LL;

        rep(j,i,K+1)
        {
            rep(k,1,j-i+2)
            {
                lli x=(dp[i-1][j-k]*Powers_Numbers[i][k])%mod;
                x=(x*(Prime[i]-1))%mod;

                dp[i][j]=(dp[i][j]+x)%mod;
            }
        }
    }
}


int main()
{
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    Sieves();
    Precompute_Powers();
    Precompute_dp_table();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli K,P;
        cin>>K>>P;

        cout<<"Case "<<t++<<": "<<dp[P][K]<<'\n';
    }





 return 0;
}
