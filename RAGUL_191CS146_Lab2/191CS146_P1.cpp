
//I used c++ to program, so kindly use g++ 191CS146_P1.cpp to compile and run

//From line 17 to 53 has the code to quicksort

//From line 54 to 114 has the code to merge sort

#include<bits/stdc++.h>


//structure defintion
using namespace std;

struct student{
	int marks;
	string name;
};

//code for the quicksort

void swapmarks(int* a, int* b)  
{  
    int t = *a;
    *a = *b;  
    *b = t;  
} 


int partition (student students[], int low, int high) 
{ 
    int pivot = students[high].marks;  
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
         
        if (students[j].marks < pivot) 
        { 
            i++;     
            swapmarks(&students[i].marks, &students[j].marks);
            (students[i].name).swap(students[j].name);
        } 
    } 
    swapmarks(&students[i + 1].marks, &students[high].marks);
    (students[i+1].name).swap(students[high].name);
    return (i + 1); 
} 

void quicksort(student students[], int low, int high)  
{ 
    if (low < high)  
    {  
        int part = partition(students, low, high);    
        quicksort(students, low, part - 1);  
        quicksort(students, part + 1, high);  
    }  
}

//Mergesort Program

void merge(student students[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    student L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i].marks = students[l + i].marks;
        L[i].name = students[l + i].name;
    }
    for (int j = 0; j < n2; j++)
    {
        R[j].marks = students[m + 1 + j].marks;
        R[j].name = students[m + 1 + j].name;
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i].marks <= R[j].marks) {
            students[k].marks = L[i].marks;
            students[k].name = L[i].name;
            i++;
        }
        else {
            students[k].marks = R[j].marks;
            students[k].name = R[j].name;
            j++;
        }
        k++;
    }
    while (i < n1) {
        students[k].marks = L[i].marks;
        students[k].name = L[i].name;
        i++;
        k++;
    }

    while (j < n2) {
        students[k].marks = R[j].marks;
        students[k].name = R[j].name;
        j++;
        k++;
    }
}
 

void mergesort(student students[],int l,int r){
    if(l>=r){
        return;
    }
    int m = (l+r-1)/2;
    mergesort(students,l,m);
    mergesort(students,m+1,r);
    merge(students,l,m,r);
}

//Program to print the array of structures


void printStructures(student students[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        {
        cout<<students[i].name<<"  "<<students[i].marks<<endl;    
        };  
}


int main(){
	int n;

    //polpulating the structure;

	student students[5];
	students[0].marks = 10;
	students[1].marks = 78;
	students[2].marks = 100;
	students[3].marks = 23;
	students[4].marks = 55;
	students[0].name = "ragul";
	students[1].name = "ramesh";
	students[2].name = "suresh";
	students[3].name = "krishna";
	students[4].name = "rakesh";

    //menu driven program

	while(1){
		cout<<"\nEnter 1 for menu ";
		cout<<"\nEnter 2 to sort marks of students using merge sort ";
		cout<<"\nEnter 3 to sort marks of students using quicksort ";
		cout<<"\nEnter 4 to print the student names and their marks ";
		cout<<"\nEnter 5 to quit \n";
		cout<<"\n--> ";
		cin>>n;
		if(n == 5)
		return 0;
		if(n == 3)
		{
		quicksort(students,0,4);
		printStructures(students,5);
		}
		if(n == 2)
		{
		mergesort(students,0,4);
		printStructures(students,5);
		}
		if(n == 4)
		printStructures(students,5);

	}


}