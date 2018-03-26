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
#define Frst	first
#define Sec		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

vlli V[1000001];
bool visited[1000001];
lli level[1000001];

void bfs(lli x)
{
    visited[x]=1;

    queue<lli>Q;
    Q.push(x);

    lli i;

    while(!Q.empty())
    {
        x=Q.front();
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

    lli T;
    cin>>T;

    while(T--)
    {
        lli N,i;
        cin>>N;

        lli M;
        cin>>M;

        while(M--)
        {
            lli x,y;
            cin>>x>>y;

            V[x].pb(y);
            V[y].pb(x);
        }

        rep(i,1,N)
        {
            V[i].pb(i+1);
            V[i+1].pb(i);
        }

        lli Sum=0;
        rep(i,1,N+1)
        {
            bfs(i);

            lli j;

            rep(j,i+1,N+1)
            {
                Sum+=level[j];
            }

            rep(j,1,N+1)
            {
                level[j]=0;
                visited[j]=0;
            }
        }

        cout<<Sum;
        nl;

        rep(i,1,N+1)
        {
            V[i].clear();
            visited[i]=0;
            level[i]=0;
        }
    }



 return 0;
}
