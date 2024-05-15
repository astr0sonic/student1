#include "kmp.h"
#include <vector>
#include <string>

std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> lps(m, 0);
    int length = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length != 0) {
                length = lps[length - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

std::vector<int> getIndices(const std::string& my_template, const std::string& text) {
    std::vector<int> indices;
    int m = my_template.size();
    int n = text.size();
    std::vector<int> lps = computeLPS(my_template);
    int i = 0, j = 0;

    while (i < n) {
        if (my_template[j] == text[i]) {
            j++;
            i++;
        }
        if (j == m) {
            indices.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && my_template[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return indices;
}
