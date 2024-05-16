
#include <stdexcept>

namespace lasd {

/* ************************************************************************** */

template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stk) : Vector<Data>(stk){ index = stk.index; }

template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stk) noexcept : Vector<Data>(std::move(stk)){ std::swap(index , stk.index); }


template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stk){
    Vector<Data>::operator=(stk);
    index = stk.index;
    return *this;
}

template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stk) noexcept{
    Vector<Data>::operator=(std::move(stk));
    std::swap(index , stk.index);
    return *this;
}

template<typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stk) const noexcept{
    if(index == stk.index){
        for(unsigned long idx = 0; idx < index; ++idx){
            if(elements[idx] != stk.elements[idx]){
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
bool StackVec<Data>::operator!=(const StackVec<Data>& stk) const noexcept{
    return !(*this == stk);
}

template<typename Data>
const Data& StackVec<Data>::Top() const{
    if(index != 0){
        return elements[index - 1];
    }
    else{
        throw std::length_error("Access to an empty stack");
    }
}

template<typename Data>
Data& StackVec<Data>::Top() {
    if(index != 0){
        return elements[index - 1];
    }
    else{
        throw std::length_error("Access to an empty stack");
    }
}

template<typename Data>
void StackVec<Data>::Pop() {
    if(index != 0){
        Reduce();
        --index;
    }
    else{
        throw std::length_error("Access to an empty stack");
    }
}

template<typename Data>
Data StackVec<Data>::TopNPop() {
    if(index != 0){
        Reduce();
        return std::move(elements[--index]);
    }
    else{
        throw std::length_error("Access to an empty stack");
    }
}

template<typename Data>
void StackVec<Data>::Push(const Data& dat){
    Expand();
    elements[index++] = dat;
}

template<typename Data>
void StackVec<Data>::Push(Data&& dat){
    Expand();
    elements[index++] = std::move(dat);
}

template<typename Data>
inline bool StackVec<Data>::Empty() const noexcept{
    return (index == 0);
}

template<typename Data>
inline unsigned long StackVec<Data>::Size() const noexcept{
    return index;
}

template<typename Data>
void StackVec<Data>::Clear(){
    index = 0;
    Vector<Data>::Resize(1);
}

template<typename Data>
void StackVec<Data>::Expand(){
    if(index == size){
        Vector<Data>::Resize(size * 2);
    }
}

template<typename Data>
void StackVec<Data>::Reduce(){
    if(index == size / 4){
        Vector<Data>::Resize(size / 2);
    }
}
// ...

/* ************************************************************************** */

}