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

#define Inf     1000000000000000
#define mod		1000000007
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
    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli N,i,Q;
        sf(N);
        sf(Q);

        vplli V(N);
        vlli queries;
        vplli queries1;
        map<lli,lli>M;
        map<lli,lli>:: itr it;

        rep(i,0,N)
        {
            sf(V[i].F);
            sf(V[i].S);
        }

        while(Q--)
        {
            lli x;
            sf(x);

            queries.pb(x);
            M.insert(mp(x,0));
        }
        M.insert(mp(-1,0));
        M.insert(mp(Inf,0));

        printf("Case %lld:\n",t++);

        Q=queries.sz();

        rep(i,0,N)
        {
            lli x=V[i].F,y=V[i].S;

            it=M.lower_bound(x);

            M[it->F]++;

            it=M.upper_bound(y);
            M[it->F]--;
        }

        for(it=M.begin();it!=M.end();it++)
        {
            queries1.pb(mp(it->F,it->S));
        }

        rep(i,1,queries1.sz()-1)
        {
            queries1[i].S +=queries1[i-1].S;
        }

        M.clear();
        rep(i,0,queries1.sz())
        {
            M.insert(mp(queries1[i].F,queries1[i].S));
        }

        rep(i,0,queries.sz())
        {
            lli x=queries[i];

            it=M.find(x);

            pf(it->S);
            nl;
        }
    }




 return 0;
}
