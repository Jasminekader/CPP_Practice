#include<iostream>
#include<vector>
#include<string>
#include<cmath>
class ObjectDistance{
private:
    float camera_distance;
    float radar_distance;
public:
    ObjectDistance(float camera_distance,float radar_distance):camera_distance(camera_distance),radar_distance(radar_distance){}
    ObjectDistance():camera_distance(0.0),radar_distance(0.0){}
    float getCameraDistance() const { return camera_distance; }
    float getRadarDistance() const { return radar_distance; }
    void setCameraDistance(float camera_distance) { camera_distance = camera_distance; }
    void setRadarDistance(float radar_distance) { radar_distance = radar_distance; }
    
    void displayInfo() const {
        std::cout << "Camera Distance: " << camera_distance << std::endl;
        std::cout << "Radar Distance: " << radar_distance << std::endl;
    }
    void printObjectDistance(const ObjectDistance& obj) {
        std::cout << "Camera Distance: " << obj.camera_distance << ", Radar Distance: " << obj.radar_distance << std::endl;
    }
    ObjectDistance*createObjectDistanceOnHeap(float radar,float camera){
        return new ObjectDistance(radar,camera);    }
};
int main(){
    ObjectDistance OD(35.5,34.8);
    OD.displayInfo();
    return 0;
}