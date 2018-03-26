/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li      int32_t
#define lli     long long
#define ulli unsigned long long

#define pn          printf("\n")
#define nl          cout<<'\n'
#define sf(N)       scanf("%lld",&N)
#define pf(N)       printf("%lld",N)
#define sl          cout<<' '
#define ps          printf(" ")

#define rep(i,a,b)  for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define elif        else if
#define mset(a,b)   memset(a,b,sizeof(a))

#define pb      push_back
#define pob     pop_back
#define itr     iterator
#define sz()    size()
#define szof    sizeof
#define lb      lower_bound
#define ub      upper_bound
#define mp      make_pair
#define vlli    vector<lli>
#define plli    pair<lli,lli>
#define vplli   vector<plli >
#define Frst    first
#define Sec     second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     10000000000000000
#define mod     1000000007
using namespace std;

lli dp[101][101][101];
vlli V;
lli N,W;

lli Fun(lli i,lli j,lli K)
{
    if(i>j)
    {
        return 0;
    }

    if(!K)
    {
        return 0;
    }

    if(i==j)
    {
        return 1;
    }

    if(dp[i][j][K]!=-1)
    {
        return dp[i][j][K];
    }

    lli k;

    lli Minimum=0;
    rep(k,i,j+1)
    {
        lli x=upper_bound(V.begin(),V.begin()+j+1,V[k]+W)-V.begin();

        Minimum=max(Minimum,Fun(x,j,K-1)+(x-k));
    }

 return (dp[i][j][K]=Minimum);
}

int main()
{
    lli T,t=1;
    sf(T);

    while(T--)
    {
        memset(dp,-1,szof(dp));

        lli K,i;
        sf(N);
        sf(W);
        sf(K);

        rep(i,0,N)
        {
            lli y,x;
            sf(y);
            sf(x);

            V.pb(x);
        }
        sort(V.begin(),V.end());

        printf("Case ");
        pf(t++);
        printf(": ");

        pf(Fun(0,N-1,K));
        pn;

        V.clear();
    }






 return 0;
}
