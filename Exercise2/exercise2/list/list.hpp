
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public ClearableContainer , virtual public LinearContainer<Data> , virtual public DictionaryContainer<Data>{
  // Must extend ClearableContainer,
  //             LinearContainer<Data>,
  //             DictionaryContainer<Data>

private:

  // ...

protected:

  // using Container::???;
  using Container::size;

  struct Node {

    // Data
    Data element;
    Node * next = nullptr;
    // ...

    /* ********************************************************************** */

    // Specific constructors
    inline Node() = default;
    
    inline Node(const Data& dat) : element(dat){};
    
    inline Node(Data&&) noexcept;
    // ...

    /* ********************************************************************** */

    // Copy constructor
    inline Node(const Node& nod) : element(nod.element){};
    // ...

    // Move constructor
    inline Node(Node&& ) noexcept;
    // ...

    /* ********************************************************************** */

    // Destructor
    virtual ~Node();
    // ...

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&) const noexcept;
    inline bool operator!=(const Node&) const noexcept;
    // ...

    /* ********************************************************************** */

    // Specific member functions
    virtual Node * Clone(Node*);

    // ...

  };

  Node * head = nullptr;
  Node * tail = nullptr;

  // ...

public:

  // Default constructor
  List() = default;
  // List() specifiers;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
  List(const TraversableContainer<Data>&);
  // List(argument) specifiers; // A list obtained from a MappableContainer
  List(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  List(const List&);
  // List(argument) specifiers;

  // Move constructor
  List(List&&) noexcept;
  // List(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  virtual ~List();
  // ~List() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  List& operator=(const List&);
  // type operator=(argument) specifiers;

  // Move assignment
  List& operator=(List&&) noexcept;
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  inline bool operator==(const List&) const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  void InsertAtFront(const Data&);
  // type InsertAtFront(argument) specifier; // Move of the value
  void InsertAtFront(Data&&);
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  void RemoveFromFront();
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)
  Data FrontNRemove();

  // type InsertAtBack(argument) specifier; // Copy of the value
  void InsertAtBack(const Data&);
  // type InsertAtBack(argument) specifier; // Move of the value
  void InsertAtBack(Data&&);

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifier; // Copy of the value
  bool Insert(const Data&) override;
  // type Insert(argument) specifier; // Move of the value
  bool Insert(Data&&) override;
  // type Remove(argument) specifier;
  bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  const Data& operator[](const unsigned long) const override;
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data& operator[](const unsigned long) override;

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  const Data& Front() const override;
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  Data& Front() override;

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  const Data& Back() const override;
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)
  Data& Back() override;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // using typename TraversableContainer<Data>::TraverseFun;
  using typename TraversableContainer<Data>::TraverseFun;

  // type Traverse(arguments) specifiers; // Override TraversableContainer member
  void Traverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(arguments) specifiers; // Override PreOrderTraversableContainer member
  void PreOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(arguments) specifiers; // Override PostOrderTraversableContainer member
  void PostOrderTraverse(TraverseFun) const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFun;
  using typename MappableContainer<Data>::MapFun;

  // type Map(argument) specifiers; // Override MappableContainer member
  void Map(MapFun) override;
  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member
  void PreOrderMap(MapFun) override;

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member
  void PostOrderMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!
  void PreOrderTraverse(TraverseFun , const Node *) const;

  void PostOrderTraverse(TraverseFun , const Node *) const;

  void PreOrderMap(MapFun , Node *);

  void PostOrderMap(MapFun , Node *);
};

/* ************************************************************************** */

}

#include "list.cpp"

#endif