//
// Created by 18123 on 2019/9/25.
//

#ifndef PAQ_HOMEWORK_NEWTONINTERPOLATION_H
#define PAQ_HOMEWORK_NEWTONINTERPOLATION_H


class NewtonInterpolation
{
private:
    double x[7] = {0.1, 0.4, 1.0, 1.8, 2.9, 3.2, 3.8};
    double y[7] = {4.2, 3.8, 2.5, 2.0, -2.0, 0.0, -0.3};
public:
    NewtonInterpolation();
    void DividedDifferenceTable(double **m);
    void ApproximateValue(double x, double **m);
};

#endif //PAQ_HOMEWORK_NEWTONINTERPOLATION_H
