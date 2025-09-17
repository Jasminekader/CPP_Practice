#include<iostream>
#include<vector>
#include<cmath>
class LaneBoundary{
private:
    float curvature;
    int lane_id;
public:
    LaneBoundary(float curv,int id):curvature(curv),lane_id(id){}
    LaneBoundary():curvature(0.0),lane_id(0){}
    float getCurvature() const { return curvature; }
    int getLaneId() const { return lane_id; }
    void setCurvature(float curv) { curvature = curv; }
    void setLaneId(int id) { lane_id = id; }
    
    void displayInfo() const {
        std::cout << "Lane ID: " << lane_id << std::endl;
        std::cout << "Curvature: " << curvature << std::endl;
    }
};
int main(){
    LaneBoundary LB1(0.015, 1);
    LaneBoundary LB2(0.023, 2);
   
    LB1.displayInfo();
    LB2.displayInfo();

    return 0;
}

