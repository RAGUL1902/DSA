//use g++ to compile as this is a c++ program
#include <iostream>
using namespace std;

//node of the bst
struct node {
	char key;
	struct node *left, *right;
};

//create new node function
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

//prints inorder traversal
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->key<<" ";
		inorder(root->right);
	}
}

//function to insert a node
struct node* BSTInsert(struct node* node, char key)
{

	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = BSTInsert(node->left, key);
	else
		node->right = BSTInsert(node->right, key);

	return node;
}

//this function is used in delete function
struct node* minValueNode(struct node* node)
{
	struct node* current = node;
	while (current && current->left != NULL)
		current = current->left;

	return current;
}


//function to delete a node
struct node* deleteNode(struct node* root, char key)
{
	
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else {
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

//main function
int main()
{
    struct node* root = NULL;
    cout<<"\nInitially the tree is empty.\n";
    cout<<"\nEnter 1 to insert a char element.\nEnter 2 to print inoder traversal.\nEnter 3 to delete a node.\nEnter 4 to exit.";
    while (1)
    {
        int choice;
        cout<<"\n--> ";
        cin>>choice;
        if(choice == 1){
            char element;
            cout<<"Enter a char to insert: ";
            cin>>element;
            root = BSTInsert(root,element);
        }
        if(choice == 2){
            cout<<"inorder traversal: ";
            inorder(root);
        }
        if(choice == 3){
            char element;
            cout<<"Enter the char to delete: ";
            cin>>element;
            root = deleteNode(root,element);
            cout<<"Element "<<element<<" is deleted.";
        }
        if(choice == 4){
            return 0;
        }
    }
    
}


