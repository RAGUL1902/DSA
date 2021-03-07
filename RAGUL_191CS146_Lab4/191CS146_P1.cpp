#include<iostream>
#include<string.h>
using namespace std;
 
struct Node
{
    string data;
    struct Node *next;
};



void InsertAtBegining(Node **head_ref, string data) 
{ 
    Node *ptr1 = new Node();
    Node *temp = *head_ref; 
    ptr1->data = data; 
    ptr1->next = *head_ref; 
 

    if (*head_ref != NULL) 
    { 
        while (temp->next != *head_ref) 
            temp = temp->next; 
        temp->next = ptr1; 
    } 
    else
        ptr1->next = ptr1; 
 
    *head_ref = ptr1; 
} 

void PrintList(Node *head) 
{ 
    Node *temp = head; 
    if (head != NULL) 
    { 
        do
        { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
        while (temp != head); 
    } 
}

Node *Search(Node *head, string data)
{
    Node *temp_head = head;
    Node *LOC= head;
    string KEY = data;
    do{
        if(LOC ->data == KEY)
        {
            return LOC;
        }
        LOC = LOC ->next;

    }while(LOC ->next != temp_head);

    return NULL;

}


int main(){
    Node *head = NULL;

    InsertAtBegining(&head,"a");
    InsertAtBegining(&head,"b");
    InsertAtBegining(&head,"c");
    InsertAtBegining(&head,"d");
    InsertAtBegining(&head,"e");
    InsertAtBegining(&head,"f");
    int i;
    while (true)
    {
        cout<<"\nEnter 1 to Print List";
        cout<<"\nEnter 2 to add elemet at begining";
        cout<<"\nEnter 3 to search element";
        cout<<"\nEnter 4 to quit";
        cout<<"\n--> ";
        cin>>i;
        if(i == 4){
            return 0;
        }
        else if(i == 1){
            cout<<endl;
            PrintList(head);
            cout<<endl;
        }
        else if(i == 2){
            string data;
            cout<<"\nEnter the data: ";
            cin>>data;
            InsertAtBegining(&head,data);
            cout<<endl;
            PrintList(head);
            cout<<endl;
            cout<<"\nData added at the begining";
            cout<<endl;
        }
        else if(i == 3)
        {
            string data;
            cout<<"\nEnter the data to be searched: "; 
            cin>>data;
            cout<<"\n LOC: "<<Search(head,data);
            cout<<endl;
        }

    }
    

}