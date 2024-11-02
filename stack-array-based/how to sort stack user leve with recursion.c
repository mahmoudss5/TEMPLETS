void sortedinsert(stack *s, type item) {
    if (isempty(s) || item > peek(s)) {
        push(s, item);
        return;
    }
    type temp = pop(s);
    sortedinsert(s, item);
    push(s, temp);
}
void sortStack(stack *s) {
    if (!isempty(s)) {
        type temp = pop(s);
        sortStack(s);
        sortedinsert(s, temp);
    }
}
