/* Problem: Maximum_point_you_can_obtain_from_cards */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len=cardPoints.size();
        int sum=0,lsum=0,rsum=0; 
        for(int i=0;i<k;i++) lsum+=cardPoints[i]; 
        sum=lsum;

        for(int i=0; i<k;i++){
            lsum-=cardPoints[k-i-1];
            rsum+=cardPoints[len-i-1];
            sum=max(sum,lsum+rsum);
        }
        return sum;
    }
};
