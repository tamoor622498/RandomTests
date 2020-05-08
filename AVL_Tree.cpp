#include <iostream>
#include <queue>

using namespace std;

class AVL {
public:
    struct Node {
        Node(int dat){
            data = dat;
            parent = nullptr;
            left = nullptr;
            right = nullptr;
            height = 0;
        }

        int data;
        Node* parent;
        Node* left;
        Node* right;
        int height;
    };

    AVL(){
        root = nullptr;
    }

    Node* insert(int num, Node* &curr);

    Node* search(int numb);

    void deleteNode();

    void inorder(Node* curr);

    void preorder(Node* curr);

    void postorder(Node* curr);

    void balance();

   void printLevelOrder(Node *root);

    //Variables
    Node* root;
};

AVL::Node* AVL::insert(int numb, Node* &curr) {
    Node* child;
    if (curr == nullptr){
        curr = new Node(numb);
    } else if (numb <= curr->data){
        curr->left = insert(numb,curr->left);
        child = curr->left;
        child->parent = curr;
        child->height = curr->height+1;
    } else {
        curr->right = insert(numb,curr->right);
        child = curr->right;
        child->parent = curr;
        child->height = curr->height+1;
    }

    return curr;
}

AVL::Node *AVL::search(int numb) {
    return nullptr;
}

void AVL::deleteNode() {

}

void AVL::inorder(Node* curr) {
    if (curr->left != nullptr){
        inorder(curr->left);
    }

    cout << curr->data << " ";

    if (curr->right != nullptr){
        inorder(curr->right);
    }
}

void AVL::preorder(Node* curr) {
    cout << curr->data << " ";

    if (curr->left != nullptr){
        preorder(curr->left);
    }

    if (curr->right != nullptr){
        preorder(curr->right);
    }
}

void AVL::postorder(Node* curr) {
    if (curr->left != nullptr){
        postorder(curr->left);
    }

    if (curr->right != nullptr){
        postorder(curr->right);
    }

    cout << curr->data << " ";
}

void AVL::balance() {

}

void AVL::printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL) return;

    // Create an empty queue for level order tarversal
    queue<Node *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // nodeCount (queue size) indicates number
        // of nodes at current lelvel.
        int nodeCount = q.size();

        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0)
        {
            Node *node = q.front();
            cout << node->data << " " << "Height: " << node->height << " ";
            q.pop();
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}

int main() {
    AVL test;
    for (int i = 0; i < 20; ++i) {
        test.insert((rand() % 100+1) ,test.root);
    }
//    AVL::Node *r;
//    r = test.root;
    test.inorder(test.root);
    cout << endl;
    test.preorder(test.root);
    cout << endl;
    test.postorder(test.root);
    cout << endl;
    test.printLevelOrder(test.root);

    return 0;
}

