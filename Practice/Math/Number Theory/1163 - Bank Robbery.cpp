/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define lli     long long

#define pn  printf("\n")
#define sf(N)       scanf("%d",&N)
#define pf(N)       printf("%d",N)

#define rep(i,a,b)  for(i=a;i<b;i++)

#define pb      push_back
#define itr     iterator
#define sz()    size()
#define szof    sizeof
#define mp      make_pair
#define vlli    vector<lli>
#define plli    pair<lli,lli>
#define vplli   vector<plli >
#define F       first
#define S       second
#define ALL(V)  V.begin(),V.end()

using namespace std;

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("Bank_Robbery.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        unsigned lli Number;
        cin>>Number;

        cout<<"Case "<<t++<<": ";

        if(Number%9)
        {
            cout<<10*(Number/9)+Number%9<<'\n';
        }
        else
        {
            cout<<10*(Number/9-1)+9<<" "<<10*(Number/9)<<'\n';
        }
    }



 return 0;
}
