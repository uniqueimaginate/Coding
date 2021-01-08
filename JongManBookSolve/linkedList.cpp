#include <iostream>

using namespace std;

// C++ STL list

struct ListNode{
    int element;
    struct ListNode *prev, *next;
};

void deleteNode(ListNode *node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void recoverNode(ListNode *node){
    node->prev->next = node;
    node->next->prev = node;
}

int main(){
    struct ListNode* head = NULL; 
    struct ListNode* second = NULL; 
    struct ListNode* third = NULL; 
    struct ListNode* pos = NULL; 


    head = new ListNode;
    second = new ListNode;
    third = new ListNode;
    pos = new ListNode;

    head->element = 1;
    second->element = 2;
    third->element = 3;

    head->next = second;
    second->next = third;
    second->prev = head;
    third->next = NULL;
    third->prev = second;
    pos = head;

    // delete second Node;
    deleteNode(second);
    while(pos->next){
        cout << pos->element << endl;
        pos = pos->next;
    }   

    // recover second Node;
    recoverNode(second);
    pos = head;
    while(pos->next){
        cout << pos->element << endl;
        pos = pos->next;
    }

    // make circular linked list
    third->next = head;
    head->prev = third;
    
    // this loop will not finish
    while(head->next){
        cout << head->next->element << endl;
        head = head->next;
    }
}