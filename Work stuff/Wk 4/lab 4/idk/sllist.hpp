/**!************************
**
\file sllist.hpp
\author Kaushik Thirumavalavan
\par DP email : 2203390@sit.singaporetech.edu.sg
\par Course : RSE 1201
\par Section :
\par Programming Lab #4
\date 28 - 01 - 2023
\brief
This program defines struct node, sllistand declares functions construct,
destruct, push_front, push_back, insert, remove_first, front, find, empty
and size .

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
* *************************
*/
#ifndef SLLIST_HPP
#define SLLIST_HPP

#include <iostream>
#include <cstddef>

namespace hlp2{
    struct node;
    struct sllist;

    // interface to individual elements of singly-linked list
    int data(node const *p); // accessor to node's data
    void data(node *p, int newval); // mutator to node's data
    node* next(node *p); // pointer to successor node
    node const* next(node const *p); // pointer to successor node
    // interface declarations for singly-linked list...

    /*
    /!************************
**
\brief
This function creates a node with a specific linked list 

\param int value 
Integer value to fill the node with 

\param next
pointer to next node in linked list 

\return
new node 
**************************
*/
    
    sllist* construct();

    /*!************************
        **
        \brief
        This function deletes the created linked list

        \param sllist * ptr_sll
        pointer pointing to singly linked list

        \return
        void
        **************************
        */
    void destruct(sllist *ptr_sll);

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
    void push_front(sllist *ptr_sll, int value);
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
    void push_back(sllist *ptr_sll, int value);

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
    void insert(sllist *ptr_sll, int value, size_t index);

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
    void remove_first(sllist *ptr_sll, int value);

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
    node* front(sllist *ptr_sll);
    node const* front(sllist const *ptr_sll);

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
    node* find(sllist const *ptr_sll, int value);

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
    bool empty(sllist const *ptr_sll);

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
    size_t size(sllist const *ptr_sll);

}


#endif