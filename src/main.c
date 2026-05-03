#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char text[50];
    int completionState;
    time_t time;

} Task;

typedef struct{
    Task *arr;
    int capacity;
    int size;

} TaskList;

void extractTasks(const char *pathToTaskfile){
    FILE *tlist;
    tlist = fopen(pathToTaskfile, "r");

    char bolsinha[1000];

    if (tlist != NULL){
        while(fgets(bolsinha, 1000, tlist)){
            printf("%s", bolsinha);
        }
    }
    else {
        printf("Error opening the file.");
    }

    fclose(tlist);

}

int main(){

    printf("Welcome to Zeca's TODO List!\n");
    printf("============================\n");
    printf("1: View Active Tasks\n");
    // printf("2: Add Task\n");
    // printf("3: Remove Task\n");
    printf("4: Exit\n");

    int option;
    printf("Choose a number: ");
    scanf("%d", &option);

    switch (option){
        case 1:
            extractTasks("./resources/tasklist.txt");
            break;

        case 4:
            exit(0);
            break;
    }

    return 0;
}