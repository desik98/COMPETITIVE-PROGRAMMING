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

#define MX1     100000
#define MX2     1000000
#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

vlli V,V1,Number;

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

lli f(lli x)
{
    lli Sum=0;

    lli i;
    rep(i,0,V.sz())
    {
        Sum+=abs(x-V[i])*Number[i];
    }

 return Sum;
}

lli f1(lli x)
{
    lli Sum=0;

    lli i;
    rep(i,0,V1.sz())
    {
        Sum+=abs(x-V1[i])*Number[i];
    }

 return Sum;
}

int main()
{
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    #endif // ONLINE_JUDGE
    freopen("double_squares_out.txt","w",stdout);*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli M,i,N,j,Q;
        sf2(M,N,Q);

        rep(i,0,Q)
        {
            lli x,y,w;
            sf2(x,y,w);

            V.pb(x);
            V1.pb(y);
            Number.pb(w);
        }

        printf("Case %lld: ",t++);

        lli low=1,high=M,Store1;

        while(low<=high)
        {
            lli mid=(low+high)/2;

            lli x=f(mid),y=f(mid+1);

            if(x<=y)
            {
                high=mid-1;
                Store1=mid;
            }
            else
            {
                low=mid+1;
                Store1=mid+1;
            }
        }

        low=1,high=N;
        lli Store2;

        while(low<=high)
        {
            lli mid=(low+high)/2;

            lli x=f1(mid),y=f1(mid+1);

            if(x<=y)
            {
                high=mid-1;
                Store2=mid;
            }
            else
            {
                low=mid+1;
                Store2=mid+1;
            }
        }

        pf1(Store1,Store2);
        pn;

        V.clear();
        V1.clear();
        Number.clear();
    }







 return 0;
}
