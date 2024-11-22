int count(list *l,type elemnt){
    int cnt=0;
    node *pt=l->head;
    for (int i = 0; i <l->size ; ++i) {
        if(pt->info==elemnt) cnt++;
        pt=pt->next;
    }
    return cnt;
}
