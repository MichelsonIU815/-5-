#include<iostream>

#pragma once
class student {
private:
    std::string _initial;
    int _group, _number, _size = 4;
    int* _arr;
public:

    student();
    student(std::string, int, int, int*, int);
    student(const student&);
    student(student&&);
    student& operator=(const student&);
    bool operator<(const student& _student) const;
    bool operator==(const student& _student) const;
    ~student();
    const std::string get_initial() const;
    friend std::ostream& operator<<(std::ostream&, const student&);
    friend std::istream& operator>>(std::istream&, student&);
};
struct hash_student {
    std::size_t operator()(const student& _student) const;
};