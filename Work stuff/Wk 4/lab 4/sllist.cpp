
#include "sllist.hpp"
#include <iostream>



namespace hlp2{
struct node {
int value; // data portion
node *next; // pointer portion
};

struct sllist {
node *head;
};
}


namespace{

    hlp2::node* create_node(int value, hlp2::node* next = nullptr);
    hlp2::node* create_node(int value, hlp2::node* next) {
        return new hlp2::node {value, next};
    }

}
namespace hlp2{
int data(node const *p) { return p->value; }
void data(node *p, int newval) { p->value = newval; }
node* next(node *p) { return p->next; }
node const* next(node const *p) { return p->next; }

sllist* construct() {
return new sllist {nullptr};
}

void destruct(sllist *ptr_sll){
        node* head = ptr_sll->head, *next;
        while(head){
            next = head->next;
            delete head;
          }
        delete ptr_sll;
    }

// add element to front of linked list
void push_front(sllist *ptr_sll, int value) {
    ptr_sll->head = create_node(value, ptr_sll->head);
    //std::cout<<"front value is: "<<ptr_sll->head->value<<std::endl;
}
node* front(sllist *ptr_sll){return ptr_sll->head;}

  
node const* front(sllist const *ptr_sll){return ptr_sll->head;}

size_t size(sllist const *ptr_sll){
        size_t cnt {};
        for (node *head = ptr_sll->head; head; head = next(head)) {
            ++cnt;
        }
        return cnt;
    }


bool empty(sllist const *ptr_sll){
        std::cout<<"empty is "<<(ptr_sll->head ? false : true )<<std::endl;
        return ptr_sll->head ? false : true;
    }
/*
bool empty(sllist const *ptr_sll){
    std::cout<<"size(ptr_sll) is:"<<size(ptr_sll)<<std::endl;
   if(size(ptr_sll)){
    return true;
   }else{
    return false;
   } 
   return false;
}
*/


/*
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
*/
// return number of elements in linked list container
/*
size_t size(sllist const *ptr_sll) {
    size_t cnt {};
    for (node *head = ptr_sll->head; head; head = next(head)) {
    ++cnt;
    }
    return cnt;
}
*/

/*
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




void push_back(sllist *ptr_sll, int value){
        if(empty(ptr_sll)){
            push_front(ptr_sll, value);
        }
        else{
            node*head = ptr_sll->head;
            while(head->next){
                head = head->next;
            }
            head->next = create_node(value);
        }
    }


 void push_back(sllist *ptr_sll, int value){
        if(empty(ptr_sll)){
            push_front(ptr_sll, value);
        }
        else{
            node*head = ptr_sll->head;
            while(head->next){
                head = head->next;
            }
            head->next = create_node(value);
        }
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
    
    //
}

void remove_first(sllist *ptr_sll, int value){
        //empty list
        if(empty(ptr_sll))return;
        //delete first
        node* head = ptr_sll->head;
        if(head->value == value){
            ptr_sll->head = head->next;
            delete head;
            return;
        }
        while(head->next){
            if(head->next->value == value){
                node*temp = head->next;
                head->next = temp->next;
                delete temp;
                break;;
            }
            head = head->next;
        }
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
    

void insert(sllist *ptr_sll, int value, size_t index){
        //start from zero
        if(index == 0){
            push_front(ptr_sll, value);
            return;
        }
        node* head = ptr_sll->head;
        while(--index && head->next){
            head = head->next;
        }
        head->next = create_node(value, head->next);
    }

node* find(sllist const *ptr_sll, int value){
    for(node* head = ptr_sll->head;head;head = next(head)){
        if(value == head->value){
            return head;
        }
    }
    return nullptr;
}
*/

}



