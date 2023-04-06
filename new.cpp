#include <iostream>
using namespace std;
class Polynomial
{
   public:
    int *degCoeff; 
    int capacity;
    Polynomial()
    {
        degCoeff = new int[5];
        capacity = 5;
        for (int i = 0; i < 5; i++)
        {
            degCoeff[i] = 0;
        }
    }
    Polynomial(Polynomial const &p)
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    void operator=(Polynomial const &p)
    {
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    void setCoefficient(int degree, int coeff)
    {
        if (degree >= capacity)
        {
            int *newdegCoeff = new int[degree + 1];
            for (int i = 0; i < capacity; i++)
            {
                newdegCoeff[i] = degCoeff[i];
            }
            for (int i = capacity; i < degree + 1; i++)
            {
                newdegCoeff[i] = 0;
            }
            newdegCoeff[degree] = coeff;
            degCoeff = newdegCoeff;
            capacity = degree + 1;
        }
        else
        {
            degCoeff[degree] = coeff;
        }
    }
    Polynomial operator+(Polynomial const &p)
    {
        Polynomial pnew;
        int i = 0, j = 0;
        while (i < capacity && j < p.capacity)
        {
            pnew.setCoefficient(i, degCoeff[i] + p.degCoeff[j]);
            i++;
            j++;
        }
        while (i < capacity)
        {
            pnew.setCoefficient(i, degCoeff[i]);
            i++;
        }
        while (j < p.capacity)
        {
            pnew.setCoefficient(j, p.degCoeff[j]);
            j++;
        }
        return pnew;
    }
    Polynomial operator-(Polynomial const &p)
    {
        Polynomial pnew;
        int i = 0, j = 0;
        while (i < capacity && j < p.capacity)
        {
            pnew.setCoefficient(i, degCoeff[i] - p.degCoeff[j]);
            i++;
            j++;
        }
        while (i < capacity)
        {
            pnew.setCoefficient(i, degCoeff[i]);
            i++;
        }
        while (j < p.capacity)
        {
            pnew.setCoefficient(j, -p.degCoeff[j]);
            j++;
        }
        return pnew;
 }
 Polynomial operator*(Polynomial const &p)
 {
     Polynomial pnew;
     for (int i = 0; i < capacity; i++)
     {
         for (int j = 0; j < p.capacity; j++)
         {
             pnew.setCoefficient(i + j, degCoeff[i] * p.degCoeff[j]);
         }
     }
     return pnew;
 }
    
 void print()
 {
     for (int i = 0; i < capacity; i++)
     {
         if (degCoeff[i] != 0)
         {
             cout << degCoeff[i] << "x" << i << " ";
         }
     }
     cout << endl;
 }
};
int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice)
    {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}
