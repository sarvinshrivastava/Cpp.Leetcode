class ThroneInheritance {
public:
    struct Node {
        string name;
        vector<Node*> childs;

        Node (string s) {
            name = s;
        }
    };
    Node* root;

    unordered_map <string, Node*> map;

    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        map[kingName] = root;
    }

    void birth(string parentName, string childName) {
        Node* child = new Node(childName);
        (map[parentName] -> childs).push_back(child);
        map[childName] = child;
    }

    void death(string name) {
        (map[name] -> name) = "DEAD";
        map.erase(name);
    }

    void DFS(Node* r, vector<string>& res) {
        if (r -> name != "DEAD")
            res.push_back(r -> name);

        for (int i = 0; i < (r -> childs).size(); ++i)
            DFS((r -> childs)[i], res);
    }

    vector<string> getInheritanceOrder() {
        vector<string> result;
        DFS(root, result);

        return result;
    }
};
