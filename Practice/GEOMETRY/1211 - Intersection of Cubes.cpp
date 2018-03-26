/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli    unsigned long long

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

    /*#ifndef ONLINE_JUDGE
    freopen("Intersection_of_Cubes.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i;
        cin>>N;

        lli x1=1,y1=1,z1=1,x2=INT_MAX,y2=INT_MAX,z2=INT_MAX;

        rep(i,0,N)
        {
            lli a1,b1,c1,a2,b2,c2;

            cin>>a1>>b1>>c1>>a2>>b2>>c2;

            x1=max(a1,x1);
            y1=max(b1,y1);
            z1=max(c1,z1);

            x2=min(a2,x2);
            y2=min(b2,y2);
            z2=min(z2,c2);
        }

        cout<<"Case "<<t++<<": ";

        if(x2<x1 or y2<y1 or z2<z1)
        {
            cout<<0;
        }
        else
        {
            cout<<(x2-x1)*(y2-y1)*(z2-z1);
        }

        nl;
    }





 return 0;
}
