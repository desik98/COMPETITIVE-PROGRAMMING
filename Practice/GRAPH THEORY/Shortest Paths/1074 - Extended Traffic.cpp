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
#define F   	first
#define S		second

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vector<plli>V[201];
lli N;
lli dist[201];
bool visited[201];

void BellMan_Ford()
{
    lli i,j,k;

    rep(i,0,N+1)
    {
        dist[i]=Inf;
    }

    dist[1]=0;

    rep(i,1,N)
    {
        lli cnt=0;
        rep(j,1,N+1)
        {
            rep(k,0,V[j].sz())
            {
                if(dist[V[j][k].F]>dist[j]+V[j][k].S)
                {
                    dist[V[j][k].F]=dist[j]+V[j][k].S;
                    cnt++;
                }
            }
        }

        if(cnt)
        {
            continue;
        }
        else
        {
            break;
        }
    }
}

void dfs(lli x)
{
    lli i;
    visited[x]=1;

    rep(i,0,V[x].sz())
    {
        if(!visited[V[x][i].F])
        {
            dfs(V[x][i].F);
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
    opt;

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli i,j;
        cin>>N;

        lli a[N+1];
        rep(i,1,N+1)
        {
            cin>>a[i];
        }

        lli M;
        cin>>M;

        while(M--)
        {
            lli x,y,w;
            cin>>x>>y;

            w=Power(a[y]-a[x],3);
            V[x].pb(mp(y,w));
        }

        dfs(1);
        BellMan_Ford();

        cout<<"Case "<<t++<<":";
        nl;

        lli q;
        cin>>q;

        while(q--)
        {
            lli x;
            cin>>x;

            if(!visited[x])
            {
                cout<<'?';
                nl;

                continue;
            }

            if(dist[x]<3)
            {
                cout<<'?';
            }
            else
            {
                cout<<dist[x];
            }
            nl;
        }

        rep(i,1,N+1)
        {
            V[i].clear();
            visited[i]=0;
            dist[i]=0;
        }
    }



 return 0;
}
