#include <vector>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList* next;

    LinkedList(int value);
};

LinkedList* findLoop(LinkedList* head) {
    // Time: O(n), Space: O(1)
    // find out the size of the cycle
    // reset the fast and slow pointers to the beginning but move the fast pointer forward by the cycle size
    // this guarantees that two pointers will meet in the origin of the cycle if we both pointers one at a time
    auto fast = head->next, slow = head;
    auto cycle_size = 0;
    while(fast && fast->next){
        if(fast == slow){
            // measure cycle size
            auto ptr = slow->next;
            cycle_size++;
            while(ptr != fast){
                cycle_size++;
                ptr = ptr->next;
            }
            cout << cycle_size << endl;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    // there isn't a cycle
    if(!fast)
        return nullptr;

    slow = head, fast = head;
    while(cycle_size--)
        fast = fast->next;

    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}
