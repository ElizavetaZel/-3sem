#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

float pi1(long long iter)
{
    float p = 0;
    float s = 1.0;
    for (int i = 0; i < iter; i++)
    {
        p += s / (2 * i + 1);
        s = -s;
    }
    return 4 * p;
}

float pi2(long long iter)
{
    float p = 1;
    for (int i = 1; i < iter; i++)
    {
        float j = i * i;
        p *= (4 * j) / (4 * j - 1);
    }
    return 2 * p;
}

float pi3(long long iter)
{
    float p = 0;
    for (int i = 1; i < iter; i++)
    {
        p += 1 / pow(i, 2); 
    }
    return sqrt(6 * p);
}


float pi4(long long iter)
{
    float p = 3.0;
    float s = 1.0;
    for (int i = 1; i <= iter; i++)
    {
        float d = (2 * i) * (2 * i + 1) * (2 * i + 2);
        p += s * (4.0 / d);
        s = -s;
    }
    return p;
}

float pi5(long long iter)
{
    float p = 0;
    for (int i = 0; i < iter; i++)
    {
        float t = 1.0 / ((2 * i + 1) * (2 * i + 1));
        p += t;
    }
    return sqrt(6 * p);
}

double measure_time(int formula_id, int precision_digits, int measurements = 50) {
    double target_error = pow(10, -precision_digits);
    const double exact_pi = 3.14159265358979323846;
    
    double total_time = 0;
    int success_count = 0;
    
    for (int m = 0; m < measurements; m++) {
        auto start = high_resolution_clock::now();
        
        bool found = false;
        long long iter = 1;
        
        while (!found) {
            float calculated_pi;
            
            switch(formula_id) {
                case 1: calculated_pi = pi1(iter); break;
                case 2: calculated_pi = pi2(iter); break;
                case 3: calculated_pi = pi3(iter); break;
                case 4: calculated_pi = pi4(iter); break;
                case 5: calculated_pi = pi5(iter); break;
            }
            
            if (fabs(calculated_pi - exact_pi) < target_error) {
                found = true;
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(end - start);
                total_time += duration.count();
                success_count++;
            }
            
            if (iter > 10000000) {
                break;
            }
            iter++;
        }
    }
    
    return (success_count > 0) ? (total_time / success_count) / 1e9 : -1.0;
}

int main()
{
    cout << "digits,pi1_time,pi2_time,pi3_time,pi4_time,pi5_time" << endl;
    
    for (int digits = 1; digits <= 10; digits++) {
        cout << digits;
        
        for (int formula = 1; formula <= 5; formula++) {
            double avg_time = measure_time(formula, digits, 50);
            
            if (avg_time > 0) {
                cout << "," << avg_time;
            } else {
                cout << "," << "nan";
            }
        }
        cout << endl;
    }
    
    return 0;
}