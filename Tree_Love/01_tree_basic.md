
### Defination of Tree:

A binary tree is a data structure in computer science where each node has at most two children, referred to as the left child and the right child.

- Tree is a non-linear data structure. (But linked list is a linear data structure.)


<br>
<br>
<br>


### Some Important term of a Binary Tree :

#### 1. **Node**:
A **node** is the fundamental unit of a binary tree that stores a piece of data, and may have links (or pointers) to other nodes (its children).

**Example Visualization**:
```
   [10]  <-- This is a node containing the value 10.
```

#### 2. **Root**:
The **root** is the topmost node in a binary tree. It is the ancestor of all other nodes in the tree.

**Example Visualization**:
```
    [1]  <-- This is the root of the tree.
   /   \
 [2]   [3]
```

#### 3. **Children**:
**Children** are the nodes that are directly connected to another node (parent) in the tree. Each node can have up to two children in a binary tree.

**Example Visualization**:
```
    [1]
   /   \
 [2]   [3]  <-- Nodes 2 and 3 are the children of node 1.
```

#### 4. **Parent**:
A **parent** node is a node that has one or more child nodes. 

**Example Visualization**:
```
    [1]  <-- Node 1 is the parent of nodes 2 and 3.
   /   \
 [2]   [3]
```

#### 5. **Sibling**:
**Siblings** are nodes that share the same parent node.

**Example Visualization**:
```
    [1]
   /   \
 [2]   [3]  <-- Nodes 2 and 3 are siblings (they share the same parent, node 1).
```

#### 6. **Ancestor**:
An **ancestor** of a node is any node along the path from the root to that node. The node itself is not considered its ancestor.

**Example Visualization**:
```
    [1]  <-- Node 1 is an ancestor of nodes 2, 4, and 5.
   /   \
 [2]   [3]  <-- Node 2 is an ancestor of nodes 4 and 5.
 / \
[4] [5]
```

- Ancestors of Node 5: [2], [1]

#### 7. **Descendant**:
A **descendant** is any node that is connected to a node by a path of edges going downward in the tree.

**Example Visualization**:
```
    [1]
   /   \
 [2]   [3]  <-- Nodes 4 and 5 are descendants of node 2.
 / \
[4] [5]
```

- Descendants of Node 2: [4], [5]

#### 8. **Leaf**:
A **leaf** node is a node that has no children (i.e., both its left and right pointers are `null`).

**Example Visualization**:
```
    [1]
   /   \
 [2]   [3]
 / \
[4] [5]  <-- Nodes 4, 5, and 3 are leaf nodes (no children).
```

### Complete Example with All Terms:

```
            [1]  <-- Root
           /   \
        [2]     [3]  <-- Children of node 1 (Siblings)
       /   \
     [4]   [5]  <-- Children of node 2 (Siblings and Leaf nodes)
     /
   [6]  <-- Leaf and Descendant of nodes 2 and 1
```

- **Node 1** is the **root**.
- **Nodes 2 and 3** are the **children** of node 1.
- **Node 1** is the **parent** of nodes 2 and 3.
- **Nodes 4 and 5** are **siblings** (children of node 2).
- **Node 2** is the **ancestor** of nodes 4, 5, and 6.
- **Node 6** is a **descendant** of nodes 2 and 1.
- **Nodes 3, 5, and 6** are **leaf** nodes.

This example captures all the essential relationships within a binary tree.