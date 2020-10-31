#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *);
struct stack *pop(struct stack *);
struct stack *peek(struct stack *);
struct stack *display(struct stack*);
int main()
{
    int option;
    do
    {
        printf("\n*****MAIN MENU*****");
        printf("\n 1.Push");
        printf("\n 2.Pop");
        printf("\n 3.Peek");
        printf("\n 4.Display");
        printf("\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                top = peek(top);
                break;
            case 4:
                top = display(top);
                break;


        }
    }
    while(option!=5);
    return 0;
}

struct stack *push(struct stack *top)
{
    struct stack *element = (struct stack *) malloc(sizeof(struct stack *));
    if(element == NULL)
    {
        printf("\nOverflow!!!");
        return top;
    }
    else
    {
        printf("\nEnter the element:");
        int el;
        scanf("%d",&el);
        element->data = el;
        if(top==NULL)
        {
            top = element;
            top->next = NULL;

        }
        else
        {
            struct stack *ptr = top;
            top = element;
            top->next = ptr;
            return top;
        }
    }
}

struct stack *display(struct stack *top)
{
    if(top==NULL)
    {
        printf("\nThe stack is empty");
        return top;
    }
    else
    {
        printf("\nThe stack is as follows:");
        struct stack *ptr = top;
        while(ptr!=NULL)
        {
            printf("\n %d",ptr->data);
            ptr = ptr->next;
        }
        return top;
    }
}

struct stack *peek(struct stack *top)
{
    printf("\nPeek: %d",top->data);
    return top;
}
struct stack *pop(struct stack *top)
{
    if(top==NULL)
    {
        printf("\nUndeflow!!!");
        return top;
    }
    else if(top->next==NULL)
    {
        free(top);
        top=NULL;
        return top;
    }
    else
    {
        struct stack *ptr = top;
        top = top->next;
        free(ptr);
        return top;
    }
}
