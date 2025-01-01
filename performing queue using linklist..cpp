#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node* link;
};
struct node *front,*rear,*newptr,*save;
int main()
{
int opt,ele;
void insertion(int);             //fn prototype for insertion
int deletion();                  //fn prototype for deletion 
void traversing(struct node*);   //fn prototype for displaying ele..
front=NULL;
rear=NULL;
printf("\nEnter main menu\n");
printf("\nPress 1 for insertion: ");
printf("\nPress 2 for deletion: ");
printf("\nPress 3 for display: ");
printf("\nPress 4 for exit: ");
while(1)
{
printf("\n\nChoose any option: ");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Enter element: ");
scanf("%d",&ele);
insertion(ele);                   //fn calling for insertion
break;
case 2:ele=deletion();                //fn calling for deletion
printf("\nThe deleted element is %d",ele);
break;
case 3:traversing(front);                //fn calling for displaying ele..
break;
case 4:exit(0);
break;
default:printf("\nPlease choose a valid option(1/2/3/4/)");
break;
}
}
}
void insertion(int ele)                 //fn definition for insertion
{
newptr=(struct node*)malloc(sizeof(struct node));
newptr->info=ele;
newptr->link=NULL;
if(front==NULL)
{
    front=newptr;
    rear=newptr;
}
    else
    {
    rear->link=newptr;
    rear=newptr;
    }
}
int deletion()            //fn definition for deletion
{
int ele;
if(front==NULL)
{
printf("\nQueue is underflow ");
return(0);
}
else
{
ele=front->info;
save=front;
front=front->link;
free(save);
return(ele);
}
}
void traversing(struct node*front)            //fn definition for displaying ele..
{
save=front;
while(save!=NULL)
{
printf("%d\t",save->info);
save=save->link;
}
}
