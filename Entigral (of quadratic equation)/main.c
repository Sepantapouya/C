//MADE BY SEPANTAPOOYA
//COPING OR USING JUST BY MENTIONING MY NAME

#include <stdio.h>
//////////////////////////////////////////////////////////////////////////
struct Quadratic_equation{
  double a,b,c;
};
struct x{
    double x1,x2;
};
//////////////////////////////////////////////////////////////////////////
struct Quadratic_equation input (void);
struct x input2 (void);
double quadratic_equation (struct Quadratic_equation,struct x);
double calculate (struct Quadratic_equation,double);
void print (double);

//////////////////////////////////////////////////////////////////////////
int main()
{
    struct Quadratic_equation a;
    struct x b;
    double c;
    a=input();
    b=input2();
    c=quadratic_equation(a,b);
    print(c);
    return 0;
}
//////////////////////////////////////////////////////////////////////////
struct Quadratic_equation input (void){
    struct Quadratic_equation a;
    printf("input 'a' of your  Quadratic equation\n");
    scanf("%lf",& a.a);
    printf("input 'b' of your  Quadratic equation\n");
    scanf("%lf",& a.b);
    printf("input 'c' of your  Quadratic equation\n");
    scanf("%lf",& a.c);
    return a;
}
//////////////////////////////////////////////////////////////////////////
struct x input2 (void){
    struct x a;
    printf("input 'x1' (minimum) \n");
    scanf("%lf",& a.x1);
    printf("input 'x2' (maximum)\n");
    scanf("%lf",& a.x2);
    return a;
}
//////////////////////////////////////////////////////////////////////////
double calculate (struct Quadratic_equation a, double b){
    double y;
    y=(a.a)*b*b+(a.b)*b+(a.c);
    return y;

}
//////////////////////////////////////////////////////////////////////////
double quadratic_equation (struct Quadratic_equation a,struct x b){
    // y = (a.a) x^2 +(a.b) x + (a.c)
    double sum=0,temp=0,x=b.x1,X=0,y=0,Y=0;
    while(x<b.x2){
        X=x+0.001;
        y=calculate(a,x);
        Y=calculate(a,X);
        temp=((y+Y)/2)*0.001;
        sum+=temp;
        x=X;
    }
    return sum;
}
//////////////////////////////////////////////////////////////////////////
void print (double a){
    printf("your intigral is=%lf\n",a);
}

