#include<stdio.h>
#include<string.h>
 
void subseq(char s[],int i ,char out[],int newidx){
    if(i==strlen(s)){
        out[newidx]='\0';
        if(newidx>0){
        
        printf("%s\n",out);
        }
        return;
        
    }
    
    //to include the current char
    out[newidx]=s[i];
    subseq(s,i+1,out,newidx+1);
    //exclude the current char
    subseq(s,i+1,out,newidx);
    
}

int main(){
    char s[50],out[50];
    scanf("%s",s);
    subseq(s,0,out,0);
    return 0;
}