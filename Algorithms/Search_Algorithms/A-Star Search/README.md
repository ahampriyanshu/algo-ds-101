# A* Search Algorithm

# A* Search Algorithm
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/313b3cc464794282b6542df30efd804a)](https://app.codacy.com/app/yasserkabbout/aStarSearchAlgorithm?utm_source=github.com&utm_medium=referral&utm_content=yasserkabbout/aStarSearchAlgorithm&utm_campaign=Badge_Grade_Dashboard)

The  most  widely  known  form  of  best-first  search  is  called  A*  Search.

It  evaluates  nodes  by  combining  g(n),  the  cost  to  reach  the  node,  and  h(n),  the  cost  to  get  from  the  node  to  the  goal:

F(n)  =  g(n)  +  h(n)

Since  g(n)  gives  the  path  cost  from  the  start  node  to  node  n,  and  h(n)  is  the  estimated  cost  of  the  cheapest  path  from  n  to  the  goal,  we  have:

F(n)=  estimated  cost  of  the  cheapest  solution  through  n.

Thus,  if  we  are  trying  to  find  the  cheapest  solution,  a  reasonable  thing  to  try  first  is  the  node  with  the  lowest  of  f(n).

It  turns  out  that  this  strategy  is  more  reasonable:  provided  that  the  heuristic  function  h(n)  satisfies  certain  conditions,  A*  search  is  both  complete  and  optimal.  The  algorithm  is  identical  to  Uniform-cost-search  exceptthat  A*  uses  g(h)  and  h(n)  instead  of  g(h).

The  way  of  how  the  A*  Search  works  is  illustrated  in the figure below. Each  time,  the  node  having  the  lowest  f(n)  value  is  the  node  expanded.  The  targets  nodes  will  be  expanded  until  reaching  the  goal  destination,  which  is  Bucharest.

![A Star Search Photo](https://github.com/yasserkabbout/A-Star-Search-Algorithm/blob/master/astarsearch.PNG)
