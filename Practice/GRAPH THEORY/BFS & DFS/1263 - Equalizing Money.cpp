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
lli N;
lli Cost[1001];
lli Sum;
lli cnt;

void dfs(lli x)
{
    visited[x]=1;

    Sum+=Cost[x];
    cnt++;

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

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli M,i;
        cin>>N>>M;

        rep(i,1,N+1)
        {
            cin>>Cost[i];
        }

        while(M--)
        {
            lli x,y;
            cin>>x>>y;

            V[x].pb(y);
            V[y].pb(x);
        }

        lli Avg=-1;
        I flag=1;

        rep(i,1,N+1)
        {
            if(!visited[i])
            {
                Sum=0;
                cnt=0;

                dfs(i);

                if(Sum%cnt)
                {
                    flag=0;
                    break;
                }

                if(Avg==-1)
                {
                    Avg=Sum/cnt;
                }
                else
                {
                    if(Avg!=Sum/cnt)
                    {
                        flag=0;
                        break;
                    }
                }
            }
        }

        cout<<"Case "<<t++<<": ";
        if(flag)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }

        nl;


        rep(i,1,N+1)
        {
            V[i].clear();
            visited[i]=0;
        }


    }





 return 0;
}
