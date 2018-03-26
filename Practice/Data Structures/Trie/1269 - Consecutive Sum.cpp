/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
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
    bool isleaf;
    TrieNode* child[2];
};

TrieNode* GetNode()
{
    TrieNode* temp=new TrieNode;
    temp->isleaf=0;

    lli i;
    rep(i,0,2)
    {
        temp->child[i]=NULL;
    }

    return temp;
}

void Insert(TrieNode* root,string s)
{
    TrieNode* temp=root;

    lli N=s.length(),i;
    rep(i,0,N)
    {
        if(!temp->child[s[i]-'0'])
        {
            temp->child[s[i]-'0']=GetNode();
        }
        temp=temp->child[s[i]-'0'];
    }
}

lli Query1(TrieNode* root,string s)
{
     TrieNode* temp=root;
     lli XOR=0,i;

     rep(i,0,32)
     {
         if(temp->child['1'-s[i]])
         {
            temp=temp->child['1'-s[i]];
            XOR+=1<<(31-i);
         }
         else
         {
             temp=temp->child[s[i]-'0'];
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
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    TrieNode* root;
    root=GetNode();

    lli N,i,j;
    cin>>N;

    string Number_Converted[N];

    rep(i,0,N)
    {
        string s1;
        cin>>s1;

        lli Number_length=s1.length();

        lli x=0,cnt=0;

        j=0;
        while(j<Number_length)
        {
            x=x*10+s1[j]-'0';

            j++;
        }

        s1.clear();
        while(x)
        {
            s1.pb(x%2+'0');
            x/=2;
            cnt++;
        }

        Number_length=cnt;
        reverse(s1.begin(),s1.end());

        string s="";
        rep(j,0,32-Number_length)
        {
            s.pb('0');
        }

        rep(j,0,Number_length)
        {
            s.pb(s1[j]);
        }

        cout<<s<<'\n';

        Insert(root,s);
        Number_Converted[i]=s;
    }

    lli Max=0,Min=0;
    rep(i,0,N)
    {
        Max=max(Max,Query1(root,Number_Converted[i]));
    }

    cout<<Max;
    nl;




 return 0;
}
