#include<stdio.h>

int main()
{
    int T,t=1;
    sf(&T);

    while(T--)
    {
        int r1,c1,r2,c2;
        sf(&r1);
        sf(&c1);sf(&r2);sf(&c2);

        if((r1+c1)%2 == (r2+c2)%2)
        {
            if((r1+c1 == r2+c2) || (r1-c1)==(r2-c2))
            {
                printf("Case %d: %d\n",t++,1);
            }
            else
            {
                printf("Case %d: %d\n",t++,2);
            }
        }
        else
        {
            printf("Case %d: impossible\n",t++);
        }
    }

    return 0;
}

void sf(int* number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c=='-')
    {
        negative = true;

        c = getchar();
    }

    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    if (negative)
        number *= -1;
}
