#include <stdio.h>
#include <string.h>
typedef long long int lli;

int first=-1,last=-1;

void check (char s[], int i, char element) {

    if (i==strlen(s))
    {
        printf("%d\n",first);
        printf("%d\n",last);
        return;
    }
    

    char current = s[i];
    if (current == element)
    {
        if (first==-1)
        {
            first = i;
        }
        else {
            last = i;
        }
        
    }

    check(s,i+1,element);
    
}

int main()
{
    char s[50];
    scanf("%s", s);

    check(s,0,'p');
    return 0;
}