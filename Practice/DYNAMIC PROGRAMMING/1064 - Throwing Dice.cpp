/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			 printf("\n")
#define nl			 cout<<'\n'
#define sf(N)        scanf("%lld",&N)
#define pf(N)        printf("%lld",N)
#define sf1(N1,N2)    scanf("%lld %lld",&N1,&N2)
#define pf1(N1,N2)    printf("%lld %lld",N1,N2)
#define sf2(N1,N2,N3) scanf("%lld %lld %lld",&N1,&N2,&N3)
#define pf2(N1,N2,N3) printf("%lld %lld %lld",N1,N2,N3)

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
#define Dup     erase(unique(V.begin(),V.end()),V.end())

#define bs      binary_search
#define ub      upper_bound
#define lb      lower_bound

#define ALL(V)  V.begin(),V.end()

#define MX1     30001
#define MX2     1000000
#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

vlli V;
lli N;

void Fun(lli x,lli index)
{
    if(index==N)
    {
        V.pb(x);
        return ;
    }

    lli i;
    rep(i,1,7)
    {
        Fun(x+i,index+1);
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
        lli i,x;
        cin>>N>>x;

        cout<<"Case "<<t++<<": ";

        if(N*6<x)
        {
            cout<<0;
            nl;

            continue;
        }

        Fun(0,0);

        sort(V.begin(),V.end());

        /*rep(i,0,V.sz())
        {
            cout<<V[i];sl;
        }
        nl;*/

        lli y=V.sz()-(lower_bound(V.begin(),V.end(),x)-V.begin());
        lli z=V.sz();

        lli a=__gcd(y,z);

        y/=a;
        z/=a;

        cout<<y<<'/'<<z;
        nl;

        V.clear();
    }







 return 0;
}
