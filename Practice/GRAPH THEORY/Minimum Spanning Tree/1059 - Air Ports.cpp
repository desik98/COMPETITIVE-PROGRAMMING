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

vlli Size,id;
vector<pair<lli,pair<lli,lli> > >V;
lli N,M,Cos1;

void initialize()
{
    V.clear();
    id.clear();
    Size.clear();

    id.pb(0);
    Size.pb(1);

    lli i;

    rep(i,1,N+1)
    {
        id.pb(i);
        Size.pb(1);
    }
}

lli root(lli x)
{
    while(x!=id[x])
    {
        x=id[id[x]];
    }

 return x;
}

void Union(lli x,lli y)
{
    lli root_x=root(x);
    lli root_y=root(y);

    if(Size[root_x]>=Size[root_y])
    {
        id[root_y]=root_x;
        Size[root_x]+=Size[root_y];
    }
    else
    {
        id[root_x]=root_y;
        Size[root_y]+=Size[root_x];
    }
}

lli Kruskal()
{
    lli i;

    lli Minimum_Cost=0;

    rep(i,0,V.sz())
    {
        lli x=V[i].S.F,y=V[i].S.S,z=V[i].F;

        if(root(x)!=root(y))
        {
            if(z<Cos1)
            {
                Union(x,y);

                Minimum_Cost+=z;
            }
        }
    }

 return Minimum_Cost;
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
        lli i;

        cin>>N>>M>>Cos1;

        initialize();

        while(M--)
        {
            lli x,y,z;
            cin>>x>>y>>z;

            V.pb(mp(z,mp(x,y)));
        }

        cout<<"Case "<<t++<<": ";

        sort(V.begin(),V.end());

        /*nl;
        rep(i,0,V.sz())
        {
            cout<<V[i].S.F<<' '<<V[i].S.S<<' '<<V[i].F;
            nl;
        }*/


        lli Val1=Kruskal();

        lli cnt=0;
        rep(i,1,N+1)
        {
            if(id[i]==i)
            {
                cnt++;
            }
        }

        cout<<Val1+cnt*Cos1<<' '<<cnt;
        nl;
    }



 return 0;
}
