class Solution {
public:
    int maximumSwap(int num) {
        vector<int> a;
        while(num>0){
        a.push_back(num%10);
        num= num/10;
        }
        reverse(a.begin(),a.end());
        bool t = false;
        for(int i=0;i<a.size();i++){
            int maxi = a[i];
            int index = 0;
         for(int j=i+1;j<a.size();j++){
            if(a[j]>=maxi ){
                maxi = a[j];
                index = j;
                t = true;
            }
         }
          if (maxi != a[i]) {
                swap(a[i], a[index]);
                break;
            }
        }
        int a1 = 0;
        for (auto d : a)  
{
    a1 = a1* 10 + d;
}
      return a1;  
    }
};