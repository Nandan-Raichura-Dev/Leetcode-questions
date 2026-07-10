class Solution {// sieve algo or method and here 1 in the array  means , the number is prime , 0 means non prime
public:
    int countPrimes(int n) {
        int primes[n+1];

        for(int i=2;i<n;i++){
            primes[i]=1;
        }


        for(int i=2;i*i<n;i++){// here we did the i*i becz we want the lopps domt run uncessary till last index,if i*i gets more then the n, we will stop there only

        if(primes[i]==1){// number is prime, we will set its factor to the 0 so our opreation get redused

        for(int j=i*i;j<=n;j+=i){// if i is 7 we will go from 7*7(i*i or 2*i) to less then n 
            primes[j]=0;
        }

        }

        // now we got the array which consist of the value 1 where 

        }

        int count=0;
        for(int i=2;i<n;i++){
            if(primes[i]==1){
                count++;
            }
        }

        return count;
    }
};