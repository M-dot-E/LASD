
namespace lasd {

/* ************************************************************************** */
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node &node) const noexcept {
    
    if (node.Element() == Element()){
         
        bool hasRChild = HasRightChild();
        bool hasLChild = HasLeftChild(); 

        bool otherHasRChild = node.HasRightChild();
        bool otherHasLChild = node.HasLeftChild(); 

        bool right = (hasRChild == otherHasRChild);
        bool left = (hasLChild == otherHasLChild); 

        if(left && right){ 
            
            if (hasLChild && hasRChild){

                return ((node.LeftChild() == LeftChild()) && (node.RightChild() == RightChild()));

            } else if (hasLChild) {

                return (node.LeftChild() == LeftChild());

            } else if (hasRChild) {

                return (node.RightChild() == RightChild());

            } else {

                return true;
            }
        }
    }

  return false;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept {
    return !(*this == node);
}

template <typename Data>
bool BinaryTree<Data>::Node::IsLeaf() const noexcept {
    return (!HasRightChild() && !HasLeftChild());
}


template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data> &binaryTree) const noexcept {
    if (size == binaryTree.size) {

        if (size != 0) {
            
            return Root() == binaryTree.Root();

        } else {

            return true;
        }
            
    } else {

        return false;
    }
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data> &binaryTree) const noexcept {
    return !(*this == binaryTree);
}

