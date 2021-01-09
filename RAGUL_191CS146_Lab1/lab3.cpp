#include<bits/stdc++.h>
using namespace std;

struct s
{
    int a;
    string c;
    float b;
};
s structs[100];
int n;
void newStructs(int i, int j,string k)
{
    structs[n].a = i;
    structs[n].b = j;
    structs[n].c = k;
    n = n+1;
}
void deletestruct(int i)
{
    for(int l=i;l<n-1;l+1)
    {
        structs[l].a = structs[l+1].a;
        structs[l].b = structs[l+1].b;
        structs[l].b = structs[l+1].b;
        n = n-1;
    }
}
void displayall()
{
    for(int i=0;i<n;i++)
    {
        cout<<"Struct "<<i+1<<" integer = "<< structs[i].a<<endl;
        cout<<"Struct "<<i+1<<" float = "<< structs[i].b<<endl;
        cout<<"Struct "<<i+1<<" string = "<<structs[i].c<<endl;
    }
    cout<<endl;
}
int main()
{

    
    while(1)
    {
        int option;
        cout<<"Enter 1 for menu\n";
        cout<<"Enter 2 for inserting value\n";
        cout<<"Enter 3 for deleting value\n";
        cout<<"Enter 4 for displaying all entries\n";
        cout<<"Enter 5 to exit\n";
        cout<<"Enter your option here: ";
        cin>>option;
        if(option == 2)
        {
            int i;
            float j;
            string k;
            cout<<"\nEnter the integer value : ";
            cin>>i;
            cout<<"\nEnter the float value: ";
            cin>>j;
            cout<<"\nEnter the String value: ";
            cin>>k;
            newStructs(i,j,k);

        }
        if (option == 3)
        {
            int i;
            cout<<"\nEnter the index of the element to be deleted: ";
            cin>>i;
            deletestruct(i);
        }

        if(option == 4)
        {
            displayall();
        }
        if(option == 5) break;

        
    }
}