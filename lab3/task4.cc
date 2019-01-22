#include<string>
#include<iostream>
#include<pthread.h>  /*POSIX  trheads */
#include<unistd.h>
using namespace std;

	
	string message;

void *input_routine(void *arg1)
{
	string x;
	cout <<"Enter a message: ";
	getline(cin,message);
}
void *print_routine(void *arg1)
{
	cout << "Message: "<<message<<endl;
}


int main()
{
	pthread_t thread1;
	pthread_t thread2;
	
	while(true){

	pthread_create(&thread1, NULL,input_routine,NULL);
	pthread_join(thread1, NULL); 
	

	
	pthread_create(&thread2, NULL,print_routine,NULL);
	pthread_join(thread2, NULL);
	}


	
	cout <<endl;
	cout <<endl;
	pthread_exit(NULL);


}
