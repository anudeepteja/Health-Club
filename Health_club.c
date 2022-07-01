#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_name 50
int val = 1000; 
typedef enum { F, T } bool;
int random(void)
{
    int ans = val;
    val++;
    return ans;
}
struct members
{
    int Id;
    char Name[max_name];
    int Age;
    char gender;
    bool yoga;
    bool cardio;
    bool zumba;
    bool weight_lifting;
    int F_yoga;
    int F_cardio;
    int F_zumba;
    int F_weight_lifting;
    struct members* left;
    struct members* right;
    int height;
};
struct trainers {

    int Id;
    char T_name[max_name];
    bool p_yoga;
    bool p_cardio;
    bool p_zumba;
    bool p_weight_lifting;
    int R_yoga;
    int R_cardio;
    int R_zumba;
    int R_weight_lifting;
    struct trainers* left;
    struct trainers* right;
    int height;
};
struct members* lptr1 = NULL;
struct trainers* lptr2 = NULL;
struct avail_members{

    char Name[max_name];
    int Id;
    bool yoga;
    bool cardio;
    bool zumba;
    bool weight_lifting;
    //prefferd trainer's id
    int T_Id;
    //prefferd time
    int time;
    int height;
    struct avail_members* left;
    struct avail_members* right;
};
int max(int a, int b);
int height_avail_members(struct avail_members *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height_avail_members(N->left), height_avail_members(N->right));
}
int getBalance_avail_members(struct avail_members *N)
{
    if (N == NULL)
        return 0;
    return height_avail_members(N->left) - height_avail_members(N->right);
}
struct avail_members* rightRotate_avail_members(struct avail_members *y)
{
    struct avail_members *x = y->left;
    struct avail_members *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = height_avail_members(y);
    x->height = height_avail_members(x);
 
    return x;
}
struct avail_members* leftRotate_avail_members(struct avail_members *x)
{
    struct avail_members *y = x->right;
    struct avail_members *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = height_avail_members(x);
    y->height = height_avail_members(y);
 
    return y;
}
struct avail_trainers{

    char Name[max_name];
    int Id;
    bool yoga;
    bool cardio;
    bool zumba;
    bool weight_lifting;
    int y_rem;
    int c_rem;
    int z_rem;
    int w_rem;
    int height;
    struct avail_trainers* left;
    struct avail_trainers* right;
};
int height_avail_trainers(struct avail_trainers *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height_avail_trainers(N->left), height_avail_trainers(N->right));
}
int getBalance_avail_trainers(struct avail_trainers *N)
{
    if (N == NULL)
        return 0;
    return height_avail_trainers(N->left) - height_avail_trainers(N->right);
}
struct avail_trainers* rightRotate_avail_trainers(struct avail_trainers *y)
{
    struct avail_trainers *x = y->left;
    struct avail_trainers *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = height_avail_trainers(y);
    x->height = height_avail_trainers(x);
 
    return x;
}
struct avail_trainers* leftRotate_avail_trainers(struct avail_trainers *x)
{
    struct avail_trainers *y = x->right;
    struct avail_trainers *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = height_avail_trainers(x);
    y->height = height_avail_trainers(y);
 
    return y;
}
struct avail_members* head1 = NULL;
struct avail_trainers* head2 = NULL;

struct yoga_trainers{
    int Id;
    int status[16];
    struct yoga_trainers* next;
};
struct cardio_trainers{
    int Id;
    int status[16];
    struct cardio_trainers* next;
};
struct zumba_trainers{
    int Id;
    int status[16];
    struct zumba_trainers* next;
};
struct weight_lifting_trainers{
    int Id;
    int status[16];
    struct weight_lifting_trainers* next;
};
struct yoga_trainers* y_head = NULL;
struct cardio_trainers* c_head = NULL;
struct zumba_trainers* z_head = NULL;
struct weight_lifting_trainers* w_head = NULL;
struct slot_box{
    int mem_ids[10];
    int trai_ids[10];
};
struct slot_head{
    
    int T;
    int slot_avail ;
    int yoga_trainers_available;
    struct yoga_trainers* y_ptr;
    int cardio_trainers_available;
    struct cardio_trainers* c_ptr;
    int zumba_trainers_available;
    struct zumba_trainers* z_ptr;
    int weight_lifting_trainers_available;
    struct weight_lifting_trainers* w_ptr;
    struct slot_box s;
};
struct slot_head A1[16];
struct fixed_list{
    int time;
    int m_Id;
    int t_Id;
    int pgm;
    int height;
    struct fixed_list* left;
    struct fixed_list* right;
};
struct fixed_list* first = NULL;
int height_fixed(struct fixed_list *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height_fixed(N->left), height_fixed(N->right));
}
int getBalance_fixed(struct fixed_list *N)
{
    if (N == NULL)
        return 0;
    return height_fixed(N->left) - height_fixed(N->right);
}
struct fixed_list* rightRotate_fixed(struct fixed_list *y)
{
    struct fixed_list *x = y->left;
    struct fixed_list *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = height_fixed(y);
    x->height = height_fixed(x);
 
    return x;
}
struct fixed_list* leftRotate_fixed(struct fixed_list *x)
{
    struct fixed_list *y = x->right;
    struct fixed_list *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = height_fixed(x);
    y->height = height_fixed(y);
 
    return y;
}
struct non_fixed_list{
    int Id;
    int height;
    struct non_fixed_list* left;
    struct non_fixed_list* right;
};
struct non_fixed_list* non_first = NULL;
int height_non_fixed(struct non_fixed_list *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height_non_fixed(N->left), height_non_fixed(N->right));
}
int getBalance_non_fixed(struct non_fixed_list *N)
{
    if (N == NULL)
        return 0;
    return height_non_fixed(N->left) - height_non_fixed(N->right);
}
struct non_fixed_list* rightRotate_non_fixed(struct non_fixed_list *y)
{
    struct non_fixed_list *x = y->left;
    struct non_fixed_list *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = height_non_fixed(y);
    x->height = height_non_fixed(x);
 
    return x;
}
struct non_fixed_list* leftRotate_non_fixed(struct non_fixed_list *x)
{
    struct non_fixed_list *y = x->right;
    struct non_fixed_list *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = height_non_fixed(x);
    y->height = height_non_fixed(y);
 
    return y;
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
int height_members(struct members *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height_members(N->left), height_members(N->right));
}
int height_trainers(struct trainers *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height_trainers(N->left), height_trainers(N->right));
}
int getBalance_members(struct members *N)
{
    if (N == NULL)
        return 0;
    return height_members(N->left) - height_members(N->right);
}
int getBalance_trainers(struct trainers *N)
{
    if (N == NULL)
        return 0;
    return height_trainers(N->left) - height_trainers(N->right);
}
struct members* rightRotate_members(struct members *y)
{
    struct members *x = y->left;
    struct members *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = height_members(y);
    x->height = height_members(x);
 
