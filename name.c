#include <stdio.h>
#include <string.h>

int main(){
    char firstName[30];

    printf("Enter your first name: \n");
    scanf("%s", firstName);

    if(strlen(firstName) > 2){
        int i =0;
        while(firstName[i]!='\0'){
            printf("%d %c\n", i, firstName[i]);
            i++;
        }
    }
}