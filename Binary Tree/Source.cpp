#include<iostream>

using namespace std;

class BinaryTree
{
private:
	//created a stuct of node with these elements
	struct node
	{
		int data;
		node* left;
		node* right;

	};
	//have a root pointer
	node* root =nullptr;

	void DisplayInOrder(node *root) 
	{
		//if the root pointer points to a node
		if (root)
		{
			//recursion to get the left most element and add it to the stack
			DisplayInOrder(root->left);
			cout << root->data << endl;
			//recursion to get the right most element and add it to the stack
			DisplayInOrder(root->right);
		}
	}
	void createNode(int data)
	{
		//have a pointer to the newely created node
		node* newNode = new node();
		newNode->data = data;
		newNode->left = newNode->right = nullptr;
		// pass both the root pointer and the newly created node
		insertNode(root,newNode);


	}
	void insertNode(node* &nodeptr, node* &newNode)
	{
		// For the first run root becomes nodeptr and since empty add the first element to the tree
		if (nodeptr == nullptr)
		{
			nodeptr = newNode;
		}
		//if the tree has more then one element. Traverse down the tree on the left side to find an empty spot
		// use recursion pass that memory address and the newnode and make that point to the newely created node
		else if (newNode->data < nodeptr->data)
		{
			insertNode(nodeptr->left, newNode);
		}
		else
		{
			insertNode(nodeptr->right, newNode);
		}

	}
public:
	
	void insertNodePublic(int data)
	{
		createNode(data);
	}
	void DisplayInOrderPublic()
	{
		DisplayInOrder(root);
	}
};



int main()
{
	BinaryTree Tree;
	Tree.insertNodePublic(5);
	Tree.insertNodePublic(1);
	Tree.insertNodePublic(22);
	Tree.insertNodePublic(20);
	Tree.insertNodePublic(85);
	Tree.insertNodePublic(12);
	Tree.insertNodePublic(3);
	
	Tree.DisplayInOrderPublic();
	system("PAUSE");

}