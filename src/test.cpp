#include <stdio.h>
#include <string.h>

int getoffset(void* from, void* end);

class Enum
{
    public:
        virtual const char* toString() = 0;
};

class AEnum : public Enum
{
    public:
        const char* toString()
        {
            return "AEnum";
        }
};

class BEnum : public Enum
{
    public:
        const char* toString()
        {
            return "BEnum";
        }
};

template <typename T>
struct Table
{
    Table(void* member_, int size_, const char* str_, T type_)
    {
        member = member_;
        size = size_;
        errmsg = str_;
        type = type_;
    }
    void* member;
    int size;
    const char* errmsg;
    T type;
};

class Event
{
public:
    Event() 
    {
        memset(this, 0, sizeof(Event));
    }
    char a[4];
    char b[8];
    AEnum c;

    bool isEqual(Event* other)
    {
        return memcmp(this, other, sizeof(Event)) ? false : true;
    }

    bool isEqual2(Event* other)
    {
        bool result = true;
        /*
        if (memcmp(this->a, other->a, 4) == 0)


        if (memcmp(this->b, other->b, 4) == 0)


            table { 0, 4 }
           4, 8 

        */
        return result;
    }
 
    bool isEqual3(Event* other)
    {
        bool result = true;

        // Table table[] = { {a, 4, "error", 0}, {b, 8, "erro2", 0} };
        Table table = Table(a, 4, "error", 0);

        /*
        for (int i=0; i<2; i++)
        {
            // printf("%p  -> %d (%d)\n", table[i].member, getoffset(table[i].member, this), table[i].size);
            int offset =  getoffset(table[i].member, this);
            if (memcmp( (char*)this+offset, (char*)other+offset, 8) == 0)
            {
                result = true;
            }
            else
            {
                printf("AAA-%s\n", table[i].errmsg);
                result = false;
            }
        }
        */

        return result;
    }

};

int getoffset(void* from, void* end)
{
    return (char*)from - (char*) end;
}

int main()
{

    Event e;
    Event* e1 = new Event();

    e.b[7]= 1;

    printf("The pointer of e : %p\n", &e);
    printf("The pointer of e.a : %p\n", e.a);
    printf("The pointer of e.b : %p\n", e.b);

    printf("The pointer of e1 : %p\n", e1);
    printf("The pointer of e1.a : %p\n", (e1->a));
    printf("The pointer of e1.b : %p\n", (e1->b));


    if ( e.isEqual(e1) )
        printf("same\n");
    else
        printf("not same\n");

    if ( e.isEqual3(e1) )
        printf("same\n");
    else
        printf("not same\n");

    Enum* enum1 = new BEnum();
    puts(enum1->toString());

    return 0;
}
