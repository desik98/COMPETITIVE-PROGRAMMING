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

    #ifndef ONLINE_JUDGE
    freopen("Incredible_Molecules.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        double x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        cout<<"Case "<<t++<<": ";

        double h;

        double low=0,high=min(r1,r2),Store=Inf;

        double x=sqrt((x1-y1)*(x1-y1)+(x2-y2)*(x2-y2));

        while(high-low>=0.0000001)
        {
            double mid=(low+high)/2;

            double Value=sqrt(r1*r1-mid*mid)+sqrt(r2*r2-mid*mid);

            if(x-Value<=0.000001)
            {
                Store=mid;
            }

            if(x<Value)
            {
                low=mid;
            }
            else
            {
                high=mid;
            }
        }
        cout<<Store;sl;

        if(Store==Inf)
        {
            cout<<0;
        }
        else
        {
            cout<<setprecision(10)<<fixed<<r1*r1*asin(Store/r1)+r2*r2*asin(Store/r2)-Store*x;

            //cout<<Store;
        }

        nl;
    }





 return 0;
}
