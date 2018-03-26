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
#define S  		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     100000000000
#define mod		1000000007
using namespace std;

bool comp(const plli &a,const plli &b)
{
    return(a.S<b.S);
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

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,j;
        cin>>N;

        vplli V(N);
        vlli visited(N);

        multiset<plli >M;
        multiset<plli >:: itr it,it1;

        rep(i,0,N)
        {
            lli x,y;
            cin>>x>>y;

            V[i].F=x;
            V[i].S=y;

            visited[i]=0;
        }

        sort(V.begin(),V.end(),comp);

        rep(i,0,N)
        {
            M.insert(mp(V[i].F,i));
        }

        /*for(it=M.begin();it!=M.end();++it)
        {
            cout<<it->F<<' '<<it->S;
            nl;
        }*/

        lli cnt=0;

        rep(i,0,N)
        {
            if(!visited[i])
            {
                visited[i]=1;
                it1=M.find(mp(V[i].F,i));
                M.erase(it1);

                it=M.upper_bound(mp(V[i].S,Inf));

                if(it!=M.end())
                {
                    j=it->S;

                    while(j<N)
                    {
                        j=it->S;

                        visited[j]=1;
                        it1=M.find(mp(V[j].F,j));
                        M.erase(it1);

                        if(M.sz())
                        it=M.upper_bound(mp(V[j].S,Inf));

                        if(!M.sz() or it==M.end())
                        {
                            break;
                        }
                    }
                }
                cnt++;
            }
        }

        cout<<"Case "<<t++<<": "<<cnt;
        nl;
    }




 return 0;
}
