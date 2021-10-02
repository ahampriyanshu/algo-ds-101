import java.util.HashMap;
import java.util.Scanner;

class HashMapDemo {
    //constant command strings
    private static final String COMMAND_ADD= "a";
    private static final String COMMAND_REMOVE = "r";
    private static final String COMMAND_VALUE = "v";
    private static final String COMMAND_IS_KEY_EXISTS = "?k";
    private static final String COMMAND_IS_VALUE_EXISTS = "?v";
    private static final String COMMAND_ALL_KEY = "ak";
    private static final String COMMAND_ALL_VALUE = "av";
    private static final String COMMAND_SIZE = "si";
    private static final String COMMAND_SHOW = "sh";
    private static final String COMMAND_QUIT= "q";

    public static void main(String[] args) {

        Scanner myScanner = new Scanner(System.in);

        // HashMap is a key-value pair data structure. Here, Key ( String ) - value (String ) type
        HashMap<String, String > hashMap = new HashMap<>();


        System.out.println("Instructions:");
        System.out.println("\t1. Add value: \""+COMMAND_ADD+" key value\" . Example: \"a name Rezwan\" here, key = 'name' , value = 'Rezwan' ");
        System.out.println("\t2. Show value: \""+COMMAND_VALUE+" key_name_here\"");
        System.out.println("\t3. Remove value: \""+COMMAND_REMOVE+" key_name_here\"");

        System.out.println("\t4. check if key exists : \""+COMMAND_IS_KEY_EXISTS+" key_name_here\"");
        System.out.println("\t5. check if value exists : \""+COMMAND_IS_VALUE_EXISTS+" value_name_here\"");

        System.out.println("\t7. See ALl Keys : \""+COMMAND_ALL_KEY+"\"");
        System.out.println("\t8. See ALl Values : \""+COMMAND_ALL_VALUE+"\"");

        System.out.println("\t9. See current HashMap conditions: \""+COMMAND_SHOW+"\"");
        System.out.println("\t10. Size of the HashMap: \""+COMMAND_SIZE+"\"");
        System.out.println("\t11. Exit program: \""+COMMAND_QUIT+"\"");

        while (true) {

            // dividing the command string and number value
            String[] tempCommand = myScanner.nextLine().split(" ");

            try{
                String commandName = String.valueOf(tempCommand[0]);
                String str1 = "", str2 = "";

                if(tempCommand.length == 2){
                    str1 = String.valueOf(tempCommand[1]);
                }
                else if(tempCommand.length == 3){
                    str1 = String.valueOf(tempCommand[1]);
                    str2 = String.valueOf(tempCommand[2]);
                }

                //checking command name and performing accordingly

                switch (commandName){
                    case COMMAND_ADD:
                        hashMap.put(str1, str2);
                        System.out.println(str1+ "-" +str2 + " added");
                        break;

                    case COMMAND_VALUE:
                        System.out.println( hashMap.get(str1) + " is the value of KEY = "+ str1);
                        break;

                    case COMMAND_REMOVE:
                        hashMap.remove(str1);
                        System.out.println( "Pair of " +str1 + " KEY is removed");
                        break;

                    case COMMAND_IS_KEY_EXISTS:
                        if(hashMap.containsKey(str1)){
                            System.out.println(str1 + " key exists in the hashmap");
                        }
                        else{
                            System.out.println(str1 + " key doesn't exist in the hashmap");
                        }
                        break;

                    case COMMAND_IS_VALUE_EXISTS:

                        if(hashMap.containsValue(str1)){
                            System.out.println(str1 + " value exists in the hashmap");
                        }
                        else{
                            System.out.println(str1 + " value doesn't exist in the hashmap");
                        }
                        break;

                    case COMMAND_ALL_KEY:
                        System.out.println("All Keys: "+hashMap.keySet());
                        break;

                    case COMMAND_ALL_VALUE:
                        System.out.println("All Values: "+hashMap.values());
                        break;

                    case COMMAND_SIZE:
                        System.out.println("HashMap size is "+hashMap.size()+" right now");
                        break;

                    case COMMAND_SHOW:
                        System.out.println(hashMap);
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
