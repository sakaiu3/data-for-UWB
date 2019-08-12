#include "queue.h"
#include <iostream>
template <class T>
Queue<T>::Queue() {
    length=0;
    front=NULL;
    back=NULL;// TODO
}

template <class T>
Queue<T>::Queue(Queue &other) {
    length = other.length;
    if (other.front == NULL) {
        front = new Node<T>();
    } else {
        front = new Node<T>(*(other.front));
        copy(this->front, other.front);
        Node<T> *temp=front;
        while(1)
        {
            if(temp->get_next()==NULL)
            {
                back=temp;
                break;
            }
            temp=temp->get_next();
        }
    }// TODO
}

template <class T>
Queue<T>::~Queue() {
    remove(front);// TODO
}

template <class T>
Queue<T> &Queue<T>::operator=(Queue &other) {
    length = other.length;
    if (other.front == NULL) {
        front = new Node<T>();
    } else {
        front = new Node<T>(*(other.front));
        copy(this->front, other.front);
        Node<T> *temp=front;
        while(1)
        {
            if(temp->get_next()==NULL)
            {
                back=temp;
                break;
            }
            temp=temp->get_next();
        }
    }
    return *this;// TODO
}

template <class T>
int Queue<T>::get_size() const {
    return length;// TODO
}

template <class T>
void Queue<T>::push(T *t) {
    if(t==NULL) return;
    Node<T> *temp=new Node<T>(t);
    if(length==0)
    {
        front=temp;
        back=temp;
        length++;
        return;
    }
    back->next=temp;
    back=back->next;
    length++;// TODO
    return;
}

template <class T>
void Queue<T>::push(Node<T> *n) {
    if(n==NULL) return;
    if(length==0)
    {
        front=n;
        back=n;
        length++;
        return;
    }
    back->next=n;
    back=back->next;
    length++;// TODO
    return;// TODO
}

template <class T>
Node<T> *Queue<T>::pop() {
    if(length==0) return NULL;// TODO
    Node<T> *temp=front;
    front=front->next;
    length--;
    return temp;
}

template <class T>
void Queue<T>::print(Node<T> *n){
    if(n->next==NULL)
    {
        n->print();
        return;
    }
    print(n->next);
    n->print();
    return;
}
template <class T>
void Queue<T>::print() {
    Node<T> *p = front;
    print(p);
    std::cout<<"END\n";
    return;
}

template <class T>
void Queue<T>::copy(Node<T> *this_, Node<T> *other_) {
    if (other_->get_next() == NULL) {
        return;
    }
    this_->set_next(new Node<T>(*(other_->get_next())));
    copy(this_->get_next(), other_->get_next());
    return;
}
template <class T>
void Queue<T>::remove(Node<T> *n) {
    if (n == NULL) {
        return;
    }
    if (n->get_next() == NULL) {
        delete n;
        return;
    }
    Node<T> *tmp = n->get_next();
    delete n;
    remove(tmp);
    return;
}
