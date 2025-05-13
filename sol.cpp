// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
        
//    // brute force approach.

//      if(nums.size() < 2) return 0;  // here No pair exits.

//       int maxi = 0;

//      for(int i = 0; i<nums.size(); i++){
     
//      for(int j  = i+1; j<nums.size(); j++){
//         maxi = max(maxi,nums[i]^nums[j]);
//      }
    
//      }

//       return maxi;
//     }
// };


class TrieNode {
    public:
        TrieNode* left;  // represents 0
        TrieNode* right; // represents 1
    
        TrieNode() {
            left = nullptr;
            right = nullptr;
        }
    };
    
    class Solution {
    private:
        TrieNode* root;
    
        void insert(int num) {
            TrieNode* curr = root;
            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if(bit == 0) {
                    if(!curr->left) curr->left = new TrieNode();
                    curr = curr->left;
                } else {
                    if(!curr->right) curr->right = new TrieNode();
                    curr = curr->right;
                }
            }
        }
    
        int findMaxXOR(int num) {
            TrieNode* curr = root;
            int maxXOR = 0;
    
            for(int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if(bit == 0) {
                    if(curr->right) {
                        maxXOR |= (1 << i);
                        curr = curr->right;
                    } else {
                        curr = curr->left;
                    }
                } else {
                    if(curr->left) {
                        maxXOR |= (1 << i);
                        curr = curr->left;
                    } else {
                        curr = curr->right;
                    }
                }
            }
    
            return maxXOR;
        }
    
    public:
        int findMaximumXOR(vector<int>& nums) {
            root = new TrieNode();
            int maxResult = 0;
    
            for(int num : nums) {
                insert(num);
            }
    
            for(int num : nums) {
                maxResult = max(maxResult, findMaxXOR(num));
            }
    
            return maxResult;
        }
    };