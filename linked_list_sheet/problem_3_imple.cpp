void joinlist(list *l1, list *l2) {
    if (l1->head == NULL) {
        l1->head = l2->head;
        l1->size = l2->size;
        return;
    }
    if (l2->head == NULL) {
        return;
    }
    node *pt = l1->head;
    while (pt->next != NULL) {
        pt = pt->next;
    }
    pt->next = l2->head;
    l1->size += l2->size;
}
