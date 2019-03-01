#include <stdio.h>
#include <stdlib.h>
/////////////////////////////////////////////////////////////
char USERNAME[10];
char PASSWORD[10];
char FOOD[54];
char *finance=0;
int I;
int F;
int N;
FILE *dt=0;
/////////////////////////////////////////////////////////////
typedef struct days{
    int weak_days;  //1 for sat     2 for sun    3 for mon      4 for tue    5 for wed      6 for thu
    //int days_food;  //1 for breakfast   2 for lunch     3 for dinner
    int breakfast[3];
    int lunch[8];
    int dinner[7];
    struct days* next;
}days;
/////////////////////////////////////////////////////////////
typedef struct food_name{
    char* name_breakfast[3];
    char* name_lunch[8];
    char* name_dinner[7];
    struct food_name* next;
}food_name;
/////////////////////////////////////////////////////////////
typedef struct student{
    //char name[100];
    char code[10];
    int money;
    struct student* next;
}student;
/////////////////////////////////////////////////////////////
days jome;
food_name jome_name;
/////////////////////////////////////////////////////////////
void tat (void);
void save (void);
void Show_Money(void);
void Increase_Money(void);
void Decrease_Money(int,days*,int ,int );
///
void days_food (days*,food_name* );
int week_selection(void);
int day_selection(void);
int food(int ,int );
int reverse(int);
void test (void);
void sepi_panel();
int sepi_panel_menu();
long long int change_char_int(void);
void reserve_food_panel();
long long int arrti (char *);
int computation_N();
void open (void);
void login (void);
int fin (void);
void first_meal (void);
void reg (void);
void my_switch (void);
void aus (void);
void super_menu (void);
void whfood (int d, int m);
void edit_user ();
void edit_food ();
void show_reserved_food(void);
void search_show_reserved_food(int a,int b,int c);
/////////////////////////////////////////////////////////////
int main(){

    days_food(& jome,& jome_name);
       super_menu();
    ////

    return 0;
}
/////////////////////////////////////////////////////////////

void Show_Money(void){
     int i;
    for(i=0;i<20;i++){
            printf(" ");
    }
    printf("your account charge is :\t");

    for(i=0;i<N;i++)
        printf("%c",finance[i]);
	printf(" Rials\n");
}

/////////////////////////////////////////////////////////////

void Increase_Money(void){
   long long int money;
    int increase,i=0;
    for(i=0;i<20;i++){
            printf(" ");
    }
    printf("Enter how much you want to charge your account :\n");
    for(i=0;i<20;i++){
            printf(" ");
    }
    scanf("%d",&increase);
    money=change_char_int();
    money+=increase;
    N=computation_N(money);
    sprintf(finance,"%lli",money);
    Show_Money();
    sepi_panel();
}

/////////////////////////////////////////////////////////////

void Decrease_Money(int a,days*jome,int b,int c){
      days* ptr=jome;
    long long int money;
    int price=0;
    int i;
    for(i=0;i<a;i++){
        ptr=ptr->next;
    }
    if(b==1){
            price=ptr->breakfast[c];
    }
    if(b==2){
            price=ptr->lunch[c];
    }
    if(b==3){
            price=ptr->dinner[c];
    }
    printf("                    price=%d Rials\n",price);
    money=change_char_int();
    if(money>=price){
        money-=price;
        N=computation_N(money);
        sprintf(finance,"%lli",money);

    }
    else{
        for(i=0;i<20;i++){
                printf(" ");
        }
        printf("your account charge is not enough.\n");
        sepi_panel();
    }
}

/////////////////////////////////////////////////////////////

