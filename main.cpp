//
//  main.cpp
//  Analysis-Algorithms
//
//  Created by Daniel Walsh on 4/6/14.
//  Copyright (c) 2014 Daniel Walsh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "ThreeSum.h"

using namespace std;

int main(int argc, const char * argv[])
{
    int temp;
    ThreeSum ts;
    ifstream in("data.txt");
    while (!in.eof()) {
        in >> temp;
        ts.PushBack(temp);
    }
    in.close();
    for (unsigned i = 0; i < ts.Size(); ++i)
        cout << ts[i] <<  '\n';
    cout << ThreeSum::Count(ts) << " triple(s) add up to zero.\n";
    return 0;
}

