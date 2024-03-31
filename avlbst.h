#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int8_t getBalance () const;
    void setBalance (int8_t balance);
    void updateBalance(int8_t diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int8_t balance_;    // effectively a signed char
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
int8_t AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(int8_t balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(int8_t diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here
    void insertFix(AVLNode<Key,Value>* parent, AVLNode<Key,Value>* node);
    void removeFix(AVLNode<Key,Value>* node, int diff);
    void rightRotate(AVLNode<Key,Value>* node);
    void leftRotate(AVLNode<Key,Value>* node);

};

/*
 * Recall: If key is already in the tree, you should 
 * overwrite the current value with the updated value.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{
  //cout << "inserting " << new_item.first << endl;
  if (BinarySearchTree<Key, Value>::root_ == nullptr){
    AVLNode<Key, Value>* toAdd = new AVLNode<Key, Value>(new_item.first, new_item.second, nullptr);
    toAdd->setBalance(0);
    BinarySearchTree<Key, Value>::root_ = toAdd;

  } else {
    AVLNode<Key, Value>* curr = static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::root_);
    bool stop = false;
    while (stop == false){
      if (new_item.first < curr->getKey()){
        if (curr->getLeft() == nullptr){

          AVLNode<Key, Value>* toAdd = new AVLNode<Key, Value>(new_item.first, new_item.second, curr);
          curr->setLeft(toAdd);

          toAdd->setBalance(0);
          if (curr->getBalance() == 1){ //right heavy -> balanced 
            curr->setBalance(0);
            //cout << "curr " << curr->getKey() << " balance " << (int)curr->getBalance() << endl;
          } else if (curr->getBalance() == 0){
            curr->setBalance(curr->getBalance() -1); //now left heavy
            //cout << "curr " << curr->getKey() << " balance " << (int)curr->getBalance() << endl;
            insertFix(curr, toAdd);
          }

          stop = true;
        } else {
          curr = curr->getLeft();
        }
      } else if (new_item.first > curr->getKey()){
        if (curr->getRight() == nullptr){

          AVLNode<Key, Value>* toAdd = new AVLNode<Key, Value>(new_item.first, new_item.second, curr);
          curr->setRight(toAdd);
          toAdd->setBalance(0);
          //cout << toAdd->getKey() << "balance to " << 

          if (curr->getBalance() == -1){ //left heavy -> balanced 
            curr->setBalance(0);
          } else if (curr->getBalance() == 0){
            curr->setBalance(curr->getBalance() + 1); //now right heavy
            insertFix(curr, toAdd);
          }

          stop = true;
        } else {
          curr = curr->getRight();
        }
      } else if (new_item.first == curr->getKey()) {

        //switching out a node does not require rebalancing 

        AVLNode<Key, Value>* switchIn = new AVLNode<Key, Value>(new_item.first, new_item.second, nullptr);
        AVLNode<Key, Value>* switchOut = curr;

        nodeSwap(switchIn, switchOut);
        if (switchOut->getParent() != nullptr){
          if (switchOut->getParent()->getRight() == switchOut){
            switchOut->getParent()->setRight(nullptr);
          } else if (switchOut->getParent()->getLeft() == switchOut){
            switchOut->getParent()->setLeft(nullptr);
          }
        }
        delete switchOut;

        stop = true; 
      }
    }
  }


  //TODO
  
}

template<class Key, class Value>
void AVLTree<Key, Value>::insertFix(AVLNode<Key,Value>* parent, AVLNode<Key,Value>* node){
  if (parent== nullptr){ return; }
  AVLNode<Key, Value>* grandparent = parent->getParent();
  if (grandparent == nullptr){ return; }

  if (parent->getKey() < grandparent->getKey()){ //parent is left child of grandparent
    int gb = grandparent->getBalance();
    gb -= 1;
    grandparent->setBalance(gb);

    if (grandparent->getBalance() == 0){
      return;
    } else if (grandparent->getBalance() == -1){
      insertFix(grandparent, parent);
    } else if (grandparent->getBalance() == -2){
      if (grandparent->getLeft() == parent && parent->getLeft() == node){ //zig zig
        rightRotate(grandparent);
        parent->setBalance(0);
        grandparent->setBalance(0);
      } else if (grandparent->getLeft() == parent && parent->getRight() == node){ //zig zig
        leftRotate(parent);
        rightRotate(grandparent);

        if (node->getBalance() == -1){
          parent->setBalance(0);
          grandparent->setBalance(1);
          node->setBalance(0);
        } else if (node->getBalance() == 0){
          parent->setBalance(0);
          grandparent->setBalance(0);
          node->setBalance(0);
        } else if (node->getBalance() == 1){
          parent->setBalance(-1);
          grandparent->setBalance(0);
          node->setBalance(0);
        }
      }
    }

  } else if (parent->getKey() > grandparent->getKey()){ //parent is right child of grandparent
    int gb = grandparent->getBalance();
    gb += 1;
    grandparent->setBalance(gb);

    if (grandparent->getBalance() == 0){
      return;
    } else if (grandparent->getBalance() == 1){
      insertFix(grandparent, parent);
    } else if (grandparent->getBalance() == 2){

      if (grandparent->getRight() == parent && parent->getRight() == node){ //zig zig
        leftRotate(grandparent);
        parent->setBalance(0);
        grandparent->setBalance(0);
      } else if (grandparent->getRight() == parent && parent->getLeft() == node){ //zig zig
        rightRotate(parent);
        leftRotate(grandparent);

        if (node->getBalance() == 1){
          parent->setBalance(0);
          grandparent->setBalance(-1);
          node->setBalance(0);
        } else if (node->getBalance() == 0){
          parent->setBalance(0);
          grandparent->setBalance(0);
          node->setBalance(0);
        } else if (node->getBalance() == -1){
          parent->setBalance(1);
          grandparent->setBalance(0);
          node->setBalance(0);
        }
      }
    }
  }

}

template<class Key, class Value>
void AVLTree<Key, Value>::rightRotate(AVLNode<Key,Value>* node){
  AVLNode<Key, Value>* parent = node->getParent();
  AVLNode<Key, Value>* leftChild = node->getLeft(); //will be pushed up
  
  AVLNode<Key, Value>* a = leftChild->getLeft();
  AVLNode<Key, Value>* b = leftChild->getRight();
  AVLNode<Key, Value>* c = node->getRight();

  leftChild->setRight(node);
  node->setParent(leftChild);
  if (parent!= nullptr){
    if (leftChild->getKey() < parent->getKey()){
      parent->setLeft(leftChild);
    } else if (leftChild->getKey() > parent->getKey()){
      parent->setRight(leftChild);
    }
  } else {
    BinarySearchTree<Key, Value>::root_ = leftChild;
  }
  leftChild->setParent(parent);
  leftChild->setLeft(a);
  node->setLeft(b);
  node->setRight(c);

  if (a != nullptr){
    a->setParent(leftChild);
  }
  if (b != nullptr){
    b->setParent(node);
  }
  if (c != nullptr){
    c->setParent(node);
  }

}

//pushes left, replaced by right child
template<class Key, class Value>
void AVLTree<Key, Value>::leftRotate(AVLNode<Key,Value>* node){
  AVLNode<Key, Value>* parent = node->getParent();
  AVLNode<Key, Value>* rightChild = node->getRight(); //will be pushed up
  
  AVLNode<Key, Value>* a = rightChild->getRight();
  AVLNode<Key, Value>* b = rightChild->getLeft();
  AVLNode<Key, Value>* c = node->getLeft();

  rightChild->setLeft(node);
  node->setParent(rightChild);
  if (parent!= nullptr){
    if (rightChild->getKey() < parent->getKey()){
      parent->setLeft(rightChild);
    } else if (rightChild->getKey() > parent->getKey()){
      parent->setRight(rightChild);
    }
  } else {
    BinarySearchTree<Key, Value>::root_ = rightChild;
  }
  rightChild->setParent(parent);
  rightChild->setRight(a);
  node->setRight(b);
  node->setLeft(c);

  if (a != nullptr){
    a->setParent(rightChild);
  }
  if (b != nullptr){
    b->setParent(node);
  }
  if (c != nullptr){
    c->setParent(node);
  }
}



/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
  //cout << "removing " << key << endl;
  AVLNode<Key, Value>* toRemove = static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::internalFind(key));

  if (toRemove != nullptr) { //if what you want to remove exists in bst
    if (toRemove->getLeft() != nullptr && toRemove->getRight() != nullptr){//both children exist
      // this is what it should be replaced with
      AVLNode<Key, Value>* pred = static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::predecessor(toRemove));
      AVLNode<Key, Value>* predPar = pred->getParent(); 

      if (predPar == toRemove){
        nodeSwap(static_cast<AVLNode<Key, Value>*>(pred), static_cast<AVLNode<Key, Value>*>(toRemove));

        //rebalance
        AVLNode<Key, Value>* parent = toRemove->getParent();
        int diff = 0;
        if (parent!= nullptr){
          //cout << "par is " << parent->getKey() << endl;
          if (parent->getLeft() == toRemove){ //toRemove is left child
            diff = 1;
          } else if (parent->getRight() == toRemove){ //toRemove is right child
            diff = -1;
          } 
        }

        if (pred->getParent() == nullptr){
          BinarySearchTree<Key, Value>::root_ = pred;
        }

        //this would only happen if the node to toRemove's left has no right nodes
        pred->setLeft(toRemove->getLeft());
        if (toRemove->getLeft() != nullptr){
          toRemove->getLeft()->setParent(pred);
        }

        delete toRemove; //and update ptrs 
        //cout << "both children " << endl;
        removeFix(parent, diff);      
      } else {

        //switch -> the node to be removed is now the rightmost node of its left subtree
        nodeSwap(static_cast<AVLNode<Key, Value>*>(pred), static_cast<AVLNode<Key, Value>*>(toRemove));

        //rebalance
        AVLNode<Key, Value>* parent = toRemove->getParent();
        int diff = 0;
        if (parent!= nullptr){
          if (toRemove->getKey() < parent->getKey()){ //toRemove is left child
            diff = 1;
          } else if (toRemove->getKey() > parent->getKey()){ //toRemove is right child
            diff = -1;
          } 
        }

        //The predecessor's parent's right child now holds the noed to be removed
        if (toRemove->getLeft() == nullptr){
          predPar->setRight(nullptr);
        } else {
          predPar->setRight(toRemove->getLeft());
          toRemove->getLeft()->setParent(predPar);
        }

        //if pred is now the root, set it accordingly
        if (pred->getParent() == nullptr){
          BinarySearchTree<Key, Value>::root_ = pred;
        }

        //cout << "both children 2" << endl;
        delete toRemove; //and update ptrs 
        removeFix(parent, diff);      
      }

    } else if (toRemove->getLeft() != nullptr) { //left child exists only
      AVLNode<Key, Value>* par = toRemove->getParent();
      AVLNode<Key, Value>* promoted = toRemove->getLeft();
      if (par != nullptr) {
        if (toRemove->getKey() < par->getKey()){
          par->setLeft(promoted);
        } else {
          par->setRight(promoted);
        }
        promoted->setParent(par);
      } else {
        promoted->setParent(nullptr);
        BinarySearchTree<Key, Value>::root_ = promoted;
      }

      //rebalance
        AVLNode<Key, Value>* parent = toRemove->getParent();
        int diff = 0;
        if (parent!= nullptr){
          if (toRemove->getKey() < parent->getKey()){ //toRemove is left child
            diff = 1;
          } else if (toRemove->getKey() > parent->getKey()){ //toRemove is right child
            diff = -1;
          } 
        }

        //cout << "left only " << endl;
        delete toRemove; //and update ptrs 
        removeFix(parent, diff);      

    } else if (toRemove->getRight() != nullptr) {     //right child exists only
      AVLNode<Key, Value>* par = toRemove->getParent();
      AVLNode<Key, Value>* promoted = toRemove->getRight();
      if (par != nullptr) {
        if (toRemove->getKey() < par->getKey()){
          par->setLeft(promoted);
        } else {
          par->setRight(promoted);
        }
        promoted->setParent(par);
      } else {
        promoted->setParent(nullptr);
        BinarySearchTree<Key, Value>::root_ = promoted;
      }
      
      //rebalance
        AVLNode<Key, Value>* parent = toRemove->getParent();
        int diff = 0;
        if (parent != nullptr){
          if (toRemove->getKey() < parent->getKey()){ //toRemove is left child
            diff = 1;
          } else if (toRemove->getKey() > parent->getKey()){ //toRemove is right child
            diff = -1;
          } 
        }
        
        delete toRemove; //and update ptrs 
        removeFix(parent, diff);      
      
    } else { //no children
      AVLNode<Key, Value>* par = toRemove->getParent();
      if (par != nullptr){ //if parent exists
        if (key < par->getKey()){
          par->setLeft(nullptr);
        } else if (key > par->getKey()){
          par->setRight(nullptr);
        }
      } else {
        BinarySearchTree<Key, Value>::root_ = nullptr;
      }
      
      //rebalance
        AVLNode<Key, Value>* parent = toRemove->getParent();
        int diff = 0;
        if (parent!= nullptr){
          if (toRemove->getKey() < parent->getKey()){ //toRemove is left child
            diff = 1;
          } else if (toRemove->getKey() > parent->getKey()){ //toRemove is right child
            diff = -1;
          } 
        }

        delete toRemove; //and update ptrs 
        removeFix(parent, diff);      

    }
  }

    // TODO
}

template<class Key, class Value>
void AVLTree<Key, Value>::removeFix(AVLNode<Key,Value>* node, int diff){

  if (node == nullptr){
    return;
  }
  //cout << "remove fix called " << node->getKey() << " " << diff << endl;

  AVLNode<Key, Value>* parent = node->getParent();
  int nextdiff = 0;
  if (parent != nullptr){
    if (node->getKey() < parent->getKey()){ //node is left child
      nextdiff = 1;
    } else if (node->getKey() > parent->getKey()){ //node is right child
      nextdiff = -1;
    }
  }

  if (diff == -1){
    // << "nbs " << (int)node->getBalance() + diff << endl;
    if (node->getBalance() + diff == -2){
      AVLNode<Key, Value>* tallerChild = node->getLeft(); //mayb

      if (tallerChild->getBalance() == -1){
        rightRotate(node);
        tallerChild->setBalance(0);
        node->setBalance(0);
        removeFix(parent, nextdiff);
      } else if (tallerChild->getBalance() == 0) {
        rightRotate(node);
        node->setBalance(-1);
        tallerChild->setBalance(1);
      } else if (tallerChild->getBalance() == 1) {

        AVLNode<Key, Value>* grandchild = tallerChild->getRight();
        leftRotate(tallerChild);
        rightRotate(node);

        if (grandchild->getBalance() == 1){
          node->setBalance(0);
          tallerChild->setBalance(-1);
          grandchild->setBalance(0);
        } else if (grandchild->getBalance() == 0){
          node->setBalance(0);
          tallerChild->setBalance(0);
          grandchild->setBalance(0);
        } else if (grandchild->getBalance() == -1){
          node->setBalance(1);
          tallerChild->setBalance(0);
          grandchild->setBalance(0);
        }

        removeFix(parent, nextdiff);
      }

    } else if (node->getBalance() + diff == -1){
      node->setBalance(-1);
    } else if (node->getBalance() + diff == 0){
      node->setBalance(0);
      removeFix(parent, nextdiff);
    }
  } else if (diff == 1){

      if (node->getBalance() + diff == 2){
      AVLNode<Key, Value>* tallerChild = node->getRight(); //mayb

      if (tallerChild->getBalance() == 1){
        leftRotate(node);
        tallerChild->setBalance(0);
        node->setBalance(0);
        removeFix(parent, nextdiff);

      } else if (tallerChild->getBalance() == 0) {
        leftRotate(node);
        node->setBalance(1);
        tallerChild->setBalance(-1);

      } else if (tallerChild->getBalance() == -1) {
        AVLNode<Key, Value>* grandchild = tallerChild->getLeft();
        rightRotate(tallerChild);
        leftRotate(node);

        if (grandchild->getBalance() == -1){
          node->setBalance(0);
          tallerChild->setBalance(1);
          grandchild->setBalance(0);

        } else if (grandchild->getBalance() == 0){
          node->setBalance(0);
          tallerChild->setBalance(0);
          grandchild->setBalance(0);

        } else if (grandchild->getBalance() == 1){
          node->setBalance(-1);
          tallerChild->setBalance(0);
          grandchild->setBalance(0);
        }

        removeFix(parent, nextdiff);
      }

    } else if (node->getBalance() + diff == 1){
      node->setBalance(1);

    } else if (node->getBalance() + diff == 0){
      node->setBalance(0);
      removeFix(parent, nextdiff);
    }

  }

  //cout << "out " << endl;

}


template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int8_t tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}


#endif