    return x;
}
struct members* leftRotate_members(struct members *x)
{
    struct members *y = x->right;
    struct members *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = height_members(x);
    y->height = height_members(y);
 
    return y;
}
struct trainers* rightRotate_trainers(struct trainers *y)
{
    struct trainers *x = y->left;
    struct trainers *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = height_trainers(y);
    x->height = height_trainers(x);
 
    return x;
}
struct trainers* leftRotate_trainers(struct trainers *x)
{
    struct trainers *y = x->right;
    struct trainers *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = height_trainers(x);
    y->height = height_trainers(y);
 
    return y;
}
struct Trainer_sort
{
    int Id;
    char Name[max_name];
    int y_rem;
    int c_rem;
    int z_rem;
    int w_rem;
    int T_Remunaration;
    int height;
    struct Trainer_sort* left;
    struct Trainer_sort* right;
};
struct Trainer_sort* T_ahead = NULL;

int height_Trainer_sort(struct Trainer_sort *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height_Trainer_sort(N->left), height_Trainer_sort(N->right));
}
int getBalance_Trainer_sort(struct Trainer_sort *N)
{
    if (N == NULL)
        return 0;
    return height_Trainer_sort(N->left) - height_Trainer_sort(N->right);
}
struct Trainer_sort* rightRotate_Trainer_sort(struct Trainer_sort *y)
{
    struct Trainer_sort *x = y->left;
    struct Trainer_sort *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = height_Trainer_sort(y);
    x->height = height_Trainer_sort(x);
 
    return x;
}
struct Trainer_sort* leftRotate_Trainer_sort(struct Trainer_sort *x)
{
    struct Trainer_sort *y = x->right;
    struct Trainer_sort *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = height_Trainer_sort(x);
    y->height = height_Trainer_sort(y);
 
    return y;
}
struct members* create_member(void)
{
    struct members *nptr1;
    nptr1 = (struct members*)malloc(sizeof(struct members));
    nptr1->Id = random();
    printf("Enter the name of member \n");
    scanf(" %[^\n]%*c",nptr1->Name);
    printf("Enter the age of member \n");
    scanf(" %d",&nptr1->Age);
    printf("Enter the gender of member (M/F) \n");
    scanf(" %c",&nptr1->gender);
    printf("Enter 1 if member wants yoga else enter 0 \n");
    int a;
    scanf("%d",&a);
    if(a == 1) {
        nptr1->yoga = T;
    }
    else
    {
        nptr1->yoga = F;
    }
    printf("Enter 1 if member wants cardio else enter 0 \n");
    scanf("%d",&a);
    if(a == 1) {
        nptr1->cardio = T;
    }
    else
    {
        nptr1->cardio = F;
    }
    printf("Enter 1 if member wants zumba else enter 0 \n");
    scanf("%d",&a);
    if(a == 1) {
        nptr1->zumba = T;
    }
    else
    {
        nptr1->zumba = F;
    }
    printf("Enter 1 if member wants weight lifting else enter 0 \n");
    scanf("%d",&a);
    if(a == 1) {
        nptr1->weight_lifting = T;
    }
    else
    {
        nptr1->weight_lifting = F;
    }
    if(nptr1->yoga == T)
    {
        printf("enter fees paid by member to yoga \n");
        scanf("%d",&nptr1->F_yoga);
    }
    else
    {
        nptr1->F_yoga = 0;
    }
    if(nptr1->cardio == T)
    {
        printf("enter fees paid by member to cardio \n");
        scanf("%d",&nptr1->F_cardio);
    }
    else
    {
        nptr1->F_cardio = 0;
    }
    if(nptr1->zumba == T)
    {
        printf("enter fees paid by member to zumba \n");
        scanf("%d",&nptr1->F_zumba);
    }
    else
    {
        nptr1->F_zumba = 0;
    }
    if(nptr1->weight_lifting == T)
    {
        printf("enter fees paid by member to weight lifting \n");
        scanf("%d",&nptr1->F_weight_lifting);
    }
    else
    {
        nptr1->F_weight_lifting = 0;
    }
    nptr1->left = NULL;
    nptr1->right = NULL;
    nptr1->height = 0;

    return nptr1;
}
struct trainers *create_trainer(void)
{
    struct trainers *nptr2;
    nptr2 = (struct trainers *)malloc(sizeof(struct trainers));
    nptr2->Id = random();
    printf("Enter the name of the trainer \n ");
    scanf(" %[^\n]%*c", nptr2->T_name);
    int a;
    nptr2->p_yoga = F;
    nptr2->p_cardio = F;
    nptr2->p_zumba = F;
    nptr2->p_weight_lifting = F;
    printf("Enter 1 if trainer knows yoga else 0 \n");
    scanf(" %d", &a);
    if (a == 1)
    {
        nptr2->p_yoga = T;
    }
    if (a == 0)
    {
        printf("Enter 1 if trainer knows cardio else 0 \n");
        scanf("%d", &a);
        if (a == 1)
        {
            nptr2->p_cardio = T;
        }
    }
    if (a == 0)
    {
        printf("Enter 1 if trainer knows zumba else 0 \n");
        scanf("%d", &a);
        if (a == 1)
        {
            nptr2->p_zumba = T;
        }
    }
    if (a == 0)
    {
        printf("Enter 1 if trainer knows weight lifting else 0 \n");
        scanf("%d", &a);
        if (a == 1)
        {
            nptr2->p_weight_lifting = T;
        }
    }
    if(nptr2->p_yoga == T)
    {
        printf("Enter remuneration for yoga \n");
        scanf("%d", &nptr2->R_yoga);
    }
    else
    {
        nptr2->R_yoga = 0;
    }
    if(nptr2->p_cardio == T)
    {
        printf("Enter remuneration for cardio \n");
        scanf("%d", &nptr2->R_cardio);
    }
    else
    {
        nptr2->R_cardio = 0;
    }
    if(nptr2->p_zumba == T)
    {
        printf("Enter remuneration for zumba \n");
        scanf("%d", &nptr2->R_zumba);
    }
    else
    {
        nptr2->R_zumba = 0;
    }
    if(nptr2->p_weight_lifting == T)
    {
        printf("Enter remuneration for weight lifting \n");
        scanf("%d", &nptr2->R_weight_lifting);
    }
    else
    {
        nptr2->R_weight_lifting = 0;
    }
    nptr2->left = NULL;
    nptr2->right = NULL;
    nptr2->height = 0;
    return nptr2;
}
struct members *insert_member(struct members *nptr, struct members *r)
{
    if (nptr == NULL)
        return r;

