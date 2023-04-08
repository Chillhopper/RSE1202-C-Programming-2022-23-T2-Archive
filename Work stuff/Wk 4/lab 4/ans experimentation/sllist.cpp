/*!************************
**
\file sllist.cpp
\author Kaushik Thirumavalavan
\par DP email : 2200927@sit.singaporetech.edu.sg
\par Course : RSE 1201
\par Section :
\par Programming Lab #4
\date 28 - 01 - 2023
\brief
This program defines functions create_node,
construct, destruct, push_front, push_back, insert, remove_first, front, find, empty
and size.

- create_node
This function creates a node with a specific linked list

- construct
This function constructs an empty linked list

- destruct
This function deletes the created linked list

- push_front
This function adds a node with a specific value at the beginning
of the linked list

- push_back
This function adds a node with a specific value at the end
of the linked list

- insert
This function adds a node with a value to specific index of linked list

- remove_first
This function removes the first instance of node with a specific value

- front
This function retrieves the front of linked list

- find
This function locates a node with a specific value

- empty
This function checks if a  linked list is empty

- size
This function returns  the size of a linked list
* **************************/

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

    /*!************************
        **
        \brief
        This function creates a node with a specific linked list

        \param int value
        Integer value to fill the node with

        \param next
        pointer to next node in linked list

        \return
        new node
        * *************************
        */

    sllist* construct(){
        return new sllist{nullptr};
    }

/*!************************
        **
        \brief
        This function deletes the created linked list

        \param sllist * ptr_sll
        pointer pointing to singly linked list

        \return
        void
        **************************
        * /

        !************************
        **/
    void destruct(sllist *ptr_sll){
        node* head = ptr_sll->head, *next;
        while(head){
            next = head->next;
            delete head;
            head = next;
        }
        delete ptr_sll;
    }

    /*!************************
        **
        \brief
        This function adds a node with a specific value at the beginning
        of the linked list

        \param ptr_sll
        pointer pointing to linked list

        \param value
        integer value in the node to be added

        \return
        void
        **************************
        */
    void push_front(sllist *ptr_sll, int value){
        ptr_sll->head = create_node(value, ptr_sll->head);
    }

    /*!************************
        **
        \brief
        This function adds a node with a specific value at the end
        of the linked list

        \param ptr_sll
        pointer pointing to linked list

        \param value
        integer value in the node to be added

        \return
        void
        **************************
        */

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
/*
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
*/
    /*!************************
        **
        \brief
        This function adds a node with a specific value at a specific index
        of the linked list

        \param ptr_sll
        pointer pointing to linked list

        \param value
        integer value in the node to be added

        \param index
        index of the linked list where the node will be added

        \return
        void
        **************************
        */
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

    /*!************************
        **
        \brief
        This function rmoves the first instance of a node with a specific value

        \param ptr_sll
        pointer pointing to linked list

        \param value
        integer value in the node to be removed

        \return
        void
        **************************
        */
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


 /************************
        **
        \brief
        This function retrieves the front of linked list

        \param ptr_sll
        pointer pointing to linked list

        \return
        node at the start of the linked list
        * *************************
        */
    node* front(sllist *ptr_sll){return ptr_sll->head;}
    node const* front(sllist const *ptr_sll){return ptr_sll->head;}

    /*!************************
        **
        \brief
        This function locates a node with a specific value

        \param ptr_sll
        pointer pointing to linked list

        \param value
        value in the node to be located

        \return
        node with the specified value
        * *************************
        */
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

    /*!************************
        **
        \brief
        This function checks if a  linked list is empty

        \param ptr_sll
        pointer pointing to linked list

        \return
        true if linked list is empty
        false if linked list is not empty
        * *************************
        */
    bool empty(sllist const *ptr_sll){
        return ptr_sll->head ? false : true;
    }
    

    /*!************************
        **
        \brief
        This function returns  the size of a linked list

        \param ptr_sll
        pointer pointing to linked list

        \return
        size of linked list
        * *************************
        */
    size_t size(sllist const *ptr_sll){
        size_t cnt {};
        for (node *head = ptr_sll->head; head; head = next(head)) {
            ++cnt;
        }
        return cnt;
    }
}