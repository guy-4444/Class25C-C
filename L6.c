#include "L6.h"
#include <stdio.h>

float min(float a, float b);
float max(float a, float b);
float Pension(float gross);
float SocialSecurity(float gross);
float HealthTax(float gross);
float EducationFund(float gross);
float IncomeTax(float gross);
float IncomeTaxW(float gross, float extraPoints);

const float PENSION_RATE = 0.06;
const float AVERAGE_SALARY_BT = 12536;
const float MAX_SALARY_FOR_BT = 50695;
const float MAX_SALARY_FOR_EDF = 16000;
const float EDF_RATIO = 0.025;
const float EXTRA_POINT_RATE = 242.0;

void startL6() {
    printf("▧ ▧ ▧ ▧ L6 ▧ ▧ ▧ ▧\n");

    float gross = 35000.0;


    float pension = Pension(gross);
    float socialSecurity = SocialSecurity(gross);
    float healthTax = HealthTax(gross);
    float educationFund = EducationFund(gross);
    float incomeTax = IncomeTax(gross);
    printf("pension: %f\n", pension);
    printf("socialSecurity: %f\n", socialSecurity);
    printf("healthTax: %f\n", healthTax);
    printf("educationFund: %f\n", educationFund);
    printf("incomeTax: %f\n", incomeTax);
    printf("\n\n\n");


    printf("0: %f\n", IncomeTax(0));
    printf("1000: %f\n", IncomeTax(1000));
    printf("7000: %f\n", IncomeTax(7000));
    printf("7000: %f\n", IncomeTaxW(7000, 2.25));
    printf("10000: %f\n", IncomeTax(10000));
    printf("35000: %f\n", IncomeTax(35000));
    printf("35000: %f\n", IncomeTaxW(35000, 10.0));
    printf("50000: %f\n", IncomeTax(50000));
    printf("100000: %f\n", IncomeTax(100000));

}

float Pension(float gross) {
    float result = gross * PENSION_RATE;
    return result;
}

float SocialSecurity(float gross) {
    const float BELOW_60_AVERAGE = 0.0104;
    const float ABOVE_60_AVERAGE = 0.07;
    const float AVERAGE_60 = AVERAGE_SALARY_BT * 0.6;

    float below = min(gross, AVERAGE_60);
    float above = max(gross - AVERAGE_60, 0);
    above = min(above, MAX_SALARY_FOR_BT - AVERAGE_60);

    float tax = 0;
    tax += below * BELOW_60_AVERAGE;
    tax += above * ABOVE_60_AVERAGE;

    return tax;
}

float HealthTax(float gross) {
    const float BELOW_60_AVERAGE = 0.0323;
    const float ABOVE_60_AVERAGE = 0.0517;
    const float AVERAGE_60 = AVERAGE_SALARY_BT * 0.6;

    float below = min(gross, AVERAGE_60);
    float above = max(gross - AVERAGE_60, 0);
    above = min(above, MAX_SALARY_FOR_BT - AVERAGE_60);

    float tax = 0;
    tax += below * BELOW_60_AVERAGE;
    tax += above * ABOVE_60_AVERAGE;

    return tax;
}

float EducationFund(float gross) {
    const float below = min(gross, MAX_SALARY_FOR_EDF);
    float tax = below * EDF_RATIO;

    return tax;
}

const float INCOME_TAX_STEP_1 = 7010;
const float INCOME_TAX_STEP_2 = 3050;
const float INCOME_TAX_STEP_3 = 6090;
const float INCOME_TAX_STEP_4 = 6290;
const float INCOME_TAX_STEP_5 = 24250;
const float INCOME_TAX_STEP_6 = 13440;

const float INCOME_TAX_STEP_RATIO_1 = 0.10;
const float INCOME_TAX_STEP_RATIO_2 = 0.14;
const float INCOME_TAX_STEP_RATIO_3 = 0.20;
const float INCOME_TAX_STEP_RATIO_4 = 0.31;
const float INCOME_TAX_STEP_RATIO_5 = 0.35;
const float INCOME_TAX_STEP_RATIO_6 = 0.47;
const float INCOME_TAX_STEP_RATIO_7 = 0.50;

float IncomeTax(float gross) {
    float part1 = min(gross, INCOME_TAX_STEP_1);
    gross = max(0, gross - INCOME_TAX_STEP_1);
    float part2 = min(gross, INCOME_TAX_STEP_2);
    gross = max(0, gross - INCOME_TAX_STEP_2);
    float part3 = min(gross, INCOME_TAX_STEP_3);
    gross = max(0, gross - INCOME_TAX_STEP_3);
    float part4 = min(gross, INCOME_TAX_STEP_4);
    gross = max(0, gross - INCOME_TAX_STEP_4);
    float part5 = min(gross, INCOME_TAX_STEP_5);
    gross = max(0, gross - INCOME_TAX_STEP_5);
    float part6 = min(gross, INCOME_TAX_STEP_6);
    gross = max(0, gross - INCOME_TAX_STEP_6);
    // rest of the salary..
    float part7 = gross;

    float tax = 0;
    tax += part1 * INCOME_TAX_STEP_RATIO_1;
    tax += part2 * INCOME_TAX_STEP_RATIO_2;
    tax += part3 * INCOME_TAX_STEP_RATIO_3;
    tax += part4 * INCOME_TAX_STEP_RATIO_4;
    tax += part5 * INCOME_TAX_STEP_RATIO_5;
    tax += part6 * INCOME_TAX_STEP_RATIO_6;
    tax += part7 * INCOME_TAX_STEP_RATIO_7;

    return tax;
}

float IncomeTaxW(float gross, float extraPoints) {
    float tax = IncomeTax(gross);

    float extraPointsRefund = extraPoints * EXTRA_POINT_RATE;
    tax -= extraPointsRefund;
    tax = max(0, tax);

    return tax;
}





float min(float a, float b) {
    if (a > b) {
        return b;
    }
    return a;
}

float max(float a, float b) {
    if (a > b) {
        return a;
    }
    return b;
}
/**

* use const / define
* use function per calculating

get gross salary from user.

run until input is -1
get option number from user

1: pension
2: educationFund
3: healthTax
4: socialSecurity
5: incomeTax




float pension(float gross) {
    float t = gross * 0.5;
    return t;
}

 */





