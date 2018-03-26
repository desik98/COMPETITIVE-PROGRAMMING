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

vector<lli>V[101];
bool visited[101];
bool visited1[101];
lli level[101];
lli level1[101];
lli S,D;
lli N;

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

void bfs1(lli x)
{
    lli i;
    queue<lli>Q;

    visited1[x]=1;
    Q.push(x);

    while(!Q.empty())
    {
        lli x=Q.front();
        Q.pop();

        rep(i,0,V[x].sz())
        {
            if(!visited1[V[x][i]])
            {
                Q.push(V[x][i]);
                visited1[V[x][i]]=1;

                level1[V[x][i]]=level1[x]+1;
            }
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
        lli N,M,i;
        cin>>N>>M;

        while(M--)
        {
            lli x,y;
            cin>>x>>y;

            V[x].pb(y);
            V[y].pb(x);
        }

        cin>>S>>D;

        bfs(S);
        bfs1(D);

        lli Minimum=-Inf;
        rep(i,0,N)
        {
            Minimum=max(Minimum,level[i]+level1[i]);
        }

        cout<<"Case "<<t++<<": ";
        cout<<Minimum;

        nl;

        rep(i,0,N)
        {
            V[i].clear();
            visited1[i]=0;
            visited[i]=0;
            level1[i]=0;
            level[i]=0;
        }
    }




 return 0;
}
