#include <iostream>
#include <string.h>

using namespace std;

char Pre[26], In[26];
struct Node{
    char c;
    Node *left, *right;
    Node(char t){
        c = t;
    }
};

Node* PreInCreate(int l1, int r1, int l2, int r2){
    Node *root = new Node(Pre[l1]);
    int i,llen,rlen;
    for (i = l2; In[i] != Pre[l1];i++);
    llen = i - l2;
    rlen = r2 - i;
    if(llen)
        root->left = PreInCreate(l1 + 1, l1 + llen, l2, i - 1);
    else
        root->left = NULL;
    if(rlen)
        root->right = PreInCreate(l1+llen+1, r1, i+1, r2);
    else
        root->right = NULL;
    return root;
}

void PostTrave(Node *root){
    if(root==NULL) return;
    PostTrave(root->left);
    PostTrave(root->right);
    printf("%c", root->c);
}

int main(){
    int len;
    Node *root = NULL;
    while(scanf("%s%s", Pre, In) != EOF){
       len = strlen(Pre);
       root = PreInCreate(0, len - 1, 0, len - 1);
       PostTrave(root);
       printf("\n");
    }
    system("pause");
    return 0;
}
