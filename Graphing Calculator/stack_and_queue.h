#ifndef STACK_H
#define STACK_H

#include "../../Iterated_List/Iterated_List/Iterated_List.h"

template <class T>
class Stack {
public:
    class Iterator {
    public:
        friend class Stack;
        Iterator() {
            _ptr = nullptr;
        }

        Iterator(typename List<T>::Iterator p) {
            _ptr = p;
        }

        T operator *() {
            return *_ptr;
        }

        bool is_null() {
            return (_ptr == NULL);
        }

        friend bool operator !=(const Iterator& left, const Iterator& right) {
            return(left._ptr != right._ptr);
        }

        friend bool operator ==(const Iterator& left, const Iterator& right) {
            return(left._ptr == right._ptr);
        }

        Iterator& operator++() {
            ++_ptr;
        }

        friend Iterator operator++(Iterator& it, int unused) {
            it._ptr++;
        }

    private:
        typename List<T>::Iterator _ptr;
    };

    Stack();

    //BIG THREE
    Stack(const Stack& other);
    Stack<T>& operator =(const Stack& other);

    Iterator top();
    bool empty();
    Iterator push(const T& item);
    T pop();
    int size() const;

    Iterator Begin() const;
    Iterator End() const;

    void print_stack() const;

private:
    List<T> _s;
    typename List<T>::Iterator _top;
    int _size;
};

template <class T>
Stack<T>::Stack() : _top(nullptr), _size(0) {

}

//BIG THREE
template <class T>
Stack<T>::Stack(const Stack& other) {
    List<T> copy(other._s);
    _s = copy;
    _top = _s.Begin();
    _size = other._size;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if(this == &other) {
        return *this;
    }
    _s = other._s;
    _top = _s.Begin();
    _size = other._size;
    return *this;
}

template <class T>
typename Stack<T>::Iterator Stack<T>::top() {
    return Begin();
}

template <class T>
bool Stack<T>::empty() {
    return (_top == NULL);
}

template <class T>
typename Stack<T>::Iterator Stack<T>::push(const T& item) {
    Iterator it = _s.InsertHead(item);
    _top = _s.Begin();
    _size++;
    return it;
}

template <class T>
T Stack<T>::pop() {
    if(empty()) {
        throw _size;
    }
    T hold = _s.Delete(_top);
    _top = _s.Begin();
    _size--;
    return hold;
}

template <class T>
int Stack<T>::size() const {
    return _size;
}

template <class T>
typename Stack<T>::Iterator Stack<T>::Begin() const {
    return Iterator(_s.Begin());
}

template <class T>
typename Stack<T>::Iterator Stack<T>::End() const {
    return Iterator(_s.End());
}

template <class T>
void Stack<T>::print_stack() const {
    _s.Print();
}

template <class T>
class Queue {
public:
    class Iterator {
    public:
        friend class Queue;
        Iterator() {
            _ptr = nullptr;
        }

        Iterator(typename List<T>::Iterator p) {
            _ptr = p;
        }

        T operator *() {
            return *_ptr;
        }

        bool is_null() {
            return(_ptr == NULL);
        }

        friend bool operator !=(const Iterator& left, const Iterator& right) {
            return(left._ptr != right._ptr);
        }

        friend bool operator ==(const Iterator& left, const Iterator& right) {
            return(left._ptr == right._ptr);
        }

        Iterator& operator++() {
            ++_ptr;
        }

        friend Iterator operator++(Iterator& it, int unused) {
            it._ptr++;
        }      

    private:
        typename List<T>::Iterator _ptr;
    };

    Queue();

    //BIG THREE
    Queue(const Queue& other);
    Queue<T>& operator =(const Queue& other);

    Iterator front();
    Iterator back();
    bool empty();
    Iterator push(const T& item);
    T pop();
    int size() const;

    Iterator Begin() const;
    Iterator End() const;

    void print_queue() const;

private:
    List<T> _s;
    typename List<T>::Iterator _front;
    typename List<T>::Iterator _back;
    int _size;
};

template <class T>
Queue<T>::Queue() : _front(nullptr), _back(nullptr), _size(0) {

}

//BIG THREE
template <class T>
Queue<T>::Queue(const Queue& other) {
    List<T> copy(other._s);
    _s = copy;
    _front = _s.Begin();
    _back = _s.LastNode();
    _size = other._size;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if(this == &other) {
        return *this;
    }
    _s = other._s;
    _front = _s.Begin();
    _back = _s.LastNode();
    _size = other._size;
    return *this;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::front() {
    return Iterator(Begin());
}

template <class T>
typename Queue<T>::Iterator Queue<T>::back() {
    return Iterator(_s.LastNode());
}

template <class T>
bool Queue<T>::empty() {
    return (_front == NULL);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::push(const T& item) {
    Iterator it;
    if(empty()) {
        it = _s.InsertHead(item);
    }
    else {
        it = _s.InsertAfter(item, _back);
    }
    _front = _s.Begin();
    _back = _s.LastNode();
    _size++;
    return it;
}

template <class T>
T Queue<T>::pop() {
    if(empty()) {
        throw _size;
    }
    T hold = _s.Delete(_front);
    _front = _s.Begin();
    if(empty()) {
        _back = _s.Begin();
    }
    else {
        _back = _s.LastNode();
    }
    _size--;
    return hold;
}

template <class T>
int Queue<T>::size() const {
    return _size;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Begin() const {
    return Iterator(_s.Begin());
}

template <class T>
typename Queue<T>::Iterator Queue<T>::End() const {
    return Iterator(_s.End());
}

template <class T>
void Queue<T>::print_queue() const {
    _s.Print();
}

#endif // STACK_H
