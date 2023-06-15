#include <iostream>
using namespace std;

// Binary Search Tree Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree
class BST
{
private:
    Node *root;

    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void inorderArray(Node *node, int *arr, int index)
    {
        if (node == nullptr)
        {
            return;
        }

        arr[index] = node->data;
        inorderArray(node->left, arr, index * 2);
        inorderArray(node->right, arr, index * 2 + 1);
    }

    int countNodesWithOneChild(Node *node)
    {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr))
        {
            return 0;
        }

        int count = 0;
        if (node->left == nullptr || node->right == nullptr)
        {
            count = 1;
        }

        count += countNodesWithOneChild(node->left) + countNodesWithOneChild(node->right);
        return count;
    }

    int treeSize(Node *root)
    {
        if (root == NULL)
            return 1;
        else
            return treeSize(root->left) + treeSize(root->right) + 1;
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void inorderArray(int *arr, int size)
    {
        inorderArray(root, arr, 1);
        int last = 0;
        for (int i = 1; i <= size; i++)
        {
            if (arr[i] != 0)
                last = i;
        }
        for (int i = 1; i <= last; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int countNodesWithOneChild()
    {
        return countNodesWithOneChild(root);
    }

    int get_treeSize()
    {
        return treeSize(root);
    }
};

int main()
{
    int n;
    cin >> n;

    BST tree;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        tree.insert(num);
    }
    int treeSize = tree.get_treeSize();
    int arr[2 * treeSize + 1] = {0};
    tree.inorderArray(arr, 2 * treeSize);

    int count = tree.countNodesWithOneChild();
    cout << count << endl;

    return 0;
}