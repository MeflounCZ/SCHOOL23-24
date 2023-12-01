#include <iostream>

using namespace std;

int main()
{
    double botLimit, topLimit, step;

    cout << "Write bottom limit of calculations:";
    cin >> botLimit;
    cout << "Write upper limit of calculations:";
    cin >> topLimit;
    cout << "How accurate do you want to be (size of steps):";
    cin >> step;

    double x = botLimit;

    while (x < topLimit){
        if(F(x)*F(x+step) == 0){
            if (F(x) == 0){
                cout << "Function intersects x axis at the value of " + x;
            }
            if (F(x+1) == 0){
                cout << "Function intersects x axis at the value of " + (x+step);
            }
        }
        if(F(x)*F(x+step) < 0){
            cout << "Function intersects x axis in interval from " + x + " to " + (x+step);
        }
        x += step;
    }
    return 0;
}
