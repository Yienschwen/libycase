#ifndef LIBYCPP_VECTOR_H_
#define LIBYCPP_VECTOR_H_

template <class T>
class Vector {
public:
    Vector();
    ~Vector();
    unsigned length();
    void append(T);
    

    T& operator[](unsigned usgIndex) { return ptrPool[usgIndex]; }
    const T& operator[](unsigned usgIndex) const { return ptrPool[usgIndex]; }

private:
    T* ptrPool;
    unsigned usgCount;
    unsigned usgCapacity;

};


#endif