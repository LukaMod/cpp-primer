#ifndef EX_13_28_B_H_
#define EX_13_28_B_H_

#include "TreeNode.h"

class BinStrTree
{
  public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree &rhs) : root(new TreeNode(*rhs.root)) {}
    BinStrTree &operator=(const BinStrTree &rhs)
    {
        auto newroot = new TreeNode(*rhs.root);
        this->~BinStrTree();
        root = newroot;
        return *this;
    }
    ~BinStrTree() { delete root; }
  private:
    TreeNode *root;
};

#endif