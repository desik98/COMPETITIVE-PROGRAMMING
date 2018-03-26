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

#define Inf     100000000000
#define mod     100000007
using namespace std;

vlli V;
vlli FACT(2000010);

void Precompute()
{
    lli i;

    FACT[0]=1;

    rep(i,1,2000010)
    {
        FACT[i]=(FACT[i-1]*i)%mod;
    }
}

lli Power1(lli a,lli b)
{
    lli result=1;

    while(b)
    {
        if(b%2)
        {
            result=(result*a);
        }

        b=b>>1;
        a=(a*a);
    }

 return result;
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

void Precompute1()
{
    lli i,j;

    for(i=2;i<=100000;i++)
    {
        j=2;

        while(Power1(i,j)<=10000000001L)
        {
            V.push_back(Power1(i,j));

            j++;
        }
    }

    sort(V.begin(),V.end());

    set<lli>s(V.begin(),V.end());
    set<lli>::itr it;

    V.clear();

    for(it=s.begin();it!=s.end();++it)
    {
        V.pb(*it);
    }

    /*rep(i,0,10)
    {
        cout<<V[i]<<' ' ;
    }*/
}


int main()
{
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    Precompute();
    Precompute1();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli a,b;
        cin>>a>>b;

        cout<<"Case "<<t++<<": ";

        lli i;

        lli Sum=0;

        lli x,y;

        Sum=upper_bound(V.begin(),V.end(),b)-lower_bound(V.begin(),V.end(),a);

        if(!Sum)
        {
            cout<<0;
            nl;

            continue;
        }

        lli Val1=FACT[2*Sum];
        lli Val2=(FACT[Sum+1]*FACT[Sum])%mod;

        lli Val=(Val1*Power(Val2,mod-2))%mod;

        cout<<Val;
        nl;
    }






 return 0;
}
