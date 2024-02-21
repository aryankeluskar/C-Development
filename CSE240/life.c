#include <stdio.h>
#include <string.h>

int main(){
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    char choice = 'a';
    // using scanf to get input from user
    scanf(" %c", &choice);

    // while loop to keep asking for input until user enters 'q'
    while (choice != 'q'){
        printf("Enter the offsets for the live cells: ");
        char offsets[1000];
        scanf("%s", offsets);
        // input is like 6,11,12,16 so we need to split the string by comma and then store every int in an array
        // printf("offsets = %s\n", offsets);

        int offsetsArray[1000];
        for(int i = 0; i < 1000; i++){
            offsetsArray[i] = 0; // initialize the array with 0
        }
        int i = 0;
        for(int j = 0; j < strlen(offsets); j++){
            // printf("offsets[j] = %c\n", offsets[j]);
            int curr = offsets[j] - '0';
            // printf("offsets[j] = %d\n", curr);
            if(curr == -4){
                i++;
            }else{
                offsetsArray[i] = offsetsArray[i] * 10 + curr;
            }
        }
        i++;

        int pos1 = 0, pos2 =0;
        int matrix[5][5];
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                matrix[i][j] = 0;
                if(pos1==offsetsArray[pos2]){
                    // if the current position is in the offsetsArray, then set the value to 1, ie: live cell
                    matrix[i][j] = 1;
                    pos2++;
                }
                pos1++;
            }
        }

        printf("generation = 0:\n");
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                if(matrix[i][j] == 1){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }

        for (int k = 0; k < 6; k++)
        {         
            printf("generation = %d:\n", k+1);
            int newMatrix[5][5];
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 5; j++){

                    // counts the number of live cells around the current cell by checking the 8 surrounding cells
                    int sum = 0;
                    for (int k = -1; k <= 1; k++){
                        for (int l = -1; l <= 1; l++){
                            if (i + k >= 0 && i + k < 5 && j + l >= 0 && j + l < 5){
                                if(matrix[i + k][j + l] == 1){
                                    sum++;
                                }
                            }
                        }
                    }

                    // if the current cell is live, then decrement the sum by 1 since we counted the current cell as well
                    if (matrix[i][j] == 1){
                        sum--;
                    }
                    // printf("%d ", sum);
                    // printf("sum for %d %d = %d\n", i, j, sum);

                    // the conditions for the game of life as per the rules
                    if(sum == 3 || (sum == 2 && matrix[i][j] == 1)){
                        newMatrix[i][j] = 1;
                    }else if((sum < 2 || sum > 3) && matrix[i][j] == 1){
                        newMatrix[i][j] = 0;
                    }
                }
                // printf("\n");
            }
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 5; j++){
                    if(newMatrix[i][j] == 1){
                        printf("*");
                    }else{
                        printf(" ");
                    }
                    matrix[i][j] = newMatrix[i][j];
                }
                printf("\n");
            }
            
        }
        printf("Good life!\n");
        printf("Press 'q' to quit or any other key to continue:\n");
        scanf(" %c", &choice);
    }
    printf("Bye Bye!\n");
}