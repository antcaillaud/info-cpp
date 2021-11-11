#include <iostream>
#include <vector>

void foo(){
    std::cerr << "le message d'erreur" << std::endl;
    exit(1); // je termine le programme avec un code d'erreur 1
}

int main(int argc, char** argv){
    std::vector<int> pile;
    int temp1;
    int temp2;
    std::string a;
    for(int k = 1; k < argc; k++){
        a = std::string(argv[k]);
        if(std::isdigit(a[0])){
            pile.push_back(std::stoi(std::string(a)));
        }
        else if((a =="+")||(a == "x")||(a == "-")||(a == "/")){
            if(pile.size()<2){
                foo();
            }
            temp1 = pile.back();
            pile.pop_back();
            temp2 = pile.back();
            pile.pop_back();
            if(a == "+"){
                pile.push_back(temp2 + temp1);
            }
            else if( a == "x"){
                pile.push_back(temp2 * temp1);
            }
            else if( a == "-"){
                pile.push_back(temp2-temp1);
            }
            else if( a == "/"){
                if(temp1 == 0){
                    foo();
                }
                else{
                    pile.push_back(temp2/temp1);
                }
            }
        } 
    }
    int res = pile.back();
    std::cout<<res<<std::endl;
    return 0;
}