    if (nptr->Id > r->Id)
    {
        nptr->left = insert_member(nptr->left, r);
    }
    else if(nptr->Id < r->Id)
    {
        nptr->right = insert_member(nptr->right, r);
    }
    nptr->height = height_members(nptr);

    int balance = getBalance_members(nptr);
    if (balance > 1 && r->Id < (nptr->left)->Id)
    {
        return rightRotate_members(nptr);
    }
    if (balance < -1 && r->Id > (nptr->right)->Id)
    {
        return leftRotate_members(nptr);
    }
    if (balance > 1 && r->Id > (nptr->left)->Id)
    {
        nptr->left = leftRotate_members(nptr->left);
        return rightRotate_members(nptr);
    }
    if (balance < -1 && r->Id < (nptr->right)->Id)
    {
        nptr->right = rightRotate_members(nptr->right);
        return leftRotate_members(nptr);
    }
    return nptr;
}
struct trainers* insert_trainer( struct trainers* nptr , struct trainers* r)
{
    if (nptr == NULL)
        return r;

    if (nptr->Id > r->Id)
    {
        nptr->left = insert_trainer(nptr->left, r);
    }
    else if(nptr->Id < r->Id)
    {
        nptr->right = insert_trainer(nptr->right, r);
    }
    nptr->height = height_trainers(nptr);

    int balance = getBalance_trainers(nptr);
    if (balance > 1 && r->Id < (nptr->left)->Id)
    {
        return rightRotate_trainers(nptr);
    }
    if (balance < -1 && r->Id > (nptr->right)->Id)
    {
        return leftRotate_trainers(nptr);
    }
    if (balance > 1 && r->Id > (nptr->left)->Id)
    {
        nptr->left = leftRotate_trainers(nptr->left);
        return rightRotate_trainers(nptr);
    }
    if (balance < -1 && r->Id < (nptr->right)->Id)
    {
        nptr->right = rightRotate_trainers(nptr->right);
        return leftRotate_trainers(nptr);
    }
    return nptr;
}
void Add_member(void)
{
    struct members* res = create_member();
    lptr1 = insert_member(lptr1 , res );
    printf("Member added successfully-------------------------------------------------------------- \n");
}
void Add_trainer(void)
{
    struct trainers* res = create_trainer();
    lptr2 = insert_trainer(lptr2 , res);
    printf("Trainer added successfully------------------------------------------------------------- \n");
}
void print_member(struct members *p)
{
    printf("Name                                    : %s \n", p->Name);
    printf("Id                                      : %d \n", p->Id);
    printf("Age                                     : %d \n", p->Age);
    printf("Gender                                  : %c \n", p->gender);
    printf("programs enrolled for                   : \n");
    if (p->yoga == T)
    {
        printf("yoga \n");
    }
    if (p->cardio == T)
    {
        printf("cardio \n");
    }
    if (p->zumba == T)
    {
        printf("zumba \n");
    }
    if (p->weight_lifting == T)
    {
        printf("weight lifting \n");
    }
    if (p->yoga == T)
    {
        printf("fees paid for yoga                      :   %d \n", p->F_yoga);
    }
    if (p->cardio == T)
    {
        printf("fees paid for cardio                    :   %d \n", p->F_cardio);
    }
    if (p->zumba == T)
    {
        printf("fees paid for zumba                     :   %d \n", p->F_zumba);
    }
    if (p->weight_lifting == T)
    {
        printf("fees paid for weight lifting            :   %d \n", p->F_weight_lifting);
    }
    
}
void ascending_odr_members(struct members *n)
{
    if(n != NULL)
    {
        ascending_odr_members(n->left); 
        print_member(n);
        ascending_odr_members(n->right);
    }
}
void Print_member_list(void)
{
    printf("Member list \n");
    ascending_odr_members(lptr1);
    printf("--------------------------------------------------------------------------------------- \n");
}
void print_trainer(struct trainers *t)
{

    printf("Name                                    :%s \n", t->T_name);
    printf("Id                                      :%d \n", t->Id);
    printf("Trainer can teach                       :\n");
    if (t->p_yoga == T)
    {
        printf("yoga\n");
    }
    if (t->p_cardio == T)
    {
        printf("cardio\n");
    }
    if (t->p_zumba == T)
    {
        printf("zumba\n");
    }
    if (t->p_weight_lifting == T)
    {
        printf("weight lifting\n");
    }
    if (t->p_yoga == T)
    {
        printf("remuneration for yoga                   : %d \n", t->R_yoga);
    }
    if (t->p_cardio == T)
    {
        printf("remuneration for cardio                 : %d \n", t->R_cardio);
    }
    if (t->p_zumba == T)
    {
        printf("remuneration for zumba                  : %d \n", t->R_zumba);
    }
    if (t->p_weight_lifting == T)
    {
        printf("remuneration for weight lifting         : %d \n", t->R_weight_lifting);
    }
}
void ascending_odr_trainers(struct trainers *n)
{
    if(n != NULL)
    {
        ascending_odr_trainers(n->left); 
        print_trainer(n);
        ascending_odr_trainers(n->right);
    }
}
void Print_trainer_list(void)
{
    printf("Trainer list \n");
    ascending_odr_trainers(lptr2);
    printf("--------------------------------------------------------------------------------------- \n");
}
struct members *minValueNode_member(struct members *n)
{
    struct members *pr = n;

    while (pr->left != NULL)
        pr = pr->left;

    return pr;
}
int del_status = 0;
struct members* del_mem(struct members* root, int key)
{
    if (root == NULL)
        return root;
 
    if ( key < root->Id )
        root->left = del_mem(root->left, key);
 
    else if( key > root->Id )
        root->right = del_mem(root->right, key);
 
    else
    {
        del_status = 1;
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct members *temp = root->left ? root->left : root->right;                                     
 
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct members* temp = minValueNode_member(root->right);
            
            root->Id = temp->Id;
            strcpy(root->Name, temp->Name);
            root->Age = temp->Age;
            root->gender = temp->gender;
            root->yoga = temp->yoga;
            root->cardio = temp->cardio;
            root->zumba = temp->zumba;
            root->weight_lifting = temp->weight_lifting;
            root->F_yoga = temp->F_yoga;
            root->F_cardio = temp->F_cardio;
            root->F_zumba = temp->F_zumba;
            root->F_weight_lifting = temp->F_weight_lifting;
 
            root->right = del_mem(root->right, temp->Id);
        }
    }
 
    if (root == NULL)
      return root;
 
    root->height = 1 + max(height_members(root->left),height_members(root->right));
 
    int balance = getBalance_members(root);
 
    if (balance > 1 && getBalance_members(root->left) >= 0)
        return rightRotate_members(root);
 
    if (balance > 1 && getBalance_members(root->left) < 0)
    {
        root->left =  leftRotate_members(root->left);
        return rightRotate_members(root);
    }
 
    if (balance < -1 && getBalance_members(root->right) <= 0)
        return leftRotate_members(root);
 
    if (balance < -1 && getBalance_members(root->right) > 0)
    {
        root->right = rightRotate_members(root->right);
        return leftRotate_members(root);
    }
 
    return root;
}
void Delete_member(void)
{
    printf("Enter the Id of the member that has to be deleted \n");
    int ID;
    scanf("%d", &ID);
    lptr1 = del_mem(lptr1 , ID);
    if(del_status == 1)
    {
        printf("Member has been deleted --------------------------------------------------------------- \n");
        del_status = 0;
    }
    else 
    {
        printf("No member with that Id --------------------------------------------------------------- \n");
    }
    
}
struct trainers *minValueNode_trainer(struct trainers *n)
{
    struct trainers *pr = n;

