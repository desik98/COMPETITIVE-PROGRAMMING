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
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("Helping_Cicada.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,M,j;
        cin>>N>>M;

        vlli V,Duplicates,Mark;
        rep(i,0,M)
        {
            lli x;
            cin>>x;

            Duplicates.pb(x);
            Mark.pb(0);
        }

        rep(i,0,M)
        {
            rep(j,0,M)
            {
                if(i==j or Duplicates[i]%Duplicates[j])
                {
                    continue;
                }
                Mark[i]=1;
            }
        }

        rep(i,0,Duplicates.sz())
        {
            if(!Mark[i])
            {
                V.pb(Duplicates[i]);
            }
        }

        cout<<"Case "<<t++<<": ";

        vplli Store;

        M=V.sz();
        rep(i,1,Power(2,M))
        {
            vlli V1;

            lli cnt=0;

            rep(j,0,M)
            {
                if(i&(1<<j))
                {
                    V1.pb(V[j]);
                    cnt++;
                }
            }

            lli LCM=V1[0];
            rep(j,1,V1.sz())
            {
                LCM=(LCM*V1[j])/__gcd(LCM,V1[j]);
            }

            Store.pb(mp(LCM,cnt));
        }

        lli Sum=0;
        rep(i,0,Store.sz())
        {
            lli cnt=Store[i].S;

            if(cnt%2)
            {
                Sum+=N/Store[i].F;
            }
            else
            {
                Sum-=N/Store[i].F;
            }
        }

        cout<<N-Sum;
        nl;
    }




 return 0;
}
