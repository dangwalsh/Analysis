//
//  ThreeSum.h
//  Analysis-Algorithms
//
//  Created by Daniel Walsh on 4/6/14.
//  Copyright (c) 2014 Daniel Walsh. All rights reserved.
//

#ifndef __Analysis_Algorithms__ThreeSum__
#define __Analysis_Algorithms__ThreeSum__

#include <iostream>

class ThreeSum
{
private:
    int *a;
    unsigned sz;
public:
    //constructors
    ThreeSum()
    :sz(0),a(new int[0]){
        std::cout << "default const\n";
    }
    ThreeSum(int n)
    :sz(n),a(new int[n]){
        std::cout << "param const\n";
    }
    ThreeSum(const ThreeSum& rhs) {
        sz = rhs.sz;
        a = new int[sz];
        for (unsigned i = 0; i < sz; ++i)
            a[i] = rhs.a[i];
        std::cout<<"copy const\n";
    }
    // destructor
    ~ThreeSum(){
        delete [] a;
        std::cout << "destructor\n";
    }
    // accessor
    int* DataPtr(void) const{
        return this->a;
    }
    unsigned Size(void)const {
        return this->sz;
    }
    // member functions
    void PushBack(int n) {
        int *temp = new int[sz];
        for (unsigned i = 0; i < sz; ++i)
            temp[i] = a[i];
        delete [] a;
        ++sz;
        a = new int[sz];
        unsigned i = 0;
        while(i < (sz-1)){
            a[i] = temp[i];
            ++i;
        }
        a[i] = n;
    }
    // operator overloads
    int& operator[](unsigned index) {
        if (index < sz)
            return a[index];
        std::cout << "index out of range.\n";
        exit(0);
    }
    // static members
    static int Count(ThreeSum &ts) {
        int size = ts.Size();
        int count = 0;
        for (int i = 0; i < size; ++i)
            for (int j = i+1; j < size; ++j)
                for (int k = j+1; k < size; ++k)
                    if (ts[i] + ts[j] + ts[k] == 0)
                        ++count;
        return count;
    }
};

#endif /* defined(__Analysis_Algorithms__ThreeSum__) */
