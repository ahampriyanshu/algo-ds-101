public class Employee {
	  private String name;
	  private List<Employee> reportee;
	  private Employee manager;
	  Employee(String name) {
		  this.name = name;		
		  reportee = new ArrayList<>();
	  }
	  public  void setManager(Employee m) {
		  manager = m;
	  }
	  public  void addReprotee(Employee e) {		 
			  reportee.add(e);
			  e.manager = this;
	  }	  
	  
	  //O(log(n)) time complexity, O(1) memory
	  static Employee closestCommonManager2(Employee a, Employee b) {
		  Employee e1 = a;
		  Employee e2 = b;
		  int h1 = 0;
		  int h2 = 0;
		  while (e1 != null || e2 != null) {
			  if (e1 != null) {				
			  	e1 = e1.manager ;
			  	h1++;
			  }
			  if (e2 != null) {				
				  	e2 = e2.manager ;
				  	h2++;
			  }	  
		  }				  
		  int diff = Math.abs(h1 - h2);
		  if(h1 > h2) {
			  e1 = a;
			  e2 = b;			  
		  } else {			 
			  e1 = b;
			  e2 = a;
		  }
		  while (diff > 0) {
			  e1 = e1.manager;
			  diff--;
		  }
		  while (e1 != e2) {
			  e1 = e1.manager ;
			  e2 = e2.manager ;
		  }
		  return e1;
	  }
	  
	  //O(log(n)) time complexity, O(log(n)) memory
	  static Employee closestCommonManager(Employee a, Employee b) {
		 
		  Stack<Employee> ls1 = new Stack<Employee>();
		  Stack<Employee> ls2 = new Stack<Employee>();		
		  while (a != null || b != null) {
			  if (a != null) {
				ls1.push(a);
			  	a = a.manager ;
			  }
			  if (b != null) {
				  ls2.push(b);
				  b = b.manager;
			  }
			  
		  }		
		  while(!ls1.isEmpty() && !ls2.isEmpty()) {
			  if (ls1.peek() != ls2.peek()) {
				  break;
			  }
			  a = ls1.pop();
			  ls2.pop();			  
		  }
		  return a;
	  }
	  
	  public String toString() {
		  return name;
	  }
  }
