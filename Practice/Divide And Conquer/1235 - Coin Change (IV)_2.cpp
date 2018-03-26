/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		int
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
#define S  		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vlli V;
map<plli,lli>M;

lli Fun(lli K,lli N)
{
    if(N<0 or K<=0)
        return 0;

    map<plli,lli>:: itr it;

    it=M.find(mp(K,N));

    if(it!=M.end())
    {
        return (it->S);
    }

    lli Val=Fun(K,N-1);

    if(K>=V[N])
    {
        Val=max(Val,Fun(K-V[N],N-1)+V[N]);
    }

    if(K>=2*V[N])
    {
        Val=max(Val,Fun(K-2*V[N],N-1)+2*V[N]);
    }


    M.insert(mp(mp(K,N),Val));

 return Val;
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
        cout<<"Case "<<t++<<": ";

        lli N,i;
        cin>>N;

        lli K;
        cin>>K;

       rep(i,0,N)
       {
           lli x;
           cin>>x;

           V.pb(x);
       }

       if(Fun(K,N-1)==K)
       {
           cout<<"Yes";
       }
       else
       {
           cout<<"No";
       }
       nl;


       V.clear();
       M.clear();
    }



 return 0;
}
