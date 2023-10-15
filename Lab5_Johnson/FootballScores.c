#include <stdio.h>

int playValues[5];

void printCombinations(int score, int fromPlayValueIndex, int *playCounts){
    int maxItters[5];

    for (int i=fromPlayValueIndex; i < 5; i++){
        maxItters[i] = score/playValues[i];
    }

    for (int j=maxItters[fromPlayValueIndex]; j >= 0; j--){
        
        playCounts[fromPlayValueIndex] = j;

        int remainingScore = score - j*playValues[fromPlayValueIndex];

        if (fromPlayValueIndex < 4){
             printCombinations(remainingScore, fromPlayValueIndex+1, playCounts);
        } else {
            if (remainingScore != 0){
                return;
            } else {
                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", playCounts[0], playCounts[1], playCounts[2], playCounts[3], playCounts[4]);
                return;
            }
        }
    }
}

int main(){

    playValues[0] = 8;
    playValues[1] = 7;
    playValues[2] = 6;
    playValues[3] = 3;
    playValues[4] = 2;

    while (1){
        int score;

        printf("Enter 0 or 1 to exit\nEnter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1){
            break;
        }

        int solution[5];
        printCombinations(score, 0, solution);


    }

    return 0;
}