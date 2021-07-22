//
// Created by Ningyuan Gao on 2021-07-20.
//

#ifndef GROUP_STRING_H
#define GROUP_STRING_H

class String {
private:
    char *str;
    int len;
    static int num;

public:
    String(const char *s);
    String();
    String(const String &);
    ~String();
    int length() const { return len };
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);

public:
    void append(const String &);
    void append(const char * s);
    void pop();
};

String::String(const char *s) {
    len = std::strlen(s);
    str = new char [len + 1];
    std::strcpy_s(str, len + 1, s);
    num ++;
}

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

#endif //GROUP_STRING_H
