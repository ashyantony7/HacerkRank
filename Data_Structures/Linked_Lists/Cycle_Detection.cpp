

// Complete the has_cycle function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {

    map<SinglyLinkedListNode*, int> count;

    auto node = head;
    count[head]++;

    while (node->next != NULL){
        if (count[node->next]) return true;
        else{
            node = node->next;
            count[node]++;
        }
    }

    return false;

}