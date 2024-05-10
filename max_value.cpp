#include "max_value.h"
double calculateMaxValue(double* nums, int n) 
    {
        double max_val = nums[0];
        double curr_val = nums[0];

        for (int i = 1; i < n; i++)
        {
           
            curr_val += nums[i];
            max_val = std::max(max_val, curr_val);

            curr_val -= 2 * nums[i];
            max_val = std::max(max_val, curr_val);

            curr_val = nums[i];
            max_val = std::max(max_val, curr_val);

            if (std::abs(nums[i]) > 1e-9) {
                curr_val /= nums[i];
                max_val = std::max(max_val, curr_val);
            }
           
        }
        return max_val;
    
}
