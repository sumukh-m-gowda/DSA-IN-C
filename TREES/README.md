# The Tree Data Structure

## What is a Tree?

The tree is a fundamental data structure in computer science. It is called a "tree" because it consists of a set of linked nodes that visually resemble an upside-down tree structure.

In this visualization:
* **R** is the top-most node (the **Root**).
* Lines connecting the nodes are called **Edges**.

![Diagram illustrating an upside-down tree structure with nodes R, A, B, C, D, E, F, G, H, and I. R connects to A, B, C. A connects to D, E. C connects to F, G, H, I.](image_8cb5f1.png)

---

## Use Cases for Tree Data Structures

The tree data structure is incredibly useful across many fields in computer science:

* **Hierarchical Data:** Ideal for modeling data with a natural hierarchy, such as:
    * **File Systems** (directories and files).
    * **Organizational Models** (management structure).
* **Databases:** Used internally for quick data retrieval and indexing (e.g., B-Trees).
* **Routing Tables:** Used in network algorithms to manage and route data packets efficiently.
* **Sorting/Searching:** Essential for efficient data storage and searching algorithms.
* **Priority Queues:** Commonly implemented using specialized tree structures, such as **Binary Heaps**.

---

## Tree Terminology and Rules

Understanding the vocabulary is key to working with trees.

The tree visualization above can be used to define the following terms:

* **The whole tree:** The entire collection of nodes and edges.
* **Root node (R):** The single node at the top of the tree; it has no parent.
* **Nodes (A, B, C, D, E, F, G, H, I):** The fundamental elements of the tree that hold data.
* **Edges:** The links that connect one node to another.
* **Child nodes (e.g., D and E are children of A):** A node directly connected to another node (its parent) one level below it.
* **Parent nodes (e.g., A is the parent of D and E):** A node that has child nodes connected below it.
* **Leaf nodes (D, E, F, G, H, I):** Nodes that have no children.
* **Tree size (n=10):** The total number of nodes in the tree (R + A-I = 10).
* **Tree height (h=2):** The length of the longest path from the root node to a leaf node (e.g., R -> A -> D is a path of length 2).
---
# Types of Trees 🌳

Trees are a fundamental data structure in computer science, used to represent hierarchical relationships. This document covers several key types of trees, forming the basis for many efficient algorithms and data organization systems.

---

## 1. Binary Trees

The **Binary Tree** is the most basic specialized tree structure.

* **Rule:** Each node in a Binary Tree can have **up to two children**—a **left child node** and a **right child node**.
* **Foundation:** This simple structure is the foundation for more complex and optimized tree types like Binary Search Trees (BSTs) and AVL Trees.

---

## 2. Binary Search Trees (BSTs)

A **Binary Search Tree** imposes an ordering rule on the basic Binary Tree structure, making it highly efficient for searching and sorting.

* **Rule:** For **every node**, the following must be true:
    * The value of the **left child node** (and all nodes in the left subtree) must be **less than** the parent node's value.
    * The value of the **right child node** (and all nodes in the right subtree) must be **greater than** the parent node's value.
* **Advantage:** This ordered arrangement allows for very quick data retrieval and insertion (on average, $O(\log n)$ time complexity).

---

## 3. AVL Trees

An **AVL Tree** (named after its inventors, Adelson-Velsky and Landis) is a self-balancing version of a Binary Search Tree.

* **Key Feature: Self-Balancing:** For every node, the difference in **height** between the left subtree and the right subtree is **at most one**. This difference is known as the **Balance Factor**.
* **Mechanism:** This balance is maintained automatically through special operations called **rotations** whenever a node is inserted or deleted.
* **Advantage:** By maintaining balance, the worst-case search time complexity is guaranteed to remain $O(\log n)$, preventing performance degradation that can happen in an unbalanced BST.

---

## 💡 Next Steps

Each of these data structures will be described in detail in subsequent pages, including:

* Interactive animations of insertions and deletions.
* Guides on how to implement them in code.
