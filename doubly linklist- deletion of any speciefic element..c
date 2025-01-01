#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *forw;
    struct node *back;
};
struct node *start, *newptr, *save, *ptr;
void create(int);
void deleteatpos(int);
void displayForward(struct node *);
int main()
{
    int ele, ans, n;
    start = NULL;
    while (1)
    {
        printf("\nEnter element: ");
        scanf("%d", &ele);
        create(ele);
        printf("Want to continue (Y/N)? ");
        scanf(" %c", &ans);
        if (ans == 'Y' || ans == 'y')
            continue;
        else
        {
        	printf("\nEnter the element you want to delete: ");
            scanf("%d", &ele);
            deleteatpos(ele);
            break;
		}
    }
    printf("\nDisplay elements forward:\n");
    displayForward(start);
    return 0;
}
void create(int ele)
{
    newptr = (struct node *)malloc(sizeof(struct node));
    if (newptr == NULL)
    {
        printf("\nOut of memory.\n");
        exit(0);
    }
    newptr->info = ele;
    newptr->forw = NULL;
    newptr->back = NULL;
    if (start == NULL)
    {
        start = newptr;
    }
    else
    {
        save = start;
        while (save->forw != NULL)
        {
            save = save->forw;
        }
        save->forw = newptr;
        newptr->back = save;
    }
}
void deleteatpos(int ele)
{
    if (start == NULL)
    printf("Linked list is empty");
    else 
	if (start->info == ele)
    {
        save = start;
        start = start->forw;
        if (start != NULL)
        start->back = NULL;
        free(save);
    }
    else
    {
        save = start;
        while (save != NULL && save->info != ele)
        {
            ptr = save;
            save = save->forw;
        }
    }
    if (save == NULL)
        printf("Element not found");
    else
    {
        ptr->forw = save->forw;
    if (save->forw != NULL)
        save->forw->back = ptr;
        free(save);
    }
}
void displayForward(struct node *start)   
{
    save = start;
    if (save == NULL)
    {
        printf("Doubly linked list is empty\n");
        return;
    }
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->forw;
    }
}

