#include <bits/stdc++.h> 
using namespace std; 
  
// Function to print permutations of string 
// This function takes three parameters: 
// 1. String 
// 2. Starting index of the string 
// 3. Ending index of the string. 
void permute(string& a, int l, int r) 
{ 
    // Base case 
    if (l == r) 
        cout << a << endl; 
    else { 
        // Permutations made 
        for (int i = l; i <= r; i++) { 
            // cout << a[l] << " " << a[i] << endl;
            // Swapping done 
            swap(a[l], a[i]); 
            
            // Recursion called 
            permute(a, l + 1, r); 
  
            // backtrack 
            swap(a[l], a[i]);
            // cout << a[l] << " " << a[i] << endl;
        } 
    } 
} 
  
// Driver Code 
int main() 
{ 
    string str = "ABC"; 
    int n = str.size(); 
  
    // Function call 
    permute(str, 0, n - 1); 
    return 0; 
} 
  