//TODO LE TRAVERSE DI BINARYTREE E LE MAP DI MUTABLEBINARYTREE
template <typename Data>
void BinaryTree<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun, &Root());
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const {
    PreOrderTraverse(fun, &Root());
}

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun,  const Node * cur) const {
    
    if(cur != nullptr){
        
        fun(cur->Element());

        if(cur->HasLeftChild()){
            PreOrderTraverse(fun, &(cur->LeftChild()));
        }

        if(cur->HasRightChild()) {
            PreOrderTraverse(fun, &(cur->RightChild()));
        }
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const {
    PostOrderTraverse(fun, &Root());
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun, const Node * cur) const {
    
    if(cur != nullptr){
        
        if(cur->HasLeftChild()) {
            PostOrderTraverse(fun, &(cur->LeftChild()));
        }
        
        if(cur->HasRightChild()) {
            PostOrderTraverse(fun, &(cur->RightChild()));
        }
        
        fun(cur->Element());
    }
}


template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const {
    InOrderTraverse(fun, &Root());
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun, const Node* cur) const {
    
    if(cur != nullptr){
        
        if(cur->HasLeftChild()){
            InOrderTraverse(fun,  &(cur->LeftChild()));
        }

        fun(cur->Element());

        if(cur->HasRightChild()){
            InOrderTraverse(fun, &(cur->RightChild()));
        }
    }
}


template <typename Data>
inline void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const {
    BreadthTraverse(fun, &Root());
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node* node) const {
    
    QueueLst<const Node*> tmpQueue;
    tmpQueue.Enqueue(node);
    
    const Node* tmp;

    while(!(tmpQueue.Empty())){
        
        tmp = tmpQueue.HeadNDequeue();
        
        fun(tmp->Element());
        
        if(tmp->HasLeftChild()) {
            tmpQueue.Enqueue(&(tmp->LeftChild()));
        }
        
        if(tmp->HasRightChild()){
            tmpQueue.Enqueue(&(tmp->RightChild()));
        }
    }
}


template <typename Data>
void MutableBinaryTree<Data>::Map(MapFun fun) {
    PreOrderMap(fun, &Root());
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun) {
    PreOrderMap(fun, &Root());
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode * cur)  {
    
    if(cur != nullptr){
        
        fun(cur->Element());

        if(cur->HasLeftChild()) {
            PreOrderMap(fun, &(cur->LeftChild()));
        }

        if(cur->HasRightChild()) {
            PreOrderMap(fun, &(cur->RightChild()));
        }
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun) {
    PostOrderMap(fun, &Root());
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode * cur) {
    
    if(cur != nullptr){
        
        if(cur->HasLeftChild()) {
            PostOrderMap(fun, &(cur->LeftChild()));
        }
        
        if(cur->HasRightChild()) {
            PostOrderMap(fun, &(cur->RightChild()));
        }
        
        fun(cur->Element());
    }
}


template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun) {
    InOrderMap(fun, &Root());
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode* cur) {
    
    if(cur != nullptr){
        
        if(cur->HasLeftChild()){
            InOrderMap(fun,  &(cur->LeftChild()));
        }

        fun(cur->Element());

        if(cur->HasRightChild()){
            InOrderMap(fun, &(cur->RightChild()));
        }
    }
}


template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun) {
    BreadthMap(fun, &Root());
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun,  MutableNode* node) {
    
    QueueLst<MutableNode*> tmpQueue;
    tmpQueue.Enqueue(node);
    
    MutableNode* tmp;

    while(!(tmpQueue.Empty())){
        
        tmp = tmpQueue.HeadNDequeue();
        
        fun(tmp->Element());
        
        if(tmp->HasLeftChild()) {
            tmpQueue.Enqueue(&(tmp->LeftChild()));
        }
        
        if(tmp->HasRightChild()){
            tmpQueue.Enqueue(&(tmp->RightChild()));
        }
    }
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data> &binaryTree) {
    
    root = &binaryTree.Root();
    current = &binaryTree.Root();
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data> &iter) {
    
    root = iter.root;
    current = iter.current;
    stack = iter.stack;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data> &&iter) noexcept {
    
    std::swap(root, iter.root);
    std::swap(current,iter.current);
    
    stack = std::move(iter.stack);
}

template <typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator() {
    
    stack.~StackLst();
    
    current = nullptr;
    root = nullptr;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data> &iter) {

    root = iter.root;
    current = iter.current;
    stack = iter.stack;

    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data> &&iter) noexcept {
    
    std::swap(root, iter.root);
    std::swap(current, iter.current);
    
    stack = std::move(iter.stack);
    
    return *this;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data> &iter) const noexcept {
    return (root==iter.root && current==iter.current && stack==iter.stack);
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data> &iter) const noexcept {
    return !(*this==iter);
}

template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
    
    if(!Terminated()){

        return current->Element();

    } else {

        throw std::out_of_range("Iterator PreOrder has terminated");
    } 
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {

    current = root;
    stack.Clear();
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    
    if(Terminated()){

        throw std::out_of_range("Iterator PreOrder has terminated.");
    }
        
    if(current->HasRightChild()) {
        stack.Push(&(current->RightChild()));
    }
        
    if(current->HasLeftChild()) {
        stack.Push(&(current->LeftChild()));
    }
        
    if(stack.Empty()){

        current = nullptr;

    } else {

        current = stack.TopNPop();
    }
         
    
    return *this;
}


template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data> &binaryTree) {
   
    root = &binaryTree.Root();
    current = &binaryTree.Root();
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data> &iter) {
    
    root = iter.root;
    current = iter.current;
    queue = iter.queue;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data> &&iter) noexcept {
    
    std::swap(root,iter.root);
    std::swap(current,iter.current);
    
    queue = std::move(iter.queue);
}

template <typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator() {
    
    queue.~QueueLst();

    current = nullptr;
    root = nullptr;
    
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data> &iter) {

    root = iter.root;
    current = iter.current;
    queue = iter.queue;
    
    return *this;
}


template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data> &&iter) noexcept {
    
    std::swap(root, iter.root);
    std::swap(current, iter.current);
    
    queue = std::move(iter.queue);
    
    return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data> &iter) const noexcept {
    return (root==iter.root && current==iter.current && queue==iter.queue);
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data> &iter) const noexcept {
    return !(*this==iter);
}

