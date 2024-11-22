#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    int *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void push(struct stack *ptr,int val)
{
    if(isFull(ptr))
    {
        printf("stack is overflow,%d is not pushed !!!\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
        printf("%d is pushed \n",ptr->arr[ptr->top]);
    }
}

void pop(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("stack is underflow");
    }
    else{
        int no=ptr->arr[ptr->top];
        ptr->top--;
        printf("%d is poped \n",no);
    }
}

int peek(struct stack* sp, int i)
{
    int arrayInd = sp->top -i + 1;

    if(arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
    }
}




 
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    
    printf("%d\n",isEmpty(s));
    printf("%d\n",isFull(s));

    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);

    pop(s);
    pop(s);
    pop(s);
    
    push(s,100);
    push(s,1000);
    push(s,555);

    printf("%d\n",isEmpty(s));
    printf("%d\n",isFull(s));

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }

    return 0;
}
