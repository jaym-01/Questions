#include <iostream>
#include <vector>
#include <stack>


using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#define left (int)(k - out.size())

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        stack<ListNode*> out;

        int quot, rem, cntr = 0;

        createStack(head, k, quot, rem, out, cntr);

        vector<ListNode*> final_out;

        while(!out.empty()){
            final_out.push_back(out.top());
            out.pop();
        }

        return final_out;
    }

private:
    int createStack(ListNode* head, int& k, int& quot, int& rem, stack<ListNode*>& out, int& cntr){
        if(head == NULL){
            quot = cntr/k;
            rem = cntr%k;

            if(quot == 0){
                int extra = k - rem;

                for(int i = 0; i < extra; i++){
                    out.push(NULL);
                }

                return 1;
            }
            else{
                return quot;
            }
        }
        else{
            cntr++;
            int vals = createStack(head->next, k, quot, rem, out, cntr);

            // check if it is the end
            if(left <= rem && vals == quot + 1){
                head->next = NULL;
            }
            else if(left > rem && vals == quot){
                head->next = NULL;
            }

            // check if it is the first one
            if(vals == 1){
                out.push(head);
                if(left <= rem) return quot + 1;
                else return quot;
            }
            else{
                return vals - 1;
            }
        }
    }
};

ListNode* create(vector<int> nums, int i){
    if(i == nums.size()) return NULL;
    else {
        ListNode* head = new ListNode;
        head->val = nums[i];
        head->next = create(nums, i + 1);

        return head;
    }
}

void destroy(ListNode* head){
    if(head == NULL){
        return;
    }

    destroy(head->next);

    delete head;
}

void print(ListNode* head){
    if(head == NULL) {
        cout << "NULL" << endl;
        return;
    }
    cout << head->val << ", ";

    print(head->next);

}

int main(){
    Solution s;

    vector<int> t1 {1,2,3,4,5,6,7};

    ListNode* t1h = create(t1, 0);

    vector<ListNode*> out1 = s.splitListToParts(t1h, 3);

    for(int i = 0; i < out1.size(); i++){
        print(out1[i]);
    }

    destroy(t1h);
}