//
// Created by Ningyuan Gao on 2021-07-20.
//

#ifndef GROUP_GSTRING_H
#define GROUP_GSTRING_H

#include <cstring>
#include <iostream>

class String {
private:
    char *str;
    int len;
    static int num;
    static const int CINLIM = 80;

private:
    static char* resize(char*& old, int length, int resize_to);

public:
    String(const char *s);
    String();
    String(const String &);
    ~String();
    int length() const { return len; };
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    friend std::ostream & operator<<(std::ostream & os, const String & st);
    friend std::istream & operator>>(std::istream & is, String & st);

public:
    void append(const String &);
    void append(const char * s);
    void pop_back();
    void pop_back(int n);
    void pop_front();
    void pop_front(int n);
};

String::String(const char *s) {
    len = std::strlen(s);
    str = new char [len + 1];
    strcpy(str, s);
    num ++;
}

int String::num = 0;

String::String() {
    len = 4;
    str = new char [5];
    str[0] = '\0';
    num ++;
}

String::~String() {
    -- num;
    delete [] str;
}

void String::append(const char *s) {
    strcat(this->str, s);
    this->len = strlen(this->str);
}

void String::pop_back() {
    if (this->len>0) {
        this->str = resize(this->str, this->len, this->len-1);
    }
}

void String::pop_back(const int n) {
    for (int i=0; i<n; i++) {
        pop_back();
    }
}

void String::pop_front() {
    char* new_ptr;
    new_ptr = new char [this->len];
    for(int i=0; i<this->len; i++) {
        new_ptr[i] = this->str[i+1];
    }
    delete [] this->str;
    this->str = new_ptr;
    --this->len;
}

void String::pop_front(const int n) {
    char* new_ptr;
    this->len -= n;
    new_ptr = new char [this->len + 1];
    for(int i=0; i<this->len; i++) {
        new_ptr[i] = this->str[i+n];
    }
    delete [] this->str;
    this->str = new_ptr;
    --this->len;
}

String & String::operator=(const String & st) {
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * s) {
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char & String::operator[](int i) {
    return str[i];
}

char* String::resize(char*& old, int length, int resize_to) {
    char* new_ptr;
    new_ptr = new char [resize_to];
    int least = (length < resize_to) ? length : resize_to;
    for(int i=0; i<least; ++i)
        new_ptr[i] = old[i];
    delete [] old;
    old = nullptr;
    return new_ptr;
}

std::ostream & operator<<(std::ostream & os, const String & st) {
    os << st.str;
    return os;
}

std::istream & operator>>(std::istream & is, String & st) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) {
        st = temp;
    }
    while (is && is.get() != '\n') {
        continue;
    }
    return is;
}

String::String(const String & st) {
    num++;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);
}

void String::append(const String & st) {
    strcat(this->str, st.str);
    this->len = strlen(this->str);
}

#endif //GROUP_GSTRING_H