    while (pr->left != NULL)
        pr = pr->left;

    return pr;
}
int del_status2 = 0;
struct trainers* del_tra(struct trainers* root, int key)
{
    if (root == NULL)
        return root;
 
    if ( key < root->Id )
        root->left = del_tra(root->left, key);
 
    else if( key > root->Id )
        root->right = del_tra(root->right, key);
 
    else
    {
        del_status2 = 1;
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct trainers *temp = root->left ? root->left : root->right;                                     
 
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct trainers* temp = minValueNode_trainer(root->right);
            
            root->Id = temp->Id;
            strcpy(root->T_name, temp->T_name);
            root->p_yoga = temp->p_yoga;
            root->p_cardio = temp->p_cardio;
            root->p_zumba = temp->p_zumba;
            root->p_weight_lifting = temp->p_weight_lifting;
            root->R_yoga = temp->R_yoga;
            root->R_cardio = temp->R_cardio;
            root->R_zumba = temp->R_zumba;
            root->R_weight_lifting = temp->R_weight_lifting;
 
            root->right = del_tra(root->right, temp->Id);
        }
    }
 
    if (root == NULL)
      return root;
 
    root->height = 1 + max(height_trainers(root->left),height_trainers(root->right));/////////////////////////you can change the statment
 
    int balance = getBalance_trainers(root);
 
    if (balance > 1 && getBalance_trainers(root->left) >= 0)
        return rightRotate_trainers(root);
 
    if (balance > 1 && getBalance_trainers(root->left) < 0)
    {
        root->left =  leftRotate_trainers(root->left);
        return rightRotate_trainers(root);
    }
 
    if (balance < -1 && getBalance_trainers(root->right) <= 0)
        return leftRotate_trainers(root);
 
    if (balance < -1 && getBalance_trainers(root->right) > 0)
    {
        root->right = rightRotate_trainers(root->right);
        return leftRotate_trainers(root);
    }
 
    return root;
}
void Delete_trainer(void)
{
    printf("Enter the Id of the trainer that has to be deleted \n");
    int ID;
    scanf("%d", &ID);
    lptr2 = del_tra(lptr2 , ID);
    if(del_status2 == 1)
    {
        printf("trainer has been deleted -------------------------------------------------------------- \n");
        del_status2 = 0;
    }
    else
    {
        printf("No trainer found with that Id ---------------------------------------------------------- \n");
    }
    
}
struct members* search_mem_Id(struct members* root , int key)
{
    if(root == NULL || root->Id == key)
        return root;

    if(root->Id < key)
        return search_mem_Id(root->right , key);   

    return search_mem_Id(root->left , key);     
}
struct members* search_mem_name(struct members* root , char a[])                                 //preorder search
{
    if(root == NULL || strcmp(root->Name , a ) == 0)
        return root;

    if(search_mem_name(root->left , a ) != NULL)
        return search_mem_name(root->left , a );

    if(search_mem_name(root->right, a )!= NULL) 
        return search_mem_name(root->right , a );

    struct members* k = NULL;
    return k;            
}
void Search_member(void)
{
    printf("Enter the member key field to search ==> Id/Name : \n");
    char field[50];
    char nm[max_name];
    int id_no;
    scanf(" %[^\n]%*c",field);
    struct members* temp;
    if(strcmp(field, "Id") == 0)
    {
        printf("Enter the member field data to search  : \n");
        scanf("%d",&id_no);
        temp = search_mem_Id(lptr1 , id_no);
        if(temp == NULL)
        {
            printf("no members exist------------------------------------------------\n");
        }
        else{
            print_member(temp);
            printf("--------------------------------------------------------------- \n");
        }
        
    }
    else
    {
        printf("Enter the member field data to search  : \n");
        scanf(" %[^\n]%*c",nm);
        if(search_mem_name(lptr1 , nm) == NULL)
        {
            printf("noo member exist----------------------------------------------\n");
        }
        else
        {
            temp = search_mem_name(lptr1 , nm);
            print_member(temp);
            printf("--------------------------------------------------------------- \n");
        }

        
    }
}
struct trainers* search_tra_Id(struct trainers* root , int key)
{
    if(root == NULL || root->Id == key)
        return root;

    if(root->Id < key)
        return search_tra_Id(root->right , key);   

    return search_tra_Id(root->left , key);     
}
struct trainers* search_tra_name(struct trainers* root , char a[])                                 //preorder search
{
    if(root == NULL || strcmp(root->T_name , a ) == 0)
        return root;

    if(search_tra_name(root->left , a ) != NULL)
        return search_tra_name(root->left , a );

    if(search_tra_name(root->right, a )!= NULL) 
        return search_tra_name(root->right , a );

