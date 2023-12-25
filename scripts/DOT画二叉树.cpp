/*
    画出二叉树，并且依叶结点权重大小来决定叶结点颜色
*/

class BinaryTree {
public:
    int nextPowerOfTen(int n) {
        int power = static_cast<int>(std::pow(10, std::ceil(std::log10(n))));
        return power;
    }

    uint64_t degree[4];
    void draw(const std::string &outf) {
        std::vector<uint64_t> weights;
        // 遍历所有叶结点，获取权重划分
        for (const auto* ptr = begin_; ptr != nullptr; ptr = ptr->next) {
            weights.push_back(ptr->weight);
        }
        std::sort(weights.begin(), weights.end());

        degree[0] = nextPowerOfTwo(weights[weights.size() / 5]);
        degree[1] = nextPowerOfTwo(weights[weights.size() / 5 * 2]);
        degree[2] = nextPowerOfTwo(weights[weights.size() / 5 * 3]);
        degree[3] = nextPowerOfTwo(weights[weights.size() / 5 * 4]);
        std::cout << "degree: " << std::endl;
        for (int i = 0; i < 4; i ++) {
            std::cout << degree[i] << "  ";
        }
        std::cout << std::endl;

        std::ofstream out(outf);
        out << "digraph G {" << std::endl;
        out << "edge [dir=none];\nnode [style=filled fillcolor=white fixedsize=true]" << std::endl;
        std::string name = "";
        to_graph(root_, out, name);


        std::string leaf_prefix("LEAF_");
        std::string internal_prefix("INT_");
        std::queue<TreeNode*> q;
        q.push(root_);
        while (!q.empty()) {
            int size = q.size();
            out << "{rank=same ";

            while (size > 0) {
                const auto head = q.front();
                q.pop();
                size --;
                if (!(head->leaf)) {
                    // 因二叉树特性而异……
                    assert(head->left != nullptr && head->right != nullptr);
                    q.push(head->left);
                    q.push(head->right);
                    out << (head->left->leaf ? leaf_prefix : internal_prefix) << std::to_string(reinterpret_cast<uint64_t>(head->left)) << " " << (head->right->leaf ? leaf_prefix : internal_prefix) << std::to_string(reinterpret_cast<uint64_t>(head->right)) << " ";
                }
            }

            out << "};\n";
        }

        out << "}" << std::endl;
        out.close();
    }

    void to_graph(TreeNode* node, std::ofstream &out, std::string& name) {
        std::string leaf_prefix("LEAF_");
        std::string internal_prefix("INT_");
        if (node->leaf) {
            // Print node name
            out << leaf_prefix << std::to_string(reinterpret_cast<uint64_t>(node));
            // Print node properties
            out << "[shape=circle label=\""+ name + "\" ";
            // Print color of the node
            std::string color;
            int size = node->weight;
            if (size < degree[0]) {
                color = "#fbffd5";
            } else if (size < degree[1]) {
                color = "#e6f2a7";
            } else if (size < degree[2]) {
                color = "#aed1af";
            } else if (size < degree[3]) {
                color = "#71afab";
            } else {
                color = "#4a7ab1";
            }
            out << "fillcolor=\""<< color << "\"];\n";


            // Print Leaf node link if there is a next page
            // if (node->next) {
            //     out << leaf_prefix << std::to_string(reinterpret_cast<uint64_t>(node)) << " -> " << leaf_prefix << std::to_string(reinterpret_cast<uint64_t>(node->next)) << ";\n";
            // }
            return ;
        }
        // Print node name
        out << internal_prefix << std::to_string(reinterpret_cast<uint64_t>(node));
        // Print node properties
        out << "[shape=circle label=\""+ name + "\"];\n";
        // Print leaves
        to_graph(node->left, out, name);
        out << internal_prefix << std::to_string(reinterpret_cast<uint64_t>(node)) << ":p" << std::to_string(reinterpret_cast<uint64_t>(node->left)) << " -> ";
        if (node->left->leaf) {
            out << leaf_prefix << std::to_string(reinterpret_cast<uint64_t>(node->left)) << ";\n";
        } else {
            out << internal_prefix << std::to_string(reinterpret_cast<uint64_t>(node->left)) << ";\n";
        }

        to_graph(node->right, out, name);
        out << internal_prefix << reinterpret_cast<uint64_t>(node) << ":p" << reinterpret_cast<uint64_t>(node->right) << " -> ";
        if (node->right->leaf) {
            out << leaf_prefix << std::to_string(reinterpret_cast<uint64_t>(node->right)) << ";\n";
        } else {
            out << internal_prefix << std::to_string(reinterpret_cast<uint64_t>(node->right)) << ";\n";
        }
    }
};