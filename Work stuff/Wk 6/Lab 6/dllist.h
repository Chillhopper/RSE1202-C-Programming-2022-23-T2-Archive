/*!************************
**
\file dllist.h
\author Kaushik Thirumavalavan
\par DP email: 2200927@sit.singaporetech.edu.sg
\par Course: RSE 1201 
\par Programming Lab #7
\date 23-02-2023
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
namespace hlp2{

/*******************************************************************************
	 * DATA TYPES
	 ******************************************************************************/

	template<typename T>struct node {
		node* prev; // pointer to previous node
		T value;  // data portion
		node* next; // pointer to next node
	};

	template<typename T>struct dllist {
		node<T> *head, *tail;
	};

    /*******************************************************************************
	 * HELPER FUNCTIONS
	 ******************************************************************************/


	 // allocate and initialize a node object on the free store
	 template<typename T> node<T>* construct_node(T value, node<T>* prev = nullptr, node<T>* next = nullptr) {
		return new node<T>{ prev, value, next };
	}

	// return dynamically allocated memory back to free store
	template<typename T> void destruct_node(node<T>* ptr_node) {
		delete ptr_node;
	}

	// return the int value in node 
	template<typename T> T get_value(node<T> const* pn) {
		return pn->value;
	}

    /*******************************************************************************
	 * REAL ASS FUNCTIONS LA GANG SHIT RIP XXX TENTACION
	 ******************************************************************************/

     template<typename T>dllist<T>* construct_list() {
		return new dllist<T>{ nullptr, nullptr };
	}


    template<typename T> void destruct_list(dllist<T>* ptr_dll) {
	if (!ptr_dll) {
	  return;
	}
	node<T> *temp;
	for (node<T> *current = ptr_dll->head; current; current = temp) {
		temp = current->next;
		destruct_node(current);
		current = nullptr;
  	}
	delete ptr_dll;
	ptr_dll = nullptr;
	}

    template<typename T>size_t size(dllist<T> const* ptr_dll) {
		size_t cnt = 0;
		for(node<T>* current = ptr_dll->head;current;current = current->next){
			cnt++;
		}
		return cnt;
	}

    template<typename T>void push_front(dllist<T>* ptr_dll, T value) {
		if (!ptr_dll)
			return;
		ptr_dll->head = construct_node<T>(value, nullptr, ptr_dll->head);
		node<T>* l_pHead = ptr_dll->head;
		node<T>* l_pNx = l_pHead->next;
		if (l_pNx)
			l_pNx->prev=l_pHead;
		if (!ptr_dll->tail)
			ptr_dll->tail = l_pHead;
	}

    template<typename T>void push_back(dllist<T>* ptr_dll, T value) {
		if(!ptr_dll){
			return;
		}
		//(value, prev, next)
		node<T>* newLast = construct_node<T>(value, nullptr, nullptr);
		node<T>* last = ptr_dll->tail;
		if(last){
		last->next = newLast;
		newLast->prev = last;
		ptr_dll->tail = newLast;
		}else{
			ptr_dll->head = newLast;
			ptr_dll->tail = newLast;
		}
	}

    template<typename T>void print(dllist<T> const* ptr_dll) {
		node<T> const* head = ptr_dll->head;
		while (head) {
			std::cout << head->value << "    ";
			head = head->next;
		}
		std::cout << "\n";
	}

    template<typename T>node<T>* find(dllist<T>* ptr_dll, int value) {
		node<T>* head = ptr_dll->head;
		while(head){
			if(head->value == value){
				return head;
			}
			head = head->next;
		}
		return nullptr;
	}

    template<typename T>void insert(dllist<T>* ptr_dll, T value, size_t position) {
		if(!ptr_dll) return;
		node<T>* nodeInsert = construct_node<T>(value, nullptr, nullptr);
		node<T>* head = ptr_dll->head;
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

    template<typename T>void remove_first(dllist<T>* ptr_dll, int value) {
        if (!ptr_dll->head) return;
        for (node<T>* head = ptr_dll->head; head; head = head->next) {
            if (head->value == value) {
			if (head->prev) head->prev->next = head->next;
			if (head->next) head->next->prev = head->prev;
			if (ptr_dll->head == head) ptr_dll->head = head->next;
			delete head;
			break;
		}
	}
}


}