#ifndef EX_13_28_A_H_
#define EX_13_28_A_H_

#include <string>

class TreeNode
{
  public:
    TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right)
    {
        ++*count;
    }
    TreeNode &operator=(const TreeNode &rhs)
    {
        ++*rhs.count;
        this->~TreeNode();
        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;
        return *this;
    }
    ~TreeNode()
    {
        if (--*count == 0)
        {
            if (left)
            {
                delete left;
                left = nullptr;
            }
            if (right)
            {
                delete right;
                right = nullptr;
            }
            delete count;
            count = nullptr;
        }
    }

  private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

#endif