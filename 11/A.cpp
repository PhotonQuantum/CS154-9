#include <iostream>

#include <cstring>

using namespace std;



class Stack

{
private:
    int *bottom_ptr;
    int *top_ptr;
    int capacity;
    void double_capacity(){
        capacity *= 2;
        int *new_bottom_ptr = new int[capacity];
        for (int i = 0; i < top_ptr - bottom_ptr + 1; i++)
            new_bottom_ptr[i] = bottom_ptr[i];
        top_ptr = new_bottom_ptr + (top_ptr - bottom_ptr);
        delete[] bottom_ptr;
        bottom_ptr = new_bottom_ptr;
    }

public:

    bool isEmpty() const //判断是否为空

    {
        return top_ptr < bottom_ptr;
    }



    //出栈

    void pop() //删除栈顶元素

    {
        if (top_ptr >= bottom_ptr) top_ptr -= 1;
    }



    void push(int val) //插入一个元素

    {
        if (top_ptr - bottom_ptr == capacity - 1) double_capacity();
        top_ptr += 1;
        *top_ptr = val;
    }



    int size() const //返回栈元素个数

    {
        return top_ptr - bottom_ptr + 1;
    }



    // //构造函数

    Stack(int cap=100)

    {
        capacity = cap;
        bottom_ptr = new int[capacity];
        top_ptr = bottom_ptr - 1;
    }

    Stack(const Stack& s)  {
        if (s.size() == 0){
            capacity = 100;
            bottom_ptr = new int[capacity];
            top_ptr = bottom_ptr - 1;
        } else {
            capacity = s.size();
            bottom_ptr = new int[capacity];
            int i = 0;
            for (i=0; i<s.size(); i++)
                bottom_ptr[i] = s.bottom_ptr[i];
            top_ptr = bottom_ptr + i - 1;
        }
    }

 

    //析构

    ~Stack()

    {
        delete[] bottom_ptr;
    }



    //输出栈顶元素

    int top()

    {
        return *top_ptr;
    }

};









int main() {

    Stack s(100);

    for (int i = 0; i < 90; i++) {

        s.push(i);

    }

    Stack s2(s);

    for (int i = 0; i < 90; i++) {

        s.pop();

    }

    cout << s.isEmpty() << endl;

    cout << s2.size() << endl;

    cout << s2.top()<<endl;

    return 0;

} 
