/* MIT License

Copyright (c) 2018 Yisroel mirsky

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#include <iostream>
#include "mls.h"
using namespace std;

//In this example we generate 10 MLS sequences using AES, then another 10 using the device's entropy source

int main(int argc, char *argv[])
{
    int m = 6; //2^m-1 bits per generated sequence
    cout<<"m = 6 (63 bits per sequence : L=2^m-1)"<<endl<<endl;
    cout<<"Generating 3 MLS sequences using AES256-CTR"<<endl;
    mls mls_aes(6,true);
    for(int i = 0; i < 3; i++)
    {
        cout<<"Sequence #"<<i+1<<": ";
        vector<bool> mls_seq = mls_aes.get_seq();
        for(int b = 0; b < mls_seq.size(); b++)
            cout<<mls_seq[b]<<" ";
        cout<<endl;
    }
    cout<<endl;

    cout<<"Generate 3 MLS sequences using the device's entropy source std::random_device"<<endl;
    mls mls_rnd(6);
    for(int i = 0; i < 3; i++)
    {
        cout<<"Sequence #"<<i+1<<": ";
        vector<bool> mls_seq = mls_rnd.get_seq();
        for(int b = 0; b < mls_seq.size(); b++)
            cout<<mls_seq[b]<<" ";
        cout<<endl;
    }
    cout<<endl;

    return -1;
}
