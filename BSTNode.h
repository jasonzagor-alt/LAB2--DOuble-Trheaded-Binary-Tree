// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// 04/24/2025 modification by Prof Sipantzi
// 12/30/2025 by Prof Sipantzi
// This is the file to include for access to the complete binary node
// template implementation

#include "book.h"
#include "BinNode.h"

#pragma once

// Simple binary tree node implementation
template <class Key, class E>
class BSTNode : public BinNode<E> {
private:
  Key k;                  // The node's key
  E it;                   // The node's value
  BSTNode* lc;            // Pointer to left child
  BSTNode* rc;            // Pointer to right child
  bool leftThread;        // True if left pointer is a thread
  bool rightThread;       // True if right pointer is a thread

public:
  // Two constructors -- with and without initial values
  BSTNode() { lc = rc = NULL; leftThread = false; rightThread = false; }
  BSTNode(Key K, E e, BSTNode* l =NULL, BSTNode* r =NULL)
    { k = K; it = e; lc = l; rc = r; leftThread = false; rightThread = false; } //new thread implemantation
  ~BSTNode() {}             // Destructor

  // Functions to set and return the value and key
  E& element() { return it; }
  void setElement(const E& e) { it = e; }
  Key& key() { return k; }
  void setKey(const Key& K) { k = K; }

  // Functions to set and return the children
  inline BSTNode* left() const { return lc; }
  void setLeft(BinNode<E>* b) { lc = (BSTNode*)b; }
  inline BSTNode* right() const { return rc; }
  void setRight(BinNode<E>* b) { rc = (BSTNode*)b; }

  // Return true if it is a leaf, false otherwise
  bool isLeaf() { return (lc == NULL) && (rc == NULL); }

  // Functions to set and return the thread status
  bool isLeftThread() const 
  {
      return leftThread; 
  }
  void setLeftThread(bool b)
  {
      leftThread = b;
  }
  bool isRightThread() const
  {
      return rightThread;
  }
  void setRightThread(bool b) 
  { 
      rightThread = b; 
  }
};
