#include<bits/stdc++.h>
using namespace std;

void solve(){
    ifstream file("input/01input");
    string s;
    getline(file,s);

    int words=0,letters=0,spchar=0,digit=0;
    string letter="",special="",digits="";
    bool ck=false;
    // cout<<s;

    for(auto c:s){
        if(c == ' ') {
            ck=false;

        }
        else if(!ck){
             words++;
             ck=true;
        }

        if(isspace(c)) {

        }
        else if(c<='9' and c>='0'){
            digits+=c;
            digit++;

        }
        else if(tolower(c)<='z' && tolower(c)>='a'){
            
            letter+=c;
            letters++;
        } 
        else{
            special+=c;

            spchar++; 
        }




    }
    cout<<"Words Count: "<<words<<"\n";
    cout<<"letters Count: "<<letters<<"\n";
    cout<<"Special characters: "<<spchar<<"\n";
    cout<<"Digits "<<digit<<"\n";


    cout<<"Separate letter: "<<letter<<"\n";
    cout<<"Separate Special Char: "<<special<<"\n";
    cout<<"Separate digits: "<<digits<<"\n";

    

}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


solve();

return 0;
}