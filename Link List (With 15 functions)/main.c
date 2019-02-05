//MADE BY SEPANTAPOOYA
//COPING OR USING JUST BY MENTIONING MY NAME

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node* next;
}node;
////////////////////////////////////////////////////////////
void menu (void);
int structer (node* head);
void print(node* head);
void print_in_a_file (node* head);
int selector_menu (void);
void add_first(node*);
void add_end(node*);
void add_to_n_place(node*);
void delete_n_place(node*);
void delete_first(node*);
void delete_end(node*);
void search(node*);
void find_biggest(node*);
void find_smallest(node*);
void swap(node*,int);
void sort(node*);
void average(node*);
void change_one_element(node*,int);

int catcher (void);
////////////////////////////////////////////////////////////

int main()
{
    menu();
    return 0;
}
////////////////////////////////////////////////////////////
void menu (void){
    int flag=1,selector;
    int size;
    node head;
    size=structer(&head);
     while (flag==1) {
        selector=selector_menu();
        /////////////////////////
        switch (selector) {
        case(1):
            add_first(&head);
        break;
        /////////////////
        case(2):
            add_end(&head);
        break;
        /////////////////
        case(3):
            add_to_n_place(&head);
        break;
        /////////////////
        case(4):
            delete_first(&head);
        break;
        /////////////////
        case(5):
            delete_end(&head);
        break;
        /////////////////
        case(6):
            delete_n_place(&head);
        break;
        /////////////////
        case(7):
            search(&head);
        break;
        /////////////////
        case(8):
            find_biggest(&head);
        break;
        /////////////////
        case(9):
            find_smallest(&head);
        break;
        /////////////////
        case(10):
            swap(&head,size);
        break;
        /////////////////
        case(11):
            sort(&head);
        break;
        /////////////////
        case(12):
            average(&head);
        break;
        /////////////////
        case(100):
            print(&head);
        break;
        /////////////////
        case(101):
            print_in_a_file(&head);
        break;
        /////////////////
        case(0):
            printf("hope you enjoy :-) \n");
            flag=0;
        break;
        /////////////////
        case(-1):
            structer(&head);
        break;
        /////////////////
        case(-2):
            change_one_element(&head,size);
        break;
        }
    }
}
////////////////////////////////////////////////////////////
int structer (node* head ){
    node* temp=head;
    int n;
    do{
        printf("enter your size of numbers\n");
        scanf("%d",&n);

    }while(n<=0);
    for(int i=0;i<n;i++,temp=temp->next){
        temp->next=(node*)malloc(sizeof(node));
        printf("enter %d th section number\n",i);
        scanf("%d",&temp->next->data);
    }
    temp->next=(node*)malloc(sizeof(node));
    temp->next=0;
    return n;
}
////////////////////////////////////////////////////////////
void print(node* head){
    node* temp=head->next;
    for(int i=0;temp;i++,temp=temp->next){
        printf("your %d th section is %d \n",i,temp->data);
    }
    printf("___________________________________________________________\n");
}
////////////////////////////////////////////////////////////
int selector_menu(){
    int i;
    printf("enter 1 for adding a number at first of list\n");
    printf("enter 2 for adding a number at end of list\n");
    printf("enter 3 for adding a number in a place that you want \n");
    printf("enter 4 for deleting first number \n");
    printf("enter 5 for deleting last number \n");
    printf("enter 6 for deleting a number in a place that you want \n");
    printf("enter 7 for searching\n");
    printf("enter 8 for finding the biggest number  \n");
    printf("enter 9 for finding the smallest number  \n");
    printf("enter 10 for swap \n");
    printf("enter 11 for sorting \n");
    printf("enter 12 for finding your sum and average \n");
    printf("enter 100 for printing \n");
    printf("enter 101 for printing your data in a file \n");
    printf("enter 0 for exiting\n");
    printf("enter -1 for re-entering your list\n");
    printf("enter -2 for changing one element from your list\n");
    printf("___________________________________________________________\n");
    scanf("%d",&i);
    return i;
}
////////////////////////////////////////////////////////////
void add_first(node* head){
    node* temp=head->next;
    head->next=(node*)malloc(sizeof(node));
    head->next->next=temp;
    head->next->data=catcher();
    printf("___________________________________________________________\n");

}
////////////////////////////////////////////////////////////
int catcher(void){
    int new_data;
    printf("input the data you want to add \n");
    scanf("%d",&new_data);
    return new_data ;
}
////////////////////////////////////////////////////////////
void add_end (node* head){
    node* temp=head->next;
    while (temp->next) {
        temp=temp->next;
    }
    temp->next=(node *)malloc(sizeof(node));
    temp->next->data=catcher();
    temp->next->next=0;
    printf("___________________________________________________________\n");
}
////////////////////////////////////////////////////////////
void add_to_n_place(node* head){
    node* temp=head;
    node* temp2;
    int n,follower;
    printf("enter the place that you want to add a number\n");
    scanf("%d",&n);
    for(follower=0;follower<n-1;follower++){
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=(node*)malloc(sizeof(node));
    temp->next->data=catcher();
    temp->next->next=temp2;
    printf("___________________________________________________________\n");

}
////////////////////////////////////////////////////////////
void delete_n_place(node* head){
  node*temp=head;
  node*temp2;
  int n,follower;
  printf("enter the place that you want to delete  number\n");
  scanf("%d",&n);
  for(follower=0;follower<n-1;follower++){
      temp=temp->next;
  }
  temp2=temp->next->next;
  free(temp->next);
  temp->next=temp2;
  printf("___________________________________________________________\n");

}
////////////////////////////////////////////////////////////
void search(node* head){
    node* temp=head->next;
    int n,result=0;
    printf("input the number that you want to search\n");
    scanf("%d",&n);
    for(int i=0;temp->next;i++,temp=temp->next){
        if(temp->data==n){
            printf("your number is in %d th section\n",i);
            printf("___________________________________________________________\n");
            result=1;
        }
    }
    if(result==0){
        printf("your number doesnt find\n");
        printf("___________________________________________________________\n");
    }



}
////////////////////////////////////////////////////////////
void find_biggest(node* head){
    int biggest;
    node* temp=head->next;
    biggest=temp->data;
    while (temp->next) {
        if(temp->next->data>=biggest){
            biggest=temp->next->data;
        }
        temp=temp->next;
    }
    printf("your biggest number is %d\n",biggest);
    printf("___________________________________________________________\n");
}
////////////////////////////////////////////////////////////
void find_smallest(node* head){
    int smallest;
    node* temp=head->next;
    smallest=temp->data;
    while (temp->next) {
        if(temp->next->data<=smallest){
            smallest=temp->next->data;
        }
        temp=temp->next;
    }
    printf("your smallest number is %d\n",smallest);
    printf("___________________________________________________________\n");
}
////////////////////////////////////////////////////////////
void swap(node* head,int size){
    node*temp_search1=head;
    node*temp_search2=head;
    int  new1 , new2;
    int follower;
    int a,b;
    printf("you want to choose 2 places to swap\n");
    do{
    printf("enter first  number of the place that you want to swap\n");
    scanf("%d",&a);
    }while(a<0||a>size);


    do{
    printf("enter second  number of the place that you want to swap\n");
    scanf("%d",&b);
    }while(b<0||b>size||b==a);
///////////////////////////////////////
    for(follower=0;follower<a;follower++){
        temp_search1=temp_search1->next;
    }
    new1=temp_search1->next->data;
    //temp3=temp1->next;

    for(follower=0;follower<b;follower++){
        temp_search2=temp_search2->next;
    }
    new2=temp_search2->next->data;
    //temp4=temp2->next;
    temp_search1->next->data=new2;
    temp_search2->next->data=new1;
    //I WANTED TO TRY SWAPING THE DATA WITH IT'S ADDRESS,BUT I CAN'T (I'LL THINK LATER ;-) ) THESE LINES ARE MY PREVIOUS TRYINGS,
    /*temp2->next=temp3;
    temp_search2->next=temp1;
    temp1->next=temp4;
    temp_search1->next=temp2;

    for(;temp5;temp5=temp5->next){}
    temp5->next=(node*)malloc(sizeof(node));
    temp5->next=0;*/
}
////////////////////////////////////////////////////////////
void delete_first(node* head){
    node*temp=head->next->next;
    free (head->next);
    head->next=temp;
}
////////////////////////////////////////////////////////////
void delete_end(node* head){
    node* temp=head->next;
    while (temp->next->next) {
        temp=temp->next;
    }
    node*head2;
    head2=temp->next->next;
    free(temp->next);
    temp->next=head2;
}
////////////////////////////////////////////////////////////
void sort(node* head){
    node*i,*j;
    int temp;
    for(i=head->next;i->next;i=i->next){
        for(j=i->next;j;j=j->next){
            if(i->data >= j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }

    }
}
////////////////////////////////////////////////////////////
void average(node* head){
    node* temp=head->next;
    int sum=0,i=0;
    for(;temp;temp=temp->next){
        sum=sum+temp->data;
        i++;
    }
    double result;
    result=sum/i;
    printf("your sum is %d \n",sum);
    printf("your average is %lf \n",result);
    printf("___________________________________________________________\n");
}
////////////////////////////////////////////////////////////
void change_one_element(node* head,int size){
    node* temp=head->next;
    int n,i,new;
    do{
    printf("enter the number of element that you want to change (0<=n<%d) \n",size);
    scanf("%d",&n);
    }while(n<0 || n>size-1);
    printf("enter your new number\n");
    scanf("%d",&new);
    for(i=0;i<n;i++){
        temp=temp->next;
    }
    temp->data=new;
}
////////////////////////////////////////////////////////////
void print_in_a_file (node* head){
    node*temp=head->next;
    int i=0;

    FILE *fptr=NULL;
    fptr=fopen("printing.txt","w");
    if(fptr == NULL)
       {
           printf("Unable to create file.\n");
           return;
       }
    while (temp) {
        fprintf(fptr," your %d th section is  %d \n",i,temp->data);
        temp=temp->next;
        i++;
    }
    fclose(fptr);
    printf("your file created succesfully \n");
    printf("___________________________________________________________\n");

}
////////////////////////////////////////////////////////////

