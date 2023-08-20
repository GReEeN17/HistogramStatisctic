#ifndef STATISTIC_H
#define STATISTIC_H


class Statistic
{
private:
    unsigned short* mass;
    int max_value;
public:
    Statistic(unsigned char* mass_);

    int getMaxValue();

    int* makeStatistic(int len, int size);
};

#endif // STATISTIC_H
