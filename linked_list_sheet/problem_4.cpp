type GetNth(list *l, int index) {
    if (l->head == NULL) {
        printf("List is empty!\n");
        return 0;
    }

    if (index < 0 || index >= l->size) {
        printf("Invalid index!\n");
        return 0;
    }

    node *pt = l->head;
    for (int i = 0; i < index; ++i) {
        pt = pt->next;
    }
    return pt->info;
}
