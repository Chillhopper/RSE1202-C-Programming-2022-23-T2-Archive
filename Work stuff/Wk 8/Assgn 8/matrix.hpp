// provide file header documentation block and function header documentation
// block for each member/non-member function

// note: all functions MUST be defined outside the class definition!!!
#include <iostream>
#include <vector>
namespace hlp2{


template <typename T>
class matrix {
public:
matrix(int rows, int cols);

T& operator[](int);
std::vector<T>& matrix<T>::operator[](int);
//T& operator[](int,int);
bool operator==(const matrix)const;
bool  operator!=(const matrix obj2)const;


//?????? weird syntax!
template <typename U>
friend std::ostream operator<<(std::ostream os, matrix<U> obj);


//accessor functions
int Rows(){
    return rowies;
}

int Cols(){
    return collies;
}
private:
int rowies;
int collies;
int size;
std::vector<std::vector<T>>arr;
//T* arr; //vector
};

template <typename T>
matrix<T>::matrix(int rows, int cols):rowies(rows), collies(cols){
    arr(rowies, std::vector<T>(collies));
    /*
    arr = new T[size];
    size = rowies*collies;
    */
}

template <typename T>
std::vector<T>& matrix<T>::operator[](int index){
    if (index < 0 || index >= size) {throw std::out_of_range("Index out of bounds");}
    //T& ref = arr[index];//return inner vector
    std::vector<T>& vect = arr[index];//return inner vector
    
    return vect;
}

template <typename T>
T& matrix<T>::operator[](int index){
    if (index < 0 || index >= size) {throw std::out_of_range("Index out of bounds");}
    T& ref = arr[index];//return value
    
    return ref;
}


/*
template <typename T>
T& matrix<T>::operator[](int index1, int index2){
    //if (index < 0 || index >= size) {throw std::out_of_range("Index out of bounds");}
    int index = index1 * collies + index2;
    T& ref = arr[index];
    return ref;
}
*/

template <typename T>
bool matrix<T>::operator==(const matrix obj2)const{
    if(rowies != obj2.rowies || collies != obj2.collies || size != obj2.size){return false;}
    //Time for the witch trials to begin, are these matrixes really the same?
    //a series of 1820's witching hunting rituals are invoked.
    // will the witch escape with a true? or die with a false?
    for(int i = 0;i<rowies;i++){
        for(int j = 0;j<collies;j++){
            if(arr[i * collies + j] != obj2.arr[i * collies + j]){
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool  matrix<T>::operator!=(const matrix obj2)const{
    return !(*this == obj2);
}

/*In this case, the left-hand side object is the output stream ostream itself, 
and the right-hand side argument is the object you want to output. 
So the ostream& is the left-hand side, and the object being output is the right-hand side. 
This is why the ostream is passed as the first argument to the operator<< overload.*/
template <typename T>
std::ostream operator<<(std::ostream os, matrix<T> obj){
    for(int i = 0;i<obj.rowies;i++){
        for(int j = 0;j<obj.collies;j++){
            os<<obj.arr[i][j];

        }
        os<<"\n";
    }
    return os;
}

}