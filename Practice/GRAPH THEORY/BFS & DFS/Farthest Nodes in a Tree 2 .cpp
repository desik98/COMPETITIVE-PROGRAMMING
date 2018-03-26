/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'

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
#define pii		pair<int,int>
#define pll		pair<li,li>
#define vpi		vector<pii >
#define vpl		vector<pll >
#define F		first
#define S		second

#define mod		1000000007
using namespace std;

vector<pair<lli,lli> >V[100001];
bool visited[100001];
vector<lli>Cost(100001);

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
            if(!visited[V[x][i].first])
            {
                visited[V[x][i].first]=1;
                Q.push(V[x][i].first);

                Cost[V[x][i].first]=Cost[x]+V[x][i].second;
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

    lli T,t;
    cin>>T;

    rep(t,0,T)
    {
        lli N,N1,i,j;
        cin>>N;

        N1=N-1;

        while(N1--)
        {
            lli a,b,w;
            cin>>a>>b>>w;

            V[a].pb(mp(b,w));
            V[b].pb(mp(a,w));
        }

        cout<<"Case "<<t+1<<": ";
        nl;

        rep(i,0,N)
        {
            bfs(i);

            cout<<*max_element(Cost.begin(),Cost.end());
            nl;

            rep(j,0,N)
            {
                visited[j]=0;
                Cost[j]=0;
            }
        }

        rep(i,0,N+1)
        {
            V[i].clear();
            visited[i]=0;
            Cost[i]=0;
        }

    }





 return 0;
}
