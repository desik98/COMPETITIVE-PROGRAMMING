/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define sf(N)       scanf("%lld",&N)
#define pf(N)       printf("%lld",N)
#define pn			printf("\n")
#define nl			cout<<'\n'
#define ps          printf(" ")
#define sl          cout<<' '

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

#define Inf     1000000000
#define mod		1000000007
using namespace std;

lli BIT[100001];
lli Max;

void update(lli x,lli Value)
{
    while(x<=Max)
    {
        BIT[x]=(BIT[x]+Value)%mod;

        x+=x&-x;
    }
}

lli query(lli x)
{
    lli Sum=0;

    while(x>0)
    {
        Sum+=BIT[x];
        Sum%=mod;

        x-=x&-x;
    }

 return Sum;
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
    #ifndef ONLINE_JUDGE
    freopen("All_Possible_Increasing_Subsequences.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        memset(BIT,0,szof(BIT));

        lli N,i;
        sf(N);

        vlli V(N);
        rep(i,0,N)
        {
            cin>>V[i];
        }

        printf("Case %lld: ",t++);

        map<lli,lli>M;
        map<lli,lli>:: itr it;

        rep(i,0,N)
        {
            lli x=V[i];

            M[x]++;
        }

        it=M.end();

        lli cnt=1;
        for(it=M.begin();it!=M.end();it++)
        {
            it->S=cnt++;
        }

        it--;

        Max=it->S;

        rep(i,0,N)
        {
            lli x=V[i];
            it=M.find(x);

            V[i]=it->S;
        }

        for(i=0;i<N;i++)
        {
            lli x=V[i];

            lli Sum=query(x-1)+1;

            update(x,Sum%mod);
        }

        pf(query(Max));
        pn;
    }




 return 0;
}
