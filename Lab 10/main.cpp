 /**
 *Joshua Whiteford
 *13/11/2017
 *main.c
 *555 Timer Astable Multivibrator Calculations
 */



/**< preprocessor directives */
#include <iostream>
#define PI 3.14592654

using namespace std;
void Timer(double R1, double R2, double C1, double *p_a, double *p_v);
    /**< Starting the function */

int main()
{
    /**< Declaring our main function Variavbles */
    double  Hz = 0, dutyCycle = 0;
    double *p_d, *p_f;
    double R1 = 0, R2 = 0, C1 = 0;

    /**< Setting our Pointer Variables to the Address Of A & V */
    p_f = &Hz;

    p_d = &dutyCycle;

    /**< Welcoming the User & Explaining what the function does  */
    cout << "This program Will Calculate the output frequency \n\t\t&\n duty cycle of a 555 timer!" << endl;
    /**< Ensuring the values the User enters are not equal to 0 */
    while ( R1 == 0 || R2 == 0 || C1 == 0 )
    {
        /**< If the Entered Values Are 0 asking the User to input new values for R1, R2, C1 */
        if (R1 == 0)
        {
            /**< Asking & Getting the User to enter a Value for R1 */
            cout << "Please Enter The value of R1 in Ohms:";
            cin >> R1;
        }
        else if (R2 == 0)
        {
            /**< Asking & Getting the User to enter a Value for R2 */
            cout << "Please Enter The value of R2 in Ohms::";
            cin >> R2;
        }
        else
        {
            /**< Asking & Getting the User to enter a Value for C1 */
            cout << "Please Enter The value of C1 in Ohms:";
            cin >> C1;

        }
    }

    /**< Sending the program to the 555Timer functin */
    Timer( R1, R2, C1, p_f, p_d );

    /**< Displaying the results to the User */
    cout << "\tThe Output Frequency is:" << Hz << "Hz" << endl;
    cout << "\tThe Duty Cycle is:" << dutyCycle << "%" << endl;

    return 0;
}

/**< Starting the second function */
void Timer (double R1, double R2, double C1, double *p_f, double *p_d )
{
    /**< Doing the Equations and setting the variables the Pointers Point to as the result */
    *p_f = 1.44/((R1 + 2*R2)*C1);

    *p_d = (R1 + R2) / (R1 + 2 * R2);

    return;
}
