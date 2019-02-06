// idea has gotten from --> https://stackoverflow.com/questions/47751272/draw-shapes-using-c-language-without-graphics-library
// edit and remake by SEPANTA POOYA

#include <stdio.h>
/////////////////////////////////////////////////////////////////////////
int calculate(int x, int y, int radius);
void draw_circle(int radius);
/////////////////////////////////////////////////////////////////////////
int main(){
    int r;
    printf("enter your radius\n");
    printf("STRONGLY SUGGEST FOR YOUR RADIUS TO BE MORE THAN 20 TO MAKE YOUR CIRCLE LOOK  REAL \n");
    scanf("%d",&r);
    draw_circle(r);
    printf("\n");
}
//////////////////////////////////////////////////////////////////////////
void draw_circle(int radius)
{
        int x, y;
        for (x=-20; x<=20; x++) {
                for (y=20; y>=-20; y--) {
                        if (calculate(x, y, radius) < 0) printf("  ");
                        else printf("**");
                }
                printf("\n");
        }
}
//////////////////////////////////////////////////////////////////////////
int calculate(int x, int y, int radius)
{
    int checker = (x*x)+(y*y)-radius;
    return checker;
}




///////////
//LAST TRY///////////////////////////////////////////////////////////////////
/*struct point {
    int x;
    int y;
};
int calculate( struct point o ,double x ,double y ,int r );
///////////////////////////////////////////////////
int main()
{
    /////////
    struct point o;
    printf("input your circle center (first x and after that y) \n");
    scanf("%d",&o.x);
    scanf("%d",&o.y);
    /////////
    int r,new_r;
    struct point new_o;
    new_o.x=o.x/100;
    new_o.y=o.y/100;
    printf("input your ray");
    scanf("%d",&r);
    new_r=r/100;
    /////////
    double x,y,yy=0;
    int res;
    for(y=5;y>=-5;y=y-0.001,yy=yy+0.001){
         for(x=-5;x<=5;x=x+0.001){
             res=calculate(new_o,x,y,new_r);
             if (res==1) printf("*");
             if (res==0) printf(" ");
             if   (x==0) printf("|");
         }
         if (yy==1){
             printf("\n");
             yy=0;
         }
         if (y==0){
             for(x=-5;x<=5;x++){
                printf("-");
             }
             printf("\n");
         }
    }
    return 0;
}
////////////////////////////////////////////////////
int calculate( struct point a,double x ,double y,int r ){
    int res;
    if(((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y)-r*r)==0) res=1;
    else res=0;
    return res;*/
