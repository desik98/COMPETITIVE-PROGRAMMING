/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'

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
#define pii		pair<int,int>
#define pll		pair<li,li>
#define vpi		vector<pii >
#define vpl		vector<pll >
#define F		first
#define S		second

#define mod		1000000007
using namespace std;

lli Race[20001];

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

    lli T,t;
    cin>>T;

    rep(t,0,T)
    {
        lli N,i;
        cin>>N;

        memset(Race,-1,szof(Race));

        rep(i,0,N)
        {
            lli x,y;
            cin>>x>>y;

            if(Race[x]!=-1)
            {
                Race[y]=1-Race[x];
            }
            else
            {
                if(Race[y]!=-1)
                {
                    Race[x]=1-Race[y];
                }
                else
                {
                    Race[x]=1;
                    Race[y]=0;
                }
            }
        }

        lli cnt1=0,cnt2=0;
        rep(i,0,20001)
        {
            if(Race[i]==0)
            {
                cnt1++;
            }
            else if(Race[i]==1)
            {
                cnt2++;
            }
        }

        cout<<"Case "<<t+1<<":"<<' ';
        cout<<max(cnt1,cnt2);
        nl;

    }



 return 0;
}
