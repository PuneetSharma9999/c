#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *head, *newptr, *save;
void create(int);
void display(struct node *);
int main()
{
    int ele, ans;
    head = NULL;
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
    display(head);
    return 0;
}
void create(int ele)
{
    newptr = (struct node *)malloc(sizeof(struct node));
    if (newptr == NULL)
    {
        printf("\nOut of memory\n");
        return;
    }
    newptr->info = ele;
    newptr->link = NULL;
    if (head == NULL)
    {
        head = newptr;
        newptr->link = head;
    }
    else
    {
        save = head;
        while (save->link != head)
        {
            save = save->link;
        }
        save->link = newptr;
        newptr->link = head; 
    }
}
void display(struct node *head)
{
    save = head;
    if (save == NULL)
    {
        printf("Circular linked list is empty\n");
        return;
    }
    do
    {
        printf("%d ", save->info);
        save = save->link;
    } while (save != head);
}

