#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// pi1: Ряд Лейбница - медленная сходимость с колебаниями
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

// pi2: Произведение Валлиса - монотонная сходимость с одной стороны
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

// pi3: Ряд Базеля - быстрая сходимость
float pi3(long long iter)
{
    float p = 0;
    for (int i = 1; i < iter; i++)
    {
        p += 1 / pow(i, 2); 
    }
    return sqrt(6 * p);
}

// pi4: Ряд Нилаканта - колеблется вокруг точного значения
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

// pi5: "Плохая" формула - сходится к другому значению
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

main()
{
    for (long long int n = 100; n < 15000; n += 100)
    {
        cout << n << endl;
        cout << pi1(n) << endl;
        cout << pi2(n) << endl;
        cout << pi3(n) << endl;
        cout << pi4(n) << endl;
        cout << pi5(n) << endl;
    }
}