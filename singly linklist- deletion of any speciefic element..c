#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start, *newptr, *save, *ptr;
void create(int);
void deleteatpos(int);
void display(struct node *);
int main()
{
    int ele, ans;
    start = NULL;
    while (1)
    {
        printf("\nEnter element: ");
        scanf("%d", &ele);
        create(ele);
        printf("Want to continue (Y/N)? ");
        scanf(" %c", &ans);
        if (ans != 'Y' && ans != 'y')
            break;
    }
    printf("\nEnter the element you want to delete: ");
    scanf("%d", &ele);
    deleteatpos(ele);
    printf("\nDisplay elements:\n");
    display(start);
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
    newptr->link = NULL;
    if (start == NULL)
    {
        start = newptr;
    }
    else
    {
    save = start;
    while (save->link != NULL)
    {
    save = save->link;
    }
    save->link = newptr;
    }
}
void deleteatpos(int ele)
{
    if (start == NULL)
    {
    printf("Linked list is empty\n");
    return;
    }
    else
    if (start->info == ele)
    {
    save = start;
    start = start->link;
    free(save);
    return;
    }
    else
    {
    save = start;
    ptr = NULL;
    while (save != NULL && save->info != ele)
    {
    ptr = save;
    save = save->link;
    }
    }
    if (save == NULL)
    {
    printf("Element not found\n");
    return;
    }
    else
    {
    ptr->link = save->link;
    free(save);
    }
}
void display(struct node *start)
{
    save = start;
    if (save == NULL)
    {
    printf("Linked list is empty\n");
    return;
    }
    while (save != NULL)
    {
    printf("%d ", save->info);
    save = save->link;
    }
}

