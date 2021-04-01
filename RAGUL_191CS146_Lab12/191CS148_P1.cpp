// Program for linked implementation of complete binary tree 
#include <bits/stdc++.h>
using namespace std;

// For Queue Size 
#define SIZE 50 

// A tree node 
class node 
{ 
	public:
	int data; 
	node *right,*left; 
}; 

// A queue node 
class Queue 
{ 
	public:
	int front, rear; 
	int size; 
	node**array; 
}; 

// A utility function to create a new tree node 
node* newNode(int data) 
{ 
	node* temp = new node();
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to create a new Queue 
Queue* createQueue(int size) 
{ 
	Queue* queue = new Queue(); 

	queue->front = queue->rear = -1; 
	queue->size = size; 

	queue->array = new node*[queue->size * sizeof( node* )]; 

	int i; 
	for (i = 0; i < size; ++i) 
		queue->array[i] = NULL; 

	return queue; 
} 

// Standard Queue Functions 
int isEmpty(Queue* queue) 
{ 
	return queue->front == -1; 
} 

int isFull(Queue* queue) 
{ return queue->rear == queue->size - 1; } 

int hasOnlyOneItem(Queue* queue) 
{ return queue->front == queue->rear; } 

void Enqueue(node *root, Queue* queue) 
{ 
	if (isFull(queue)) 
		return; 

	queue->array[++queue->rear] = root; 

	if (isEmpty(queue)) 
		++queue->front; 
} 

node* Dequeue(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return NULL; 

	node* temp = queue->array[queue->front]; 

	if (hasOnlyOneItem(queue)) 
		queue->front = queue->rear = -1; 
	else
		++queue->front; 

	return temp; 
} 

node* getFront(Queue* queue) 
{ return queue->array[queue->front]; } 

// A utility function to check if a tree node
// has both left and right children 
int hasBothChild(node* temp) 
{ 
	return temp && temp->left && temp->right; 
} 

// Function to insert a new node in complete binary tree 
void insert(node **root, int data, Queue* queue) 
{ 
	// Create a new node for given data 
	node *temp = newNode(data); 

	// If the tree is empty, initialize the root with new node. 
	if (!*root) 
		*root = temp; 

	else
	{ 
		// get the front node of the queue. 
		node* front = getFront(queue); 

		// If the left child of this front node doesn’t exist, set the 
		// left child as the new node 
		if (!front->left) 
			front->left = temp; 

		// If the right child of this front node doesn’t exist, set the 
		// right child as the new node 
		else if (!front->right) 
			front->right = temp; 

		// If the front node has both the left child and right child, 
		// Dequeue() it. 
		if (hasBothChild(front)) 
			Dequeue(queue); 
	} 

	// Enqueue() the new node for later insertions 
	Enqueue(temp, queue); 
} 

// Standard level order traversal to test above function 
void levelOrder(node* root) 
{ 
	Queue* queue = createQueue(SIZE); 

	Enqueue(root, queue); 

	while (!isEmpty(queue)) 
	{ 
		node* temp = Dequeue(queue); 

		cout<<temp->data<<" "; 

		if (temp->left) 
			Enqueue(temp->left, queue); 

		if (temp->right) 
			Enqueue(temp->right, queue); 
	} 
} 

void printInorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printInorder(node->left); 
  
     /* then print the data of node */
     printf("%d ", node->data);   
  
     /* now recur on right child */
     printInorder(node->right); 
}
void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
  
     // first recur on left subtree 
     printPostorder(node->left); 
  
     // then recur on right subtree 
     printPostorder(node->right); 
  
     // now deal with the node 
     printf("%d ", node->data); 
}

void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
  
     /* first print data of node */
     printf("%d ", node->data);   
  
     /* then recur on left sutree */
     printPreorder(node->left);   
  
     /* now recur on right subtree */
     printPreorder(node->right); 
}



// Driver program to test above functions
int main()
{
    struct node* root = NULL;
    struct Queue* queue = createQueue(SIZE);
    printf("Initially the tree is empty\n");    
    while(1){
        int c;
        printf("\nEnter 1 to insert: ");
        printf("\nEnter 2 to print preorder: ");
        printf("\nEnter 3 to print postorder: ");
        printf("\nEnter 4 to print inorder: ");
        printf("\nEnter 5 to print nodes (inserted order): ");
        printf("\n-->");
        scanf("%d",&c);
        if(c == 1){
            int value;
            printf("Enter the value: ");
            scanf("%d",&value);
            insert(&root,value,queue);
        }
        if(c == 2){
            printPreorder(root);
        }
        if(c==3){
            printPostorder(root);
        }
        if(c == 4){
            printInorder(root);
        }
        if(c == 5){
            levelOrder(root);
        }
    }
} 

