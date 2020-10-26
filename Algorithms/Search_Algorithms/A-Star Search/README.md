# A* Search Algorithm

The  most  widely  known  form  of  best-first  search  is  called  A*  Search.

## few terminologies:
  - Node (also called State) — All potential position or stops with a unique identification
  - Transition — The act of moving between states or nodes.
  - Starting Node — Whereto start searching
  - Goal Node — The target to stop searching.
  - Search Space — A collection of nodes, like all board positions of a board game
  - Cost — Numerical value (say distance, time, or financial expense) for the path from a node to another node.
  - g(n) — this represents the exact cost of the path from the starting node to any node n
  - h(n) — this represents the heuristic estimated cost from node n to the goal node.
  - f(n) — lowest cost in the neighboring node n

Each time A* enters a node, it calculates the cost, f(n)(n being the neighboring node), to travel to all of the neighboring nodes, and then enters the node with the lowest value of f(n).

It  evaluates  nodes  by  combining  g(n),  the  cost  to  reach  the  node,  and  h(n),  the  cost  to  get  from  the  node  to  the  goal:

F(n)  =  g(n)  +  h(n)

Since  g(n)  gives  the  path  cost  from  the  start  node  to  node  n,  and  h(n)  is  the  estimated  cost  of  the  cheapest  path  from  n  to  the  goal,  we  have:

F(n)=  estimated  cost  of  the  cheapest  solution  through  n.

Thus,  if  we  are  trying  to  find  the  cheapest  solution,  a  reasonable  thing  to  try  first  is  the  node  with  the  lowest  of  f(n).

It  turns  out  that  this  strategy  is  more  reasonable:  provided  that  the  heuristic  function  h(n)  satisfies  certain  conditions,  A*  search  is  both  complete  and  optimal.  The  algorithm  is  identical  to  Uniform-cost-search  exceptthat  A*  uses  g(h)  and  h(n)  instead  of  g(h).

The  way  of  how  the  A*  Search  works  is  illustrated  in the figure below. Each  time,  the  node  having  the  lowest  f(n)  value  is  the  node  expanded.  The  targets  nodes  will  be  expanded  until  reaching  the  goal  destination,  which  is  Bucharest.

![A Star Search Photo](https://github.com/yasserkabbout/A-Star-Search-Algorithm/blob/master/astarsearch.PNG)
