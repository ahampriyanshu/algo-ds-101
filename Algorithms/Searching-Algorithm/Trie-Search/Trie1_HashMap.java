import java.util.HashMap;
import java.util.Map;

public class Trie1_HashMap{

	public static void main(String[] args) {
		Trie t=new Trie();
		t.insert("CAT");
		t.insert("CAP");
		t.insert("DOG");
		t.insert("DAD");
		t.insert("DADDY");
		t.insert("COPY");
		System.out.println(t.search("CAP"));
		// t.display();
	}

}
class TrieNode{
	char data;
	Map<Character,TrieNode> next;
	boolean terminate;
	
	public TrieNode(char data,boolean terminate) {
		this.data=data;
		next=new HashMap<>();
		this.terminate=terminate; 
	}
}

class Trie{
	TrieNode root;
	
	public Trie() {
		this.root=new TrieNode('\0',false);
	}
	
	public boolean search(String s) {
		TrieNode x=this.root;
		for(int i=0;i<s.length();i++) {
			char c=s.charAt(i);
			if(i+1 == s.length() && x.next.containsKey(c) && x.next.get(c).terminate) {
				return true;
			}
			if(!x.next.containsKey(c)) {
				return false;
			}
			x=x.next.get(c);
		}
		return false;
	}

	public void display() {
		display(root);
	}

	private void display(TrieNode root) {
		if(root== null) {
			return;
		}
		for(Map.Entry<Character,TrieNode> e:root.next.entrySet()) {
			System.out.print(e.getValue().data+" "+e.getValue().terminate+" ");
			display(e.getValue());
			System.out.println();
		}		
	}

	public void insert(String data) {
		insert(root,data);
	}

	private void insert(TrieNode root, String s) {

		TrieNode x=root;
		
		for(int i=0;i<s.length();i++) {
			char c=s.charAt(i);
			if(i+1== s.length()) {
				x.next.put(c,new TrieNode(c,true));
				break;
			}
			if(!x.next.containsKey(c)) {
				x.next.put(c,new TrieNode(c,false));
			}
			x=x.next.get(c);
		}

	}
	
	
	
}


