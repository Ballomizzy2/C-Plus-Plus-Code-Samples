#include <iostream>
#include <iomanip>

using namespace std;

int main(void)

{

    int table[4][2];

    for (int j = 0; j < 4; j++)

    {

        for (int k = 0; k < 2; k++)

        {

            table[j][k] = j + k;

            cout << setw(4) << table[j][k];

        }

        cout << endl;

    }

    return 0;

}