/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		int
#define ulli unsigned long long

#define pn			 printf("\n")
#define nl			 cout<<'\n'
#define sf(N)        scanf("%lld",&N)
#define pf(N)        printf("%lld",N)
#define sf1(N1,N2)    scanf("%lld %lld",&N1,&N2)
#define pf1(N1,N2)    printf("%lld %lld",N1,N2)
#define sf2(N1,N2,N3) scanf("%lld %lld %lld",&N1,&N2,&N3)
#define pf2(N1,N2,N3) printf("%lld %lld %lld",N1,N2,N3)

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
#define Dup     erase(unique(V.begin(),V.end()),V.end())

#define bs      binary_search
#define ub      upper_bound
#define lb      lower_bound

#define ALL(V)  V.begin(),V.end()

#define MX1     100000
#define MX2     1000000
#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

struct TrieNode
{
    map<lli,TrieNode*> Map;
};

TrieNode* GetNode()
{
    TrieNode* temp=new TrieNode;

    return temp;
}

void Insert(TrieNode* root,string s)
{
    TrieNode* temp=root;

    lli N=s.length(),i;
    rep(i,0,N)
    {
        if(temp->Map.find(s[i]-'0') == temp->Map.end())
        {
            temp->Map[s[i]-'0']=GetNode();
        }

        temp=temp->Map[s[i]-'0'];
    }
}

lli Query_Maximum(TrieNode* root,string s)
{
    TrieNode* temp=root;

    lli N=s.length(),i,XOR=0;
    rep(i,0,N)
    {
        if(temp->Map.find('1'-s[i]) != temp->Map.end())
        {
            XOR+=1<<(63-i);
            temp=temp->Map['1'-s[i]];
        }
        else
        {
            temp=temp->Map[s[i]-'0'];
        }
    }

    return XOR;
}

lli Query_Minimum(TrieNode* root,string s)
{
    TrieNode* temp=root;

    lli N=s.length(),i,XOR=0;
    rep(i,0,N)
    {
        if(temp->Map.find(s[i]-'0') != temp->Map.end())
        {
            temp=temp->Map[s[i]-'0'];
        }
        else
        {
            XOR+=1<<(63-i);
            temp=temp->Map['1'-s[i]];
        }
    }

    return XOR;
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
    freopen("double_squares.txt","r",stdin);*/
    //freopen("double_squares_out.txt","w",stdout);
//    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        TrieNode* root;
        root=GetNode();

        lli N,i;
        cin>>N;

        //cout<<"Case "<<t++<<": ";

        lli Max=0,Min=INT_MAX,Prefix=0;

        string Zeroes="";
        rep(i,0,32)
        {
            Zeroes.push_back('0');
        }

        Insert(root,Zeroes);

        while(N--)
        {
            lli x;
            cin>>x;

            Prefix^=x;
            x=Prefix;

            string s="";

            while(x)
            {
                s.push_back(x%2+'0');
                x/=2;
            }

            while(s.length()<32)
            {
                s.push_back('0');
            }

            reverse(s.begin(),s.end());

            //cout<<s<<'\n';

            Max=max(Max,Query_Maximum(root,s));
            Min=min(Min,Query_Minimum(root,s));

            Insert(root,s);
        }

        cout<<Max;
        cout<<' ';
        cout<<Min<<'\n';
    }




 return 0;
}
