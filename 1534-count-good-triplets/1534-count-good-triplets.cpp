class Solution {
public:
    int countGoodTriplets(std::vector<int>& arr, int a, int b, int c) {
        int increment = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                    if (std::abs(arr[i] - arr[j]) <= a) {
                        if (std::abs(arr[j] - arr[k]) <= b) {
                            if (std::abs(arr[i] - arr[k]) <= c) {
                                increment++;
                            }
                        }
                    }
                }
            }
        }
        return increment;
    }
};