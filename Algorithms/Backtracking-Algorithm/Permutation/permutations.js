//Heap's Algorithm

//Print Function
function print(list,length){
  empty_list = []
  for(var i=0;i<length;i++){
    empty_list.push(list[i])
  }
  console.log(empty_list)
}

function permutation(list,size,length){
  // if size 1, print self
  if(size==1) print(list,length)

  for(var j=0;j<size;j++){

    //recursive function
    permutation(list,size-1,length)

    //if size is odd, swap first and last element
    if(size % 2 == 1){
      var temp = list[0]
      list[0] = list[size-1]
      list[size-1] = temp
    }

    //else swap ith and last element
    else{
      var temp = list[j]
      list[j] = list[size-1]
      list[size-1] = temp
    }
      
  }

}

//Test
var list = [4,5,6]
size = list.length
permutation(list,size,size)
