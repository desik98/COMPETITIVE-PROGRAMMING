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
#define F   	first
#define S		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     10000000000
#define mod		1000000007
using namespace std;

vector<plli >V1[1001];
vector<plli >V[1001];
vector<lli>V4[1001];
bool visited[1001];
lli dist[1001];
bool Check[1001];
bool Check1[1001];
bool Check2[1001];
vlli V3;
lli N;

void dfs(lli x)
{
    V3.pb(x);
    visited[x]=1;

    lli i;

    rep(i,0,V4[x].sz())
    {
        if(!visited[V4[x][i]])
        {
            dfs(V4[x][i]);
        }
    }
}

void Bellman_Ford(lli x)
{
    lli i,j,k;

    dist[x]=0;

    I flag=0;
    rep(i,0,N-1)
    {
        flag=0;
        rep(j,0,N)
        {
            rep(k,0,V[j].sz())
            {
                if(dist[V[j][k].F]>dist[j]+V[j][k].S)
                {
                    dist[V[j][k].F]=min(dist[V[j][k].F],dist[j]+V[j][k].S);
                    flag=1;
                }
            }
        }

        if(!flag)
        {
            return;
        }
    }

        rep(j,0,N)
        {
            rep(k,0,V[j].sz())
            {
                if(dist[V[j][k].F]>dist[j]+V[j][k].S)
                {
                    dist[V[j][k].F]=min(dist[V[j][k].F],dist[j]+V[j][k].S);
                    Check1[V[j][k].F]=1;
                }
            }
        }

}


void Bellman_Ford_1(lli x)
{
    lli i,j,k;

    dist[x]=0;

    I flag=0;
    rep(i,0,N-1)
    {
        flag=0;
        rep(j,0,N)
        {
            rep(k,0,V1[j].sz())
            {
                if(dist[V1[j][k].F]>dist[j]+V1[j][k].S)
                {
                    dist[V1[j][k].F]=min(dist[V1[j][k].F],dist[j]+V1[j][k].S);
                    flag=1;
                }
            }
        }

        if(!flag)
        {
            return;
        }
    }

        rep(j,0,N)
        {
            rep(k,0,V1[j].sz())
            {
                if(dist[V1[j][k].F]>dist[j]+V1[j][k].S)
                {
                    dist[V1[j][k].F]=min(dist[V1[j][k].F],dist[j]+V1[j][k].S);
                    Check2[V1[j][k].F]=1;
                }
            }
        }

}

void Concatenate()
{
    lli i;
    rep(i,0,N+1)
    {
        Check[i]=Check1[i] & Check2[i];
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

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

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

            V[x].pb(mp(y,w));
            V1[y].pb(mp(x,w));
            V4[y].pb(x);
        }

        cout<<"Case "<<t++<<": ";

        rep(i,0,N+1)
        {
            dist[i]=Inf;
        }

        Bellman_Ford(0);

        rep(i,0,N+1)
        {
            dist[i]=Inf;
        }

        Bellman_Ford_1(0);

        Concatenate();

        vlli V2;
        rep(i,0,N+1)
        {
            if(Check[i])
            {
                V2.pb(i);
            }
        }

        if(!V2.sz())
        {
            cout<<"impossible";
            nl;

            continue;
        }

        rep(i,0,V2.sz())
        {
            if(!visited[V2[i]])
            {
                dfs(V2[i]);
            }
        }

        sort(V3.begin(),V3.end());

        rep(i,0,V3.sz())
        {
            cout<<V3[i]<<' ';
        }
        nl;

        rep(i,0,N+1)
        {
            V[i].clear();
            V1[i].clear();
            V4[i].clear();
            Check[i]=0;
            Check1[i]=0;
            Check2[i]=0;
            visited[i]=0;
        }
        V3.clear();
    }




 return 0;
}
