#include<bits/stdc++.h>
using namespace std;
struct binary_tree{
    int val;
    struct binary_tree *left;
    struct binary_tree *right;
};
binary_tree* create_node(int data){
    binary_tree *temp = (binary_tree*)malloc(sizeof(binary_tree()));
    temp->val=data;
    temp->left=temp->right=NULL;
    return temp;

}
binary_tree* insert_node(binary_tree* root,int data){
    binary_tree* temp;
    if(root==NULL){
        root = create_node(data);
    }
    queue<binary_tree*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
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
void inorder(binary_tree* root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}
void delete_deepest(binary_tree* root,binary_tree* d_node)
{
    queue<binary_tree*>q;
    binary_tree* temp;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp==d_node)
        {
            temp = NULL;
            delete(d_node);
        }
    if(temp->right){
            if(temp->right==d_node)
            {
                temp->right=NULL;
                delete(d_node);
            }
            else
                q.push(temp->right);
        }    
    if(temp->left){
        if(temp->left==d_node){
            temp->left==NULL;
            delete(d_node);
        }
        else
            q.push(temp->left);
    }}

}
binary_tree* deletenode(binary_tree* root,int key)
{
    if(!root)
        return NULL;
    
    if(root->left==NULL && root->right==NULL)
    {
            if(root->val==key)
                return NULL;
            else
                return root;
    }
    queue<binary_tree*>q;
    q.push(root);
    binary_tree* temp,*key_node=NULL;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->val==key)
            key_node=temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if(key_node!=NULL)
    {
        int x = temp->val;
        delete_deepest(root,temp);
        key_node->val = x;
    }
        return root;
}

int main(){
    binary_tree* root;
    /*root=create_node(10);
    root->left=create_node(11);
    root->right=create_node(9);
    root->left->left=create_node(7);
    root->right->left=create_node(15);
    root->right->right=create_node(8);
    int key = 12;
    cout<<"Inorder traversal of tree : ";
    inorder(root);
    root = insert_node(root,key);
    cout<<"\nInorder after insertion : ";
    inorder(root);*/
    root=create_node(10);
    root->left=create_node(11);
    root->left->left=create_node(7);
    root->left->right=create_node(12);
    root->right=create_node(9);
    root->right->left=create_node(15);
    root->right->right=create_node(8);
    cout<<"Inorder traversal before deletion: ";
    inorder(root);
    cout<<"\nDelete the k = 11 : ";
    int key = 11;
    root= deletenode(root,key);
    cout<<"\nInorder traversal after deletion : ";
    inorder(root);



}