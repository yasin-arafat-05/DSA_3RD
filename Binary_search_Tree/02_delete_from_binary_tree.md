<br>
<br>

# Algorithrm for deleting nodes:

```cpp

if(root->data ==data){
    // logic for deteting node
}else if(root->data > data){
    // go to right side
}else{
    // go to left side
}

```


# Example: 

<br>

### Original Tree Structure
This is the BST with the elements inserted in the order: `100, 50, 25, 70, 60, 110, 120, 115`.

```
       100
      /   \
    50     110
   /  \      \
 25   70     120
      /       /
     60      115
```

### -:  Four cases :-

### Case 1: Deleting a Node with No Child (Leaf Node)
- **Original Tree:** 

```
       100
      /   \
    50     110
   /  \      \
 25   70     120
      /       /
     60      115
```

- **Example:** Delete node `25`.

**Result:**

```
       100
      /   \
    50     110
      \      \
      70     120
      /       /
     60      115
```

**Explanation:** Node `25` is a leaf node (no children). It is simply removed, and its parent (`50`) loses the left child link.

### Case 2: Deleting a Node with One Child (Child on the Left)
- **Original Tree:**

```
       100
      /   \
    50     110
   /  \      \
 25   70     120
      /       /
     60      115
```

- **Example:** Delete node `70`.

**Result:**

` Let, root = 70  and root->left = 60 হচ্ছে, আমরা  temp নামক ভেরিবলে root->left = 60 সেভ করবো তারপর root কে ডিলিট করে, temp কে return করবো ।  `

```
       100
      /   \
    50     110
   /  \      \
  25  60     120
             /
            115
```

**Explanation:** Node `70` has only one child, `60`, which is on the left. When `70` is deleted, its child (`60`) takes its place under `50`.

### Case 3: Deleting a Node with One Child (Child on the Right)
- **Original Tree:**

```
       100
      /   \
    50     110
   /  \      \
 25   70     120
      /       /
     60      115
```

- **Example:** Delete node `110`.

**Result:**

` Let, root = 110  and root->right = 120 হচ্ছে, আমরা  temp নামক ভেরিবলে root->right = 120 সেভ করবো তারপর root কে ডিলিট করে, temp কে return করবো ।  `

```
       100
      /   \
    50     120
   /  \    /
 25   70  115
      /
     60
```

**Explanation:** Node `110` has only one child, `120`, which is on the right. When `110` is deleted, its child (`120`) takes its place under `100`.

### Case 4: Deleting a Node with Two Children
- **Original Tree:**

```
       100
      /   \
    50     110
   /  \      \
 25   70     120
      /       /
     60      115
```

- **Example:** Delete node `50`.

**Result:**
`ধরি এইক্ষেত্রে 50 কে ডিলীট করবো এক্ষেত্রে, ডিলিট করার পর যেহেতু আমাদের দুই সাইডেই(left and right) node আছে । আমরা যে কোন এক সাইডের  node কে 50 এর জায়গা দিতে হবে । যদি left সাইড থেকে দিতে চায় তাহলে left এর সবচেয়ে বড় আর right সাইড থেকে দিতে চাইলে সবচেয়ে ছোট ভ্যালু(60) দিয়ে 50 এর জায়গা পূর্ণ করবো । আর যেই খানে আগে, 25(process:01) আর  60(process:02) ছিল সেই node টা ডিলিট করে দিতে হবে ।  `


```
process:01

       100
      /   \
    25     110
   /  \      \
 NULL  70     120
      /       /
     60      115


process:02

       100
      /   \
    60     110
   /  \      \
 25   70     120
      /       /
    NULL      115

```

**Explanation:** Node `50` has two children (`25` and `70`). The in-order successor of `50` is `60` (the smallest node in the right subtree of `50`). Node `50` is replaced with `60`, and `60` is removed from its original position.

