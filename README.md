# 🌐 Browser History Management System using Doubly Linked List (C++)

<p align="center">
  **A Console-Based Browser History Simulation**
  <br>
  Manage webpages, navigate between visited pages, and perform insertion, deletion, and searching operations using a Doubly Linked List.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?logo=cplusplus" alt="C++">
  <img src="https://img.shields.io/badge/Data%20Structure-Doubly%20Linked%20List-orange" alt="Doubly Linked List">
  <img src="https://img.shields.io/badge/Project-Individual-purple" alt="Individual Project">
  <img src="https://img.shields.io/badge/Interface-Console-lightgrey" alt="Console">
</p>

---

## 📌 About the Project

**Browser History Management System** is a menu-driven console application developed using C++. It simulates the basic functionality of a web browser's history management system using a **Doubly Linked List**.

Each webpage is represented by a node containing its Page ID, URL, and Title. Every node maintains two pointers: one pointing to the previous webpage and another pointing to the next webpage.

The system allows users to manage browsing history through insertion, deletion, searching, and navigation operations. It also supports moving between webpages in both forward and backward directions.

This project demonstrates the practical application of linked lists, pointers, dynamic memory allocation, and data structure operations.

---

## ✨ Features

### 📄 Webpage Management
- Add a webpage at the beginning of the history.
- Add a webpage at the end of the history.
- Insert a webpage after a specific Page ID.
- Prevent duplicate Page IDs.

### 🔍 Search & Display
- Search for a webpage using its Page ID.
- Display browser history in forward order.
- Display browser history in backward order.
- Display the currently selected webpage.
- Count the total number of webpages.

### 🧭 Browser Navigation
- Navigate to the previous webpage.
- Navigate to the next webpage.
- Maintain the current webpage using a pointer.

### 🗑️ Deletion Operations
- Delete a webpage from the beginning.
- Delete a webpage from the end.
- Delete a webpage using its Page ID.
- Release dynamically allocated memory before exiting.

---

## 🧠 Concepts Used

| Concept | Application |
|---|---|
| Doubly Linked List | Stores and connects webpage records. |
| Structures | Represents webpage details. |
| Pointers | Maintains links between nodes. |
| Dynamic Memory Allocation | Creates nodes dynamically using `new`. |
| Insertion Operations | Adds webpages at different positions. |
| Deletion Operations | Removes webpages and updates links. |
| Forward Traversal | Displays history from first to last. |
| Backward Traversal | Displays history from last to first. |
| Searching | Locates webpages using Page ID. |
| Menu-Driven Programming | Allows users to select operations. |

---

## 🔗 Doubly Linked List Structure

Each webpage is represented by a node containing:

- `left` – Pointer to the previous webpage.
- `right` – Pointer to the next webpage.
- `id` – Unique Page ID.
- `url` – Webpage URL.
- `title` – Webpage title.

### Node Representation

```text
+----------+------+----------+----------+
|   LEFT   |  ID  |   URL    |  TITLE   |
+----------+------+----------+----------+
     |                 |
     v                 v
 Previous            Next
 Webpage            Webpage
```

### Example Linked List

```text
NULL
  |
  v
+------+       +------+       +------+
|  101 | <-->  |  102 | <-->  |  103 |
+------+       +------+       +------+
                                   |
                                   v
                                  NULL

  Page 1         Page 2         Page 3
```

The two-way connections allow the browser to navigate between webpages in both directions.

---

## ⚙️ How It Works

1. The program starts with an empty browser history.
2. The user selects an operation from the menu.
3. When a webpage is added, memory is allocated dynamically for a new node.
4. The node is connected to the existing list by updating the previous and next pointers.
5. Deletion operations remove the selected node and reconnect the remaining nodes.
6. Search operations locate webpages using their unique Page IDs.
7. Navigation operations update the current webpage pointer.
8. Before exiting, all dynamically allocated nodes are released.

---

## ⏱️ Time Complexity

Let `n` represent the total number of webpages.

| Operation | Time Complexity |
|---|---|
| Insert at Beginning | O(1) |
| Insert at End | O(1)* |
| Insert After Page ID | O(n) |
| Delete from Beginning | O(1) |
| Delete from End | O(1)* |
| Delete by Page ID | O(n) |
| Search by Page ID | O(n) |
| Forward Traversal | O(n) |
| Backward Traversal | O(n) |
| Previous / Next Navigation | O(1) |
| Count Webpages | O(n) |

*Insertion and deletion at the end are O(1) when a tail pointer is maintained.*

---

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Main programming language |
| GCC / G++ | Compiler |
| Doubly Linked List | Dynamic webpage management |
| Structures | Stores webpage information |
| Pointers | Maintains node connections |
| Dynamic Memory Allocation | Allocates and releases memory |

---

## 📂 Project Structure

```text
Browser-History-Management-Using-Doubly-Linked-List/
│
├── BrowserHistory.cpp
└── README.md
```

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/srxxr4man/Browser-History-Management-Using-Doubly-Linked-List.git
```

### 2. Navigate to the Project Directory

```bash
cd Browser-History-Management-Using-Doubly-Linked-List
```

### 3. Compile the Program

```bash
g++ BrowserHistory.cpp -o BrowserHistory
```

### 4. Run the Program

**Linux / macOS:**

```bash
./BrowserHistory
```

**Windows:**

```bash
BrowserHistory.exe
```

---

## 🎯 Learning Outcomes

Through this project, I gained practical experience in:

- Understanding the structure and working of Doubly Linked Lists.
- Implementing insertion and deletion operations.
- Learning pointer manipulation and dynamic memory allocation.
- Performing forward and backward traversal.
- Managing node connections during deletion.
- Implementing searching and navigation operations.
- Applying data structures to a real-world-inspired application.

---

## 🔮 Future Enhancements

- Add browser history search using webpage titles.
- Implement a recently visited webpages feature.
- Add visit timestamps for each webpage.
- Introduce bookmark management.
- Implement history clearing functionality.
- Add a graphical user interface.
- Support persistent history storage using file handling.

---

## 🎓 Academic Details

- **Institution:** Muthoot Institute of Technology and Science (MITS)
- **Department:** Artificial Intelligence and Data Science
- **Academic Batch:** 2025–2029
- **Semester:** 3
- **Project Type:** Individual Project
- **Subject Area:** Data Structures and Algorithms

---

## 👨‍💻 Author

**A Sreeram**

Artificial Intelligence and Data Science Student  
Muthoot Institute of Technology and Science (MITS)

---

## ⭐ Acknowledgement

This project was developed as part of learning and practicing Data Structures and Algorithms using C++. It helped strengthen the understanding of Doubly Linked Lists and their practical applications.

---

<p align="center">
  **Browse. Navigate. Manage.** 🌐
  <br>
  <i>Understanding Data Structures Through Practical Implementation.</i>
</p>
