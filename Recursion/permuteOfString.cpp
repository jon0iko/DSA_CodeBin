#include<iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

void permute(string s,int l,int sz){
    if(l==sz){
        cout<<s<<endl;
        return;
    }
    for(int i=l;i<=sz;i++){
        swap(s[l],s[i]);
        permute(s,l+1,sz);
        swap(s[l],s[i]);
    }
}

// permuteWithoutduplicates code below
// Program to print all permutations of a

// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil(string str, char first, int l, int h)
{
	// initialize index of ceiling element
	int ceilIndex = l;

	// Now iterate through rest of the elements and find the
	// smallest character greater than 'first'
	for (int i = l + 1; i <= h; i++)
		if (str[i] > first && str[i] < str[ceilIndex])
			ceilIndex = i;

	return ceilIndex;
}

// Print all permutations of str in sorted order
void PermutationsWithoutDupli(string str)
{
	// Get size of string
	int size = str.length();
	// Sort the string in increasing order
	sort(str.begin(), str.end());
	// Print permutations one by one
	bool isFinished = false;
	while (!isFinished)
	{
		// print this permutation
		cout << str << endl;
		// printf("%d %s \n", x++, str);
		// Find the rightmost character which is smaller
		// than its next character. Let us call it 'first
		// char'
		int i;
		for (i = size - 2; i >= 0; --i)
			if (str[i] < str[i + 1])
				break;
		// If there is no such character, all are sorted in
		// decreasing order, means we just printed the last
		// permutation and we are done.
		if (i == -1)
			isFinished = true;
		else
		{
			// Find the ceil of 'first char' in right of
			// first character. Ceil of a character is the
			// smallest character greater than it
			int ceilIndex = findCeil(str, str[i], i + 1, size - 1);
			// Swap first and second characters
			swap(str[i], str[ceilIndex]);
			// Sort the string on right of 'first char'
			sort(str.begin() + i + 1, str.end());
		}
	}
}

//permutation without duplicates efficient way
void printAllPermutationsEfficient(string s, string l)
{
    if (s.length() < 1) 
        cout << l + s << endl;
    unordered_set<char> uset;
    for (int i = 0; i < s.length(); i++) 
    {
        if (uset.find(s[i]) != uset.end()) 
            continue;
        else
            uset.insert(s[i]);
        string temp = "";
        if (i < s.length() - 1) 
            temp = s.substr(0, i) + s.substr(i + 1);
        else
            temp = s.substr(0, i);
        printAllPermutationsEfficient(temp, l + s[i]);
    }
}



int main(){
    string s;
    cin>>s;
    int sz=s.size();
    permute(s,0,sz-1);
    PermutationsWithoutDupli(s);
}