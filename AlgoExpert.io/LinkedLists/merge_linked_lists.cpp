#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList* next;

    LinkedList(int value) {
        this->value = value;
        next = nullptr;
    }
};

LinkedList* mergeLinkedLists(LinkedList* headOne, LinkedList* headTwo) {
    // Time: O(n + m), Space: O(1)
    auto first = headOne, second = headTwo;
    LinkedList* ptr;

    if(first->value < second->value){
        ptr = first;
        first = first->next;
    } else {
        ptr = second;
        second = second->next;
    }

    auto result = ptr;

    while(first && second){
        if(first->value < second->value){
            ptr->next = first;
            first = first->next;
            ptr = ptr->next;
        } else {
            ptr->next = second;
            second = second->next;
            ptr = ptr->next;
        }
    }

    ptr->next = first ? first : second;

    return result;
}
