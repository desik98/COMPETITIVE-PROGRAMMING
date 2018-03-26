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

#define MX1     100000LL
#define MX2     1000000LL
#define Inf     1000000000000000LL
#define mod		1000000007LL
using namespace std;

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
        lli N,i,j;
        cin>>N;

        map<pair<plli,lli>,lli> U;
        map<pair<lli,lli>,lli> U1,U2;
        map<pair<plli,lli>,lli> :: itr it;
        map<plli,lli> :: itr it1;

        vplli V(N);
        rep(i,0,N)
        {
            cin>>V[i].F>>V[i].S;
        }

        rep(i,0,N)
        {
            rep(j,i+1,N)
            {
                lli a=V[j].S-V[i].S,b=V[j].F-V[i].F;

                lli GCD=__gcd(abs(a),abs(b));

                a/=GCD;
                b/=GCD;

                U[mp(mp(a,-b),a*V[i].F-b*V[i].S)]++;
            }
        }

        for(it=U.begin();it!=U.end();it++)
        {
            cout<<it->F.F.F<<' '<<it->F.F.S<<' '<<it->F.S<<' '<<it->S<<'\n';
            U1[mp(it->F.F.F,it->F.F.S)]+=it->S;
        }

        for(it1=U1.begin();it1!=U1.end();it1++)
        {
            U1[mp(it1->F.F,it1->F.S)]*=U1[mp(it1->F.F,it1->F.S)];
        }

        for(it=U.begin();it!=U.end();it++)
        {
            U1[mp(it->F.F.F,it->F.F.S)]-=it->S*it->S;
        }

        nl;
        for(it1=U1.begin();it1!=U1.end();it1++)
        {
            U1[mp(it1->F.F,it1->F.S)]/=2;
            cout<<it1->F.F<<' '<<it1->F.S<<' '<<it1->S<<'\n';
        }

        nl;
        nl;
    }





 return 0;
}
