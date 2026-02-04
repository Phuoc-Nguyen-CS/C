#include <iostream>
#include <unordered_set>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Hash set
void removeDuplicates(Node *head)
{
    if (!head) return;

    Node* current = head;
    Node* prev = nullptr;
    std::unordered_set<int> seen;

    while (current) {
        // seen.end() returns a special value that is equivalent to a data
        // not being found in the set
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
        }
        else {
            // Add what we found
            seen.insert(current->data);
            // update previous
            prev = current;
        }
        current = prev->next;
    }
}

// Runner
void removeDuplicatesNoBuffer(Node *head)
{
    Node *current = head;
    while (current)
    {
        Node *runner = current;
        while (runner->next)
        {
            // Found duplicate
            if (runner->next->data == current->data)
            {   
                // This is the node to be deleted
                Node *duplicate = runner->next;
                
                runner->next = runner->next->next;
                delete duplicate;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Helper: Print the list
void printList(Node *head)
{
    while (head)
    {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main()
{
    // Creating list: 10 -> 12 -> 11 -> 11 -> 12 -> 11 -> 10
    Node *head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(11);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(10);

    std::cout << "Original List: ";
    printList(head);

    // removeDuplicates(head);
    removeDuplicatesNoBuffer(head);

    std::cout << "After Removing Dups: ";
    printList(head);

    return 0;
}