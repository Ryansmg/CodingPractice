#include <stdio.h>
#include <iostream>
#include <deque>
#include <string>
using namespace std;

//후위 표기식

//string1.compare(string2)는 같으면 0을 반환함.

string postFixNotation(string s);

int main()
{
    string s; cin >> s;
    cout << postFixNotation(s);
}

string postFixNotation(string s){
    deque<string> dq;
    deque<string> dq2;
    int size = s.length();
    for(int i=0; i<size; i++) {
        char c = s.at(i);
        if(c=='(') {
            int firstI = i;
            int bln = 1;
            while(bln != 0){
                i++;
                char c2 = s.at(i);
                if(c2=='(') bln++;
                else if(c2==')') bln--;
            }
            dq.emplace_back(postFixNotation(s.substr(firstI+1, i-firstI-1)));
        }
        else dq.emplace_back(string(1,c));
    }

    while(true)
    {
        s = dq.front();
        dq.pop_front();
        if(dq.empty()) {dq2.emplace_back(s); break;}
        string ch = dq.front();
        dq.pop_front();
        if(ch.compare("*") == 0 || ch.compare("/") == 0) {
            string s2 = s + dq.front() + ch;
            dq.pop_front();
            dq.emplace_front(s2);
        }
        else {
            dq2.emplace_back(s);
            dq2.emplace_back(ch);
        }
    }

    while(true)
    {
        s = dq2.front();
        dq2.pop_front();
        if(dq2.empty()) break;
        string ch = dq2.front();
        dq2.pop_front();
        string s2 = s + dq2.front() + ch;
        dq2.pop_front();
        dq2.emplace_front(s2);
    }

    return s;
}