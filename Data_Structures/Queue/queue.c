/*global variable*/
const int SIZE = 10;

struct Queue {
	int *store; /*the array with the elements*/
	int max_size;
	int size;
        int start;
};
typedef struct Queue Queue;

int init(Queue *x)
{
    if (x == NULL)
    {
        return -1;
    }
    x->store = (int *)malloc(SIZE*sizeof(int));
    if (x->store == NULL)
    {
        return -1;
    }
    x->max_size = SIZE;
    x->size = 0;
    x->start = 0;
    return 0;
}

int enq(Queue *x, int val)
{
    if (x == NULL)
    {
        return -1;
    }
    if (x->size == x->max_size)
    {
        /*blew the memory*/
        return -1;
    }
    x->store[(x->start + x->size) % x->max_size] = val;
    x->size += 1;
    return 0;
}

/*pval is a return value*/
int deq(Queue *x, int *pval)
{
    int i=0;
    if (x == NULL)
    {
        return -1;
    }
    if (pval == NULL)
    {
        return -1;
    }
    if (x->size == 0)
    {
        return -1;
    }
    *pval = x->store[x->start];
    x->store[x->start] = 0;
    x->start = (x->start + 1) % x->max_size;
    x->size -= 1;
    return 0;
}

int isEmpty(Queue x, int *r)
{
    if (r == NULL)
    {
        return -1;
    }
    if (x.size == 0)
    {
        *r = 1;
        return 0;
    }
    else
    {
        *r = 0;
        return 0;
    }
}

int isFull(Queue x, int *r)
{
    if (r == NULL)
    {
        return -1;
    }
    if (x.size == x.max_size)
    {   
        *r = 1;
        return 0;
    }
    else
    {   
        *r = 0;
        return 0;
    }
}

int print_queue(Queue x)
{
    int i = 0;
    for (i=(x.size-1); i>=0; i--)
    {
        printf("%d\n",x.store[(i+x.start)%x.max_size]);
    }
    return 0;
}

int free_queue(Queue x)
{
    free(x.store);
    return 0;
}
