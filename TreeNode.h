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
  ~TreeNode(){
    for(int i=0;i<children.size();i++){
        delete children[i];
    }
  }
};