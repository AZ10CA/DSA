using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

int size_of(LinkedList *node) {
    auto ptr = node;
    auto size = 0;

    while (ptr) {
        size++;
        ptr = ptr->next;
    }

    return size;
}

LinkedList *middleNode(LinkedList *linkedList) {
    // Time: O(n), Space: O(1)
    auto size = size_of(linkedList);
    auto middle = std::ceil(size / 2);

    while (middle-- && linkedList)
        linkedList = linkedList->next;

    return linkedList;
}
