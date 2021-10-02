import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

class HashSetDemo {
     //constant command strings
     private static final String COMMAND_ADD= "a";
     private static final String COMMAND_REMOVE = "r";

     private static final String COMMAND_IS_VALUE_EXISTS = "?v";

     private static final String COMMAND_ALL_VALUE = "av";

     private static final String COMMAND_ITERATE_ALL_VALUE = "i";

     private static final String COMMAND_CLEAR = "c";

     private static final String COMMAND_SIZE = "si";
     private static final String COMMAND_SHOW = "sh";
     private static final String COMMAND_QUIT= "q";

     public static void main(String[] args) {

      Scanner myScanner = new Scanner(System.in);

      // HashSet ensure there is no duplicate value in it
      HashSet<Integer> hashSet = new HashSet<>();


      System.out.println("Instructions:");
      System.out.println("\t1. Add value: \""+COMMAND_ADD+" value\" . Example: \"a 44\" here, 44 is added");
      System.out.println("\t2. Remove value: \""+COMMAND_REMOVE+" value_here\"");
      System.out.println("\t3. check if value exists : \""+COMMAND_IS_VALUE_EXISTS+" value_here\"");
      System.out.println("\t4. See ALl Values : \""+COMMAND_ALL_VALUE+"\"");
      System.out.println("\t5. Iterate through all values : \""+COMMAND_ITERATE_ALL_VALUE+"\"");
      System.out.println("\t6. Clear HashSet : \""+COMMAND_CLEAR+"\"");
      System.out.println("\t7. See current HashSet conditions: \""+COMMAND_SHOW+"\"");
      System.out.println("\t8. Size of the HashSet: \""+COMMAND_SIZE+"\"");
      System.out.println("\t9. Exit program: \""+COMMAND_QUIT+"\"");


      while (true) {

         // dividing the command string and number value
         String[] tempCommand = myScanner.nextLine().split(" ");

         try{
          String commandName = String.valueOf(tempCommand[0]);
          int value = 0;

          if(tempCommand.length == 2){
              value = Integer.parseInt(tempCommand[1]);
          }

          //checking command name and performing accordingly
          switch (commandName){
               case COMMAND_ADD:
                    if(hashSet.add(value)){
                        System.out.println(value+ " is added to the hashset");

                    }
                    else{
                        System.out.println(value+ " is already on the hashset");
                    }
                    break;

               case COMMAND_REMOVE:
                   if(hashSet.remove(value)){
                       System.out.println(value+ " is removed from hashset");

                   }
                   else{
                       System.out.println(value+ " remove failed");
                   }
                   break;


               case COMMAND_IS_VALUE_EXISTS:
                    if(hashSet.contains(value)){
                        System.out.println(value + " value exists in the hashset");
                    }
                    else{
                        System.out.println(value + " value doesn't exist in the hashset");
                    }
                    break;

               case COMMAND_ALL_VALUE:
                    System.out.println("All Values: "+hashSet);
                    break;

              case COMMAND_ITERATE_ALL_VALUE:
                  Iterator<Integer> i = hashSet.iterator();
                  int c = 1;
                  while (i.hasNext()){
                      System.out.println("Serial "+ c + " is : " +i.next());
                      c++;
                  }
                  System.out.println("----------------");
                  break;

               case COMMAND_SIZE:
                    System.out.println("HashSet size is "+hashSet.size()+" right now");
                    break;

               case COMMAND_SHOW:
                    System.out.println(hashSet);
                    break;

               case COMMAND_QUIT:
                    return;

               default:
                    System.out.println("Invalid command format");
                    break;
              }
         }
         catch (NumberFormatException e){
          System.out.println("Invalid command format");
         }
         catch (Exception e){
          System.out.println("Exception: "+ e.getMessage());
         }
         }
     }
}
