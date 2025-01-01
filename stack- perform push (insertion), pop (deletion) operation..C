#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 50
int top;
int main()
{
int stack[SIZE],ele,opt;
void push (int[],int);
int pop (int[]);
void display (int[]);
top=-1;
printf("main menu");
printf("\n press 1 for push");
printf("\n press 2 for deletion");
printf("\n press 3 for display");
printf("\n press 4 for exit");
while(1)
{
printf("\n choose any option");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("\n Enter element: ");
scanf("%d",&ele);
push(stack,ele);
break;
case 2:ele=pop(stack);
break;
case 3:display(stack);
break;
case 4:exit(0);
break;
default:printf("\n Wrong choice ");
break;
}
}
}
void push (int stack[],int ele)
{
if(top==SIZE-1)
printf("\n stack is overflow ");
else
{
top++;
stack[top]=ele;
}
}
int pop (int stack[])
{
int ele;
if(top==-1)
{
printf("\n stack is underflow ");
return 0;
}
else
{
ele=stack[top];
printf("\n poped element is %d",ele);
top--;
return ele;
}

}
void display (int stack[])
{
int i;
for(i=top;i>=0;i--)
{
printf("\n%d",stack[i]);
}
}

