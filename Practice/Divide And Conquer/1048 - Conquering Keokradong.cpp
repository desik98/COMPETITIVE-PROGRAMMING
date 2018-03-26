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
    freopen("Conquering_Keokradong.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,K;
        cin>>N>>K;

        vlli V;
        lli Sum=0;

        rep(i,0,N+1)
        {
            lli x;
            cin>>x;

            V.pb(x);
            Sum+=x;
        }

        cout<<"Case "<<t++<<": ";

        lli low=*max_element(V.begin(),V.end()),high=Sum;
        N=V.sz();

        lli Store=low;

        while(low<=high)
        {
            lli mid=(low+high)/2;

            lli cnt=0,x=0,i=0;

            while(i<N)
            {
                x+=V[i];

                if(x>mid)
                {
                    x=V[i];

                    cnt++;
                }

                i++;
            }

            if(cnt>K)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
                Store=mid;
            }
        }

        vlli Mark(N);

        lli x=V[0],cnt=0;
        rep(i,1,N)
        {
            x+=V[i];

            if(x>Store)
            {
                x=V[i];

                Mark[i-1]=1;
            }
            else
            {
                Mark[i-1]=0;
            }
        }
        Mark[N-1]=0;

        rep(i,1,N)
        {
            V[i]+=V[i-1];
        }

        rep(i,0,N)
        {
            if(Mark[i])
            {
                cnt++;
            }
        }

        i=N-1;
        while(cnt<K+1)
        {
            while(Mark[i])
            {
                i--;
            }
            Mark[i]=1;
            i--;

            cnt++;
        }

        cout<<Store;
        nl;

        lli j=-1;
        rep(i,0,N)
        {
            if(Mark[i])
            {
                if(j==-1)
                {
                    cout<<V[i];
                    nl;

                    j=i;
                    continue;
                }

                cout<<V[i]-V[j];
                nl;

                j=i;
            }
        }
    }




 return 0;
}