void days_food (days* jome,food_name* jome_name){
   jome->next=(days*)malloc(sizeof(days));
    days* shanbe=jome->next;
    shanbe->next=0;
    shanbe->weak_days=1;
    ///

    jome_name->next=(food_name*)malloc(sizeof(food_name));
    food_name* shanbe_food=jome_name->next;
    shanbe_food->next=0;

    shanbe->breakfast[1]=30000; //omlet
    shanbe_food->name_breakfast[1]="omlet\0";
    shanbe->breakfast[2]=20000; //nano halva
    shanbe_food->name_breakfast[2]="nano halva\0";

    shanbe->lunch[1]=60000;  //zereshk polo ba morgh + dogh
    shanbe_food->name_lunch[1]="zereshk polo ba morgh + dogh\0";
    shanbe->lunch[2]=50000;  //adas polo keshmeshe adi + salade kalam
    shanbe_food->name_lunch[2]="adas polo keshmeshe adi + salade kalam\0";
    shanbe->lunch[3]=80000;  //chelo joje kababe tak
    shanbe_food->name_lunch[3]="chelo joje kababe tak\0";
    shanbe->lunch[4]=90000;  //chelo kabab hosseini tak
    shanbe_food->name_lunch[4]="chelo kabab hosseini tak\0";
    shanbe->lunch[5]=50000;  //kashk va bademjan tak
    shanbe_food->name_lunch[5]="kashk va bademjan tak\0";
    shanbe->lunch[6]=10;     //yarane 3200 tak
    shanbe_food->name_lunch[6]="yarane 3200 tak\0";
    shanbe->lunch[7]=10;     //yarane 2000 bofe tabiat
    shanbe_food->name_lunch[7]="yarane 2000 bofe tabiat\0";

    shanbe->dinner[1]=40000; //shevid polo tone mahi adi + abmive
    shanbe_food->name_dinner[1]="shevid polo tone mahi adi + abmive\0";
    shanbe->dinner[2]=50000; //abgosht adi+torshi
    shanbe_food->name_dinner[2]="abgosht adi+torshi\0";
    shanbe->dinner[3]=60000; //salad kardinal tak
    shanbe_food->name_dinner[3]="salad kardinal tak\0";
    shanbe->dinner[4]=80000; //dolme felfel sabz tak
    shanbe_food->name_dinner[4]="dolme felfel sabz tak\0";
    shanbe->dinner[5]=10;    //khorak salad olovie tak
    shanbe_food->name_dinner[5]="khorak salad olovie tak\0";
    shanbe->dinner[6]=10;    //yarane 3200 tak
    shanbe_food->name_dinner[5]="yarane 3200 tak\0";

    shanbe->next=(days*)malloc(sizeof(days));
    days* yek_shanbe=shanbe->next;
    yek_shanbe->next=0;
    yek_shanbe->weak_days=2;

    shanbe_food->next=(food_name*)malloc(sizeof(food_name));
    food_name* yek_shanbe_food=shanbe_food->next;
    yek_shanbe_food->next=0;

    yek_shanbe->breakfast[1]=30000; //adasi
    yek_shanbe_food->name_breakfast[1]="adasi\0";
    yek_shanbe->breakfast[2]=20000; //nano paniro shir
    yek_shanbe_food->name_breakfast[2]="nano paniro shir\0";

    yek_shanbe->lunch[1]=50000;  //chelo khoresht sabzi adi + mive
    yek_shanbe_food->name_lunch[1]="chelo khoresht sabzi adi + mive\0";
    yek_shanbe->lunch[2]=30000;  //lobia polo adi+masto khiar
    yek_shanbe_food->name_lunch[2]="lobia polo adi+masto khiar\0";
    yek_shanbe->lunch[3]=70000;  //shevid polo mahi ghezel ala tak
    yek_shanbe_food->name_lunch[3]="shevid polo mahi ghezel ala tak\0";
    yek_shanbe->lunch[4]=80000;  //chelo khoresht gheime tak
    yek_shanbe_food->name_lunch[4]="chelo khoresht gheime tak\0";
    yek_shanbe->lunch[5]=90000;  //chelo meigo sokhari tak
    yek_shanbe_food->name_lunch[5]="chelo meigo sokhari tak\0";
    yek_shanbe->lunch[6]=10;     //yarane 3200 tak
    yek_shanbe_food->name_lunch[6]="yarane 3200 tak\0";
    yek_shanbe->lunch[7]=10;     //yarane 2000 bofe tabiat
    yek_shanbe_food->name_lunch[7]="yarane 2000 bofe tabiat\0";

    yek_shanbe->dinner[1]=30000; //koko sib zamini adi +dogh
    yek_shanbe_food->name_dinner[1]="koko sib zamini adi +dogh\0";
    yek_shanbe->dinner[2]=40000; //chelo khoresht mosama kado adi + mast
    yek_shanbe_food->name_dinner[2]="chelo khoresht mosama kado adi + mast\0";
    yek_shanbe->dinner[3]=60000; //mirza ghasemi tak
    yek_shanbe_food->name_dinner[3]="mirza ghasemi tak\0";
    yek_shanbe->dinner[4]=70000; //khorake shenisel morgh tak
    yek_shanbe_food->name_dinner[4]="khorake shenisel morgh tak\0";
    yek_shanbe->dinner[5]=10;    //nano paniro sib zamini tak
    yek_shanbe_food->name_dinner[5]="nano paniro sib zamini tak\0";
    yek_shanbe->dinner[6]=10;    //yarane 3200 tak
    yek_shanbe_food->name_dinner[6]="yarane 3200 tak\0";
    ////////////////////////////
    yek_shanbe->next=(days*)malloc(sizeof(days));
    days* do_shanbe=yek_shanbe->next;
    do_shanbe->next=0;
    do_shanbe->weak_days=3;
    ////
    yek_shanbe_food->next=(food_name*)malloc(sizeof(food_name));
    food_name* do_shanbe_food=yek_shanbe_food->next;
    do_shanbe_food->next=0;

    do_shanbe->breakfast[1]=20000;   //khame asali
    do_shanbe_food->name_breakfast[1]="khame asali\0";
    do_shanbe->breakfast[2]=10000;   //nano kare moraba
    do_shanbe_food->name_breakfast[2]="nano kare moraba\0";

    do_shanbe->lunch[1]=40000;   //chelo joje kabab adi+dogh
    do_shanbe_food->name_lunch[1]="chelo joje kabab adi+dogh\0";
    do_shanbe->lunch[2]=30000;   //chelo goshto gharch adi + salad
    do_shanbe_food->name_lunch[2]="chelo goshto gharch adi + salad\0";
    do_shanbe->lunch[3]=80000;   //chelo kabab kobide tak
    do_shanbe_food->name_lunch[3]="chelo kabab kobide tak\0";
    do_shanbe->lunch[4]=60000;   //estanboli polo tak
    do_shanbe_food->name_lunch[4]="estanboli polo tak\0";
    do_shanbe->lunch[5]=70000;   //chelo kabab chobi morgh tak
    do_shanbe_food->name_lunch[5]="chelo kabab chobi morgh tak\0";
    do_shanbe->lunch[6]=10;      //yarane 3200 tak
    do_shanbe_food->name_lunch[6]="yarane 3200 tak\0";
    do_shanbe->lunch[7]=10;      //yarane 2000 bofe tabiat
    do_shanbe_food->name_lunch[7]="yarane 2000 bofe tabiat\0";

    do_shanbe->dinner[1]=40000;  //makaroni ba goosht adi+salad
    do_shanbe_food->name_dinner[1]="makaroni ba goosht adi+salad\0";
    do_shanbe->dinner[2]=30000;  //khorak loobia chity ba tokhm morgh + dorchin
    do_shanbe_food->name_dinner[2]="khorak loobia chity ba tokhm morgh + dorchin\0";
    do_shanbe->dinner[3]=70000;  //chelo khoresht sabzi tak
    do_shanbe_food->name_dinner[3]="chelo khoresht sabzi tak\0";
    do_shanbe->dinner[4]=60000;  //khorak hamberger tak
    do_shanbe_food->name_dinner[4]="khorak hamberger tak\0";
    do_shanbe->dinner[5]=10;     //soup jo + tokhm morgh va sibzamini tak
    do_shanbe_food->name_dinner[5]="soup jo + tokhm morgh va sibzamini tak\0";
    do_shanbe->dinner[6]=10;     //yarane 3200 tak
    do_shanbe_food->name_dinner[6]="yarane 3200 tak\0";
    ////////////////////////////
    do_shanbe->next=(days*)malloc(sizeof(days));
    days* se_shanbe=do_shanbe->next;
    se_shanbe->next=0;
    se_shanbe->weak_days=4;
    ////
    do_shanbe_food->next=(food_name*)malloc(sizeof(food_name));
    food_name* se_shanbe_food=do_shanbe_food->next;
    se_shanbe_food->next=0;

    se_shanbe->breakfast[1]=30000;   //adasi
    se_shanbe_food->name_breakfast[1]="adasi\0";
    se_shanbe->breakfast[2]=20000;   //nano halva
    se_shanbe_food->name_breakfast[2]="nano halva\0";

    se_shanbe->lunch[1]=30000;   //chelo khoresht gheime adi + mast
    se_shanbe_food->name_lunch[1]="chelo khoresht gheime adi + mast\0";
    se_shanbe->lunch[2]=20000;   //kashk va bademjan adi + abmive
    se_shanbe_food->name_lunch[2]="kashk va bademjan adi + abmive\0";
    se_shanbe->lunch[3]=70000;   //zereshk polo ba morgh tak
    se_shanbe_food->name_lunch[3]="zereshk polo ba morgh tak\0";
    se_shanbe->lunch[4]=50000;   //koko sabzi tak
    se_shanbe_food->name_lunch[4]="koko sabzi tak\0";
    se_shanbe->lunch[5]=50000;   //adas polo keshmeshe tak
    se_shanbe_food->name_lunch[5]="adas polo keshmeshe tak\0";
    se_shanbe->lunch[6]=10;      //yarane 3200 tak
    se_shanbe_food->name_lunch[6]="yarane 3200 tak\0";
    se_shanbe->lunch[7]=10;      //yarane 2000 bofe tabiat
    se_shanbe_food->name_lunch[7]="yarane 2000 bofe tabiat\0";

    se_shanbe->dinner[1]=30000;  //estanboli polo adi + masto khiar
    se_shanbe_food->name_dinner[1]="estanboli polo adi + masto khiar\0";
    se_shanbe->dinner[2]=20000;  //halim + mive
    se_shanbe_food->name_dinner[2]="halim + mive\0";
    se_shanbe->dinner[3]=80000;  //khorak kabab tabe i tak
    se_shanbe_food->name_dinner[3]="khorak kabab tabe i tak\0";
    se_shanbe->dinner[4]=70000;  //khorak morgh o gharch tak
    se_shanbe_food->name_dinner[4]="khorak morgh o gharch tak\0";
    se_shanbe->dinner[5]=80000;  //abgosht sonati tak
    se_shanbe_food->name_dinner[5]="abgosht sonati tak\0";
    se_shanbe->dinner[6]=10;     //yarane 3200 tak
    se_shanbe_food->name_dinner[6]="yarane 3200 tak\0";

    ////////////////////////////
    se_shanbe->next=(days*)malloc(sizeof(days));
    days* char_shanbe=se_shanbe->next;
    char_shanbe->next=0;
    char_shanbe->weak_days=5;
    ////
    se_shanbe_food->next=(food_name*)malloc(sizeof(food_name));
    food_name* char_shanbe_food=se_shanbe_food->next;
    char_shanbe_food->next=0;

    char_shanbe->breakfast[1]=20000; //fereni + panir
    char_shanbe_food->name_breakfast[1]="fereni + panir\0";
    char_shanbe->breakfast[2]=30000; //nano kare va asal
    char_shanbe_food->name_breakfast[2]="nano kare va asal\0";

    char_shanbe->lunch[1]=20000;  //shevid polo khorak tone mahi adi + khorma
    char_shanbe_food->name_lunch[1]="shevid polo khorak tone mahi adi + khorma\0";
    char_shanbe->lunch[2]=30000;  //chelo khoresht lobia sabzi adi + masto khiar
    char_shanbe_food->name_lunch[2]="chelo khoresht lobia sabzi adi + masto khiar\0";
    char_shanbe->lunch[3]=80000;  //chelo kabab bakhtiari tak
    char_shanbe_food->name_lunch[3]="chelo kabab bakhtiari tak\0";
    char_shanbe->lunch[4]=90000;  //khorak belderchin kababi tak
    char_shanbe_food->name_lunch[4]="khorak belderchin kababi tak\0";
    char_shanbe->lunch[5]=50000;  //kashk va bademjan tak
    char_shanbe_food->name_lunch[5]="kashk va bademjan tak\0";
    char_shanbe->lunch[6]=10;     //yarane 3200 tak
    char_shanbe_food->name_lunch[6]="yarane 3200 tak\0";
    char_shanbe->lunch[7]=10;     //yarane 2000 bofe tabiat
    char_shanbe_food->name_lunch[6]="yarane 2000 bofe tabiat\0";

    char_shanbe->dinner[1]=30000;    //chelo morgh beryan adi + soup
    char_shanbe_food->name_dinner[1]="chelo morgh beryan adi + soup\0";
    char_shanbe->dinner[2]=20000;    //nano paniro sibzamini adi + ash reshte
    char_shanbe_food->name_dinner[2]="nano paniro sibzamini adi + ash reshte\0";
    char_shanbe->dinner[3]=60000;    //makaroni ba goosht tak
    char_shanbe_food->name_dinner[3]="makaroni ba goosht tak\0";
    char_shanbe->dinner[4]=80000;    //dolme felfel sabz tak
    char_shanbe_food->name_dinner[4]="dolme felfel sabz tak\0";
    char_shanbe->dinner[5]=10;       //soup jo + tokhm morgh va sib zmini tak
    char_shanbe_food->name_dinner[5]="soup jo + tokhm morgh va sib zamini tak\0";
    char_shanbe->dinner[6]=10;       //yarane 3200 tak
    char_shanbe_food->name_dinner[6]="yarane 3200 tak\0";


    ////////////////////////////
    char_shanbe->next=(days*)malloc(sizeof(days));
    days* panj_shanbe=char_shanbe->next;
    panj_shanbe->next=0;
    panj_shanbe->weak_days=6;
    /////
    char_shanbe_food->next=(food_name*)malloc(sizeof(food_name));
    food_name* panj_shanbe_food=char_shanbe_food->next;
    panj_shanbe_food->next=0;

    panj_shanbe->breakfast[1]=30000; //adasi
    panj_shanbe_food->name_breakfast[1]="adasi\0";
    panj_shanbe->breakfast[2]=20000; //nano halva
    panj_shanbe_food->name_breakfast[2]="nano halva\0";

    panj_shanbe->lunch[1]=40000; //chelo joje kabab adi+dogh
    panj_shanbe_food->name_lunch[1]="chelo joje kabab adi+dogh\0";
    panj_shanbe->lunch[2]=30000; //lobia polo adi+masto khiar
    panj_shanbe_food->name_lunch[2]="lobia polo adi+masto khiar\0";
    panj_shanbe->lunch[3]=60000; //mirza ghasemi tak
    panj_shanbe_food->name_lunch[3]="mirza ghasemi tak\0";
    panj_shanbe->lunch[4]=60000; //estanboli polo tak
    panj_shanbe_food->name_lunch[4]="estanboli polo tak\0";
    panj_shanbe->lunch[5]=70000; //chelo kabab chobi morgh tak
    panj_shanbe_food->name_lunch[5]="chelo kabab chobi morgh tak\0";
    panj_shanbe->lunch[6]=10;    //yarane 3200 tak
    panj_shanbe_food->name_lunch[6]="yarane 3200 tak\0";
    panj_shanbe->lunch[7]=10;   //yarane 2000 bofe tabiat
    panj_shanbe_food->name_lunch[7]="yarane 2000 bofe tabiat\0";

    panj_shanbe->dinner[1]=30000;    //chelo khoresht gheime adi + mast
    panj_shanbe_food->name_dinner[1]="chelo khoresht gheime adi + mast\0";
    panj_shanbe->dinner[2]=30000;    //khorak loobia chity ba tokhm morgh + dorchin
    panj_shanbe_food->name_dinner[2]="khorak loobia chity ba tokhm morgh + dorchin\0";
    panj_shanbe->dinner[3]=60000;    //salad kardinal tak
    panj_shanbe_food->name_dinner[3]="salad kardinal tak\0";
    panj_shanbe->dinner[4]=50000;    //koko sabzi tak
    panj_shanbe_food->name_dinner[4]="koko sabzi tak\0";
    panj_shanbe->dinner[5]=50000;    //adas polo keshmeshe tak
    panj_shanbe_food->name_dinner[5]="adas polo keshmeshe tak\0";
    panj_shanbe->dinner[6]=10;       //yarane 3200 tak
    panj_shanbe_food->name_dinner[6]="yarane 3200 tak\0";
}

