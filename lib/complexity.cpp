#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    
    vector<long long int> params;
    ifstream MyReadFile("../params/var_values.txt");
    string oneNum;
    while (getline(MyReadFile, oneNum))
    {
        params.push_back(stoi(oneNum));
    }

    vector<int> times;
    int base;
    auto start = high_resolution_clock::now();
    char command[50] = "input_gen.exe 10";
    system(command);
    system("pgm.exe");
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    base = duration.count();

    for (auto item : params)
    {
        string x = to_string(item);
        int i;
        for (i = 14; i < 14 + x.size(); i++)
        {
            command[i] = x[i - 14];
        }
        command[i] = 0;
        start = high_resolution_clock::now();
        system(command);
        // cout<<command<<endl;
        system("pgm.exe");
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        if(params[0]==item){
            base = duration.count();
        }
        cout << "Time taken by function for input VAR="<<item<<": "
             << duration.count() / base << " units" << endl;
        times.push_back(duration.count() / base);
    }
}