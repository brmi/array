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
//Eliminate the item at position pos by copying all elements before it one place to the right. Put the item that was thus eliminated into the first position of the array. Return the original position of the item that was moved to the beginning.

//int flip(string a[], int n);
//Reverse the order of the elements of the array and return n.


//int differ(const string a1[], int n1, const string a2[], int n2);
//Return the position of the first corresponding elements of a1 and a2 that are not equal.

//int subsequence(const string a1[], int n1, const string a2[], int n2);
//If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning position in the array. Return −1 if a1 does not contain a2 as a contiguous subsequence.

//int lookupAny(const string a1[], int n1, const string a2[], int n2);
//Return the smallest position in a1 of an element that is equal to any of the elements in a2. Return −1 if no element of a1 is equal to any element of a2.

//int separate(string a[], int n, string separator);
//Rearrange the elements of the array so that all the elements whose value is < separator come before all the other elements, and all the elements whose value is > separator come after all the other elements. Return the position of the first element that, after the rearrangement, is not < separator, or n if there are no such elements.


int appendToAll(string a[], int n, string value);

int lookup(const string a[], int n, string target);

int positionOfMax(const string a[], int n);

int rotateLeft(string a[], int n, int pos);

int rotateRight(string a[], int n, int pos);

int flip(string a[], int n);

int differ(const string a1[], int n1, const string a2[], int n2);

int subsequence(const string a1[], int n1, const string a2[], int n2);

int lookupAny(const string a1[], int n1, const string a2[], int n2);

int separate(string a[], int n, string separator);


int main()
{
    string cast[6] = { "maggie", "carl", "daryl", "rick", "michonne", "carol" };
    
    cout<< separate(cast, 6, "glenn");
    
    
}

int separate(string a[], int n, string separator)
{
    if(n<0)
        return -1;
    
    int count=0;
    for (int i=0; i<n; i++)
    {
        int m=0;
        while(m<n)
        {
            if(a[i]>separator)
            {
                string temp;
                temp= a[i];
                
                for (int j=i; j<n; j++)
                {
                    a[j]=a[j+1];
                }
                a[n-1]=temp;
                m++;
                //move a[i] to the last position & move everything else to the left one
            }else
                break;
        }if(a[i]<=separator)
            count++;
        //cout<<a[i]<<" ";
    }
    return count;
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
    if(pos>(n-1))
        return -1;
    
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
    }
    return originalPos;
}

int rotateRight(string a[], int n, int pos)
{
    if(pos>(n-1))
        return -1;
    
    if(n<0)
        return -1;
    
    string temp;
    temp= a[pos];
    int originalPos=pos;
    
    for (int i=0; i<n; i++)
    {
        if (pos!=0)
        {
            a[pos]=a[pos-1];
            pos--;
        }else
        {
            a[0]=temp;
            break;
        }
    }
    return originalPos;
}

int flip(string a[], int n)
{
    if(n<0)
        return -1;
    
    string temp;
    int i=0;
    int j=n;
    
    while (i<n)
    {
        temp=a[j-1];
        a[j-1]=a[i];
        a[i]=temp;
        i++;
        j--;
        if(i>=j)
            break;
        
    }
    return n;
}


int differ(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<0)
        return -1;
    if(n2<0)
        return -1;
    
    int n;
    
    int j=0;
    
    if(n1<n2)
        n=n1;
    else
        n=n2;
    
    for (int i=0; i<n; i++)
    {
        if(a1[i]!=a2[j])
            return i;
        j++;
        
    }
    return n;
    
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    
    if(n1<0)
        return -1;
    if(n2<0)
        return -1;
    
    int count=0;
    int i=0;
    int j=0;
    
    while(i<n1)
    {
        if(n2==0)
            return 0;
        
        if(j>=n2)
            break;
        
        if(a1[i]==a2[j])
        {
            if(i>=(n1-1))
                break;
            i++;
            j++;
            count++;
            
            
        }else if (a1[i]!=a2[j])
        {
            i++;
            j=0;
            count=0;
        }
    }
    
    if(j!=n2)
        return -1;
    else if(count>1)
    {
        return (i-count);
    }
    else
    {
        return -1;
    }
}


int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if (n1<0 || n2<0)
        return -1;
    
    int i=0;
    int j=0;
    
    while(i<n1)
    {
        
        if(j>=n2)
            break;
        
        if(a1[i]==a2[j])
        {
            return i;
            
        }else if (a1[i]!=a2[j])
        {
            j++;
        }
        
        if(j>=n2&& i!=n1)
        {
            i++;
            j=0;
        }
    }
    return -1;
}































