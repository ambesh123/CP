#include<iostream>
#include<malloc.h>
using namespace std;

struct tree
{
	tree *left;
	tree *right;
	int data;
};

tree *insert(tree *root,int d)
{
	tree *p,*s;
	bool b=true;
	p=(tree *)malloc(sizeof(tree));
	p->left=NULL; p->right=NULL; p->data=d;
	if(root==NULL)return p;
	else
	{
		s=root;
		while(b)
		{
			if(d>s->data){
				if(s->right==NULL){
					s->right=p;
					b=false;
				}
				else s=s->right;
			}
			else {
				if(s->left==NULL){
					s->left=p;
					b=false;
				}
				else s=s->left;
			}
		}
		
		return root;
	}
}

void display(tree *root)
{
	if(root->left!=NULL)display(root->left);
	cout<<(root->data)<<" ";
	if(root->right!=NULL)display(root->right);
}

int main()
{
	tree *root=NULL;
	int i;
	for(int j=0;j<6;j++)
	{
	cin>>i; root=insert(root,i);	
	}
	display(root);	
}
