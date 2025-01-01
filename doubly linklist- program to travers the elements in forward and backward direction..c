#include<stdlib.h>
#include<stdio.h>
struct node
{
    int info;
    struct node* forw,* back;
};
struct node *start, *newptr, *save;
void create(int);
void displayForward(struct node*);
void displayBackward(struct node*);
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
        if (ans == 'Y' || ans == 'y')
            continue;
        else
            break;
    }
    printf("\nDisplay elements forward:\n");
    displayForward(start);
    printf("\n\nDisplay elements backward:\n");
    displayBackward(start);
    return 0;
}
void create(int ele)
{
    newptr = (struct node*)malloc(sizeof(struct node));
    if (newptr == NULL)
    {
        printf("\nOut of memory\n");
        return;
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
void displayBackward(struct node *start)
{
    save = start;
    if (save == NULL)
    {
        printf("Doubly linked list is empty\n");
        return;
    }
    while (save->forw != NULL)
    {
        save = save->forw;
    }
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->back;
    }
}

