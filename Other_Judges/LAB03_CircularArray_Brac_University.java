public class CircularArray{
  
  private int start;
  private int size;
  private Object [] cir;
  
  /*
   * if Object [] lin = {10, 20, 30, 40, null}
   * then, CircularArray(lin, 2, 4) will generate
   * Object [] cir = {40, null, 10, 20, 30}
   */
  public CircularArray(Object [] lin, int st, int sz){
    	start = st;
	size = sz;
	cir = new Object[lin.length];
	
	for(int i=0;i<lin.length;i++)
	{
		cir[st] =lin[i];	//as start hobe st theke so cir (amader class e declare kora) e circularly rakhbo
		st = (st+1)%(cir.length);	//mode korechi as circular ly rakhtechi . for ex. st=3 so 3,4,0,1,2
  }
  
  //Prints from index --> 0 to cir.length-1
  public void printFullLinear(){
        //TO DO
	for(int i=0;i<cir.length; i++)	//just cir array ta print korechi. 
	{
		if(i!=cir.length-1) system.out.print(cir[i]+" ,");	
		else system.out.print(cir[i]+".\n");
	}
  }
  
  // Starts Printing from index start. Prints a total of size elements
  public void printForward(){
    //To DO
	for(int i=0,j=start;i<size; i++,j=(j+1)%cir.length) //comment e age thekei sob bolei deoa ki korte hobe
	{
		if(i!=size-1) system.out.print(cir[j]+" ,");
		else system.out.print(cir[j]+".\n");
	}
  }
  
  
  public void printBackward(){
   //TO DO
	for(int i=0,j=(start+size-1)%cir.length;i<size; i++,j--)
	{
		if(i!=size-1) system.out.print(cir[j]+" ,");
		else system.out.print(cir[j]+".\n");
	}
  }
  
  // With no null cells
  public void linearize(){
    //TO DO
	Object[] WithoutNull = new Object[size];

	for(int i=0,j=start;i<size; i++,j=(j+1)%cir.length)
	{
		WithoutNull[i] = cir[j]
	}
	cir = WithoutNull;
	start = 0;
  }
  
  // Do not change the Start index
  public void resizeStartUnchanged(int newcapacity){
    //TO DO
	Object[] tmp = new Object[newcapacity];
	for(int i=0,j=start,k=start;i<size; i++,j=(j+1)%tmp.length,k=(k+1)%cir.length)
	{
		tmp[i] = cir[j];
	}
	cir = tmp;
	start = 0;
  }
  
  // Start index becomes zero
  public void resizeByLinearize(int newcapacity){
    //TO DO
	Object[] tmp = new Object[newcapacity];
	for(int i=0,j=start;i<cir.length; i++,j=(j+1)%cir.length)
	{
		tmp[i] = cir[j];
	}
	cir = tmp;
	start = 0;
	
	
  }
  
  /* pos --> position relative to start. Valid range of pos--> 0 to size.
   * Increase array length by 3 if size==cir.length
   * use resizeStartUnchanged() for resizing.
   */
  public void insertByRightShift(Object elem, int pos){
    //TO DO
    if(pos < 0 || pos > size) System.out.println("Invalid position");
    else if(size == cir.length) resizeStartUnchanged(cir.length + 3);
    if(pos >= 0 || pos <= size){
    if(cir[(start+pos)%cir.length] == null) cir[(start + pos)%cir.length] = elem;
    else{
	for(int i = 0, k = (start + size - 1)%cir.length; i < (size - pos); i++, k--){
	    if(k - 1 < 0) k = cir.length-1;
	    cir[(k+1)%cir.length] = cir[k];
	}
	cir[(start + pos)%cir.length] = elem;
	size++;
	}
    }
	
  }
  
  public void insertByLeftShift(Object elem, int pos){
    //TO DO
	if(pos < 0 || pos > size) System.out.println("Invalid position");
    else if(size == cir.length) resizeStartUnchanged(cir.length + 3);
    if(pos >= 0 || pos <= size){
      for(int i = 0, k = ((start-1) < 0 ? cir.length-1:start-1); i < (size - pos); i++, k = (k+1)%cir.length)
        cir[k] = cir[k + 1];
      cir[(start + pos)%cir.length] = elem;
      size++; start = ((start-1) < 0 ? cir.length:--start);
    }
  }
  
  /* parameter--> pos. pos --> position relative to start.
   * Valid range of pos--> 0 to size-1
   */
  public void removeByLeftShift(int pos){
    //TO DO
	 if(pos < 0 || pos >= size) System.out.println("Invalid position");
    else{
      for(int i = 0, k = (start + pos)%cir.length; i < (size - pos - 1); i++, k = (k+1)%cir.length)
        cir[k] = cir[(k+1)%cir.length];
      cir[(start + (--size))%cir.length] = null;
    }
  }
  
  /* parameter--> pos. pos --> position relative to start.
   * Valid range of pos--> 0 to size-1
   */
  public void removeByRightShift(int pos){
    //TO DO
	 if(pos < 0 || pos >= size) System.out.println("Invalid position");
    else{
      for(int i = 0, k = (start+pos)%cir.length; i <= (size - pos); i++, k = ((k-1) > 0 ? --k : cir.length-1))
        cir[k] = cir[((k - 1) < 0 ? cir.length-1 : k-1)];
      cir[start] = null;
      start = (start+1)%cir.length; size--;
    }
  }
  }
  
  
  //This method will check whether the array is palindrome or not
  public void palindromeCheck(){
    //TO DO
	//just loop chalaye check 
  }
  
  
  //This method will sort the values by keeping the start unchanged
  public void sort(){
    //TO DO

		//ekdom easy!!!
  }
  
  //This method will check the given array across the base array and if they are equivalent interms of values return true, or else return false
  public boolean equivalent(CircularArray k){
    //TO DO

	//base arrah r k array jodi valuegula same hoy then return true else return false

    return false; // Remove this line
  }
}
