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
#define sl          cout<<' '
#define ps          printf(" ")

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
#define Frst    first
#define Sec     second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000000000
#define mod     1000000007
using namespace std;

lli BIT[200001];
lli N;

void update(lli i,lli Value)
{
    for(;i<=N;i+=i&-i)
    {
        BIT[i]+=Value;
    }
}

lli query(lli i)
{
    lli Sum=0;

    for(;i>0;i-=i&-i)
    {
        Sum+=BIT[i];
    }

 return Sum;
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

    #ifndef ONLINE_JUDGE
    freopen("Diablo.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        memset(BIT,0,szof(BIT));

        lli i,Q;
        cin>>N>>Q;

        lli cnt=0;

        vlli V;
        V.pb(0);

        rep(i,1,N+1)
        {
            lli x;
            cin>>x;

            V.pb(x);
        }
        N+=Q;

        cout<<"Case "<<t++<<":";
        nl;

        rep(i,1,V.sz())
        {
            update(i,1);
        }
        cnt+=V.sz()-1;

        while(Q--)
        {
            char ch;
            cin>>ch;

            lli x;
            cin>>x;

            if(ch=='a')
            {
                V.pb(x);
                update(V.sz()-1,1);

                cnt++;
            }
            else
            {
                if(cnt<x)
                {
                    cout<<"none";
                    nl;

                    continue;
                }

                lli low=1,high=V.sz()-1,ans=V.sz()-1;
                while(low<=high)
                {
                    lli mid=(low+high)/2;

                    if(query(mid)>=x)
                    {
                        ans=min(ans,mid);
                        high=mid-1;
                    }
                    else
                    {
                        low=mid+1;
                    }
                }

                cout<<V[ans];nl;
                update(ans,-1);

                cnt--;
            }
        }

    }




 return 0;
}
