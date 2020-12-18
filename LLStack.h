#ifndef LLSTACK_H
#define LLSTACK_H

#include "E:\Career\ITI\CDB\Day1-DS-ITI\include\LinkedList.h"
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
        //virtual ~LLStack();

    protected:

};

#endif // LLSTACK_H
