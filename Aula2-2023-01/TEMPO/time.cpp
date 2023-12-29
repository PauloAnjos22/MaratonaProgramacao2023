#include <iostream>

int timeConversion(int time);

int main()
{
    int time;
    std::cin >> time;

    timeConversion(time);

    return 0;
}

int timeConversion(int time)
{
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    while (time != 0)
    {
        if (time <= 60)
        {
            seconds = seconds + time;
            time = 0;
            if (seconds >= 60)
            {
                minutes = minutes + 1;
                seconds = seconds - 60;
            }

            if (minutes >= 60)
            {
                hours = hours + 1;
                minutes = minutes - 60;
            }
        }
        else
        {
            minutes = minutes + 1;

            if (minutes >= 60)
            {
                hours = hours + 1;
                minutes = minutes - 60;
            }
            time = time - 60;
        }
    }
    std::cout << hours << ":" << minutes << ":" << seconds << std::endl;

    return 0;
}
