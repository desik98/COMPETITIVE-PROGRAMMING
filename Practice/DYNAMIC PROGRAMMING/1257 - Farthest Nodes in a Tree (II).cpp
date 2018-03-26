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

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vector<plli > V[100012];
bool visited[100012];
vlli dist(100012);
vlli Max_Dist(100012);

void bfs(lli x)
{
    visited[x]=1;

    lli i;
    queue<lli>Q;

    Q.push(x);

    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();

        rep(i,0,V[x].sz())
        {
            if(!visited[V[x][i].F])
            {
                visited[V[x][i].F]=1;
                Q.push(V[x][i].F);

                dist[V[x][i].F]=dist[x]+V[x][i].S;
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
    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,M;
        cin>>N;

        M=N-1;

        while(M--)
        {
            lli x,y,w;
            cin>>x>>y>>w;

            V[x].pb(mp(y,w));
            V[y].pb(mp(x,w));
        }

        cout<<"Case "<<t++<<":";
        nl;

        bfs(0);
        lli Maximum=max_element(dist.begin(),dist.begin()+N)-dist.begin();

        rep(i,0,N)
        {
            dist[i]=0;
            visited[i]=0;
        }

        bfs(Maximum);
        Maximum=max_element(dist.begin(),dist.begin()+N)-dist.begin();

        rep(i,0,N)
        {
            Max_Dist[i]=dist[i];
            dist[i]=0;
            visited[i]=0;
        }

        bfs(Maximum);

        rep(i,0,N)
        {
            cout<<max(Max_Dist[i],dist[i]);
            nl;

            Max_Dist[i]=0;
            dist[i]=0;
            V[i].clear();
            visited[i]=0;
        }

    }



 return 0;
}
