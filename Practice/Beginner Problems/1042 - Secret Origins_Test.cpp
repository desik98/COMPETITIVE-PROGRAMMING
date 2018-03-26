#include<bits/stdc++.h>
using namespace std;


long long int toBinary(long long int n)
{
long count=0;
for(int q=0;n>0;q++)
{
if((n%2)==1)
count++;
n/=2;
}
return count;
}

int main()
{
    freopen("double_squares_out.txt","w",stdout);
int t;
scanf("%d",&t);
for(int i=0;i<t;i++)
{
long long int b1;
scanf("%lld",&b1);
long long int x=b1+1;
for(long long int j=x;;j++)
{
if(toBinary(b1)==toBinary(j))
{
printf("Case %d: %lld\n",i+1,j);
break;
}
}

}
return 0;
}
