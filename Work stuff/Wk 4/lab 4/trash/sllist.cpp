// Other than sllist.hpp, you really don't have to include any other files except when testing your code.
// When you're ready to submit, don't include either of the following two headers: <forward_list> and <list>
// If you're not including sllist.hpp, you may need to include <cstddef> for size_t [which is the largest unsigned type from the C standard library]
#include "sllist.hpp"
#include <iostream>
// Private functions must be declared and defined in an anonymous namespace!!!

// All names declared in sllist.hpp must be defined in namespace hlp2!!!

// See the spec for structure and interface definitions!!!

/*
namespace{
hlp2::node* create_node(int value, hlp2::node* next = nullptr);
}
*/

struct node {
int value; // data portion
node *next; // pointer portion
};

struct sllist {
node *head;
};


namespace hlp2{


sllist* construct() {
return new sllist {nullptr};
}

namespace{

    node* create_node(int value, node* next = nullptr) {
    return new node {value, next};
    }

}

int data(node const *p) { return p->value; }
void data(node *p, int newval) { p->value = newval; }
node* next(node *p) { return p->next; }
node const* next(node const *p) { return p->next; }


// add element to front of linked list
void push_front(sllist *ptr_sll, int value) {
    ptr_sll->head = create_node(value, ptr_sll->head);
    //std::cout<<"front value is: "<<ptr_sll->head->value<<std::endl;
}
// return number of elements in linked list container
size_t size(sllist const *ptr_sll) {
    size_t cnt {};
    for (node *head = ptr_sll->head; head; head = next(head)) {
    ++cnt;
    }
    return cnt;
}

void destruct(sllist *ptr_sll){
    node* temp;
    for (node *head = ptr_sll->head; head; head = next(temp)) {
        if(head!=nullptr){
        temp = head;
        delete head;
        }else{
            delete head;
        }
    }
    delete ptr_sll;
}
bool empty(sllist const *ptr_sll){
   if(size(ptr_sll)){
    return true;
   }else{
    return false;
   } 
   return false;
}
void push_back(sllist *ptr_sll, int value){
    node* current = ptr_sll->head;
    if(ptr_sll->head == nullptr){
        node* newNode = create_node(value, nullptr);
        ptr_sll->head = newNode;
    }else{
        while(current->next != nullptr){
            current = next(current);
        }
        node* newNode = create_node(value, nullptr);
        current->next = newNode;
    }
    //IDENTIFYING LAST NODE WITH POINTER ARITHMATIC MAY BE WRONG!!!
    //node* last = ((ptr_sll->head)+size(ptr_sll)-1);
    
    /*
    node* last;
    for(node* head = ptr_sll->head;head!=nullptr;head = next(head)){
        last = head;
    }
    node* newLast = create_node(value, nullptr);
    last->next = newLast;
    */
}
//MISSING NODE
void remove_first(sllist *ptr_sll, int value){

    //node* temp;
    
    node* trail = ptr_sll->head;
    int flip = 0;
    for(node* head = ptr_sll->head; head; head = next(head)){
        //trail is supposed to trail behind temp node
        if(flip>0){
            trail = next(trail);        
        }
        if(head->value == value){
            trail->next = head->next;
            delete head;

        }
        flip++;
    }
    
}

void insert(sllist *ptr_sll, int value, size_t index){

    
    node* head = ptr_sll->head;
    node* temp1 = head;
    //node* oneNode;
    if (index == 0) {
        push_front(ptr_sll, value);
    }else if(index == 1){
        node* newNode1 = create_node(value, head->next->next);
        head->next = newNode1;
    }else{
    //temp1 is before the insert onject, temp2 is after. The idea is to connect both of these to the ends of the inserted object.
    for(size_t i = 0; i<=index-1;i++){
        temp1 = temp1->next;
        }
    node* temp2 = temp1->next;
    node* newNode = create_node(value, temp2);
    temp1->next = newNode;
    }
    
}

node* front(sllist *ptr_sll){
 if(ptr_sll->head){
    return ptr_sll->head;
 }
 return nullptr;
}
node const* front(sllist const *ptr_sll){
 if(ptr_sll->head){
    return ptr_sll->head;
 }
 return nullptr;
}

node* find(sllist const *ptr_sll, int value){
    for(node* head = ptr_sll->head;head;head = next(head)){
        if(value == head->value){
            return head;
        }
    }
    return nullptr;
}


}



