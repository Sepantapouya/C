//MADE BY SEPANTA POOYA
//COPYING  OR USING JUST WITH MENTIONING MY NAME
#include <stdio.h>

int main()
{
    int n,lines,lines_i=1,space,space_i=0,spacemain=0,spacemain_i=0;
    printf("input your n\n");
    scanf("%d",&n);
    lines=n;
    space=lines-1;
    while (lines_i<=lines) {
        spacemain=(2*(lines_i-1))-1;
        while (space_i<space) {
            printf(" ");
            space_i=space_i+1;
        }
        printf("*");
        while (spacemain_i<spacemain) {
            printf(" ");
            spacemain_i=spacemain_i+1;
        }
        if(spacemain>=0){
                printf("*");
        }
        printf("\n");
        lines_i=lines_i+1;
        space=space-1;
        space_i=0;
        spacemain_i=0;

    }
    lines=n-1;
    lines_i=lines;
    space=1;
    int new;
    new=n-2;
    while (lines_i>0) {
        spacemain=(2*new)-1;
        while (space_i<space) {
            printf(" ");
            space_i=space_i+1;
        }
        printf("*");
        while (spacemain_i<spacemain) {
            printf(" ");
            spacemain_i=spacemain_i+1;
        }
        if(spacemain>=0){
                printf("*");
        }
        printf("\n");
        space=space+1;
        space_i=0;
        lines_i=lines_i-1;
        new=new-1;
        spacemain_i=0;

    }


    return 0;
}

