//MADE BY SEPANTAPOOYA
//COPING OR USING JUST BY MENTIONING MY NAME
#include <stdio.h>

int main()
{
    int a;
    int b;
    int n;
    int m;
    printf("input your number\n");
    scanf("%d",&m);
    a=1;
    b=1;
    printf("%d",a);
    printf("_");
    printf("%d",b);
    printf("_");
    n=a+b;
    while(n<m){
        printf("%d",n);
        printf("_");
        a=b;
        b=n;
        n=a+b;
    }

    printf("\n\n");
    return 0;
}

