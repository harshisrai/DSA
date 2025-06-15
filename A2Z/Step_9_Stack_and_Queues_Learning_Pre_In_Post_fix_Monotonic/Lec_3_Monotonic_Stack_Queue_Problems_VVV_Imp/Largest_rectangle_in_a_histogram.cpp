/* Problem: Largest_rectangle_in_a_histogram */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; 
        int width=0,maxArea=0;
        int n=heights.size(); 
        for(int i=0; i<=n; i++){
            //letting loop run for i==n is how we handle the non-emptied stack at the last index
            // at pop them out considering their nse to be not their and this index to be 'n'.
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i])){
                int idx=st.top(); // idx for which we will calculate area
                // the i which we are at caused it to pop - so it is it's nse; 
                // we need pse now - which will be element in stack right at the top now 
                st.pop(); 

                // we need width now 0 to i OR st.top to i (this i can even be n, when there is no nse for idx element)
                if(st.empty()) width=i; 
                else width=i-st.top()-1;  
                maxArea=max(maxArea, heights[idx]*width);
            }
            st.push(i); 
        }
        
        return maxArea;
    }
};