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
#define F   	first
#define S		second

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vector<pair<lli,plli> > V,V1;
vlli id,Size;
lli N;

void Initialize()
{
    lli i;

    rep(i,0,N+1)
    {
        id.pb(i);
        Size.pb(1);
    }
}

lli root(lli x)
{
    while(id[x]!=x)
    {
        x=id[id[x]];
    }

 return x;
}

void Union(lli x,lli y)
{
    lli root_x=root(x);
    lli root_y=root(y);

    if(Size[root_x]<Size[root_y])
    {
        Size[root_y]+=Size[root_x];
        id[root_x]=root_y;
    }
    else
    {
        Size[root_x]+=Size[root_y];
        id[root_y]=root_x;
    }
}

lli Kruskal()
{
    lli i,j;
    Initialize();

    lli Cost=0;
    rep(i,0,V.sz())
    {
        lli w=V[i].F;
        lli x=V[i].S.F;
        lli y=V[i].S.S;

        if(root(x)!=root(y))
        {
            Union(x,y);
            Cost+=w;
        }
    }

    id.clear();
    Size.clear();

    Initialize();

    rep(i,0,V1.sz())
    {
        lli w=-V1[i].F;
        lli x=V1[i].S.F;
        lli y=V1[i].S.S;

        if(root(x)!=root(y))
        {
            Union(x,y);
            Cost+=w;
        }
    }


 return Cost;
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
       cin>>N;

       lli x,y,w,i;
       cin>>x>>y>>w;

       while(!(!x && !y && !w))
       {
           V.pb(mp(w,mp(x,y)));
           V1.pb(mp(-w,mp(x,y)));

           cin>>x>>y>>w;
       }

       sort(V.begin(),V.end());
       sort(V1.begin(),V1.end());

       lli Val=Kruskal();

       cout<<"Case "<<t++<<": ";
       if(Val%2)
       {
           cout<<Val<<'/'<<'2';
       }
       else
       {
           cout<<Val/2;
       }
       nl;

       V.clear();
       V1.clear();
       id.clear();
       Size.clear();
    }




 return 0;
}
