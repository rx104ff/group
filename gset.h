//
// Created by Ningyuan Gao on 2021-07-30.
//

#ifndef GROUP_GSET_H
#define GROUP_GSET_H

template <class T>
class Set {
private:
    T * buffer;
    int size{};
    int capacity{};

public:
    Set();
    Set(const T * array, int size_t);
    Set(const Set<T> & s);
    ~Set();
    int length() { return size; };
    int find(const T & item);
    bool remove(const T & item);
    bool add(const T & item);
    Set<T> & set_union(const Set<T> & s);
    Set<T> & set_intersection(const Set<T> & s);
    void print();

public:
    T & operator[](int i);
    Set<T> & operator=(const Set<T> & set);
    Set<T> & operator+(const Set<T> & set);
    Set<T> & operator+(const T  & item);
    Set<T> & operator-(const Set<T> & set);
    Set<T> & operator-(const T & item);
    Set<T> & operator*(const Set<T> & set);
};

template <class T>
void Set<T>::print() {
    for (int i=0; i<this->size; i++){
        std::cout<<this->buffer[i]<<" ";
    }
}

template <class T>
Set<T>::Set() {
    size = 0;
    capacity = 0;
    buffer = 0;
}

template <class T>
Set<T>::Set(const T * arr, int size_t) {
    auto tmp_buff = new T [size_t];
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
    buffer = new T [count];
    memcpy(buffer, tmp_buff, count * sizeof(T));
    capacity = count;
    size = count;
}

template <class T>
Set<T>::Set(const Set<T> & s) {
    size = s.size;
    capacity = s.capacity;
    buffer = new T [size];
    for (int i=0; i<size; i++) {
        buffer[i] = s.buffer[i];
    }
}

template <class T>
Set<T>::~Set() {
    delete [] buffer;
}

template <class T>
int Set<T>::find(const T & item) {
    for (int i=0; i<size; i++) {
        if (item == buffer[i]) {
            return i;
        }
    }
    return -1;
}

template <class T>
bool Set<T>::remove(const T & item) {
    int position = find(item);
    if (position != -1) {
        size -= 1;
        capacity -= 1;
        T * tmp_buffer = new T [size];
        for (int i=0; i<position; i++) {
            tmp_buffer[i] = buffer[i];
        }
        for (int i=position; i<(size); i++) {
            tmp_buffer[i] = buffer[i + 1];
        }
        delete [] buffer;
        buffer = tmp_buffer;
        return true;
    }
    return false;
}

template <class T>
bool Set<T>::add(const T & item) {
    T * new_buffer = new T [size + 1];
    for (int i=0; i<size; i++) {
        new_buffer[i] = buffer[i];
        if (item == buffer[i]) {
            return false;
        }
    }
    new_buffer[size] = item;
    size += 1;
    capacity += 1;
    delete [] buffer;
    buffer = new_buffer;
    return true;
}

template <class T>
Set<T> & Set<T>::set_union(const Set<T> & s) {
    int total = s.size + size;
    T * tmp_buffer = new T [total];
    for (int i=0; i<s.size; i++) {
        tmp_buffer[i] = s.buffer[i];
    }

    for (int i=0; i<size; i++) {
        tmp_buffer[s.size + i] = buffer[i];
    }

    delete [] buffer;
    auto new_set = Set<T>(tmp_buffer, total);
    size = new_set.size;
    capacity = new_set.capacity;
    buffer = new T [size];
    memcpy(buffer, new_set.buffer, size * sizeof(T));
    return *this;
}

template <class T>
Set<T> & Set<T>::set_intersection(const Set<T> & s) {
    auto new_set = Set<T>();
    auto s_copy =  Set<T>(s);
    for (int i=0; i<s.size; i++) {
        if (this->remove(s.buffer[i])) {
            new_set.add(s.buffer[i]);
        }
    }
    for (int i=0; i<size; i++) {
        if (s_copy.remove(buffer[i])) {
            new_set.add(buffer[i]);
        }
    }
    size = new_set.size;
    capacity = new_set.capacity;
    delete [] buffer;
    buffer = new T [size];
    memcpy(buffer, new_set.buffer, size * sizeof(T));
    return *this;
}

template <class T>
Set<T> & Set<T>::operator+(const Set<T> & set) {
    auto new_set = new Set<T>(set);
    new_set.set_union(set);
    return *new_set;
}

template <class T>
Set<T> & Set<T>::operator+(const T & item) {
    auto new_set = new Set<T>(*this);
    new_set->add(item);
    return *new_set;
}

template <class T>
Set<T> & Set<T>::operator=(const Set<T> & set) {
    if (&set != this) {
        delete [] buffer;
        capacity = set.capacity;
        size = set.size;
        buffer = new T [size];
        memcpy(buffer, set.buffer, size * sizeof(T));
        return *this;
    }
}

template <class T>
Set<T> & Set<T>::operator-(const T & item) {
    auto new_set = new Set<T>(*this);
    new_set->remove(item);
    return *new_set;
}

template <class T>
Set<T> & Set<T>::operator-(const Set<T> & set) {
    auto new_set = new Set<T>(*this);
    for (int i=0; i<set.size; i++) {
        new_set->remove(set.buffer[i]);
    }
    return *new_set;
}

template <class T>
T & Set<T>::operator[](int i) {
    return buffer[i];
}

template <class T>
Set<T> & Set<T>::operator*(const Set<T> & set) {
    auto new_set = new Set<T>(*this);
    new_set->set_intersection(set);
    return *new_set;
}


#endif //GROUP_GSET_H
