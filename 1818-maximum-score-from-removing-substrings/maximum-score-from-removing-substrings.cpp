class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>y){
            stack<char>st1;
            for(int i=0;i<s.length();i++){
                if(!st1.empty()&&s[i]=='b'&&st1.top()=='a'){
                    ans+=x;
                    st1.pop();
                }
                else{
                    st1.push(s[i]);
                }
            }
            string second="";
            while(!st1.empty()){
                if(second.length()>0&&second.back()=='a'&&st1.top()=='b'){
                    ans+=y;
                    st1.pop();
                    second.pop_back();
                }else{
                    second+=st1.top();
                    st1.pop();
                }
            }
            return ans;
        }else{
            stack<char>st1;
            for(int i=0;i<s.length();i++){
                if(!st1.empty()&&s[i]=='a'&&st1.top()=='b'){
                    ans+=y;
                    st1.pop();
                }
                else{
                    st1.push(s[i]);
                }
            }
            string second="";
            while(!st1.empty()){
                if(second.length()>0&&second.back()=='b'&&st1.top()=='a'){
                    ans+=x;
                    st1.pop();
                    second.pop_back();
                }else{
                    second+=st1.top();
                    st1.pop();
                }
            }
            return ans;

        }
    }
};