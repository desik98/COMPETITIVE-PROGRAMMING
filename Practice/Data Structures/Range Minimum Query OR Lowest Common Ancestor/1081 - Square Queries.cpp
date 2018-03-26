/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#include<cstdio>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			 printf("\n")
#define nl			 cout<<'\n'
#define sf(N)        scanf("%d",&N)
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

#define MX1     500
#define MX2     1000000
#define Inf     1000000000000000
#define mod		1000000007
#define k       8
using namespace std;

I a[MX1+1][MX1+1];
I table[MX1+1][MX1+1][9];

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
    #ifndef ONLINE_JUDGE
    freopen("Square Queries.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    I T,t=1;
    sf(T);

    while(T--)
    {
        I N,i,Q,j,l,m;
        sf(N);sf(Q);

        rep(i,0,N)
        {
            rep(j,0,N)
            {
                rep(l,0,9)
                {
                    table[i][j][l]=0;
                }
            }
        }

        rep(i,0,N)
        {
            rep(j,0,N)
            {
                sf(a[i][j]);
            }
        }

        printf("Case %d:\n",t++);

        rep(i,0,N)
        {
            rep(j,0,N)
            {
                table[i][j][0]=a[i][j];
            }
        }

        for(i=0;i<N;i++)
        {
            for(l=1;l<k+1;l++)
            {
                for(j=0;j<N-(1<<l)+1;j++)
                {
                    table[i][j][l]=max(table[i][j][l],max(table[i][j][l-1],table[i][j+(1<<(l-1))][l-1]));
                }
            }
        }


        while(Q--)
        {
            I R,C,Sec;
            sf(R),sf(C),sf(Sec);

            R--;
            C--;

            I C1=C,C2=C+Sec-1;

            I Min=0;

            rep(i,R,R+Sec)
            {
                C1=C;
                for(j=k;j>=0;j--)
                {
                    if(C1+(1<<j)-1<=C2)
                    {
                        Min=max(table[i][C1][j],Min);
                        C1+=1<<j;
                    }
                }
            }

            printf("%d\n",Min);
        }
    }




 return 0;
}
