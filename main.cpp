#include <iostream>
#include "BinaryTree.h"
#include "LinkedList.h"
#include "LLStack.h"

using namespace std;

int main()
{
    BinaryTree<int> tree;

    tree.Add(50);
    tree.Add(30);
    tree.Add(20);
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
