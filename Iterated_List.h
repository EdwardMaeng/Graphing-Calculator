#ifndef ITERATED_LIST_H
#define ITERATED_LIST_H

#include "../../Linked_List/linked_list_functions.h"

template <class T>
class List {
public:
    class Iterator {
    public:
        friend class List;
        Iterator() {
            _ptr = nullptr;
        }

        Iterator(node<T>* p) {
            _ptr = p;
        }

        T& operator *() {
            return _ptr->_item;
        }

        T* operator ->() {
            return &_ptr->_item;
        }

        bool is_null() {
            return(_ptr == nullptr);
        }

        friend bool operator !=(const Iterator& left, const Iterator& right) {
            return(left._ptr != right._ptr);
        }

        friend bool operator ==(const Iterator& left, const Iterator& right) {
            return(left._ptr == right._ptr);
        }

        Iterator& operator++() {
            _ptr = _ptr->_next;
            return *this;
        }

        friend Iterator operator++(Iterator& it, int unused) {
            Iterator hold = it;
            ++it;
            return hold;
        }

    private:
        node<T>* _ptr;
    };

    List();

    ~List();
    List(const List<T> &other);
    List<T>& operator =(const List<T> &other);

    Iterator InsertHead(T i);
    Iterator InsertAfter(T i, Iterator iMarker);
    Iterator InsertBefore(T i, Iterator iMarker);
    Iterator InsertSorted(T i, bool order);
    Iterator InsertSortedAndAdd(T i, bool order);

    T Delete(List<T>::Iterator iMarker);
    void Print() const;
    Iterator Search(const T &key);
    Iterator Prev(Iterator iMarker);

    T& operator[](int index) const;
    Iterator Begin() const;
    Iterator End() const;
    Iterator LastNode() const;
    T Random(T lo, T hi);

    void test_iterate();

    void test_list();

    template <class U>
    friend ostream& operator <<(ostream& outs, const List<U>& l);

private:
    node<T>* head_ptr;
    node<T>* _last_node;
    int _size;
};

template <class T>
List<T>::List() : head_ptr(nullptr), _size(0), _last_node(nullptr) {

}

template <class T>
List<T>::~List() {
    ::clear_list(head_ptr);
}

template <class T>
List<T>::List(const List<T> &other) {
    head_ptr = ::copy_list(other.head_ptr);
}

