# Data Structures and Algorithms (DSA) in C

Welcome to the **DSA in C** repository! This repository contains implementations of fundamental **data structures** and **algorithms** using the C programming language. It is designed to help students, beginners, and enthusiasts learn and practice DSA concepts effectively.

## Table of Contents
- [About](#about)
- [Features](#features)
- [Data Structures](#data-structures)
- [Algorithms](#algorithms)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## About
This repository focuses on providing clean and efficient implementations of various data structures and algorithms in C. Each module is explained with examples and is designed to help improve your problem-solving and coding skills.

## Features
- Easy-to-understand C implementations
- Well-structured and commented code
- Covers both **linear** and **non-linear** data structures
- Includes common algorithms for sorting, searching, and more
- Useful for coding interviews and competitive programming practice

## Data Structures
Implemented data structures include:

- **Linear Data Structures**
  - Arrays
  - Linked Lists (Singly, Doubly, Circular)
  - Stack
  - Queue (Simple, Circular, Priority)
  
- **Non-linear Data Structures**
  - Trees (Binary Tree, Binary Search Tree, AVL Tree)
  - Graphs
  - Heaps

## Algorithms
Implemented algorithms include:

- **Sorting Algorithms**
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
  - Quick Sort
  - Heap Sort

- **Searching Algorithms**
  - Linear Search
  - Binary Search

- **Graph Algorithms**
  - Depth-First Search (DFS)
  - Breadth-First Search (BFS)
  - Dijkstra’s Algorithm

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
