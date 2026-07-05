#include<stdio.h>
#include<unistd.h>
int main() {
	for(;;){
	fork();
	fork();
	fork();
	}
	printf("hello\n");
	return 0;
}