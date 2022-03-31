# Final Project Proposal

Richard, Sahith, Kevin

## Leading Question

Problem: Github don't know who have similar interests as them without going
through their network manually.

Our algorithm would find similar developers and suggest those as followers,
making it easier to network and find jobs. Since developers already know who
they are following, it would be pointless to find those. We want to find new
developers that are *similar* to a certain fixed developers and suggest those as
new followers.

Our dataset contains Github developers ids and graph of who follows whom.

## Dataset Acquisition and Processing

### Data format

This data is from the Stanford Large Network Dataset Collection. It was
collected from the public Github API in June 2019. It was downloaded in March
2022. The node edges are stored in a JSON file describing which Github
developers follow which developers (indexed by integer id). There is another CSV
file that associates each developer id with their username. The dataset has
289,000 edges. We plan to use all of the data.

### Data correction

We will read the CSV using a C++ library. We will get rid of any nodes that are
not connected to any edges. We will ensure that the graph of developers is
*connected* (**see next paragraph**). Check if the nodes are connected to
yourself, as you cannot follow yourself. Furthermore, we should also check if
the node ids in the graph are no more than the graph ids in the list they gave
us. In turn, we are checking if the values are valid and not negative values and
such.

To make the graph connected, we will split the graph into multiple connected
subgraphs. Ideally, there would only be 1 such subgraph. In case there are
multiple subgraphs (that are not connected to each other), we will pick the one
with the most nodes.

### Data Storage

We will store the developer relations as integer keys in a graph, stored as an
adjacency list. The storage costs of the graph will be O(n + m), where n is the
number of developers (nodes) and m is the total number of follower relations
(edges). We will store the developer usernames in an array, where the index
corresponds to the node id. The storage costs of the array is O(n), where n is
the number of developers (nodes).

## Graph Algorithms

### Traversal

We will do a BFS (breadth first search) traversal of the developers starting
from a single node to identify developers similar (but not connected) to them

### Algorithms

We will use two algorithms and one traversal.

Our algorithm will take as input one "target" developer. It will output (in
ranked order) multiple similar developers that will be suggested as new
followers.

The first algorithm we will use is PageRank. This will identify the more
"influential" developers (that is, those who have greater number of connections
to other influential developers). The output of this algorithm is used in the
second step.

The second algorithm is Dijkstra's. Using a BFS, we will look for developers
that are at least two edges away from the target developer. We will find the
shortest path using Dijkstra's, with the edge weighted based on the PageRank
weighting of the two nodes it is connecting. The BST will be limited to a
fixed predetermined depth.

From this process, we will get a list of developers, each with a "distance" to
the target developer. We can sort this list based on the Dijkstra's distance and
output that list. We will limit our output to a fix constant number of
developers.

## Timeline

- Week 1: (March 25 - April 3) - Gathering Data, project environment setup, and
  find libraries to use
- Week 2: (April 3 - April 10) - Implementing the Jaccard similarity score and
  incorporating data with them.
- Week 3: (April 11 - April 17) - **(mid project check in)** - Implementing the
  Djikstra's algorithm and incorporating data with them
- Week 4: (April 18 - April 24) - Implementing the BFS traversal 
- Week 5: (April 25 - May 1) - Linking these two together to produce our goal of
  finding which gives us the most similar users
- Week 6: (May 2 - May 6) - Wrapping things up
