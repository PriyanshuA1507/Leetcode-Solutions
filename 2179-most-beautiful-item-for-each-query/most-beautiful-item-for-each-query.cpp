/*class Solution {
    int maxbeauty(vector<vector<int>> items, int a){
        int max=0;
        for(int i=0;i<items.size();i++){       
                if(items[i][0]<=a){
                    if(max<items[i][1])
                    max=items[i][1];
                }
        }
        return max;

    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> result;
        for(int i=0;i<queries.size();i++){
            result.push_back(maxbeauty(items,queries[i]));
        }
        return result;
    }
};*/
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int ma=items[0][1];
        int price=items[0][0];
        for(int i=1;i<items.size();i++){
            if(items[i][1]<=ma){
                items[i][0]=price;
                items[i][1]=ma;
            }else{
                ma=items[i][1];
                price=items[i][0];
            }
        }
        vector<int>answer(queries.size(),0);
        int j=0;
        for(int i=0;i<queries.size();i++){
            int curr=queries[i];
            vector<int> target ={queries[i],ma};
            auto it=upper_bound(items.begin(),items.end(),target);
            if (it != items.begin()) {
                it--;
                cout<<(*it)[0]<<" "<<(*it)[1]<<endl;
                answer[j] = (*it)[1];
                j++;
            }else{
                answer[j] =0;
                j++;
                cout<<"NO"<<endl;
            }            
        }
        return answer;
    }
};