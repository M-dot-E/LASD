
#include <stdexcept>
namespace lasd {

/* ************************************************************************** */

template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data>& con) : Vector<Data>(con) {
    head = 0;
    tail = con.Size(); 
    Vector<Data>::Resize(size * 2);
}


template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data>&& con) : Vector<Data>(std::move(con)) {
    head = 0;
    tail = con.Size(); 
    Vector<Data>::Resize(size * 2);
}

template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec & q) : Vector<Data>(q){
    head = q.head;
    tail = q.tail;
}

template<typename Data>
QueueVec<Data>::QueueVec(QueueVec && q) noexcept : Vector<Data>(std::move(q)){
    std::swap(head , q.head);
    std::swap(tail , q.tail);
}


template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& q){
    Vector<Data>::operator=(q);
    head = q.head;
    tail = q.tail;
    return *this;
}

template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& q)noexcept{
    Vector<Data>::operator=(std::move(q));
    std::swap(head , q.head);
    std::swap(tail , q.tail);
    return *this;
}

template<typename Data>
bool QueueVec<Data>::operator==(const QueueVec& q) const noexcept{

    if (Empty() && q.Empty()) {
    return true;
    }
    if(Size() != q.Size()){
        return false;
    }
    unsigned long this_head = head;
    unsigned long q_head = q.head;

    for(unsigned long index = 0; index < Size(); index++){
        if(elements[this_head] != q.elements[q_head]){
            return false;
        }
        this_head = (this_head + 1) % size;
        q_head = (q_head + 1) % q.size;
    }
    return true;
}

template<typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& q) const noexcept{
    return !(*this == q);
}

template<typename Data>
const Data & QueueVec<Data>::Head() const{
    if( head != tail){
        return elements[head];
    }
    else{
        throw std::length_error("Access to an empty queue");
    }
}

template<typename Data>
Data & QueueVec<Data>::Head(){
    if( head != tail){
        return elements[head];
    }
    else{
        throw std::length_error("Access to an empty queue");
    }
}

template<typename Data>
void QueueVec<Data>::Dequeue(){
    if( head != tail ){
        Reduce();
       head = head+1%size;
    }
    else{
        throw std::length_error("access to an empty queue");
    }
}

template<typename Data>
Data QueueVec<Data>::HeadNDequeue(){
    if( head != tail ){
        Reduce();
        Data dat(std::move(elements[head]));
        head = head+1%size;
        return dat;
    }
    else{
        throw std::length_error("access to an empty queue");
    }
}

template<typename Data>
void QueueVec<Data>::Enqueue(const Data& dat){
    Expand();
    elements[tail++] = dat;
    tail %= size;
}

template<typename Data>
void QueueVec<Data>::Enqueue(Data&& dat){
    Expand();
    elements[tail++] = std::move(dat);
    tail %= size;
}

template<typename Data>
inline bool QueueVec<Data>::Empty() const noexcept{
    return (head == tail);
}

template<typename Data>
inline unsigned long QueueVec<Data>::Size() const noexcept{
    return (((size + tail) - head) % size);
}

template<typename Data>
void QueueVec<Data>::Clear(){
    head = tail = 0;
    Vector<Data>::Resize(4);
}

template<typename Data>
void QueueVec<Data>::Expand(){
    unsigned long num = Size();
    if( num + 1 == size ){
        Resize( size *2 , num);
    }
}

template<typename Data>
void QueueVec<Data>::Reduce(){
    unsigned long num = Size();
    if( num + 1 == size /4 ){
        Resize( size /2 , num);
    }
}

template<typename Data>
void QueueVec<Data>::Resize(unsigned long newsize , unsigned long num){
    Data * tmpElements = new Data[newsize];
    unsigned long max = ( num <= newsize ) ? num : size;
    for(unsigned long idx1 = head , idx2 = 0; idx2 < max; ++idx1 %= size , ++idx2 %= newsize){
        std::swap(elements[idx1] , tmpElements[idx2]);
    }
    std::swap(elements , tmpElements);
    delete[] tmpElements;
    head = 0;
    tail = num;
    size = newsize;
}
// ...

/* ************************************************************************** */

}