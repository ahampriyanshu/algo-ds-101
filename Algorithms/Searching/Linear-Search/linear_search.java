class Search  
{  
public static int Linear (int array[], int num) 
{ 
    int length = array.length; //to calculate array length
    for(int i = 0; i < length; i++) 
    { 
       if(array[i] == num)
       return i; 
    } 
    return -1; 
}  
public static void main(String args[]) 
{ 
    int array[] = { 5, 13, 29, 38, 44, 59, 63, 69, 84, 90, 208 };  
    int num = 69;     
    int index = search(array, num); //looking for the selection in array
    if(result == -1) 
    System.out.print("Could not find the selection in the array."); 
    else
    System.out.print("Selection found at index: " + index); 
} 
} 
