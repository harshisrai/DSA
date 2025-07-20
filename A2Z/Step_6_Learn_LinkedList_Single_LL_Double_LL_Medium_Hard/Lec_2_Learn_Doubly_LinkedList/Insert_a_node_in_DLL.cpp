/* Problem: Insert_a_node_in_DLL */

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node* temp=head;
        while(pos--) temp=temp->next;
        Node* ins=new Node(data);
        ins->next=temp->next;
        if(ins->next) ins->next->prev=ins;
        ins->prev=temp;
        temp->next=ins;
        return head;
    }
};