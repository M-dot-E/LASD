
#include <stdexcept>
#include <string>

namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline List<Data>::Node::Node( Data&& dat)noexcept{
    std::swap(element , dat);
}

template<typename Data>
inline List<Data>::Node::Node( Node && nod)noexcept{
    std::swap(element , nod.element);
    std::swap(next , nod.next);
}

template<typename Data>
List<Data>::Node::~Node(){
    
}

template<typename Data>
bool List<Data>::Node::operator==(const Node& nod) const noexcept{
    return (element == nod.element) \
    && ((next == nullptr && nod.next == nullptr) || (next != nullptr && nod.next != nullptr) && (*next == *nod.next));
}

template<typename Data>
inline bool List<Data>::Node::operator!=(const Node& nod) const noexcept{
    return !(*this == nod);
}

template<typename Data>
typename List<Data>::Node * List<Data>::Node::Clone(Node * tail){
    if(next == nullptr){
        return tail;
    }
    else{
        Node * node = new Node(element);
        node->next = next->Clone(tail);
        return node;
    }
}

template<typename Data>
List<Data>::List(const TraversableContainer<Data> & con){
    con.Traverse(
        [this](const Data & dat){
            InsertAtBack(dat);
        }
    );
}

template<typename Data>
List<Data>::List(MappableContainer<Data> && con){
    con.Map(
        [this](Data & dat){
            InsertAtBack(std::move(dat));
        }
    );
}

template<typename Data>
List<Data>::~List(){
    Clear();
}

//move constructor list
template<typename Data>
List<Data>::List(List<Data>&& lst)noexcept{
   std::swap(head , lst.head);
   std::swap(tail , lst.tail);
   std::swap(size , lst.size); 
}

//copy constructor list
template<typename Data>
List<Data>::List(const List<Data>& lst){
    if(this == &lst){
        return;
    }

    for( unsigned long i = 0; i < lst.size; i++){
        InsertAtBack(lst[i]);
    }
}

//copy assignment list
template<typename Data>
List<Data>& List<Data>::operator=(const List<Data>& lst){
    if(*this == lst){
        return *this;
    }

    Clear();

    Node *temp = lst.head;
    while(temp != nullptr){
        InsertAtBack(temp -> element);
        temp = temp->next;
    }
    return *this;
}

// move assignment list
template<typename Data>
List<Data>& List<Data>::operator=(List<Data>&& lst) noexcept{
    std::swap(head , lst.head);
    std::swap(tail , lst.tail);
    std::swap(size , lst.size);
    return *this;
}

template<typename Data>
bool List<Data>::operator==(const List<Data>& lst) const noexcept {
    if (size != lst.size) {
        return false;
    }

    Node* cur = head;
    Node* lstCur = lst.head;

    while (cur != nullptr) {
        if (cur->element != lstCur->element) {
            return false;
        }
        cur = cur->next;
        lstCur = lstCur->next;
    }

    return true;
}

template<typename Data>
bool List<Data>::operator!=(const List<Data>& lst) const noexcept {
    return !(*this == lst);
}

template<typename Data>
void List<Data>::Clear(){
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    head = nullptr;
    size = 0;
}

template<typename Data>
bool List<Data>::Insert(const Data & dat){
    for(Node * cur = head; cur != nullptr; cur = cur->next){
        if(cur->element == dat){
            return false;
        }
    }
    InsertAtBack(dat);
    return true;
}

template<typename Data>
bool List<Data>::Insert( Data && dat){
    for(Node * cur = head; cur != nullptr; cur = cur->next){
        if(cur->element == dat){
            return false;
        }
    }
    InsertAtBack(std::move(dat));
    return true;
}

template<typename Data>
bool List<Data>::Remove(const Data& dat){
    Node * last = nullptr;
    for(Node** cur = &head; *cur != nullptr; last = *cur , cur = &((*cur))->next){
        if((*cur)->element == dat){
            Node* node = *cur;
            *cur = node->next;
            node->next = nullptr;
            delete node;
            size--;
            if(tail == node){
                tail = last;
            }
            return true;
        }
    }
    return false;
}

template<typename Data>
const Data & List<Data>::operator[](const unsigned long index) const{
    if(index < size){
        Node * cur = head;
        for(unsigned long i = 0; i < index ; ++i , cur = cur->next){}
        return cur->element;
    }
    else{
        throw std::out_of_range("Access at index : " + std::to_string(index));
    }
}

