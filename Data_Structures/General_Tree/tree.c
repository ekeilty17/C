struct llnode {
   struct TreeNode *tree; /*linked list of tree nodes*/
   struct llnode *next;
};
typedef struct llnode llnode;

struct TreeNode {
    int val;
    struct llnode *succs;
};
typedef struct TreeNode TreeNode;

#include "ll.c"
#include "ll_queue.c"

TreeNode* init(int val)
{
    int r=0;
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->val = val;
    temp->succs = NULL;
    return temp;
}

/*there's no way of organizing a general tree that isn't arbitrary
so the user will have to put the tree in the order they wish*/
/*this means instead of adding a value, they have to add a node*/
int add(TreeNode **root, TreeNode *node)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    if (*root == NULL)
    {
        /*the root was not initialized as a node*/
        return -1;
    }
    if (node == NULL)
    {
        return -1;
    }
    else
    {
        r=ll_add_to_tail(&((*root)->succs), node);
        return 0;
    }
}

int printDepth_rec(TreeNode *root, int tab)
{
    int i = 0;
    llnode *curr = root->succs;
    for(i=0; i<tab; i++)
    {
        printf("\t");
    }
    tab += 1;
    printf("%d\n",root->val);
    
    while (curr != NULL)
    {
        printDepth_rec(curr->tree, tab);
        curr = curr->next;
    }
    return 0;
}
int printDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return printDepth_rec(root, 0);
}

/*Transversals (visiting every node in order)*/
int Level_Order(TreeNode *root)
{
    int r = 0;
    int count = 0;
    TreeNode *temp = NULL;
    llnode *curr = NULL;
    Queue *q = NULL;
    if (root == NULL)
    {
        return -1;
    }
    r=enq(&q, root);

    while (q != NULL)
    {
        count = size(q);
        while (count > 0)
        {
            r=q->val->val;
            printf("%d ",r);
            r=deq(&q, &temp);
            curr = temp->succs;
            while (curr != NULL)
            {
                r=enq(&q, curr->tree);
                curr = curr->next;
            }
            count -= 1;
        }
        printf("\n");
    }
    return 0;
}

/*this will also do a "pre order"-esque traversal*/
TreeNode* searchTree(TreeNode *root, int val)
{
    TreeNode *node = NULL;
    llnode *curr = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        return root;
    }
    else
    {
        curr = root->succs;
        /*if curr == NULL we are at the end of the succs
          if node == NULL then we still havent found the node*/
        while ((curr != NULL) && (node == NULL))
        {
            /*printf("%d\n",curr->tree->val);*/
            node=searchTree(curr->tree, val);
            curr = curr->next;
        }
        return node;
    }
}

int free_tree(TreeNode *root)
{
    int r = 0;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        llnode *head = root->succs;
        llnode *curr = head;
        free(root);
        while (curr != NULL)
        {
            r=free_tree(curr->tree);
            curr = curr->next;
        }
        r=ll_free(head);
        return 0;
    }
}
