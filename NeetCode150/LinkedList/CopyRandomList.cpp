#include "includes.h"

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        std::unordered_map<Node *, Node *> mp;

        Node *curr = head;
        // Maps curr node to a new node 
        while (curr != nullptr)
        {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Do the linking here
        curr = head;
        while (curr != nullptr)
        {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};