    struct trainers* k = NULL;
    return k;            
}
void Search_trainer(void)
{
    printf("Enter the trainer key field to search ==> Id/Name : \n");
    char field[50];
    char nm[max_name];
    int id_no;
    scanf(" %[^\n]%*c",field);
    struct trainers* temp;
    if(strcmp(field, "Id") == 0)
    {
        printf("Enter the trainer field data to search  : \n");
        scanf("%d",&id_no);
        temp = search_tra_Id(lptr2 , id_no);
        if(temp == NULL)
        {
            printf("no trainer exist-------------------------------------------------\n");
        }
        else
        {
            print_trainer(temp);
            printf("--------------------------------------------------------------- \n");
        }
        
    }
    else
    {
        printf("Enter the trainer field data to search  : \n");
        scanf(" %[^\n]%*c",nm);
        temp = search_tra_name(lptr2 , nm);
        if(temp == NULL)
        {
            printf("no trainer exist-------------------------------------------------\n");
        }
        else
        {
            print_trainer(temp);
            printf("--------------------------------------------------------------- \n");
        }
    }
}
void R_search(struct members* nptr , int s , int e)
{
    if(nptr->Id <= e && nptr->Id >= s)
    {
        printf("Id : %d  ", nptr->Id);
        printf(" Name : %s \n", nptr->Name);
        if(nptr->left != NULL)
        {
            R_search(nptr->left,s,e);
        }
        if(nptr->right!=NULL)
        {
            R_search(nptr->right,s,e);
        }
        
    }
    else if(nptr->Id < s)
    {
        if(nptr->right != NULL)
        {
            R_search(nptr->right,s,e);
        }
    }
    else if(nptr->Id > e)
    {
        if(nptr->left!= NULL)
        {
            R_search(nptr->left,s,e);
        }
    }
}
void Range_Search(void)
{
    int start , end ;
    printf("enter the starting member Id to search : \n");
    scanf("%d",&start);
    printf("enter the ending member Id to search : \n");
    scanf("%d",&end);
    R_search(lptr1 , start , end);

}
struct avail_trainers* create_avail_trainer( struct trainers* n)
{
    struct avail_trainers* node = (struct avail_trainers*)malloc(sizeof(struct avail_trainers));
    node->Id = n->Id;
    strcpy(node->Name,n->T_name);
    node->yoga = n->p_yoga;
    node->cardio = n->p_cardio;
    node->zumba = n->p_zumba;
    node->weight_lifting = n->p_weight_lifting;
    node->y_rem = n->R_yoga;
    node->c_rem = n->R_cardio;
    node->z_rem = n->R_zumba;
    node->w_rem = n->R_weight_lifting;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct avail_trainers *insert_avail_trainer(struct avail_trainers *nptr, struct avail_trainers *r)
{
    if (nptr == NULL)
        return r;

    if (nptr->Id > r->Id)
    {
        nptr->left = insert_avail_trainer(nptr->left, r);
    }
    else if(nptr->Id < r->Id)
    {
        nptr->right = insert_avail_trainer(nptr->right, r);
    }
    nptr->height = height_avail_trainers(nptr);

    int balance = getBalance_avail_trainers(nptr);
    if (balance > 1 && r->Id < (nptr->left)->Id)
    {
        return rightRotate_avail_trainers(nptr);
    }
    if (balance < -1 && r->Id > (nptr->right)->Id)
    {
        return leftRotate_avail_trainers(nptr);
    }
    if (balance > 1 && r->Id > (nptr->left)->Id)
    {
        nptr->left = leftRotate_avail_trainers(nptr->left);
        return rightRotate_avail_trainers(nptr);
    }
    if (balance < -1 && r->Id < (nptr->right)->Id)
    {
        nptr->right = rightRotate_avail_trainers(nptr->right);
        return leftRotate_avail_trainers(nptr);
    }
    return nptr;
}
void create_avail_trainer_list(void)
{
    int i , j , stop = 0 , Id;
    for(i = 0;stop == 0;i++)
    {
        printf("If you want to enter a trainer enter 1 or else 0 :\n");
        scanf("%d",&j);
        if(j == 1)
        {
            printf("Enter Id of the trainer \n ");
            scanf("%d",&Id);
            struct trainers* temp = search_tra_Id(lptr2 , Id);
            struct avail_trainers* res = create_avail_trainer(temp);
            head2 = insert_avail_trainer(head2 , res);
            printf("Added in availlist of trainers\n");
        }
        else
        {
            stop = 1;
            printf("available trainers list is created succeffully \n");
        }
    }
}
struct avail_members* create_avail_member( struct members* n)
{
    struct avail_members* node = (struct avail_members*) malloc(sizeof(struct avail_members));
    node->Id = n->Id;
    strcpy(node->Name,n->Name);
    node->yoga = n->yoga;
    node->cardio = n->cardio;
    node->zumba = n->zumba;
    node->weight_lifting = n->weight_lifting;
    printf("Enter preffered time : \n");
    scanf("%d",&node->time);
    printf("Enter preffered trainer's id : \n");
    scanf("%d",&node->T_Id);
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct avail_members *insert_avail_member(struct avail_members *nptr, struct avail_members *r)
{
    if (nptr == NULL)
        return r;

    if (nptr->Id > r->Id)
    {
        nptr->left = insert_avail_member(nptr->left, r);
    }
    else if(nptr->Id < r->Id)
    {
        nptr->right = insert_avail_member(nptr->right, r);
    }
    nptr->height = height_avail_members(nptr);

    int balance = getBalance_avail_members(nptr);
    if (balance > 1 && r->Id < (nptr->left)->Id)
    {
        return rightRotate_avail_members(nptr);
    }
    if (balance < -1 && r->Id > (nptr->right)->Id)
    {
        return leftRotate_avail_members(nptr);
    }
    if (balance > 1 && r->Id > (nptr->left)->Id)
    {
        nptr->left = leftRotate_avail_members(nptr->left);
        return rightRotate_avail_members(nptr);
    }
    if (balance < -1 && r->Id < (nptr->right)->Id)
    {
        nptr->right = rightRotate_avail_members(nptr->right);
        return leftRotate_avail_members(nptr);
    }
    return nptr;
}
void create_avail_members_list(void)
{
    int i , j , stop = 0 , Id;
    for(i = 0;stop == 0;i++)
    {
        printf("If you want to enter a member enter 1 or else 0 :\n");
        scanf("%d",&j);
        if(j == 1)
        {
            printf("Enter Id of the member \n ");
            scanf("%d",&Id);
            struct members* temp = search_mem_Id(lptr1 , Id);
            struct avail_members* res = create_avail_member(temp);
            head1 = insert_avail_member(head1 , res);
            printf("Added in availlist of members \n");
        }
        else
        {
            stop = 1;
            printf("available members list is created succeffully \n");
        }
    }

}
int count_y  = 0, count_c = 0 , count_z = 0, count_w = 0;
struct yoga_trainers* y_nptr;
struct cardio_trainers *c_nptr;
struct zumba_trainers *z_nptr;
struct weight_lifting_trainers *w_nptr;
struct yoga_trainers *y_tp;
struct cardio_trainers *c_tp;
struct zumba_trainers *z_tp;
struct weight_lifting_trainers *w_tp;
void divide_avail_trainers_list(struct avail_trainers *temp2)
{
    int i = 0;
    if (temp2 != NULL)
    {
        if (temp2->yoga == T)
        {
            count_y++;
            if (y_head == NULL)
            {
                y_head = (struct yoga_trainers *)malloc(sizeof(struct yoga_trainers));
                y_head->Id = temp2->Id;
                for (i = 0; i < 16; i++)
                {
                    y_head->status[i] = 1;
                }
                y_head->next = NULL;
                y_nptr = y_head;
            }
            else
            {
                y_tp = (struct yoga_trainers *)malloc(sizeof(struct yoga_trainers));
                y_tp->Id = temp2->Id;
                for (i = 0; i < 16; i++)
                {
                    y_tp->status[i] = 1;
                }
                y_tp->next = NULL;
                y_nptr->next = y_tp;
                y_nptr = y_nptr->next;
            }
        }
        if (temp2->cardio == T)
        {
            count_c++;
            if (c_head == NULL)
            {
                c_head = (struct cardio_trainers *)malloc(sizeof(struct cardio_trainers));
                c_head->Id = temp2->Id;
                for (i = 0; i < 16; i++)
                {
                    c_head->status[i] = 1;
                }
                c_head->next = NULL;
                c_nptr = c_head;
            }
            else
            {
                c_tp = (struct cardio_trainers *)malloc(sizeof(struct cardio_trainers));
                c_tp->Id = temp2->Id;
                for (i = 0; i < 16; i++)
                {
                    c_tp->status[i] = 1;
                }
                c_tp->next = NULL;
                c_nptr->next = c_tp;
                c_nptr = c_nptr->next;
            }
        }
        if (temp2->zumba == T)
        {
            count_z++;
            if (z_head == NULL)
            {
                z_head = (struct zumba_trainers *)malloc(sizeof(struct zumba_trainers));
                z_head->Id = temp2->Id;
                for (i = 0; i < 16; i++)
                {
                    z_head->status[i] = 1;
                }
                z_head->next = NULL;
                z_nptr = z_head;
            }
            else
            {
                z_tp = (struct zumba_trainers *)malloc(sizeof(struct zumba_trainers));
                z_tp->Id = temp2->Id;
                for (i = 0; i < 16; i++)
                {
                    z_tp->status[i] = 1;
                }
                z_tp->next = NULL;
                z_nptr->next = z_tp;
                z_nptr = z_nptr->next;
            }
        }
        if (temp2->weight_lifting == T)
        {
            count_w++;
            if (w_head == NULL)
            {
                w_head = (struct weight_lifting_trainers *)malloc(sizeof(struct weight_lifting_trainers));
                w_head->Id = temp2->Id;
                for (i = 0; i < 16; i++)
                {
                    w_head->status[i] = 1;
                }
                w_head->next = NULL;
                w_nptr = w_head;
            }
            else
            {
                w_tp = (struct weight_lifting_trainers *)malloc(sizeof(struct weight_lifting_trainers));
                w_tp->Id = temp2->Id;
                for (i = 0; i < 16; i++)
                {
                    w_tp->status[i] = 1;
                }
                w_tp->next = NULL;
                w_nptr->next = w_tp;
                w_nptr = w_nptr->next;
            }
        }
        divide_avail_trainers_list(temp2->left);
        divide_avail_trainers_list(temp2->right);
    }
}
void print_avail_trainers_list( struct avail_trainers* node)
{
    if(node != NULL)
    {
        printf("Id No : %d      Name : %s \n", node->Id , node->Name);
        print_avail_trainers_list(node->left);
        print_avail_trainers_list(node->right);
    }
}
void print_avail_members_list( struct avail_members* node)
{
    if(node != NULL)
    {
        printf("Id No : %d      Name : %s      Time : %d    preffered TrainerId : %d \n", node->Id , node->Name , node->time , node->T_Id);
        print_avail_members_list(node->left);
        print_avail_members_list(node->right);
    }
}
int Time = 0;
int D_T_id = 0;
int fix_slot(struct avail_members* pointer)
{
    int i, status = 0 ,ans = 0;
    struct yoga_trainers* t1 = A1[0].y_ptr;
    struct cardio_trainers* t2 = A1[0].c_ptr;
    struct zumba_trainers* t3 = A1[0].z_ptr;
    struct weight_lifting_trainers* t4 = A1[0].w_ptr;
    for(i = pointer->time - 6; i < 16 && status == 0;i++)
    {
        if(pointer->yoga == T && A1[i].slot_avail > 0 && A1[i].yoga_trainers_available > 0 && status == 0)
        {
            t1 = A1[0].y_ptr;
            while(t1 != NULL && status == 0)
            {
                if(t1->Id == pointer->T_Id && t1->status[i] == 1)
                {
                    t1->status[i] = 0;
                    A1[i].s.mem_ids[10 - A1[i].slot_avail] = pointer->Id;
                    A1[i].s.trai_ids[10 - A1[i].slot_avail] = t1->Id;
                    D_T_id = t1->Id;
                    A1[i].slot_avail =  A1[i].slot_avail - 1;
                    A1[i].yoga_trainers_available = A1[i].yoga_trainers_available - 1;
                    status = 1;
                    ans = 1; 
                    Time = i + 6;
                }
                t1 = t1->next;
            }
        }
        if(pointer->cardio == T && A1[i].slot_avail > 0 && A1[i].cardio_trainers_available > 0 && status == 0)
        {
            t2 = A1[0].c_ptr;
            while(t2 != NULL && status == 0)
            {
                if(t2->Id == pointer->T_Id && t2->status[i] == 1)
                {
                    t2->status[i] = 0;
                    A1[i].s.mem_ids[10 - A1[i].slot_avail] = pointer->Id;
                    A1[i].s.trai_ids[10 - A1[i].slot_avail] = t2->Id;
                    D_T_id = t2->Id;
                    A1[i].slot_avail =  A1[i].slot_avail - 1;
                    A1[i].cardio_trainers_available = A1[i].cardio_trainers_available - 1;
                    status = 1;
                    ans = 2;
                    Time = i + 6;
                }
                t2 = t2->next;
            }
        }
        if(pointer->zumba == T && A1[i].slot_avail > 0 && A1[i].zumba_trainers_available > 0 && status == 0)
        {
            t3 = A1[0].z_ptr;
            while(t3 != NULL && status == 0)
            {
                if(t3->Id == pointer->T_Id && t3->status[i] == 1)
                {
                    t3->status[i] = 0;
                    A1[i].s.mem_ids[10 - A1[i].slot_avail] = pointer->Id;
                    A1[i].s.trai_ids[10 - A1[i].slot_avail] = t3->Id;
                    D_T_id = t3->Id;
                    A1[i].slot_avail =  A1[i].slot_avail - 1;
                    A1[i].zumba_trainers_available = A1[i].zumba_trainers_available - 1;
                    status = 1;
                    ans = 3;
                    Time = i + 6;
                }
                t3 = t3->next;
            }
        }
        if(pointer->weight_lifting == T && A1[i].slot_avail > 0 && A1[i].weight_lifting_trainers_available > 0 && status == 0)
        {
            t4 = A1[0].w_ptr;
            while(t4 != NULL && status == 0)
            {
                if(t4->Id == pointer->T_Id && t4->status[i] == 1)
                {
                    t4->status[i] = 0;
                    A1[i].s.mem_ids[10 - A1[i].slot_avail] = pointer->Id;
                    A1[i].s.trai_ids[10 - A1[i].slot_avail] = t4->Id;
                    D_T_id = t4->Id;
                    A1[i].slot_avail =  A1[i].slot_avail - 1;
                    A1[i].weight_lifting_trainers_available = A1[i].weight_lifting_trainers_available - 1;
                    status = 1;
                    ans = 4;
                    Time = i + 6;
                }
                t4 = t4->next;
            }
        }
    }
    if(status == 1)
    {
        return ans;
    }
    else
    {
        return 0;
    }
}
struct fixed_list *insert_fixed(struct fixed_list *nptr, struct fixed_list *r)
{
    if (nptr == NULL)
        return r;

