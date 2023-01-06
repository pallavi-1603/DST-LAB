class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> result;
        result.resize(heights.size());

        int highest;
        for(int i = 0; i < heights.size(); i++){
            int currentHeight = heights[i];

            highest = heights[i+1];
            for(int j = i + 1; j < heights.size(); j++){
                if(heights[j] > currentHeight){
                    result[i]++;
                    break;
                }

                if(heights[j] >= highest) {
                    result[i]++;
                }

                if(heights[j] > highest)
                    highest = heights[j];
            }
        }

        return result;
    }
};