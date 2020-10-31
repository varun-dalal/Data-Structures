#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_at_beginning(struct node *);
struct node *insert_at_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *del(struct node *);
struct node *sort_list(struct node *);
int main(){
    int option;
    do
    {

        printf("\n\n *****MAIN MENU*****");
        printf("\n  1: Create a list");
        printf("\n  2: Display the list");
        printf("\n  3: Insert an element at beginning");
        printf("\n  4: Insert an element at end");
        printf("\n  5: Insert an element before a node");
        printf("\n  6: Insert an element after a node");
        printf("\n  7: Deleting the first node");
        printf("\n  8: Deleting the last node");
        printf("\n  9: Deleting a given node");
        printf("\n 10: Delete element after a given node");
        printf("\n 11: Delete entire list");
        printf("\n 12: Sort List");
        printf("\n 13: EXIT");
        printf("\nEnter your option:");
        scanf("%d",&option);
        switch(option)
        {

            case 1:
                start = create_ll(start);
                printf("\nLINKED LIST CREATED");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_at_beginning(start);
                break;
            case 4:
                start = insert_at_end(start);
                break;
            case 5:
                start = insert_before(start);
                break;
            case 6:
                start = insert_after(start);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start);
                break;
            case 9:
                start = delete_node(start);
                break;
            case 10:
                start = delete_after(start);
                break;
            case 11:
                start = delete_list(start);
                break;
            case 12:
                start = sort_list(start);
                break;

        }
    }
    while(option!=13);
    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data:");
    scanf("%d",&num);
    while(num!=-1)
    {

        new_node = (struct node *) malloc (sizeof(struct node));
        new_node->data = num;
        if(start==NULL)
        {

            new_node->next = NULL;
            start = new_node;
        }
        else
        {
           ptr = start;
           while(ptr->next != NULL)
            ptr = ptr->next;
           ptr->next = new_node;
           new_node->next = NULL;
        }
        printf("\nEnter the data:");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("\t %d,",ptr->data);
        ptr=ptr->next;
    }
    return start;
}


struct node *insert_at_beginning(struct node *start)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    int num;
    printf("\nEnter the element to be added:");
    scanf("%d",&num);
    new_node->data =num;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *insert_at_end(struct node *start)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    int num;
    printf("\nEnter the element to be added:");
    scanf("%d",&num);
    new_node->data =num;
    new_node->next = NULL;
    struct node *ptr = start;
    while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    ptr->next = new_node;
    return start;

}

struct node *insert_before(struct node *start)
{
    printf("\nEnter the element before which you want to add an element:");
    int bef;
    scanf("%d",&bef);
    printf("\nEnter the element to be added:");
    int num;
    scanf("%d",&num);
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    new_node->data = num;
    int found=0;
    struct node *ptr0,*ptr1 =start;
    while(ptr1!=NULL)
    {
        if(ptr1->data == bef)
        {
            found=1;
            break;
        }
        ptr0=ptr1;
        ptr1=ptr1->next;
    }
    if(!found)
    {
        printf("\nThe element was not found!!!");
        main();
    }
    else
    {
      ptr0->next = new_node;
      new_node->next = ptr1;
    }
    return start;
}

struct node *insert_after(struct node *start)
{
    int after;
    printf("\nEnter the node after which you want to add element:");
    scanf("%d",&after);
    int num;
    printf("\nEnter the element to be added:");
    scanf("%d",&num);
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    new_node->data = num;
    struct node *ptr = start;
    int found =0;
    while(ptr!=NULL)
    {
        if(ptr->data == after)
        {
            found =1;
            break;
        }
        ptr=ptr->next;
    }
    if(!found)
    {

        printf("\nThe node doesn't exist");
        main();
    }
    else
    {
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    return start;
}

struct node *delete_beg(struct node *start)
{
    printf("\nDeleting the first node!!!");
    struct node *ptr = start;
    start = ptr->next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    printf("\nDeleting the last node!!!");
    struct node *ptr = start;
    struct node *ptr0 = start;
    while(ptr->next !=NULL)
    {
        ptr0=ptr;
        ptr=ptr->next;

    }
    ptr0->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start)
{
    int del;
    printf("\nEnter the node to be deleted:");
    scanf("%d",&del);
    int found =0;
    struct node *ptr0,*ptr = start;
    while(ptr!=NULL)
    {
        if(ptr->data==del)
        {
            found =1;
            break;
        }
        ptr0=ptr;
        ptr = ptr->next;
    }
    if(!found)
    {
        printf("\nThe node doesn't exist");
        main();
    }
    else
    {
        ptr0->next = ptr->next;
        free(ptr);
    }
    return start;
}

struct node *delete_after(struct node *start)
{
    int after;
    printf("\nEnter the node after which you want to delete element:");
    scanf("%d",&after);
    struct node *ptr =start;
    int found =0;
    while(ptr!=NULL)
    {
        if(ptr->data ==after)
        {
            found =1;
            break;
        }
        ptr=ptr->next;
    }
    struct node *ptr2 = (ptr->next);
    ptr->next = ptr2->next;
    free(ptr2);
    return start;
}

struct node *del(struct node *start)
{
    struct node *ptr = start;
    start = ptr->next;
    free(ptr);
    return start;
}
struct node *delete_list(struct node *start)
{
    while(start!=NULL)
    {
        start = del(start);
    }
    printf("\nList deleted!!!");
    return start;
}

struct node *sort_list(struct node *start)
{
    struct node *ptr = start;
    while(ptr!=NULL)
    {
        struct node *ptr2 = ptr->next;
        while(ptr2!=NULL)
        {
            if(ptr->data >ptr2->data)
            {
                int temp= ptr->data;
                ptr->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
    display(start);
    return start;
}
