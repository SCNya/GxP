//ver. 1.1 by AEffect 23.11.12 23:54
#include "GxP.h"
#include "GxP.cpp"

int main()
{
    ifstream in;
    in.open("f.txt");
    /*
     *http://10k.aneventapart.com/1/Uploads/177/
     *
     *f.txt == {xxx
     *          xxx
     *          xxx}
     */
    if (!in.good()) cout << "Error: 1" << endl;
    else
        {
        create(in);
        in.close();
        step();
        for (int i(0); i < (*m); i++)
        {
           delete mass[i];
            mass[i] = 0;
        }
        delete [] mass;
        mass = 0;
        }
    return(0);
}
