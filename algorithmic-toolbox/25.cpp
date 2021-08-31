#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector <std::vector< int> >  &data){
    for (int i=0;i<data.size();i++){
        for (int k=0;k<data[i].size();k++){
            std::cout<<data[i][k]<<' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    return ;
}

int main(){
    int m , n;
    std::cin>>m>>n;
    std::vector<int> golds(n+1);
    for (int i=1;i<golds.size();i++){
        std::cin>>golds[i];
    }

    std::vector< std::vector<int> > data(golds.size());
    for (int i=0;i<data.size();i++){
        std::vector<int> tmp(m+1);
        data[i] = tmp;
    }
    //print (data);
    for (int i=1 ; i<data.size();i++){
        for (int k=1 ; k<data[i].size();k++){
            if (k<golds[i]){
                data[i][k] = data[i-1][k];
            }
            else{
                data[i][k] = std::max(data[i-1][k] , data[i-1][k-golds[i]]+golds[i]);
            }
            //print(data);
        }
    }
    std::cout<<data[data.size()-1][data[0].size()-1];
    return 0;
}