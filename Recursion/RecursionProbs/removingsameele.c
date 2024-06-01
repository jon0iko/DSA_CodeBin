#include <stdio.h>
#include <string.h>
typedef long long int lli;

int map[26] = {0};
int ind=0;

void rem(char s[], int i, char new[])
{
    if (i == strlen(s))
    {
        return;
    }

    char current = s[i];
    if (map[current - 'a'] == 1)
    {
        rem(s, i + 1, new);
    }
    else
    {
        new[ind++] = current;
        map[current - 'a'] = 1;
        rem(s, i + 1, new);
    }
    new[ind]='\0';
}

int main()
{
    char s[50], output[50];
    scanf("%s", s);
    rem(s, 0, output);
    printf("%s",output);
    

    return 0;
}