//MADE BY SEPANTAPOOYA
//COPING OR USING JUST BY MENTIONING MY NAME
#include <stdio.h>
struct point {
     double a[500];
     int n;
};
int log(int m);
struct point input (void);
double input2 (void);
void print (struct point);
double biggest (struct point);
double smallest (struct point);
struct point order (struct point,double,double);
 int search (struct point,double);


int main()
{
    struct point ml,ml2;
    double big,small,x;
    int y;
    ml=input();
    big=biggest(ml);
    small=smallest(ml);
    ml2=order (ml,big,small);    
    print(ml2);
    x=input2();
    y=search(ml2,x);
    if(y!=-1)printf("your  place is = %d\n",y);
    else printf("your number not found.\n");
    return 0;
}

//////////////////////////////////////////////////////////
struct point input (void){
    struct point a;
    int i;
    do{
        printf("Enter 0<n<500:\n");
        scanf("%d",& a.n);
    }
    while(a.n<0 || a.n>500);
    for (i=1;i<=a.n;i++){
        printf("enter a[%d]=",i);
        scanf("%lf",& a.a[i]);
    }
    return a;
}
//////////////////////////////////////////////////////////
double input2 (void){
    double x;
    printf("input your x for search\n");
    scanf("%lf",&x);
    return x;
}
//////////////////////////////////////////////////////////
void print (struct point m){
    int i;
    for(i=1;i<m.n;i++){
        printf("a[%d]=%lf\n",i,m.a[i]);
    }
}
//////////////////////////////////////////////////////////
double biggest (struct point m){
    int i=1,t=1;
    double biggest;
    for (;i<=m.n;){
        biggest=m.a[i];
        while (i<=m.n) {
           i=i+1;
           if(m.a[i]>=m.a[t]){
               biggest=m.a[i];
               m.a[t]=m.a[i];
           }

        }
    }
    return biggest;

}
//////////////////////////////////////////////////////////
double smallest (struct point m){
    int i=1,t=1;
    double smallest;
    for (;i<=m.n;){
        smallest=m.a[i];
        while (i<=m.n) {
           i=i+1;
           if(m.a[i]<=m.a[t]){
               smallest=m.a[i];
               m.a[t]=m.a[i];
           }

        }
    }
    return smallest;

}
//////////////////////////////////////////////////////////
struct point order (struct point ml1,double big,double small){
    struct point ml2;
    int i,I=1;
    int t=big;
    while(t>=small){
        for (i=1;i<=ml1.n;i++){
            if(ml1.a[i]==t ){
                ml2.a[I]=ml1.a[i];
                I=I+1;
                ml1.a[i]=small-1;

            }
        }
        t=t-1;
    }
    return ml2;

}
//////////////////////////////////////////////////////////
int log(int m){
    int i=2;
    while(m>0){
        m/=2;
        i++;
    }
    return i;
}
int search (struct point a,double x){
    int i=0,j=a.n,t,s;
    s=log(a.n);
    do{
        t=(i+j)/2;
        if(x<a.a[t]) i=t;
        if(x>a.a[t]) j=t;
        if(x==a.a[t]) return t;
        s--;
    }while(s>0);
    return -1;
}







