#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_list(struct node *);
struct node *display(struct node *);
struct node *add_beg(struct node *);
struct node *add_end(struct node *);
struct node *add_before(struct node *);
struct node *add_after(struct node *);
struct node *del_beg(struct node *);
struct node *del_end(struct node *);
struct node *del_before(struct node *);
struct node *del_after(struct node *);
struct node *del_all(struct node *);
int main()
{
    int option;
    do
    {
        printf("\n*****MAIN MENU*****");
        printf("\n  1.Create a list");
        printf("\n  2.Display list");
        printf("\n  3.Add to the beginning of list");
        printf("\n  4.Add to the end of list");
        printf("\n  5.Add before a given node");
        printf("\n  6.Add after a given node");
        printf("\n  7.Delete node at the beginning");
        printf("\n  8.Delete node at the end");
        printf("\n  9.Delete element before a node");
        printf("\n 10.Delete element after a node");
        printf("\n 11.Delete the entire list");
        printf("\nEnter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                start = create_list(start);
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = add_beg(start);
                break;
            case 4:
                start = add_end(start);
                break;
            case 5:
                start = add_before(start);
                break;
            case 6:
                start = add_after(start);
                break;
            case 7:
                start = del_beg(start);
                break;
            case 8:
                start = del_end(start);
                break;
            case 9:
                start = del_before(start);
                break;
            case 10:
                start = del_after(start);
                break;
            case 11:
                start = del_all(start);
                break;

        }

    }while(option!=12);

    return 0;
}

