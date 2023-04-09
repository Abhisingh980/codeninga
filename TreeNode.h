#include <vector>
using namespace std;
template <typename t>
class TreeNode{
    public:
    t data;
    vector<TreeNode<t>*> children;
    TreeNode(t data){
        this->data=data;
    }
};
