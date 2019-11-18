// #include <Arduino.h>
#include "fuzzy_coba.h"
#include <iostream>


using namespace std;
Fuzzy jarak(-12,-8,-4,0,4,8,12,4);


int main(int argc, char const *argv[])
{
    float data;
    while(1) {
        cout << "Masukkan data : " ;
        cin >> data;
        data = jarak.getFuzzy(data);
        cout << "Hasil : " << data << endl;
        jarak.print();

    }
    return 0;
}


