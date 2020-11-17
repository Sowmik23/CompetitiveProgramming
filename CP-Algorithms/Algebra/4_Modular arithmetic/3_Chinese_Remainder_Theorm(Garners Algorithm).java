


/// take 100 prime numbers greater than 10^9
/// which allows numbers as large as 10^900

             
final int sz = 100;
int primes[] = new int[sz];
int r[][] = new int [sz][sz];


void init(){
	for(int x = 1000*1000*1000, i=0;i<sz;x++){
		if(BigInteger.valueOf(x).isProbablePrime(100)){
			primes[i++] = x;
		}
	}
	
	for(int i=0;i<sz;i++){
		for(int j=i+1;j<sz;j++){
			r[i][j] = BigInteger.valueOf(primes[i]).modInverse(BigInteger.valueOf(primes[j]).intValue();
		}
	}
}

class Number {
	int arr[] = new int[sz];
	
	public Number() {
	}
	
	public Number(int n){
		for(int i=0;i<sz;i++){
			arr[i] = n%primes[i];
		}
	}
	
	public Number(BigInteger n){
		for(int i=0;i<sz;i++){
			arr[i] = n.mod(BigInteger.valueOf(primes[i])).intValue();
		}
	}
	
	public Number add(Number n){
		Number result = new Number();
		for(int i=0;i<sz;i++){
			result.arr[i] = (arr[i] + n.arr[i])%primes[i];
		}
		return result;
	}
	
	public Number subtract(Number n){
		Number result = new Number();
		for(int i=0;i<sz;i++){
			result.arr[i] = (arr[i] - n.arr[i] + primes[i])%primes[i];
		}
		return result;
	}
	
	public Number multiply(Number n){
		Number result = new Number();
		for(int i=0;i<sz;i++){
			result.arr[i] = (int)((arr[i]*1l*n.arr[i])%primes[i];
		}
		return result;
	}
	
	public BigInteger bigIntegerValue(boolean can_be_negative){
		BigInteger result = BigInteger.ZERO, mult = BigInteger.ONE;
		int x[] = new int [sz];
		for(int i=0;i<sz;i++){
			x[i] = arr[i] ;
			for(int j=0;j<i;j++){
				long cur = (x[i] - x[j])*1l*r[j][i];
				x[i] = (int)((cur%primes[i] + primes[i])%primes[i]);
			}
			result = result.add(mult.multiply(BigInteger.valueOf(x[i])));
			mult = mult.multiply(BigInteger.valueOf(primes[i]);
		}
		
		if(can_be_negative){
			if(result.compareTo(mult.shiftRight(1)) >= 0){
				result = result.subtract(mult);
			}
		}
		
		return result;
	}
}
	
	
	
	
	
	
	
	
	
	

