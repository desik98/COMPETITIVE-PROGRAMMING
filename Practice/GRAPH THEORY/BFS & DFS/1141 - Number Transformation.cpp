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
vlli V1;
bool visited[1001];
bool visited1[1001];
lli level[1001];
lli S,Target;

void bfs(lli x)
{
    lli i;
    queue<lli>Q;

    visited[x]=1;
    Q.push(x);

    while(!Q.empty())
    {
        lli x=Q.front();
        Q.pop();

        rep(i,0,V[x].sz())
        {
            if(!visited[V[x][i]])
            {
                Q.push(V[x][i]);
                visited[V[x][i]]=1;

                level[V[x][i]]=level[x]+1;
            }
        }
    }
}

void Sieves()
{
    lli i,j;

    lli N=1000;

    rep(i,0,N+1)
    {
        V1.pb(i);
    }

    for(i=2;i<=sqrt(N);i++)
    {
        if(V1[i])
            for(j=2;j<=N/i;j++)
            {
                V1[i*j]=0;
            }
    }
}

void Precompute(lli S)
{
    lli i;

    visited1[S]=1;

    for(i=2;i<=sqrt(S);i++)
    {
        if(S%i==0 && V1[i])
        {
            if(S+i<=Target)
            V[S].pb(S+i);

            if(i*i!=S)
            {
                if(S+S/i<=Target)
                    V[S].pb(S+S/i);
            }

            if(!visited1[S+i] && S+i<=Target)
            {
                Precompute(S+i);
            }

            if(!visited1[S+S/i] && i*i!=S && S+S/i<=Target)
            {
                Precompute(S+S/i);
            }
        }
    }
}

void Initialize()
{
    lli i;

    rep(i,1,1001)
    {
        V[i].clear();
        visited1[i]=0;
        visited[i]=0;
        level[i]=0;
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

    Sieves();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli i,j;
        Initialize();

        cin>>S>>Target;

        if(!(S-1))
        {
            cout<<"Case "<<t++<<": "<<"-1";
        }

        Precompute(S);

        rep(i,1,Target+1)
        {
            if(visited1[i])
            {
                cout<<i<<' ';

                rep(j,0,V[i].sz())
                {
                    cout<<V[i][j]<<' ';
                }
                nl;
            }
        }

        bfs(S);

        if(!level[Target])
        {
            cout<<"Case "<<t++<<": "<<"-1";
        }
        else
        {
            cout<<"Case "<<t++<<": "<<level[Target];
        }
        nl;
    }





 return 0;
}
