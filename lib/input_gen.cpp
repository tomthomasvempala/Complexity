#include <bits/stdc++.h>
using namespace std;

ifstream MyReadFile("../params/ip_format.txt");;

unordered_map<string, int> data;

void integer(string &oneLine)
{
    int x = rand() % 20;
    cout << x;
    int space2 = oneLine.find(' ');
    string word2 = oneLine.substr(0, space2);
    oneLine = oneLine.substr(space2 + 1);
    data[word2] = x;
    if (oneLine == "nl")
    {
        cout << endl;
    }
    else
    {
        cout << " ";
    }
}

int main()
{
    freopen("../params/gen_inputs/ip.txt", "w", stdout);
    
    string oneLine;
    srand(time(0));
    while (getline(MyReadFile, oneLine))
    {
        int space = oneLine.find(' ');
        if (space != -1)
        {
            string word = oneLine.substr(0, space);
            oneLine = oneLine.substr(space + 1);
            if (word == "int")
            {
                integer(oneLine);
            }
            else if (word == "for")
            {
                int c = oneLine[0];
                // if (isalpha())
            }
        }
    }
    MyReadFile.close();
}