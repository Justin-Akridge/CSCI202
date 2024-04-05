#include <iostream>
#include "queueType.h"
 
using namespace std;
   
int main()
{
    queueType<int> queue;
    int x, y;
    for (int i = 0; i < 10; i++) {
      queue.initializeQueue(); 
      x = 4;
      y = 5;
      queue.addQueue(x);
      queue.addQueue(y);
      x = queue.front(); 
      queue.deleteQueue();
      queue.addQueue(x + 5);
      queue.addQueue(16);
      queue.addQueue(x);
      queue.addQueue(y - 3);

      cout << "Queue Elements: ";

      while (!queue.isEmptyQueue())
      {
          cout << " " << queue.front();
          queue.deleteQueue();	
      }

      cout << endl;
    }

    return 0;
}
