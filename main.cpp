#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    cout<<"Entre your file: ";
    char in_file[15];
    cin>>in_file;

    int i = 0;
    while (in_file[i])
    {
        tolower(in_file[i]);
        i++;
    }

    const char* start = in_file;
    const char* illegal_characters="*\"<>?|";

    if (strcspn(in_file, illegal_characters)==strlen(in_file))
    {
        if (((strchr(in_file, ':')==strrchr(in_file, ':'))&&(strcspn( in_file, ":")==1))||(strcspn(in_file, ":")==strlen(in_file)))
        {
            const size_t dot = strcspn(in_file, ".");
            start+=dot;
            if (strcmp(start, ".txt")==0||strcmp(start, ".")==0||strcmp(start, "")==0)
            {
                if (strcmp(start, "")==0)
                    strcat(in_file, ".txt");
                if (strcmp(start, ".")==0)
                    strcat(in_file, "txt");
                FILE * ptrFile = fopen(in_file, "r");
                fseek( ptrFile, 0, SEEK_END );
                long size_of_file = ftell(ptrFile);
                fseek( ptrFile, 0, SEEK_SET );
                //char * buffer = (char*) malloc(sizeof(char) * size_of_file);
                //size_t result = fread(buffer, 1, size_of_file, ptrFile);
                //puts(buffer);
                //char *my_array = new char [size_of_file];
                //my_array=NULL;
                //size_t result = fread(my_array, 1, size_of_file, ptrFile);
                //cout<<sizeof(my_array);
                //cout<<my_array;
                char mystring[size_of_file];
                fgets(mystring, size_of_file, ptrFile);
                puts(mystring);
                /*char input_string;
                cin >> input_string;
                size_t o;
                while (true)
                {
                    if(strstr(mystring, input_string)) o++;
                    if (mystring[0] == '\0')
                    {
                        break;
                    }
                }
                cout<<o;*/
            }
        }
        else
        {
            cout<<"Your file contains two or more \":\" or the possition of \":\" not the srcond or it is't \"\\\" after the \":\"";
        }
    }
    else
    {
        cout<<"Your file contains one of illegal characters *\"<>?|";
    }

    return 0;
}

