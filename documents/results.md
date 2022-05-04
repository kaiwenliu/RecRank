The output and correctness of each algorithm – You should summarize, visualize, or highlight some part of the full-scale run of each algorithm. Additionally, the report should briefly describe what tests you performed to confirm that each algorithm was working as intended.

- For the PageRank algorithm,
- <img width="986" alt="Screen Shot 2022-05-03 at 8 27 59 PM" src="https://media.github-dev.cs.illinois.edu/user/14404/files/bf7d295f-708f-40b0-92f7-bdb7498695d7">, our output of the function matches the expected as shown in the picture.
- ![alt test](https://courses.cs.washington.edu/courses/cse373/17au/project3/diagrams/pagerank-simple-04.png).



Here's the second example.
- ![alt_text](https://courses.cs.washington.edu/courses/cse373/17au/project3/diagrams/pagerank-complex-04.png).



- For Djikstra's algorithm, we have created test cases to make sure it works correctly.
- Case 1:
```cpp

TEST_CASE("Dijkstra simple", "") {
    vector<double> weights = {0.1, 0.2, 0.3};
    vector<pair<size_t, size_t>> edges = {{0, 1}, {0, 2}};
    vector<vector<pair<size_t, double>>> adjacency_list = to_adjacency_list(edges, weights);
    Dijkstra dijkstra(adjacency_list, 0);
    vector<double> nodes = dijkstra.generate();
    REQUIRE(nodes[0] < nodes[2]);
    REQUIRE(nodes[2] < nodes[1]);
}
```

- Case 2: 

```cpp

TEST_CASE("Dijkstra medium", "") {
    vector<double> weights = {0.1, 0.2, 0.3, 0.4};
    vector<pair<size_t, size_t>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    vector<vector<pair<size_t, double>>> adjacency_list = to_adjacency_list(edges, weights);
    Dijkstra dijkstra(adjacency_list, 0);
    vector<double> nodes = dijkstra.generate();
    REQUIRE(nodes[0] < nodes[2]);
    REQUIRE(nodes[2] < nodes[1]);
    REQUIRE(nodes[1] < nodes[3]);
}

```

Case 1 Passing: 

<img width="795" alt="Screen Shot 2022-05-03 at 8 37 55 PM" src="https://media.github-dev.cs.illinois.edu/user/14404/files/452e04a3-bd9b-4058-93ea-3512b23edaf8">

Case 2 Passing: 

<img width="779" alt="Screen Shot 2022-05-03 at 8 38 28 PM" src="https://media.github-dev.cs.illinois.edu/user/14404/files/c4db5e38-d17c-40e6-8777-3bdcf84ba9af">

- For the BFS Algorithm:
- Case 1:

```cpp


TEST_CASE("BFS works tiny", "") {
    vector<vector<pair<size_t, double>>> adjacency_list = {
        {{1, 1234}, {2, 5678}},
        {{2, 3456}, {0, 1234}, {3, 5678}},
        {{0, 5678}, {1, 1234}, {4, 1234}},
        {{1, 1234}},
        {{2, 5678}},
    };
    vector<double> weights = {0, 10, 20, 30, 40};
    BFS bfs(adjacency_list, weights, 0, 100);
    vector<pair<double, size_t>> best = bfs.generate();
    REQUIRE(best[0].first == 30);
    REQUIRE(best[0].second == 3);
    REQUIRE(best[1].first == 40);
    REQUIRE(best[1].second == 4);
    REQUIRE(best.size() == 2);
}

```

Case 1 Passing:
<img width="857" alt="Screen Shot 2022-05-03 at 8 41 23 PM" src="https://media.github-dev.cs.illinois.edu/user/14404/files/ddf5d7b1-08b8-43c7-af57-373774d8d494">



The answer to your leading question – You should direct address your proposed leading question. How did you answer this question? What did you discover? If your project was ultimately unsuccessful, give a brief reflection about what worked and what you would do differently as a team.


- We answered 
