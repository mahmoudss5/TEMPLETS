#define MAX_SIZE 100 

typedef struct {
    int items[MAX_SIZE];
    int size;
} List;

void initializeList(List *list) {
    list->size = 0;
}

int isEmpty(List *list) {
    return list->size == 0;
}

int isFull(List *list) {
    return list->size == MAX_SIZE;
}

int insert(List *list, int position, int value) {
    if (isFull(list)) {
        printf("Error: List is full.\n");
        return 0;
    }
    if (position < 0 || position > list->size) {
        printf("Error: Invalid position.\n");
        return 0;
    }
    for (int i = list->size; i > position; i--) {
        list->items[i] = list->items[i - 1];
    }
    list->items[position] = value;
    list->size++;
    return 1;
}

int delete(List *list, int position) {
    if (isEmpty(list)) {
        printf("Error: List is empty.\n");
        return 0;
    }
    if (position < 0 || position >= list->size) {
        printf("Error: Invalid position.\n");
        return 0;
    }
    for (int i = position; i < list->size - 1; i++) {
        list->items[i] = list->items[i + 1];
    }
    list->size--;
    return 1;
}

int retrieve(List *list, int position, int *value) {
    if (position < 0 || position >= list->size) {
        printf("Error: Invalid position.\n");
        return 0;
    }
    *value = list->items[position];
    return 1;
}

void display(List *list) {
    if (isEmpty(list)) {
        printf("The list is empty.\n");
        return;
    }
    printf("List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->items[i]);
    }
    printf("\n");
}
