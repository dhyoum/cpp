#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    thread* a1 = new thread([]{ 
            for(int i=0;i<50; i++) 
            {
                cout << i << endl;
            }
            });
    

    delete a1;

    // chrono::seconds dura( 5 );
    // this_thread::sleep_for( dura );

    return 0;
}
