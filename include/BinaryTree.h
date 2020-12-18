#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"
#include "../LLStack.h"

using namespace std;

template<class T>
class BinaryTree
{
    Node<T> *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void Add(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if(root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node<T> *current = root, *parent;

            while(current != NULL)
            {
                parent = current;
                if(newNode->Data > current->Data)
                    current = current->Right;
                else
                    current = current->Left;
            }

            if(newNode->Data > parent->Data)
                parent->Right = newNode;
            else
                parent->Left = newNode;
        }
    }

    void Delete(T data)
    {
        Node<T> *pDelete = Search(data);
        Node<T> *temp;

        if(pDelete == NULL)
            return;

        if(pDelete == root)
        {
            if(root->Left == NULL && root->Right == NULL)
            {
                root = NULL;
            }
            else if(root->Right == NULL)
            {
                root = root->Left;
            }
            else if(root->Left == NULL)
            {
                root = root->Right;
            }
            else
            {
                temp = root->Right;
                while(temp->Left != NULL)
                    temp = temp->Left;

                temp->Left = root->Left;
                root = root->Right;
            }
        }
        else
        {
            Node<T> *parent = GetParent(pDelete);
            Node<T> *target;

            if(pDelete->Left == NULL && pDelete->Right == NULL)
            {
                target = NULL;
            }
            else if(pDelete->Right == NULL)
            {
                target = pDelete->Left;
            }
            else if(pDelete->Left == NULL)
            {
                target = pDelete->Right;
            }
            else
            {
                temp = pDelete->Right;
                while(temp->Left != NULL)
                    temp = temp->Left;

                temp->Left = pDelete->Left;
                target = pDelete->Right;
            }

            if(parent->Left == pDelete)
                parent->Left = target;
            else
                parent->Right = target;
        }

        delete pDelete;
    }

    void Traverse()
    {
        Display(root);
    }

    void Display(){
        if(root==NULL) return;
        LLStack<Node<T>> stk; //define a new stack of Nodes of T (contains pointers to nodes not actual nodes)
        stk.push(root); //push root to stack (stk now contains pointer to Node of T)
        int op = 0; // initializing Last Operation done as push (0) -> pop (1)
        while(!stk.isEmpty()) //Iterate as long as the stack is not empty
        {
            Node<T>*current = stk.last(); //Top of Stack
            if(op==0) //last operation was Push
            {


            if(current->Left== NULL){ //If Node has no left
                cout<<(current->Data)<<endl;    //display data
                stk.pop();                      //pop from stack
                op=1;                           //set last operation as Pop
                if(current->Right!=NULL)        //check right
                {
                    stk.push(current->Right);   //if node has right push the right into stack
                    op=0;                       //set last operation as Push
                }
            }
            else{
                stk.push(current->Left);        //If node has left, push left into stack
                op=0;                           //set last operation as Push
            }
            }
            else{ //if last operation was Pop
                cout<<(current->Data)<<endl;    //display data
                stk.pop();                      //pop from stack
                op=1;                           //set last operation as Pop
                if(current->Right!=NULL)        //check right
                {
                    stk.push(current->Right);   //if node has right push the right into stack
                    op=0;                       //set last operation as Push
                }
            }
        }
    }

private:
    Node<T>* Search(T data)
    {
        Node<T> *current = root;

        while(current != NULL)
        {
            if(data == current->Data)
                return current;

            if(data > current->Data)
                current = current->Right;
            else
                current = current->Left;
        }

        return NULL;
    }

    Node<T>* GetParent(Node<T>*child)
    {
        Node<T> *parent = root;

        while(parent != NULL)
        {
            if(parent->Left == child || parent->Right == child)
                return parent;

            if(child->Data > parent->Data)
                parent = parent->Right;
            else
                parent = parent->Left;
        }

        return NULL;
    }

    void Display(Node<T> *pDisplay)
    {
        if(pDisplay == NULL)
            return;

        Display(pDisplay->Left);

        cout << pDisplay->Data<< endl;

        Display(pDisplay->Right);
    }


};

#endif // BINARYTREE_H
