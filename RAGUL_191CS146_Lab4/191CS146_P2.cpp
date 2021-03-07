#include<iostream>
#include<string>
using namespace std;


struct Node {
   string data;
   struct Node *next;
   struct Node *prev;
};

void InsertAtBegining(Node **head_ref,string new_data){
    
    struct Node* new_node = (struct Node*)malloc(sizeof(Node));
     new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    
    (*head_ref) = new_node;
}

Node *Search(Node** head_ref, string x)
{
 
    
    Node* temp = *head_ref;
 
    
    while (temp->data != x
           && temp->next != NULL) { 
        temp = temp->next;
    }
 
    if (temp->data != x)
        return NULL;

    return temp;
}

void InsertAfterLOC(Node **tmp_head,Node *prev_node,string new_data){


   if (prev_node == NULL) {
        InsertAtBegining(tmp_head,new_data);
    }
 

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 

    new_node->data = new_data;

    new_node->next = prev_node->next;
 

    prev_node->next = new_node;
 

    new_node->prev = prev_node;
 
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}


void Insert(Node **tmp_head,string item, string prev){
   Node *LOC = Search(tmp_head,prev);
   if(LOC == NULL){
      InsertAtBegining(tmp_head,item);
      return;
   }
   InsertAfterLOC(tmp_head,LOC,item);

}

void PrintList(struct Node* node) 
{ 
    struct Node* last; 
    cout<<"\nTraversal in forward direction \n"; 
    while (node != NULL) { 
        cout<<node->data<<" ";
        last = node; 
        node = node->next; 
    } 
 
    cout<<"\nTraversal in reverse direction \n"; 
    while (last != NULL) { 
         cout<<last->data<<" "; 
        last = last->prev; 
    } 
}

int main() {

    Node * head = NULL;
   // InsertAtBegining(&head,"a");
   // InsertAtBegining(&head,"b");
   // InsertAtBegining(&head,"c");
   // InsertAtBegining(&head,"d");
   // InsertAtBegining(&head,"e");

   while(true){
      int i;
      cout<<"\nEnter 1 to print list: ";
      cout<<"\nEnter 2 to insert value:";
      cout<<"\nEnter 3 to Delete first occurence: ";
      cout<<"\nEnter 4 to exit";
      cout<<"\n--> ";
      cin>>i;

      if(i == 4){
         return 0;
      }
      else if(i == 1){
         PrintList(head);
      }
      else if(i  == 2){
         string a,b;
         cout<<"\nEnter the item to insert: ";
         cin>>a;
         cout<<"\nEnter the element after which the item should be inserted: ";
         cin>>b;
         Insert(&head,b,a);
         PrintList(head);
      }


   }


}