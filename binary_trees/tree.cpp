#include "tree.h"
Node *buildTree(string &str)
{
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
void inorder(Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    else
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int num_nodes(Node *T)
{
    if(T == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + num_nodes(T->left) + num_nodes(T->right));
    }
}
int leaf_nodes(Node *T)
{   
    if(T == NULL)
    {
        return 0;
    }
    else if(T->left == NULL && T->right == NULL)
    {
        return 1;
    }
    else
    {
        return (leaf_nodes(T->left) + leaf_nodes(T->right));
    }
}
int num_non_leaf_nodes(Node* T)
{
    int c1 = num_nodes(T);
    int c2 = leaf_nodes(T);
    return (c1-c2);
}
bool compare(Node* T1,Node* T2)
{
    if(T1 == NULL && T2 == NULL)
    {
        return true;
    }
    else if((T1 == NULL && T2 != NULL) || (T2 == NULL && T1 != NULL))
    {
        return false;
    }
    else if(T1->data != T2->data)
    {
        return false;
    }
    else
    {
        return true && compare(T1->left,T2->left) && compare(T1->right,T2->right);
    }
}
void swap(Node *T)
{
    if(T == NULL)
    {
        return;
    }
    else
    {
        Node *temp = T->left;
        T->left = T->right;
        T->left = temp;
        swap(T->left);
        swap(T->right);
    }
}
void clone_util(Node *T1,Node *T2)
{

}
void clone(Node *T1,Node *T2)
{
    
}
int main()
{   
    string s,s1;
    s = "1 2 3 4 5 N N N N N N";
    s1 = "1 2 3 4 5 N N N N N N";
    Node *root1 = buildTree(s);
    Node *root2 = buildTree(s1);
    cout<<num_non_leaf_nodes(root1)<<endl<<compare(root1,root2)<<endl;
    inorder(root1);
    swap(root1);
    cout<<endl;
    inorder(root1);
    return 0;
}