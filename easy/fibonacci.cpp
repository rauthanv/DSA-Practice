class Solution {
public:
    int fib(int n) {
    //recusion
    //     if(n==0) return 0;
    //     if(n==1) return 1;
    //     return fib(n-1)+fib(n-2);

    if(n==0) return 0;
    if(n==1) return 1;
    int n1=0,n2=1;
    int temp;
    while(n>1){
        temp=n1;
        n1=n2;
        n2=temp+n2;
        n--;
    }
    return n2;
    }
};