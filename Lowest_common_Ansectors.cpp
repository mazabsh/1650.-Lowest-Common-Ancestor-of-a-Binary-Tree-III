#include<iostream> 
#include<unordered_set> 

using namespace std; 

class Node{
public: 
      int val; 
      Node* left; 
      Node* right; 
      Node* parent; 
      Node(int _val): val(_val), left(nullptr), right(nullptr), parent(nullptr){}
   
}; 

class Solution{
public:  
      Node* lowestCommonAncestor(Node* p, Node * q){
        if(p==q) return p; 
        unordered_set<Node*> ansectors; 
        while(p!=nullptr) {
          ansectors.insert(p); 
          p = p->parent; 
        }
        while(q!=nullptr){
          if(ansectors.count(q)) return q; 
          q = q->parent; 
        }
        return nullptr; 
      }
};
int main(){
    Node* root = new Node(3);
    Node* node5 = new Node(5);
    Node* node1 = new Node(1);
    Node* node6 = new Node(6);
    Node* node2 = new Node(2);

    // Set up left/right and parent pointers
    root->left = node5; root->right = node1;
    node5->parent = root; node1->parent = root;
    node5->left = node6; node5->right = node2;
    node6->parent = node5; node2->parent = node5;

    // Test case
    Solution sol;
    Node* lca = sol.lowestCommonAncestor(node6, node2);
    cout << "LCA of 6 and 2: " << lca->val << endl;  // Expected: 5

    // Clean up memory
    delete root;
    delete node5;
    delete node1;
    delete node6;
    delete node2;

    return 0;
}
  
