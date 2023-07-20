#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *BuildTree(node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the left side"
         << " " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter the right side"
         << " " << data << endl;
    root->right = BuildTree(root->right);
    return root;
}
void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
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
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
node *bulidlevelorder(node *root)
{
    queue<node *> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter the left node for :" << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter the right node for :" << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    
    int ans=max(l,r)+1;
    return ans;
}
pair<int,int> diameterfast(node*root)
{
    if(root==NULL)
    {
        pair<int,int> p=make_pair(0,0);
        return p;
    }
    pair<int,int> left=diameterfast(root->left);
    pair<int,int> right=diameterfast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int diameter(node *root)
{
    // if(root==NULL)
    // {
    //     return 0;
    // }
    // int op1=diameter(root->left);
    // int op2=diameter(root->right);
    // int op3=height(root->left)+1+height(root->right);

    // int ans=max(op1,max(op2,op3));
    return diameterfast(root).first;
}
pair<bool,int> isbalancedfast(node* root)
{
    if(root==NULL)
    {
        pair<bool,int>p =make_pair(true,0);
        return p;
    }
    pair<int,int> left=isbalancedfast(root->left);
    pair<int,int> right=isbalancedfast(root->right);
    bool leftAns=left.first;
    bool rightAns=right.first;
    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int> ans;
    ans.second=max(left.second,right.second+1);
    if(leftAns&&rightAns&&diff)
    {
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;

}
bool isbalanced(node *root)
{
    // if(root==NULL){
    //     return true;
    // }
    // bool left=isbalanced(root->left);
    // bool right=isbalanced(root->right);

    // bool diff=abs(height(root->left)-height(root->right))<=1;
    // if(left && right && diff)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return false;
    // }
    return isbalancedfast(root).first;
}
int main()
{
    node *root = NULL;
    // bulidlevelorder(root);
    // levelordertraversal(root);
    root = BuildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 8 9 -1 -1 -1 -1 
    int s=height(root);
    cout<<"Height of tree is : "<<s<<endl;
    // int s1=diameter(root);
    // cout<<"Diameter of tree is : "<<s1<<endl;
    if(isbalanced(root))
    {
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"not Balanced"<<endl;

    }
    //  cout<<"Level Order Traversal:"<<endl;
    //  levelordertraversal(root);

    // cout<<"Inorder Traversal"<<endl;
    // inorder(root);
    // cout<<endl;
    // cout<<"Preorder Traversal"<<endl;
    // preorder(root);
    // cout<<endl;
    // cout<<"Postorder Traversal"<<endl;
    // postorder(root);
    // cout<<endl;
    return 0;
}
