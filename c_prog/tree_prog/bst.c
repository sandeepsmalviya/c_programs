#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node *left;
        struct node *right;

};

struct  BST {
	struct node* root;
};


struct BST* createBST();

void  insert(struct BST *bst,int data);
void  insertR(struct node **root,int data);

struct node* delete(struct BST* bst, int data);
struct node* deleteNode(struct node* root, int data);

struct node* findR(struct node *root, int data);
struct node* find(struct BST *bst, int data);

struct node* findMin(struct BST *bst);
struct node* findMinR(struct node *root);

struct node* findMax(struct BST *bst);
struct node* findMaxR(struct node *root);


void preorderTraversal(struct node* root);
void preorder(struct BST* bst);

void inorderTraversal(struct node* root);
void inorder(struct BST* bst);

void postorderTraversal(struct node* root);
void postorder(struct BST* bst);



struct BST* createBST() {
	struct BST *temp =  (struct BST*) malloc(sizeof(struct BST));
        temp->root = NULL;	
	return temp;
}


void preorderTraversal(struct node* root) {
	if(root == NULL) {
		return;
	}
	printf("%d ", root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);

}
void preorder(struct BST* bst) {
	preorderTraversal(bst->root);	
}


void inorderTraversal(struct node* root) {
	if(root == NULL) {
		return;
	}
	inorderTraversal(root->left);
	printf("%d ", root->data);
	inorderTraversal(root->right);

}
void inorder(struct BST* bst) {
	inorderTraversal(bst->root);	
}

void postorderTraversal(struct node* root) {
	if(root == NULL) {
		return;
	}
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ", root->data);

}
void postorder(struct BST* bst) {
	postorderTraversal(bst->root);	
}


struct node* find(struct BST *bst, int data) {
	return findR(bst->root, data);
}
struct node* findR(struct node *root, int data) {

        if(root==NULL) {
                // There is no element in the tree 
                return NULL;
        }

         if(data < (root->data)) { 
                return findR(root->left, data);
         } else  if(data > (root->data)) {
		return findR(root->right, data);
	 }else {		
                return root;
	 }
}


struct node* findMin(struct BST *bst) {
	return findMinR(bst->root);
}
struct node* findMinR(struct node *root) {

        if(root==NULL) {
                // There is no element in the tree 
                return NULL;
        }

         if(root->left) { 
                return findMinR(root->left);
         } else {		
                return root;
	 }
}


struct node* findMax(struct BST *bst) {
	return findMaxR(bst->root);
}
struct node* findMaxR(struct node *root) {

        if(root==NULL) {
                // There is no element in the tree 
                return NULL;
        }

         if(root->right) { 
                return findMaxR(root->right);
         } else {		
                return root;
	 }
}


void  insert(struct BST *bst,int data) {
	insertR(&(bst->root), data);
}

void  insertR(struct node **root,int data) {
        if(*root == NULL)
        {
                struct node *temp;
                temp = (struct node *)malloc(sizeof(struct node));
                temp->data = data;
                temp->left = temp->right = NULL;
                *root = temp;
        }

        if(data >((*root)->data)) {
                 insertR(&((*root)->right), data);
        } else if(data < ((*root)->data)) {
                 insertR(&((*root)->left), data);
        }else {
        	// Else there is nothing to do as the data is already in the tree. 
	}
        
}


struct node* delete(struct BST* bst, int data) {
	return deleteNode(bst->root, data);
}
/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int data) {
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (data < root->data)
        root->left = deleteNode(root->left, data);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = findMinR(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main() {
	
	struct BST *bst = createBST();
	insert(bst, 15);

	insert(bst, 13);
	insert(bst, 11);
	insert(bst, 12);
	insert(bst, 18);
	insert(bst, 16);
	insert(bst, 17);
	insert(bst, 50);
	
	int item = 23;
	struct node* temp = find(bst, item);
	if(temp != NULL) {
		printf("Element found = %d\n", temp->data);
	}else {
		printf("Element not found = %d\n", item);
	}

	struct node* minNode = findMin(bst);
	if(minNode != NULL) {
		printf("Min Element found = %d\n", minNode->data);
	}else {
		printf("Min Element not found\n");
	}

	struct node* maxNode = findMax(bst);
	if(maxNode != NULL) {
		printf("Max Element found = %d\n", maxNode->data);
	}else {
		printf("Max Element not found\n");
	}

	printf("Preorder Traversal:\n");
	preorder(bst);
	printf("\n");

	printf("Inorder Traversal:\n");
	inorder(bst);
	printf("\n");

	printf("Postorder Traversal:\n");
	postorder(bst);
	printf("\n");
	
	return 0;
}
