#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (!temp)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    if (!root)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxVal(Node *root)
{
    Node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteFromBST(Node *root, int val)
{
    // base case
    if (!root)
    {
        return NULL;
    }

    if (root->data == val)
    {
        // 0 child
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left && root->right)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        // left part
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        // right part
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter data : ";
    takeInput(root);
    cout << "Level Order Traversal Below : " << endl;
    levelOrder(root);

    cout << "Inorder Traversal Below : " << endl;
    inorder(root);

    cout << endl
         << "Preorder Traversal Below : " << endl;
    preorder(root);

    cout << endl
         << "Postorder Traversal Below : " << endl;
    postorder(root);

    cout << endl
         << "Min value in the tree is : " << minVal(root)->data << endl;
    cout << "Max value in the tree is : " << maxVal(root)->data << endl;

    int val;
    cout << "Enter a node to delete : ";
    cin >> val;
    deleteFromBST(root, val);
    cout << "Tree After Deletion : " << endl;
    levelOrder(root);

    return 0;
}