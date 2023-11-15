#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int shared = 0;
struct lock lk;

void fn1()
{
  int i;
  for(i = 0; i < 10; i++) {
    acquire(&lk);
    shared++;
    printf("%d from thread 1\n", shared);
    release(&lk);
  }

  exit(0);
}

void fn2()
{
  int i;
  for(i = 0; i < 10; i++) {
    acquire(&lk);
    shared++;
    printf("%d from thread 2\n", shared);
    release(&lk);
  }

  exit(0);
}

void fn3()
{
  int i;
  for(i = 0; i < 10; i++) {
    acquire(&lk);
    shared++;
    printf("%d from thread 3\n", shared);
    release(&lk);
  }

  exit(0);
}

int
main()
{
  initlock(&lk);

  acquire(&lk);
  int tid1 = thread_create(fn1);
  printf("Thread 1 spawned; tid=%d\n", tid1);
  release(&lk);
  
  acquire(&lk);
  int tid2 = thread_create(fn2);
  printf("Thread 2 spawned; tid=%d\n", tid2);
  release(&lk);

  acquire(&lk);
  int tid3 = thread_create(fn3);
  printf("Thread 3 spawned; tid=%d\n", tid3);
  release(&lk);

  thread_join();
  thread_join();
  thread_join();

  exit(0);
}
