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

lli dp[1<<16][21];
lli base,K;
string s;
lli arr[256];

lli Fun(lli mask,lli rem)
{
    if(mask == (1<<s.length())-1 )
    {
        return !rem;
    }

    if(dp[mask][rem] == -1)
    {
        lli j,Sum=0;

        rep(j,0,s.length())
        {
            if(!(mask&(1<<j))) // == 0)
            {
                Sum+=Fun(mask|(1<<j),(rem*base+arr[s[j]])%K);
            }
        }

        dp[mask][rem]=Sum;
    }

    return dp[mask][rem];
}

void Precompute()
{
    lli i;
    rep(i,0,10)
    {
        arr[i+'0']=i;
    }

    arr['A']=10;
    arr['B']=11;
    arr['C']=12;
    arr['D']=13;
    arr['E']=14;
    arr['F']=15;
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

    Precompute();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli i,j;
        cin>>base>>K;

        cin>>s;

        cout<<"Case "<<t++<<": ";

        memset(dp,-1,szof(dp));

        cout<<Fun(0,0);
        nl;

        /*rep(i,0,1<<s.length())
        {
            rep(j,0,K+1)
            {
                cout<<dp[i][j]<<' ';
            }
            nl;
        }

        nl;*/
    }




 return 0;
}
