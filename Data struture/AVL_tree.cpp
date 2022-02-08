#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
struct node{
    int val;
    node *left ,*right;
    int height;
};
node* newnode(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->val = data;
    temp->right=temp->left = NULL;
    temp->height=1;
    return temp;
}
int height(node* N)
{
    if(N == NULL)
        return 0;
    return N->height;
}
node* rightrotate(node* y){
    node *x = y->left;
    node* t2 = x->right;
    x->right = y;
    y->left=t2;
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1; 
    return x;
}
node* leftrotate(node* x)
{
    node* y = x->right;
    node* t2 = y->left;
    y->left = x;
    x->right =t2;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}
int getbalance(node* n)
{
    if(n==NULL)
        return 0;
    return height(n->left) - height(n->right);
}
node* insert_node(node* root,int key)
{
    if(root==NULL)
        return (newnode(key));
    if(key>root->val)
    
        root->right=insert_node(root->right,key);
    else if(key<root->val)
        root->left = insert_node(root->left,key);
    else
        root;
    root->height = 1+max(height(root->left),height(root->right));
    int balance = getbalance(root);
    if(balance>1 && key < root->left->val) // left left case
        return rightrotate(root);
    if(balance>1 && key>root->left->val)  // left right case
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance<-1 && key>root->right->val) // right right case
        return leftrotate(root);
    if(balance<-1 && key<root->right->val)
    {
        root->right=rightrotate(root->right); // right left case
        return leftrotate(root);
    }
    return root;
}
void  preorder (node* root)
{
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node* root = NULL;
    root = insert_node(root,10);
    root = insert_node(root,20);
    root = insert_node(root,30);
    root = insert_node(root,40);
    root = insert_node(root,50);
    root = insert_node(root,25);
    cout<<" Preorder traversal of the consrtructed AVL tree is : ";
    preorder(root);
    root = insert_node(root,26);
    root = insert_node(root,27);
    cout<<"\n After inserting 26 and 26 Preorder traversal is : ";
    preorder(root);
    cout<<"\n";
}

