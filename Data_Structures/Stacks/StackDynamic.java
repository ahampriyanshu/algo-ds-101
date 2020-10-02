/**
 * Compile and execute: java -classpath StackDynamic.jar StackDynamic.java
 * Stack implementation in language C <https://github.com/jytaloramon/data-structure/tree/master/stack> 
 *
 * @author  Ytalo Ramon
*/

package Stack;

public class StackDynamic {
    public static void main(String[] args) {

        String value, inputs_operations[][] = { { "1", "Orange" }, { "1", "Apple" }, { "4", "Orange" }, { "0", "" },
                { "1", "Pineapple" }, { "2", "" }, { "0", "" }, { "0", "" }, { "0", "" }, { "1", "Avocado" },
                { "1", "Strawberry" }, { "2", "" }, { "1", "Guava" }, { "1", "Star Fruit" }, { "2", "" },
                { "1", "Banana" }, { "4", "Banana" }, { "2", "" }, { "1", "Acerola" }, { "4", "Guava" } };

        Stack stack = new Stack();

        System.out.println("---------- Dynamic Stack ----------\n");

        for (String[] input_op : inputs_operations) {
            try {
                switch (input_op[0]) {
                    case "0":
                        System.out.print("POP: " + input_op[1]);
                        value = stack.pop();
                        System.out.println(value);
                        break;

                    case "1":
                        System.out.print("PUSH: " + input_op[1]);
                        stack.push(input_op[1]);
                        System.out.println(" => OK!");
                        break;

                    case "2":
                        System.out.print("PEEK: " + input_op[1]);
                        value = stack.peek();
                        System.out.println(value);
                        break;

                    default:
                        System.out.print("SEARCH: " + input_op[1]);
                        int rs = stack.search(input_op[1]);
                        System.out.println(rs != -1 ? " - OFFSET (" + rs + ")" : "Not Found!");

                }
            } catch (Exception e) {
                System.out.println();
                System.out.println(e.getMessage());
            }

            System.out.println();
            System.out.println(stack);
            System.out.println("\n");
        }

    }
}

/**
 * Item
 */
class Item {

    private final String value; // content value.
    private Item next; // Ref. to prox. item.

    /**
     * Constructor of class.
     * 
     * @param value content.
     * @param next  prox. item.
     */
    public Item(String value, Item next) {
        this.value = value;
        this.next = next;
    }

    public String getValue() {
        return value;
    }

    public Item getNext() {
        return next;
    }

    public void setNext(Item next) {
        this.next = next;
    }

    @Override
    public String toString() {
        return this.value;
    }
}

/**
 * Stack
 */
class Stack {

    private Item top; // Array of item.

    /**
     * Constructor of class.
     */
    public Stack() {
        this.top = null;
    }

    /**
     * Check if the stack is empty.
     * 
     * @return or true if empty or false if not empty.
     */
    public boolean isEmpty() {
        return this.top == null;
    }

    /**
     * Push a new item onto the stack.
     * 
     * @param value insertion value.
     */
    public void push(String value) throws Exception {
        this.top = new Item(value, this.top);
    }

    /**
     * Remove the item at the top of the stack.
     * 
     * @return the removed value.
     * @throws Exception if it is not possible to remove - stack empty.
     */
    public String pop() throws Exception {
        if (this.isEmpty())
            throw new Exception("Empty Stack, impossible remove item!");

        String value = this.top.getValue();
        this.top = this.top.getNext();
        return value;
    }

    /**
     * Removes all items from the Stack.
     */
    public void clear() {
        Item item = this.top, proxItem;
        while (item != null) {
            proxItem = item.getNext();
            item.setNext(null);
            item = proxItem;
        }
    }

    /**
     * Return the item on the top of the stack. Not remove value.
     * 
     * @return the value at the top.
     * @throws Exception if it is not possible to remove - stack empty.
     */
    public String peek() throws Exception {
        if (this.isEmpty())
            throw new Exception("Empty Stack, impossible remove item!");

        return this.top.getValue();
    }

    /**
     * Search for value in the stack.
     * 
     * @param value sought value
     * @return if found, its offset from the top of the stack is returned.
     *         Otherwise, -1 is returned.
     */
    public int search(String value) {
        Item item = this.top;
        int offset = 0;

        while (item != null) {
            if (item.getValue().equalsIgnoreCase(value))
                return offset;
            item = item.getNext();
            offset++;
        }

        return -1;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder("Status Stack:\n");
        Item item = this.top;
        int offset = 0;

        while (item != null) {
            stringBuilder.append("| " + (offset) + " - " + item + "\n");
            item = item.getNext();
            offset++;
        }
        stringBuilder.append("------------------\n");

        return stringBuilder.toString();
    }
}