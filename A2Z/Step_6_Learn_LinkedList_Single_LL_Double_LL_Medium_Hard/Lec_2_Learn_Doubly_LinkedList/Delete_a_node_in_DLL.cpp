/* Problem: Delete_a_node_in_DLL */



class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        x-=2;
        Node* temp=head;
        
        if(x==-1){
            if(temp->next) head=temp->next, head->prev=nullptr;
            delete temp;
            return head;
        }
        while(x--){
            temp=temp->next;
        }
        
        Node* del=temp->next; 
        temp->next=del->next;
        if(del->next) del->next->prev=temp;
        delete del;
        return head;
        
        
        
    }
};