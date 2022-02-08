#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
struct node{
	char data;
	struct node *left,*right;
};
unordered_map<char,int>m;
node* create_node(char key){
	node* temp = new node();
	temp ->data = key;
	temp->left = temp->right = NULL;
	return temp;
}
// int search(vector<char> in,int start,int end,char val){
// 	for(int i=start;i<=end;i++)if(in[i]==val)return i;
// }
node * build_tree(vector<char> &in,vector<char> &pre,int start,int end){
	if(start>end)return NULL;
	static int preindex = 0;
	node * root = create_node(pre[preindex++]);
	if(start==end)return root;
	int inindex = m[root->data];//search(in,start,end,root->data);
	root->left = build_tree(in,pre,start,inindex -1);
	root->right = build_tree(in,pre,inindex+1,end);
	return root;
}
void inorder(node *root){
	if(root==NULL)return ;
	else
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void preorder(node *root){
	if(root==NULL)return ;
	else{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
int main(){
	std::vector<char> in{'D','B','E','A','F','C'},pre{'A','B','D','E','C','F'};
	node* root;
	int start =0;
	for(int i=0;i<in.size();i++)m[in[i]]=i;
	int end = in.size()-1;
	root = build_tree(in,pre,start,end);
	cout<<"Inorder traversal : ";
	inorder(root);
	cout<<"\nPreorder traversal : ";
	preorder(root);
	cout<<endl;

}