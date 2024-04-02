#include "queueType.h"


const queueType::queueType<Type>& operator=(const queueType<Type>&) {}

template <class Type>
bool queueType::isEmptyQueue() const {
  return (count == 0);
}

template <class Type>
bool queueType::isFullQueue() const {
  return (count == maxQueueSize);
}

template <class Type>
void queueType::initializeQueue() {
  queueFront = 0;
  queueRear = maxQueueSize - 1;
  count = 0;
}

template <class Type>
Type queueType::front() const {
  if (!isEmptyQueue()) {
    return list[queueRear];
  }
}

template <class Type>
Type queueType::back() const {
  if (!isEmptyQueue()) {
    return list[queueFront];
  }
}

template <class type>
void queueType::addQueue(const Type& queueElement) {
  
}

template <class Type>
void queueType::deleteQueue();

template <class Type>
queueType::queueType(int queueSize = 100);

template <class Type>
queueType::queueType(const queueType<Type>& otherqueue);

template <class Type>
queueType::~queueType();
