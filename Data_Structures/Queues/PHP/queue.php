
<?php 
//Author KevinMathewTh

//FIFO
class Node{
    
  public $value;
  public $next;

}

//Queue class that store Node in queue

class Queue{
    private $front = null;
    private $back = null; 

    //Check if empty
    public function isEmpty(){
    return $this->front == null;
    }

    //Enqueue function

public function enqueue($value){
    $oldBack = $this->back;
    $this->back = new Node(); 
    $this->back->value = $value;
    if($this->isEmpty()){
    $this->front = $this->back; 
    }else{
    $oldBack->next = $this->back;
    }
}

// Dequeue Function

public function dequeue(){
if($this->isEmpty()){
    return null; 
    }
    $removedValue = $this->front->value;
    $this->front = $this->front->next;
    return $removedValue;
}


// Show queue Function

public function show(){

    $current = $this->front;
    $print="";
    while($current != NULL)
    {
        $print .=$current->value.",";
        $current = $current->next;
    }
    echo $print;
    }
}


//Create a New Queue

$queue = new Queue();


//Inserting 1 , 2 , 3 , 4

$queue->enqueue(1);
$queue->enqueue(2);
$queue->enqueue(3);
$queue->enqueue(4);

$queue->show();

echo "<br>";

//DeQueue First Element

$queue->dequeue()."\n";

//Show 
$queue->show();

?>