template <typename Data>
const Data& BTBreadthIterator<Data>::operator*() const {
    
    if(!Terminated()){

        return current->Element();

    } else {

        throw std::out_of_range("Iterator Breadth has terminated");
    } 
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {

    current = root;
    queue.Clear();
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    
    if(Terminated()){

        throw std::out_of_range("Iterator Breadth has terminated.");
    }
        
    
    if(current->HasLeftChild()) {
        
        queue.Enqueue(&(current->LeftChild()));
    }
        
    
    if(current->HasRightChild()) {
        
        queue.Enqueue(&(current->RightChild()));
    }
        
    
    if(queue.Empty()) {
        
        current = nullptr;

    } else {

        current = queue.HeadNDequeue();
    }
    
        
    return *this;

}

template <typename Data>
void BTInOrderIterator<Data>::getCurrentMostLeftNode() {
    
    while (current->HasLeftChild()) {
        
        stack.Push(current);

        current = &(current->LeftChild());
    }
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &binaryTree) {
    
    root = &binaryTree.Root();
    current = &binaryTree.Root();

    getCurrentMostLeftNode();
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data> &iter) {
    
    root = iter.root;
    current = iter.current;
    
    stack = iter.stack;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data> &&iter) noexcept {
    
    std::swap(root, iter.root);
    std::swap(current,iter.current);
    
    stack = std::move(iter.stack);
}

template <typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator() {
    
    stack.~StackLst();

    current = nullptr;
    root = nullptr;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data> &iter) {

    root = iter.root;
    current = iter.current;
    
    stack = iter.stack;
    
    return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data> &&iter) noexcept {
    
    std::swap(root, iter.root);
    std::swap(current, iter.current);
    
    stack = std::move(iter.stack);
    
    return *this;
}


template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data> &iter) const noexcept {
    return (root==iter.root && current==iter.current && stack==iter.stack);
}

template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data> &iter) const noexcept {
    return !(*this==iter);
}


template <typename Data>
const Data& BTInOrderIterator<Data>::operator*() const {
    
    if(!Terminated()){

        return current->Element();

    } else {

        throw std::out_of_range("Iterator InOrder has terminated");
    } 
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept
{
    current = root;
    
    stack.Clear();
    
    if(current != nullptr) {
        getCurrentMostLeftNode();
    }
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    
    if(Terminated()) {

        throw std::out_of_range("Iterator InOrder has terminated.");
    }
        
    if(current->HasRightChild()){

        current = &(current->RightChild());
        getCurrentMostLeftNode();

    } else {

        if(stack.Empty()) {

            current = nullptr;

        } else {

            current = stack.TopNPop(); 
        }
    }

    return *this;
}

template <typename Data>
void BTPostOrderIterator<Data>::getCurrentMostLeftLeaf() {
    
    while (current->HasLeftChild()) {
        stack.Push(current);
        current = &(current->LeftChild());
    }

    if(current->HasRightChild()) {
        stack.Push(current);
        current = &(current->RightChild());
        getCurrentMostLeftLeaf();
    }
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data> &binaryTree) {
    
    root = &binaryTree.Root();
    current = &binaryTree.Root();
    
    getCurrentMostLeftLeaf();
    
    last = current;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data> &iter) {
    
    root = iter.root;
    current = iter.current;
    
    last = iter.last;
    
    stack = iter.stack;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data> &&iter) noexcept {
    
    std::swap(root,iter.root);
    std::swap(current,iter.current);
    
    std::swap(last,iter.last);
    
    stack = std::move(iter.stack);
}

template <typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator() {
    
    stack.~StackLst();

    current = nullptr;
    root = nullptr;
    last = nullptr;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data> &iter) {

    root = iter.root;
    current = iter.current;
    
    last = iter.last;
    
    stack = iter.stack;

    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data> &&iter) noexcept {
    
    std::swap(root, iter.root);
    std::swap(current, iter.current);
    std::swap(last,iter.last);
    
    stack = std::move(iter.stack);
    
    return *this;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data> &iter) const noexcept {
    return (root==iter.root && current==iter.current && last==iter.last && stack==iter.stack);
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data> &iter) const noexcept {
    return !(*this==iter);
}

template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept
{
    current = root;
    
    stack.Clear();

    if(current != nullptr) {

        getCurrentMostLeftLeaf();
        
        last = current;
    }

}

template <typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
    
    if(!Terminated()){

        return current->Element();

    } else {

        throw std::out_of_range("Iterator PostOrder has terminated");
    } 
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    
    if(Terminated()) {
        throw std::out_of_range("Iterator PostOrder has terminated.");
    }

    if(stack.Empty()){

        current = nullptr;
        last = nullptr;

    } else {

        current = stack.TopNPop();
        
        if(current->HasRightChild() && !(&(current->RightChild())==last)){
            
            stack.Push(current);
            current = &(current->RightChild());
            getCurrentMostLeftLeaf();

        }
    }

    last = current;
    
    return *this;
}

// ...

/* ************************************************************************** */

}
