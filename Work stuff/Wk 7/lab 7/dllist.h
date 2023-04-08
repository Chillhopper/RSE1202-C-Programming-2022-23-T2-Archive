namespace hlp2 {
  template <typename T>
  class dllist{
  public:
    template <typename U>
    struct node
    {
      node* prev;
      U value;  // data portion
      node* next;
    };
        
    dllist();
        
        // Copy ctor
        dllist(dllist<T> const&);
        
    ~dllist();
        
        // Copy assignment operator
        dllist<T>& operator=(dllist<T> const&);

    // Return the count of elements 
    size_t size() const;

    // Add a new value to the beginning 
    void push_front(T value);

        // Remove the front node
    void pop_front();


    // Add a new value to the end
    void push_back(T value);

    // Print the contents 
    void print() const;

    // Find first occurrence 
    node<T>* find(T value) const;

    // Insert value in linked list at index.
    // Assume zero-based indexing with 1st element at index 0, the second element
    // at index 1, and so on. If list has 4 elements, their indices range from
    // 0 to 3. Then a call to insert() with index 4 would insert value as last
    // element of list. In the same example, if index is 10, then the value is
    // inserted at index 4. 
    void insert(T value, T position);

    // Remove the first element in list with value
      void remove_first(T value);
        
    // Remaining functions to be declared

  private:
    node<T>* head;
    node<T>* tail;
  };
    template<typename T>
  dllist<T>::dllist() :head(nullptr),tail(nullptr) {}

  template<typename T>
  dllist<T>::dllist(dllist<T> const&other):head(nullptr), tail(nullptr){
    if(other.head==nullptr){
      return;
    }
    node<T> const* current=other.head;
    while(current!=nullptr){
      push_back(current->value);
      current=current->next;
    }
  }

    template<typename T>    
  dllist<T>::~dllist(){
    node<T>* current = head;
    while (current != nullptr) {
      node<T>* next = current->next;
      delete current;
      current = next;
    }
    head = nullptr;
    tail = nullptr;
  }

    template<typename T>
  dllist<T>& dllist<T>::operator=(dllist<T> const& rhs){
    if (this != &rhs) {
      node<T>* curr = head;
      while (curr != nullptr) {
        node<T>* temp = curr;
        curr = curr->next;
        delete temp;
      }
      head = tail = nullptr;
      node<T>* other_curr = rhs.head;
      while (other_curr != nullptr) {
        push_back(other_curr->value);
        other_curr = other_curr->next;
      }
    }
    return *this;
  }

  template<typename T>
  size_t dllist<T>::size() const{
    size_t count = 0;
    node<T>* current = head;
    while (current != nullptr) {
      count++;
      current = current->next;
    }
    return count;
  }

  template<typename T>
  void dllist<T>:: push_front(T value){
    node<T>* newNode = new node<T>{ nullptr, value, nullptr };
    if (!head) {
      head = tail = newNode;
    }
    else {
      head->prev = newNode;
      newNode->next = head;
      head = newNode;
    }
  }

  template<typename T>
  void dllist<T>:: pop_front(){
    if (head == nullptr) {
      return;
    }
    else if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
    }
    else {
      node<T>* new_head = head->next;
      delete head;
      head = new_head;
      head->prev = nullptr;
    }
  }

  template<typename T>
  void dllist<T>:: push_back(T value){
    node<T>* new_node = new node<T>{ tail, value, nullptr };
    if (tail != nullptr) {
      tail->next = new_node;
    }
    else {
      head = new_node;
    }
    tail = new_node;
  }

  template<typename T>
  void dllist<T>:: print() const{
    node<T> const* l_pCur = head;
    while (l_pCur) {
      std::cout << l_pCur->value << "    ";
      l_pCur = l_pCur->next;
    }
    std::cout << "\n";
  }

  template<typename T>
  dllist<T>::node<T>* dllist<T>::find(T value) const{
    node<T>* current = head;
    while (current != nullptr) {
      if (current->value == value) {
        return current;
      }
      current = current->next;
    }
    return nullptr;
  }

template<typename T>
  void dllist<T>:: insert(T value, T position){
    if (head == nullptr) {
    push_front(value);    
    return;
    }
    else if (position == 0) {
      push_front(value);
      return;
    }
    node<T>* current = head;
    for (size_t i = 0; i < position - 1; i++) {
      if (current->next == nullptr) {
        push_back(value);
        // return
        return;
      }
      current = current->next;
    }
    node<T>* newNode = new node<T>{ current, value, current->next };
    current->next = newNode;
    if (newNode->next != nullptr) {
      newNode->next->prev = newNode;
    }
    else {
      tail = newNode;
    }
  }

  template<typename T>
  void dllist<T>:: remove_first(T value){
    if (head == nullptr) {
      return;
    }
    if (head->value == value) {
      pop_front();
      return;
    }
    node<T>* current = head;
    while (current->next != nullptr) {
      if (current->next->value == value) {
        node<T>* temp = current->next;
        current->next = current->next->next;
        if (current->next != nullptr) {
          current->next->prev = current;
        }
        else {
          tail = current;
        }
        delete temp;
        return;
      }
      current = current->next;
    }
  }
}
