#include "sllist.hpp"

namespace hlp2{
    struct node{
        int value;
        node *next;
    };
    struct sllist{
        node *head;
    };


}
namespace{
    /*
    \brief      Create a node with a specified linked list
    \param[in]  value   -> value to fill the node with
    \param[in]  next    -> pointer to the next node in a linked list
    \return     Node filled with given parameters
    */
    hlp2::node* create_node(int value, hlp2::node *next = nullptr);
    hlp2::node* create_node(int value, hlp2::node* next) {
        return new hlp2::node {value, next};
    }
}


namespace hlp2{

    // interface to individual elements of singly-linked list
    int         data(node const *p){return p->value;} // accessor to node's data
    void        data(node *p, int newval){p->value = newval;} // mutator to node's data
    node*       next(node *p){return p->next;} // pointer to successor node
    node const* next(node const *p){return p->next;} // pointer to successor node

    /*
    \brief      1) construct a empty linked list
    \return     pointer to created empty linked list
    */
    sllist* construct(){
        return new sllist{nullptr};
    }

    /*
    \brief      2) delete the created linked list
    \param[in]  ptr_sll -> pointer to a singly linked list
    */
    void destruct(sllist *ptr_sll){
        node* head = ptr_sll->head, *next;
        while(head){
            next = head->next;
            delete head;
            head = next;
        }
        delete ptr_sll;
    }

    /*
    \brief      3) add a node with a specified value to start of linked list
    \param[in]  ptr_sll -> pointer to linked list
    \param[in]  value   -> value to be added
    */
    void push_front(sllist *ptr_sll, int value){
        ptr_sll->head = create_node(value, ptr_sll->head);
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
        return ptr_sll->head ? false : true;
    }
    /*
   
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


  
    


    node* find(sllist const *ptr_sll, int value){
        node* head = ptr_sll->head;
        while(head){
            if(head->value == value){
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }

  
    

    */

}