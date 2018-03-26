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

lli mod;

void mul(lli mat1[][2],lli mat2[][2])
{
    lli res[2][2];

    res[0][0] = (mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0])%mod;
    res[0][1] = (mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[1][1])%mod;
    res[1][0] = (mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0])%mod;
    res[1][1] = (mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[1][1])%mod;

    mat1[0][0]=res[0][0];
    mat1[0][1]=res[0][1];
    mat1[1][0]=res[1][0];
    mat1[1][1]=res[1][1];
}

void pow(lli res[][2],lli exp)
{
    lli mat[][2]={{0,1},{1,1}};

    while(exp)
    {
        if(exp&1)
        {
            mul(res,mat);
        }

        exp>>=1;
        mul(mat,mat);
    }
}

lli Power(lli a,lli b)
{
    lli result=1;

    while(b)
    {
        if(b%2)
        {
            result=(result*a);
        }

        b=b>>1;
        a=(a*a);
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
    cin>>T;

    while(T--)
    {
        lli res[2][2]={ {1,0},{0,1} };

        lli a,b,n,m;
        cin>>a>>b>>n>>m;

        cout<<"Case "<<t++<<": ";

        mod=Power(10LL,m);

        pow(res,n);

        cout<<(a*res[0][0]+b*res[0][1])%mod;
        nl;
    }



 return 0;
}
