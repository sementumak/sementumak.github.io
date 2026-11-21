#pragma once

#include <iostream>
#include <algorithm>

class String{
public:
    String(){
        char* null = new char[1];
        *null = '\0';
        data = null;
        size = 0;
        capacity = 0;
    }


    String(const char* str){
        size_t strlen = 0;
        while(*str!='\0'){
            strlen += 1;
            str += 1;
        }
        data = new char[strlen+1];
        std::copy(str-strlen, str+1, data);
        size = strlen;
        capacity = strlen;
    }


    String(size_t n, char c){
        data = new char[n+1];
        std::fill(data, data+n, c);
        *(data + n) = '\0';
        size = n;
        capacity = n;
    }


    String(const String& other){
        data = new char[other.size+1];
        std::copy(other.data, other.data+other.size, data);
        *(data + other.size) = '\0';
        size = other.size;
        capacity = other.size;
    }


    ~String(){
        delete[] data;
    }


    String& operator=(const String& other){
        if (this == &other){
            return *this;
        }
        if (capacity >= other.size){
            capacity = capacity;
        }
        else{
            capacity = other.size;
            delete[] data;
            data = new char[other.size+1];
        }
        std::copy(other.data, other.data+other.size, data);
        *(data + other.size) = '\0';
        size = other.size;
        return *this;
    }


    char operator[](size_t i)const{
        return data[i];
    }


    char& operator[](size_t i){
        return data[i];
    }


    size_t Length()const{
        return size;
    }


    size_t Size()const{
        return size;
    }


    size_t Capacity()const{
        return capacity;
    }


    void PushBack(char a){
        if (size == capacity){
            if (capacity == 0){
                capacity += 1;
            }
            else{
                capacity = capacity * 2; 
            }
            char* new_data = new char[capacity + 1];
            std::copy(data, data + size, new_data);
            delete[] data;
            data = new_data;

            data[size] = a;
            data[size+1] = '\0';
            size += 1;
        }
        else{
            data[size] = a;
            data[size+1] = '\0';
            size += 1;
        }
    }


    void PopBack(){
        if (size > 0){
            data[size-1] = '\0';
            size -= 1;
        }
    }


    const char& Front()const{
        return data[0];
    }


    char& Front(){
        return data[0];
    }


    const char& Back()const{
        return data[size-1];
    }


    char& Back(){
        return data[size-1];
    }


    bool Empty()const{
        return size == 0;
    }


    void Clear(){
        size = 0;
        data[size] = '\0';
    }


    const char* Data()const{
        return &data[0];
    }

    char* Data(){
        return &data[0];
    }


    String& operator+=(const String& other){
        if(size + other.size <= capacity){
            std::copy(other.data, other.data + other.size, data + size);
            data[size + other.size] = '\0'; 
            size += other.size;
            return *this;
        }
        else{
            char* new_data = new char[size + other.size + 1];
            std::copy(data, data+size, new_data);
            std::copy(other.data, other.data + other.size, new_data+size);
            delete[] data;
            data = new_data;
            capacity = size + other.size;
            data[size + other.size] = '\0';
            size = size + other.size;
            return *this;
        }
    }


    String& operator+=(const char other){
        PushBack(other);
        return *this;
    }


    void ShrinkToFit(){
        if (capacity > size){
            char* new_data = new char[size + 1];
            std::copy(data, data + size + 1, new_data);
            delete[] data;
            data = new_data;
            capacity = size;
        }
    }


    size_t Find(const String& substring)const{
        if (substring.size == 0){
            return 0;
        }
        if (substring.size > size){
            return this->Length();
        }
        for(size_t i = 0; i <= size - substring.size; ++i){
            size_t j = 0;
            while(j < substring.size && data[i+j] == substring[j]){
                ++j;
            }
            if(j == substring.size){
                return i;
            }
        }
        return this->Length();
    }


    size_t Rfind(const String& substring)const{
        if (substring.size == 0){
            return this->Length();
        }
        if (substring.size > size){
            return this->Length();
        }
        for(size_t i = size; i >= substring.size; --i){
            size_t j = substring.size;
            while(j > 0 && data[i-j] == substring[substring.size - j]){
                --j;
            }
            if(j == 0){
                return i - substring.size;
            }
        }
        return this->Length();    
    }


    String Substr(const size_t start, const size_t count)const{
        if (start >= size || count == 0){
            return String();
        }
        String res(count, '\0');
        std::copy(data+start, data + start + count,res.data);
        return res;
    }


private:
    char* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};

String operator+(String lhs, const char rhs){
    lhs += rhs;
    return lhs;
}


String operator+(String lhs, const String& rhs){
    lhs += rhs;
    return lhs;
}


String operator+(char lhs, const String& rhs){
    String res(1, lhs);
    res += rhs;
    return res;
}


std::ostream& operator<<(std::ostream& os, const String& str) {
    for (size_t i = 0; i < str.Size(); ++i) {
        os << str[i];
    }
    return os;
}


std::istream& operator>>(std::istream& is, String& str) {
    str.Clear();
    char c;
    while (is >> c) {
        str.PushBack(c);
    }
    return is;
}


bool operator==(const String& lhs, const String& rhs) {
    if (lhs.Size() != rhs.Size()) {
        return false;
    }
    for (size_t i = 0; i < lhs.Size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}


bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}


bool operator>(const String& lhs, const String& rhs) {
    size_t i = 0;
    while (i < lhs.Size() && i < rhs.Size()) {
        if (lhs[i] < rhs[i]) {
            return false;
        }
        if (lhs[i] > rhs[i]) {
            return true;
        }
        ++i;
    }
    return i < lhs.Size();
}



bool operator<(const String& lhs, const String& rhs) {
    return rhs > lhs;
}


bool operator<=(const String& lhs, const String& rhs) {
    return !(rhs < lhs);
}


bool operator>=(const String& lhs, const String& rhs) {
    return !(lhs < rhs);
}