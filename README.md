# RecRank

RecRank is a Github followers recommendations engine written in C++. It uses
PageRank to identify "popular" github users that follow your followers, but you
do not follow. it will recommend these as new followers for you. This is a way
to find new popular users that you may want to follow.

## File hierarchy

Top level code files:
```
bfs.cpp, bfs.hpp           - BFS traversal
dijkstra.cpp, dijkstra.hpp - Dijkstra algorithm
pagerank.cpp, pagerank.hpp - PageRank algorithm
driver.cpp, driver.hpp     - Helper functions
main.cpp                   - Main code
csv.hpp                    - CSV reader library
```

Located in the tests folder:
```
tests/test.cpp - contains all of our tests
```

Located in the data folder:
```
data/edges.csv - The edges between the vertices
data/names.csv - The users that each vertex corresponds to
```

Presentation Video: [https://drive.google.com/file/d/1LYaO8Fjj2dN_c7YwxSKEr1KGQfkoAssr/view?usp=sharing](https://drive.google.com/file/d/1LYaO8Fjj2dN_c7YwxSKEr1KGQfkoAssr/view?usp=sharing)

## Installation Instructions

1. Clone this repository
2. Run `make` in the directory to build the relevant files. Clang with support
   for C++14 is required.
3. Run `./main <github username>` with any Github users who starred at least 10
   repos. See `data/names.csv` for full list of valid usernames.

## Sample program run

```
$ ./main gucong3000
Loaded 289003 edges
Analyzing connections...
Top 10 follower recommendations for gucong3000:
    dalinhuang99         (score: 1.97702) (31890)
    Bunlong              (score: 1.98578) (19222)
    plrthink             (score: 1.98607) (15940)
    kauegimenes          (score: 1.98609) (30002)
    gabrielpconceicao    (score: 1.98629) (13638)
    JonnyBanana          (score: 1.98635) (19253)
    XadillaX             (score: 1.98641) (5300)
    simongfxu            (score: 1.98659) (31659)
    mikalv               (score: 1.98659) (34426)
    nfultz               (score: 1.98664) (27803)
```

## Data sources

The dataset is sourced from the [SNAP Github Social Network
dataset](https://snap.stanford.edu/data/github-social.html).
