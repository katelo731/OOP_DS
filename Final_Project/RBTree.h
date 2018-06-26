#ifndef RBTREE_H
#define RBTREE_H
#include <bits/stdc++.h>
#define RED 0
#define BLACK 1
using namespace std;

struct Node
{
	int key, height, weight, color;
	string gender;
	Node *left = NULL, *right = NULL, *parent = NULL;
	
	Node(int k, string g, int h, int w)
	{
		key = k;
		gender = g;
		weight = w;
		height = h;
		color = RED;
	}
	
	const string getGender() {return gender;}
    const int getHeight() {return height;}
    const int getWeight() {return weight;}
};

class RBTree
{
	public:
		RBTree();
		void left_rotate(Node *x);
		void right_rotate(Node *x);
		bool insert(int k,string g,int h,int w);
		Node &operator[](int k);
		void display();
		void display(Node *n);
	private:
		Node *root;
};

#endif
