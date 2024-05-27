class ParkingSystem {
public:
      vector<int> a;
    ParkingSystem(int big, int medium, int small) {

        a.push_back(big);
         a.push_back(medium);
          a.push_back(small);
    }
    
    bool addCar(int i) {
        if(i==1){
         if(a[0]>0){
            a[0]-=1;
            return true;
         }
         else
         return false;
        }
         if(i==2){
         if(a[1]>0){
            a[1]-=1;
            return true;
            
         }
         else
         return false;
        }
         if(i==3){
         if(a[2]>0){
            a[2]-=1;
            return true;
         }
         else
         return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */