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
        printf("Empty list ;p");
        return;
    }
    struct list* p;
    for (p = lst; p != NULL; p = p->ptr)
        printf ("%d ", p->field);
}

struct list* add(struct list* head, int data)
{
    struct list* temp;
    temp = (struct list*)malloc(sizeof(struct list));
    head->ptr = temp;
    temp->field = data;
    temp->ptr = NULL;
    return (temp);
}

int remove_last(struct list* head)
{
    if (head == NULL)
        return NULL;
    if (head->ptr == NULL) {
        free(head);
        return 0;
    }
    struct list *current = head;
    while (current->ptr->ptr != NULL)
        current = current->ptr;
    free(current->ptr);
    current->ptr = NULL;
    return 0;
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
        printf("Empty list ;p\n");
        return -1;
    }
    if( head->ptr == NULL)
        return (head->field == value) ? 0: -1;
    struct list *current = head;
    for (; current !=NULL; current = current->ptr)
        if( current->field == value )
            return 0;
    return -1;
};


int main()
{
struct list* head;
int a;
struct  list* p1 = (struct list*)malloc(sizeof(struct list));
head = NULL;
p1->field = NULL;

printf( "\nMenu\n" );
printf( "1. Create the first element of the list\n" );
printf( "2. Add a new element to the end of the list\n" );
printf( "3. Delete an element from the end of the list\n" );
printf( "4. Look through the list\n" );
printf( "5. DELETE the list\n" );
printf( "6. Search for an element of the list\n" );
printf( "7. Exit\n" );

int input;
while (input != 7) {
        printf( "\nPrint 1/2/3/4/5/6/7: " );
        scanf("%d", &input);
switch (input) {
    case 1: /* Create the first element of the list*/
        printf("Add an element: ");
        scanf("%d", &a);
        head = p1 = init(a);
        head = p1;
        listprint(head);
        putchar('\n');
        break;
    case 2: /* Add a new element to the end of the list*/
        printf("Add a value: ");
        scanf("%d", &a);
        if (head == NULL)
        {
            head = p1 = init(a);
            head = p1;
            listprint(head);
            putchar('\n');
        }
        else {
            p1 = add(p1, a);
            listprint(head);
            putchar('\n');
        }
        break;
    case 3: /* Delete a element from the end of the list*/
        remove_last(head);
        listprint(head);
        putchar('\n');
        break;
    case 4: /* Look through the list*/
        listprint(head);
        putchar('\n');
        break;
    case 5: /* DELETE the list*/
        head = destroyListRecursive(head);
        listprint(head);
        putchar('\n');
        break;
    case 6: /* Search for an element in the list*/
        printf("Enter an element: ");
        scanf("%d", &a);
        if (searchElement(head, a) == 0)
            printf("An element has been found");
        else
            printf("Couldn't find an element :c");
        putchar('\n');
        break;
    case 7: /* Exit*/
        break;
    default:
        printf("Wrong input!\n");
        break;
        }
}
free(p1);
return 0;
}
