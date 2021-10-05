import java.util.PriorityQueue;
import java.util.Scanner;

class PriorityQueueDemo{

    //constant command strings
    private static final String COMMAND_ADD= "a";
    private static final String COMMAND_REMOVE = "r";
    private static final String COMMAND_FIRSTVALUE = "f";
    private static final String COMMAND_SHOWREMOVE = "sr";
    private static final String COMMAND_SIZE = "si";
    private static final String COMMAND_SHOW = "sh";
    private static final String COMMAND_QUIT= "q";

    public static void main(String[] args) {

        Scanner myScanner = new Scanner(System.in);
        //the elements keeping on PriorityQueue must be implements  Comparable interface.
        // In this case, Integer implements Comparable interface
        // PriorityQueue is automatically rearranged based on priority set by toCompare() overridden method
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<Integer>();


        System.out.println("Instructions: \"command_name _value\" , for example: a 44");
        System.out.println("\t1. Add value: \""+COMMAND_ADD+"\" . Example: \"a 11\" will add 11 at the priority queue");
        System.out.println("\t2. First/Peek value: \""+COMMAND_FIRSTVALUE+"\"");
        System.out.println("\t3. Remove First/Peek value: \""+COMMAND_REMOVE+"\"");
        System.out.println("\t4. Show and Remove First/Peek value: \""+COMMAND_SHOWREMOVE+"\"");
        System.out.println("\t5. Size of the Deque: \""+COMMAND_SIZE+"\"");
        System.out.println("\t6. See current Deque conditions: \""+COMMAND_SHOW+"\"");
        System.out.println("\t7. Exit program: \""+COMMAND_QUIT+"\"");

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
                    case COMMAND_ADD:
                        isDone = priorityQueue.offer(value);
                        if(isDone){
                            System.out.println(value + " is added");
                        }
                        else{
                            System.out.println(value + " couldn't add !");
                        }
                        break;
                    case COMMAND_REMOVE:
                        priorityQueue.remove();
                        System.out.println( "first value is removed from  priority queue.");
                        break;
                    case COMMAND_FIRSTVALUE:
                        System.out.println(priorityQueue.peek() + " is first value right now");
                        break;
                    case COMMAND_SHOWREMOVE:
                        System.out.println(priorityQueue.poll() + " is first value which is just removed from priority queue.");
                        break;

                    case COMMAND_SIZE:
                        System.out.println("PriorityQueue size is "+priorityQueue.size()+" right now");
                        break;
                    case COMMAND_SHOW:
                        System.out.println(priorityQueue);
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
