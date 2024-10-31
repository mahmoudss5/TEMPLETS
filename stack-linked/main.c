#include <stdio.h>
#include <stdlib.h>
#include "stack_linkedlist.h"
int main(void) {
 stack s;
    creatstack(&s);
    push(&s,5);
    push(&s,6);
    push(&s,7);
    int ans= pop(&s);
    if (!isempty(&s)){
        printf("it is not empty");
    }
    return 0;
}
