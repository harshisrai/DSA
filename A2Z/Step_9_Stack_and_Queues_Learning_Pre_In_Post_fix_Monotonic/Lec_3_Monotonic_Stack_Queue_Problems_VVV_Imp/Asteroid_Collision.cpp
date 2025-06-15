/* Problem: Asteroid_Collision */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; 
        for(int i:asteroids){
            // if top is +ve, and curr is -ve
            // pop till less or equal magnitude are out - if empty, -ve push else not 
            if(i<0){
                i=-i; 
                while(!st.empty() && st.back()<i && st.back()>0) st.pop_back(); 
                if(st.empty() || st.back()<0) st.push_back(-i); 
                else if(st.back()==i) st.pop_back(); 
            }
            else{
                st.push_back(i); 
            }
        }
        return st; 
    }
};