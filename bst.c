#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct  Node *left,*right;
    
    
};
struct  Node* createNode(int data)
{
    struct  Node* newNode = malloc(sizeof(struct Node));

    newNode->data= data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
       
};

struct Node* insert(struct  Node* root, int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    if(data<root->data)
    {
        root->left = insert(root->left,data);
    }
    if(data>root->data)
    {
        root->right = insert(root->right,data);
    }
    return root;
};

void inorder(struct  Node* root)
{
    if(root!=NULL)
    {
         inorder(root->left);
         printf("%d ",root->data);
         inorder(root->right);
    }
}
void postorder(struct Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }

}

void preorder(struct Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
       
    }

}

int main()
{
    int a[10] = { 20,10,5,24,35,50,6,9,34,70};
    struct Node *root = NULL;

    for(int i= 0;i<10;i++)
    {
        root = insert(root,a[i]);
    }
    
    printf("\nIn-order traversing : ");
    inorder(root);

    printf("\nPOst-order traversing : ");
    postorder(root);

    printf("\nPre-order traversing : ");
    preorder(root);
    

    //Best of luck, See you !
    return 0;
}