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
#define F   	first
#define S		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000000000
#define mod		1000000007
#define MX1	100005
using namespace std;

lli n,c,q,block,arr[MX1],res[MX1],cnt[MX1],cntl[MX1],cntr[MX1];
vector<pair<plli,lli > > queries;

bool cmp(const pair<plli,lli > &a,const pair<plli,lli > &b)
{
    lli block_a=a.F.F/block,block_b=b.F.F/block;

    if(block_a!=block_b)
    {
        return block_a<block_b;
    }
    return a.F.S<b.F.S;
}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("Strongest_Community.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli i;
        cin>>n;
        cin>>c;
        cin>>q;

        block=(lli)sqrt(n);

        queries.clear();

        rep(i,0,n+1)
        {
            cnt[i]=0;
        }

        rep(i,1,n+1)
        {
            cin>>arr[i];
        }

        cntr[1]=1;

        rep(i,2,n+1)
        {
            if(arr[i]==arr[i-1])
            {
                cntr[i]=cntr[i-1]+1;
            }
            else
            {
                cntr[i]=1;
            }
        }

        cntl[n]=1;

        repr(i,n-1,0)
        {
            if(arr[i]==arr[i+1])
            {
                cntl[i]=cntl[i+1]+1;
            }
            else
            {
                cntl[i]=1;
            }
        }

        rep(i,0,q)
        {
            lli a,b;
            cin>>a;
            cin>>b;

            queries.pb(mp(mp(a,b),i));
        }

        cout<<"Case "<<t++<<":\n";

        /*rep(i,1,n+1)
        {
            cout<<cntr[i];sl;
        }
        nl;

        rep(i,1,n+1)
        {
            cout<<cntl[i];sl;
        }
        nl;*/

        sort(queries.begin(),queries.end(),cmp);
        lli moleft=1,moright=0;

        rep(i,0,q)
        {
            lli left=queries[i].F.F,right=queries[i].F.S;

            while(moleft<left)
            {
                cnt[cntl[moleft]]--;
                moleft++;
            }

            while(moleft>left)
            {
                moleft--;
                cnt[cntl[moleft]]++;
            }

            while(moright<right)
            {
                moright++;
                cnt[cntr[moright]]++;
            }

            while(moright>right)
            {
                cnt[cntr[moright]]--;
                moright--;
            }

            /*cout<<left<<' '<<right;
            nl;

            lli j;
            rep(j,1,n+1)
            {
                cout<<cnt[j];sl;
            }
            nl;*/

            lli low=1,high=right-left+1,Store=1;

            while(low<=high)
            {
                lli mid=(low+high)/2;

                if(cnt[mid])
                {
                    low=mid+1;
                    Store=mid;
                }
                else
                {
                    high=mid-1;
                }
            }

            res[queries[i].S]=Store;
        }

        rep(i,0,q)
        {
            cout<<res[i];
            nl;
        }
    }



    return 0;
}
