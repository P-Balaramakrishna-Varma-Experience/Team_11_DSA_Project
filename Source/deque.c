#include "../Header/AllModule.h" 


void display(Deque fl) //to print the elements present in the deque
{
    Deque t = fl;
    if (t == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        while (t != NULL)
        {
            PrintGElemType(t->val1);
            t = t->next;
        }
    }
}

struct NodeDq *New() //to create a newnode
{
    struct NodeDq *new;
    new = (struct NodeDq *)malloc(sizeof(struct NodeDq));
    new->next = NULL;
    new->prev = NULL;
    //assert(new != NULL);
    return new;
}

void inject(GElementType val1) // add element to the from the back end
{
    Deque new = New();

    new->val1 = val1;
    //new->val2 =val2;
    if (rear == NULL)
    {
        front = rear = new;
    }
    else
    {
        new->prev = rear;
        rear->next = new;
        rear = new;
    }
}

void push(GElementType val1) //add element from the front side
{
    Deque new = New();
    new->val1 = val1;
    //new->val2 = val2;
    if (front == NULL)
    {
        rear = front = new;
    }
    else
    {
        new->next = front;
        front->prev = new;
        front = new;
    }
}

GElementType pop() // to delete the element from the front side
{
    if (front == NULL)
    {
        printf("Enter exit");
        exit(0);
    }
    else
    {
        Deque t = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        else
        {
            front->prev = NULL;
        }

        GElementType data_present = t->val1;
        free(t);
        return data_present;
    }
}

GElementType eject() //to delete element from back side
{
    if (front == NULL)
    {
        printf("Enter exit ");
        exit(0);
    }
    else
    {
        Deque t = rear;
        rear = rear->prev;
        if (rear == NULL)
        {
            front = NULL;
        }
        else
        {
            rear->next = NULL;
        }
        GElementType data_present = t->val1;
        free(t);
        return data_present;
    }
}

void DeleteDeque(void)
{
    while (front != NULL)
    {
        GElementType u = pop();
        DeleteGElemType(u);
    }
}

/* int main()
{
    char name[10];
    printf("type : \npush--to add element from front\ninject--to add elememt from back\npop--to delete element from first\neject--delete element from last\nexit--to exit from the code\n");
    while (1)
    {
        scanf("%s", name);
        if (strcmp("push", name) == 0)
        {
            int a;
            scanf("%d", &a);
            push(a);
            display(front);
        }
        else if (strcmp("inject", name) == 0)
        {
            int a;
            scanf("%d", &a);
            inject(a);
            display(front);
        }
        else if (strcmp("pop", name) == 0)
        {
            pop();
            display(front);
        }
        else if (strcmp("eject", name) == 0)
        {
            eject();
            display(front);
        }
        else if (strcmp("exit", name) == 0)
        {
            exit(0);
        }
    }
} */