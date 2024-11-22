void join(list *l, list *l2) {
    int sz = size(l2);
    int sz1 = size(l);
    for (int i = 0; i < sz; ++i) {
        type item = peak(l2, i);
        insert(l, item, sz1);
        sz1++;
    }
}
