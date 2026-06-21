#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> mp={
        {"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9},{"ten",10},{"eleven",11},{"twelve",12},{"thirteen",13},{"fourteen",14},{"fifteen",15},{"sixteen",16},{"seventeen",17},{"eighteen",18},{"nineteen",19},{"twenty",20},{"a",1},{"both",2},{"another",1},{"first",1},{"second",2},{"third",3}
    };
    string word,line;
    getline(cin,line);
    stringstream ss(line);
    vector<string> words;
    while(ss >> word){
        if(word.back() == '.')
            word.pop_back();
        words.push_back(word);
    }
    vector<string>res;
    for(auto w:words){
        if(mp.count(w)){
            int num = mp[w];
            int val = num * num %100;
            char temp[3];
            sprintf(temp,"%02d",val);
            res.push_back(temp);
        }
    }
    sort(res.begin(),res.end(),[](string a,string b){
        return a+b<b+a;});
    if(res.empty()){
        cout<<0<<endl;
        return 0;
    }
    string ans;
    for(auto s:res) ans+= s;
    size_t  pos = 0;
    while(pos < ans.size() && ans[pos] == '0')
        pos++;
    if(pos == ans.size())
        cout << ans.substr(pos) <<endl;
    return 0;
    }