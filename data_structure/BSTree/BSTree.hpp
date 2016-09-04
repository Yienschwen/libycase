#ifndef LIBYCPP_BSTREE_H_
#define LIBYCPP_BSTREE_H_

#include <vector>
#include <cstddef>

template <class T>
class BSTree {
public:
    //TODO: iterator
    BSTree() {
        root = NULL;
        count = 0;
    }

    // friend BSTree<T>::BSTree(const BSTree&);

    BSTree(const BSTree& bstInput) {
        if (bstInput.count != 0) {
            preorder_copy(bstInput.root, this->root, NULL);
        }
        this->count = bstInput.count;
    }
    
    BSTree& operator=(const BSTree& bstInput) {
        return BSTree<T>(bstInput);
    }

    ~BSTree() {
        clear();
    }

    void insert(const T& varInput) {
        if (root == NULL) {
            root = new Node(varInput);
        }
        else {
            Node *ptrCurrent, *ptrNext;
            ptrNext = root;
            while (ptrNext != NULL) {
                ptrCurrent = ptrNext;
                ptrNext = (varInput < ptrCurrent->key) ? (ptrCurrent->left) : (ptrCurrent->right);
            }
            ((varInput < ptrCurrent->key) ? (ptrCurrent->left) : (ptrCurrent->right)) = new Node(varInput, ptrCurrent);
        }
        count++;
    }

    std::vector<T> inorder() {
        std::vector<T> vctInorder;
        nodeInorder(root, vctInorder);
        return vctInorder;
    }

    T max() {
        Node* ptrCurrent = root;
        while (ptrCurrent != NULL) {
            if (ptrCurrent->right == NULL)
                return ptrCurrent->key;
            ptrCurrent = ptrCurrent->right;
        }
    }

    T min() {
        Node* ptrCurrent = root;
        while (ptrCurrent != NULL) {
            if (ptrCurrent->left == NULL)
                return ptrCurrent->key;
            ptrCurrent = ptrCurrent->left;
        }
    }

    void clear() {
        postorder_delete(root);
        count = 0;
    }

    std::size_t size() {
        return count;
    }
    
private:
    // delete
    // transplant

    struct Node {
        Node *parent, *left, *right;
        T key;

        Node(const T& varInput) {
            parent = left = right = NULL;
            key = varInput;
        }

        Node(const T& varInput, Node* ptrParent) {
            parent = ptrParent;
            left = right = NULL;
            key = varInput;
        }

    };

    void nodeInorder(Node *ptrNode, std::vector<T>& vctInorder) {
        if (ptrNode != NULL) {
            nodeInorder(ptrNode->left, vctInorder);
            vctInorder.push_back(ptrNode->key);
            nodeInorder(ptrNode->right, vctInorder);
        }
    }

    void preorder_copy(Node* ptrSource, Node*& ptrDest, Node* ptrParent) {
        if (ptrSource != NULL) {
            ptrDest = new Node(ptrSource->key, ptrParent);
            preorder_copy(ptrSource->left, ptrDest->left, ptrDest);
            preorder_copy(ptrSource->right, ptrDest->right, ptrDest);
        }
    }

    void postorder_delete(Node*& ptrNode) {
        if (ptrNode != NULL) {
            postorder_delete(ptrNode->left);
            postorder_delete(ptrNode->right);
            delete ptrNode;
            ptrNode = NULL;
        }
    }

    Node* root;
    std::size_t count;

};

#endif
