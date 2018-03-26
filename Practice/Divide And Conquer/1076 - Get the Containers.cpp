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

    /*#ifndef ONLINE_JUDGE
    freopen("Get_The_Containers.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,M;
        cin>>N>>M;

        vlli V(N);
        lli Sum=0;
        rep(i,0,N)
        {
            cin>>V[i];
            Sum+=V[i];
        }

        cout<<"Case "<<t++<<": ";

        lli low=*max_element(V.begin(),V.end()),high=Sum,Store=*max_element(V.begin(),V.end());

        while(low<=high)
        {
            lli mid=(low+high)/2;

            lli cnt=1;

            i=0;
            Sum=0;

            while(i<N)
            {
                Sum+=V[i];

                if(Sum>mid)
                {
                    Sum=V[i];
                    cnt++;
                }
                i++;
            }

            if(cnt<=M)
            {
                high=mid-1;
                Store=mid;
            }
            else
            {
                low=mid+1;
            }
        }

        cout<<Store;
        nl;

    }





 return 0;
}
