#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Binary Search Tree tests
    BinarySearchTree<char,int> bt;
    bt.insert(std::make_pair('a',1));
    bt.insert(std::make_pair('b',2));
    
    cout << "Binary Search Tree contents:" << endl;
    for(BinarySearchTree<char,int>::iterator it = bt.begin(); it != bt.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    if(bt.find('b') != bt.end()) {
        cout << "Found b" << endl;
    }
    else {
        cout << "Did not find b" << endl;
    }
    cout << "Erasing b" << endl;
    bt.remove('b');

    // AVL Tree Tests
    /*AVLTree<char,int> at;
    at.insert(std::make_pair('a',1));
    at.insert(std::make_pair('b',2));

    cout << "\nAVLTree contents:" << endl;
    for(AVLTree<char,int>::iterator it = at.begin(); it != at.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    if(at.find('b') != at.end()) {
        cout << "Found b" << endl;
    }
    else {
        cout << "Did not find b" << endl;
    }
    cout << "Erasing b" << endl;
    at.remove('b');*/

    return 0;
}


/*#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{
  BinarySearchTree<int,int> testTree;

  testTree.insert(std::make_pair(15, 15));
testTree.insert(std::make_pair(-41, -41));
testTree.insert(std::make_pair(-32, -32));
testTree.insert(std::make_pair(-39, -39));
testTree.insert(std::make_pair(73, 73));
testTree.insert(std::make_pair(138, 138));
testTree.insert(std::make_pair(-117, -117));
testTree.insert(std::make_pair(147, 147));
testTree.insert(std::make_pair(-1, -1));
testTree.insert(std::make_pair(65, 65));
testTree.insert(std::make_pair(5, 5));
testTree.insert(std::make_pair(31, 31));
testTree.insert(std::make_pair(-72, -72));
testTree.insert(std::make_pair(-50, -50));
testTree.insert(std::make_pair(49, 49));
testTree.insert(std::make_pair(35, 35));
testTree.insert(std::make_pair(79, 79));
testTree.insert(std::make_pair(-60, -60));
testTree.insert(std::make_pair(105, 105));
testTree.insert(std::make_pair(-149, -149));
testTree.insert(std::make_pair(-67, -67));
testTree.insert(std::make_pair(-68, -68));
testTree.insert(std::make_pair(134, 134));
testTree.insert(std::make_pair(119, 119));
testTree.insert(std::make_pair(58, 58));
testTree.insert(std::make_pair(121, 121));
testTree.insert(std::make_pair(-22, -22));
testTree.insert(std::make_pair(46, 46));
testTree.insert(std::make_pair(36, 36));
testTree.insert(std::make_pair(-123, -123));

testTree.remove(-50);
testTree.remove(147);
testTree.remove(105);
testTree.remove(-149);
testTree.remove(31);
testTree.remove(-123);
testTree.remove(-60);
testTree.remove(65);
testTree.remove(46);
testTree.remove(134);
testTree.remove(138);
testTree.remove(-67);
testTree.remove(121);
testTree.remove(15);
testTree.remove(36);
testTree.remove(79);
testTree.remove(-39);
testTree.remove(-41);
testTree.remove(49);
testTree.remove(-68);
testTree.remove(-117);
testTree.remove(73);
testTree.remove(58);
testTree.remove(35);
testTree.print();
testTree.remove(5);
testTree.print();

  /*testTree.insert(std::make_pair(5, 20));
  testTree.insert(std::make_pair(-2, 10));
  testTree.insert(std::make_pair(6, 30));
  testTree.insert(std::make_pair(4, 30));
  testTree.insert(std::make_pair(9, 30));
  testTree.insert(std::make_pair(-6, 30));
  testTree.insert(std::make_pair(3, 30));
  testTree.insert(std::make_pair(8, 30));
  testTree.insert(std::make_pair(-11, 30));
  testTree.insert(std::make_pair(1, 30));
  testTree.insert(std::make_pair(7, 30));
  testTree.print();
  //testTree.remove(-6);
  testTree.remove(3);
  //testTree.remove(-11);
  testTree.remove(1);
  //testTree.print();
  testTree.remove(6);
  //testTree.print();
  testTree.remove(8);
  testTree.print();
  testTree.remove(-2);
  testTree.print();
  testTree.remove(5);
  testTree.print();
  testTree.remove(7);
  testTree.print();
  testTree.remove(9);
  testTree.print();*/
  //testTree.print();
	//testTree.insert(std::make_pair(3, 159));
  //testTree.print();
	//testTree.insert(std::make_pair(1, 9));
  //testTree.print();
	//testTree.insert(std::make_pair(3, 0x5a));
  //testTree.print();
	//testTree.insert(std::make_pair(15, 0xb));
  //testTree.print();
	//testTree.insert(std::make_pair(1, 4));
  //testTree.print();

  //insertion deletion is removing that parent??
	/*testTree.insert(std::make_pair(3, 159));
  testTree.print();

  testTree.remove(5);
  //testTree.find(1);
  testTree.print();*/
/*for(BinarySearchTree<int,int>::iterator it = testTree.begin(); it != testTree.end(); ++it) {
    cout << "hello " << it->first << " " << it->second << endl;
  }*/
  /*BinarySearchTree<int,int>::iterator it = testTree.begin();
  cout << "begin() "<< it->first << " " << it->second << endl;
  ++it;
  cout << "one ++ "<< it->first << " " << it->second << endl;
  ++it;
  cout << "two ++ "<< it->first << " " << it->second << endl;
  ++it;

  //cout << testTree.end() << endl;
  cout << "should be end " << (it == testTree.end()) << endl;

  it = testTree.begin();
  //cout << "eng() nullptr? "<< it << endl;

  /*for(BinarySearchTree<int,int>::iterator it = testTree.begin(); it != testTree.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
  testTree.print();*/

  /*testTree.insert(std::make_pair(5, 8));
  testTree.print();

	testTree.insert(std::make_pair(3, 159));
  testTree.print();
  
	testTree.insert(std::make_pair(1, 9));
  testTree.print();*/

	/*testTree.insert(std::make_pair(3, 0x5a));
  testTree.print();
	testTree.insert(std::make_pair(15, 0xb));
  testTree.print();
	testTree.insert(std::make_pair(1, 4));
  testTree.print();
	testTree.insert(std::make_pair(3, 159));
  testTree.print();*/
  /*
    // Binary Search Tree tests
    BinarySearchTree<char,int> bt;
    bt.insert(std::make_pair('a',1));
    bt.insert(std::make_pair('b',2));
    bt.print();
    
    cout << "Binary Search Tree contents:" << endl; 
    for(BinarySearchTree<char,int>::iterator it = bt.begin(); it != bt.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    cout << "hey " << endl;
    if(bt.find('b') != bt.end()) {
        cout << "Found b" << endl;
    }
    else {
        cout << "Did not find b" << endl;
    }
    cout << "Erasing b" << endl;
    bt.remove('b');

    // AVL Tree Tests
    AVLTree<char,int> at;
    at.insert(std::make_pair('a',1));
    at.insert(std::make_pair('b',2));

    cout << "\nAVLTree contents:" << endl;
    for(AVLTree<char,int>::iterator it = at.begin(); it != at.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    if(at.find('b') != at.end()) {
        cout << "Found b" << endl;
    }
    else {
        cout << "Did not find b" << endl;
    }
    cout << "Erasing b" << endl;
    at.remove('b');

    return 0;
}*/
