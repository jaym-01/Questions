#include <iostream>
#include <vector>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode* ge = NULL, *current = head, *ge_head = NULL, *ls = NULL;

        while(current != NULL){
            if(current->val >= x){
                if(ge == NULL) ge_head = current;
                else ge->next = current;
                ge = current;

                if(current == head){
                    head = current->next;
                }

                if(ls != NULL){
                    ls->next = current->next;
                }
            }
            else{
                ls = current;
            }

            current = current->next;
        }

        if(ge != NULL){
            ge->next = NULL;
        }

        if(ls == NULL){
            return ge_head;
        }
        else{
            ls->next = ge_head;
            return head;
        }
    }
};