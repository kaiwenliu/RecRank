Week 1 Progress: 
  - We set the goals of gathering data, setting up the project environment, and finding the appropriate libaries to use. We have accomplished all of these goals. 
  - Richard accomplished the task of setting up the project environment and Sahith and Kevin both worked together and accomplished the tasks of gathering the data and finding the libaries we needed to use. 
  - We haven't encountered any problems that impeded us from reaching our goal so far
  - For next week, we plan to implement the PageRank algorithm and making the data work with it. 


Week 2 Progress: 
  - We achieved the goal of incorporating the data with the program and are in progress of incorporating the PageRank algorithm with it. 
  - Richard accomplished the task of incorporating the data with the project and Sahith and Kevin both planned and worked together on the PageRank algorithm.
  - We didn't have any problems reaching our goal, we just needed more time but we know what to do. 
  - For next week, we plan to finish implementing the PageRank algorithm and start on incorporating Djikstra's algorithm too.



Week 3 Progress: 
  - We achieved the goal of incorporating the Djikstra and PageRank algorithms. 
  - Richard and Sahith accomplished the task of implementing Djikstra's algorithm and Kevin implemented the PageRank algorithm.
  - We didn't have any problems reaching our goal.
  - For next week, we plan to implement the BFS traversal and test the project with it. 

Week 4 Progress:
  - We revised our implementation of Dijkstra's algorithm
    - We changed our implementation to use an adjacency list instead of an
      adjacency matrix for better space efficiency
    - We fixed the edge weight calculation to correctly average the weight of
      two adjaceny node PageRank weights

Week 5 Progress:
  - We implemented BFS
    - We added unit test for BFS
    - The BFS implementation finds nodes near the target that are not direct neighbors
    - It limits results to 100 nodes and sorts by the pagerank score
    - The BFS results will be recommended to users as potential connections
    - Sahith and Richard worked on this
  - We fixed pagerank
    - Kevin worked on this

Week 6 Progress:
  - Fixed pagerank algorithm
    - Switched to an adjacency list implementation with iterative feedforward to
      avoid memory usage issues with adjacency matrix
  - Add a command line interface that accepts a Github username as input
    - Has a help page which shows if the input is invalid
