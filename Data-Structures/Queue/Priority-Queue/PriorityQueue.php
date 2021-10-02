
<?php
  
  // Declare a class
  class priorityQueue extends SplPriorityQueue {
        
      // Compare function to compare priority
      // queue elements
      public function compare($p1, $p2) {
          if ($p1 === $p2) return 0;
          return $p1 < $p2 ? -1 : 1;
      }
  }
    
  // Create an object of priority queue
  $obj = new priorityQueue();
    
  // Insert elements into the queue
  $obj->insert("p2",2);
  $obj->insert("p1",1);
  $obj->insert("p3",3);
  $obj->insert('p4',4);
    
  // Display the priority queue elements
  // var_dump($obj);
  echo"Object  :";
  print_r($obj);
  
  // Display the extracted element
  // from priority queue
  echo"Show extracted element according to priority  :";
  var_dump($obj->extract());
  
  // Display the number of elements
  // in priority queue
  echo"Show the number of elements  :";
  var_dump($obj->count());
  
  // Use isCorrupted() function to check
  // priority queue is in corrupted state
  // or not
  echo"Show priority queue is in corrupted state or not  :";
  var_dump($obj->isCorrupted());
  
  // Use isEmpty() function to check
  // priority queue is empty or not
  echo"Show priority queue is empty or not  :";
  var_dump($obj->isEmpty());
  
  ?>