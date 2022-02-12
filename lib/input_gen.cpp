#include <bits/stdc++.h>
using namespace std;

ifstream MyReadFile("../params/ip_format.txt");
;

unordered_map<string, int> data;

vector<string> statements;

string inspect(string oneLine, int index);

int findVal(string c)
{
    int t;
    if (isalpha(c[0]))
    {
        string ch = "";
        ch += c[0];
        t = data[ch];
    }
    else
    {
        t = stoi(c);
    }
    return t;
}

void integer(string &oneLine, int mini = 5, int maxi = 10)
{
    int space2 = oneLine.find(' ');
    int x;
    string word2 = oneLine.substr(0, space2);
    if (!isalpha(word2[0]))
    {

        x = stoi(word2);
        cout << x;
    }
    else
    {
        x = mini + rand() % (maxi - mini);
        cout << x;
    }

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

int forloop(string oneLine, int start)
{
    int t = findVal(oneLine);
    int i = start + 1, count = 0;
    // cout<<"\nloopilkeri"<<t<<"\n";
    while (true)
    {
        string res = inspect(statements[i], i);
        i++;
        if (res == "endfor")
        {
            count++;
            // cout<<"count = "<<count<<endl;
            if (count < t)
            {
                i = start + 1;
            }
            else
            {

                // cout<<"returning i="<<i+1<<endl;
                return i;
            }
        }
        else if(res.size()!=0){
            i = stoi(res);
        }
    }
}

string inspect(string oneLine, int index)
{
    if(oneLine[0]=='#'){
        return "";
    }
    // cout << "*" << index + 1 << " " << oneLine << endl;
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
            return to_string(forloop(oneLine, index));
        }
    }
    else if (oneLine == "endfor")
    {
        return "endfor";
    }
    else if (oneLine == "nl")
    {
        cout << endl;
    }
    return "";
}

int main()
{
    freopen("../params/gen_inputs/ip.txt", "w", stdout);

    string oneLine;
    srand(time(0));
    while (getline(MyReadFile, oneLine))
    {
        statements.push_back(oneLine);
    }

    for (int i = 0; i < statements.size(); i++)
    {
        oneLine = statements[i];
        string ind = inspect(oneLine, i);
        if (ind != "" && ind != "endfor")
        {
            i = stoi(ind) - 1;
        }
    }
    MyReadFile.close();
}