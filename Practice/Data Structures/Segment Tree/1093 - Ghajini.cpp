#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li      int32_t
#define lli     long long
#define ulli unsigned long long

#define pn          printf("\n")
#define nl          cout<<'\n'

#define rep(i,a,b)  for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define elif        else if
#define mset(a,b)   memset(a,b,sizeof(a))

#define pb      push_back
#define pob     pop_back
#define itr     iterator
#define sz      size()
#define lb      lower_bound
#define ub      upper_bound
#define mp      make_pair
#define pii     pair<int,int>
#define pll     pair<li,li>
#define vpi     vector<pii >
#define vpl     vector<pll >
#define F       first
#define S       second

#define mod     1000000007
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

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,K,i,j;
        cin>>N>>K;

        vector<lli>V(N);
        rep(i,0,N)
        {
            cin>>V[i];
        }

        cout<<"Case "<<t++<<": ";

        vector<lli> Maximum,Minimum;

        deque<lli>D;
        rep(i,0,K)
        {
            while(!D.empty() && V[D.back()]<V[i])
            {
                D.pob();
            }
            D.pb(i);
        }
        Maximum.pb(V[D.front()]);

        rep(j,i,N)
        {
            if(D.front()<j-K+1)
            {
                D.pop_front();
            }

            while(!D.empty() && V[D.back()]<V[j])
            {
                D.pob();
            }
            D.pb(j);

            Maximum.pb(V[D.front()]);
        }

        deque<lli>D1;
        rep(i,0,K)
        {
            while(!D1.empty() && V[D1.back()]>V[i])
            {
                D1.pob();
            }
            D1.pb(i);
        }
        Minimum.pb(V[D1.front()]);

        rep(j,i,N)
        {
            if(D1.front()<j-K+1)
            {
                D1.pop_front();
            }

            while(!D1.empty() && V[D1.back()]>V[j])
            {
                D1.pob();
            }
            D1.pb(j);

            Minimum.pb(V[D1.front()]);
        }

        lli Abs_Diff=0;
        rep(i,0,Maximum.size())
        {
            Abs_Diff=max(Abs_Diff,Maximum[i]-Minimum[i]);
        }

        cout<<Abs_Diff;
        cout<<'\n';
    }



 return 0;
}

