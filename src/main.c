#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{ // Not used yet
    char text[50];
    int completionState;
    time_t time;

} Task;

typedef struct{ // Not used yet
    Task *arr;
    int capacity;
    int size;

} TaskList;

void extractTasks(const char *pathToTaskfile){
    FILE *tlist;
    tlist = fopen(pathToTaskfile, "r");

    char bolsinha[100];

    if (tlist != NULL){
        while(fgets(bolsinha, 100, tlist)){
            printf("%s", bolsinha); // Print each task
        }
    }
    else {
        printf("Error opening the file.");
    }
    fclose(tlist);
}

void addTask(const char *pathToTaskfile){
    FILE *tlist;
    tlist = fopen(pathToTaskfile, "a");

    char task[100];
    printf("Describe new task: ");
    fgets(task, sizeof(task), stdin);
    fprintf(tlist, task); // Append task to list

    fclose(tlist);
}

int main(){ // TODO: FIX Double newline

    char pathToFile[50] = "./resources/tasklist.txt";

    printf("Welcome to Zeca's TODO List!\n");
    printf("============================\n");
    printf("1: View Active Tasks\n");
    // printf("2: Add Task\n");
    // printf("3: Remove Task\n");
    printf("4: Exit\n");

    int option;
    printf("Choose a number: ");
    scanf("%d", &option);
    getchar();

    switch (option){
        case 1:
            extractTasks(pathToFile);
            break;
        
        case 2:
            addTask(pathToFile);

            printf("Updated List:\n");
            extractTasks(pathToFile);

        case 4:
            exit(0);
            break;
    }

    return 0;
}