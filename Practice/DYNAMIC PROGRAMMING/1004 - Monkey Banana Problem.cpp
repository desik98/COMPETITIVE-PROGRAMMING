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

#define Inf     100000000000
#define mod		1000000007
using namespace std;

lli a[202][202];
lli dp[202][202];

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

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,j;
        cin>>N;

        rep(i,0,2*N)
        {
            rep(j,0,N+1)
            {
                a[i][j]=0;
                dp[i][j]=0;
            }
        }

        rep(i,1,N+1)
        {
            rep(j,1,i+1)
            {
                cin>>a[i][j];
                dp[i][j]=a[i][j];
            }
        }

        rep(i,N+1,2*N)
        {
            rep(j,1,2*N-i+1)
            {
                cin>>a[i][j];
                dp[i][j]=a[i][j];
            }
        }

        rep(i,2,N+1)
        {
            rep(j,1,i+1)
            {
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
            }
        }

        rep(i,N+1,2*N)
        {
            rep(j,1,2*N-i+1)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+a[i][j];
            }
        }

        cout<<"Case "<<t++<<": ";
        cout<<dp[2*N-1][1];
        nl;
    }




 return 0;
}
