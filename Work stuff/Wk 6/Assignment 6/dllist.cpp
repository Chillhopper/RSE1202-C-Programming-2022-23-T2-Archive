#include <iostream>
#include <iomanip>
#include "dllist.h"

namespace hlp2 {

	dllist::dllist(): head(nullptr), tail(nullptr) {}

	//copy constructor
	dllist::dllist(dllist const& list){
		node* objNode = list.head;
		while(objNode){
			this->push_back(objNode->value);
			objNode = objNode->next;
		}
	}

	dllist::~dllist(){
		node* cleanse = head;
		while(cleanse!=nullptr){
			node* temp = cleanse->next;
			delete cleanse;
			cleanse = temp;
		}
		head = nullptr;
		tail = nullptr;
	}

// Copy assignment
//copy obj to current list
		dllist& dllist::operator=(dllist const& other)
	{
		
		if (this != &other) {
			
			node* curr = head;
			
			while (curr != nullptr) {
				
				node* temp = curr;
				
				curr = curr->next;
				
				delete temp;
			}
			
			head = tail = nullptr;

			
			node* other_curr = other.head;
			
			while (other_curr != nullptr) {
				
				push_back(other_curr->value);
				
				other_curr = other_curr->next;
			}
		}
		
		return *this;
	}
	/*
	dllist& dllist::operator=(dllist const& obj){
		//the cleansing
		node* cleanse = head;
		while(cleanse!=nullptr){
			node* temp = cleanse->next;
			delete cleanse;
			cleanse = temp;
		}
		head = nullptr; tail = nullptr;
	//curr is from obj to cycle through obj, created because you cant edit a const
	//thisthis is "this" but in a more versatile form to traverse this nodes
		node* thisthis = this->head;
		for(node* curr = obj.head;curr!=nullptr;){
			node* newNode = new node;
			newNode->value = curr->value;

			if (curr->next != nullptr) {
				newNode->next = curr->next;
				newNode->next->prev = newNode;
				} else {
				newNode->next = nullptr;
				tail = newNode;
			}
			if (curr->prev != nullptr) {
				newNode->prev = curr->prev;
				newNode->prev->next = newNode;
				} else {
				newNode->prev = nullptr;
				head = newNode;
			}

			thisthis = newNode;
			curr = curr->next;
			thisthis = thisthis->next;
			
		}
		this->tail = obj.tail;
		return *this;
	}
	*/
	// If data is the same and in the same order, return true
	bool operator==(dllist const& obj1, dllist const& obj2){
		dllist::node* addy1 = obj1.head; dllist::node* addy2 = obj2.head;

		if(obj1.size() == obj2.size()){
			for(;addy1!=nullptr;){
				if(addy1->value != addy2->value){return false;}
				if(addy1->next&&addy2->next){
				addy1 = addy1->next;
				addy2 = addy2->next;
				}else if(addy1->next||addy2->next){
					return false;
				}else if(!(addy1->next) && !(addy2->next)){
					return true;
				}
			}
		}else{
			return false;
		}
		return true;
	}

	// Add the data of the right dllist to the end of the left dllist, preserving the 
	// order of the data

	dllist operator+(dllist const& lhs, dllist const& rhs) {
		
		dllist result = lhs;
		
		dllist::node const* current = rhs.head;
		
		while (current != nullptr) {
			
			result.push_back(current->value);
			
			current = current->next;
		}
		
		return result;
	}
/*	
	dllist operator+(dllist const& obj1, dllist const& obj2){
		dllist holder = obj1;
		//dllist::node* holdNode = holder.head;
		//dllist::node* addy1 = obj1.head;
		dllist::node* addy2 = obj2.head;
		holder = obj1; //operator overload makes this possible
		while(addy2){
			holder.push_back(addy2->value); //doesnt account last node
			addy2 = addy2->next;
		}
		//for last node
		//addy2 = addy2->next;
		if(addy2){holder.push_back(addy2->value);}
		return holder;
	}
*/
	// Add the data of the right dllist to the end of this dllist, preserving the 
	// order of the data and returning a reference to self
	dllist& dllist::operator+=(dllist const& obj2){
		dllist& self = *this;
		self = (self + obj2);
		
		return self;
	}

