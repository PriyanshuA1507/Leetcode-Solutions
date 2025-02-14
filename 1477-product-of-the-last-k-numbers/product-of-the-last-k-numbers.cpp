class ProductOfNumbers {
public:
    vector<int> a;
        int front=-1;
        int rear=-1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(front==-1 ){
            a.push_back(num);
            front=0;
            rear=0;
        }
        else{
            a.push_back(num);
            rear++;
        }
    }
    
    int getProduct(int k) {
        int ans=1;
        int r=rear;
        while(k-->0){
            ans*=a[r];
            r--;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */