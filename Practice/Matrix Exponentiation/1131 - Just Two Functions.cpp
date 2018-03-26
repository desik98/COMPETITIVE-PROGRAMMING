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
using namespace std;

lli a1,b1,c1;
lli a2,b2,c2;
lli mod;

void mul(lli mat1[][6],lli mat2[][6])
{
    lli res[6][6]={0};

    lli i,j,k;

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            for(k=0;k<6;k++)
            {
                res[i][j]+=mat1[i][k]*mat2[k][j];
                res[i][j]%=mod;
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
    lli mat[][6]={  {a1,b1,0,0,0,c1},
                    {1,0,0,0,0,0},
                    {0,1,0,0,0,0},
                    {0,0,c2,a2,b2,0},
                    {0,0,0,1,0,0},
                    {0,0,0,0,1,0}
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

        lli f0,f1,f2;
        cin>>f0>>f1>>f2;

        lli g0,g1,g2;
        cin>>g0>>g1>>g2;

        cin>>mod;

        cout<<"Case "<<t++<<":";
        nl;

        lli res[6][6];

        lli i,j;

        lli Q;
        cin>>Q;

        while(Q--)
        {
            lli N;
            cin>>N;

            if(!N)
            {
                cout<<f0;sl;cout<<g0;
            }
            elif(N==1)
            {
                cout<<f1;sl;cout<<g1;
            }
            elif(N==2)
            {
                cout<<f2;sl;cout<<g2;
            }
            else
            {
                rep(i,0,6)
                {
                    rep(j,0,6)
                    {
                        res[i][j]=(i==j);
                    }
                }

                pow(res,N-2);

                if(N%3==1)
                {
                    cout<<(f0*res[0][2]+f2*res[0][0]+g1*res[0][4])%mod;
                    sl;
                    cout<<(g0*res[3][5]+g2*res[3][3]+f1*res[3][1])%mod;
                }
                elif(N%3==2)
                {
                    cout<<(f0*res[0][2]+f1*res[0][1]+g2*res[0][3])%mod;
                    sl;
                    cout<<(g0*res[3][5]+g1*res[3][4]+f2*res[3][0])%mod;
                }
                else
                {
                    cout<<(f1*res[0][1]+f2*res[0][0]+g0*res[0][5])%mod;
                    sl;
                    cout<<(g1*res[3][4]+g2*res[3][3]+f0*res[3][3])%mod;
                }
            }
            nl;
        }
    }




 return 0;
}