/////////////////////////////////////////////////////////////

int week_selection(void){
    int a;
       do{
        printf("                    Enter 1 for selecting food in shanbe \n");
        printf("                    Enter 2 for selecting food in yek_shanbe \n");
        printf("                    Enter 3 for selecting food in do_shanbe \n");
        printf("                    Enter 4 for selecting food in se_shanbe \n");
        printf("                    Enter 5 for selecting food in char_shanbe \n");
        printf("                    Enter 6 for selecting food in panj_shanbe \n                    ");
        scanf("%d",&a);
    }while (a<1 || a>6);
    return a;
}

////////////////////////////////////////////////////////////

int day_selection(void){
    int a;

    do{
        printf("                    Enter 1 for reserving food for breakfast\n");
        printf("                    Enter 2 for reserving food for lunch\n");
        printf("                    Enter 3 for reserving food for dinner\n                    ");
        scanf("%d",&a);
    }while (a<1 || a>3);
    return a;
}

////////////////////////////////////////////////////////////

int food(int week,int day){
    int i;
    printf("                    choose your food\n");
    if(week==1){
        if(day==1){
            do{
                printf("                    Enter 1 for omlet(30000 Rials) \n");
                printf("                    Enter 2 for nano halva(20000 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>2);
        }
        if(day==2){
            do{
                printf("                    Enter 1 for zereshk polo ba morgh + dogh(60000 Rials) \n");
                printf("                    Enter 2 for adas polo keshmeshe adi + salade kalam(50000 Rials) \n");
                printf("                    Enter 3 for chelo joje kababe tak(80000 Rials) \n");
                printf("                    Enter 4 for chelo kabab hosseini tak(90000 Rials) \n");
                printf("                    Enter 5 for kashk va bademjan tak(50000 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>7);
        }
        if(day==3){
            do{
                printf("                    Enter 1 for shevid polo tone mahi adi + abmive(40000 Rials) \n");
                printf("                    Enter 2 for abgosht adi+torshi(50000 Rials) \n");
                printf("                    Enter 3 for asalad kardinal tak(60000 Rials) \n");
                printf("                    Enter 4 for dolme felfel sabz tak(80000 Rials) \n");
                printf("                    Enter 5 for khork salad olovie tak(10 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                scanf("%d",&i);
            }while(i<1 || i>6);
        }
    }
    ///////////////////////////////////////////////////////////////////////////
    if(week==2){
        if(day==1){
            do{
                printf("                    Enter 1 for adasi(30000 Rials) \n");
                printf("                    Enter 2 for nano paniro shir(20000 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>2);
        }
        if(day==2){
            do{
                printf("                    Enter 1 for chelo khoresht sabzi adi + mive(50000 Rials) \n");
                printf("                    Enter 2 for lobia polo adi+masto khiar(30000 Rials) \n");
                printf("                    Enter 3 for shevid polo mahi ghezel ala tak(70000 Rials) \n");
                printf("                    Enter 4 for chelo khoresht gheime tak(80000 Rials) \n");
                printf("                    Enter 5 for chelo meigo sokhari tak(90000 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>7);
        }
        if(day==3){
            do{
                printf("                    Enter 1 for koko sib zamini adi +dogh(30000 Rials) \n");
                printf("                    Enter 2 for chelo khoresht mosama kado adi + mast(40000 Rials) \n");
                printf("                    Enter 3 for mirza ghasemi tak(60000 Rials) \n");
                printf("                    Enter 4 for khorake shenisel morgh tak(70000 Rials) \n");
                printf("                    Enter 5 for nano paniro sib zamini tak(10 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                scanf("%d",&i);
            }while(i<1 || i>6);
        }
    }
    ///////////////////////////////////////////////////////////////////////////
    if(week==3){
        if(day==1){
            do{
                printf("                    Enter 1 for khame asali(20000 Rials) \n");
                printf("                    Enter 2 for nano kare moraba(10000 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>2);
        }
        if(day==2){
            do{
                printf("                    Enter 1 for chelo joje kabab adi+dogh(40000 Rials) \n");
                printf("                    Enter 2 for chelo goshto gharch adi + salad(30000 Rials) \n");
                printf("                    Enter 3 for chelo kabab kobide tak(80000 Rials) \n");
                printf("                    Enter 4 for estanboli polo tak(6000 toman Rials) \n");
                printf("                    Enter 5 for chelo kabab chobi morgh tak(70000 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>7);
        }
        if(day==3){
            do{
                printf("                    Enter 1 for makaroni ba goosht adi+salad(40000 Rials) \n");
                printf("                    Enter 2 for khorak loobia chity ba tokhm morgh + dorchi(30000 Rials) \n");
                printf("                    Enter 3 for chelo khoresht sabzi tak (70000 Rials) \n");
                printf("                    Enter 4 for khorak hamberger tak(60000 Rials) \n");
                printf("                    Enter 5 for soup jo + tokhm morgh va sib zmini tak(10 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                scanf("%d",&i);
            }while(i<1 || i>6);
        }
    }
    ///////////////////////////////////////////////////////////////////////////
    if(week==4){
            if(day==1){
                do{
                    printf("                    Enter 1 for adasi(30000 Rials) \n");
                    printf("                    Enter 2 for nano halva(20000 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>2);
            }
            if(day==2){
                do{
                    printf("                    Enter 1 for chelo khoresht gheime adi + mast(30000 Rials) \n");
                    printf("                    Enter 2 for kashk va bademjan adi + abmive kalam(20000 Rials) \n");
                    printf("                    Enter 3 for zereshk polo ba morgh tak(70000 Rials) \n");
                    printf("                    Enter 4 for koko sabzi tak(50000 Rials) \n");
                    printf("                    Enter 5 for adas polo keshmeshe tak(50000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                    printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>7);
            }
            if(day==3){
                do{
                    printf("                    Enter 1 for estanboli polo adi + masto khiar(30000 Rials) \n");
                    printf("                    Enter 2 for halim + mive(20000 Rials) \n");
                    printf("                    Enter 3 for khorak kabab tabe i tak(80000 Rials) \n");
                    printf("                    Enter 4 for khorak morgh o gharch tak(70000 Rials) \n");
                    printf("                    Enter 5 for abgosht sonati tak(80000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>6);
            }
        }

    /////////////////////////////////////////////////////////////////////////////////////////////

    if(week==5){
            if(day==1){
                do{
                    printf("                    Enter 1 for fereni + panir(20000 Rials) \n");
                    printf("                    Enter 2 for nano kare va asal(30000 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>2);
            }
            if(day==2){
                do{
                    printf("                    Enter 1 for shevid polo khorak tone mahi adi + khorma(20000 Rials) \n");
                    printf("                    Enter 2 for chelo khoresht lobia sabzi adi + masto khiar(30000 Rials) \n");
                    printf("                    Enter 3 for chelo kabab bakhtiari tak(80000 Rials) \n");
                    printf("                    Enter 4 for khorak belderchin kababi tak(90000 Rials) \n");
                    printf("                    Enter 5 for kashk va bademjan tak(50000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                    printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>7);
            }
            if(day==3){
                do{
                    printf("                    Enter 1 for chelo morgh beryan adi + soup(30000 Rials) \n");
                    printf("                    Enter 2 for nano paniro sibzamini adi + ash reshte(20000 Rials) \n");
                    printf("                    Enter 3 for makaroni ba goosht tak(60000 Rials) \n");
                    printf("                    Enter 4 for soup jo + tokhm morgh va sib zmini tak(10 Rials) \n");
                    printf("                    Enter 5 for dolme felfel sabz tak(80000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>6);
            }
        }

    //////////////////////////////////////////////////////////////////////////////////////////

    if(week==6){
            if(day==1){
                do{
                    printf("                    Enter 1 for adasi(30000 Rials) \n");
                    printf("                    Enter 2 for nano halva(20000 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>2);
            }
            if(day==2){
                do{
                    printf("                    Enter 1 for chelo joje kabab adi+dogh(40000 Rials) \n");
                    printf("                    Enter 2 for lobia polo adi+masto khiar(30000 Rials) \n");
                    printf("                    Enter 3 for mirza ghasemi tak(60000 Rials) \n");
                    printf("                    Enter 4 for estanboli polo tak(60000 Rials) \n");
                    printf("                    Enter 5 for chelo kabab chobi morgh tak(70000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                    printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>7);
            }
            if(day==3){
                do{
                    printf("                    Enter 1 for chelo khoresht gheime adi + mast(30000 Rials) \n");
                    printf("                    Enter 2 for khorak loobia chity ba tokhm morgh + dorchin(30000 Rials) \n");
                    printf("                    Enter 3 for salad kardinal tak(60000 Rials) \n");
                    printf("                    Enter 4 for koko sabzi tak(50000 Rials) \n");
                    printf("                    Enter 5 for adas polo keshmeshe tak(50000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>6);
            }
        }
    return i;
}

////////////////////////////////////////////////////////////

int reverse(int a){
  int x,y,z,result=0;
  while(a>0){
    x=a/10;
    y=x*10;
    z=a-y;
    result+=z;
    result*=10;
    a=x;
  }
  return result/10;
}

////////////////////////////////////////////////////////////

void super_menu(void){
		printf("\n");
		printf("\n");
        for(int i=0;i<20;i++){//space
                printf(" ");
        }
    for(int i=0;i<60;i++){//#
                printf("#");
        }
    printf("\n");
    for(int i=0;i<8;i++){//$ first  $
                for(int i=0;i<20;i++){
                        printf(" ");
                }
                printf("$");
                for(int i=0;i<59;i++){
                        printf(" ");
                }
                printf("$\n");
        }

        for(int i=0;i<20;i++){//login
                printf(" ");
        }
        printf("$\t\t1 ===>> login");
        for(int i=0;i<35;i++){
                printf(" ");
        }

        printf("$\n");

        for(int i=0;i<20;i++){//register
                printf(" ");
        }
        printf("$\t\t2 ===>> Register");
        for(int i=0;i<32;i++){
                printf(" ");
        }

        printf("$\n");

        for(int i=0;i<20;i++){//Take a tour
                printf(" ");
        }
        printf("$\t\t3 ===>> Take a tour");
                for(int i=0;i<29;i++){
                printf(" ");
        }

        printf("$\n");

        for(int i=0;i<20;i++){//About us
                printf(" ");
        }
        printf("$\t\t4 ===>> About us");
        for(int i=0;i<32;i++){
                printf(" ");
        }

        printf("$\n");

                for(int i=0;i<20;i++){//Exit
                printf(" ");
        }
        printf("$\t\t0 ===>> Exit");
        for(int i=0;i<36;i++){
                printf(" ");
        }

        printf("$\n");

        for(int i=0;i<8;i++){//$ second $
                for(int i=0;i<20;i++){
                        printf(" ");
                }
                printf("$");
                for(int i=0;i<59;i++){
                        printf(" ");
                }
                printf("$\n");
        }
    for(int i=0;i<20;i++){//space
                printf(" ");
        }
    for(int i=0;i<60;i++){//#
        printf("#");
        }
        my_switch();
}

////////////////////////////////////////////////////////////

void my_switch (void){
        int s;
        printf("\n\n                    Enter your choise :\t");
        scanf("%d",&s);
        if(s==1){
                login();
        }
        else if(s==2){
                reg();
        }
        else if(s==3){
                tat();
        }
        else if(s==4){
                aus();
        }
        else if(s==0){
                printf("\n\n                    Bye Bye\tSee you soon :*)");
                exit(1);
        }
        else if(!(s==1||s==2||s==3||s==4||s==0)){
                printf("                    Wrong choise!\n                    Try again");
                my_switch();
        }
}

/////////////////////////////////////////////////////////////

void aus (void){
        printf("\n\n");
        for(int i=0;i<20;i++){//space
                printf(" ");
        }
        printf("Hi :)\n                    It's our project for university of Kashan !\n");
                for(int i=0;i<20;i++){//space
                printf(" ");
        }
        printf("We are four groupmates :\n");
                for(int i=0;i<20;i++){//space
                printf(" ");
        }
        printf("Sepanta Pooya\n                    Elahe Shapoori\n                    Salar Gholaminejad\n                    Omid Mazraati\n");
                for(int i=0;i<20;i++){//space
                printf(" ");
        }
        printf("Enjoy ;)");
        my_switch();
}


////////////////////////////////////////////////////////////

int fin (void){
        long long int tmp,j;
        int n=0;
        scanf("%lld",&tmp);
        j=tmp;
        while(j>0){
                j/=10;
                n++;
        }
        finance=(char *) malloc (n * sizeof(char));
        sprintf(finance,"%lli",tmp);
        return n;
}

////////////////////////////////////////////////////////////

void first_meal (void){
        int j,k,d;
        do{
        for(int i=0;i<20;i++){
                printf(" ");
        }
                printf("Enter a number between[1] to [6] :");
                scanf("%d",&j);
        }while(j>6 || j<1);
        d=j;
        j=((j*10)+2)*10;
        do{
                for(int i=0;i<20;i++){
                printf(" ");
        }
        printf("Enter a number between[1] to [7] :");
        scanf("%d",&k);
        }while(k>7 || k<1);
        sprintf(FOOD,"%d",(j+k));
        int x=0;
        for(int j=3;j<54;j++){
        sprintf(&FOOD[j],"%d",x);
        }
        printf("\n                    Your gift will be :\n");
        whfood(d,k);
}

////////////////////////////////////////////////////////////

void reg (void){
        dt=fopen("data.dat","a");

        for(int i=0;i<20;i++){
                printf(" ");
        }
        printf("Enter your USERNAME :\t");
        scanf("%s",USERNAME);

        for(int i=0;i<20;i++){
                printf(" ");
        }
        printf("Enter your PASSWORD :\t");
        scanf("%s",PASSWORD);

        for(int i=0;i<20;i++){
                printf(" ");
        }
        printf("Enter your first finance [Rial] :\t");
        int n=fin();

        for(int i=0;i<20;i++){
                printf(" ");
        }
        printf("Your first lunch meal will be our treat! :D\n");
        first_meal();

        fwrite(USERNAME, sizeof(char), 10, dt);
        fwrite(PASSWORD, sizeof(char), 10, dt);
        fwrite(FOOD, sizeof(char), 54, dt);
        fwrite(finance, sizeof(char), n, dt);
        fprintf(dt,"\n");
        fclose(dt);

        free(finance);
        super_menu();
}

////////////////////////////////////////////////////////////

void login (void){
        char temp[500];
        long long int u,p,l,k;

        dt=fopen("data.dat","r");
        if (dt==NULL){
                printf("\n                    you have not been registered\n\n");
                super_menu();
        }

        for(int i=0;i<20;i++){
                printf(" ");
        }
        printf("Enter your USERNAME :\t");
        scanf("%lli",&u);

        for(int i=0;i<20;i++){
                printf(" ");
        }
        printf("Enter your PASSWORD :\t");
        scanf("%lli",&p);

        rewind(dt);
        while(!(u==l && p==k)) {
                if (feof(dt)){break;}
                I=(ftell(dt)-1);
                fread(USERNAME, sizeof(char), 10, dt);
                fread(PASSWORD, sizeof(char), 10, dt);

                l=arrti(USERNAME);
                k=arrti(PASSWORD);
                if ((u==l) && (p==k)) {
                        open();
                        sepi_panel();
                }else {
                        fgets(temp,500,dt);
                }
        }
        if(u!=l || p!=k){
                for(int i=0;i<20;i++){
                        printf(" ");
                }
                printf("You entered your USERNAME and PASSWORD wrong OR you have not been registered yet :\n");
                fclose(dt);

        int selection;
                printf("\n                    1 ===>> ReLogin");
                printf("\n                    2 ===>> Register");
                printf("\n                    3 ===>> Main menu");
                printf("\n                    0 ===>> Exit");
                printf("\n");
                do{
                        for(int i=0;i<20;i++){
                                printf(" ");
                        }
                        scanf("%d",&selection);
        }while(selection<0 || selection>3);
        if(selection==1){
                        login();
                }
        if(selection==2){
                        reg();
                }
        if(selection==3){
                        super_menu();
                }
                if(selection==0){
                        exit(1);
                }
        }
}

////////////////////////////////////////////////////////////

long long int arrti (char *c){
        long long int j=0;
        for (int i=0;i<10;i++){
                j*=10;
                j+=(c[i]-48);
        }
        return j;
}

////////////////////////////////////////////////////////////

void open (void){
        char tmp[500];
        fread(FOOD, sizeof(char), 54, dt);
        int i=ftell(dt);
        fgets(tmp,500,dt);
        F=(ftell(dt))-2;
        N=(F-i);
        finance=(char *) malloc (N*sizeof(char));
        rewind(dt);
        fseek(dt,i,SEEK_CUR);
        fread(finance,sizeof(char),N,dt);
}

////////////////////////////////////////////////////////////

void save (void){
        char c[1];
        FILE *fo=0; FILE *fn=0;
        fo=fopen("data.dat","r");
        fn=fopen("ndata.dat","w");
        rewind(fo);
        for(int i=0;i<I;i++){
                fread(c,sizeof(char),1,fo);
                fwrite(c,sizeof(char),1,fn);
        }

        fwrite(USERNAME, sizeof(char), 10, fn);
        fwrite(PASSWORD, sizeof(char), 10, fn);
        fwrite(FOOD, sizeof(char), 54, fn);
        fwrite(finance,sizeof(char),N,fn);

        fseek(fo, (F-I), SEEK_CUR);

        while(!feof(fo)){
                fread(c,sizeof(char),1,fo);
                fwrite(c,sizeof(char),1,fn);
        }

        fclose(fo);
        fclose(fn);
        fclose(dt);
        free(finance);
		days * pjome = &jome;
		food_name * pjome_name = &jome_name;
		free(pjome->next->next->next->next->next->next);
		free(pjome->next->next->next->next->next);
		free(pjome->next->next->next->next);
		free(pjome->next->next->next);
		free(pjome->next->next);
		free(pjome->next);
		free(pjome_name->next->next->next->next->next->next);
		free(pjome_name->next->next->next->next->next);
		free(pjome_name->next->next->next->next);
		free(pjome_name->next->next->next);
		free(pjome_name->next->next);
		free(pjome_name->next);
        remove("data.dat");
        rename("ndata.dat", "data.dat");
		exit(0);
}

////////////////////////////////////////////////////////////

void sepi_panel(){
    int flag=1;
    int select;
    while(flag==1){
        select=sepi_panel_menu();
        switch(select){
            case 1:
            reserve_food_panel();
            break;

            case 2:
            show_reserved_food();
                break;

            case 3:
            edit_user();
            break;

            case 4:
            edit_food();
            break;

            case 5:
            Show_Money();
            break;

            case 6:
            Increase_Money();
            break;

            case 7:
            save();
            break;

            case 0:
            super_menu();
            break;


        }
    }
}

////////////////////////////////////////////////////////////

int sepi_panel_menu(){
    int a;
	printf("\n\n\n");
    do{
        printf("                    Enter 1 for reserving food\n");
        printf("                    Enter 2 for viewing your reservd food\n");
        printf("                    Enter 3 for changing user data\n");
        printf("                    Enter 4 for changing reserved food\n");
        printf("                    Enter 5 for viewing your finance\n");
        printf("                    Enter 6 for increasing your finance\n");
                printf("                    Enter 7 for saving your data\n");
        printf("                    Enter 0 for going back to main menu\n                    ");
        scanf("%d",&a);
    }while(a<0 || a>7);
    return a;
}

////////////////////////////////////////////////////////////

void reserve_food_panel(){
    int a,b,c,i;
    int food_selection,reverse_food_selection;
    food_selection=a=week_selection();
    food_selection*=10;
    b=day_selection();
    food_selection+=b;
    food_selection*=10;
    c=food(a,b);
    food_selection+=c;
    reverse_food_selection=reverse(food_selection);
    for(i=0;i<=51;i=i+3){
        if(FOOD[i]==(char)a+48 && FOOD[i+1]==(char)b+48){
            printf("                    you have reserve food at this day and this meal\n");
            sepi_panel();
        }
    }
    Decrease_Money(a,& jome,b,c);
    for(i=3;i<=51;i=i+3){
        if(FOOD[i]==(char)48 && FOOD[i+1]==(char)48 && FOOD[i+2]==(char)48){

            //sprintf(FOOD,"%d",food_selection);
            /*sprintf(&FOOD[i],"%d",a);
            sprintf(&FOOD[i+1],"%d",b);
            sprintf(&FOOD[i+2],"%d",c);*/

            FOOD[i]=(char)a+48;
            FOOD[i+1]=(char)b+48;
            FOOD[i+2]=(char)c+48;
            break;
        }
    }
    sepi_panel();

}

/////////////////////////////////////////////////////////////

int computation_N(long long int money){
    int i=0;
    while(money>0){
        money/=10;
        i++;
    }
    return i;
}

/////////////////////////////////////////////////////////////

long long int change_char_int(void){
    long long int j=0;
    for (int i=0;i<N;i++){
        j*=10;
        j+=( (int) finance[i]-48);
    }
    return j;
}

/////////////////////////////////////////////////////////////

void whfood (int d, int m){
        if(d==1){      //shanbe
                if(m==1){
                        printf("\n                    zereshk polo ba morgh + dogh");
                }else if(m==2){
                        printf("\n                    adas polo keshmeshe adi + salade kalam");
                }else if(m==3){
                        printf("\n                    chelo joje kababe tak");
                }else if(m==4){
                        printf("\n                    chelo kabab hosseini tak");
                }else if(m==5){
                        printf("\n                    kashk va bademjan tak");
                }else if(m==6){
                        printf("\n                    yarane 3200 tak");
                }else if(m==7){
                        printf("\n                    yarane 2000 bofe tabiat");
                }
        }else if(d==2){//1shanbe
                if(m==1){
                        printf("\n                    chelo khoresht sabzi adi + mive");
                }else if(m==2){
                        printf("\n                    lobia polo adi+masto khiar");
                }else if(m==3){
                        printf("\n                    shevid polo mahi ghezel ala tak");
                }else if(m==4){
                        printf("\n                    chelo khoresht gheime tak");
                }else if(m==5){
                        printf("\n                    chelo meigo sokhari tak");
                }else if(m==6){
                        printf("\n                    yarane 3200 tak");
                }else if(m==7){
                        printf("\n                    yarane 2000 bofe tabiat");
                }
        }else if(d==3){//2shanbe
                if(m==1){
                        printf("\n                    chelo joje kabab adi+dogh");
                }else if(m==2){
                        printf("\n                    chelo goshto gharch adi + salad");
                }else if(m==3){
                        printf("\n                    chelo kabab kobide tak");
                }else if(m==4){
                        printf("\n                    estanboli polo tak");
                }else if(m==5){
                        printf("\n                    chelo kabab chobi morgh tak");
                }else if(m==6){
                        printf("\n                    yarane 3200 tak");
                }else if(m==7){
                        printf("\n                    yarane 2000 bofe tabiat");
                }
        }else if(d==4){//3shanbe
                if(m==1){
                        printf("\n                    chelo khoresht gheime adi + mast");
                }else if(m==2){
                        printf("\n                    kashk va bademjan adi + abmive");
                }else if(m==3){
                        printf("\n                    zereshk polo ba morgh tak");
                }else if(m==4){
                        printf("\n                    koko sabzi tak");
                }else if(m==5){
                        printf("\n                    adas polo keshmeshe tak");
                }else if(m==6){
                        printf("\n                    yarane 3200 tak");
                }else if(m==7){
                        printf("\n                    yarane 2000 bofe tabiat");
                }
        }else if(d==5){//4shanbe
                if(m==1){
                        printf("\n                    shevid polo khorak tone mahi adi + khorma");
                }else if(m==2){
                        printf("\n                    chelo khoresht lobia sabzi adi + masto khiar");
                }else if(m==3){
                        printf("\n                    chelo kabab bakhtiari tak");
                }else if(m==4){
                        printf("\n                    khorak belderchin kababi tak");
                }else if(m==5){
                        printf("\n                    kashk va bademjan tak");
                }else if(m==6){
                        printf("\n                    yarane 3200 tak");
                }else if(m==7){
                        printf("\n                    yarane 2000 bofe tabiat");
                }
        }else if(d==6){//5shanbe
                if(m==1){
                        printf("\n                    chelo joje kabab adi+dogh");
                }else if(m==2){
                        printf("\n                    lobia polo adi+masto khiar");
                }else if(m==3){
                        printf("\n                    mirza ghasemi tak");
                }else if(m==4){
                        printf("\n                    estanboli polo tak");
                }else if(m==5){
                        printf("\n                    chelo kabab chobi morgh tak");
                }else if(m==6){
                        printf("\n                    yarane 3200 tak");
                }else if(m==7){
                        printf("\n                    yarane 2000 bofe tabiat");
                }
        }
}

////////////////////////////////////////////////////////////

void edit_user () {
    printf("                    Enter new USERNAME:\t");
    scanf("%s",USERNAME);
    printf("                    Enter new PASSWORD:\t" );
    scanf("%s",PASSWORD);
    printf("                    You must SAVE your data ASAP\n");
    sepi_panel();
}

////////////////////////////////////////////////////////////

void edit_food (){
    int first_food;
    days* ptr=&jome;
    long long int money;
    int price=0;
    int j;
    int increase,decrease;



    int week,day,i,counter,check=0,t1;
    char efood[54];
    for(int temp=0;temp<54;temp++){efood[temp]=FOOD[temp];}
    week=week_selection();
    day=day_selection();
    if(week==1){
        if(day==1){
            do{
                printf("                    Enter 1 for omlet(30000 Rials) \n");
                printf("                    Enter 2 for nano halva(20000 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>2);
        }
        if(day==2){
            do{
                printf("                    Enter 1 for zereshk polo ba morgh + dogh(60000 Rials) \n");
                printf("                    Enter 2 for adas polo keshmeshe adi + salade kalam(50000 Rials) \n");
                printf("                    Enter 3 for chelo joje kababe tak(80000 Rials) \n");
                printf("                    Enter 4 for chelo kabab hosseini tak(90000 Rials) \n");
                printf("                    Enter 5 for kashk va bademjan tak(50000 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>7);
        }
        if(day==3){
            do{
                printf("                    Enter 1 for shevid polo tone mahi adi + abmive(40000 Rials) \n");
                printf("                    Enter 2 for abgosht adi+torshi(50000 Rials) \n");
                printf("                    Enter 3 for asalad kardinal tak(60000 Rials) \n");
                printf("                    Enter 4 for dolme felfel sabz tak(80000 Rials) \n");
                printf("                    Enter 5 for khork salad olovie tak(10 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                scanf("%d",&i);
            }while(i<1 || i>6);
        }
    }
    ///////////////////////////////////////////////////////////////////////////
    if(week==2){
        if(day==1){
            do{
                printf("                    Enter 1 for adasi(30000 Rials) \n");
                printf("                    Enter 2 for nano paniro shir(20000 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>2);
        }
        if(day==2){
            do{
                printf("                    Enter 1 for chelo khoresht sabzi adi + mive(50000 Rials) \n");
                printf("                    Enter 2 for lobia polo adi+masto khiar(30000 Rials) \n");
                printf("                    Enter 3 for shevid polo mahi ghezel ala tak(70000 Rials) \n");
                printf("                    Enter 4 for chelo khoresht gheime tak(80000 Rials) \n");
                printf("                    Enter 5 for chelo meigo sokhari tak(90000 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>7);
        }
        if(day==3){
            do{
                printf("                    Enter 1 for koko sib zamini adi +dogh(30000 Rials) \n");
                printf("                    Enter 2 for chelo khoresht mosama kado adi + mast(40000 Rials) \n");
                printf("                    Enter 3 for mirza ghasemi tak(60000 Rials) \n");
                printf("                    Enter 4 for khorake shenisel morgh tak(70000 Rials) \n");
                printf("                    Enter 5 for nano paniro sib zamini tak(10 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                scanf("%d",&i);
            }while(i<1 || i>6);
        }
    }
    ///////////////////////////////////////////////////////////////////////////
    if(week==3){
        if(day==1){
            do{
                printf("                    Enter 1 for khame asali(20000 Rials) \n");
                printf("                    Enter 2 for nano kare moraba(10000 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>2);
        }
        if(day==2){
            do{
                printf("                    Enter 1 for chelo joje kabab adi+dogh(40000 Rials) \n");
                printf("                    Enter 2 for chelo goshto gharch adi + salad(30000 Rials) \n");
                printf("                    Enter 3 for chelo kabab kobide tak(80000 Rials) \n");
                printf("                    Enter 4 for estanboli polo tak(6000 toman Rials) \n");
                printf("                    Enter 5 for chelo kabab chobi morgh tak(70000 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                scanf("%d",&i);
            }while(i<1 || i>7);
        }
        if(day==3){
            do{
                printf("                    Enter 1 for makaroni ba goosht adi+salad(40000 Rials) \n");
                printf("                    Enter 2 for khorak loobia chity ba tokhm morgh + dorchi(30000 Rials) \n");
                printf("                    Enter 3 for chelo khoresht sabzi tak (70000 Rials) \n");
                printf("                    Enter 4 for khorak hamberger tak(60000 Rials) \n");
                printf("                    Enter 5 for soup jo + tokhm morgh va sib zmini tak(10 Rials) \n");
                printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                scanf("%d",&i);
            }while(i<1 || i>6);
        }
    }
    ///////////////////////////////////////////////////////////////////////////
    if(week==4){
            if(day==1){
                do{
                    printf("                    Enter 1 for adasi(30000 Rials) \n");
                    printf("                    Enter 2 for nano halva(20000 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>2);
            }
            if(day==2){
                do{
                    printf("                    Enter 1 for chelo khoresht gheime adi + mast(30000 Rials) \n");
                    printf("                    Enter 2 for kashk va bademjan adi + abmive kalam(20000 Rials) \n");
                    printf("                    Enter 3 for zereshk polo ba morgh tak(70000 Rials) \n");
                    printf("                    Enter 4 for koko sabzi tak(50000 Rials) \n");
                    printf("                    Enter 5 for adas polo keshmeshe tak(50000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                    printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>7);
            }
            if(day==3){
                do{
                    printf("                    Enter 1 for estanboli polo adi + masto khiar(30000 Rials) \n");
                    printf("                    Enter 2 for halim + mive(20000 Rials) \n");
                    printf("                    Enter 3 for khorak kabab tabe i tak(80000 Rials) \n");
                    printf("                    Enter 4 for khorak morgh o gharch tak(70000 Rials) \n");
                    printf("                    Enter 5 for abgosht sonati tak(80000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>6);
            }
        }

    /////////////////////////////////////////////////////////////////////////////////////////////

    if(week==5){
            if(day==1){
                do{
                    printf("                    Enter 1 for fereni + panir(20000 Rials) \n");
                    printf("                    Enter 2 for nano kare va asal(30000 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>2);
            }
            if(day==2){
                do{
                    printf("                    Enter 1 for shevid polo khorak tone mahi adi + khorma(20000 Rials) \n");
                    printf("                    Enter 2 for chelo khoresht lobia sabzi adi + masto khiar(30000 Rials) \n");
                    printf("                    Enter 3 for chelo kabab bakhtiari tak(80000 Rials) \n");
                    printf("                    Enter 4 for khorak belderchin kababi tak(90000 Rials) \n");
                    printf("                    Enter 5 for kashk va bademjan tak(50000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                    printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>7);
            }
            if(day==3){
                do{
                    printf("                    Enter 1 for chelo morgh beryan adi + soup(30000 Rials) \n");
                    printf("                    Enter 2 for nano paniro sibzamini adi + ash reshte(20000 Rials) \n");
                    printf("                    Enter 3 for makaroni ba goosht tak(60000 Rials) \n");
                    printf("                    Enter 4 for soup jo + tokhm morgh va sib zmini tak(10 Rials) \n");
                    printf("                    Enter 5 for dolme felfel sabz tak(80000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>6);
            }
        }

    //////////////////////////////////////////////////////////////////////////////////////////

    if(week==6){
            if(day==1){
                do{
                    printf("                    Enter 1 for adasi(30000 Rials) \n");
                    printf("                    Enter 2 for nano halva(20000 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>2);
            }
            if(day==2){
                do{
                    printf("                    Enter 1 for chelo joje kabab adi+dogh(40000 Rials) \n");
                    printf("                    Enter 2 for lobia polo adi+masto khiar(30000 Rials) \n");
                    printf("                    Enter 3 for mirza ghasemi tak(60000 Rials) \n");
                    printf("                    Enter 4 for estanboli polo tak(60000 Rials) \n");
                    printf("                    Enter 5 for chelo kabab chobi morgh tak(70000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials) \n");
                    printf("                    Enter 7 for yarane 2000 bofe tabiat(10 Rials) \n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>7);
            }
            if(day==3){
                do{
                    printf("                    Enter 1 for chelo khoresht gheime adi + mast(30000 Rials) \n");
                    printf("                    Enter 2 for khorak loobia chity ba tokhm morgh + dorchin(30000 Rials) \n");
                    printf("                    Enter 3 for salad kardinal tak(60000 Rials) \n");
                    printf("                    Enter 4 for koko sabzi tak(50000 Rials) \n");
                    printf("                    Enter 5 for adas polo keshmeshe tak(50000 Rials) \n");
                    printf("                    Enter 6 for yarane 3200 tak(10 Rials)\n                    ");
                    scanf("%d",&i);
                }while(i<1 || i>6);
            }
        }
/////////////////////////////////////////////////////////////////////////////////////////

    for(counter=0;counter<=51;counter+=3){
        if(efood[counter]==week+48){
            if(efood[counter+1]==day+48){
                if(efood[counter+2]!=48){
                    first_food=efood[counter+2];
                    efood[counter+2]=(i+48);
                    check=1;
                }
            }
        }
    }
    if(check==0){printf("                    Your numbers are wrong or you did not reserve\n"); sepi_panel();}
    else {
        for(j=0;j<week;j++){
            ptr=ptr->next;
        }
        if(day==1){
                price=ptr->breakfast[first_food-48];
        }
        if(day==2){
                price=ptr->lunch[first_food-48];
        }
        if(day==3){
                price=ptr->dinner[first_food-48];
        }
        increase=price;
        ptr=&jome;
        for(j=0;j<week;j++){
            ptr=ptr->next;
        }
        if(day==1){
                price=ptr->breakfast[i];
        }
        if(day==2){
                price=ptr->lunch[i];
        }
        if(day==3){
                price=ptr->dinner[i];
        }
        decrease=price;
        money=change_char_int();
        money+=(increase-decrease);
        N=computation_N(money);
        sprintf(finance,"%lli",money);
        for(t1=0 ; t1<54 ; t1++ ){
            FOOD[t1]=efood[t1];
        }
        printf("                    You must SAVE your data ASAP\n");
        sepi_panel ();
    }
}

////////////////////////////////////////////////////////////

void show_reserved_food(void){
        printf("\n");
        int i,a,b,c;
        for(i=0;FOOD[i]!=(char)48  && i<=51 ;i=i+3){
                a=(char) FOOD[i] - 48;
                b=(char) FOOD[i+1] - 48;
                c=(char) FOOD[i+2] - 48;
                search_show_reserved_food(a,b,c);
        }
        sepi_panel();
}

////////////////////////////////////////////////////////////

void search_show_reserved_food(int a,int b,int c){
        food_name* ptr=&jome_name;
        int i;
        char* name;

        for(i=0;i<a;i++){
        ptr=ptr->next;
        }

        if(b==1){
            name=ptr->name_breakfast[c];
        }
        if(b==2){
            name=ptr->name_lunch[c];
        }
        if(b==3){
            name=ptr->name_dinner[c];
        }

        printf("                    on ");
        if(a==1) printf("shanbe\t\t");
        if(a==2) printf("yek_shanbe\t");
        if(a==3) printf("do_shanbe\t");
        if(a==4) printf("se_shanbe\t");
        if(a==5) printf("char_shanbe\t");
        if(a==6) printf("panj_shanbe\t");
        printf("for ");
        if(b==1) printf("breakfast\t");
        if(b==2) printf("lunch\t");
        if(b==3) printf("dinner\t");
        printf("you reseved ");
        printf("%s\n",name);


}

////////////////////////////////////////////////////////////

void tat (){
	printf("\n                    We have some tips here for you :\n");
	printf("\n                    1. Your USERNAME and PASSWORD must be [10] digits\n");
	printf("\n                        and DO NOT started with [0]\n");
	printf("\n                        We recommend use your university's ID number\n");
	printf("\n                        as USERNAME and your national's ID as PASSWORD\n");
	printf("\n                        [ if it DOES NOT started with [0] ]\n\n\n");
	printf("\n                    2. After changing frequently use save\n");
	printf("\n                    3. Be patient ! we are starter !!!");
	super_menu();
}








