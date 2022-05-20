using namespace std;

#include <iostream>
#include <queue>

// To do level order, you need to do a BFS
//Only now that we don't need to traverse, we need to find elements in each level

// DFS = preorder, postorder, inorder

//You can treat trees and graphs to be the samer for this purpose

// We can use a Queue to efficiently traverse in BFS fashion. Here are the steps of our algorithm:

// 1. Start by pushing the root node to the queue.
// 2. Keep iterating until the queue is empty.
// 3. In each iteration, first count the elements in the queue (let’s call it levelSize). We will have these many nodes in the current level.
// 4. Next, remove levelSize nodes from the queue and push their value in an array to represent the current level.
// 5. After removing each node from the queue, insert both of its children into the queue.
// 6. If the queue is not empty, repeat from step 3 for the next level.

class TreeNode{

    public:

    int val = 0;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = nullptr;

    }
    
};


class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      int levelSize = queue.size();
      vector<int> currentLevel;
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();
        // add the node to the current level
        currentLevel.push_back(currentNode->val);
        // insert the children of current node in the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
      result.push_back(currentLevel);
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}