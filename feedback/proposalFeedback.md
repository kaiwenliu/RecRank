
### Grade
Incomplete (0%)

### Comments
Overall, the proposal is in great shape. The idea is novel and your leading question is interesting.

**Leading Questions**
The overall goal of the proposal needs clarification. You might want to elaborate on How your algorithm may solve the problem? Why this problem is important? And also give a brief description of your dataset. Also, it is not clear to me why do you want to specifically look at developers who did not follow each other.
 
**Data**
It seems like you are assuming a connected graph. Why do you make this assumption? Based on your leading question, it is possible that the graph will be disconnected and have several subgraphs (communities). Also just removing nodes that have no edges will not ensure a connected graph. It is ok to only consider a connected graph but you need to clarify what data processing procedure is necessary to create such a graph.


**Algorithm**
Djikstra's algorithm requires a weighted graph. How do you plan to assign the weight? 

The algorithm for Jaccard Index doesn’t satisfy the requirements for complex algorithms.


**Output**
In your output, what is the input? How many developers do you plan to output? 
