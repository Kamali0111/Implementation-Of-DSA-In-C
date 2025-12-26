#!/usr/bin/env bash
# Simple smoke tests (without requiring CUnit). Expand to real unit tests as needed.
set -e

echo "Building demos for smoke tests..."
make demo-linked_list demo-stack demo-queue demo-bst >/dev/null

for f in bin/demo_linked_list bin/demo_stack bin/demo_queue bin/demo_bst; do
  echo "Running $f"
  $f || { echo "$f failed"; exit 2; }
done

echo "All smoke tests passed."
