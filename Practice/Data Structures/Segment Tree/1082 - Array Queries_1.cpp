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
#define Frst	first
#define Sec		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000000000
#define mod		1000000007
#define k       16
using namespace std;

vlli V;
lli N;
lli table[100001][17];

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
        lli N,i,Q,j;
        sf(N);
        sf(Q);

        rep(i,0,N)
        {
            lli x;
            sf(x);

            V.pb(x);
        }

        printf("Case %lld:\n",t++);

        rep(i,0,N)
        {
            rep(j,0,17)
            {
                table[i][j]=Inf;
            }
        }

        rep(i,0,N)
        {
            table[i][0]=V[i];
        }

        rep(j,1,k+1)
        {
            rep(i,0,N-(1<<j)+1)
            {
                table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
            }
        }

        while(Q--)
        {
            lli L,R;
            sf(L);
            sf(R);

            L--;
            R--;

            lli i;

            lli Ans=Inf;

            for(i=16;i>=0;i--)
            {
                if(L+(1<<i)-1<=R)
                {
                    Ans=min(Ans,table[L][i]);
                    L+=1<<i;
                }
            }

            pf(Ans);
            pn;
        }

        V.clear();
    }



 return 0;
}
