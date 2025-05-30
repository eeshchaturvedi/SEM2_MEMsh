#include<iostream>
#include<string>

using namespace std;

int main() {
    int* arr = new int[5];
    for (int i = 0; i < 6; i++)
    {
        try {
            if(i < 0 || i >= 5) {
                throw string("Array index out of bounds.");
            }

            cout << "Enter " << i+1 << "th element : ";
            cin >> arr[i];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000,'\n');
                throw int(0);
            }
        }

        catch (const string& str) { cout << "Exception : " << str << endl;}

        catch (int e) { 
            cout << "ERROR : Invalid input" << endl; 
            i--;
        }
    }
    delete[] arr;
    return 0;
}