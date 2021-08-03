//
// Created by Ningyuan Gao on 2021-07-30.
//

#ifndef GROUP_GSET_H
#define GROUP_GSET_H

template <class T>
class Set {
private:
    using element = T;
    element * buffer;
    unsigned int size;
    unsigned int capacity;

public:
    Set();
    Set(const T * array, const unsigned int size_t);
    Set(const Set<T> & s);
    ~Set();
    unsigned int length() { return size; };
    int find(const T & item);
    T * remove(const T & item);
    void add(const T & item)
    Set<T> & set_union(const Set<T> & s);
    Set<T> & set_intersection(const Set<T> & s);

public:
    T & operator[](int i) { return buffer[i]; };
    Set<T> & operator=(Set<T> & set);
    Set<T> & operator+(Set<T> & set);
    Set<T> & operator+(T * item);

};

template <class T>
Set<T>::Set() {
    size = 0;
    capacity = 0;
    buffer = 0;
}

template <class T>
Set<T>::Set(const T * arr, const unsigned int size_t) {
    this->size = size_t;
    this->capacity = size_t;
    T * tmp_buff = new T [size_t];
    int count = 0;
    for (int i=0; i<size_t; i++) {
        bool flag = false;
        for (int j=0; j<i; j++) {
            if (arr[i] == tmp_buff[j]) {
                flag = true;
            }
        }
        if (!flag) {
            tmp_buff[count] = arr[i];
            count ++;
        }
    }
    this->size = count;
    this->capacity = count;
    this->buffer = new T [size];
    for (int i=0; i<count; i++) {
        this->buffer[i] = tmp_buff [i];
    }
}

template <class T>
Set<T>::Set<class T>(const Set<T> & s) {
    this->size = s.size;
    this->capacity = s.buffer;
    delete [] this->buffer;
    this->buffer = s.buffer;
}

template <class T>
Set<T>::~Set() {
    delete [] this->buffer;
}

template <class T>
int Set<T>::find(const T & item) {
    for (int i=0; i<this->size; i++) {
        if (*item == this->buffer[i]) {
            return i;
        }
    }
    return -1;
}

template <class T>
T * Set<T>::remove(const T * item) {
    int position = find(*item);
    if (position != -1) {
        this->size -= 1;
        this->capacity -= 1;
        T * tmp_buffer = new T [this->size];
        for (int i=0; i<position; i++) {
            tmp_buffer[i] = this->buffer[i];
        }
        for (int i=position; i<(this->size); i++) {
            tmp_buffer[i] = this->buffer[i + 1];
        }
        T * val = this->buffer[i];
        delete [] this->buffer;
        this->buffer = tmp_buffer;
        return val;
    }
    return nullptr;
}

template <class T>
void Set<T>::add(const T &item) {
    if (!*item) {
        return;
    }

    T * new_buffer = new T * [this->size + 1];
    for (int i=0; i<this->size; i++) {
        new_buffer[i] = this->buffer[i];
        if (*item == this->buffer[i]) {
            return;
        }
    }
    new_buffer[this->size] = *item;
    this->size += 1;
    this->capacity += 1;
    delete [] this->buffer;
    this->buffer = new_buffer;
}

template <class T>
Set<T> & Set<T>::set_intersection(const Set<T> & s) {
    int total = s.size + this->size;
    T * tmp_buffer = new T [total];
    for (int i=0; i<s.size; i++) {
        tmp_buffer[i] = s[i];
    }
    for (int i=0; i<this->size; i++) {
        tmp_buffer[s.size + i] = this->buffer[i];
    }
    return Set<T>(tmp_buffer, total);
}

template <class T>
Set<T> & Set<T>::set_union(const Set<T> & s) {
    auto new_set = new Set<T>();
    for (int i=0; i<s.size; i++) {
        for (int j=0; j<this->size; j++) {
            new_set->add(this->remove(*(s.buffer[i])));
        }
    }
    for (int i=0; i<this->size; i++) {
        for (int j=0; j<this->size; j++) {
            new_set->add(this->remove(*(s.buffer[i])));
        }
    }
    Set<T>::~Set<T>(s);
    Set<T>::~Set<T>(this);
    this = new_set;
    return *this;
}

template <class T>
Set<T> & Set<T>::operator+(Set<T> &set) {
    return Set<T>::set_union(set);
}

template <class T>
Set<T> & Set<T>::operator+(T *item) {
    this->add(item);
    return *this;
}

template <class T>
Set<T> & Set<T>::operator=(Set<T> &set) {
    this->capacity = set.capacity;
    this->size = set.size;
    delete [] this->buffer;
    this->buffer = set.buffer;
    return *this;
}

#endif //GROUP_GSET_H
