
#include <stdlib.h>
#include <zconf.h>
#include <stdio.h>
#include <unistd.h>
#include "task.h"
#include "list.h"
#include "schedulers.h"

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10
#define TID 1

struct node *head = NULL;

void add(char *name, int priority, int burst) {
    printf("VALUES PRIOR TO TASK LOAD\n");
    printf("N: %s\n", name);
    printf("P: %d\n", priority);
    printf("B: %d\n", burst);

	// Add task
	Task task = { .name = name, .tid = TID, .priority = priority, .burst = burst };
	printf("VALUES AFTER TASK LOAD\n");
    printf("N: %s\n", task.name);
    printf("P: %d\n", task.priority);
    printf("B: %d\n", task.burst);

    if (head != NULL) {
        // Inserting Node pointer and Task pointer objects
        insert(&head, &task);
    } else {
        // Create the head Node
        head = (struct node *)malloc(sizeof(struct node));
        head->task = &task;
        head->next = NULL;
        printf("VALUES AFTER HEAD LOAD\n");
        printf("N: %s\n", head->task->name);
        printf("P: %d\n", head->task->priority);
        printf("B: %d\n", head->task->burst);

    }
}

// invoke the scheduler
void schedule() {
	// Traverse List
    traverse(head);
}
