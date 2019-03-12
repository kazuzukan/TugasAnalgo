/*
    Nama : Risyad Pangestu
    NPM : 140810170003
    Kelas : A
    Tanggal : 6 Maret 2019
    Program Mencari Nilai Maksimal
*/

#include <iostream>
using namespace std;

typedef int Nilai[100];
void carimaksimal(int n, Nilai x);

int main(){
    Nilai x;
    int n;
    cout<<" Mencari Nilai Maksimal \n";
    cout<<" Input size of Array \n";
    cin>>n;

    for (int i=1; i<=n; i++){
        cout<<" Number "<<i+1<<" : ";
        cin>>x[i];
    }
    carimaksimal(n,x);
    return 0;
}

void carimaksimal(int n, Nilai x){
    int max,i;
    max = x[0];
    i=2;
    while (i<=n){
        if (max < x[i]){
            max = x[i];
        }
    }
    cout<<"Nilai Max : "<<max;
}