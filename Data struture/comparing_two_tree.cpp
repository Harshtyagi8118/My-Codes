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
bool is_identical(binary_tree *x,binary_tree *y)
{
    if(x ==NULL && y == NULL)
        return true;
    else
        return ( x && y) && (x->val==y->val)&& is_identical(x->left,y->left) && is_identical(x->right,y->right);
}
int main()
{
    binary_tree *t=create_node(10);
    binary_tree *root  = create_node(10);
    t->left=root->left=create_node(11);
    t->right=root->right=create_node(9);
    t->left->left=root->left->left=create_node(7);
    t->right->left=root->right->left=create_node(15);
    t->right->right= root->right->right=create_node(8);
    //int key = 12;
    cout<<"Inorder traversal of first tree : ";
    inorder(root);
    //cout<<"\nAfter insertion : ";
   // root = insert_node(root,key);
    cout<<"\nInorder traversal of second tree :";
    inorder(t);
    if(is_identical(root,t))
        cout<<"\nBoth trees are same\n";
    else
        cout<<"\nTrees are not same\n";
}