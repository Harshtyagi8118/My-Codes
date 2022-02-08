#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
struct node{
    int val;
    struct node *left,*right;
};
node* create_node(int key)
{
    node* temp = new node();
    temp->val=key;
    temp->left=temp->right=NULL;
    return temp;
}
node* insert_node(node* root,int key){
    if(root==NULL)return  create_node(key);
     if(key>root->val)root->right= insert_node(root->right,key);
     if(key<root->val)root->left= insert_node(root->left,key);
     return root;
}
int cnt=0;
void search_element(node *root,int data){
    if(root==NULL)return ;
    if(root->val==data){cout<<data<<" is present in the tree ";cnt++;}
    search_element(root->left,data);
    search_element(root->right,data);

}
node* min_val(node* root){
    node* current = root;
    while(current && current->left!=NULL){
        current = current->left;
    }
    return current;
}
node* delete_node(node* root,int data){
    if(root==NULL)return root;
    if(data>root->val) root->right = delete_node(root->right,data);
    else if(data <root->val) root->left = delete_node(root->left,data);
    else{
        if(root->left==NULL){
            node* temp = root->right;
            free(root);
            return temp;}
          else  if(root->right==NULL){
                node* temp = root->left;
                free(root);
                return temp;
            }
        
            node* temp = min_val(root->right);
            root->val = temp->val;
            root->right = delete_node(root->right,temp->val);
    
    }
    return root;
}
void inorder_traversal(node *root){
    if(root==NULL)return ;
    else{
        inorder_traversal(root->left);
        cout<<root->val<<" ";
        inorder_traversal(root->right);
    }
}
int main(){
    node * root=NULL;
   root= insert_node(root,20);
   root= insert_node(root,10);
   root= insert_node(root,5);
   root= insert_node(root,45);
   root= insert_node(root,25);
   root= insert_node(root,15);
   cout<<"Inorser treaversal of tree is :";
    inorder_traversal(root);
    cout<<endl<<"Enter the value that you have to search :";
    int k;
    cin>>k;
    search_element(root,k);
    if(cnt==0)cout<<k<<" is not present ";
    cout<<endl;
    int v;
    cout<<"Node to be deleted :";
    cin>>v;
    root= delete_node(root,v);
    cout<<"After deletion :";
    inorder_traversal(root);
}