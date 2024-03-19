#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here


bool equalPaths(Node * root)
{
  if (root == nullptr){
    return true;
  }
    // Add your code below
    int longest = longestPath(root);
    int shortest = shortestPath(root);
    if (shortest == longest){
      return true;
    } else {
      return false;
    }
}

int longestPath(Node* root){
  if (root->left == nullptr && root->right == nullptr){
    return 0;
  } else if (root->left == nullptr){
    return longestPath(root->right) + 1;
  } else if (root->right == nullptr){
    return longestPath(root->left) + 1;
  } else {
    int left = longestPath(root->left);
    int right = longestPath(root->right);
    if (left > right){
      return left + 1;
    } else {
      return right + 1;
    }
  }
}

int shortestPath(Node* root){
  if (root->left == nullptr && root->right == nullptr){
    return 0;
  } else if (root->left == nullptr){
    return shortestPath(root->right) + 1;
  } else if (root->right == nullptr){
    return shortestPath(root->left) + 1;
  } else {
    int left = shortestPath(root->left);
    int right = shortestPath(root->right);
    if (left < right){
      return left + 1;
    } else {
      return right + 1;
    }
  }
}

