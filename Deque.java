import java.util.*;

class DequeDemo{

    //constant command strings
    private static final String COMMAND_ADDLAST = "al";
    private static final String COMMAND_REMOVELAST = "rl";
    private static final String COMMAND_ADDFIRST = "af";
    private static final String COMMAND_REMOVEFIRST = "rf";
    private static final String COMMAND_FIRSTVALUE = "f";
    private static final String COMMAND_SHOWREMOVEFIRST = "srf";
    private static final String COMMAND_SHOWREMOVELAST = "srl";
    private static final String COMMAND_LASTVALUE = "l";
    private static final String COMMAND_SIZE = "si";
    private static final String COMMAND_SHOW = "sh";
    private static final String COMMAND_QUIT= "q";

    public static void main(String[] args) {

        Scanner myScanner = new Scanner(System.in);

        // Deque is an interface. there are two deque implementations :
        Deque<Integer> arrayDeque = new ArrayDeque<Integer>(); // 1. using ArrayDeque instance
        Deque<Integer> linkedListDeque = new ArrayDeque<Integer>(); //2. using LinkedList instance

        //Deque is a double ended queue. It's possible to add or remove element from both head and tail
        System.out.println("Instructions: \"command_name _value\" , for example: al 44");
        System.out.println("\t1. Add value at the end command: \""+COMMAND_ADDLAST+"\" . Example: \"al 11\" will add 11 at the end");
        System.out.println("\t2. Remove value from the end command: \""+COMMAND_REMOVELAST+"\" ");
        System.out.println("\t3. Add value at the beginning command: \""+COMMAND_ADDFIRST+"\"");
        System.out.println("\t4. Remove value from the beginning command: \""+COMMAND_REMOVEFIRST+"\"");
        System.out.println("\t5. First value: \""+COMMAND_FIRSTVALUE+"\"");
        System.out.println("\t6. Last value: \""+COMMAND_LASTVALUE+"\"");
        System.out.println("\t7. Show and Remove First value: \""+COMMAND_SHOWREMOVEFIRST+"\"");
        System.out.println("\t8. Show and Remove Last value: \""+COMMAND_SHOWREMOVELAST+"\"");
        System.out.println("\t9. Size of the Deque: \""+COMMAND_SIZE+"\"");
        System.out.println("\t10. See current Deque conditions: \""+COMMAND_SHOW+"\"");
        System.out.println("\t11. Exit program: \""+COMMAND_QUIT+"\"");

        while (true) {

            // dividing the command string and number value
            String[] tempCommand = myScanner.nextLine().split(" ");

            try{
                String commandName = String.valueOf(tempCommand[0]);
                int value = 0;

                //if only command without value, then we need not try parsing value
                if(tempCommand.length > 1){
                    value = Integer.parseInt(tempCommand[1]);
                }

                //checking command name and performing accordingly
                boolean isDone = false;
                switch (commandName){
                    case COMMAND_ADDLAST:
                        isDone = arrayDeque.offerLast(value);
                        if(isDone){
                            System.out.println(value + " is added to last");
                        }
                        break;
                    case COMMAND_ADDFIRST:
                        isDone = arrayDeque.offerFirst(value);
                        if(isDone){
                            System.out.println(value + " is added to the first");
                        }
                        break;
                    case COMMAND_REMOVEFIRST:
                        System.out.println(arrayDeque.removeFirst() + " is removed from first");
                        break;
                    case COMMAND_FIRSTVALUE:
                        System.out.println(arrayDeque.getFirst() + " is first value right now");
                        break;
                    case COMMAND_SHOWREMOVEFIRST:
                        System.out.println(arrayDeque.pollFirst() + " is first value which is just removed from deque.");
                        break;
                    case  COMMAND_SHOWREMOVELAST :
                        System.out.println(arrayDeque.pollLast() + " is last value which is just removed from deque.");
                        break;
                    case COMMAND_LASTVALUE:
                        System.out.println(arrayDeque.getLast() + " is last value right now");
                        break;
                    case COMMAND_SIZE:
                        System.out.println("Deque size is "+arrayDeque.size()+" right now");
                        break;
                    case COMMAND_SHOW:
                        System.out.println(arrayDeque);
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