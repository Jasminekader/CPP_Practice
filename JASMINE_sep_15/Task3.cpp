#include<iostream>
#include<iostream>
#include<vector>
#include<string>
class AerospaceComponent{
public:
    enum ComponentType { COMPONENT_TYPE_ENGINE, COMPONENT_TYPE_WING, COMPONENT_TYPE_LANDING_GEAR,COMPONENT_TYPE_AVIONICS,COMPONENT_TYPE_FUEL_SYSTEM };
    enum ComponentStatus { COMPONENT_STATUS_OPERATIONAL, COMPONENT_STATUS_MAINTENANCE_REQUIRED,COMPONENT_STATUS_FAILED };
private:
    int componentIdentifier;
    double componentEfficiency;
    std::string componentManufacturer;
    ComponentType componentType;
    ComponentStatus componentStatus;

public:
    AerospaceComponent(int id,double efficiency,std::string manufacturer,ComponentType type,ComponentStatus status):
        componentIdentifier(id),componentEfficiency(efficiency),componentManufacturer(manufacturer),componentType(type),componentStatus(status){};
    AerospaceComponent():componentIdentifier(0),componentEfficiency(100.0),componentManufacturer("Unknown"),componentType(COMPONENT_TYPE_ENGINE),componentStatus(COMPONENT_STATUS_OPERATIONAL){};

private:
    void UpdateStatus(){
        if (componentEfficiency < 50.0)
            componentStatus = COMPONENT_STATUS_FAILED;
        else if (componentEfficiency < 80.0)
            componentStatus = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        else
            componentStatus = COMPONENT_STATUS_OPERATIONAL;
    }
public:
    void SimulateUsage(int usageHours){
        for(int i=0;i<usageHours;++i){
            componentEfficiency-=usageHours*0.5;
            if(componentEfficiency<0) componentEfficiency=0;
            UpdateStatus();
        }
    }
public:
    void PerformMaintenance(){
        switch (componentStatus) {
        case COMPONENT_STATUS_OPERATIONAL:
            std::cout << "Component " << componentIdentifier << " is operational. No maintenance required.\n";
            break;
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
            std::cout << "Component " << componentIdentifier << " requires maintenance soon.\n";
            break;
        case COMPONENT_STATUS_FAILED:
            std::cout << "Component " << componentIdentifier << " has failed and needs immediate maintenance.\n";
            break;
        default:
            std::cout << "Unknown status.\n";
            break;
        }
    }
    void BoostEfficiency(){
        while(componentEfficiency<100.0)
            componentEfficiency+=1.0;
            if (componentEfficiency > 100.0) {
                componentEfficiency = 100.0;
            }
            UpdateStatus();
        
    }
    void AssignManufacturer(const AerospaceComponent&Component,const std::string & manufacturer){
        componentManufacturer=manufacturer;}
    bool isEfficient(const AerospaceComponent&component){
        if(componentEfficiency>85.0)
            return true;
    }
    bool isSameType(const AerospaceComponent&componentA,const AerospaceComponent &componentB){
        if (componentA.componentType==componentB.componentType)
            return true;
    }
    
    bool isSameStatus(const AerospaceComponent&componentA,const AerospaceComponent &componentB){
        if(componentA.componentStatus==componentB.componentStatus)
        return true;
    }
    void PrintFormattedComponentList(const AerospaceComponent componentList[],const int listSize){
        for(int i=0;i<listSize;i++){
            std::cout<<"Component ID:"<<componentList[i].componentIdentifier<<std::endl;
            std::cout<<"Efficiency:"<<componentList[i].componentEfficiency<<std::endl;
            std::cout<<"Manufacturer:"<<componentList[i].componentManufacturer<<std::endl;
            std::cout<<"Type:"<<componentList[i].componentType<<std::endl;
            std::cout<<"Status:"<<componentList[i].componentStatus<<std::endl;
        }
    }
    int SearchComponentByIdentifier(const AerospaceComponent componentList[],const int listSize,const int serachIdentifier){
        for(int i=0;i<listSize;i++){
            if(componentList[i].componentIdentifier==serachIdentifier)
                return i;
        }
        return -1;
    }
    int GetIdentifier() const { return componentIdentifier; }
    double GetEfficiency() const { return componentEfficiency; }
    const std::string &GetManufacturer() const { return componentManufacturer; }
    ComponentType GetType() const { return componentType; }
    ComponentStatus GetStatus() const { return componentStatus; }

