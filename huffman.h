#include <string>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left, * right;
    HuffmanNode(char d, int f) : data(d), frequency(f), left(nullptr), right(nullptr) {}
    ~HuffmanNode() {
        delete left;
        delete right;
    }
};

struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return (l->frequency > r->frequency);
    }
};

HuffmanNode* buildHuffmanTree(const map<char, int>& freq) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (auto pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* parent = new HuffmanNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top();
}

void generateCodes(HuffmanNode* root, string code, map<char, string>& codes) {
    if (!root) return;
    if (root->data != '\0') {
        codes[root->data] = code;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

std::string encode(const string& text) {
    map<char, int> freq;

    for (char c : text) {
        freq[c]++;
    }

    HuffmanNode* root = buildHuffmanTree(freq);

    map<char, string> codes;
    generateCodes(root, "", codes);

    string encoded = "";
    for (char c : text) {
        encoded += codes[c];
    }

    delete root;
    return encoded;
}

std::string decode(const string& encoded, const map<char, string>& codes) {
    string decoded = "";
    string currentCode = "";

    for (char bit : encoded) {
        currentCode += bit;

        for (const auto& pair : codes) {
            if (pair.second == currentCode) {
                decoded += pair.first;
                currentCode = "";
                break;
            }
        }
    }

    return decoded;
}
