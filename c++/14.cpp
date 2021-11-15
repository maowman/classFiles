#include <iostream>

double answer1;


int main(){
    double n , count = 0 , total = 0;
    while(std::cin>>n){
        if (n == 999){
            break;
        }
        else if (n <= 100 && n >= 0){
            count +=1;
            total += (double) n;
        }
    }
    std::cout<<total / count<<std::endl;
    answer1 = total / double(count);
    return 0;
}