template <class T>
List<T>& List<T>::operator =(const List<T> &other) {
    if(this == &other) {
        return *this;
    }
    ::clear_list(head_ptr);

    head_ptr = ::copy_list(other.head_ptr);
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::InsertHead(T i) {
    Iterator it = ::insert_head(head_ptr, i);
    _size++;
    _last_node = ::last_node(head_ptr);
    return it;
}

template <class T>
typename List<T>::Iterator List<T>::InsertAfter(T i, Iterator iMarker) {
    Iterator it = ::insert_after(head_ptr, iMarker._ptr, i);
    _size++;
    _last_node = ::last_node(head_ptr);
    return it;
}

template <class T>
typename List<T>::Iterator List<T>::InsertBefore(T i, Iterator iMarker) {
    Iterator it = ::insert_before(head_ptr, iMarker._ptr, i);
    _size++;
    _last_node = ::last_node(head_ptr);
    return it;
}

template <class T>
typename List<T>::Iterator List<T>::InsertSorted(T i, bool order) {
    Iterator it = ::insert_sorted(head_ptr, i, order);
    _size++;
    _last_node = ::last_node(head_ptr);
    return it;
}

template <class T>
typename List<T>::Iterator List<T>::InsertSortedAndAdd(T i, bool order) {
    Iterator it = ::insert_sorted_and_add(head_ptr, i, order);
    _size++;
    _last_node = ::last_node(head_ptr);
    return it;
}

template <class T>
T List<T>::Delete (List<T>::Iterator iMarker) {
    _size--;
    _last_node = ::last_node(head_ptr);
    return ::delete_node(head_ptr, iMarker._ptr);
}

template <class T>
void List<T>::Print() const {
    ::print_list(head_ptr);
}

template <class T>
typename List<T>::Iterator List<T>::Search(const T &key) {
    return ::search_list(head_ptr, key);
}

template <class T>
typename List<T>::Iterator List<T>::Prev(Iterator iMarker) {
    try {
        return ::previous_node(head_ptr, iMarker._ptr);
    }
    catch(string p) {
        cout << "Error in Previous Node (Prev): " << p << endl;
        throw p;
    }
}

template <class T>
T& List<T>::operator[](int index) const {
    return ::at(head_ptr, index);
}

template <class T>
typename List<T>::Iterator List<T>::Begin() const {
    return head_ptr;
}

template <class T>
typename List<T>::Iterator List<T>::End() const {
    return nullptr;
}

template <class T>
typename List<T>::Iterator List<T>::LastNode() const {
    return ::last_node(head_ptr);
}

template <class T>
T List<T>::Random(T lo, T hi) {
    srand(time(NULL));
    int r = rand() % (hi - lo + 1) + lo;
    return r;
}

template <class U>
ostream& operator <<(ostream& outs, const List<U>& l) {
    ::print_list(l.head_ptr, outs);
    return outs;
}

template <class T>
void List<T>::test_iterate() {
    List<int> l;

    l.InsertHead(5);
    l.InsertHead(3);
    l.InsertHead(7);
    l.InsertHead(9);
    l.InsertHead(10);
    l.InsertHead(15);

    List<int>::Iterator it1;

    it1 = l.Begin();

    cout << "it = " << *it1 << endl;

    List<int>::Iterator it2 = it1;

    cout << "it2 = " << *it2 << endl;

    if(it1 == it2) {
        cout << "it1 == it2" << endl;
    }

    List<int>::Iterator it3 = it1;

    it3++;

    cout << "it3 = " << *it3 << endl;

    if(it1 != it3) {
        cout << "it3 != it1" << endl;
    }

    for(it1 = l.Begin(); it1 != l.End(); it1++) {
        cout << *it1 << "|";
    }
    cout << endl;

}

template <class T>
void List<T>::test_list() {
    List<int> l;

    l.InsertHead(17);
    l.InsertHead(35);
    l.InsertHead(6);
    l.InsertHead(54);
    l.InsertHead(6);

    List<int>::Iterator crusor = l.Begin();
    int insertThis;
    char choice;
    bool done = false;

    cout << "----------------------------" << endl;
    cout << "[R]andom [A]fter [B]efore [D]elete [S]earch [P]revious [N]ext [H]ome [E]nd [?] e[x]it" << endl;
    cout << "----------------------------" << endl;

    do {
        List<int>::Iterator walker = l.Begin();
        cout << "H->";

        while(walker != NULL) {
            if(crusor == walker) {
                cout << "{" << *walker << "}->";
            }
            else {
                cout << "[" << *walker << "]->";
            }
            ++walker;
        }
        cout << "|||" << endl;

        cin >> choice;

        switch (toupper(choice)) {
        case 'R':
        case 'r':
            if(crusor != NULL) {
                l.InsertAfter(l.Random(1, 99), crusor);
                ++crusor;
            }
            else {
                l.InsertHead(l.Random(1, 99));
                crusor = l.Begin();
            }
            break;
        case 'A':
        case 'a':
            cout << ">> ";
            cin >> insertThis;
            if(crusor != NULL) {
                l.InsertAfter(insertThis, crusor);
                ++crusor;
            }
            else {
                l.InsertHead(insertThis);
                crusor = l.Begin();
            }
            break;
        case 'B':
        case 'b':
            cout << ">> ";
            cin >> insertThis;
            if(crusor != NULL) {
                l.InsertBefore(insertThis, crusor);
                crusor = l.Prev(crusor);
            }
            else {
                l.InsertHead(insertThis);
                crusor = l.Begin();
            }
            break;
        case 'D':
        case 'd':
            if(crusor != NULL) {
                l.Delete(crusor);
            }
            crusor = l.Begin();
            break;
        case 'S':
        case 's':
            cout << ">> ";
            cin >> insertThis;
            crusor = l.Search(insertThis);
            break;
        case 'P':
        case 'p':
            if(crusor != l.Begin()) {
                crusor = l.Prev(crusor);
            }
            break;
        case 'N':
        case 'n':
            if(crusor != l.LastNode()) {
                ++crusor;
            }
            break;
        case 'H':
        case 'h':
            crusor = l.Begin();
            break;
        case 'E':
        case 'e':
            crusor = l.LastNode();
            break;
        case '?':
            cout << "----------------------------" << endl;
            cout << "[R]andom [A]fter [B]efore [D]elete [P]revious [N]ext [H]ome [E]nd [?] e[x]it" << endl;
            cout << "----------------------------" << endl;
            break;
        case 'x':
        case 'X':
            done = true;
            cout << "THANKS! ADIOS!" << endl;
            break;
        default:
            cout << "Invalid choice: " << choice << endl;
            break;
        }
        cout << "..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   ..   .." << endl;
    } while (!done);

    cout << "-------------------------END------------------------" << endl;
}


#endif // ITERATED_LIST_H
