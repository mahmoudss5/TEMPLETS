int isPresent(list *l, type target) {
    if (l->size == 0) {
        return 0;
    }
    node *pt = l->head;
    int found = 0;
    int index = 0;
    while (pt != NULL) {
        if (pt->info == target) {
            found = 1;
            break;
        }
        pt = pt->next;
        index++;
    }
    if (!found) {
        return 0;
    }
    int x= erase(l, index);
    insert(l, x, 0);

    return 1;
}