template<typename Data>
Data & List<Data>::operator[](const unsigned long index){
    if(index < size){
        Node * cur = head;
        for(unsigned long i = 0; i < index ; ++i , cur = cur->next){}
        return cur->element;
    }
    else{
        throw std::out_of_range("Access at index : " + std::to_string(index));
    }
}

template<typename Data>
void List<Data>::InsertAtFront(const Data& newData){
    if(head == nullptr){
        head = new Node(newData);
        tail = head;
    }
    else{
        Node * newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template<typename Data>
void List<Data>::InsertAtFront(Data&& newData){
    if(head == nullptr){
        head = new Node(std::move(newData));
        tail = head;
    }
    else{
        Node * newNode = new Node(std::move(newData));
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template<typename Data>
void List<Data>::RemoveFromFront(){
    if(this->Size() == 0){
    throw std::length_error("the List is empty");
    }
    Node * temp = head;
    head = head->next;
    delete temp;
    size--;
}

template<typename Data>
Data List<Data>::FrontNRemove(){
    if(this->Size() == 0){
    throw std::out_of_range("the List is empty");
    }
    Node * temp = head;
    Data returningData = temp->element;
    head = head->next;
    delete temp;
    size--;
    return returningData;
}

template<typename Data>
void List<Data>::InsertAtBack(const Data& newData){
    /*if(tail == nullptr){
        tail = new Node(newData);
        head = tail;
    }
    else{
        Node * newNode =new Node(newData);
        tail->next = newNode;
        tail=newNode;
    }*/
    Node * newNode = new Node(newData);
    if( head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template<typename Data>
void List<Data>::InsertAtBack(Data&& newData){
    /*if(tail == nullptr){
        Node * newNode = new Node(std::move(newData));
        head = newNode;
        tail = head;
    }
    else{
        Node * newNode =new Node(std::move(newData));
        tail->next = newNode;
        tail = newNode;
    }*/
    Node * newNode = new Node(std::move(newData));
    if( head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template<typename Data>
const Data& List<Data>::Front() const{
    if(head != nullptr){
        return head->element;
    }
    else{
        throw std::length_error("Access to an empty list");
    }
}

template<typename Data>
Data& List<Data>::Front(){
    if(head != nullptr){
        return head->element;
    }
    else{
        throw std::length_error("Access to an empty list");
    }
}

template<typename Data>
const Data& List<Data>::Back() const{
    if(tail != nullptr){
        return tail->element;
    }
    else{
        throw std::length_error("Access to an empty list");
    }
}

template<typename Data>
Data& List<Data>::Back() {
    if(tail != nullptr){
        return tail->element;
    }
    else{
        throw std::length_error("Access to an empty list");
    }
}


template<typename Data>
inline void List<Data>::Traverse(TraverseFun fun) const{
    PreOrderTraverse(fun , head);
}

template<typename Data>
inline void List<Data>::PreOrderTraverse(TraverseFun fun) const{
    PreOrderTraverse(fun , head);
}

template<typename Data>
inline void List<Data>::PostOrderTraverse(TraverseFun fun) const{
    PostOrderTraverse(fun , head);
}

template<typename Data>
inline void List<Data>::Map(MapFun fun){
    PreOrderMap(fun , head);
}

template<typename Data>
inline void List<Data>::PreOrderMap(MapFun fun){
    PreOrderMap(fun , head);
}

template<typename Data>
inline void List<Data>::PostOrderMap(MapFun fun){
    PostOrderMap(fun , head);
}

template<typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun , const Node * cur) const{
    for(; cur != nullptr; cur = cur->next){
        fun(cur->element);
    }
}

template<typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun , const Node * cur) const{
    if(cur != nullptr){
        PostOrderTraverse(fun , cur->next);
        fun(cur->element);
    }
}

template<typename Data>
void List<Data>::PreOrderMap(MapFun fun ,  Node * cur) {
    for(; cur != nullptr; cur = cur->next){
        fun(cur->element);
    }
}

template<typename Data>
void List<Data>::PostOrderMap(MapFun fun ,  Node * cur) {
    if(cur != nullptr){
        PostOrderMap(fun , cur->next);
        fun(cur->element);
    }
}
// ...

/* ************************************************************************** */

}