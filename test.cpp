#include "threadPool/pthreadpool.h"
#include "threadPool/pthreadpool.cpp"
#include "taskqueue/taskqueue.h"
#include "taskqueue/taskqueue.cpp"
#pragma 

void taskFunc(void* arg)
{
	int num = *(int*)arg;
	printf("thread %ld is working, number = %d\n", pthread_self(), num);
	Sleep(1);
}


int main(void)
{
	//�����̳߳�
	ThreadPool<int>pool(3, 10);
	for (int i = 0; i < 100; ++i)
	{
		int* num = new int(i + 100);
		pool.addTask(Task<int>(taskFunc, num));

	}

	Sleep(20);
	return 0;
}