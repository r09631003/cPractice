struct ListNode* removeElements(struct ListNode* head, int val){
    helper(&head, val);
    
    return head;
}

void helper(struct ListNode **head, int x){
    if(!(*head)) return;
    
    struct ListNode *cur = *head;
    
    while(cur->next){
        if(cur->next->val != x)
            cur = cur->next;
        else{
            struct ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        }
    }
    
    if((*head)->val == x){
        struct ListNode *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}
