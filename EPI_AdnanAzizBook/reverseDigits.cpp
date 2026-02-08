#include <iostream>
long Reverse(int x)
{
    bool is_neg = x<0;
    long result = 0, x_remaining=abs(x);
    while(x_remaining)
    {
        result = result * 10 + x_remaining % 10;
        x_remaining /=10 ;     
    }
    return is_neg ?  -result : result; 
}
int main (){

    int n = -123;
    std::cout << "reverseOf("<<n<<") = " <<Reverse(n)<<std::endl; 

    return 0;
}