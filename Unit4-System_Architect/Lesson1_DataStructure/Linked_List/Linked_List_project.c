#include <stdio.h>
#include <stdlib.h>


struct SStudent{
char name[40];
int Id;
struct SStudent* Next;

};

struct SStudent* first=NULL;



void AddStudent(){
struct SStudent* PNew;
struct SStudent* PCheck;
if(first==NULL){
   PNew =(struct SStudent*)malloc (sizeof(struct SStudent));
   first=PNew;
}
else{
        PCheck=first;

while(PCheck->Next)
   PCheck = PCheck->Next;

 PNew =(struct SStudent*)malloc(sizeof(struct SStudent));
 PCheck->Next=PNew;

}
printf("Enter name :");
scanf("%s",&PNew->name);
printf("Enter ID :");
scanf("%d",&PNew->Id);
PNew->Next=NULL;


}

void ViewStudent(){
struct SStudent* current =first;
if(first==NULL){
    printf("Empty \n ");
}
while(current){
     printf("name is :%s \n",current->name);
     printf("\n ID is : %d \n",current->Id);
     printf("---------------------------- \n");
     current=current->Next;
}
}

void DeleteAll(){
struct SStudent* current =first;
if(first==NULL){
    printf("---Empty--- \n ");
}
while(current){
   struct SStudent* temp = current ;
     current=current->Next;
     free(temp);
}
first=NULL;
}

void DeleteStudent(){
    int user_id =0;
    printf("Enter student id \n");
    scanf("%d",&user_id);
    if(first){
       struct SStudent* previous =NULL;
       struct SStudent* selected =first;
       while(selected){
        if(selected -> Id == user_id){
                if(previous){
                    previous->Next=selected->Next;
                }
                else {
                    first=selected->Next;
                }
           free (selected) ;
        }
        previous=selected;
        selected=selected->Next;

       }

    }


}
void GetNth(){
    int x;
    struct SStudent* current =first;
    printf("enter num of node \n");
    scanf ("%d",&x);
int count=0;
if(x !=0){
while(count<x){
    count++;
    current=current->Next;
}}
 printf("name of this node is :%s \n",current->name);
     printf("\n ID is : %d \n",current->Id);
}

int Get_Length(){
struct SStudent* current =first;
int count=0;
while(current!=NULL){
        count++;
    current=current->Next;
}
return count;
}

void Get_Nth_End(){
    int x;
    struct SStudent* current =first;
int node_number;
int b=Get_Length();
printf("Enter the desired node \n");
scanf("%d",&node_number);
x =b-node_number;
int count =0;
if(x !=0){
while(count<x){
    count++;
    current=current->Next;
}}
 printf("name of this node is :%s \n",current->name);
     printf("\n ID is : %d \n",current->Id);

}

void  Get_Middle(){
int count=0;
    struct SStudent* current =first;
    int b=Get_Length();

    while(count !=b/2){
        current=current->Next;
        count++;
    }
     printf("name of this node is :%s \n",current->name);
     printf("\n ID is : %d \n",current->Id);


}
int main()
{
    int x=0;
    while (1){
        printf("Enter 1 for Adding\n");

        printf("Enter 2 for delete \n");

        printf("Enter 3 for view all \n");

        printf("Enter 4 for Delete all \n");

        printf("Enter 5 for getting special node from beginning \n");
        printf("Enter 6 to find length of a linked list \n");
         printf("Enter 7 for getting special node from the end \n");
        printf("Enter 8 for the middle\n");
        scanf("%d",&x);
        switch(x){
          case 1:
        AddStudent();
        break;
          case 2:
        DeleteStudent();
        break;
          case 3:
        ViewStudent();
        break;
          case 4:
        DeleteAll();
        break;
        case 5:
       GetNth();
        break;
        case 6:
        printf("the length is %d \n",Get_Length());
        break;
        case 7:
       Get_Nth_End();
        break;
        case 8:
       Get_Middle();
        break;
        }
    }

    return 0;
}
