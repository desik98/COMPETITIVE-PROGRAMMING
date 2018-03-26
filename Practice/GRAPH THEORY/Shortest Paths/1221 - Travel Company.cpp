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

vector<plli>V[201];
lli N;
lli dist[201];

bool BellMan_Ford()
{
    lli i,j,k;

    rep(i,0,N+1)
    {
        dist[i]=Inf;
    }

    dist[0]=0;

    rep(i,1,N)
    {
        lli cnt=0;
        rep(j,0,N)
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
            if(i==N-1)
            {
                return 1;
            }

            continue;
        }
        else
        {
            break;
        }
    }

    return 0;
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

        lli M;
        cin>>M;

        lli P;
        cin>>P;

        while(M--)
        {
            lli x,y,w,z;
            cin>>x>>y>>w>>z;

            V[x].pb(mp(y,z*P-w));
        }

        bool Check_Variable=BellMan_Ford();

        cout<<"Case "<<t++<<": ";

        if(Check_Variable)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        nl;

        rep(i,0,N+1)
        {
            V[i].clear();
            dist[i]=0;
        }
    }



 return 0;
}
