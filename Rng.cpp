#include <bits/stdc++.h>
using namespace std;

void WelcomeMessage()
{
    cout << "       -------------------------------------------------------";
    cout << "\n\t\t*** Welcome to Our Project. ***" << endl;
    cout << "\t\t*** Random number generator. ***" << endl<<endl;
    cout<<"\t\t   ICG RULE: X(i+1)=(a/Xi)%m"<<endl;
    cout<<"\t\t   MSM RULE: X(i)= (Xi)^2 -> mid%m"<<endl;
    cout<<"\t\t   LFG RULE: X(i)=(Xi-j operator Xi-k)%m"<<endl;
    cout<<"\t\t   MRG RULE: X(i+1)= sum(an*Xi-q)%m"<<endl;
    cout << "       -------------------------------------------------------";
    cout << endl;
}
void output()
{
    cout << endl
         << endl;
    cout << " ----------------------------" << endl;
    cout << "|     Xn      |      Rn      |" << endl;
    cout << "|----------------------------|" << endl;
}
void EndMessage()
{
    cout << "       -------------------------------------------------------";
    cout << "\n\t               ** Thank you!!!. **" << endl;
    cout << "       -------------------------------------------------------";
    cout << endl;

}

class Calculation
{
private:
    double x0;   // seed
    double m;    // modulus
    int steps; // numbers
    double a;    // multiplier

public:
    Calculation(double initialX, double modulus, int numOfSteps)
    {
        x0 = initialX;
        m = modulus;
        steps = numOfSteps;
    }

    double Xn;
    double Rn;
    double test[];


    void calculateICG(double a)
    {
        double result1 = x0 / m;
        while (result1 >= 1)
        {
            result1 /= m;
        }
        cout << "|   " << x0 << "      |   " << result1 << "   |" << endl;
        test[0]=result1;
        double xxn;
        for (int i = 1; i <= steps; i++)
        {
            double result = a / x0;
            Xn = fmod(result, m);
            xxn = Xn;
            Rn = Xn / m;
            while (Rn >= 1)
            {
                Rn /= m;
            }
            test[i]=Rn;
            cout << "|   " << xxn << "  |   " << Rn << " |        " <<test[i]<< endl;
            x0 = Xn;
        }
    }

void calculateMSM()
{
    for (int i = 1; i <= steps; i++)
    {
        int SQure = x0 * x0;
        string value = to_string(SQure);
        int skipchars = (value.size() - 4) / 2;
        string ans;
        for (int j = skipchars; j < skipchars + 4; j++)
            ans.push_back(value[j]);
        Xn = stod(ans);
        Rn = Xn / m;
        while(Rn >= 1){
            Rn /=m;
        }
        test[i]=Rn;
        string xn="x"+to_string(i);
        cout << xn <<" = "<<x0 << "  " << SQure << " " << Rn << endl;
        x0 = Xn;
    }
}


    void calculateLFG(int Operator, int j, int k, int x0, int x1, int m)
    {
        double Xn[steps];
        double Rn[steps];
        Xn[0] = x0;
        Xn[1] = x1;
        for (int i = 2; i < steps; i++)
        {
            if (Operator == 1)
            {
                Xn[i] = (x1 + x0) % m;
            }
            else if (Operator == 2)
            {
                Xn[i] = (x1 - x0) % m;
            }
            else if (Operator == 3)
            {
                Xn[i] = (x1 * x0) % m;
            }
            else if (Operator == 4)
            {
                Xn[i] = (x1 ^ x0) % m;
            }
            x0 = x1;
            x1 = Xn[i];
        }
        for (int j = 0; j < steps; j++)
        {
            Xn[j] = fmod(Xn[j], m);
            Rn[j] = Xn[j] / m;
            test[j]=Rn[j];
            cout << Xn[j] << "             " << Rn[j] << endl;
        }
    }


    void calculateMRG(int n, double num[], double X[])
    {
        for (int i = 0; i < steps; i++)
        {
            Xn = 0;

            for (int j = 0; j < steps - 1; j++)
            {
                Xn += num[j] * X[j];
            }
            Xn = fmod(Xn, m);
            Rn = Xn / m;
            test[i]=Rn;
            cout << Xn << "             " << Rn << endl;

            for (int j = steps - 1; j > 0; j--)
            {
                X[j] = X[j - 1];
            }

            X[0] = Xn;
        }
    }



