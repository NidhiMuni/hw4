#include <iostream>
#include <map>
#include "bst.h"
#include "avlbst.h"

using namespace std;


int main(int argc, char *argv[])
{

  AVLTree<int, int> testTree;
  testTree.insert(std::make_pair(-53, -53));
    testTree.insert(std::make_pair(-144, -144));
    testTree.insert(std::make_pair(-22, -22));
    testTree.insert(std::make_pair(56, 56));
    testTree.insert(std::make_pair(-147, -147));
    testTree.insert(std::make_pair(75, 75));
    testTree.insert(std::make_pair(-128, -128));
    testTree.insert(std::make_pair(123, 123));
    testTree.insert(std::make_pair(-89, -89));
    testTree.insert(std::make_pair(-117, -117));
    testTree.insert(std::make_pair(50, 50));
    testTree.insert(std::make_pair(2, 2));
    testTree.insert(std::make_pair(114, 114));
    testTree.insert(std::make_pair(21, 21));
    testTree.insert(std::make_pair(147, 147));
    testTree.insert(std::make_pair(45, 45));
    testTree.insert(std::make_pair(16, 16));
    testTree.insert(std::make_pair(28, 28));
    testTree.insert(std::make_pair(-64, -64));
    testTree.insert(std::make_pair(-77, -77));
    testTree.insert(std::make_pair(-73, -73));
    testTree.insert(std::make_pair(71, 71));
    testTree.insert(std::make_pair(105, 105));
    testTree.insert(std::make_pair(144, 144));
    testTree.insert(std::make_pair(-20, -20));
    testTree.insert(std::make_pair(41, 41));
    testTree.insert(std::make_pair(-61, -61));
    testTree.insert(std::make_pair(106, 106));
    testTree.insert(std::make_pair(-96, -96));
    testTree.insert(std::make_pair(-142, -142));

  testTree.print();

    // Removals
    testTree.remove(-20);
    testTree.remove(-96);
    testTree.remove(-89);
    testTree.remove(16);
    testTree.remove(56);
    testTree.remove(144);
    testTree.remove(105);

  testTree.print();
    testTree.remove(-144);
  testTree.print();
  
  /*testTree.insert(std::make_pair(50, 1));
  testTree.insert(std::make_pair(25, 1));
  testTree.insert(std::make_pair(10, 1));
  testTree.print();

testTree.insert(std::make_pair(50, 1));
testTree.insert(std::make_pair(25, 1));
testTree.insert(std::make_pair(75, 1));
testTree.insert(std::make_pair(10, 1));
testTree.insert(std::make_pair(30, 1));
testTree.insert(std::make_pair(60, 1));
testTree.insert(std::make_pair(80, 1));

testTree.print();

testTree.insert(std::make_pair(5, 1));
testTree.insert(std::make_pair(55, 1));
testTree.insert(std::make_pair(65, 1));
testTree.insert(std::make_pair(90, 1));
testTree.print();
testTree.insert(std::make_pair(53, 1));
testTree.print();*/

/*testTree.insert(std::make_pair(58, 58));
testTree.insert(std::make_pair(1, 1));
testTree.insert(std::make_pair(82, 82));
testTree.insert(std::make_pair(-141, -141));
testTree.insert(std::make_pair(-142, -142));
testTree.insert(std::make_pair(-56, -56));
testTree.insert(std::make_pair(112, 112));
testTree.insert(std::make_pair(102, 102));
testTree.insert(std::make_pair(126, 126));
testTree.insert(std::make_pair(-47, -47));
testTree.insert(std::make_pair(4, 4));
testTree.insert(std::make_pair(-129, -129));
testTree.insert(std::make_pair(95, 95));
testTree.insert(std::make_pair(-149, -149));
testTree.insert(std::make_pair(69, 69));
testTree.insert(std::make_pair(-13, -13));
testTree.insert(std::make_pair(-70, -70));
testTree.insert(std::make_pair(-131, -131));
testTree.insert(std::make_pair(137, 137));
testTree.insert(std::make_pair(-11, -11));
testTree.insert(std::make_pair(51, 51));
testTree.insert(std::make_pair(39, 39));
testTree.insert(std::make_pair(60, 60));
testTree.insert(std::make_pair(-83, -83));
testTree.insert(std::make_pair(-115, -115));

testTree.print();

//this is where -115 disappears
//cout << endl;
cout << endl;
cout << "92 insertion " << endl;
testTree.insert(std::make_pair(-92, -92));
testTree.print();
cout << endl;
cout << endl;

testTree.insert(std::make_pair(-14, -14));
//testTree.print();
testTree.insert(std::make_pair(-26, -26));
//testTree.print();
testTree.insert(std::make_pair(19, 19));
testTree.insert(std::make_pair(73, 73));
testTree.print();*/

  //testTree.print();
  /*AVLTree<int,int> at;
  at.insert(std::make_pair(3,1));
  at.insert(std::make_pair(2,1));
  at.insert(std::make_pair(1,1));
  //at.insert(std::make_pair(5,1));
  at.print();*/
  //at.leftRotate()
  //at.insert(std::make_pair('b',2));


    // Binary Search Tree tests
    /*BinarySearchTree<char,int> bt;
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
    bt.remove('b');*/

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
