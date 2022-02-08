#include<bits/stdc++.h>
using namespace std;
struct binary_tree{
    int val;
    struct binary_tree *left;
    struct binary_tree *right;
};
binary_tree* create_node(int data)
{
    binary_tree* temp;
    temp = new binary_tree();
    if(!temp){
        cout<<"Memory error\n";
        return NULL;
    }
    temp->val=data;
    temp->left=temp->right=NULL;
    return temp;
}
binary_tree* insert_node(binary_tree * root,int data)
{
    if(root==NULL)
    root = create_node(data);
    queue<binary_tree*> q;
    q.push(root);
    binary_tree *temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        else
        {
            temp->left=create_node(data);
            return root;
        }
        if(temp->right!=NULL)
            q.push(temp->right);
        else
        {
            temp->right=create_node(data);
            return root;
        }
    }    
}
void inorder(binary_tree *root)
{
    if(root==NULL)
        return ;
    else
    {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}
int main()
{
    binary_tree *root = create_node(10);
    root->left=create_node(11);
    root->right=create_node(9);
    root->left->left=create_node(7);
    root->right->left=create_node(15);
    root->right->right=create_node(8);
    int key = 12;
    cout<<"Before insertion : ";
    inorder(root);
    cout<<"\nAfter insertion : ";
    root = insert_node(root,key);
    inorder(root);
}