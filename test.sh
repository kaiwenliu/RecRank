#!/bin/bash

# This is a shell script to run all tests sequentially.

TEST_PARSING="test-parsing"
TEST_PAGERANK="test-pagerank"

echo "Testing Parsing"
cd parsing/
./$TEST_PARSING
cd ..

echo "Testing PageRank"
cd pagerank/
./$TEST_PAGERANK
cd ..
