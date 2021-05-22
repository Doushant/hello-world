#include<iostream>
#include <bits/stdc++.h>
using namespace std;
  
void removeWord(string str)
{
    // Used to split string around spaces.
    istringstream ss(str);
  
    string word; // for storing each word

    while (ss >> word) 
    {
        // print the read word
        cout << word << "\n";
    }
}
  
// Driver code
int main()
{
    string str;
    cout<< "input a sentence: ";
    cin>>str;
    removeWord(str);
    return 0;
}