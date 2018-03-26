/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li      int32_t
#define lli     long long
#define ulli unsigned long long

#define pn          printf("\n")
#define nl          cout<<'\n'
#define sf(N)       scanf("%lld",&N)
#define pf(N)       printf("%lld",N)
#define sl          cout<<' '
#define ps          printf(" ")

#define rep(i,a,b)  for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define elif        else if
#define mset(a,b)   memset(a,b,sizeof(a))

#define pb      push_back
#define pob     pop_back
#define itr     iterator
#define sz()    size()
#define szof    sizeof
#define lb      lower_bound
#define ub      upper_bound
#define mp      make_pair
#define vlli    vector<lli>
#define plli    pair<lli,lli>
#define vplli   vector<plli >
#define Frst    first
#define Sec     second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000000000
#define mod     10007
using namespace std;

void mul(lli mat1[][3],lli mat2[][3])
{
    lli res[3][3]={0};

    lli i,j,k;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                res[i][j]+=mat1[i][k]*mat2[k][j];
                res[i][j]%=mod;
            }
        }
    }

    rep(i,0,3)
    {
        rep(j,0,3)
        {
            mat1[i][j]=res[i][j];
        }
    }
}

void pow(lli res[][3],lli exp)
{
    lli mat[][3]={  {2,0,1},
                    {1,0,0},
                    {0,1,0}
                 };

    while(exp)
    {
        if(exp&1)
        {
            mul(res,mat);
        }

        mul(mat,mat);
        exp>>=1;
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
    freopen("nth_term.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli N;
        sf(N);

        //cout<<"Case "<<t++<<": ";

        if(N==1 or N==2)
        {
            printf("Case %lld: %lld\n",t++,N);

            continue;
        }

        lli res[][3]={{1,0,0},
                      {0,1,0},
                      {0,0,1},
                      };

        pow(res,N-2);

        printf("Case %lld: %lld\n",t++,(2*res[0][0]+res[0][1]+res[0][2])%mod);
    }




 return 0;
}
