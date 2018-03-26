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
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli M,N,i;
        cin>>M>>N;

        stack<string>S;
        lli cnt=0;

        vlli V(M);
        rep(i,0,M)
        {
            cin>>V[i];

            char ch=V[i]+'0';
            string s="";

            s.pb(ch);

            S.push(s);
        }

        sort(V.begin(),V.end());

        cout<<"Case "<<t++<<": ";

        while(!S.empty())
        {
            string s=S.top();
            S.pop();

            if(s.sz()==N)
            {
                cnt++;
            }
            else
            {
                lli x=lower_bound(V.begin(),V.end(),s[s.length()-1]-'0'-2)-V.begin();
                lli y=upper_bound(V.begin(),V.end(),s[s.length()-1]-'0'+2)-V.begin();

                rep(i,x,y)
                {
                    char ch=V[i]+'0';

                    if(abs(s[s.length()-1]-ch)<=2)
                    {
                        string s1=s;
                        s1.pb(ch);

                        S.push(s1);
                    }
                }
            }
        }

        cout<<cnt;
        nl;



    }




 return 0;
}
