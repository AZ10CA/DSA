using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

int size_of(LinkedList *);

LinkedList *mergingLinkedLists(
        LinkedList *linkedListOne, LinkedList *linkedListTwo
) {
    /**
  if we start iterating from the first node, the larger linked list will fall behind the smaller linked list
  this results in the larger list reaching the intersection later than the smaller one
      */
    auto size_1 = size_of(linkedListOne), size_2 = size_of(linkedListTwo);
    auto larger = size_1 > size_2 ? linkedListOne : linkedListTwo;
    auto smaller = larger == linkedListOne ? linkedListTwo : linkedListOne;
    auto diff = std::abs(size_1 - size_2);

    // providing a head start to the larger linked list
    while (diff--)
        larger = larger->next;

    for (int i = 0; i < std::min(size_1, size_2); i++) {
        if (larger == smaller)
            return larger;
        larger = larger->next;
        smaller = smaller->next;
    }

    return nullptr;
}

int size_of(LinkedList *node) {
    auto ptr = node;
    auto size = 0;

    while (ptr) {
        size++;
        ptr = ptr->next;
    }

    return size;
}
