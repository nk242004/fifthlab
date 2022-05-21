#include <iostream>

using namespace std;

const char* code[5] = { "11", "10", "001", "000", "01" };

typedef char nametype;

struct node {
    node* leftchild;
    node* rightchild;

    nametype element;
};

typedef node* TREE;

void MAKENULL(TREE T)
{
    T->leftchild = NULL;
    T->rightchild = NULL;
    T->element = 0;
}

int ROOT(node* n)
{
    int left, right;
    if (n->leftchild != NULL && n->rightchild != NULL)
    {
        left = ROOT(n->leftchild) + 1;
        right = ROOT(n->rightchild) + 1;

        if (left > right)
            return right;
        else
            return left;
    }
    else if (n->leftchild == NULL)
    {
        return 1;
    }
    else if (n->rightchild == NULL)
    {
        return 1;
    }
}

void leftnode(nametype v, node* temp)
{
    if (temp->leftchild == NULL)
    {
        temp->leftchild = new node;

        temp->leftchild->element = v;

        temp->leftchild->leftchild = NULL;
        temp->leftchild->rightchild = NULL;
    }
    else if (temp->rightchild == NULL)
    {
        temp->rightchild = new node;

        temp->rightchild->element = v;

        temp->rightchild->leftchild = NULL;
        temp->rightchild->rightchild = NULL;
    }
    else
    {
        int left = ROOT(temp->leftchild);
        int right = ROOT(temp->rightchild);

        if (left == right)
            leftnode(v, temp->leftchild);
        else if(right < left)
            leftnode(v, temp->rightchild);
    }
}

void preorder(node* temp)
{
    if (temp->leftchild != NULL)
    {
        cout << temp->leftchild->element << '\t';

        preorder(temp->leftchild);
    }
    if (temp->rightchild != NULL)
    {
        cout << temp->rightchild->element << '\t';

        preorder(temp->rightchild);
    }
}

void PREORDER(TREE T)
{
    cout << T->element << '\t';

    preorder(T);

    cout << endl;
}

void postorder(node* temp)
{
    if (temp->leftchild != NULL)
    {
        postorder(temp->leftchild);
        
        cout << temp->leftchild->element << '\t';
    }
    if (temp->rightchild != NULL)
    {
        postorder(temp->rightchild);

        cout << temp->rightchild->element << '\t';
    }
}

void POSTORDER(TREE T)
{
    postorder(T);

    cout << T->element << endl;
}

void inorder(node* temp)
{
    if (temp->leftchild != NULL)
    {
        inorder(temp->leftchild);

        cout << temp->element << '\t';
    }
    else if(temp->leftchild == NULL && temp->rightchild == NULL)
        cout << temp->element << '\t';

    if (temp->rightchild != NULL)
        inorder(temp->rightchild);
}

void INORDER(TREE T)
{
    inorder(T);

    cout << endl;
}

node* leftnode(node* n, node* temp)
{
    if (!(temp->leftchild == NULL && temp->rightchild == NULL))
    {
        if (temp->leftchild == n)
            return temp;
        else if (temp->rightchild == n)
            return temp;
        else
        {
            node* returnvalue = leftnode(n, temp->leftchild);

            if (returnvalue != NULL)
                return returnvalue;

            return leftnode(n, temp->rightchild);
        }
    }

    return NULL;
}

node* preleftnode(node* temp)
{
    cout << "preleftnode" << endl;

    if (temp != NULL)
    {
        cout << "First cout" << endl;
        cout << temp->element << endl;
    }
    else
        return NULL;

    if (temp->leftchild != NULL)
    {
        cout << "second if true" << endl;
        preleftnode(temp->leftchild);
    }
    if (temp->rightchild != NULL)
    {
        cout << "third if true" << endl;
        preleftnode(temp->rightchild);
    }
    else
    {
        cout << "else" << endl;
        return NULL;
    }
}

node* PARENT(node* n, TREE T)
{
    if (T == n)
        return NULL;

    node* temp = T;

    return leftnode(n, temp);
}

node* LEFTMOST_CHILD(node* n, TREE T)
{
    node* temp = PARENT(n, T);

    temp = temp->leftchild;

    while (temp->leftchild != NULL)
        temp = temp->leftchild;

    return temp;
}

node* RIGHT_SIBLING(node* n, TREE T)
{
    node* temp = PARENT(n, T);

    if (temp->leftchild == n)
        return temp->rightchild;
    else
        return NULL;
}

nametype LABEL(node* n, TREE T)
{
    node* temp = PARENT(n, T);

    if (temp->leftchild == n)
        return temp->leftchild->element;
    else
        return temp->leftchild->element;
}

void CREATE(nametype v,  TREE T)
{
    leftnode(v, T);
}



void CODE(char* word)
{
    cout << "Coded word: " << endl;

    for(int i = 0; i < strlen(word); i++)
    switch (word[i])
    {
        case 'a':
            cout << code[0];
            break;
        case 'b':
            cout << code[1];
            break;
        case 'c':
            cout << code[2];
            break;
        case 'd':
            cout << code[3];
            break;
        case 'e':
            cout << code[4];
            break;
    }

    cout << endl;
}

void DECODE(char* word)
{
    cout << "Word: " << endl;

    for (int i = 0; i < strlen(word); i++)
        switch (word[i])
        {
        case '1':
        {
            switch (word[i + 1])
            {
            case '1':
                cout << 'a';
                break;
            case '0':
                cout << 'b';
                break;
            }

            i++;
        }
            break;

        case '0':
        {
            switch (word[i + 1])
            {
            case '1':
                cout << 'e';
                break;
            case '0':
            {
                switch (word[i + 1])
                {
                case '1':
                    cout << 'c';
                    break;
                case '0':
                    cout << 'd';
                    break;
                }

                i++;
            }
            break;
            }

            i++;
        }
            break;
        }

    cout << endl;
}




int main()
{
    char* word = new char[100];
    char* wordtwo = new char[100];

    TREE T = new node;

    MAKENULL(T);

    T->element = '-';

    char arr[15] = { 'b', 'a', ' ', ' ', ' ', ' ', '-', 'b', '\\', 'c', 'a', '*', '+', '*'};

    int count = 15;

    while ((count--) - 1)
    {
        CREATE(arr[count - 1], T);
    }

    PREORDER(T);
    POSTORDER(T);
    INORDER(T);

    cout << "Enter word to code: " << endl;

    cin >> word;

    CODE(word);

    cout << "Enter code to decode: " << endl;

    cin >> wordtwo;

    DECODE(wordtwo);

    return 0;
}
