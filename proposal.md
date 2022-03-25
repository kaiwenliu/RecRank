# Final Project Proposal

Richard, Sahith, Kevin

## Leading Question

Which Github developers have similar interests? That is, which developers share
similar followers but are not following each other?

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
*connected*. Check if the nodes are connected to yourself, as you cannot follow
yourself. Furthermore, we should also check if the node ids in the graph are no
more than the graph ids in the list they gave us. In turn, we are checking if
the values are valid and not negative values and such. 

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

There are two algorithms. The first is the node similarity algorithm, which
finds similar nodes based on shared edges. This is also known as the Jaccard
Index (or Jaccard similarity score). The algorithm will take in a graph and a
node to start at. To compute the Jaccard Index between two nodes, we count the
number of nodes that they share and the number of nodes they differ. This
algorithm is done in O(n + m), where n is the number of edges of the first node
and m is the number of edges of the second node.  The algorithm will output
multiple nodes in the order that they share a significant degree of similarity.

We will also use Djikstra's algorithm to find the shortest path between users of
related interests. The algorithm is done in O( E log V), where V is the number
of vertices and E is the total number of edges. We are doing Dijkstra's on all
the nodes. Therefore the total time complexity will be O(V * E * log V). The
algorithm will output multiple nodes, sorted in the order that are closest to
the target node (but not directly connected to it).

We want to find developers that share overlap according to both of these
algorithms. This way, we can be sure that they do indeed have a high degree of
similarity. We will print a list of users that are similar to someone in
formatted text.

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
