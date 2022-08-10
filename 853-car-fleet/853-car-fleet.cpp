class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> s;
        int n=position.size();
        if(n==1)
            return 1;
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++)
            temp.push_back({position[i],speed[i]});
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        for(auto z:temp){
            float time=(float)(target-z.first)/(z.second);
            s.push(time);
            if(s.size()>=2){
                float a=s.top();
                s.pop();
                float b=s.top();
                s.pop();
                if(a<=b)
                    s.push(b);
                else{
                    s.push(b);
                    s.push(a);
                }
             }
        }
        return s.size();
    }
};