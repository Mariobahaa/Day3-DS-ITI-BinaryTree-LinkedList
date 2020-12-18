#ifndef LNODE_H
#define LNODE_H

template<class T>
class lNode
{
    public:
        T*Data;
        lNode *Next, *Prev;

        lNode(T *data)
        {
            Data = data;
            Next = Prev = NULL;
        }

};

#endif // LNODE_H


