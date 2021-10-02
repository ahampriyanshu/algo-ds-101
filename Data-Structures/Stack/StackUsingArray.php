
<?php 
class Stack
{
    protected $stack;
    protected $size;
    public function __construct($size = 50) {
        //declare stack
        $this->stack = array();
        //declare stack size
        $this->size  = $size;
    }
    public function push($data) {//push element into stack
        if(count($this->stack) < $this->size) {//check if stack is overflow       
            // array_unshift() prepends passed elements to the front of the array.
            array_unshift($this->stack, $data);//insert an element at the beginning      
        } else {
            throw new RuntimeException("Stack overflow");//show error is stack overflow
        }
    }
    

    public function pop() {//pop element from stack
        if (empty($this->stack)) {//check if stack is empty          
            throw new RuntimeException("Stack underflow");//throw error if empty
        } else {
            // array_shift() shifts the first value of the array off and returns it
            return array_shift($this->stack);//pop element
        }
    }
    
   
}
 
$stack = new Stack();//create obbject of class
 
$stack->push(4);//add 4 to stack
$stack->push(5);//add 5 to stack 
 
echo $stack->pop();  // Pop 5 and echo the element popped
 
$stack->push(7);//add 7 to stack
$stack->push(9);//add 9 to stack
$stack->push(8);//add 8 to stack
 
echo $stack->pop();  // Pop 8 and echo the element popped
echo $stack->pop();  // Pop 9 and echo the element poppedv
?>