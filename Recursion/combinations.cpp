#include<iostream>
using namespace std;


void combinations(string s,int l,int sz,string ans)
{
    if(l==sz)
    {
        cout<<ans<<endl;
        return;
    }
    combinations(s,l+1,sz,ans+s[l]);
    combinations(s,l+1,sz,ans);
}
int main()
{
    string s="123";
    combinations(s,0,s.length(),"");
}