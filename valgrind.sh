#!/usr/bin/env bash
set -e
DEMO=$1
if [ -z "$DEMO" ]; then
  echo "Usage: ./valgrind.sh <demo-name>"
  exit 1
fi
case $DEMO in
  linked_list)
    BIN=bin/demo_linked_list
    make demo-linked_list
    ;;
  stack)
    BIN=bin/demo_stack
    make demo-stack
    ;;
  queue)
    BIN=bin/demo_queue
    make demo-queue
    ;;
  bst)
    BIN=bin/demo_bst
    make demo-bst
    ;;
  *)
    echo "Unknown demo: $DEMO"
    exit 2
    ;;
esac

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $BIN || true
