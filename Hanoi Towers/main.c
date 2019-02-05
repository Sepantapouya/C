//MADE BY SEPANTAPOOYA
//COPING OR USING JUST BY MENTIONING MY NAME

#include <stdio.h>
///////////////////////////////////////////////////////////////////
int disks_number (void);
int input (void);
void hanoi_recursive(int,int,int,int);

///////////////////////////////////////////////////////////////////
int main()
{
    int n,start,help,end;
    n=disks_number();
    do{
        printf("input your starting line (must be 0 or 1 or 2)\n");
        start=input();
    }while(start<0 || start>2);
    //////////////
    do {
        printf("input your helping line (Generally must be 0 or 1 or 2 and not %d(becuase %d is starting line )) \n",start,start);
        help=input();
    }while(help<0 || help>2 || help==start);
    //////////////
    do{
        printf("input your ending line ( Generally must be 0 or 1 or 2 and not %d and %d(becuase %d  and %d are starting and helping lines )) \n",start,help,start,help );
        end=input();
    }while(end<0 || end >2 || end==start || end==help);
    hanoi_recursive(n,start,help,end);

    return 0;
}
///////////////////////////////////////////////////////////////////
int disks_number (void){
    int n;
    printf("Input your disks number \n");
    scanf("%d",&n);
    return n ;
}
///////////////////////////////////////////////////////////////////
int input (void){
    int a;
    scanf("%d",&a);
    return a;
}
///////////////////////////////////////////////////////////////////
void hanoi_recursive(int disks ,int start ,int help ,int end){
    if(disks==1){
        printf("transfer disk %d kg from %d to %d \n",disks, start,end);
    }
    if(disks>1){
        hanoi_recursive(disks-1,start,end,help);
        printf("transfer disk %d kg from %d to %d \n",disks, start,end);
        hanoi_recursive(disks-1,help,start,end);
    }

}

