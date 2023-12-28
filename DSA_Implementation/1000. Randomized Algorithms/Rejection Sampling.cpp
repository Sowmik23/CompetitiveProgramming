// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        

        //  Rejection Sampling
        // Time Complexity: O(1)O(1)O(1) average, but O(∞)O(\infty)O(∞) worst case.
        /*
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col+(row-1)*7;
        } while(idx>40);

        return 1+(idx-1)%10;
        */

        int i, j;
        while( (i=rand7())>6 ); //// P(i is even) = P(i is odd) = 0.5
        while( (j=rand7())>5 ); // P(j==1) = P(j==2) = P(j==3) = P(j==4) = P(j==5) = 0.2

        return i&1 ? j : j+5;

        /*
        Details:
        We can't get an equal distribution between 1 and 10 by simply generating a 
        single integer between 1 and 7. But we can generate two random numbers. 
        The first, i, will tell us whether the final answer is in the range 1-5 or 6-10.
        The second, j, tells us whether the final answer is the first, second, ..., fifth 
        number in the selected range.

        We can check whether i is even or odd--i % 2 == 0 tells us if it's even--but rand7() 
        generates four odd numbers (1, 3, 5, 7) and only three evens (2, 4, 6). So we have to discard
        one of the odds in order to have equal probability of getting an even or an odd. 
        OP chose to discard 7. We exit the first while loop with i equal to 
        one of (1, 2, 3, 4, 5, 6) with equal probability.

        If j is one of (1, 2, 3, 4, 5) then we can just use it as is, but there is
        a chance it will take the value of 6 or 7. So the second while loop ensures that 
        we keep trying until j is one of (1, 2, 3, 4, 5). This too is with equal probability.

        Finally, if i is even, we just return j. If i is odd, we just add five to 
        get one of (6, 7, 8, 9, 10).

        Got it?*/
    }
};