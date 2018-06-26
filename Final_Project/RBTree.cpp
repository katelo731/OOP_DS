#include "RBTree.h"

RBTree::RBTree()
{
	root = NULL;
}

void RBTree::left_rotate(Node *x)
{
	Node *y;
	
	y = x->right;
	x->right = y->left;
	
	if(y->left) 
		y->left->parent = x;
		
	y->parent = x->parent;
	
	if(!x->parent) root = y;
	else if(x == x->parent->left) x->parent->left = y; 
	else x->parent->right = y;
	
	y->left = x;
	x->parent = y;
}

void RBTree::right_rotate(Node *x)
{
	Node *y;
	
	y = x->left;
	x->left = y->right;
	
	if(y->right)
		y->right->parent = x;
	
	y->parent = x->parent;
	
	if(!x->parent) root = y;
	else if(x == x->parent->right) x->parent->right = y; 
	else x->parent->left = y;
	
	y->right = x;
	x->parent = y;
}

bool RBTree::insert(int k,string g,int h,int w)
{
	Node *n, *p, *z, *u;
	p = NULL;
	n = root;
	bool colli = false;
	
	while(n)
	{
		p = n;
		if(k < n->key) n = n->left;
		else if(k > n->key) n = n->right;
		else return false;
	}
	
	if(!p)
	{
		z = root = new Node(k,g,h,w);
		z->color = BLACK;
		z->parent = z->left = z->right = NULL;
	}
	else
	{
		z = new Node(k,g,h,w);
		z->color = RED;
		z->parent = p;
		z->left = z->right = NULL;
		
		if(z->key < p->key) p->left = z;
		else p->right = z;
	}
	
	while(z->parent && z->parent->color==RED)
	{
		if(z->parent == z->parent->parent->left)
		{
			u = z->parent->parent->right;
			if(u && u->color == RED)
			{
				z->parent->color = BLACK;
				u->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if(z == z->parent->right)
				{
					z = z->parent;
					left_rotate(z);
				}
				
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(z->parent->parent);
			}
		}
		else
		{
			u = z->parent->parent->left;
			if(u && u->color == RED)
			{
				z->parent->color = BLACK;
				u->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if(z == z->parent->left)
				{
					z = z->parent;
					right_rotate(z);
				}
				
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(z->parent->parent);
			}
		}
		root->color = BLACK;
	}
	return true;
}

Node &RBTree::operator[](int k)
{
	Node *n = root;
	
	while(n->key != k && n != NULL)
	{
		if(n->key > k) n = n->left;
		else n = n->right;
	}
	return *n;
}
/*
void RBTree::display()
{
	display(root);
} 

void RBTree::display(Node *n)
{
	if(n->left) display(n->left);
	cout << setw(8) << n->key << setw(10) << n->gender << setw(8) << n->height << setw(8) << n->weight << setw(8) << ((n->color==0)? 'R' : 'B') << endl;
	if(n->right) display(n->right);
}
*/
