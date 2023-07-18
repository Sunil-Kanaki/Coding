#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *getnode(struct node *root,int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(newnode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node *ins(struct node *root,int data)
{
    if(root==NULL)
    {
        root = getnode(root,data);
        return root;
    }
    else if(data <= root->data)
    {
        root->left = ins(root->left,data);
        return root;
    }
    else if(data > root->data)
    {
        root->right = ins(root->right,data);
        return root;
    }
}
int search(struct node *root,int data)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(data == root->data)
    {
        return 1;
    }
    else if(data < root->data)
    {
        return search(root->left,data);
    }
    else return search(root->right,data);
}
int min(struct node *root)
{
    struct node *current = root;
    while(current->left!=NULL)
    {
        return min(current->left);
    }
    return  current->data;
}
int max(struct node *root)
{
    struct node *current = root;
    while(current->right!=NULL)
    {
        return max(current->right);
    }
    return  current->data;
}
struct node *delete(struct node *root,int data)
{
    if(root==NULL)
    {
        return data;
    }
    else if(data < root->data)
    {
        return delete(root->left,data);
    }
    else if(data > root->data)
    {
        return delete(root->right,data);
    }
    else 
    
    {
        root->data = NULL;
        printf("delted\n");
    }
    else{
        printf("data not found\n");
    }
}
int main()
{
    int c,a,e,m,n,del;
    struct node *root = NULL;
    while(1)
    {
        printf("1--Insert\n 2--Search\n 3--max\n  4--min\n  5--delete\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : printf("Enter data\n");
                        scanf("%d",&a);
                        root = ins(root,a);
                        break;
            case 2 : printf("Enter the number to be searched\n");
                        scanf("%d",&e);
                        if(search(root,e)==1)
                        {
                            printf("Found\n");
                        }
                        else{
                            printf("Not Found\n");
                        }
                        break;
            case 3 : m = max(root);
                    printf("maximum = %d\n",m);
                    break;
            case 4 : n = min(root);
                     printf("minimum = %d\n",n);
                    break;
            case 5 : printf("Enter the data to be deleted\n");
                    scanf("%d",&del);
                    delete(root,del);
                    break;
        }

    }

}
