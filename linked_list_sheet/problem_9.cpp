void Reverse(list *l) {
    if (l->head == NULL || l->head->next == NULL) {

        return;
    }

    node *prev = NULL;
    node *current = l->head;
    node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    l->head = prev;
}
