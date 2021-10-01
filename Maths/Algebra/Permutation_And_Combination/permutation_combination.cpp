#include<iostream>
using namespace std;

long long factorial( long long  num ){
 if( ( num == 0 ) || ( num == 1 )){
    return num;
 }
 long long fact = 1;
 while( num > 0 ){
    fact = fact * num;
    num = num - 1;
 }
 return fact;
}

long long permutation( long long n , long long r ){
    return ( factorial( n ) / factorial( n - r ) );
}

long long combination( long long n , long long r ){
    return  ( factorial ( n ) / ( factorial ( r ) * factorial ( n - r )  ) );
}

int main(){
 long long selection = 0, n = 0 , r = 0;
 cout<<"Press 1 for Permutaion  or Press 2 for Combination :";
 cin >> selection;
 if( (selection != 1 ) && ( selection != 2 ) ){
    cout <<"<!-----Incorrect Option Selected-----!>"<<"\n";
    return 1;
 }
 cout<<"Enter the value of the places [n] and the number of objects [r] :";
 cin >> n >> r;

 if( n < r ){
    cout<<"<!----Incorrect Value of [n] and [r] is inserted.----!>\n";
    return 1;
 }

 if( selection == 1 ){
 cout <<"Permutation :"<<permutation( n , r)<<"\n";
 }
 else if( selection == 2 ){
 cout <<"Combination :"<<combination( n , r)<<"\n";
 }
 return 1;
}
