#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "List.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList : public List<T> {
protected:
    struct Node {
        T value;
        Node* next;
        Node(const T& v = T(), Node* n = nullptr) : value(v), next(n) {}
    };

    Node* head;

public:
    LinkedList();
    virtual ~LinkedList();

    void append(const T& elem) override;
    void clear() override;
    T& getElement(int) override;
    const T& getElement(int) const override;
    int getLength() const override;
    void insert(int, const T&) override;
    bool isEmpty() const override;
    void remove(int) override;
    void replace(int, const T&) override;

    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<U>&);
};

#include "LinkedList.tpp"
#endif // LINKEDLIST_HPP