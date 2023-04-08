/*!************************
**
\file dllist.cpp
\author Kaushik Thirumavalavan
\par DP email: 2200927@sit.singaporetech.edu.sg
\par Course: RSE 1201 
\par Programming Assignment #4
\date 02-02-2023
\brief
This program defines functions which use interface-implementation separation 
to complete a doubly linked list ADT

Helper functions : 
- construct node 
This function allocates and initializes a node object on the free store 

- destruct node 
This function return dynamically allocated memory back to free store

- get_value
This function returns the int value in node


Functions of a singly-linked list : 

- construct_list
This function creates a empty linked list 

- destruct_list
This function deletes the created linked list 

- size
This function returns  the count of all elements

- push_front
This function adds an element with a specific value at the beginning 
of the linked list

- push_back
This function adds an element with a specific value at the end 
of the linked list

- print
This function print each element of linked list from front to back

- find
This function finds the  first element in linked list with 
value specified by 2nd parameter

- insert
This function insert elements with value in 2nd parameter in linked list at
the index specified by position

- remove_first
This function removes the  first element in linked list with value 
specified in 2nd parameter
**************************
*/

#include <iostream>
#include <iomanip>
#include "dllist.h"
#include <iostream>

namespace hlp2 {

	/*******************************************************************************
	 * DATA TYPES
	 ******************************************************************************/

	struct node {
		node* prev; // pointer to previous node
		int value;  // data portion
		node* next; // pointer to next node
	};

	struct dllist {
		node *head, *tail;
	};

	/*******************************************************************************
	 * HELPER FUNCTIONS
	 ******************************************************************************/


	 // allocate and initialize a node object on the free store
	node* construct_node(int value, node* prev = nullptr, node* next = nullptr) {
		return new node{ prev, value, next };
	}

	// return dynamically allocated memory back to free store
	void destruct_node(node* ptr_node) {
		delete ptr_node;
	}

	// return the int value in node 
	int get_value(node const* pn) {
		return pn->value;
	}

	/*******************************************************************************
	 * FUNCTIONS OF A SINGLY-LINKED LIST
	 ******************************************************************************/
	/*
	dllist* construct_list(); // IMPLEMENTED
	void destruct_list(dllist *ptr_dll);
	size_t size(dllist const* ptr_dll);
	void push_front(dllist *ptr_dll, int value); // IMPLEMENTED
	void push_back(dllist *ptr_dll, int value);
	void print(dllist const* ptr_dll); // IMPLEMENTED
	node* find(dllist const* ptr_dll, int value);
	void remove_first(dllist *ptr_dll, int value);
	void insert(dllist *ptr_dll, int value, size_t position);

	*/

	 // allocate and initialize dllist object on free store
	 //DONE
	 /*!************************
  **
  \brief
  This function allocates and initializes a node object on the free store.
  \param value
  data portion 
  \param prev
  pointer to previous node iniitialised to null
  \param next
  pointer to next node initialised to null
  \return 
  new node 
  **************************
  */
	dllist* construct_list() {
		return new dllist{ nullptr, nullptr };
	}

	// delete linked list and then the dllist object
	 /*!************************
  **
  \brief
  This function return dynamically allocated memory back to free store
  \param ptr_node
  pointer pointing to node to be deleted
  \return
  void
  **************************
  */
	void destruct_list(dllist* ptr_dll) {
	if (!ptr_dll) {
	  return;
	}
	node *temp;
	for (node *current = ptr_dll->head; current; current = temp) {
		temp = current->next;
		destruct_node(current);
		current = nullptr;
  	}
	delete ptr_dll;
	ptr_dll = nullptr;
	}
	/*
	void destruct_list(dllist* ptr_dll) {
  		if (!ptr_dll) {
  		  return;
  		}
		node *end = ptr_dll->tail;
		node *temp;
		for (node *current = end; current; current = temp) {
			temp = current->prev;
			delete current;
			current = nullptr;
  		}
	}
	*/
	  /*!************************
  **
  \brief
  This function returns  the count of all elements
  \param ptr_dll
  pointer pointing to list of elements to be counted 
  \return count
  count if all elements
  **************************
  */
	// return the count of elements in linked list
	size_t size(dllist const* ptr_dll) {
		size_t cnt = 0;
		for(node* current = ptr_dll->head;current;current = current->next){
			cnt++;
		}
		return cnt;
	}

