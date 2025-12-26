# DSA-C-Implementations (Advanced)

Collection of essential data structures and algorithms implemented in C with a focus on:
- Efficient memory management
- Pointer manipulation safety
- Unit testing and valgrind checks
- Simple benchmarking hooks

## What's included
- Singly Linked List
- Stack (array + linked-list)
- Queue (circular + linked-list)
- Binary Search Tree (BST)
- Demo programs (demos/)
- Unit tests (tests/) using CUnit or a simple test harness
- `valgrind.sh` script to run valgrind checks

## Build
Requires: `gcc`, `make`, `valgrind` (optional), `cmake` + `CUnit` (optional for tests)

```bash
# build everything
make

# build and run demos
make demo-linked_list
./bin/demo_linked_list

# run tests (if CUnit installed)
make test

# run valgrind on a demo
make valgrind DEMO=linked_list
```

## How to push to GitHub
```bash
git init
git add .
git commit -m "Initial commit: advanced DSA implementations in C"
git remote add origin https://github.com/<your-username>/dsa-c-implementations.git
git branch -M main
git push -u origin main
```

## Contributing
PRs welcome. Please run `make test` and `valgrind.sh demo=<module>` before opening a PR.
