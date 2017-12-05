#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ms(a,b) memset(a,b,sizeof(a))
#define fr(i,a,b) for(long long int i=a;i<b;i++)
#define vsort(v) sort(v.begin(),v.end())
#define whl(t) while(t--)
#define vuni(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )
#define mod 1000000007

using namespace std;
//akashravi.tk

typedef long long ll;

void fscpp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Tnode
{
    int val, pr;
    Tnode *left, *right;
};

Tnode* newnode(int key)
{
    Tnode* tp = new Tnode;
    tp->val = key;
    tp->pr = rand();
    tp->left = tp->right = NULL;
    return tp;
}
Tnode* search(Tnode* root, int key)
{
    if(root==NULL or root->val==key)
        return root;
    if(root->val < key)
        search(root->left,key);
    else search(root->right,key);
}

/*
pair<Tnode*, Tnode*> split(Tnode* root, int x)
{
    if(root->val <= x)
    {
        Tnode* t1=root;
        Tnode* t2=root->right;
        return mp(t1,t2);
    }
    else split(root->left,x);
}
*/

void split(Tnode* t,Tnode* &l,Tnode* &r,int key)
{
    if(!t) l=r=NULL;
    else if(t->val<=key)
    {
        split(t->right,t->right,r,key);
        l=t;
    }
    else
    {
        split(t->left,l,t->left,key);
        r=t;
    }
}

Tnode* merge(Tnode* t1, Tnode* t2)
{
    //Tnode* root;
    if(t1==NULL) return t2;
    if(t2==NULL) return t1;
    if(t1->pr < t2->pr)
    {
        // root=t2;
        t2->left=merge(t1,t2->left);
        // return root;
    }
    else
    {
        // root=t1;
        t1->right=merge(t1->right,t2);
    }
    // return root;
}

/*
void insert(Tnode* root, Tnode* a, Tnode* parent,int c)
{
    if(!root) root=a;
    else if(root->pr > a->pr)
    {
        if(root->val > a->val)
        {
            insert(root->left,a,root,1);
        }
        else
        {
            insert(root->right,a,root,2);
        }
    }
    else
    {
        if(c==1)
        {
            parent->left=a;
            //pair<Tnode*, Tnode*> p= split(root, a->val);
            a->left=p.first;
            a->right=p.second;
        }
        else
        {
            parent->right=a;
            pair<Tnode*, Tnode*> p= split(root, a->val);
            a->left=p.first;
            a->right=p.second;
        }
    }

}
*/

void insert(Tnode* &root, Tnode* a)
{
    if(!root) root=a;
    else if(a->pr > root->pr)
    {
        split(root,a->left,a->right,a->val);
        root=a;
    }
    else
    {
        if(root->val <= a->val)
            insert(root->right,a);
        else
            insert(root->left,a);
    }
}

void inorder(Tnode* root)
{
    if (root)
    {
        inorder(root->left);
        cout << "val: "<< root->val << "  pr: "<< root->pr << endl;
        inorder(root->right);
    }
}

int main()
{

    srand(time(NULL));
    Tnode* root=newnode(10);
    Tnode* a=newnode(12);
    insert(root,a);
    a=newnode(8);
    insert(root,a);
    a=newnode(18);
    insert(root,a);
    Tnode* root2=newnode(20);
    a=newnode(14);
    insert(root2,a);
    a=newnode(16);
    insert(root2,a);
    inorder(root);
    cout<<endl;
    inorder(root2);
    cout<<endl<<"After merging:"<<endl;
    Tnode* b=merge(root,root2);
    inorder(b);

    //cout<<"\n";

    return 0;
}
