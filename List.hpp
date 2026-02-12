#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class List {
protected:
    int length;

public:
    List() : length(0) {}
    virtual ~List() {}

    virtual void append(const T&) = 0;
    virtual void clear() = 0;

    // Return by reference so stored objects can be modified (e.g. addCourse).
    virtual T& getElement(int) = 0;
    virtual const T& getElement(int) const = 0;

    virtual int getLength() const = 0;
    virtual void insert(int, const T&) = 0;
    virtual bool isEmpty() const = 0;
    virtual void remove(int) = 0;
    virtual void replace(int, const T&) = 0;
};

#endif // LIST_HPP