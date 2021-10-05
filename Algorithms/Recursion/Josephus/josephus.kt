fun main(args: Array<String>){
    //Taking n, k as input values
    val (n, k) = readLine()!!.split(' ').map{it.toInt()}
    
    //array to store status dead/alive of a person
    //initially all persons are alive so we set the staus to false, meaning all are       //not dead
    val is_dead = BooleanArray(n) 

    var index = 0 //index of a person in the circle

    var died_count = 0 //count of died people so far
    
    while(true){

        //if only one person is alive, indeed that's our answer so break
        if(died_count == n-1)
            break

        //next we move until we reach the kth alive person from the current index
        var count = k-1//to keep track of alive people

        while(count > 0){
            index = (index + 1)%n // to move around the circle so that after the last index we move to the first index
            if(!is_dead[index])count--
        }

        //kth person would die
        is_dead[index] = true

        //count of person died so far would be incremented
        died_count++

        //now start from the next alive person
        while(is_dead[index])index = (index + 1)%n
    }
    
    //after the loop the only person alive is at the position of the 'index'.
    println(index + 1)//index + 1 to make it 1 based indexing
}