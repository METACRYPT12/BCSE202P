
#include <iostream>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

public:
    BST();
    BST(int);
    BST *Insert(BST *, int);
    void InOrder(BST *);
    void preOrder(BST *);
    void postOrder(BST *);
};

BST::BST()
{
    data = 0;
    left = NULL;
    right = NULL;
}

BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST *BST::Insert(BST *root, int data)
{
    if (root == NULL)
    {
        return new BST(data);
    }

    if (data > root->data)
    {
        root->right = Insert(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = Insert(root->left, data);
    }

    return root;
}

void BST::InOrder(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void BST::preOrder(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void BST::postOrder(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int tmp, choice;
    BST tree;
    BST *root = NULL;
    bool flag = true;
    cout << "Enter elements of Tree(-100 to terminate): " << endl;
    cin >> tmp;
    if (tmp != -100)
        root = tree.Insert(root, tmp);
    cin >> tmp;
    while (tmp != -100)
    {
        tree.Insert(root, tmp);
        cin >> tmp;
    }
    while (flag)
    {

        cout << "1. preOrder" << endl;
        cout << "2. InOrder" << endl;
        cout << "3. postOrder" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            tree.preOrder(root);
            cout << "\n\n";
            break;
        case 2:
            tree.InOrder(root);
            cout << "\n\n";
            break;
        case 3:
            tree.postOrder(root);
            cout << "\n\n";
            break;
        case 0:
            flag = false;
            break;
        default:
            break;
        }
    }
    return 0;
}