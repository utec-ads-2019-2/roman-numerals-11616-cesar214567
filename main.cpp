#include <iostream>
#include <map>
#include <iostream>
#include <vector>
#include <unordered_map> 

using namespace std;

unordered_map<string,int> maps={{"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10},{"XL",40},{"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},{"M",1000}};
unordered_map<int,string> maps2={{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
vector<int> vector_keys={1000,900,500,400,100,90,50,40,10,9,5,4,1};
int convert_roman_to_decimal(string palabra){
    int retorno=0;
    int i=0;
    string temporal="";
    while (i<palabra.length()){
        temporal=temporal+palabra[i]+palabra[i+1];
        if (maps.find(temporal)==maps.end()){
            string temporal2="";
            temporal2+=palabra[i];
            retorno+=maps[temporal2];
            i++;
        }else{
            retorno+=maps[temporal];
            i+=2;
        }
        temporal="";
    }
    return retorno;
}

string convert_decimal_to_roman(string palabra){
    int temporal=stoi(palabra);
    string retorno="";
    for ( int i=0;i<vector_keys.size();i++){
        int contador=0;
        while (vector_keys[i]<=temporal ){
            retorno+=maps2[vector_keys[i]];
            temporal-=vector_keys[i];
            //if(it->first=="")
        }
       
    }
    return retorno;
    
}


int main(){
    string palabra;
    while(cin>>palabra){
        if (!isdigit(palabra[0])){
            cout<<convert_roman_to_decimal(palabra)<<endl;
        }else{
            cout<<convert_decimal_to_roman(palabra)<<endl;
        }

    }
}
