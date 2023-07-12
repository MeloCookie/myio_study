#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> map = {
    { 0 , 1 , 0 , 0 , 0 , 0},
    { 0 , 0 , 0 , 1 , 1 , 0},
    { 0 , 1 , 0 , 1 , 1 , 0},
    { 0 , 0 , 0 , 0 , 0 , 0},
    { 0 , 1 , 1 , 1 , 1 , 0},
    { 0 , 0 , 0 , 0 , 1 , 0}
};

struct Point
{
    int x;
    int y;
};

std::vector<Point> dir = {
    {0, -1},
    {0, 1},
    {1, 0},
    {-1, 0}
};

std::vector<Point> dfs(std::vector<std::vector<bool>> is_visited, Point now, std::vector<Point> current_path, size_t &step) {
    step++;
    if(now.x == 5 && now.y ==5){
        return current_path;
    }
    std::vector<Point> shortest_path;
    for (size_t i = 0; i < dir.size(); i++)
    {
        Point next;
        std::vector<Point> temp = current_path;
        std::vector<Point> temp_path;
        next.x = now.x + dir[i].x;
        next.y = now.y + dir[i].y;
        if(next.x < 0 || next.y < 0 || next.x >= 6 || next.y >= 6){
            continue;
        }
        if(is_visited[next.y][next.x] || map[next.y][next.x]){
            continue;
        }
        temp.push_back(next);
        is_visited[next.y][next.x] = true;
        temp_path = dfs(is_visited, next, temp, step);
        if(temp_path.size() < shortest_path.size() || shortest_path.size() == 0){
            shortest_path = temp_path;
        }
    }
    return shortest_path;
}

std::vector<Point> bfs(size_t &step) {

    std::queue<Point> q;
    Point now;
    now.x = 0;
    now.y = 0;
    q.push(now);
    std::vector<std::vector<std::vector<Point>>> plans = {
        { {}, {}, {}, {}, {}, {}},
        { {}, {}, {}, {}, {}, {}},
        { {}, {}, {}, {}, {}, {}},
        { {}, {}, {}, {}, {}, {}},
        { {}, {}, {}, {}, {}, {}},
        { {}, {}, {}, {}, {}, {}},
    };
    while (!q.empty())
    {
        step++;
        now = q.front();
        q.pop();
        for (size_t i = 0; i < dir.size(); i++)
        {
            Point next;
            next.x = now.x + dir[i].x;
            next.y = now.y + dir[i].y;
            if(next.x < 0 || next.y < 0 || next.x >= 6 || next.y >= 6){
                continue;
            }
            if(map[next.y][next.x]){
                continue;
            } 
            std::vector<Point> temp = plans[now.y][now.x];
            temp.push_back(next);
            if(plans[next.y][next.x].size() == 0 || plans[next.y][next.x].size() > temp.size()){
                plans[next.y][next.x] = temp;
                q.push(next);
            }
        }
    }    
    return plans[5][5];
}


void show(std::string name , std::vector<Point> path) {
    std::cout<<"method : "<<name<<std::endl;
    for (const auto & point : path)
    {
        std::cout<< "x : "<<point.x<<" y : "<<point.y<<std::endl;
    }
    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector<std::vector<bool>> is_visited = {
        { true, false, false, false, false, false},
        { false, false, false, false, false, false},
        { false, false, false, false, false, false},
        { false, false, false, false, false, false},
        { false, false, false, false, false, false},
        { false, false, false, false, false, false}
    };
    Point now;
    now.x = 0;
    now.y = 0;
    std::vector<Point> current_path;
    current_path.push_back(now);
    size_t dfs_step = 0;
    size_t bfs_step = 0;
    
    std::vector<Point> dfs_solution = dfs(is_visited, now, current_path, dfs_step);
    std::vector<Point> bfs_solution = bfs(bfs_step);
    show("dfs", dfs_solution);
    show("bfs", bfs_solution);

    std::cout<<"dfs : "<<dfs_step <<" bfs : "<<bfs_step<<std::endl;
    return 0;
}
