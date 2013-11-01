/* Fibonacci number:
 *      0 1 1 2 3 5 8 13 21 34 55
 *   - Recursive 
 *   - Non-recursive
 */
#include <iostream>

#define FIBO_ERR (-1)

static int _fibo_memo(int n, int* memo);

// this is bad solution
int fibo(int n) 
{
    if (n<=0) 
        return FIBO_ERR;

    if (n==1 || n==2)   
        return (n-1);

    return fibo(n-2)+fibo(n-1);
}

int fibo_memo(int n) 
{
    if (n<0)
        return FIBO_ERR;

    int memo[n+1];
    for(int i=0; i<=n; i++) {
        memo[i] = -1;
    }
    
    memo[0] = 0;
    memo[1] = 1;

    return _fibo_memo(n, memo);
}

static int _fibo_memo(int n, int* memo)
{
    if (n==0 || n==1)
        return memo[n];

    if (memo[n]!=-1) 
        return memo[n];
    else 
        return (_fibo_memo(n-1, memo) + _fibo_memo(n-2, memo));
} 

int fibo_nr(const int n) 
{
    int i;

    if (n<=0) 
        return FIBO_ERR;

    if (n==1 || n==2)   
        return (n-1);
    
    int prev_2 = 0;
    int prev_1 = 1;
    int num;
    
    for (i=3; i<=n; i++) {
        num = prev_1 + prev_2;
        prev_2 = prev_1;
        prev_1 = num;  
    }
    
    return num;
}

void TEST_fibo()
{
    int num;
    
    std::cout << "\n*** TEST for Fibonacci number ***\n"
              << "Enter an interger: ";

    while (std::cin>>num) {
        std::cout << "Recursive: \n";
        for (int i=1; i<=num; i++) {
            std::cout << fibo(i) << " ";
        }
        std::cout << "\n";
        
        std::cout << "Non-recursive: \n";
        for (int i=1; i<=num; i++) {
            std::cout << fibo_nr(i) << " ";
        }
        std::cout << "\n";
        
        std::cout << "Memo-recursive: \n";
        for (int i=0; i<num; i++) {
            std::cout << fibo_memo(i) << " ";
        }

        std::cout << "\nEnter an interger: ";
    }

    std::cout << "\nTEST for Fibonacci number finished.\n";
}

