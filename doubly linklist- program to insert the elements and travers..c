#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node*link;
}
*start,*newptr,*save;
int main()
{
	int ele,ans;
	void create (int);
	void display (struct node*);
	start=NULL;
	while(1)
	{
		printf("\nEnter element: ");
		scanf("%d",&ele);
		create(ele);
		printf("\n want to continue (Y/N) ");
		scanf("%c",&ans);
		if(ans=='Y'||ans=='y')
		continue;
		else
		break;
		printf("\nDisplay element ");
		display(start);
	}
	void create (int ele)
	{
		newptr=(struct node*)malloc(sizeof(struct node));
		if(newptr==NULL)
		{
			printf("\nOut of memory ");
		}
		newptr->info=ele;
		newptr->link=NULL;
		if(start==NULL)
		start=newptr;
		else
		save=start;
		while(save->link!=NULL)
		{
			save=save->link;
		}
		save->link=newptr;
	}
}
void display (struct node*)
{
	if(start==NULL)
	printf("\nLinked list is empty ");
	else
	save=start;
	while(save->link!=NULL)
	{
		printf("\n%d",save->info);
    }
    save=save->link;
}
