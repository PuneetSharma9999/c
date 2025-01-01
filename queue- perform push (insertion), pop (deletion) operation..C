#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 50
int front,rear;
int main()
{
int queue[SIZE],opt,ele;
void insertion(int[],int);
int deletion(int[]);
void traversing(int[]);
front=-1,rear=-1;
printf("\nEnter main menu\n");
printf("\n1.INSERTION\n2.DELETION\n3.TRVAVERSING\n4.EXIT");
while(1)
{
printf("\n\nChoose any option: ");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Enter element: ");
scanf("%d",&ele);
insertion(queue,ele);
break;
case 2:ele=deletion(queue);
break;
case 3:traversing(queue);
break;
case 4:exit(0);
break;
default:printf("\nPlease choose a valid option(1/2/3/4/)");
break;
}
}
}
void insertion(int queue[],int ele)
{
if(rear==SIZE-1)
printf("\nQueue is overflow");
else
if(rear==-1)
{
rear=0,front=0;
queue[rear]=ele;
}
else
{
rear++;
queue[rear]=ele;
}
}
int deletion(int queue[])
{
int ele;
if(front==-1)
{
printf("Queue is underflow");
return(0);
}
else
if(front==rear)
{
ele=queue[front];
front=-1,rear=-1;
printf("The deleted element is %d",ele);
return(ele);
}
else
{
ele=queue[front];
front++;
printf("The deleted element is %d",ele);
return(ele);
}
}
void traversing(int queue[])
{
int i;
printf("The elements in Queue:\n");
for(i=front;i<=rear;i++)
{
printf("%d\t",queue[i]);
}
}
