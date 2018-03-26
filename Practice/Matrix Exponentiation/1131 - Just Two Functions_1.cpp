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
using namespace std;

lli a1,b1,c1;
lli a2,b2,c2;
lli f0,f1,f2;
lli g0,g1,g2;
lli M;

void mul(lli mat1[][6],lli mat2[][6])
{
    lli res[6][6]={0};

    lli i,j,k;

    rep(i,0,6)
    {
        rep(j,0,6)
        {
            rep(k,0,6)
            {
                res[i][j]+=mat1[i][k]*mat2[k][j];
                res[i][j]%=M;
            }
        }
    }

    rep(i,0,6)
    {
        rep(j,0,6)
        {
            mat1[i][j]=res[i][j];
        }
    }
}

void pow(lli res[][6],lli exp)
{
    lli mat[][6]={{a1,0,b1,0,0,c1},
                  {0,a2,0,b2,c2,0},
                  {1,0,0,0,0,0},
                  {0,1,0,0,0,0},
                  {0,0,1,0,0,0},
                  {0,0,0,1,0,0}
                 };

    while(exp)
    {
        if(exp%2)
        {
            mul(res,mat);
        }

        mul(mat,mat);
        exp/=2;
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
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;
        cin>>f0>>f1>>f2;
        cin>>g0>>g1>>g2;
        cin>>M;

        cout<<"Case "<<t++<<":\n";

        lli Q;
        cin>>Q;

        while(Q--)
        {
            lli N,i,j;
            cin>>N;

            if(!N)
            {
                cout<<f0<<' '<<g0;
            }
            elif(N==1)
            {
                cout<<f1<<' '<<g1;
            }
            elif(N==2)
            {
                cout<<f2<<' '<<g2;
            }
            else
            {
                lli res[6][6]={
                                {1,0,0,0,0,0},
                                {0,1,0,0,0,0},
                                {0,0,1,0,0,0},
                                {0,0,0,1,0,0},
                                {0,0,0,0,1,0},
                                {0,0,0,0,0,1}
                            };

                pow(res,N-2);

                /*rep(i,0,6)
                {
                    rep(j,0,6)
                    {
                        cout<<res[i][j];sl;
                    }
                    nl;
                }
                nl;*/

                lli x,y;

                x=(res[0][0]*f2+res[0][1]*g2+res[0][2]*f1+res[0][3]*g1+res[0][4]*f0+res[0][5]*g0)%M;
                y=(res[1][0]*f2+res[1][1]*g2+res[1][2]*f1+res[1][3]*g1+res[1][4]*f0+res[1][5]*g0)%M;

                cout<<x;sl;
                cout<<y;
            }
            nl;
        }
    }




 return 0;
}
