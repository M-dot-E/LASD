
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>{
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // ...
  using BinaryTree<Data>::size;

  struct NodeVec : virtual public MutableBinaryTree<Data>::MutableNode{ // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    // ...
    Data data;

    Vector<NodeVec*> * tree = nullptr;

    ulong index = 0;

    NodeVec() = default;

    NodeVec(const Data&, unsigned long, Vector<NodeVec*> *);

    NodeVec(Data&&, unsigned long, Vector<NodeVec*> *);

    virtual ~NodeVec() = default;

    const Data& Element() const noexcept override;

    Data& Element() noexcept override;

    bool HasLeftChild() const noexcept override;

    bool HasRightChild() const noexcept override;

    NodeVec& LeftChild() const override;

    NodeVec& RightChild() const override;

    NodeVec& LeftChild() override;

    NodeVec& RightChild() override;

  };
  Vector<NodeVec*> * vectorTree = nullptr;

public:

  // Default constructor
  BinaryTreeVec() = default;
  // BinaryTreeVec() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const TraversableContainer<Data> & container);
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a TraversableContainer
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
  BinaryTreeVec(MappableContainer<Data> && container) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(BinaryTreeVec&&) noexcept;
  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec();
  // ~BinaryTreeVec() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec<Data>& operator=(const BinaryTreeVec<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec<Data>& operator=(BinaryTreeVec<Data>&&) noexcept;


  /* ************************************************************************ */

 // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const BinaryTreeVec<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator!=(const BinaryTreeVec<Data>&) const noexcept;


  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  NodeVec& Root() const override;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)
  NodeVec& Root() override;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
   void Clear() noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)
  using typename TraversableContainer<Data>::TraverseFun;

  // type BreadthTraverse(arguments) specifiers; // Override BreadthTraversableContainer member
  void BreadthTraverse(TraverseFun) const override;
  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)
  using typename MappableContainer<Data>::MapFun;

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member
  void BreadthMap(MapFun) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
