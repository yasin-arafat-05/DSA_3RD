
To align the response with the format you shared earlier, I'll break down the procedure and map it to the C++ code you've provided. I'll cover both searching and insertion in the binary search tree (BST) as per the logic used in your code.

---


<br>
<br>


### **Procedure 7.4: Search in BST (LOC, ROOT, ITEM)**

A binary search tree `T` is in memory, and an `ITEM` is given. This procedure searches for the location `LOC` of the `ITEM` in `T` and follows these cases:
1. **LOC = NULL** means `ITEM` is not in the tree.
2. **LOC ≠ NULL** means `ITEM` is found in the tree.

#### **Steps:**

1. **[Is the Tree Empty?]**
   - If `ROOT = NULL`, set `LOC := NULL` (i.e., `ITEM` is not in the tree) and exit.

2. **[Is ITEM the root?]**
   - If `ROOT->data == ITEM`, set `LOC := ROOT` and exit.

3. **[Recursive Search]**
   - If `ITEM < ROOT->data`, recursively search in the left subtree (`searchInBST(ROOT->left, ITEM)`).
   - If `ITEM > ROOT->data`, recursively search in the right subtree (`searchInBST(ROOT->right, ITEM)`).

4. **[Result]**
   - If the recursion reaches a `NULL` pointer, the item is not found in the tree.

---

### **Code Implementation for Search in BST**

```cpp
bool searchInBST(Node *root, int data) {
    Node *temp = root;
   
    // Base case: Tree is empty
    if (temp == NULL) {
        return false;
    }

    // Base case: ITEM found at root
    if (temp->data == data) {
        return true;
    }

    // Recursive logic to search in left or right subtree
    if (data < temp->data) {
        return searchInBST(temp->left, data);
    } else {
        return searchInBST(temp->right, data);
    }
}
```


<br>
<br>


---

### **Procedure 7.5: Insert into BST (ROOT, ITEM)**

A binary search tree `T` is in memory, and an `ITEM` is given. This procedure inserts `ITEM` into `T` while maintaining the properties of a binary search tree.

#### **Steps:**

1. **[Is Tree Empty?]**
   - If `ROOT = NULL`, create a new node with `ITEM`, assign it to `ROOT`, and return.

2. **[Find the Insertion Position]**
   - If `ITEM < ROOT->data`, recursively move to the left subtree (`insertIntoBST(ROOT->left, ITEM)`).
   - If `ITEM > ROOT->data`, recursively move to the right subtree (`insertIntoBST(ROOT->right, ITEM)`).

3. **[Insert New Node]**
   - When a `NULL` node is reached, create a new node and attach it as the left or right child.

---

### **Code Implementation for Insertion in BST**

```cpp
Node *insertIntoBST(Node *&root, int data) {

    // Base case: If root is NULL, create a new node and return it
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    // Recursive logic to insert in left or right subtree
    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    
    return root;
}
```


<br>
<br>


---

### **Procedure for Deletion in BST**

#### **Steps:**

1. **[Is Tree Empty?]**
   - If `ROOT = NULL`, exit as the tree is empty.

2. **[Find the Node to Delete]**
   - Recursively move left or right based on whether the value to delete is less than or greater than the current node's data.

3. **[Node Found]**
   - **Case 1:** Node with **no children**. Simply delete the node.
   - **Case 2:** Node with **one child**. Delete the node and replace it with its child.
   - **Case 3:** Node with **two children**. Find the minimum value in the right subtree, replace the node's data with that value, and then delete the node with the minimum value from the right subtree.

---

### **Code Implementation for Deletion in BST**

```cpp
Node *deleteFromBST(Node *root, int val) {

    // Base case: Tree is empty
    if (root == NULL) {
        return root;
    }

    // Finding the node to delete
    if (val < root->data) {
        root->left = deleteFromBST(root->left, val);
    } else if (val > root->data) {
        root->right = deleteFromBST(root->right, val);
    } else {
        // Node found

        // Case 1: No children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        // Case 2: One child (left)
        if (root->left != NULL && root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 2: One child (right)
        if (root->right != NULL && root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: Two children
        if (root->left != NULL && root->right != NULL) {
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = deleteFromBST(root->right, min);
        }
    }

    return root;
}
```

---

