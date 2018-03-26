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
#define sf2(N1,N2)       scanf("%lld %lld",&N1,&N2)
#define pf2(N1,N2)       printf("%lld %lld",N1,N2)
#define sf3(N1,N2,N3)   scanf("%lld %lld %lld",&N1,&N2,&N3)
#define pf3(N1,N2,N3)       printf("%lld %lld %lld",N1,N2,N3)

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

#define Inf     100000000
#define mod		1000000007
using namespace std;

vlli TWO(1000001);
vlli FIVE(1000001);

void Precompute()
{
    lli N=1000000;

    lli i,j;

    TWO[0]=0;
    FIVE[0]=0;

    for(i=1;i<=N;i++)
    {
        lli cnt1=0,cnt2=0;

        j=i;
        while(j%2==0)
        {
            cnt1++;
            j/=2;
        }

        j=i;
        while(j%5==0)
        {
            cnt2++;
            j/=5;
        }

        TWO[i]=cnt1;
        FIVE[i]=cnt2;
    }

    rep(i,1,N+1)
    {
        TWO[i]+=TWO[i-1];
        FIVE[i]+=FIVE[i-1];
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
    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    Precompute();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli n,r,p,q;
        cin>>n>>r>>p>>q;

        lli cnt1=TWO[n]-TWO[r]-TWO[n-r],cnt2=FIVE[n]-FIVE[r]-FIVE[n-r];

        /*cout<<cnt1<<' '<<cnt2;
        nl;*/

        lli cnt_expo_two=0,cnt_expo_five=0;
        while(p%2==0)
        {
            p/=2;
            cnt_expo_two++;
        }

        while(p%5==0)
        {
            p/=5;
            cnt_expo_five++;
        }

        cnt1+=cnt_expo_two*q;
        cnt2+=cnt_expo_five*q;

        cnt1=min(cnt1,cnt2);

        cout<<"Case "<<t++<<": "<<cnt1;
        nl;
    }




 return 0;
}
