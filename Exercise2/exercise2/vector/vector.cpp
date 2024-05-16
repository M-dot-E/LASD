
#include <stdexcept>
#include <string>
namespace lasd {

/* ************************************************************************** */
template<typename Data>
Vector<Data>::Vector( const unsigned long newsize ){
    elements = new Data[newsize];
    size = newsize;
}

template<typename Data>
Vector<Data>::Vector(const Vector<Data>& vec){
    elements = new Data[vec.size];
    std::copy(vec.elements , vec.elements + vec.size, elements);
    size = vec.size;
}

template<typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>& con) : Vector(con.Size()){
    unsigned long index = 0;
    con.Traverse(
        [this , &index](const Data& dat){
        elements[index++] = dat;
    }
    );
}

template<typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& con) : Vector(con.Size()){
    unsigned long index = 0;
    con.Map(
        [this , &index](Data& dat){
        elements[index++] = std::move(dat);
    }
    );
}

template<typename Data>
Vector<Data>::Vector(Vector<Data>&& vec) noexcept{
    std::swap(elements , vec.elements);
    std::swap(size , vec.size);
}

template<typename Data>
Vector<Data>::~Vector(){
    delete[] elements;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec){
    Vector<Data>* tempvec = new Vector<Data>(vec);
    std::swap(*tempvec , *this);
    delete tempvec;
    return *this;
}

template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept{
    std::swap(elements , vec.elements);
    std::swap(size , vec.size);
    return * this;
}

template<typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept{
    if(size == vec.size){
        for(unsigned long index = 0;index < size;index++){
            if(elements[index] != vec.elements[index]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}
template<typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& vec) const noexcept{
    return !(*this == vec);
}


template<typename Data>
void Vector<Data>::Clear(){
    delete[] elements;
    elements = nullptr;
    size = 0;
}

template<typename Data>
void Vector<Data>::Resize(const unsigned long newsize){
    if(newsize == 0){
        Clear();
    }
    else if(size != newsize){
        unsigned limit=(size < newsize) ? size : newsize;
        Data* tmpelements = new Data[newsize];
        for(unsigned long i  = 0; i < limit; i++){
            std::swap(elements[i] , tmpelements[i]);
        }
        std::swap(elements , tmpelements);
        size = newsize;
        delete[] tmpelements;
    }
}

template<typename Data>
const Data& Vector<Data>::operator[](const unsigned long index) const{
    if( index < size ){
        return elements[index];
    }
    else{
        throw std::out_of_range("Access at index" + std::to_string(index) + "vector size is" + std::to_string(size));
    }
}

template<typename Data>
Data& Vector<Data>::operator[](const unsigned long index){
    if( index < size ){
        return elements[index];
    }
    else{
        throw std::out_of_range("Access at index" + std::to_string(index) + "vector size is" + std::to_string(size));
    }
}

template<typename Data>
const Data& Vector<Data>::Front() const{
    if(size != 0){
        return elements[0];
    }
    else{
        throw std::length_error("Accessing an empty vector its forbidden");
        }
}

template<typename Data>
Data& Vector<Data>::Front(){
    if(size != 0){
        return elements[0];
    }
    else{
        throw std::length_error("Accessing an empty vector its forbidden");
        }
}

template<typename Data>
const Data& Vector<Data>::Back() const{
    if(size != 0){
        return elements[size-1];
    }
    else{
        throw std::length_error("Accessing an empty vector its forbidden");
        }
}

template<typename Data>
 Data& Vector<Data>::Back(){
    if(size != 0){
        return elements[size-1];
    }
    else{
        throw std::length_error("Accessing an empty vector its forbidden");
        }
}

template<typename Data>
SortableVector<Data>::SortableVector(const unsigned long newsize) : Vector<Data>(newsize){}

template<typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& con) : Vector<Data>(con){}

template<typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& con) : Vector<Data>(std::move(con)){}

//copy constructor sortable vector
template<typename Data>
SortableVector<Data>::SortableVector(const SortableVector<Data> & vec) : Vector<Data>(vec){}

//move constructor sortable vector
template<typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data> && vec) noexcept : Vector<Data>(std::move(vec)){}

// copy assignment sortable vector
template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& vec){
    Vector<Data>::operator=(vec);
    return *this;
}

// move assignment sortable vector

template<typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data>&& vec) noexcept{
    Vector<Data>::operator=(std::move(vec));
    return *this;
}


/* ************************************************************************** */

}