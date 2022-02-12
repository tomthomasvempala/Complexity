#include <bits/stdc++.h>
using namespace std;

ifstream MyReadFile("../params/ip_format.txt");
;

unordered_map<string, int> data;

vector<string> statements;

string inspect(string oneLine,int &index);

int findVal(char c){
    int t;
    if (isalpha(c))
    {
        string ch ="";
        ch+= c;
        t = data[ch];
    }
    else
    {
        t = c - '0';
    }
    return t;
}

void integer(string &oneLine,int mini=1,int maxi=5)
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

int forloop(string oneLine,int start)
{
    int c = oneLine[0];
    int t=findVal(c);
    // cout<<"t="<<t<<endl;
    int i=start+1,count=0;
    while (true)
    {
        if(count<t){
            string res = inspect(statements[i],start);
            i++;
            if(res=="endfor"){
            count++;
            if(count<t){
                i=start+1;
            }
            else{

                return i;
            }
        }
        }
        else
        {
            break;
        }
    }
}

string inspect(string oneLine,int &index)
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
            index = forloop(oneLine,index)-1;
        }
    }
    else if(oneLine=="endfor"){
        return "endfor";
    }
    else if(oneLine=="nl"){
        cout<<endl;
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
        // cout<<"\noneLine = "<<i+1<<endl;
        inspect(oneLine,i);
    }
    MyReadFile.close();
}