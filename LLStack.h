#ifndef LLSTACK_H
#define LLSTACK_H

#include "LinkedList.h"
#include<iostream>

using namespace std;

template<class T>
class LLStack
{
    private:
    LinkedList<T> stk;
    int top;
    public:
        void push(T*data){
            stk.Add(data);
            top++;
        }

        T*pop(){
            if(stk.getHead()==NULL) return NULL;
            T*temp = stk.getTail();
            stk.DeleteByIndex(top);
            top--;
            return temp;

        }
        LLStack(){top=-1;}
        void display(){stk.Display();}

        T*last(){
            return stk.getTail();
        }
        bool isEmpty(){
            return !(top+1);
        }
        //virtual ~LLStack();

    protected:

};

#endif // LLSTACK_H
