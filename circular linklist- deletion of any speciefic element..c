#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *head, *newptr, *save, *ptr;
void create(int);
void deleteatpos(int);
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
        {
            printf("\nEnter the element you want to delete: ");
            scanf("%d", &ele);
            deleteatpos(ele);
            break;
        }
    }
    printf("\nDisplay elements:\n");
    display(head);
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
void deleteatpos(int ele)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    else
    {
        save = head;
        ptr = NULL;
        while (save->link != head && save->info != ele)
        {
            ptr = save;
            save = save->link;
        }
        if (save->info != ele)
        {
            printf("Element not found\n");
            return;
        }
        if (save == head)
        {
            ptr = head;
            while (ptr->link != head)
            {
                ptr = ptr->link;
            }
            if (head == head->link)
            {
                free(head);
                head = NULL;
            }
            else
            {
                ptr->link = head->link;
                head = head->link;
                free(save);
            }
        }
        else
        {
            ptr->link = save->link;
            free(save);
        }
    }
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Circular linked list is empty\n");
        return;
    }
    save = head;
    do
    {
        printf("%d ", save->info);
        save = save->link;
    } while (save != head);
}