   bool calculateKS(double Tnumber)
{
    double Dplus = 0, Dminus = 0, D0 = 0, critical = 0;

    if (steps == 0) {
        cout << "No data for KS Test!" << endl;
        return false;
    }
    else{
    sort(test, test + steps);

    for (int i = 0; i < steps; i++)
    {
        double Pr = (double)(i + 1) / steps;
        double Dr = (double)i / steps;
        Dplus = max(Dplus, Pr - test[i]);
        Dminus = max(Dminus, test[i] - Dr);
    }

    D0 = max(Dminus, Dplus);

    if (Tnumber == 0.10)
    {
        critical = 1.22 / sqrt(steps);
    }
    else if (Tnumber == 0.05)
    {
        critical = 1.36 / sqrt(steps);
    }
    else if (Tnumber == 0.01)
    {
        critical = 1.63 / sqrt(steps);
    }

    if (D0 < critical)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
}




bool calculateKS(double Tnumber, double Rnum[], int count)
{
    double Dplus = 0, Dminus = 0, D0 = 0, critical = 0;
    sort(Rnum, Rnum + count);

    for (int i = 0; i < count; i++)
    {
        double Pr = (double)(i + 1) / count;
        double Dr = (double)i / count;
        Dplus = max(Dplus, Pr - Rnum[i]);
        Dminus = max(Dminus, Rnum[i] - Dr);
    }

    D0 = max(Dminus, Dplus);
    if (Tnumber == 0.10)
    {
        critical = 1.22 / sqrt(count);
    }
    else if (Tnumber == 0.05)
    {
        critical = 1.36 / sqrt(count);
    }
    else if (Tnumber == 0.01)
    {
        critical = 1.63 / sqrt(count);
    }

    if (D0 < critical)
    {
        return true;
    }
    else
    {
        return false;
    }
}

};
int main()
{
    WelcomeMessage();
    while (true) {
        cout << endl<< "\t\t\t Choose a method:" << endl;
        cout << "\t\t\t     1 --> ICG" << endl;
        cout << "\t\t\t     2 --> MSM" << endl;
        cout << "\t\t\t     3 --> LFG" << endl;
        cout << "\t\t\t     4 --> MRG" << endl;
        cout<<  "\t\t\t     5 --> KS TEST"<<endl<<"\t\t\t  --------------"<<endl<<endl;

        double initialX, multiplier, modulus;
        int numOfSteps, method;

        cout << "Enter the number of method (0 to exit): ";
        cin >> method;

        if (method == 0) break;

        if(method != 5){
            cout << "Enter initial value of x0 : ";
            cin >> initialX;
            cout << "Enter value of m : ";
            cin >> modulus;
            cout << "Enter number of steps : ";
            cin >> numOfSteps;
        }
        double num[numOfSteps];
        double X[numOfSteps];

        Calculation calc(initialX, modulus, numOfSteps);
        string choice;

        switch (method)
        {
        case 1:
            cout << "Enter Value of multiplier : ";
            cin >> multiplier;
            output();
            calc.calculateICG(multiplier);
            break;

        case 2:
            output();
            calc.calculateMSM();
            break;

    case 3:
    int j, k;
        cout << "Enter value of lag 1 (j) : ";
        cin >> j;
        cout << "Enter value of lag 2 (k) : ";
        cin >> k;
    int Operator;
    while (Operator != 1 && Operator != 2 && Operator != 3 && Operator != 4)
    {
        cout << "    Choose Operator : " << endl;
        cout << "      1- Addition (+)" << endl;
        cout << "      2- Subtraction (-)" << endl;
        cout << "      3- Multiplication (*)" << endl;
        cout << "      4- XOR " << endl;
        cin >> Operator;
    }
    int x0, x1;
    cout << "Enter value of seed 1 (X0): " << endl;
    cin >> x0;
    cout << "Enter value of seed 2 (X1): " << endl;
    cin >> x1;
    output();
    calc.calculateLFG(Operator, j, k, x0, x1, modulus);
    break;


        case 4:
            cout << "Enter numbers(ex.. a, b ,c) :" << endl;
            for (int i = 0; i < numOfSteps - 1; i++)
            {
                cin >> num[i];
            }
            cout << "Enter value of x0 :" << endl;
            cin >> X[0];
            for (int i = 1; i < numOfSteps - 1; i++)
            {
                cout << "Enter value of (ex.. x1, x2) :" << endl;
                cin >> X[i];
            }
            output();
            calc.calculateMRG(numOfSteps, num, X);
            break;

        case 5:
            cout << "Do you want to provide your own random numbers for KS Test? (yes/no): ";
            cin >> choice;
            if(choice == "yes"){
                cout << "------- Provide random numbers to test -------" << endl;
                int count;
                cout<<"Enter number of the Random numbers : "<<endl;
                cin>>count;

                double Rnum[count];
                for(int i=0;i<count;i++)
                {
                    cout<<"Enter numbers value : "<<endl;
                    cin>>Rnum[i];
                }
                double Tnumber;
                cout << "Enter value of the test number (0.10 or 0.05 or 0.01) : ";
                cin >> Tnumber;

                while (Tnumber != 0.10 && Tnumber != 0.05 && Tnumber != 0.01)
                {
                    cout << "Invalid value! Please enter 0.10, 0.05, or 0.01: ";
                    cin >> Tnumber;
                }
                if(calc.calculateKS(Tnumber,Rnum,count)){
                    cout<<"KS Test Result: Passed"<<endl<<endl;
                }
                else{
                    cout<<"KS Test Result: Failed"<<endl<<endl;
                }
            } else if (choice == "no"){
                double Tnumber;
                cout << "Enter value of the test number (0.10 or 0.05 or 0.01) : ";
                cin >> Tnumber;

                while (Tnumber != 0.10 && Tnumber != 0.05 && Tnumber != 0.01)
                {
                    cout << "Invalid value! Please enter 0.10, 0.05, or 0.01: ";
                    cin >> Tnumber;
                }
                if(calc.calculateKS(Tnumber)){
                    cout<<"KS Test Result: Passed"<<endl<<endl;
                }
                else{
                    cout<<"KS Test Result: Failed"<<endl<<endl;
                }
            } else {
                cout << "Invalid choice!" << endl;
            }
            break;

        default:
            cout << "Invalid method choice!" << endl;
            break;
        }
    }
    EndMessage();
    return 0;
}
