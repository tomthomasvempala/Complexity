#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
using namespace std::chrono;

int main(){
    freopen("outputs/op.txt","w",stdout);
    auto start = high_resolution_clock::now();
    system("input_gen.exe 5");
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function for input n = 5:"
         << duration.count() << " microseconds" << endl;
}