#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class CircularQueue
{
    int size, head, tail, curr_size;
    int *Queue;

public:
    CircularQueue(int k)
    {
        size = k;
        Queue = new int[size];
        curr_size = 0;
        head = 0;
        tail = -1;
    }
    int front()
    {
        if (curr_size)
            return Queue[head];
        return -1;
    }
    int rear()
    {
        if (curr_size)
            return Queue[tail];
        return -1;
    }
    bool enqueue(int value)
    {
        if (curr_size == size)
            return false;
        else
        {
            tail++;
            tail %= size;
            Queue[tail] = value;
            curr_size++;
            return true;
        }
    }
    bool dequeue()
    {
        if (curr_size)
        {
            head++;
            head %= size;
            curr_size--;
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (curr_size)
            return false;
        return true;
    }
    bool isFull()
    {
        if (curr_size == size)
            return true;
        return false;
    }
};

int main()
{
    int n, k, t1;
    cout << "enter n and k" << '\n';
    cin >> n >> k;
    int inputArray[n];
    CircularQueue circle(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inputArray[i];
        circle.enqueue(inputArray[i]);
    }

    while (!circle.isEmpty())
    {
        for (int j = 0; j < k; j++)
        {
            if (j < k - 1)
            {
                t1 = circle.front();
                circle.dequeue();
                circle.enqueue(t1);
            }
            else
            {
                circle.dequeue();
            }
        }
    }
    cout << t1 << '\n';
}