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
        lli N,i;
        cin>>N;

        map < lli,lli > String_Hash_Store;

        rep(i,0,N)
        {
            string Word;
            cin>>Word;

            lli Hash=0;
            lli Word_Length=Word.length(),i;

            sort(Word.begin()+1,Word.begin()+Word_Length);
            //cout<<Word<<'\n';

            rep(i,0,Word_Length)
            {
                Hash=Hash*173+Word[i];
            }

            String_Hash_Store[Hash]++;
        }

        lli M;
        cin>>M;

        string Sentence;
        getline(cin,Sentence);

        cout<<"Case "<<t++<<":\n";

        while(M--)
        {
            lli cnt=0,j;

            getline(cin,Sentence);
            Sentence.push_back(' ');

            string Sentence_substring="";

            lli Sentence_Length=Sentence.length(),Hash_Sentence=0;
            rep(i,0,Sentence_Length)
            {
                if(Sentence[i]==' ')
                {
                    Hash_Sentence=0;
                    //cout<<Sentence_substring<<' ';

                    sort(Sentence_substring.begin()+1,Sentence_substring.begin()+Sentence_substring.length());

                    rep(j,0,Sentence_substring.length())
                    {
                        Hash_Sentence=Hash_Sentence*173+Sentence_substring[j];
                    }

                    cnt+=String_Hash_Store[Hash_Sentence];

                    Sentence_substring="";
                }
                else
                {
                    Sentence_substring.push_back(Sentence[i]);
                }
            }

            cout<<cnt;
            nl;
        }
    }





 return 0;
}
