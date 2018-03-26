#include<stdio.h>

int main()
{
    int T,t=1;
    scanf("%d",&T);

    for(t=1;t<T+1;t++)
    {
        double a,b,c;
        scanf("%lf %lf %lf",&a,&b,&c);

        double p=(a*c)/b;
        if(b-p <=0)
        {
            printf("Case %d: -1\n",t);

            continue;
        }

        double q=(p+c)*(p+a)/(b-p);

        printf("Case %d: %0.9lf\n",t,p+q);
    }

 return 0;
}
