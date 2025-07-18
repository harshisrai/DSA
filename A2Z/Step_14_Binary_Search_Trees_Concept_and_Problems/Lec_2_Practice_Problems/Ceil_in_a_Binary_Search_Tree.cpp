/* Problem: Ceil_in_a_Binary_Search_Tree */

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    int ans=-1; 
    while(root){
        if(root->data==input) return input; 
        else if(root->data<input) root=root->right; 
        else{
            ans=root->data; 
            root=root->left; 
        }
    }
    return ans; 
}