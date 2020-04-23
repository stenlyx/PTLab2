#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int val;
struct node * next;
    } node_t;

int searchNode(node_t *head, int value)
{
    if( head == NULL )
        return -1;
    if( head->next == NULL)
        return (head->val == value) ? 0: -1;

        int position = 0;
    node_t *cur = head;
    do {
        if( cur->val == value )
            return position;
        else
            position++;
        cur = cur->next;
    } while( cur != NULL );

    return -1;
};

void print_list(node_t * head) {
    node_t * current = head;
while (current != NULL) {
    printf("Number: %d\n", current->val);
        current = current->next;
}
}

void push(node_t * head, int val) {
    node_t * current = head;
while (current->next != NULL) {
current = current->next;
}
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;

}
int remove_last(node_t * head) {

int retval = 0;
    if (head->next == NULL) {
        retval = head->val;
            free(head);
return retval;
}
    node_t * current = head;
while (current->next->next != NULL) {
    current = current->next;
}
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
return retval;
}
int main() {
    node_t * head = NULL;
    head = malloc(sizeof(node_t));

    if (head == NULL) {
return 1;
}
int n, a;
/*
        head->val = 1000;
        head->next = malloc(sizeof(node_t));
        head->next->val = 2000;
        head->next->next = malloc(sizeof(node_t));
        head->next->next->val = 1608;
        head->next->next->next = malloc(sizeof(node_t));
        head->next->next->next->val = 2001;
        head->next->next->next->next = NULL;
        */
int input;
int lol = 1;
while (input != 7) {
    printf( "Menu\n" );
    printf( "1. Create the first value of the list\n" );
    printf( "2. Add a new value to the end of the list\n" );
    printf( "3. Delete a value from the end of the list\n" );
    printf( "4. Look through the list\n" );
    printf( "5. DELETE the list\n" );
    printf( "6. Search for a value in the list\n" );
    printf( "7. Exit\n" );
    printf( "Print 1/2/3/4/5/6/7: " );
scanf("%d", &input);
switch (input) {
    case 1:
        break;
    case 2:
        printf("\nInput a value: ");
        n=scanf("%d", &a);
        if(n !=1)
            return 2;
        printf("\nAdded new value to the list \n\n");
        push(head, a);
        print_list(head);
        getch();
        break;
    case 3:
        printf("\nDelete the last value in the list\n\n");
        remove_last(head);
        print_list(head);
        break;
    case 4:
        head->val = 1000;
        head->next = malloc(sizeof(node_t));
        head->next->val = 2000;
        head->next->next = malloc(sizeof(node_t));
        head->next->next->val = 1608;
        head->next->next->next = malloc(sizeof(node_t));
        head->next->next->next->val = 2001;
        head->next->next->next->next = NULL;
        print_list(head);
        break;
    case 5:
        while (lol < sizeof(node_t)) {
            remove_last(head);
            print_list(head);
            lol++;
        }
        break;
    case 6:
        puts("Search for value:");
        int val;
        scanf("%d", &val);
        if (searchNode(head, val) != -1)
            printf("Found! Position %d\n",searchNode(head, val) +1 );
        else
            puts("Couldn't find the value!");
        break;
    case 7:
        printf("/nExiting the program.");
        break;
    default:
        printf("/nWrong input!");
        }
}
getchar();
return 0;
}
