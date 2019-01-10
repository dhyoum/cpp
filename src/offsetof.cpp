#include <stdio.h>

template <typename T, typename M> M get_member_type(M T::*);
template <typename T, typename M> T get_class_type(M T::*);

template <typename T,
          typename R, R T::*M
         >
constexpr size_t offset_of()
{
    return reinterpret_cast<size_t>(&(((T*)0)->*M));
}

#define OFFSET_OF(m) offset_of<decltype(get_class_type(m)), decltype(get_member_type(m)), m>()

template<typename T, typename U> constexpr size_t offsetOf(U T::*member)
{
    return (char*)&((T*)nullptr->*member) - (char*)nullptr;
}

struct Table
{
    int offset;
    const char* para;
};

struct Base
{
    virtual ~Base(){}
    virtual Table* getTable()= 0;

    void test()
    {
        const Table* table = getTable();
        for (int i=0; i<1; i++)
        {
            char** pptr = (char**)((char*)this + table[i].offset);
            printf("%s value : %p (offset:%d)\n", table[i].para, (*pptr), table[i].offset);
        }
    }
};

struct Event : public Base
{
    Event()
    {
        ptr = new char();
        printf("ptr = %p\n", ptr);
    }

    int x;
    int y;
    int arr[2];
    char* ptr;
    char z;

    virtual Table* getTable() 
    {
        printf("1. address ptr = %p\n", &ptr);
        printf("2. address ptr = %p\n", ptr);
        static Table paramTable[] =  {
            /*
            {OFFSET_OF(&Event::x), "hellox"},
            {OFFSET_OF(&Event::y), "helloy"},
            {OFFSET_OF(&Event::arr), "hello_arr"},
            {OFFSET_OF(&Event::ptr), "hello_ptr"}
            {offsetOf(&Event::x), "hellox"},
            {offsetOf(&Event::y), "helloy"},
            {offsetOf(&Event::arr), "hello_arr"},
            {offsetOf(&Event::ptr), "hello_ptr"},
            {offsetOf(&Event::z),   "hello_z"},
            */
            {(char*)&ptr-(char*)this, "hello_ptr"}
        };

        return paramTable;
    }
};

int main()
{
    Base* b = new Event();
    b->test();

    delete b;

    return 0;
}
