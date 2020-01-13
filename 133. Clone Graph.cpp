/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        return dfs(map, node);
    }
    
private:
    Node* dfs(unordered_map<Node*, Node*>& map, Node* node) {
        if (!node) {
            return NULL;
        }
        if (map.find(node) != map.end()) {
            return map[node];
        }
        map[node] = new Node(node->val, vector<Node*>());
        for (int i = 0; i < node->neighbors.size(); ++i) {
            Node* nxt = dfs(map, node->neighbors[i]);
            map[node]->neighbors.push_back(nxt);
        }
        return map[node];
    }
};
