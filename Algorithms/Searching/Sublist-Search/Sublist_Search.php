<?php

class Node {
    public int $key;
    public ?Node $next;
}

/**
 * Create a new node
 * 
 * @param int $key node identifier
 */
function createNewNode (int $key) {
    $node = new Node();
    $node->key = $key;
    $node->next = null;
    return $node;
}

/**
 * Search sublist
 * 
 * @param Node $first First node
 * @param Node $second Second node
 * @return bool
 */
function subListSearch(Node $first, Node $second): bool
{
    $fNode = $first;
    $sNode = $second; 
  
    if ($first == null && $second == null) {
        return true;
    }
     
    if ($first == null || ($first != null && $second == null)) {
        return false; 
    }
    
    while ($second != null) {
        $sNode = $second; 

        while ($fNode != null) {

            if ($sNode == null) {
                return false;
            } elseif ($fNode->key == $sNode->key) { 
                $fNode = $fNode->next; 
                $sNode = $sNode->next; 
            } else {
                break;
            }
        } 

        if ($fNode == null) {
            return true;
        }

        $fNode = $first;
        $second = $second->next;
    } 
    return false; 
}

/**
 * Print a specific node
 * 
 * @param Node $node
 */
function printList(Node $node)
{
    while($node != null) {
        echo $node->key . ' ';
        $node = $node->next;
    }
    echo "\n";
}

/**
 * Test sublist search
 */
function testSubListSearch()
{
    $first = createNewNode(1); 
    $first->next = createNewNode(2);
    $first->next->next = createNewNode(3);
    $first->next->next->next = createNewNode(4); 
  
    $second = createNewNode(1); 
    $second->next = createNewNode(2); 
    $second->next->next = createNewNode(1); 
    $second->next->next->next = createNewNode(2); 
    $second->next->next->next->next = createNewNode(3); 
    $second->next->next->next->next->next = createNewNode(4);

    echo "First list:\n";
    printList($first);
    echo "Second list: \n";
    printList($second);
    echo "\n";
  
    if(subListSearch($first, $second)) {
        echo 'List Found'; 
    } else {
        echo 'List Not Found';
    }
    echo "\n";
}

// Test:
testSubListSearch();
// Result:
// First list:
// 1 2 3 4
// Second list:
// 1 2 1 2 3 4

// List Found