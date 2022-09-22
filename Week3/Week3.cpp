#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


class Student
{
public:

    string firstName;
    string lastName;
    int grade;


};


//sepreate line token
Student BreakStringIntoTokens(string line)
{
    Student s;
    vector <string> token;
    stringstream ss(line);

    while (ss.good())
    {
        string substr;
        getline(ss, substr, ' ');
        token.push_back(substr);
        //cout << substr;
    }

    s.firstName = token[0];
    s.lastName = token[1];
    s.grade = stoi(token[2]);

    return s;
}

void bubbleSort(vector<Student>& arr, int n)
{
    int i, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].grade < arr[j + 1].grade)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

}

int main()
{
    //vector student
    vector <Student> students;

    string line;

    int i = 0;


    ifstream fin;

    fin.open("example.txt");

    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            Student s = BreakStringIntoTokens(line);

            students.push_back(s);

        }
    }

    else
    {
        cout << "couldn't open" << endl;
    }
 

    // handle sorting
    cout << "\n\n\n";

    bubbleSort(students, students.size());


    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].firstName << " " << students[i].lastName << " " << students[i].grade << endl;
        //cout << students[i].lastName << endl;
        //cout << students[i].grade << endl;
    }

    // handle the average

    float count = (students.size());
    {
        int sum = 0;
        int average = 0;

        for (int i = 0; i < count; i ++)
        {
            sum += students[i].grade;

                average = sum / count;

                
        }

        cout << "Average: " << (average);
    }

        return(0);

}