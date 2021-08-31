#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct operation
{
    int type;
    int data;
};


int main(){
    std::string str;
    std::cin>>str;
    std::stringstream  ss;
    ss<<str;
    int cache;
    std::vector<struct operation> operations;
    while(ss>>cache){
        struct operation number;
        number.data = cache;
        number.type = -1;
        if (ss.str().size()!=0){
            char chr;
            ss>>chr;
            struct operation 
        }
    }

    

}