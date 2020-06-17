#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class CircularQueue
{
    int size,head,tail,curr_size;
    int *Queue;
    
    public:
    CircularQueue(int k)
    {
        size=k;
        Queue=new int [size];
        curr_size=0;
        head=0;
        tail=-1;
    }
    int front()
    {
       if (curr_size) return Queue[head];
       return -1;
    }
    int rear()
    {
        if (curr_size) return Queue[tail];
        return -1;
    }
    bool enqueue(int value)
    {
        if (curr_size==size) return false;
        else
        {
            tail++;
            tail%=size;
            Queue[tail]=value;
            curr_size++;
            return true;
        }
    }
    bool dequeue()
    {
        if (curr_size)
        {
        head++;
        curr_size--;
        return true;
        }
        return false;
        
    }
    bool isEmpty()
    {
        if (curr_size) return false;
        return true;
    }
    bool isFull()
    {
        if (curr_size==size) return true;
        return false;
    }
};

int main()
{
    CircularQueue myQueue(4);
    cout<<myQueue.enqueue(1)<<'\n';
    cout<<myQueue.enqueue(2)<<'\n';
    cout<<myQueue.enqueue(3)<<'\n';
    cout<<myQueue.enqueue(4)<<'\n';
    cout<<myQueue.enqueue(5)<<'\n';
    cout<<myQueue.front()<<'\n';
    cout<<myQueue.rear()<<'\n';
    cout<<myQueue.isFull()<<'\n';
    cout<<myQueue.dequeue()<<'\n';
    cout<<myQueue.enqueue(5)<<'\n';
    cout<<myQueue.front()<<'\n';
    cout<<myQueue.rear()<<'\n';
    cout<<myQueue.dequeue()<<'\n';
    cout<<myQueue.enqueue(100)<<'\n';
    cout<<myQueue.front()<<'\n';
    cout<<myQueue.rear()<<'\n';
    
    
}