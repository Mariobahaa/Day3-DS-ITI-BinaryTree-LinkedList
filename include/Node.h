#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    public:
        T Data;
        Node* Left, *Right;

        Node(int data)
        {
            Data = data;
            Left = Right = NULL;
        }
};

#endif // NODE_H
