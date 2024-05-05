#include "volume.h"
#include <algorithm>

int getMaxVolume(int a, int b, int c, int n, int* arr) {
    int maxV = 0;
    int h;
    int w = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] <= c && arr[j] <= c)
            {
                h = std::min(arr[i], arr[j]);
                if (j - i <= a)  w = j - i;
                int l = b;
                int volume = l * w * h;
                if (volume <= a * b * c) maxV = std::max(maxV, volume);
            }
        }
    }

    return maxV;
}
