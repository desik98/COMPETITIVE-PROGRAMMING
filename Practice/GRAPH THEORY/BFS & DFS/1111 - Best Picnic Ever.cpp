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

vector<lli>V[1001];
bool visited[1001];
lli Count[1001];

void dfs(lli x)
{
    lli i;

    Count[x]++;

    rep(i,0,V[x].sz())
    {
        if(!visited[V[x][i]])
        {
            dfs(V[x][i]);
        }
    }
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
    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli K,N,M,i,j;
        sf(K);
        sf(N);
        sf(M);

        vlli V1(K);
        rep(i,0,K)
        {
            sf(V1[i]);
        }

        while(M--)
        {
            lli x,y;
            sf(x);
            sf(y);

            V[x].pb(y);
        }

        rep(i,0,K)
        {
            rep(j,0,N+1)
            {
                visited[j]=0;
            }

            dfs(V1[i]);
        }

        lli cnt=0;
        rep(i,0,N+1)
        {
            if(Count[i]>=K)
            {
                cnt++;
            }
        }

        printf("Case ");
        pf(t++);
        printf(": ");
        pf(cnt);
        pn;

        rep(i,1,N+1)
        {
            V[i].clear();
            Count[i]=0;
        }
    }




 return 0;
}
