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
#define sf2(N1,N2)       scanf("%lld %lld",&N1,&N2)
#define pf2(N1,N2)       printf("%lld %lld",N1,N2)
#define sf3(N1,N2,N3)   scanf("%lld %lld %lld",&N1,&N2,&N3)
#define pf3(N1,N2,N3)       printf("%lld %lld %lld",N1,N2,N3)

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
    /*#ifndef ONLINE_JUDGE
    freopen("Aladdin_and_the_Optimal_Invitation.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli m,n,q;
        cin>>m>>n>>q;

        lli Sum=0,Sum1=0,cnt=0,cnt1=0;

        vector<pair<pair<lli,lli>,lli> >V;
        lli i;

        lli low1=Inf,high1=0,low2=Inf,high2=0;

        map<plli,lli>M;
        map<plli,lli>:: itr it;

        while(q--)
        {
            lli u,v,w;
            cin>>u>>v>>w;

            low1=min(low1,u);
            high1=max(high1,u);

            low2=min(low2,v);
            high2=max(high2,v);

            it=M.find(mp(u,v));

            if(it!=M.end())
            {
                lli x=it->S;

                M.erase(it);
                M.insert(mp(mp(u,v),x+w));
            }
            else
            {
                M.insert(mp(mp(u,v),w));
            }
        }

        for(it=M.begin();it!=M.end();it++)
        {
            lli u=it->F.F,v=it->F.S,w=it->S;

            V.pb(mp(mp(u,v),w));
        }

        cout<<"Case "<<t++<<": ";

        lli N=V.sz();

        lli Store1=low1,Store2=low2;

        while(low1<=high1)
        {
            //cout<<low1<<' '<<high1<<' ';

            lli mid1=(low1+high1)/2;
            Store1=mid1;

            lli mid2=mid1-1;

            lli Maximum1=0;

            rep(i,0,N)
            {
                Maximum1=Maximum1+abs(V[i].F.F-mid2)*V[i].S;
            }

            lli mid3=(mid1+1);

            lli Maximum2=0;

            rep(i,0,N)
            {
                Maximum2=Maximum2+abs(V[i].F.F-mid3)*V[i].S;
            }

            if(Maximum1<=Maximum2)
            {
                high1=mid1-1;
            }
            else
            {
                low1=mid1+1;
            }

            /*cout<<low1<<' '<<high1<<' ';

            cout<<mid2<<' '<<Maximum1<<' ';
            cout<<mid3<<' '<<Maximum2;
            nl;*/
        }

        while((-low2+high2)>0.0001)
        {
            //cout<<low2<<' '<<high2<<' ';

            double mid1=(low2+high2)/2;
            Store2=mid1;

            double Maximum=0;

            rep(i,0,N)
            {
                Maximum=Maximum+abs(V[i].F.S-mid1)*V[i].S;
            }

            double mid2=(low2+mid1)/2;

            double Maximum1=0;

            rep(i,0,N)
            {
                Maximum1=Maximum1+abs(V[i].F.S-mid2)*V[i].S;
            }

            double mid3=(mid1+high2)/2;

            double Maximum2=0;

            rep(i,0,N)
            {
                Maximum2=Maximum2+abs(V[i].F.S-mid3)*V[i].S;
            }

            if(Maximum1<=Maximum2)
            {
                high2=mid1;
            }
            else
            {
                low2=mid1;
            }

            /*cout<<low2<<' '<<high2;
            nl;*/
        }

        lli x1=floor(Store1);
        lli x2=x1+1;
        lli y1=floor(Store2);
        lli y2=y1+1;

        double Total=0,Total1=0,Total2=0,Total3=0;

        rep(i,0,V.sz())
        {
            Total+=V[i].S*abs(V[i].F.F-x1);
        }

        rep(i,0,V.sz())
        {
            Total1+=V[i].S*abs(V[i].F.F-x2);
        }

        rep(i,0,V.sz())
        {
            Total2+=V[i].S*abs(V[i].F.S-y1);
        }

        rep(i,0,V.sz())
        {
            Total3+=V[i].S*abs(V[i].F.S-y2);
        }

        if(Total<Total1)
        {
            cout<<x1<<' ';
        }
        else
        {
            cout<<x2<<' ';
        }

        if(Total2<Total3)
        {
            cout<<y1;
        }
        else
        {
            cout<<y2;
        }


        nl;
    }




 return 0;
}