struct node *create_list(struct node *start)
{
    printf("\nEnter the data:");
    int num;
    scanf("%d",&num);
    while(num!=-1)
    {
        if(start ==NULL)
        {
            struct node *new_node = (struct node *) malloc(sizeof(struct node *));
            new_node->data = num;
            new_node->prev = NULL;
            new_node->next = NULL;
            start = new_node;

        }
        else
        {
            struct node *new_node = (struct node *) malloc(sizeof(struct node *));
            new_node->data = num;

                struct node *ptr = start;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next = new_node;
                new_node->prev = ptr;
                new_node->next = NULL;

        }
        printf("\nNode added");
        printf("\nEnter the data:");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr = start;
    if(ptr==NULL)
    {
        printf("\nThe List is empty!!!");
        return start;
    }
    while(ptr!=NULL)
    {
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}

struct node *add_beg(struct node *start)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    printf("\nEnter the element to be added:");
    int num;
    scanf("%d",&num);
    new_node->data = num;
    start->prev = new_node;
    new_node->prev = NULL;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *add_end(struct node *start)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    printf("\nEnter the element to be added:");
    int num;
    scanf("%d",&num);
    new_node->data = num;
    struct node *ptr = start;
    while(ptr->next !=NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = NULL;
    new_node->prev = ptr;
    return start;
}

struct node *add_before(struct node *start)
{
    int bef;
    printf("\nEnter the node before which you want to enter an element:");
    scanf("%d",&bef);
    struct node *ptr, *preptr;
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    printf("\nEnter the element you want to enter:");
    int num;
    scanf("%d",&num);
    new_node->data = num;
    ptr = start;
    int found =0;
    while(ptr->next!=NULL)
    {
        if(ptr->data==bef)
        {
            found =1;
            break;
        }
        ptr = ptr->next;
    }
    if(found)
    {
        preptr = ptr->prev;
        preptr->next = new_node;
        new_node->next = ptr;
        ptr->prev =  new_node;
        new_node->prev = preptr;
    }
    else
    {
        printf("\nThe given node wasnt found!!!");
    }

    return start;

}

struct node *add_after(struct node *start)
{

    printf("\nEnter the node after which you want to add an element:");
    int after;
    scanf("%d",&after);
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    struct node *ptr, *postptr;
    ptr = start;
    int found =0;
    while(ptr->next!=NULL)
    {
        if(ptr->data == after)
        {
            found =1;
            break;
        }
        ptr = ptr->next;
    }

    if(found)
    {
        postptr = ptr->next;
        int num;
        printf("\nEnter the element to be added:");
        scanf("%d",&num);
        new_node->data = num;
        ptr->next = new_node;
        new_node->next = postptr;
        postptr->prev = new_node;
        new_node->prev = ptr;

    }
    else
    {
        printf("\nThe node wasn't found!!!");
    }
    return start;
}

struct node *del_beg(struct node *start)
{
    if(start==NULL)
    {
        printf("\nThe list is empty");
    }
    else if(start->next == NULL)
    {
        struct node *ptr = start;
        start = NULL;
        free(ptr);
        printf("\n Only 1 element was left and has been deleted. The list is empty now");
    }
    else
    {
        struct node *ptr = start;
        start = start->next;
        free(ptr);
        start->prev = NULL;
        printf("\nNode deleted successfully!!!");
    }
    return start;
}

struct node *del_end(struct node *start)
{
    struct node *ptr = start;
    if(ptr==NULL)
    {
        printf("\nThe List is empty!!!");
        return start;
    }
    else if(ptr->next == NULL)
    {
        free(ptr);
        start = NULL;
        printf("\nOnly one element was left and has been deleted!!! The list is empty now");
        return start;
    }
    else
    {

        while(ptr->next!=NULL)
            ptr = ptr->next;
        struct node *preptr = ptr->prev;
        free(ptr);
        preptr->next = NULL;
        printf("\nLast node deleted successfully!!!");
        return start;
    }
    return start;
}

struct node *del_before(struct node *start)
{
    struct node *ptr,*preptr,*postptr = start;
    printf("\nEnter the node whose previous element you want to delete:");
    int bef;
    scanf("%d",&bef);
    if(start->data==bef)
    {
        printf("\nYou have selected the first node");
        return start;
    }
    if((start->next)->next ==NULL)
    {
        struct node *ptr = start;
        start = start->next;
        start->prev= NULL;
        start->next =NULL;
        free(ptr);
        return start;
    }
    int found =0;
    while(postptr->next!=NULL)
    {
        if(postptr->data==bef)
        {
            found =1;
            break;
        }
        postptr = postptr->next;
    }
    ptr = postptr ->prev;
    preptr = ptr->prev;

    preptr->next = postptr;
    postptr->prev =preptr;
    free(ptr);
    return start;
}

struct node *del_after (struct node *start)
{
    struct node *ptr, *temp;
    int after;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &after);
    ptr = start;
    if((start->next)== NULL)
    {
        printf("\nOnly one element left!!!");
        return start;
    }
    else if((start->next)->next == NULL)
    {
        if(start->data==after)
        {
            struct node *ptr2 = start->next;
            ptr2->prev = NULL;
            ptr2->next = NULL;
            free(ptr);
            start = ptr2;
            printf("\nNode Deleted Successfully!!");
            return start;
        }
        else if((start->next)->data == after)
        {
            printf("\nYou have selected the last node!!!");
            return start;

        }
        else
        {
            printf("\nNode not found!!!");
            return start;
        }
    }
    else
    {
        int found =0;
        while(ptr->next!=NULL)
        {
            if(ptr->data == after)
            {
                found =1;
                break;
            }
            ptr = ptr->next;
        }
        if(ptr->next==NULL)
        {
            printf("\nLast node selected!!!");
            return start;
        }
        else if((ptr->next)->next == NULL)
        {
            struct node *ptr2 = ptr->next;
            ptr->next = NULL;
            ptr2->prev = NULL;
            free(ptr2);
            printf("\nNode Deleted Successfully!!");
            return start;
        }
        else
        {
            struct node *ptr2, *ptr3;
            ptr2 = ptr->next;
            ptr3= ptr2->next;
            ptr->next = ptr3;
            ptr3->prev = ptr;
            free(ptr2);
            printf("\nNode Deleted Successfully!!");
            return start;
        }
    }

    return start;
}

struct node *del_all(struct node *start)
{
    struct node *ptr = start;
    while(start!=NULL)
    {
        if(ptr->next ==NULL)
        {
            start = NULL;
            free(ptr);
        }
        else
        {
            struct node *temp = start;
            start = start->next;
            free(temp);
        }
    }
    printf("\nList deleted successfully!!!");
    return start;
}
