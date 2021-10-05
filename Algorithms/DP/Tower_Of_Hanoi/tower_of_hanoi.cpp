#include <iostream>

using namespace std;

void towerOfHanoi(char from,char to,char aux,int n){
	if(n == 1){
		cout<<"Move disk 1 from rod "<<from<<" to rod "<<to<<endl;
		return;
	}

	towerOfHanoi(from,aux,to,n-1);
	cout<<"Move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
	towerOfHanoi(aux,to,from,n-1);
}

int main(){
	int n; cin>>n;
	towerOfHanoi('A','C','B',n);
	return 0;
}