    if (nptr->m_Id > r->m_Id)
    {
        nptr->left = insert_fixed(nptr->left, r);
    }
    else if(nptr->m_Id < r->m_Id)
    {
        nptr->right = insert_fixed(nptr->right, r);
    }
    nptr->height = height_fixed(nptr);

    int balance = getBalance_fixed(nptr);
    if (balance > 1 && r->m_Id < (nptr->left)->m_Id)
    {
        return rightRotate_fixed(nptr);
    }
    if (balance < -1 && r->m_Id > (nptr->right)->m_Id)
    {
        return leftRotate_fixed(nptr);
    }
    if (balance > 1 && r->m_Id > (nptr->left)->m_Id)
    {
        nptr->left = leftRotate_fixed(nptr->left);
        return rightRotate_fixed(nptr);
    }
    if (balance < -1 && r->m_Id < (nptr->right)->m_Id)
    {
        nptr->right = rightRotate_fixed(nptr->right);
        return leftRotate_fixed(nptr);
    }
    return nptr;
}

struct non_fixed_list *insert_non_fixed(struct non_fixed_list *nptr, struct non_fixed_list *r)
{
    if (nptr == NULL)
        return r;

    if (nptr->Id > r->Id)
    {
        nptr->left = insert_non_fixed(nptr->left, r);
    }
    else if(nptr->Id < r->Id)
    {
        nptr->right = insert_non_fixed(nptr->right, r);
    }
    nptr->height = height_non_fixed(nptr);

