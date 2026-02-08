/*
WAP which takes input an array of digits encoding in decimal number D and 
updates the array to represent D+1 
eg. 
input :  [1,2,9]
output : [1,3,0]
*/
#include <iostream>
#include<vector>
using namespace std;
vector<int> plusOne(vector<int>& A)
{
    ++A.back();
    for (int i = A.size() -1 ;  i> 0 &&  A[i] == 10 ; --i )
    {
        A[i] = 0;
        ++A[i-1];
    }
    if (A[0]==10){
    A[0] = 0 ; 
    A.insert(A.begin(),1);
    }
    return A;
}
int main()
{
    vector<int> A {9,9,9};
    vector<int > R = plusOne(A);
    for (auto i :  R){
    std::cout << i ;
    }
    cout << std::endl;
    return 0 ;
} 