    void DisplayDetails()const{
        std::cout<<"Compnent_ID:"<<componentIdentifier<<std::endl;
        std::cout<<"Efficiency:"<<componentEfficiency<<std::endl;
        std::cout<<"Manufacturer:"<<componentManufacturer<<std::endl;
        std::cout<<"Type:"<<componentType<<std::endl;
        std::cout<<"Status:"<<componentStatus<<std::endl;
        
    }
};

int main(){
    AerospaceComponent Aero[3];
    AerospaceComponent Aero1(101, 92.5, "GE Aviation",AerospaceComponent::COMPONENT_TYPE_ENGINE,AerospaceComponent::COMPONENT_STATUS_OPERATIONAL);
    AerospaceComponent Aero2(102, 45.0, "Honeywell",AerospaceComponent::COMPONENT_TYPE_AVIONICS, AerospaceComponent::COMPONENT_STATUS_FAILED);
    AerospaceComponent Aero3;
    
    Aero1.DisplayDetails();
    Aero2.DisplayDetails();
    Aero3.DisplayDetails();

    
    int choice;
    do{
        std::cout<<"\nAerospace Component Menu\n";
        std::cout<<"1. Add Component Details\n";
        std::cout<<"2. Assign Manufactrer\n";
        std::cout<<"3. Simulate Usage\n";
        std::cout<<"4. Boost Efficiency\n";
        std::cout<<"5. Check Maintenance Status\n";
        std::cout<<"6. compare components\n";
        std::cout<<"7. Display all components\n";
        std::cout<<"8. Exit\n";
        std::cout<<"Enter choice:";
        std::cin>>choice;
        switch(choice){
            case 1:{
                int id;
                double efficiency;
                std::string manufacturer;
                int typeInput,statusInput;
                std::cout<<"Enter Component ID:";
                std::cin>>id;
                std::cout<<"Enter Efficiency:";
                std::cin>>efficiency;
                std::cout<<"Enter Manufacturer:";
                std::cin>>manufacturer;
                std::cout<<"Enter Type (0-Engine,1-Wing,2-Landing Gear,3-Fuel System):";
                std::cin>>typeInput;
                std::cout<<"Enter Status (0-Operational,1-Maintenance Required,2-Failed):";
                std::cin>>statusInput;
                Aero[choice]=AerospaceComponent(id,efficiency,manufacturer,(AerospaceComponent::ComponentType)typeInput,(AerospaceComponent::ComponentStatus)statusInput);
                std::cout<<"Component added successfully!"<<std::endl;
                break;
            }
            case 2:{
                int hours;
                std::cout<<"Enter usage hours to simulate:";
                std::cin>>hours;
                Aero[choice].SimulateUsage(hours);
                std::cout<<"Usage simulated successfully!"<<std::endl;
                break;
            }
            case 3:{
                Aero[choice].PerformMaintenance();
                std::cout<<"Maintenance performed successfully!"<<std::endl;
                break;
            }
            case 4:{
                Aero[choice].BoostEfficiency();
                std::cout<<"Efficiency boosted successfully!"<<std::endl;
                break;
            }
            case 5:{
                int id;
                std::cout<<"Enter Component ID to check status:";
                std::cin>>id;
                int index=Aero[choice].SearchComponentByIdentifier(Aero,3,id);
                if(index!=-1){
                    Aero[index].DisplayDetails();
                }else{
                    std::cout<<"Component not found!"<<std::endl;
                }
                break;
            }
            case 6:{
                int componentA,componentB;
                std::cout<<"Enter indices of two components to compare (0-2):";
                std::cin>>componentA>>componentB;
                if(Aero[choice].isSameType(Aero[componentA],Aero[componentB])){
                    std::cout<<"Components are of the same type."<<std::endl;
                }else{
                    std::cout<<"Components are of different types."<<std::endl;
                }
                break;

            }
            case 7:{
                Aero[choice].PrintFormattedComponentList(Aero,3);
                break;
            }
            case 8:{
                std::cout<<"Exiting program."<<std::endl;
                break;
            }
            default:
                std::cout<<"Invalid choice. Please try again."<<std::endl;
                break;
        }
    }while(choice!=8);
    
    Aero1.PrintFormattedComponentList(Aero,3);
    Aero2.PrintFormattedComponentList(Aero,3);
    return 0;

}