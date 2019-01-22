#include<string>
#include<iostream>
#include<pthread.h>  /*POSIX  trheads */
#include<unistd.h>
using namespace std;

	
	string message = "hello";
	int x = 0;
	pthread_mutex_t amutex = PTHREAD_MUTEX_INITIALIZER;

void *input_routine(void *arg1)
{
	
	while(1)
	{
	pthread_mutex_lock(&amutex);
	if (x==0)
	{	
		cout <<"Enter a message: ";
		getline(cin,message);
		x = 1; 
	}
	pthread_mutex_unlock(&amutex);
	}
}
void *print_routine(void *arg1)
{	
	while(1)
	{
	pthread_mutex_lock(&amutex);
	if(x==1)
	{
		cout <<"message was: "<<message<<endl;
		x = 0;
	}
	pthread_mutex_unlock(&amutex);
	}
}


int main()
{
	pthread_t thread1;
	pthread_t thread2;
	
	pthread_create(&thread1, NULL,input_routine,NULL);
	pthread_create(&thread2, NULL,print_routine,NULL);
	
	cout <<endl;
	cout <<endl;
	//pthread_exit(NULL);


}




