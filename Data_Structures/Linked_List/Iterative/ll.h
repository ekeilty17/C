struct llnode {            /* since the llnode is a self-referential structure */
   int val;                /* we can not compile the struct and typedef decl into one */
   struct llnode *next;
};
typedef struct llnode llnode;

int ll_add_to_head( llnode **head, int val);
int ll_add_to_tail( llnode **head, int val);
int ll_print_from_head( llnode *p);
int ll_print_from_tail( llnode *p);
int ll_free( llnode *p);

/*my helper functions*/
int ll_find_by_value(llnode *pList,int val);
int ll_del_from_tail(llnode **ppList);
int ll_del_from_head(llnode **ppList);
int ll_del_by_value(llnode **ppList,int val);
int ll_insert_in_order(llnode **ppList,int val);
int ll_concat(llnode **pSrcA,llnode **pSrcB);
int ll_sort(llnode **ppList);
int ll_index(llnode *pList, int index);
int ll_length(llnode *pList);
