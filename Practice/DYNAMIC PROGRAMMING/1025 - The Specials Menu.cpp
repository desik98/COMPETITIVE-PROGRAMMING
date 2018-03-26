/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'
#define sf(N)       scanf("%lld",&N)
#define pf(N)       printf("%lld",N)
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
#define Frst	first
#define Sec		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

string s;
lli dp[61][61];

lli Solve(lli a,lli b)
{
    if(a>b)
    {
        return 0;
    }

    if(a==b)
    {
        return 1;
    }

    if(dp[a][b]==-1)
    {
        if(s[a]==s[b])
        {
            dp[a][b]=1+Solve(a+1,b)+Solve(a,b-1);
        }
        else
        {
            dp[a][b]=Solve(a+1,b)+Solve(a,b-1)-Solve(a+1,b-1);
        }
    }

 return dp[a][b];
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
    cin>>T;

    while(T--)
    {
        memset(dp,-1,szof(dp));

        cin>>s;

        cout<<"Case "<<t++<<": ";

        lli N=s.length();
        cout<<Solve(0,N-1);
        nl;
    }




 return 0;
}
