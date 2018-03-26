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

#define Inf     100000000000
#define mod		1000000007
using namespace std;

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
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,W,i,j;
        cin>>N>>W;

        vlli V(N);
        vlli V1;
        vlli V2;

        vlli Store1,Store2;

        lli Sum1=0;

        rep(i,0,N)
        {
            cin>>V[i];

            Sum1+=V[i];

            if(!(i&1))
            {
                V1.pb(V[i]);
            }
            else
            {
                V2.pb(V[i]);
            }
        }

        cout<<"Case "<<t++<<": ";

        if(Sum1<=W)
        {
            cout<<Power(2,N);
            nl;

            continue;
        }

        if(*min_element(V.begin(),V.end())>W)
        {
            cout<<1;
            nl;

            continue;
        }

        rep(i,0,Power(2,V1.sz()))
        {
            lli Sum=0;
            rep(j,0,V1.sz())
            {
                if(i&(1<<j))
                {
                    Sum+=V1[j];
                }
            }

            Store1.pb(Sum);
        }

        rep(i,0,Power(2,V2.sz()))
        {
            lli Sum=0;
            rep(j,0,V2.sz())
            {
                if(i&(1<<j))
                {
                    Sum+=V2[j];
                }
            }

            Store2.pb(Sum);
        }

        sort(Store2.begin(),Store2.end());

        lli Sum=0;

        rep(i,0,Store1.sz())
        {
            Sum+=upper_bound(Store2.begin(),Store2.end(),W-Store1[i])-Store2.begin();
        }

        cout<<Sum;

        nl;
    }



 return 0;
}
