//MADE BY SEPANTAPOOYA
//COPING OR USING JUST BY MENTIONING MY NAME
#include <stdio.h>

int main()
{
    int n,m,big,small,gcd,lcm,a,b,c,A,B,C,i=1;
    printf("input your n\n");
    scanf("%d",&n);
    printf("input your m\n");
    scanf("%d",&m);
    if(m>n){
        big=m;
        small=n;
    }
    else{
        big=n;
        small=m;
    }
    while (i<=small) {
        a=small/i;
        b=a*i;
        c=small-b;
        A=big/i;
        B=A*i;
        C=big-B;
        if(c==0 && C==0){
            gcd=i;
        }
        i=i+1;
    }
    printf("your gcd is:");
    printf("%d\n",gcd);
    lcm=big*small/gcd;
    printf("your lcm is:");
    printf("%d\n",lcm);




    return 0;
}