    int balance = getBalance_non_fixed(nptr);
    if (balance > 1 && r->Id < (nptr->left)->Id)
    {
        return rightRotate_non_fixed(nptr);
    }
    if (balance < -1 && r->Id > (nptr->right)->Id)
    {
        return leftRotate_non_fixed(nptr);
    }
    if (balance > 1 && r->Id > (nptr->left)->Id)
    {
        nptr->left = leftRotate_non_fixed(nptr->left);
        return rightRotate_non_fixed(nptr);
    }
    if (balance < -1 && r->Id < (nptr->right)->Id)
    {
        nptr->right = rightRotate_non_fixed(nptr->right);
        return leftRotate_non_fixed(nptr);
    }
    return nptr;
}
void traversal_avail_members( struct avail_members* node)
{
    if(node != NULL)
    {
        int res = fix_slot(node);
        if(res != 0)
        {
            struct fixed_list* pointer1 = (struct fixed_list*)malloc(sizeof(struct fixed_list));
            pointer1->time = Time;
            pointer1->m_Id = node->Id;
            pointer1->t_Id = node->T_Id;
            pointer1->pgm = res;
            pointer1->height = 0;
            pointer1->left = NULL;
            pointer1->right = NULL;
            first = insert_fixed(first , pointer1);
        }
        else
        {
            struct non_fixed_list* pointer2 = (struct non_fixed_list*)malloc(sizeof(struct non_fixed_list));
            pointer2->Id = node->Id;
            pointer2->height = 0;
            pointer2->left = NULL;
            pointer2->right = NULL;
            non_first = insert_non_fixed(non_first , pointer2);
        }
        traversal_avail_members(node->left);
        traversal_avail_members(node->right);
    }
}
void print_fixed_list(struct fixed_list* ptr)
{
    if(ptr != NULL)
    {
        printf("%d 'O' clock ==> Idmember %d ==> Idtrainer %d ==> program :",ptr->time , ptr->m_Id , ptr->t_Id);
        if(ptr->pgm == 1)
        {
            printf("yoga \n");
        }
        else if(ptr->pgm == 2)
        {
            printf("cardio \n");
        }
        else if(ptr->pgm == 3)
        {
            printf("zumba \n");
        }
        else if(ptr->pgm == 4)
        {
            printf("weight lifting \n");
        }
        print_fixed_list(ptr->left);
        print_fixed_list(ptr->right);
    }
}
void print_non_fixed_list(struct non_fixed_list* node)
{
    if(node !=NULL)
    {
        printf("Id = %d \n",node->Id);
        print_non_fixed_list(node->left);
        print_non_fixed_list(node->right);
    }
}
void Schedule_slot(void)
{
    printf("This is function for scheduling slots, So enter the data of available trainers \n");
    create_avail_trainer_list();
    printf("These are the availble trainers list : \n");
    print_avail_trainers_list(head2);
    printf("---------------------------------------------------------------------------------------\n");
    create_avail_members_list();
    printf("These are the members requiests list : \n");
    print_avail_members_list(head1);
    printf("---------------------------------------------------------------------------------------\n");
    divide_avail_trainers_list(head2);
    int i;
    for (i = 0; i < 16; i++)
    {
        A1[i].T = i + 6;
        A1[i].slot_avail = 10;
        A1[i].yoga_trainers_available = count_y;
        A1[i].cardio_trainers_available = count_c;
        A1[i].zumba_trainers_available = count_z;
        A1[i].weight_lifting_trainers_available = count_w;
        A1[i].y_ptr = y_head;
        A1[i].c_ptr = c_head;
        A1[i].z_ptr = z_head;
        A1[i].w_ptr = w_head;
        int j = 0;
        for (j = 0; j < 10; j++)
        {
            A1[i].s.mem_ids[j] = 0;
            A1[i].s.trai_ids[j] = 0;
        }
    }
    traversal_avail_members( head1);
    printf("The schedule is : \n");
    print_fixed_list(first);
    printf("---------------------------------------------------------------------------------------\n");
    printf("The non scheduled members are : \n");
    print_non_fixed_list(non_first);
    printf("---------------------------------------------------------------------------------------\n");

}
void print_hour_fixed_list(struct fixed_list* node , int i)
{
    if(node != NULL)
    {
        if(node->time == i)
        {
            printf("Member Id %d        Trainer Id %d       program :",node->m_Id , node->t_Id);
            if(node->pgm == 1)
            {
                printf("yoga \n");
            }
            else if(node->pgm == 2)
            {
                printf("cardio \n");
            }
            else if(node->pgm == 3)
            {
                printf("zumba \n");
            }
            else
            {
                printf("weight lifting \n");
            }
        }
        print_hour_fixed_list(node->left , i);
        print_hour_fixed_list(node->right , i);
    }
}
void Print_hour_wise_list(void)
{
    int i ;
    for ( i = 6; i < 21; i++)
    {
        printf("%d 'O' clock schedule : \n",i);
        print_hour_fixed_list(first , i);
        printf("---------------------------------------------------------------------------------------\n");
    }
}


struct Trainer_sort* insert_Trainer_sort(struct Trainer_sort* nptr , struct Trainer_sort* r)
{
    if (nptr == NULL)
        return r;

