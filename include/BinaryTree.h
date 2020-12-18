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
        LLStack<Node<T>> stk;
        stk.push(root);
        int op = 0;
        while(!stk.isEmpty())
        {
            Node<T>*current = stk.last();
            if(op==0) //last operation was Push
            {


            if(current->Left== NULL){
                cout<<(current->Data)<<endl;
                stk.pop();
                op=1;
                if(current->Right!=NULL)
                {
                    stk.push(current->Right);
                    op=0;
                }
            }
            else{
                stk.push(current->Left);
                op=0;
            }
            }
            else{
                 cout<<(current->Data)<<endl;
                stk.pop();
                op=1;
                if(current->Right!=NULL)
                {
                    stk.push(current->Right);
                    op=0;
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
