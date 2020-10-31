#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *add_list(struct node *);
struct node *display(struct node *);
struct node *add_beg(struct node *);
struct node *add_end(struct node *);
struct node *del_beg(struct node *);
struct node *del_end(struct node *);
struct node *del_node(struct node *);
struct node *del_all(struct node *);

int main()
{
    int option;
    do
    {
        printf("\n*****MAIN MENU*****");
        printf("\n  1.Create a List");
        printf("\n  2.Display List");
        printf("\n  3.Add a node at the beginning");
        printf("\n  4.Add a node at the end");
        printf("\n  5.Delete first node");
        printf("\n  6.Delete last node");
        printf("\n  7.Delete a given node");
        printf("\n  8.Delete all nodes");
        printf("\nEnter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                start = add_list(start);
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
                start = del_beg(start);
                break;
            case 6:
                start = del_end(start);
                break;
            case 7:
                start = del_node(start);
                break;
            case 8:
                start = del_all(start);
                break;


        }
    }
    while(option!=9);
    return 0;
}

struct node *add_list(struct node *start)
{
    int num;
    printf("\nEnter -1 to stop!!!");
    printf("\nEnter the data:");
    scanf("%d",&num);
    while(num!=-1)
    {
        if(start==NULL)
        {
            struct node *ptr = (struct node *) malloc(sizeof(struct node *));
            ptr->data = num;
            ptr->next = ptr;
            ptr->prev = ptr;
            start = ptr;
        }
        else
        {
            struct node *new_node = (struct node *) malloc(sizeof(struct node *));
            new_node->data = num;
            struct node *ptr = start;
            while(ptr->next!=start)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = start;
            start->prev = new_node;
            new_node->prev = ptr;
        }
        printf("\nEnter the data:");
        scanf("%d",&num);

    }
    return start;

}

struct node *display (struct node *start)
{
    struct node *ptr = start;
    if(ptr==NULL)
    {
        printf("\nThe list is empty!!!");
        return start;
    }
    else
    {
        printf("\nThe list is as follows: \n");
        while(ptr->next!=start)
        {
            printf("\t %d,",ptr->data);
            ptr= ptr->next;
        }
        printf("\t %d",ptr->data);
        return start;
    }
}

struct node *add_beg(struct node *start)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    printf("\nEnter the element you want to enter:");
    int num;
    scanf("%d",&num);
    if(start==NULL)
    {
        new_node->data =num;
        new_node->prev = new_node;
        new_node->next=new_node;
        printf("\nElement added successfully!!!");
        return start;
    }
    else
    {
        new_node->data = num;
        struct node *ptr = start;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->next = start;
        start->prev = new_node;
        new_node->prev = ptr;
        printf("\nElement added sucessfully!!!");
        return start;
    }
}

struct node *add_end(struct node *start)
{
    printf("\nEnter the element you want to enter:");
    int num;
    scanf("%d",&num);
    if(start==NULL)
    {
        struct node *new_node = (struct node *) malloc (sizeof(struct node *));
        new_node->data = num;
        start = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
        return start;
    }
    else
    {
        struct node *ptr = start;
        while(ptr->next != start)
            ptr=ptr->next;
        struct node *new_node = (struct node *) malloc(sizeof(struct node *));
        new_node->data = num;
        ptr->next = new_node;
        new_node->next = start;
        start->prev = new_node;
        new_node->prev = ptr;
        return start;
    }
}

struct node *del_beg(struct node *start)
{
    struct node *ptr = start;
    if(ptr==NULL)
    {
        printf("\nThe list is empty!!!");
        return start;
    }
    else if(ptr->next==start)
    {
        start = NULL;
        free(ptr);
        printf("\nNode deleted successfully");
        return start;
    }
    else
    {
        start = start->next;
        start->prev = ptr->prev;
        (ptr->prev)->next = start;
        free(ptr);
        printf("\nNode deleted successfully");
        return start;
    }
}

struct node *del_end(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> prev -> next = start;
        start -> prev = ptr -> prev;
    free(ptr);
    return start;

}

struct node *del_node (struct node *start)
{
    struct node *ptr;
    int val;
    printf("\n Enter the value of the node which has to be deleted : ");
    scanf("%d", &val);
    ptr = start;
    if(ptr -> data == val)
    {
        start = del_beg(start);
        return start;
    }
    else
    {
        while(ptr -> data != val)
            ptr = ptr -> next;
        ptr -> prev -> next = ptr -> next;
        ptr -> next -> prev = ptr -> prev;
        free(ptr);
        return start;
    }
}

struct node *del_all(struct node *start)
{
    struct node *ptr;
    ptr =start;
    while(ptr->next !=start)
        start = del_end(start);
    free(start);
    return start;
}
