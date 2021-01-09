#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    //string input from the user
    
    cout<<"Enter the input String: ";
    cin>>s;

    char *p = &s[0];
    //pointer p used to traverse the character array(string)
    
    cout<<"\nOdd elements :";
    for(int i=0;i<s.length();i = i+2)
    {
        cout<<*(p+i)<<" ";
    }
    cout<<endl<<"Even elements are: ";
    for(int i=1;i<s.length();i = i+2)
    {
        cout<<*(i+p)<<" ";
    }


}
