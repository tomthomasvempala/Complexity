#include <bits/stdc++.h>
using namespace std;

ifstream MyReadFile("../params/ip_format.txt");
;

unordered_map<string, int> data;

vector<string> statements;

string inspect(string oneLine,int index);

void integer(string &oneLine,int mini=0,int maxi=5)
{
    int x =mini+ rand() % (maxi-mini);
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

void forloop(string oneLine,int start)
{
    int c = oneLine[0];
    int t;
    if (isalpha(c))
    {
        t = data[oneLine];
    }
    else
    {
        t = c - '0';
    }
    // cout<<"t="<<t<<endl;
    int i=start+1,count=0;
    while (true)
    {
        if(count<t){
            string res = inspect(statements[i],0);
            i++;
            if(res=="endfor"){
            count++;
            if(count<t){
                i=start+1;
            }
            else{
                break;
            }
        }
        }
        else
        {
            break;
        }
    }
}

string inspect(string oneLine,int index)
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
            forloop(oneLine,index);
        }
    }
    else if(oneLine=="endfor"){
        return "endfor";
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
        inspect(oneLine,i);
    }
    MyReadFile.close();
}