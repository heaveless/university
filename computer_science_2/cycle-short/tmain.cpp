// Cycle sort
#include <iostream>
using namespace std;


void cycleSort(int arrayOfNumbers[], int numberOfElements)
{
    int writes = 0;

    for (int cycle_start = 0; cycle_start <= numberOfElements - 2; cycle_start++)
    {
        // initialize the value of the first element
        int element = arrayOfNumbers[cycle_start];

        // Count all smaller values than our element
        int position = cycle_start;
        for (int i = cycle_start + 1; i < numberOfElements; i++)
        {
            if (arrayOfNumbers[i] < element)
            {
                position++;
            }
        }

        // If the element is already in the correct position
        if (position == cycle_start)
        {
            continue;
        }

        // Ignore duplicate elements
        while (element == arrayOfNumbers[position])
        {
             position += 1;
        }

        // Put the value in the right position
        if (position != cycle_start)
        {
            swap(element, arrayOfNumbers[position]);
            writes++;
        }

        // Cycle for the rest of elements
        while (position != cycle_start)
        {
            position = cycle_start;

            // Find position where we put the element
            for (int i = cycle_start + 1; i < numberOfElements; i++)
            {
                if (arrayOfNumbers[i] < element)
                {
                    position += 1;
                }
            }

            // Ignore duplicate elements
            while (element == arrayOfNumbers[position])
            {
                position += 1;
            }

            // Put the value in the right position
            if (element != arrayOfNumbers[position])
            {
                swap(element, arrayOfNumbers[position]);
                writes++;
            }
        }
    }
}

void printElementsOfArray(int arrayOfNumbers[], int numberOfElements)
{
  for (int i = 0; i < numberOfElements; ++i)
  {
    cout << arrayOfNumbers[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arrayOfNumbers[] = {4, 7, 9, 3, 21, 18, 23, 15, 8, 17};
  int numberOfElements = sizeof(arrayOfNumbers) / sizeof(arrayOfNumbers[0]);

  cycleSort(arrayOfNumbers, numberOfElements);
  cout<<"The sorted array is: \n";
  printElementsOfArray(arrayOfNumbers, numberOfElements);
}
