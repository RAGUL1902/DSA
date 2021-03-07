
//Kindly use g++ to compile as this is a c++ program

#include <iostream> 
#include <stdlib.h> 
using namespace std;
 
// Node 
typedef struct node { 
    char data;  
    int priority; 
 
    struct node* next; 
 
} Node; 
 
// Function to Create A New Node 
Node* newNode(char d, int p) 
{ 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->data = d; 
    temp->priority = p; 
    temp->next = NULL; 
 
    return temp; 
} 
 
// Return the value at head 
int peek(Node** head) 
{ 
    return (*head)->data; 
} 
  
void pop(Node** head) 
{ 
    Node* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 
 
// Function to push according to priority 
void Enqueue(Node** head, char d, int p) 
{ 
    Node* start = (*head); 
 
    // Create new Node 
    Node* temp = newNode(d, p); 
  
    if ((*head)->priority < p) { 
 
        // Insert New Node before head 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
 
        while (start->next != NULL && 
            start->next->priority > p) { 
            start = start->next; 
        }  
        temp->next = start->next; 
        start->next = temp; 
    } 
} 
 
// Function to check is list is empty 
int isEmpty(Node** head) 
{ 
    return (*head) == NULL; 
} 

void printList(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->data <<endl; 
        n = n->next; 
    } 
}
 
// Driver code 
int main() 
{ 
    Node* pq = newNode(0, 0); 
    cout<<"\nInitially the list is empty"<<endl;

    while(1){
            int i;
            cout<<"\nEnter 1 to Enqueue element";
            cout<<"\nEnter 2 to Dequeue element";
            cout<<"\nEnter 3 to print priority queue";
            cout<<"\nEnter 4 to quit";
            cout<<"\n-->";
            cin>>i;
        if(i == 1){
            char ele;
            int priority;
            cout<<"\nEnter the character: ";
            cin>>ele;
            cout<<"\nEnter the priority: ";
            cin>>priority;
            Enqueue(&pq, ele, priority);
        }
        else if(i == 3){

            printList(pq);
        }
        else if(i == 2){
            pop(&pq);
            cout<<"Element dequeued\n";
            printList(pq);
        }
        else if (i == 4) {
            return 0;
        }   
    }
    }
    
