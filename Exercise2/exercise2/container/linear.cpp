
#include <stdexcept>
namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun fun)const{
    PreOrderTraverse(fun);
}

template<typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun)const{
    for(unsigned long index = 0; index < size; index++){
        fun(operator[](index));
    }
}

template<typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun)const{
    unsigned long index = size;
    while(index > 0){
        fun(operator[](--index));
    }
}

template<typename Data>
inline void LinearContainer<Data>::Map(MapFun fun){
    PreOrderMap(fun);
}

template<typename Data>
inline void LinearContainer<Data>::PreOrderMap(MapFun fun){
    for(unsigned long index = 0; index < size; index++){
        fun(operator[](index));
    }
}

template<typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFun fun){
    unsigned long index = size;
    while(index > 0){
        fun(operator[](--index));
    }
}

template<typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer<Data>& lc) const noexcept{
    if(size == lc.size){
        for(unsigned long index = 0; index < size; index++){
            if(operator[](index) != lc[index]){
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
inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& lc) const noexcept{
    return !(*this == lc);
}

template<typename Data>
const Data& LinearContainer<Data>::Front() const{
    if(size != 0){
        return operator[](0);
    }
    else{
        throw std::length_error("accessing an empty container it's forbidden");
    }
}

template<typename Data>
Data& LinearContainer<Data>::Front() {
    if(size != 0){
        return operator[](0);
    }
    else{
        throw std::length_error("accessing an empty container it's forbidden");
    }
}

template<typename Data>
const Data& LinearContainer<Data>::Back() const{
    if(size != 0){
        return operator[](size-1);
    }
    else{
        throw std::length_error("accessing an empty container it's forbidden");
    }
}

template<typename Data>
Data& LinearContainer<Data>::Back() {
    if(size != 0){
        return operator[](size-1);
    }
    else{
        throw std::length_error("accessing an empty container it's forbidden");
    }

}



template<typename Data>
void SortableLinearContainer<Data>::Sort() noexcept{
    QuickSort(0 , size - 1);
}

template<typename Data>
void SortableLinearContainer<Data>::QuickSort(unsigned long p , unsigned long r) noexcept{
    if(p < r){
        unsigned long q = Partition(p , r);
        QuickSort(p , q);
        QuickSort(q + 1 , r);
    }
}

template<typename Data>
unsigned long SortableLinearContainer<Data>::Partition(unsigned long p, unsigned long r)noexcept{
    Data x = operator[](p);
    unsigned long i = p - 1;
    unsigned long j = r + 1;
    do{
        do{ j--; }
        while(x < operator[](j));
        do{ i++; }
        while(x > operator[](i));
        if(i < j){ std::swap(operator[](i), operator[](j)); }
    }
    while( i < j );
    return j;
}

// ...

/* ************************************************************************** */

}