	// add element to the front of linked list
	//DONE
	/*!************************
  **
  \brief
  This function adds an element with a specific value at the beginning 
  of the linked list
  \param ptr_dll
  pointer pointing to the list to which an element will be added
  \param value
  value to be added to list
  \return
  void
  **************************
  */
	void push_front(dllist* ptr_dll, int value) {
		if (!ptr_dll)
			return;
		ptr_dll->head = construct_node(value, nullptr, ptr_dll->head);
		node* l_pHead = ptr_dll->head;
		node* l_pNx = l_pHead->next;
		if (l_pNx)
			l_pNx->prev=l_pHead;
		if (!ptr_dll->tail)
			ptr_dll->tail = l_pHead;
	}

	// add element to the back of linked list
	/*!************************
  **
  \brief
  This function adds an element with a specific value at the end 
  of the linked list
  \param ptr_dll
  pointer pointing to the list to which an element will be added 
  \param value
  value to be added to list 
  \return
  void
  **************************
  */
	void push_back(dllist* ptr_dll, int value) {
		if(!ptr_dll){
			return;
		}
		//(value, prev, next)
		node* newLast = construct_node(value, nullptr, nullptr);
		node* last = ptr_dll->tail;
		if(last){
		last->next = newLast;
		newLast->prev = last;
		ptr_dll->tail = newLast;
		}else{
			ptr_dll->head = newLast;
			ptr_dll->tail = newLast;
		}
	}

	// print each element of linked list from front to back
	//DONE
	  /*!************************
  **
  \brief
  This function print each element of linked list from front to back
  \param ptr_dll 
  Pointer pointing to list of elements to be printed 
  \return
  void
  **************************
  */
	void print(dllist const* ptr_dll) {
		node const* head = ptr_dll->head;
		while (head) {
			std::cout << head->value << "    ";
			head = head->next;
		}
		std::cout << "\n";
	}

	
	// find first element in linked list with value specified by 2nd parameter
	 /*!************************
  **
  \brief
  This function finds the  first element in linked list with 
  value specified by 2nd parameter
  \param ptr_dll
  pointer pointing to linked list where specified value will be searched
  \param value
  specific value to match in the list 
  \return 
  first element of linked list that matches the value specified
  **************************
  */
	node* find(dllist* ptr_dll, int value) {
		node* head = ptr_dll->head;
		while(head){
			if(head->value == value){
				return head;
			}
			head = head->next;
		}
		return nullptr;
	}
	
	// insert element with value in 2nd parameter in linked list at
	// index specified by position and
	/*!************************
  **
  \brief
  This function insert elements with value in 2nd parameter in linked list at
  the index specified by position
  \param ptr_dll
  pointer pointing to linked list where specified value will be added into
  a specified position 
  \param value
  value to be added
  \param position
  index of where the value will be added
  \return
  void 
  **************************
  */
	void insert(dllist* ptr_dll, int value, size_t position) {
		if(!ptr_dll) return;
		node* nodeInsert = construct_node(value, nullptr, nullptr);
		node* head = ptr_dll->head;
		size_t count = 0;
		if(!ptr_dll->head){
			push_front(ptr_dll,value);
		}
		while(head){
			if(count==position){
				//std::cout<<"count:"<<count<<" value"<<value<<std::endl;
				if(head->prev){
					nodeInsert->prev = head->prev;
					nodeInsert->next = head;
					head->prev->next = nodeInsert;
					head->prev = nodeInsert;
				}else{
					ptr_dll->head = nodeInsert;
					nodeInsert->next = head;
					head->prev = nodeInsert;
				}
				
				break;
			}
			count++;
			head = head->next;
			if(!head){
				push_back(ptr_dll, value);
			}
		}
	}
	 /*!************************
  **
  \brief
  This function removes the  first element in linked list with value 
  specified in 2nd parameter
  \param ptr_dll
  pointer pointing to linked list where first element matching the specified
  value will be removed 
  \param value
  value to match and remove from linked list 
  \return
  void
  **************************
  */
	// remove first element in linked list with value specified in 2nd parameter
	void remove_first(dllist* ptr_dll, int value) {
	if (!ptr_dll->head) return;
	for (node* head = ptr_dll->head; head; head = head->next) {
		if (head->value == value) {
			if (head->prev) head->prev->next = head->next;
			if (head->next) head->next->prev = head->prev;
			if (ptr_dll->head == head) ptr_dll->head = head->next;
			delete head;
			break;
		}
	}
}
	
	/*
	void remove_first(dllist* ptr_dll, int value) {
		if(!ptr_dll->head) return;
		if(ptr_dll->head->prev == nullptr){
			node* temp = ptr_dll->head->next;
			delete ptr_dll->head;
			ptr_dll->head = temp;
			ptr_dll->head->prev = nullptr;
		}
		for(node* head = ptr_dll->head;head;head = head->next){
			if(head->value == value){
				node* temp = head;
				head->prev->next = temp->next;
				head->next->prev = temp->prev;
				delete head;
				break;
			}
		}
	}
	*/
	
} // end namespace hlp2