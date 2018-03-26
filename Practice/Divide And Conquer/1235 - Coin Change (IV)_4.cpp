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

void Gen(vector<lli> &v,vector<lli> &V,lli Sum,lli i)
{
    V.pb(Sum);

    if(i<v.sz())
    {
        Gen(v,V,Sum,i+1);
        Gen(v,V,Sum+v[i],i+1);
        Gen(v,V,Sum+2*v[i],i+1);
    }
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
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,K,i;
        cin>>N>>K;

        vlli Store1,Store2;
        vlli V1,V2;

        vlli V(N);
        rep(i,0,N)
        {
            cin>>V[i];

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

        if(!(N-1))
        {
            if(V[0]==K or (2*V[0])==K)
            {
                cout<<"Yes";
            }
            else
            {
                cout<<"No";
            }

            nl;
            continue;
        }

        Gen(V1,Store1,0,0);
        Gen(V2,Store2,0,0);

        sort(Store2.begin(),Store2.end());

        I flag=0;
        rep(i,0,Store1.sz())
        {
            if(binary_search(Store2.begin(),Store2.end(),K-Store1[i]))
            {
                flag=1;
                break;
            }
        }

        if(flag)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        nl;
    }




 return 0;
}
