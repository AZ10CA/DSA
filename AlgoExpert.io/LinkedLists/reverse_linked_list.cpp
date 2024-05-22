using namespace std;

class LinkedList {
public:
    int value;
    LinkedList* next;

    LinkedList(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

LinkedList* reverseLinkedList(LinkedList* head) {
    // Time: O(n), Space: O(1)
    LinkedList* prev = nullptr;
    while(head){
        auto next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

