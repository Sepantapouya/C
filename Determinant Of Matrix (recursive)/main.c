//MADE BY SEPANTAPOOYA
//COPING OR USING JUST BY MENTIONING MY NAME

#include <stdio.h>
//////////////////////////
struct matrix {
    double a[100][100];
    int x,y;
};
struct minus {
    double a[100];
    int x;
};
//////////////////////////
struct matrix input (void);
void print_shape (struct matrix);
double recursive_determinant(struct matrix);
void print_result (double);
/////////////////////////////////////////////////////////////
int main()
{
    struct matrix a;
    double res;
    printf("your matris must be like a square\n");
    a=input();
    print_shape(a);
    res=recursive_determinant(a);
    print_result(res);
    return 0;
}
/////////////////////////////////////////////////////////////
struct matrix input (void){
    struct matrix a;
    do{
        printf("input x 2=<x=<100\n");
        scanf("%d",&a.x);
    }while(a.x<2 || a.x>100);

    /*do{
        printf("input n(y) 0=<n=<100\n");
        scanf("%d",&a.n);
    }while(a.n<0 || a.n>100);*/

    a.y=a.x;

    int i,j;

    for(j=1;j<=a.y;j++){
        for(i=1;i<=a.x;i++){
            printf("input a[%d][%d]\n",i,j);
            scanf("%lf",&a.a[i][j]);
        }
    }
    return a;
}
/////////////////////////////////////////////////////////////
void print_shape (struct matrix a){
    int i,j;
    printf("___________________________________________\n\n");
    for(j=1;j<=a.y;j++){
        for(i=1;i<=a.x;i++){
            printf("%lf\t",a.a[i][j]);
        }
        printf("\n");
    }
    printf("___________________________________________\n");
}
/////////////////////////////////////////////////////////////
double recursive_determinant(struct matrix a){
    if(a.x==2){
        double A,B,res;
        A=a.a[1][1]*a.a[2][2];
        B=a.a[2][1]*a.a[1][2];
        res=A-B;
        return res;
    }
    if(a.x==3){
        double A,B,C,D,E,F,res;
        A=a.a[1][1]*a.a[2][2]*a.a[3][3];
        B=a.a[2][1]*a.a[3][2]*a.a[1][3];
        C=a.a[3][1]*a.a[1][2]*a.a[2][3];
        D=a.a[3][1]*a.a[2][2]*a.a[1][3];
        E=a.a[2][1]*a.a[1][2]*a.a[3][3];
        F=a.a[1][1]*a.a[3][2]*a.a[2][3];
        res=A+B+C-D-E-F;
        return res;
    }
    struct matrix c;
    if(a.x > 3){
        double res=0;
        int sign=1,I=1,i,j,t;
        while(I<=a.x){
            c=a;
            for(j=1;j<=c.y;j++,t++){
                for(i=1;i<=c.x;i++){
                    if(i<I) c.a[i][j]=a.a[i][j+1];
                    else c.a[i][j]=a.a[i+1][j+1];
                    c.x=a.x-1;
                    c.y=a.y-1;
                }
            }

            print_shape(c);
            res=res+(recursive_determinant(c)*sign*a.a[I][1]);
            sign=sign*-1;
            I++;
        }
        printf("%lf",res);
        return res;
    }
}
/////////////////////////////////////////////////////////////
void print_result (double res){
    printf("your result is=%lf\n",res);
}
/////////////////////////////////////////////////////////////

