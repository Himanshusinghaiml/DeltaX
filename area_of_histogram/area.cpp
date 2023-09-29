 long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> st;
        long long maxA = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i])) {
                long long height = arr[st.top()];
                st.pop();
                long long width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
  