//#include "huffman.h"
//#include <string>
//#include <map>
//#include <queue>
//using namespace std;
//
//struct HuffmanNode {
//    char data;
//    int frequency;
//    HuffmanNode* left, * right;
//};
//
//
//struct Compare {
//    bool operator()(HuffmanNode* l, HuffmanNode* r) {
//        return (l->frequency > r->frequency);
//    }
//};
//
//HuffmanNode* createNode(char data, int frequency) {
//    HuffmanNode* node = new HuffmanNode();
//    node->data = data;
//    node->frequency = frequency;
//    node->left = node->right = nullptr;
//    return node;
//}
//HuffmanNode* buildHuffmanTree(const map<char, int>& freq) {
//    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
//
//    for (auto pair : freq) {
//        pq.push(createNode(pair.first, pair.second));
//    }
//
//
//    while (pq.size() != 1) {
//        HuffmanNode* left = pq.top(); pq.pop();
//        HuffmanNode* right = pq.top(); pq.pop();
//        HuffmanNode* parent = createNode('\0', left->frequency + right->frequency);
//        parent->left = left;
//        parent->right = right;
//        pq.push(parent);
//    }
//
//    return pq.top();
//}
//
//
//void generateCodes(HuffmanNode* root, string code, map<char, string>& codes) {
//    if (!root) return;
//    if (root->data != '\0') {
//        codes[root->data] = code;
//    }
//    generateCodes(root->left, code + "0", codes);
//    generateCodes(root->right, code + "1", codes);
//}
//
//
//std::string encode(const string& text) {
//    map<char, int> freq;
//
//    for (char c : text) {
//        freq[c]++;
//    }
//
//    HuffmanNode* root = buildHuffmanTree(freq);
//
//    map<char, string> codes;
//    generateCodes(root, "", codes);
//
//    string encoded = "";
//    for (char c : text) {
//        encoded += codes[c];
//    }
//    return encoded;
//}
//
//
//std::string decode(const string& encoded, const map<char, string>& codes) {
//    string decoded = "";
//    string currentCode = "";
//
//    for (char bit : encoded) {
//        currentCode += bit;
//
//        for (const auto& pair : codes) {
//            if (pair.second == currentCode) {
//                decoded += pair.first;
//                currentCode = "";
//                break;
//            }
//        }
//    }
//    return decoded;
//}
