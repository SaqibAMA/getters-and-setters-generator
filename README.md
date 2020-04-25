# Getters and Setters Generator

Making getters and setters for classes every single time you're creating them, is pretty tedious. So I wrote this code to allow you to easily generate getters and setters using your data members.

### How to use?
Firstly, create a .txt file on your PC with all of your data members that you want to generate the getters and setters for i.e.

char* name;

Date DOB;

ID personID;

int age;

float salary;

Next, run the script and it will ask you for file name. Input the file name, and it will create a file in the .exe location. You'll be good to go!

### Limitations
I've configured the script to work with single int* and single char*, however, double pointers are not supported. Similarly, object pointers have varying members so I have not implemented them as well.

Thank you for having a look!
