#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *add_beg(struct node *);
struct node *add_end(struct node *);
struct node *del_beg(struct node *);
struct node *del_end(struct node*);
struct node *del_after(struct node *);
struct node *del_list(struct node *);


int main()
{
    int option;
    do
    {
        printf("\n\n *****MAIN MENU*****");
        printf("\n  1: Create a list");
        printf("\n  2. Display the circular linked list");
        printf("\n  3. Add a node at beginning");
        printf("\n  4. Add a node at the end");
        printf("\n  5. Delete the node at the beginning");
        printf("\n  6. Delete the node at the end");
        printf("\n  7. Delete a node after a given node");
        printf("\n  8. Delete the entire list");
        printf("\n  9. EXIT");
        printf("\n Enter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                start = create_cll(start);
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
                start = del_after(start);
                break;
            case 8:
                start = del_list(start);
                break;
        }
    }
    while(option!=9);
    return 0;
}

struct node *create_cll(struct node *start)
{
     printf("\n Enter -1 to stop");
     printf("\nEnter the data:");
     int num;
     scanf("%d",&num);
     while(num!=-1)
     {
         struct node *new_node = (struct node *) malloc(sizeof(struct node *));
         new_node->data = num;
         if(start == NULL)
         {
             new_node->next = new_node;
             start = new_node;
         }
         else
         {
             struct node *ptr = start;
             while(ptr->next != start)
             {
                 ptr=ptr->next;
             }
             ptr->next = new_node;
             new_node->next = start;
         }
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
        printf("\nThe Circular LL is empty!!!");

    }
    else
    {
        printf("\nThe Circular LL is as follows:\n");
        do
        {
            printf("\t %d,",ptr->data);
            ptr = ptr->next;
        }
        while(ptr != start);

    }

    return start;
}

struct node *add_beg(struct node *start)
{
    printf("\nEnter the element to be added:");
    int num;
    scanf("%d",&num);
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    new_node->data = num;
    struct node *end = start;
    while(1)
    {
        if(end->next == start)
            break;
        end= end->next;
    }
    end->next = new_node;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node *add_end(struct node *start)
{
    printf("\nEnter the number to be added at the end :");
    int num;
    scanf("%d",&num);
    struct node *new_node = (struct node *) malloc(sizeof(struct node *));
    new_node->data = num;
    struct node *end = start;
    while(1)
    {
        if(end-> next == start)
            break;
        end=end->next;
    }
    end->next = new_node;
    new_node->next = start;
    return start;
}

struct node *del_beg(struct node *start)
{
    struct node *ptr = start;
    if(ptr==NULL)
    {
        printf("\nThe Circular Linked List is empty!!!");
        main();
    }
    else if(ptr->next == ptr)
    {
        free(ptr);
        start = NULL;
        printf("\nDeleted the first node successfully");

    }
    else
    {
        while(ptr->next!= start)
            ptr=ptr->next;
        ptr->next = start->next;
        struct node *del = start;

        start = start->next;
        printf("\nDeleted the first node successfully");
        free(del);


    }
    return start;
}
struct node *del_end(struct node *start)
{
    struct node *ptr = start;
    if(ptr==NULL)
    {
        printf("\nThe Circular Linked List is empty!!!");
        main();
    }
    else if(ptr->next == ptr)
    {
        start = NULL;
        free(ptr);
         printf("\nDeleted the last node successfully");
    }
    else
    {
        struct node *preptr = start;
        while(ptr->next != start)
        {
            preptr = ptr;
            ptr=ptr->next;
        }

        preptr->next = start;
        free(ptr);
         printf("\nDeleted the last node successfully");
    }
    return start;
}

struct node *del_after(struct node *start)
{
    printf("Enter the value after which the node has to be deleted:");
    int num;
    scanf("%d",&num);
    struct node *ptr = start;
    if(ptr->next == ptr)
    {
        free(ptr);
        start = NULL;
        return start;
    }

    struct node *postptr = NULL;
    int found =0;
    do
    {
        if(ptr->data == num)
        {
            found = 1;
            break;
        }
        ptr= ptr->next;
    }
    while (ptr!=start);
    if(found)
    {
        struct node *temp = ptr->next;
        postptr = ptr;
        for(int i=0;i<2;i++)
            postptr = postptr->next;
        free(temp);
        ptr->next = postptr;

    }
    else
    {
        printf("\nNode not found");
        main();
    }
    return start;
}

struct node *del_list(struct node *start)
{
    while(start!=NULL)
    {
        struct node *ptr = start;
        if(ptr->next == ptr)
        {
            free(ptr);
            start = NULL;
        }
        else
        {
            while(ptr->next!= start)
                ptr=ptr->next;
            ptr->next = start->next;
            struct node *del = start;

            start = start->next;
            free(del);


        }
    }
    return start;
}
