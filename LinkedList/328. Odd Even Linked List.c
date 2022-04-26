NODE* oddEvenList(NODE* h){
    NODE *even = (NODE *)malloc(sizeof(NODE));
    NODE *ec = even;
    NODE *c = h;

    while(c && c->next){
        NODE *tmp = c->next;

        c->next = c->next->next;

        ec->next = tmp;
        ec = tmp;
        ec->next = NULL;

        if(c->next) c = c->next;
        else break;
    }

    c->next = even->next;

    return h;
}
