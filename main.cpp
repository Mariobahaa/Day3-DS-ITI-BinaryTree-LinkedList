#include <iostream>
#include "BinaryTree.h"
#include "LinkedList.h"
#include "LLStack.h"

using namespace std;

int main()
{
    BinaryTree<int> tree;

    tree.Add(20);
    tree.Add(10);
    tree.Add(5);
    tree.Add(1);
    tree.Add(6);
    tree.Add(7);
    tree.Add(15);
    tree.Add(13);
    tree.Add(12);
    tree.Add(14);
    tree.Add(17);
    tree.Add(18);
    tree.Add(25);
    tree.Add(21);
    tree.Add(27);
    tree.Add(30);
    tree.Add(40);
    tree.Add(50);
    //tree.Add(10);
    //tree.Add(30);

    //tree.Traverse();
    tree.Display();
    /*LLStack<int> stk;
    stk.push(new int (1));
    stk.display();
    cout << stk.isEmpty();*/


    return 0;
}
