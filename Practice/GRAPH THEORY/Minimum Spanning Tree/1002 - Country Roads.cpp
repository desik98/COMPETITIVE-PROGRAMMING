/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li      int32_t
#define lli     long long
#define ulli unsigned long long

#define pn          printf("\n")
#define nl          cout<<'\n'
#define sf(N)       scanf("%lld",&N)
#define pf(N)       printf("%lld",N)

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
#define F       first
#define S       second

#define Inf     100000000000
#define mod     1000000007
using namespace std;

vector<plli>V[501];
bool visited[501];
vector<pair<lli,plli> >V1;
lli Source;
vlli id;
vlli Size;
lli N;
lli dp[501];

void Initialize()
{
    lli i;

    rep(i,0,N)
    {
        id.pb(i);
        Size.pb(1);
        dp[i]=-Inf;
    }
}

lli root(lli x)
{
    lli i=x;

    while(id[i]!=i)
    {
        id[i]=id[id[i]];
        i=id[i];
    }

 return i;
}

void Union(lli x,lli y)
{
    lli root_x=root(x);
    lli root_y=root(y);

    if(Size[root_x]<Size[root_y])
    {
        Size[root_y]+=Size[root_x];
        id[root_x]=root_y;
    }
    else
    {
        Size[root_x]+=Size[root_y];
        id[root_y]=root_x;
    }
}

void bfs(lli x)
{
    lli i;
    queue<lli>Q;

    Q.push(x);
    visited[x]=1;

    while(!Q.empty())
    {
        lli x=Q.front();
        Q.pop();

        rep(i,0,V[x].sz())
        {
            if(!visited[V[x][i].F])
            {
                Q.push(V[x][i].F);
                visited[V[x][i].F]=1;

                dp[V[x][i].F]=max(dp[x],V[x][i].S);
            }
        }
    }

}

void Kruskal()
{
    lli i,j;
    Initialize();

    rep(i,0,V1.sz())
    {
        lli w=V1[i].F;
        lli x=V1[i].S.F;
        lli y=V1[i].S.S;

        if(root(x)!=root(y))
        {
            V[x].pb(mp(y,w));
            V[y].pb(mp(x,w));

            Union(x,y);
        }
    }

    dp[Source]=0;

    bfs(Source);

    rep(i,0,N)
    {
        if(dp[i]==-Inf)
            cout<<"Impossible";
        else
            cout<<dp[i];

        nl;
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
        lli M,i;
        cin>>N>>M;

        while(M--)
        {
            lli x,y,w;
            cin>>x>>y>>w;

            V1.pb(mp(w,mp(x,y)));
        }

        sort(V1.begin(),V1.end());

        cin>>Source;

        cout<<"Case "<<t++<<":";
        nl;

        Kruskal();

        rep(i,0,N)
        {
            V[i].clear();
            visited[i]=0;
        }
        V1.clear();
        id.clear();
        Size.clear();
    }




 return 0;
}
