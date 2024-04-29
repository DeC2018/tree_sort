#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* insert(Node* root, int value) {
    if (root == NULL) {
        root = (Node*) malloc(sizeof(Node));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
    } else if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(Node* root, int* arr, int* index) {
    if (root != NULL) {
        inorder(root->left, arr, index);
        arr[(*index)++] = root->value;
        inorder(root->right, arr, index);
    }
}

void treeSort(int arr[], int n) {
    int i;
    Node* root = NULL;

    for (i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    int index = 0;
    inorder(root, arr, &index);

    free(root);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    treeSort(arr, n);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
