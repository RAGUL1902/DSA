//use g++ to  compile the program  
#include <iostream> 
#include <string> 
#include <queue> 
using namespace std; 

// Linked list node 
struct ListNode 
{ 
	int data; 
	ListNode* next; 
}; 

struct BinaryTreeNode 
{ 
	int data; 
	BinaryTreeNode *left, *right; 
}; 

// insert node in linked list
void push(struct ListNode** head_ref, int new_data) 
{ 
	struct ListNode* new_node = new ListNode; 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

// construct binary tree
BinaryTreeNode* newBinaryTreeNode(int data) 
{ 
	BinaryTreeNode *temp = new BinaryTreeNode; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// linked representation of binary tree. 
void linked_list_to_binarytree(ListNode *head, BinaryTreeNode* &root) 
{ 
	queue<BinaryTreeNode *> q; 

	// Base Case 
	if (head == NULL) 
	{ 
		root = NULL;
		return; 
	} 

	root = newBinaryTreeNode(head->data); 
	q.push(root); 

	head = head->next; 
	while (head) 
	{ 

		BinaryTreeNode* parent = q.front(); 
		q.pop(); 

		BinaryTreeNode *leftChild = NULL, *rightChild = NULL; 
		leftChild = newBinaryTreeNode(head->data); 
		q.push(leftChild); 
		head = head->next; 
		if (head) 
		{ 
			rightChild = newBinaryTreeNode(head->data); 
			q.push(rightChild); 
			head = head->next; 
		} 
		parent->left = leftChild; 
		parent->right = rightChild; 
	} 
} 

//function to traverse the binary tree after conversion 
void inorder_traversal(BinaryTreeNode* root) 
{ 
	if (root) 
	{ 
		inorder_traversal( root->left ); 
		cout << root->data << " "; 
		inorder_traversal( root->right ); 
	}
    
} 
void preorder_traversal(BinaryTreeNode* root) 
{ 
    
   if(root){
    // first print data of node 
    cout << root->data << " "; 
    // rhen recursion on left subtree and then right
    preorder_traversal(root->left);  
    preorder_traversal(root->right); 
   }
   
}

void postorder_traversal(BinaryTreeNode* root) 
{ 
    if (root == NULL) 
        return; 
  
    // first recursion on left subtree and then right
    postorder_traversal(root->left); 
    postorder_traversal(root->right); 
    cout << root->data << " "; 
} 
int Height(BinaryTreeNode* root) 
{ 
    if (root == NULL) 
        return -1; 
    else
    { 
        // FInd height of each side
        int left_height = Height(root->left); 
        int right_height = Height(root->right); 
     
        if (left_height > right_height) 
            return(left_height + 1); 
        else return(right_height + 1); 
    } 
} 
// Driver program to test above functions 
int main() 
{ 
	// create a linked list shown in above diagram 
	struct ListNode* head = NULL; 
    int ele,ch;
	printf("\n1 - Insert an element into tree\n");
    printf("2 - Inorder Traversal\n");
    printf("3 - Preorder Traversal\n");
    printf("4 - Postorder Traversal\n");
    printf("5 - Height of tree\n");
    printf("6 - Exit\n");
    while(1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:    
            cout<<"Enter element to insert ";
            scanf("%d",&ele);
            push(&head,ele);
            BinaryTreeNode *root; 
	        linked_list_to_binarytree(head, root); 
            break;
        case 2:    
            cout << "Inorder Traversal of the constructed Binary Tree is: \n"; 
	        inorder_traversal(root); 
            break;
        case 3:    
           cout<<"\n Pre order traversal: \n";
            preorder_traversal(root);
            break;
        case 4:    
            cout<<"\n Post order traversal: \n";
            postorder_traversal(root);
            break;
        case 5: 
              
           cout<<"\n Height of tree is "<<Height(root);
           break;
        case 6:
          exit(0);
        default :     
            printf("Wrong choice, Please enter correct choice  ");
            break;    
        }
    }
	
     
	return 0; 
} 
