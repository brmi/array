//
//  main.cpp
//  array
//
//  Created by desiree on 11/9/14.
//  Copyright (c) 2014 desiree. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//int appendToAll(string a[], int n, string value);
//Append value to the end of each of the n elements of the array and return n.

//int lookup(const string a[], int n, string target);
//Return the position of a string in the array that is equal to target; if there is more than one such string, return the smallest position number of such a matching string. Return −1 if there is no such string. As noted above, case matters: Do not consider "RIck" to be equal to "rIcK".

//int positionOfMax(const string a[], int n);
//Return the position of a string in the array such that that string is >= every string in the array.

//int rotateLeft(string a[], int n, int pos);
//Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that was thus eliminated into the last position of the array. Return the original position of the item that was moved to the end.

//int rotateRight(string a[], int n, int pos);
//Eliminate the item at position pos by copying all elements before it one place to the right. Put the item that was thus eliminated into the first position of the array. Return the original position of the item that was moved to the beginning. Here's an example:
//string characters[5] = { "rosita", "bob", "sasha", "glenn", "michonne" };
//int p = rotateRight(characters, 5, 2);  // returns 2
//// characters now contains:  "sasha", "rosita", "bob", "glenn", "michonne"


int appendToAll(string a[], int n, string value);

int lookup(const string a[], int n, string target);

int positionOfMax(const string a[], int n);

int rotateLeft(string a[], int n, int pos);

int rotateRight(string a[], int n, int pos);

int main()
{
    string cast[6] = { "rosita", "bob", "sasha", "glenn", "michonne" };
    int n=5;
    int pos=1;
    
    //{ "rosita", "rosita", "sasha", "glenn", "michonne" }
    
    cout<<rotateRight(cast, n, pos);
}

int rotateRight(string a[], int n, int pos)
{
    if(n<0)
        return -1;
    
    string temp;
    temp= a[pos];
    int originalPos=pos;
    
    for (int i=0; i<n; i++)
    {
        if (pos!=(n-1))
        {
            string tempString;
            a[pos]=a[pos-1];
            
            
            pos++;
        }else
        {
            a[0]=temp;
            
        }
        cout<<a[i]<<endl;
    }
    return originalPos;
}

int appendToAll(string a[], int n, string value)
{
    for (int i=0; i<n; i++)
    {
        a[i]=a[i]+value;
    }
    if (n<0)
        return -1;
    
    return n;
}


int lookup(const string a[], int n, string target)
{
    if(n<0)
        return -1;
    
    for(int i=0; i<n; i++)
    {
        if(a[i]==target)
            return i;
    }
    return -1;
}

int positionOfMax(const string a[], int n)
{
    if(n<0)
        return -1;
    
    int i=0;
    int j=i+1;
    
    while(i<n && j<n)
    {
        while(i<(n-1) && j<(n-1))
        {
            if(a[i]>=a[j])
            {
                j++;
            }
            else
            {
                i++;
            }
            
        }
        if(a[i]<a[j])
            return j;
        if(a[i]>a[j])
            return i;
        if(a[i]==a[j])
        {
            if(i<j)
                return i;
            else
                return j;
        }
        
    }
    return -1;
}

int rotateLeft(string a[], int n, int pos)
{
    if(n<0)
        return -1;
    
    string temp;
    temp= a[pos];
    int originalPos=pos;
    
    for (int i=0; i<n; i++)
    {
        if (pos!=(n-1))
        {
            a[pos]=a[pos+1];
            pos++;
        }else
        {
            a[n-1]=temp;
            
        }
        cout<<a[i]<<endl;
    }
    return originalPos;
}




































