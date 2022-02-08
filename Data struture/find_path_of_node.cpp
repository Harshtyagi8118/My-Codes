#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
struct node{
    int val;
    struct node *left,*right;
};
node* create_node(int key){
    node * temp = (node*)malloc(sizeof(node));
    temp->val = key;
    temp->left=temp->right=NULL;
    return temp;
}
bool find_path(node* root,vector<int> & v,int key){
    if(root==NULL)return false;
    v.push_back(root->val);
    if(root->val==key)return true;
    if(root->left&&find_path(root->left,v,key)||root->right&&find_path(root->right,v,key))return true;
    v.pop_back();
    return false;
}
void store(node* root,vector<int>&v){
    if(root==NULL)return ;
    if(find(v.begin(),v.end(),root->val)==v.end())v.push_back(root->val);
    if(root->left)store(root->left,v);
    if(root->right)store(root->right,v);
}
int main(){
    node* root = create_node(0);
    root->left = create_node(1);
    root->right = create_node(2);
    root->right->left = create_node(6);
    root->right->right = create_node(5);
    root->right->left->left = create_node(3);
    root->right->left->left->right = create_node(4);
    vector<int>v1,v2;
    if(find_path(root,v1,3)){
        for(int i=0;i<v1.size();i++)
            cout<<v1[i]<<" ";
    }
    cout<<endl;
    store(root,v2);
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;

}
