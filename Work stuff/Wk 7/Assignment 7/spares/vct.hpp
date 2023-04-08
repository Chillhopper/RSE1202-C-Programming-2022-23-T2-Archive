// make sure to have a file-level Doxygen documentation block AND
// function-level documentation block for each function that your
// client will be using!!!
/*!*****************************************************************************
\file       vector.hpp
\author     
\par        
\par        Course: HLP2
\par        Section: student - A
\par        Assignment 6
\date       
\brief
  build my own version of std::vector. Functions are:
 - reserve
	   function that will be used by both clients and other functions to add memory for new elements.
 - resize
	   resizes the container so that it contains n elements. 
 - push_back
     pushes back memory block.
 - empty
     check if container is empty.
 - size
     returns sz.
 - capacity
     returns space.
 - allocations
     returns allocs.
*******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR_HPP
#define VECTOR_HPP
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>          // need this for size_t
#include <initializer_list> // need this for std::initializer_list<int>
 
namespace hlp2 {
	
class vector {
public:
  // @todo: using declarations required!!!
  // types to declare: size_type, value_type,
  // reference, const_reference, pointer, const_pointer
  using size_type = size_t;
  using value_type = int;
  using pointer = value_type*;
  using const_pointer = value_type const*;
  using reference = value_type&;
  using const_reference = value_type const&;

public:
  public:
  vector(){sz=0; space = 0; allocs = 0; data = nullptr;} // default ctor
  explicit vector(size_type n); // non-default ctor

  vector(std::initializer_list<int> rhs){
    for(int value : rhs){
        this->push_back(value);
    }
  }; // non-default ctor
  vector(vector const& rhs){
    this->sz = rhs.sz;
    this->space = rhs.space;
    this->allocs = rhs.allocs;

    for(size_type i = 0; i<sz; i++){
        data[i] = rhs[i];
    }
  } // copy ctor
  ~vector(){if(this->data) delete[] this->data;}
  vector& operator=(vector const&);
  vector& operator=(std::initializer_list<int> rhs);
  reference operator[](size_type index);
  const_reference operator[](size_type index) const;
  /*!*****************************************************************************
	\brief
	  function that will be used by both clients and other functions to add memory for new elements.
	\param n
	  n is the size of memory to be added.
	\return
	  void
	*******************************************************************************/
  void reserve(size_type n){
        
  }
  /*!*****************************************************************************
	\brief
	  resizes the container so that it contains n elements.
	\param n
	  n is the elements to resize container.
	\return
	  void
	*******************************************************************************/
  void resize(size_type n){
    this->data = new (value_type[n + this->size()]); //reallocates this much more data
    allocs++;
  }
  /*!*****************************************************************************
	\brief
	  pushes back memory block.
	\param val
	  values to be pushed back.
	\return
	  void
	*******************************************************************************/
  void push_back(value_type val){
    (this->data)[sz] = val;
    /*
    if(this->size()!=0){
        data[this->size() - 1u] = val;
        sz++;
    }*/
  }
  /*!*****************************************************************************
	\brief
	  check if container is empty.
	\return
	  bool
	*******************************************************************************/
  bool empty() const{
    if(sz == 0){
        return true;
    }
    return false;
  } // is container empty?
  /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
  size_type size() const{
     return sz;
  } // what is sz?
  /*!*****************************************************************************
	\brief
	  returns space.
	\return
	  size_type
	*******************************************************************************/
  size_type capacity() const{
    return (size_type)(sizeof(data)/sizeof(value_type)); //return number of elements
  } // what is space?
  /*!*****************************************************************************
	\brief
	  returns allocs.
	\return
	  size_type
	*******************************************************************************/
  size_type allocations() const{
    return allocs;
  } // how many allocations or "growths"?
  // iterators ...
  pointer begin(){
    return data;
  } // pointer to first element
  pointer end(){
    return (data+sz);
  } // pointer to one past last element

  const_pointer begin() const{
    return (const_pointer)data;
  };
  const_pointer end() const{
    return (const_pointer(data+sz));
  }
  const_pointer cbegin() const{
    return (data + sz);
  };
  const_pointer cend() const{
    return (data + sz);
  }

  // @todo: declare iterators [described in spec]

private:
  size_type sz;     // the number of elements in the array
  size_type space;  // the allocated size (in terms of elements) of the array
  size_type allocs; // number of times space has been updated
  pointer   data;   // the dynamically allocated array

};

} // namespace hlp2

#endif // VECTOR_HPP