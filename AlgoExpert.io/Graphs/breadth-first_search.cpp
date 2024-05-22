#include <vector>
#include <iostream>

using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
    string name;
    vector<Node *> children;

    Node(string str) { name = str; }

    vector <string> breadthFirstSearch(vector <string> *array) {
        // Time: O(V + E), Space: O(V)
        queue < Node * > to_visit;
        to_visit.push(this);

        while (not to_visit.empty()) {
            auto top = to_visit.front();
            to_visit.pop();
            for (auto child: top->children)
                to_visit.push(child);

            array->push_back(top->name);

        }

        return *array;
    }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};
