#include"student.h"

student::student() : _initial(""), _group(0), _number(0), _size(4), _arr(new int[4]) {}
student::student(std::string initial, int group, int number, int* arr, int size) : _initial(initial), _group(group), _number(number), _size(size), _arr(new int[size]) {
    for (int i = 0; i < size; i++) {
        this->_arr[i] = arr[i];
    }
}
student::student(const student& _student) : _initial(_student._initial), _group(_student._group), _number(_student._number), _size(_student._size), _arr(new int[_student._size]) {
    for (int i = 0; i < _size; i++) {
        this->_arr[i] = _student._arr[i];
    }
}
student::student(student&& _student) : _initial(_student._initial), _group(_student._group), _number(_student._number), _size(_student._size), _arr(_student._arr) {
    _student._arr = nullptr;
}
student& student::operator=(const student& _student) {
    this->_initial = _student._initial;
    this->_group = _student._group;
    this->_number = _student._number;
    this->_size = _student._size;
    this->_arr = new int[_student._size];
    for (int i = 0; i < _student._size; i++) {
        this->_arr[i] = _student._arr[i];
    }
    return *this;
}
bool student::operator<(const student& _student) const {
    return this->_initial < _student._initial;
}
bool student::operator==(const student& _student) const {
    return this->_initial == _student._initial &&
        this->_number == _student._number &&
        this->_size == _student._size &&
        this->_group == _student._group &&
        std::equal(this->_arr, this->_arr + this->_size, _student._arr);
}
student::~student() {
    delete[] _arr;
}
const std::string student::get_initial() const {
    return _initial;
}
std::ostream& operator<<(std::ostream& os, const student& _student) {
    os << "[Initial: " << _student._initial << "]\n[Group: " << _student._group << "]\n[Number: " << _student._number << "]\n[Grades: [";
    for (int i = 0; i < _student._size; i++) {
        os << _student._arr[i];
        if (i < _student._size - 1) {
            os << ", ";
        }
    }
    os << "]]\n";
    return os;
}

std::istream& operator>>(std::istream& is, student& _student) {
    is >> _student._initial >> _student._group >> _student._number >> _student._size;
    _student._arr = new int[_student._size];
    for (int i = 0; i < _student._size; i++) {
        is >> _student._arr[i];
    }
    return is;
}
std::size_t hash_student::operator()(const student& _student) const {
    return std::hash<std::string>()(_student.get_initial());
}