	// Return a dllist with data in same order but negated
	dllist const dllist::operator-()const{
		dllist returnlist;
		for(node* curr = head; curr!=nullptr; curr = curr->next){
			//node* newNode = new node;
			returnlist.push_back(-(curr->value));

		}
		return returnlist;
	}

	// Pop back node and return reference to self
	dllist& dllist::operator--(){
		node* newtail = tail->prev;
		newtail->next = nullptr;
		delete tail;
		tail = newtail;

		return *this;

	}

	// Copy self, pop back node, and return copy
	dllist const dllist::operator--(int){
		dllist copy = *this;
		node* newtail = copy.tail;
		newtail->next = nullptr;
		delete tail;
		tail = newtail;
		return copy;
	}

	// Return data of node using input parameter as index where 0 is the head
	int& dllist::operator[](size_t index){
		node* curr = head;

			for(size_t i = 0; i < index ;i++){
				curr = curr->next;
			}
		return curr->value;
		
	}

	int const& dllist::operator[](size_t index)const{
			node* curr = head;
			for(size_t i = 0; i < index ;i++){
				curr = curr->next;
			}
		return (curr->value);
	}

	// Print using print()
	std::ostream& operator<<(std::ostream& stream, dllist const& list){
		list.print();
		return stream;
	}

	size_t dllist::size() const{
		size_t cnt = 0;
		if(head == nullptr){
			return 0u;
		}
		node* curr = (node*)head;
		while(curr!=nullptr){
			curr = curr->next;
			cnt++;
		}
		return cnt;
	}

// Add a new value to the beginning 
	void dllist::push_front(int value){
		node* newNode = new node;
		newNode->value = value;
		newNode->next = head;
		if(head!=nullptr){
		head->prev = newNode;
		}
		head = newNode;
	}

	// Remove the front node
	void dllist::pop_front(){
		node* curr = head->next;
		delete head;
		head = curr;
		
	}

	// Add a new value to the end
		

		void hlp2::dllist::push_back(int value) {
		
		node* new_node = new node{ tail, value, nullptr };
		
		if (tail != nullptr) {
			
			tail->next = new_node;
		}
		else {
			
			head = new_node;
		}
		
		tail = new_node;
	}
	/*
	void dllist::push_back(int value){
		node* newNode = new node;
		newNode->value = value;
		newNode->prev = tail;
		newNode->next = nullptr;
		//tail is nullptr when list is empty
		if(tail == nullptr){
			head = newNode;
		}else{
		tail->next = newNode;
		}
		tail = newNode;
	}
	*/
	
void dllist::remove_first(int value) {
		
		if (head == nullptr) {
			return;
		}
		if (head->value == value) {
			pop_front();
			return;
		}
		node* current = head;
		while (current->next != nullptr) {
			if (current->next->value == value) {	
				node* temp = current->next;	
				current->next = current->next->next;
				if (current->next != nullptr) {	
					current->next->prev = current;
				}else {		
					tail = current;
				}
				delete temp;
				return;
			}
			current = current->next;
		}
	}

void dllist::insert(int value, size_t position) {
		
		if (head == nullptr) {
			push_front(value);
			
			return;
		}
		
		else if (position == 0) {
			push_front(value);
			
			return;
		}
		
		node* current = head;
		
		for (size_t i = 0; i < position - 1; i++) {
			
			if (current->next == nullptr) {
				push_back(value);
				// return
				return;
			}
			
			current = current->next;
		}
		
		node* newNode = new node{ current, value, current->next };
		
		current->next = newNode;
		
		if (newNode->next != nullptr) {
			
			newNode->next->prev = newNode;
		}
		else {
			
			tail = newNode;
		}
	}
	
	bool operator!=(dllist const& lhs, dllist const& rhs)
	{
		
		return !(lhs == rhs); 
	}


		hlp2::dllist::node* hlp2::dllist::find(int value) const {
		
		node* current = head;
		
		while (current != nullptr) {
			
			if (current->value == value) {
				return current;
			}
			
			current = current->next;
		}
		
		return nullptr;
	}


	void dllist::print() const
	{
		node const* l_pCur = head;
		while (l_pCur) {
			std::cout << l_pCur->value << "    ";
			l_pCur = l_pCur->next;
		}
		std::cout << "\n";
	}

	//TODO: Rest of the member functions

} // end namespace hlp2