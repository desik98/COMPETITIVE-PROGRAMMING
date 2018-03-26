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

vlli V[50001];
bool visited[50001];
vlli indegree(50001);
priority_queue<plli >Q1;
vlli V1;
lli N;

void Toposort()
{
    lli i,j;

    rep(i,0,N+1)
    {
        indegree[i]=0;
    }

    rep(i,1,N+1)
    {
        rep(j,0,V[i].sz())
        {
            lli x=V[i][j];

            indegree[x]++;
        }
    }

    rep(i,1,N+1)
    {
        Q1.push(mp(-indegree[i],-i));
    }

    /*while(!Q1.empty())
    {
        cout<<-Q1.top().F<<' '<<-Q1.top().S;
        nl;

        Q1.pop();
    }*/

    lli cnt=0;

    while(!Q1.empty())
    {
        plli p=Q1.top();
        lli y=-p.F,x=-p.S;

        Q1.pop();

        if(!visited[x])
        {
            visited[x]=1;
            cnt++;

            V1.pb(x);

            if(cnt==N)
            {
                while(!Q1.empty())
                {
                    Q1.pop();
                }
                break;
            }

            rep(i,0,V[x].sz())
            {
                if(!visited[V[x][i]])
                {
                    lli z=V[x][i];

                    indegree[z]--;

                    Q1.push(mp(-indegree[z],-z));
                }
            }
        }

    }

    /*rep(i,0,V1.sz())
    {
        cout<<V1[i]<<' ';
    }
    nl;*/
}

lli cnt1;

void dfs(lli x)
{
    visited[x]=1;
    cnt1++;

    lli i;
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
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N1,i;
        cin>>N;

        N1=N;

        while(N1--)
        {
            lli x,y;
            cin>>x>>y;

            V[x].pb(y);
        }

        cout<<"Case "<<t++<<": ";

        Toposort();

        rep(i,1,N+1)
        {
            visited[i]=0;
        }

        lli cnt=0,Val=Inf;
        rep(i,0,V1.sz())
        {
            if(!visited[V1[i]])
            {
                cnt1=0;

                dfs(V1[i]);

                if(cnt1>cnt)
                {
                    cnt=cnt1;
                    Val=V1[i];
                }
                elif(cnt1==cnt)
                {
                    Val=min(Val,V1[i]);
                }
            }
        }

        cout<<Val;
        nl;

        rep(i,1,N+1)
        {
            V[i].clear();
            visited[i]=0;
            indegree[i]=0;
        }
        V1.clear();
    }




 return 0;
}
