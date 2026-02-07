class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_rectangle_area = -1;
        int element, nse, pse;
        stack<int> st;

        for(int i = 0; i < n; ++i) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                element = st.top(); st.pop();
                nse = i;
                pse = !st.empty() ? st.top() : -1;
                max_rectangle_area = max(max_rectangle_area, (nse - pse - 1) * heights[element]);
            }
            st.push(i);
        }

        while(!st.empty()) {
            nse = n;
            element = st.top(); st.pop();
            pse = !st.empty() ? st.top() : -1;
            max_rectangle_area = max(max_rectangle_area, (nse - pse - 1) * heights[element]);
        }

        return max_rectangle_area;
    }
};