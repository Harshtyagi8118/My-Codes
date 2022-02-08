#include<stdio.h>
struct node{
	int data;
	struct node *link;
};
typedef node;
struct node *START = NULL;
node* create_node()
{
	node *n;
	n = node* malloc(sizeof(node));
	return n;
}
void insert_value()   // inserting at the end
{
	node *temp,*t;
	temp = create_node();
	temp->link = NULL;
	if(START==NULL)
		START = temp;
	else
	{
		t = START;
		while(t->link!=NULL)
			t=t->link;
	}
	t->link=temp;
}
void delete_node()   //deleting first node
{	node *r = START;
	if(START==NULL)
		printf("List is empty");
	else
	START = START->link;
	free(r);
}