    if (nptr->T_Remunaration > r->T_Remunaration)
    {
        nptr->left = insert_Trainer_sort(nptr->left, r);
    }
    else if(nptr->T_Remunaration < r->T_Remunaration)
    {
        nptr->right = insert_Trainer_sort(nptr->right, r);
    }
    nptr->height = height_Trainer_sort(nptr);

    int balance = getBalance_Trainer_sort(nptr);
    if (balance > 1 && r->T_Remunaration < (nptr->left)->Id)
    {
        return rightRotate_Trainer_sort(nptr);
    }
    if (balance < -1 && r->T_Remunaration > (nptr->right)->Id)
    {
        return leftRotate_Trainer_sort(nptr);
    }
    if (balance > 1 && r->T_Remunaration > (nptr->left)->Id)
    {
        nptr->left = leftRotate_Trainer_sort(nptr->left);
        return rightRotate_Trainer_sort(nptr);
    }
    if (balance < -1 && r->T_Remunaration < (nptr->right)->Id)
    {
        nptr->right = rightRotate_Trainer_sort(nptr->right);
        return leftRotate_Trainer_sort(nptr);
    }
    return nptr;
}
int count_status(int Arr[])   
{
    int i , res = 0;
    for ( i = 0; i < 16; i++)
    {
        if(Arr[i] == 0)
        {
            res++;
        }
    }
    return res;
}
struct yoga_trainers *re1;
struct cardio_trainers *re2;
struct zumba_trainers *re3;
struct weight_lifting_trainers *re4 ;
void trav_avail_trainers(struct avail_trainers* node)
{
    if(node != NULL)
    {
        struct Trainer_sort* point = (struct Trainer_sort*)malloc(sizeof(struct Trainer_sort));
        point->Id = node->Id;
        strcpy(point->Name , node->Name);
        point->y_rem = node->y_rem;
        point->c_rem = node->c_rem;
        point->z_rem = node->z_rem;
        point->w_rem = node->w_rem;
        point->T_Remunaration = 0;
        point->height = 0;
        point->left = NULL;
        point->right = NULL;
        re1 = y_head;
        re2 = c_head;
        re3 = z_head;
        re4 = w_head;
        while(re1 != NULL && node->yoga == T)  
        {
            if(re1->Id == point->Id)
            {
                int count = count_status(re1->status);
                point->T_Remunaration = point->T_Remunaration + (count*point->y_rem);
                break;
            }
            re1 = re1->next;
        }
        while(re2 != NULL && node->cardio == T)
        {
            if(point->Id == re2->Id)
            {
                int count = count_status(re2->status);
                point->T_Remunaration = point->T_Remunaration + (count*point->c_rem);
                break;
            }
            re2 = re2->next;
        }
        while(re3 != NULL && node->zumba == T)
        {
            if(point->Id == re3->Id)
            {
                int count = count_status(re3->status);
                point->T_Remunaration = point->T_Remunaration + (count*point->z_rem);
                break;
            }
            re3 = re3->next;
        }
        while(re4 != NULL && node->weight_lifting == T)
        {
            if(point->Id == re4->Id)
            {
                int count = count_status(re4->status);
                point->T_Remunaration = point->T_Remunaration + (count*point->w_rem);
                break;
            }
            re4 = re4->next;
        }
        T_ahead = insert_Trainer_sort(T_ahead , point);
        trav_avail_trainers(node->left);
        trav_avail_trainers(node->right);
    }
}
void print_Trainer_sort( struct Trainer_sort* root )
{
    if(root != NULL)
    {
        print_Trainer_sort(root->right);
        printf("%s will earn    %d \n" , root->Name , root->T_Remunaration );
        print_Trainer_sort(root->left);
    }
}
void Print_sorted_remuneration_list(void)
{
    struct avail_trainers* ptr1 = head2;
    trav_avail_trainers(ptr1);
    printf("hightest to lowest -------->\n");
    print_Trainer_sort(T_ahead);
}
int main()
{
    int choice_of_funtion;
    int flag = 0;
    printf("Enter 0 ==>         End \n");
    printf("Enter 1 ==>         Adding Members \n");
    printf("Enter 2 ==>         Display Members list \n");
    printf("Enter 3 ==>         Adding Trainers \n");
    printf("Enter 4 ==>         Display Trainers list \n");
    printf("Enter 5 ==>         Deletion of Members \n");
    printf("Enter 6 ==>         Deletion of Trainers \n");
    printf("Enter 7 ==>         Search of Members \n");
    printf("Enter 8 ==>         Search of Trainers \n");
    printf("Enter 9 ==>         Members in a given Range \n");
    printf("Enter 10 ==>        Schedule slots for members \n");
    printf("Enter 11 ==>        Hour wise schedule \n");
    printf("Enter 12 ==>        Sorted Remunaration list of Trainers \n");
    while (flag == 0)
    {
        printf("Enter the choice of funtion : ");
        scanf("%d",&choice_of_funtion);
        printf("\n");
        switch (choice_of_funtion)
        {
        case 0:
            printf("----------------End--------------------\n");   
            flag = 1; 
            break;
        case 1:
            printf("Adding Members to the list \n");
            Add_member();
            break;
        case 2:
            printf("Displaying the Member's list \n");
            Print_member_list();
            break;
        case 3:
            printf("Adding Trainers to the list \n");
            Add_trainer();
            break;
        case 4:
            printf("Displaying the Trainer's list \n");
            Print_trainer_list();
            break;
        case 5:
            printf("Deletion of Member from the list \n");
            Delete_member();
            break;   
        case 6:
            printf("Deletion of Trainer from the list \n");
            Delete_trainer();
            break; 
        case 7:
            printf("Search of Member from the list \n");
            Search_member();
            break; 
        case 8:
            printf("Search of Trainer from the list \n");
            Search_trainer();
            break; 
        case 9:
            printf("Range of Members from the Member's list \n");
            Range_Search();
            break; 
        case 10:
            printf("scheduling the slot for Members \n");
            Schedule_slot();
            break; 
        case 11:
            printf("Display of hour wise schedule \n");
            Print_hour_wise_list();
            break;        
        case 12:
            printf("Display sorted Remunaration list of Trainers \n");
            Print_sorted_remuneration_list();
            break;        
        default:
            printf("----------------End--------------------\n");   
            flag = 1; 
            break;
        }
    }

    return 0;
}