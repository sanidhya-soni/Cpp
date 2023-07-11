#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int maxi = 0;

ListNode *removeHelper(ListNode *p)
{
    if (p == nullptr)
        return p;

    p->next = removeHelper(p->next);

    maxi = max(maxi, p->val);

    if (p->val < maxi)
    {
        ListNode *temp = p->next;
        p->next = nullptr;
        return temp;
    }
    return p;
}

ListNode *removeNodes(ListNode *head)
{
    ListNode *p = head;
    head = removeHelper(p);
    return head;
}

int main()
{
    // Create a linked list and pass it to the function removeNodes and it will do the job by returning the required output.

    return 0;
}
