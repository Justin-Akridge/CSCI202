#ifndef QUEUETYPE.H
#define QUEUETYPE.H

template <class Type>
class queueType
{
public:
  const queueType<Type>& operator=(const queueType<Type>&);
  bool isEmptyQueue() const;
  bool isFullQueue() const;
  void initializeQueue();
  Type front() const;
  Type back() const;
  void addQueue(const Type& queueElement);
  void deleteQueue();
  queueType(int queueSize = 100);
  queueType(const queueType<Type>& otherqueue);
  ~queueType();
private:
  int maxQueueSize;
  int count;
  int queueFront;
  int queueRear;
  Type *list;
};

#endif //QUEUETYPE.H
