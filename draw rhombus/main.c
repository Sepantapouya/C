//MADE BY SEPANTA POOYA
//COPING OR USING JUST BY MENTIONING MY NAME
#include <stdio.h>

int main()
{
    int n,star,lines,lines_i=1,star_i=0,space,space_i=0;
    printf("input your n\n");
    scanf("%d",&n);
    lines=n;
    space=lines-1;
    while (lines_i<=lines) {
        while (space_i<space) {
            printf(" ");
            space_i=space_i+1;
        }
        star=(2*lines_i)-1;
        while (star_i<star) {
            printf("*");
            star_i=star_i+1;
        }
        printf("\n");
        star_i=0;
        lines_i=lines_i+1;
        space=space-1;
        space_i=0;
    }
    lines=n-1;
    lines_i=lines;
    space=1;
    while (lines_i>0) {
        while (space_i<space) {
            printf(" ");
            space_i=space_i+1;
        }
        star=(2*lines_i)-1;
        while (star_i<star) {
            printf("*");
            star_i=star_i+1;
        }
        printf("\n");
        space=space+1;
        star_i=0;
        space_i=0;
        lines_i=lines_i-1;

    }


    return 0;
}

