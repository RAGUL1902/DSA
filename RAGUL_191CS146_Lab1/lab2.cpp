#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    //number of elements.

    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    int *ptr= a;
    //pointer to traverse the array and find the minimum element

    for(int i=0;i<n;i++)
    {
        if(*(ptr+i) < *ptr )
        {
            ptr = ptr+i;
        }
    }
    cout<<"Minimum Element in the array is "<<*ptr;

}