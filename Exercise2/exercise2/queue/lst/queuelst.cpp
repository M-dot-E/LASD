
namespace lasd {

/* ************************************************************************** */

template <typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data>& con) : List<Data>(con) {}

template <typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data>&& con) : List<Data>(std::move(con)) {}

template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst& q) : List<Data>(q){}

template<typename Data>
QueueLst<Data>::QueueLst(QueueLst&& q) noexcept : List<Data>(std::move(q)){}


template<typename Data>
inline QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& q){
    List<Data>::operator=(q);
    return *this;
}

template<typename Data>
inline QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& q) noexcept{
    List<Data>::operator=(std::move(q));
    return *this;
}

template<typename Data>
inline bool QueueLst<Data>::operator==(const QueueLst& q) const noexcept{
    return List<Data>::operator==(q);
}

template<typename Data>
inline bool QueueLst<Data>::operator!=(const QueueLst& q) const noexcept{
    return List<Data>::operator!=(q);
}

template<typename Data>
inline const Data& QueueLst<Data>::Head() const{
    return List<Data>::Front();
}

template<typename Data>
inline Data& QueueLst<Data>::Head(){
    return List<Data>::Front();
}

template<typename Data>
inline void QueueLst<Data>::Dequeue(){
    return List<Data>::RemoveFromFront();
}

template<typename Data>
inline Data QueueLst<Data>::HeadNDequeue(){
    return List<Data>::FrontNRemove();
}

template<typename Data>
inline void QueueLst<Data>::Enqueue(const Data& dat){
    return List<Data>::InsertAtBack(dat);
}

template<typename Data>
inline void QueueLst<Data>::Enqueue(Data&& dat){
    return List<Data>::InsertAtBack(std::move(dat));
}

// ...

/* ************************************************************************** */

}