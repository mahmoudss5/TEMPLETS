type pop(list *l) {
    int position=0;
    if (l->head == NULL) {
        printf("Error: List is empty.\n");
        return 0;
    }
    node *current = l->head;
    type elem;
        elem = current->info;
        l->head = current->next;
        free(current);
    l->size--;
    return elem;
}
