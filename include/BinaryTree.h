#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

using namespace std;

class BinaryTree
{
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void Add(int data)
    {
        Node *newNode = new Node(data);

        if(root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node *current = root, *parent;

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

    void Delete(int data)
    {
        Node *pDelete = Search(data);
        Node *temp;

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
            Node *parent = GetParent(pDelete);
            Node *target;

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

private:
    Node* Search(int data)
    {
        Node *current = root;

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

    Node* GetParent(Node *child)
    {
        Node *parent = root;

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

    void Display(Node *pDisplay)
    {
        if(pDisplay == NULL)
            return;

        Display(pDisplay->Left);

        cout << pDisplay->Data<< endl;

        Display(pDisplay->Right);
    }
};

#endif // BINARYTREE_H
