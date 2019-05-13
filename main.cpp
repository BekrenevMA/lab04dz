#include <iostream>
#include <assert.h>


using namespace std;

char nibble_to_hex(uint8_t i)
{
    assert(0x0 <= i && i <= 0xf);
    char symbols[]="0123456789abcdef";
    return symbols[i];
}

void print_in_hex(uint8_t byte)
{
    cout<<nibble_to_hex(byte>>4)
        <<nibble_to_hex(byte&0x0f);
}

const uint8_t* as_bytes(const void* data)
{
    return reinterpret_cast<const uint8_t*>(data);
}

void print_in_hex(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

char bit_digit(uint8_t byte, uint8_t bit)
{
    if (byte & (0x1 << bit))
    {
        return '1';
    }
    return '0';
}

void print_in_binary(uint8_t byte)
{
    for (uint8_t bit = 7; bit >= 0; bit--)
    {
        cout << bit_digit(byte, bit);
        if (bit==0)
            return;
    }
}

void print_in_binary(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

cale (uint16_t op1, char operat, uint16_t op2)
{
    if (operat=='&')
    {
        print_in_hex(&op1, sizeof(op1));
        cout<<operat<<" ";
        print_in_hex(&op2, sizeof(op2));
        cout<<"= ";
        uint16_t res;
        res=op1&op2;
        print_in_hex(&res, sizeof(res));
        cout<<'\n';

        print_in_binary(&op1, sizeof(op1));
        cout<<operat<<" ";
        print_in_binary(&op2, sizeof(op2));
        cout<<"= ";
        print_in_binary(&res, sizeof(res));
        cout<<'\n';
    }

    if (operat=='|')
    {
        print_in_hex(&op1, sizeof(op1));
        cout<<operat<<" ";
        print_in_hex(&op2, sizeof(op2));
        cout<<"= ";
        uint16_t res;
        res=op1|op2;
        print_in_hex(&res, sizeof(res));
        cout<<'\n';

        print_in_binary(&op1, sizeof(op1));
        cout<<operat<<" ";
        print_in_binary(&op2, sizeof(op2));
        cout<<"= ";
        print_in_binary(&res, sizeof(res));
        cout<<'\n';
    }

    if (operat=='^')
    {
        print_in_hex(&op1, sizeof(op1));
        cout<<operat<<" ";
        print_in_hex(&op2, sizeof(op2));
        cout<<"= ";
        uint16_t res;
        res=op1^op2;
        print_in_hex(&res, sizeof(res));
        cout<<'\n';

        print_in_binary(&op1, sizeof(op1));
        cout<<operat<<" ";
        print_in_binary(&op2, sizeof(op2));
        cout<<"= ";
        print_in_binary(&res, sizeof(res));
        cout<<'\n';
    }
}

struct Student
{
    char name[17];
    uint16_t year;
    float average;
    uint8_t gender:1;
    uint8_t courses;
    Student* starosta;
};

int main()
{
    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');

    /*cout<<"Enter your transaction: ";
    uint16_t op1, op2;
    char operat;
    cin>> op1 >> operat >>op2;

    cale(op1, operat, op2);
*/
    Student students[3]=
    {
        {"Nikolay", 2018, 2.4, 0, 1, nullptr},
        {"Misha", 2018, 4.0, 1, 1, &students[0]},
        {"Marina", 2018, 4.5, 0, 1, &students[0]}
    };

    cout<<"Addres of students:"<< '\n'
        <<&students<<'\n';
    cout<<"Size of students:"
        <<sizeof(students)<< '\n';
    cout<<"-----------------------------"<< '\n';

    for (size_t i=0; i<3; i++)
    {
        cout<<"Addres of student "<<i+1<<" : "<< '\n'
        <<&students[i]<<'\n';
        cout<<"Size of student"<<i+1<<": "
            <<sizeof(students[i])<< '\n';
        cout<<"-----------------------------"<< '\n';
    }

    cout<<"Addres of name of student 1: "<< '\n'
        <<&students[1].name<< '\n';
    cout<<"Offset of name of student 1: "<< '\n'
        <<offsetof(Student, name)<< '\n';
    cout<<"Size of name of student 1: "<< '\n'
        <<sizeof(students[1].name)<< '\n';
    cout<<"Print_in_hex of name of student 1 : "<< '\n';
    print_in_hex(&students[1].name, sizeof(students[1].name));
    cout<< '\n';
    cout<<"Print_in_binary of name of student 1 : "<< '\n';
    print_in_binary(&students[1].name, sizeof(students[1].name));
    cout<< '\n';
    cout<<"-----------------------------"<< '\n';

    cout<<"Addres of year of student 1: "<< '\n'
        <<&students[1].year<< '\n';
    cout<<"Offset of year of student 1: "<< '\n'
        <<offsetof(Student, year)<< '\n';
    cout<<"Size of year of student 1: "<< '\n'
        <<sizeof(students[1].year)<< '\n';
    cout<<"Print_in_hex of year of student 1 : "<< '\n';
    print_in_hex(&students[1].year, sizeof(students[1].year));
    cout<< '\n';
    cout<<"Print_in_binary of year of student 1 : "<< '\n';
    print_in_binary(&students[1].year, sizeof(students[1].year));
    cout<< '\n';
    cout<<"-----------------------------"<< '\n';

    cout<<"Addres of average of student 1: "<< '\n'
        <<&students[1].average<< '\n';
    cout<<"Offset of average of student 1: "<< '\n'
        <<offsetof(Student, average)<< '\n';
    cout<<"Size of average of student 1: "<< '\n'
        <<sizeof(students[1].average)<< '\n';
    cout<<"Print_in_hex of average of student 1 : "<< '\n';
    print_in_hex(&students[1].average, sizeof(students[1].average));
    cout<< '\n';
    cout<<"Print_in_binary of average of student 1 : "<< '\n';
    print_in_binary(&students[1].average, sizeof(students[1].average));
    cout<< '\n';
    cout<<"-----------------------------"<< '\n';

    cout<<"Addres of courses of student 1: "<< '\n'
        <<&students[1].courses<< '\n';
    cout<<"Offset of courses of student 1: "<< '\n'
        <<offsetof(Student, courses)<< '\n';
    cout<<"Size of courses of student 1: "<< '\n'
        <<sizeof(students[1].courses)<< '\n';
    cout<<"Print_in_hex of courses of student 1 : "<< '\n';
    print_in_hex(&students[1].courses, sizeof(students[1].courses));
    cout<< '\n';
    cout<<"Print_in_binary of courses of student 1 : "<< '\n';
    print_in_binary(&students[1].courses, sizeof(students[1].courses));
    cout<< '\n';
    cout<<"-----------------------------"<< '\n';

    cout<<"Addres of starosta of student 1: "<< '\n'
        <<&students[1].starosta<< '\n';
    cout<<"Offset of starosta of student 1: "<< '\n'
        <<offsetof(Student, starosta)<< '\n';
    cout<<"Size of starosta of student 1: "<< '\n'
        <<sizeof(students[1].starosta)<< '\n';
    cout<<"Print_in_hex of starosta of student 1 : "<< '\n';
    print_in_hex(&students[1].starosta, sizeof(students[1].starosta));
    cout<< '\n';
    cout<<"Print_in_binary of starosta of student 1 : "<< '\n';
    print_in_binary(&students[1].starosta, sizeof(students[1].starosta));
    cout<< '\n';
    cout<<"-----------------------------"<< '\n';

    print_in_hex(&students[1], sizeof(students[1]));

    return 0;
}
