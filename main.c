#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

struct list {
    int field;
    struct list *ptr;
};


struct list* init(int a)
{
    struct list* head = (struct list*)malloc(sizeof(struct list));
    head->field = a;
    head->ptr = NULL;
    return (head);
}



void listprint(struct list* lst)
{
    if (lst == NULL) {
        printf("Empty list ;p\n");
        return;
    }
    struct list* p;
    p = lst;
    do {
        printf("%d ", p->field);
        p = p->ptr;
    } while (p != NULL);
}

struct list* add(struct list* head, int data)
{
    struct list* temp, * p;
    p = head->ptr;
    temp = (struct list*)malloc(sizeof(struct list));
    head->ptr = temp;
    temp->field = data;
    temp->ptr = p;
    return (temp);
}

int remove_last(struct list* head) {
    int retval = 0;
    if (head->ptr == NULL) {
        retval = head->field;
        free(head);
        return retval;
    }
    struct list * current = head;
    while (current->ptr->ptr != NULL) {
        current = current->ptr;
    }
    retval = current->ptr->field;
    free(current->ptr);
    current->ptr = NULL;
    return retval;
}

struct list *destroyListRecursive(struct list * head)
{

    if (head != NULL) {
        destroyListRecursive(head->ptr);
        free(head);
    }

    return NULL;
}

int searchElement(struct list *head, int value)
{
    if(head == NULL) {
        printf("Empty list ;p");
        return -1;
    }
    if( head->ptr == NULL)
        return (head->field == value) ? 0: -1;

    int position = 0;
    struct list *cur = head;
    do {
        if( cur->field == value )
            return position;
        else
            position++;
        cur = cur->ptr;
    } while( cur != NULL );
    return -1;
};


int main()
{
struct list* head, * r;
int a, n, e, l;
struct  list* p1 = (struct list*)malloc(sizeof(struct list));
head = 0;
p1 = 0;

int input;
while (input != 7) {
    printf( "\nMenu\n" );
    printf( "1. Create the first element of the list\n" );
    printf( "2. Add a new element to the end of the list\n" );
    printf( "3. Delete an element from the end of the list\n" );
    printf( "4. Look through the list\n" );
    printf( "5. DELETE the list\n" );
    printf( "6. Search for an element of the list\n" );
    printf( "7. Exit\n" );
    printf( "Print 1/2/3/4/5/6/7: " );
scanf("%d", &input);
switch (input) {
    case 1: // Create the first element of the list
        printf("How many elements do you want in your first list?: ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("Add an element: ");
            scanf("%d", &a);
            if (i == 0)  {
                head = p1 = init(a);
                head = p1;
            }
            else
                p1 = add(p1, a);
        }
        break;
    case 2: // Add a new element to the end of the list
        printf("\nAdd a value: ");
        scanf("%d", &a);
        if (head == NULL) {
            head = p1 = init(a);
            head = p1;
        }
        else {
            p1 = add(p1, a);
            listprint(head);
            putchar('\n');
        }
        break;
    case 3: // Delete a element from the end of the list
        remove_last(head);
        putchar('\n');
        listprint(head);
        putchar('\n');
        break;
    case 4: // Look through the list
        putchar('\n');
        listprint(head);
        putchar('\n');
        break;
    case 5: // DELETE the list
        head = destroyListRecursive(head);
        putchar('\n');
        listprint(head);
        break;
    case 6: // Search for an element in the list
        printf("Enter an element: ");
        scanf("%d", &a);
        if (searchElement(head, a) != -1)
            printf("An element has been found, position %d\n", searchElement(head, a)+1);
        else
            printf("Couldn't find an element :c");
        break;
    case 7: // Exit
        break;
    default:
        printf("/nWrong input!");
        break;
        }
}
free(p1);
getchar();
return 0;
}
