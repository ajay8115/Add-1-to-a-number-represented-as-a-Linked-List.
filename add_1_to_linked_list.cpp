// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *pre = NULL;
        Node *cur = head;
        Node *next = head->next;

        while (cur and cur->next)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    Node *addOne(Node *head)
    {
        Node *ptr = reverse(head);
        Node *cur = ptr;
        Node *prev = NULL;
        while (cur)
        {
            if (cur->data < 9)
            {
                cur->data += 1;
                return reverse(ptr);
            }
            else if (cur->data == 9)
            {
                cur->data = 0;
                prev = prev->next;
                cur = cur->next;
            }
        }

        // if all the digits are 9
        Node *temp = new Node(1);
        prev->next = temp;
        return reverse(ptr);
    }
};
