void remove_duplicated(list *l) {
    if (l->size == 0) {
        printf("The list is empty.\n");
        return;
    }
    node *prev = l->head;
    node *pt = l->head->next;
    while (pt != NULL) {
        if (pt->info == prev->info) {

            node *duplicate = pt;
            prev->next = pt->next;
            pt = pt->next;
            free(duplicate);
            l->size--;
        } else {

            prev = pt;
            pt = pt->next;
        }
    }
}
