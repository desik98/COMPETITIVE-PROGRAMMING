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
using namespace std;

vlli V[100001];
vlli V1[100001];
vlli V2[100001];
vlli V3[100001];
bool visited[100001];
bool visited1[100001];
lli postorder[100001];
lli Time=0;
lli Root[100001];
lli Head;
lli level[100001];
//stack<lli>Toposort;

bool sortbygreater(const pair<lli,lli> &a,const pair<lli,lli> &b)
{
    return (a.F>b.F);
}

void dfs1(lli x)
{
    visited1[x]=1;

    lli i;
    rep(i,0,V1[x].sz())
    {
        if(!visited1[V1[x][i]])
        {
            dfs1(V1[x][i]);
        }
    }

    postorder[x]=++Time;
}

void dfs(lli x)
{
    visited[x]=1;

    lli i;
    rep(i,0,V[x].sz())
    {
        if(!visited[V[x][i]])
        {
            dfs(V[x][i]);
            Root[V[x][i]]=Head;
        }
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
        lli N,n,i,j;
        cin>>n;

        vplli Store_Edges;

        map<lli,lli>M1;
        map<lli,lli> :: itr it1;

        while(n--)
        {
            lli z;
            cin>>z;

            while(z--)
            {
                lli x,y;
                cin>>x>>y;

                Store_Edges.pb(mp(x,y));

                M1[x]=1;
                M1[y]=1;
            }
        }

        cout<<"Case "<<t++<<": ";

        lli cnt=0;
        for(it1=M1.begin();it1!=M1.end();it1++)
        {
            //cout<<it1->F<<' ';

            it1->S=++cnt;
        }

        N=M1.sz();
        rep(i,0,Store_Edges.sz())
        {
            lli x=Store_Edges[i].F,y=Store_Edges[i].S;

            Store_Edges[i].F=M1[x];
            Store_Edges[i].S=M1[y];

            V[M1[x]].pb(M1[y]);
            V1[M1[y]].pb(M1[x]);
        }

//        cout<<"Graph\n";
//        rep(i,1,N+1)
//        {
//            cout<<i<<' ';
//
//            rep(j,0,V[i].sz())
//            cout<<V[i][j]<<' ';
//            nl;
//        }

        rep(i,1,N+1)
        {
            Root[i]=i;
        }

        rep(i,1,N+1)
        {
            if(!visited1[i])
            {
                dfs1(i);
            }
        }

        vplli V4;
        rep(i,1,N+1)
        {
            V4.pb(mp(postorder[i],i));
        }

        sort(V4.begin(),V4.end(),sortbygreater);

        lli Count=0;

        rep(i,0,V4.sz())
        {
            Head=V4[i].S;

            if(!visited[Head])
            {
                Count++;
                dfs(Head);
            }
        }

        set<plli >Remove_Duplicates;
        set<plli >:: itr it;

        rep(i,0,Store_Edges.sz())
        {
            Remove_Duplicates.insert(mp(Root[Store_Edges[i].F],Root[Store_Edges[i].S]));
        }

        M1.clear();

        for(it=Remove_Duplicates.begin();it!=Remove_Duplicates.end();it++)
        {
            lli x=it->F,y=it->S;

            M1[x]=1;
            M1[y]=1;
        }

        cnt=0;
        for(it1=M1.begin();it1!=M1.end();it1++)
        {
            it1->S=++cnt;
        }

        for(it=Remove_Duplicates.begin();it!=Remove_Duplicates.end();it++)
        {
            lli x=it->F,y=it->S;

            if(x!=y)
            {
                V2[M1[x]].pb(M1[y]);
                V3[M1[y]].pb(M1[x]);
            }
        }

//        rep(i,1,Count+1)
//        {
//            cout<<i<<' ';
//
//            rep(j,0,V2[i].sz())
//            {
//                cout<<V2[i][j]<<' ';
//            }
//            nl;
//        }

        lli cnt0=0,cnt1=0,cntx=0,cnt01=0,cnt11=0,cntx1=0;
        rep(i,1,Count+1)
        {
            if(!V2[i].sz())
            {
                cnt0++;
            }
            elif(V2[i].sz() == 1)
            {
                cnt1++;
            }
            else
            {
                cntx++;
            }
        }

        rep(i,1,Count+1)
        {
            if(!V3[i].sz())
            {
                cnt01++;
            }
            elif(V3[i].sz() == 1)
            {
                cnt11++;
            }
            else
            {
                cntx1++;
            }
        }

        if(cntx or cnt0!=1 or cntx1 or cnt01!=1)
        {
            cout<<"NO";
        }
        else
        {
            cout<<"YES";
        }
        nl;

        Time=0;
        rep(i,1,N+1)
        {
            V[i].clear();
            V1[i].clear();
            V2[i].clear();
            V3[i].clear();
            visited[i]=0;
            visited1[i]=0;
            postorder[i]=0;
            Root[i]=0;
            level[i]=0;
        }
        Head=0;
    }




 return 0;
}
