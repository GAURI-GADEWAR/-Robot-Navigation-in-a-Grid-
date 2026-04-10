# Grid Pathfinding using DFS and BFS (C)

## About

This is a simple C program where I have implemented DFS (Depth First Search) and BFS (Breadth First Search) on a 2D grid.

The grid contains:

* 0 → free cell
* 1 → blocked cell

The program finds a path from a start point to a target point and prints traversal and path.

---

## What this program does

* Takes grid input from user
* Takes start and target coordinates
* Runs DFS and BFS
* Prints traversal of both
* Prints path if found

---

## Algorithms used

### DFS (Depth First Search)

* Explores one path deeply first
* Uses recursion
* Does not guarantee shortest path

### BFS (Breadth First Search)

* Explores level by level
* Uses queue
* Always gives shortest path in this grid

---

## How to run

1. Compile:

```
gcc code.c -o output
```

2. Run:

```
./output
```

---

## Input format

* Enter rows and columns
* Enter grid (0 and 1 values)
* Enter start coordinates
* Enter target coordinates

---

## Output

* DFS traversal
* DFS path (if exists)
* BFS traversal
* BFS path (shortest path)

---

## Concepts used

* Arrays
* Recursion
* Queue
* Graph traversal

---

## Conclusion

This program shows how DFS and BFS can be used for pathfinding in a grid and how BFS helps in finding the shortest path.

---