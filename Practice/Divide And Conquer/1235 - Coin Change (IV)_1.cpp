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
        cout<<"Case "<<t++<<": ";

        lli N,K,i,j,Sum1=0;
        cin>>N>>K;

        vlli V1(N),V;
        rep(i,0,N)
        {
            cin>>V1[i];
            Sum1+=2*V1[i];
        }

        if(Sum1==K)
        {
            cout<<"Yes";
            nl;

            continue;
        }

        if(Sum1<K)
        {
            cout<<"No";
            nl;

            continue;
        }

        sort(V1.begin(),V1.end());

        if(binary_search(V1.begin(),V1.end(),K))
        {
            cout<<"Yes";
            nl;

            continue;
        }

        rep(i,0,Power(2,N))
        {
            lli Sum=0;
            rep(j,0,N)
            {
                if(i&(1<<j))
                {
                    Sum+=V1[j];
                }
            }

            V.pb(Sum);
        }

        if(binary_search(V.begin(),V.end(),K))
        {
            cout<<"Yes";
            nl;

            continue;
        }

        I flag=0;
        rep(i,0,upper_bound(V.begin(),V.end(),K)-V.begin())
        {
            if(binary_search(V.begin(),V.end(),K-V[i]))
            {
                flag=1;

                break;
            }
        }

        if(flag)
        {
            cout<<"Yes";
            nl;

            continue;
        }

        cout<<"No";
        nl;
    }




 return 0;
}
