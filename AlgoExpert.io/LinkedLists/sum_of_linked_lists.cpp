using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

int list_to_int(LinkedList *list);

LinkedList *int_to_list(int num);

LinkedList *sumOfLinkedLists(
        LinkedList *linkedListOne, LinkedList *linkedListTwo
) {
    auto total = list_to_int(linkedListOne) + list_to_int(linkedListTwo);
    return int_to_list(total);
}


int list_to_int(LinkedList *list) {
    string str;
    auto ptr = list;
    while (ptr) {
        str += ptr->value + '0';
        ptr = ptr->next;
    }

    std::reverse(str.begin(), str.end());
    return stoi(str);
}

LinkedList *int_to_list(int num) {
    // Time: O(n), Space: O(n) where n is the max size between the lists
    auto str = to_string(num);
    std::reverse(str.begin(), str.end());

    auto head = new LinkedList(str[0] - '0');
    auto ptr = head;
    for (int i = 1; i < str.size(); i++) {
        ptr->next = new LinkedList(str[i] - '0');
        ptr = ptr->next;
    }
    return head;
}
