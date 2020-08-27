#include <iostream>
using namespace std;


class ListNode {
public:
    ListNode* next;
    int var;

    ListNode(int x) : next(NULL), var(x) {}

};

void print(ListNode* list) {
    for(ListNode* it = list; it != NULL; it = it->next) {
        cout << it->var << (it->next == NULL ? "" : " -> ");
    }
    cout << endl;
}

int traverse(ListNode* l) {
    int count = 0;
    for(ListNode* temp = l; temp != nullptr; temp = temp->next) {
        count++;
    }
    return count;
}

ListNode* findIntersection(ListNode* l1, ListNode* l2) {
    int s1 = 0, s2 = 0;
    s1 = traverse(l1);
    s2 = traverse(l2);
    
    ListNode* bigList, smallList;
    if(s1 > s2) 
        bigList = l1;
    else
        smallList = l2;
    
    for(int i = 0; i < abs(s1 - s2); ++i) {
        bigList = bigList->next;
    }    

    ListNode* it1 = bigList, it2 = smallList;
    while(it1 != it2 || it1 != nullptr && it2 != nullptr) {
        it1 = it1->next;
        it2 = it2->next;
    }

    return it1;

}

int main() {
    ListNode* list1;
    ListNode* temp = new ListNode(1);
    
    list1 = temp;    
    for(int i = 2; i < 11; ++i) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    
    ListNode* trav = list1;
    for(int i = 0; i < 5; ++i) {
        trav = trav->next;
    }
    ListNode* list2;
    temp = new ListNode(15);
    list2 = temp;
    for(int i = 14; i > 10; --i) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    
    temp->next = trav;
    
    print(list1);
    print(list2);

    ListNode* inter = findIntersection(list1, list2);
    cout << "intersection at " << inter->var << endl;
    return 0;
}
