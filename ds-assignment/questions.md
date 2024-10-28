# Activity-V (Last Updated: 27/10/24)

- **Type:** Group Activity (4-5 members)
- **Implementation:** C / C++
- **Submission:** Any one member from the group
- **Submission Mode:** Google Classroom
- **Submission Deadline:** 17/11/24
- **Total Marks:** 05
- **Note:** Storage of input data in files/databases is optional.

---

## A-1

Create three databases using a header-linked list:

- **Student:** (Roll No, Name, Branch ID, CGPA)
- **University:** (University ID, University Name, University Location, Year of start)
- **Branch:** (Branch ID, University ID, Branch Name)

Implement the following modules/sub-modules using a menu-driven approach:

- Ensure that Roll No, University ID, and Branch ID are unique (duplicate entries should not be allowed, and the user will be prompted accordingly).
- A student can only take a University ID/Branch ID if it exists in the University/Branch database.
- Convert and store Student Name, University Name, and Branch Name in capital letters. (If the user does not enter accordingly, the program must convert it).
- Display the entire student list/University list/Branch list.
- Delete all students with a CGPA < 6.0 and store them in another list. They will return to the original student list if their CGPA >= 6.0 (Update function).
- Display the list of students attending **KIIT University**.
- **ADD/MODIFY/DELETE/UPDATE** entries in any database as needed.
- Display details of students attending **KIIT University** with the branch **CSE**.
- Display the list of branches available in any given University.
- Display University details in ascending order by their year of starting.
- Display all student names/University names containing a given substring entered by the user.

---

## A-2

Create a database using a header-linked list to store details of a **Shopping Card** issued by the shopping mall.

- **Shopping Card:** (Card_ID, Customer_Name, Points, Date_of_Birth, Last_date_of_transaction, Address)
- **Item:** (Item_ID, Item_Name, Price, Quantity)

Implement the following modules/sub-modules using a menu-driven approach:

- Ensure that **Card_ID** and **Item_ID** are unique (duplicate entries should not be allowed and the user will be prompted).
- Update function to allow address updates only (other fields cannot be updated by the customer).
- A customer can buy products from the list, with points assigned based on the item type:
  
  | Type of Item | Points for every ₹100 purchase |
  |--------------|--------------------------------|
  | Grocery      | 1                              |
  | Garments     | 5                              |
  | Electronics  | 10                             |

- When decided by the shopping mall manager (on a chosen date), a 10% discount can be offered to the first 10 customers who accumulate 1000 points. Customers may immediately redeem points for the discount, resetting points to zero, or retain points for later use. This process continues monthly.
- On a chosen date, a 15% discount is available for the first 5 customers who accumulate 1000 points and are **senior citizens (age > 60)**. Points may be redeemed immediately with a 10% discount, resetting points to zero, or retained for later use. This process repeats monthly.

Modules:

- Display customer and item details as needed.
- Add new customers and items.
- Delete customers if the last transaction date is over a year ago.
- Show items out of stock during purchase.

---

## A-3

At a vaccination center, people make a queue. Due to space constraints, parallel queues are formed after the first queue is full, up to three queues. Queue size will be user-defined.

Modules:

- Implement queue operations (insertion and deletion). When the first person enters the center, all people move one step forward.
- Handle scenarios when no one is in line for a vaccine and when no more people can be added due to lack of space.

---

## A-4

Write a program to implement **four double-ended queues (D-queues)** in an array.

---

## A-5

Implement round-robin scheduling using a linked list, where each node represents a process with attributes **<PID, CPU_time>**. A time quantum **T** is provided by the user. Each process runs for time **T**, updating **CPU_time** to **CPU_time - T**. The current process node is deleted from the beginning and added to the end of the list. If **CPU_time** ≤ 0, the process is deleted. Processes are executed based on user choice until all nodes are deleted.

---

## A-6

Write a program to construct a binary search tree (BST) from a given sequence of **preorder** and **inorder** traversal data.

---

## A-7

Write a program to check if the left subtree of a binary search tree is a mirror image of its right subtree.

---

## A-8

Implement a graph ADT using a linked list and traverse it using **breadth-first search (BFS)** and **depth-first search (DFS)** from a specified node.

---

## A-9

Assume ATM locations for different banks are represented by nodes in a graph with information **<ATM ID, BANK ID, CITY ID, LOCATION ID>**. Write pseudocode/algorithm to find the nearest ATM of a specific bank from a given location. Find subsequent neighboring ATMs as per user request.

---

## A-10

Write a program to convert a postfix expression to its equivalent prefix expression by constructing an expression tree.
