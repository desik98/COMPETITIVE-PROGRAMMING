#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'
#define sl			cout<<' '
#define ps 			printf(" ")

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
#define F		first
#define S		second
 #define mod		1000000007
using namespace std;

string s,s1;
lli f[1000001];

void Precompute()
{
	lli N=s1.length(),i;

	lli j=0;

	rep(i,1,N)
	{
		while(j>=0 and s1[j]!=s1[i])
		{
			if(j>=1)
			{
				j=f[j-1];
			}
			else
			{
				j=-1;
			}
		}
		j++;

		f[i]=j;
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

 	lli T,t=1;
 	cin>>T;

 	while(T--)
 	{
        cin>>s;

        s1=s;
        reverse(s1.begin(),s1.end());

        cout<<"Case "<<t++<<": ";

        if(s==s1)
        {
            cout<<s.length();nl;
            continue;
        }

        Precompute();



        /*lli i;
        rep(i,0,s.length())
        {
            cout<<f[i];sl;
        }
        nl;*/

        lli N=s.length(),i,j=1;

        lli cnt=0;
        rep(i,0,N)
        {
            while(j>=0 and s[i]!=s1[j])
            {
                if(j>=1)
                {
                    j=f[j-1];
                }
                else
                {
                    j=-1;
                }
            }
            j++;

            if(j==N)
            {
                cnt++;

                j=f[N-1];
            }
        }

        cout<<2*N-j;
        nl;
 	}





 return 0;
}
