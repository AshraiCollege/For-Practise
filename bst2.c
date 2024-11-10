#include<stdio.h>
#include<stdlib.h>

struct node1
{
    int data;
    struct node1 *left,*right;
    
};

struct node1* createNode(int data)
{
    struct  node1* newNode = malloc(sizeof(struct node1));
    newNode->data= data;
    newNode->left= NULL;
    newNode->right= NULL;
    return newNode;
    
};


struct node1* insert(struct  node1* root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    else if(data<root->data)  
    {
        root->left = insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right = insert(root->right,data);
    }
    return root;
};
void inorder(struct node1* root)
{   
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
    

}



int main()
{
    struct  node1* root;

    int a[10]={30,20,22,45,55,26,87,54,37,43};

    for(int i=0;i<10;i++)
    {
        root = insert(root,a[i]);
    }

    printf("In-order traversing: ");
    inorder(root);
    
    return 0;
}