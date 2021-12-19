#include <iostream>
#include <vector>

struct direction {
    int x ,y;
    direction( int inputX , int inputY ){
        x = inputX;
        y = inputY;
    }
};

void addStudent(std::vector<std::vector<int>> &data , struct direction cruuentDirection , std::vector<int> standUpStudent , int startX , int startY ){
    int currentX = startX + cruuentDirection.x;
    int currentY = startY + cruuentDirection.y;
    while(true){
        if  (currentX >= data.size() || currentY >= data[currentX].size() || currentX < 0 || currentY <0){
            break;
        }
        standUpStudent.push_back(data[currentX][currentY]);
        currentY += cruuentDirection.y;
        currentX += cruuentDirection.x;
    }
    return;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> data(n, std::vector<int>(m));
    for (int i = 0; i < (int)data.size(); i++)
    {
        for (int k = 0; k < (int)data[i].size(); k++)
        {
            std::cin >> data[i][k];
        }
    }
    int x, y;
    std::cin >> x >> y;
    int biggest = -1;
    std::vector<int> standUp ; 
    struct direction UL(-1 , -1) , UR(-1 , 1) , DL(1 , -1) , DR(1 , 1);

}