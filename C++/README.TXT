Notes:
	-	Any function implemented in the header (except in the case of templates)
		and any unprotected header means 0 to the exrcise.
	-	Every output should be ended by a newline
	-	The imposed filenames must be followed to the letter, as well as class
		names, function names and method names.
	- FORBIDDEN functions:
		- Alloc, printf, free

	-	Not allowed to use STL until modul08
	-	Forbidden to use the C++ keywords "using namespace" and  "friend".
	-	Files associated with a class will always be ClassNames.hpp and 
		ClassNames.cpp
	-	Examples of each exercise can contain requirements not listed in the
		exercise.
	-	No C++11
	-	Compiler is C++
	-	Flags: -Wall -Wextra -Werror
	-	Includes should be able to be included independently from others.
	-	No coding style inforced
	-	We can have many Files.

1. C++ Basics:
C++ is an extension of the C programming language. It includes additional 
features like object-oriented programming and templates.
In C++, you have classes, objects, and inheritance to facilitate OOP.
C++ code is typically organized into header files (.hpp) and implementation 
files (.cpp).

2. Header Files (.hpp):
Header files declare the class structure, function prototypes, and other 
declarations.
You should not implement functions in the header files unless you are working 
with templates.
Avoid unprotected headers, and always use include guards to prevent multiple 
inclusions.

3. Implementation Files (.cpp):
Implementation files (.cpp) contain the actual code for your functions and 
methods.
Follow the naming convention, and create files like ClassName.hpp and 
ClassName.cpp for each class.

4. Forbidden Functions:
You are not allowed to use functions like Alloc, printf, or free. Instead, 
you should use C++ memory management (e.g., new and delete).

5. STL (Standard Template Library):
You are not allowed to use the STL until modul08, so you should avoid using 
standard C++ library containers and algorithms until then.

6. Namespaces:
Avoid using "using namespace." You should qualify your classes and functions 
with their respective namespaces to avoid naming conflicts.

7. C++ Compiler and Flags:
Use a C++ compiler to compile your code.
Include the flags -Wall -Wextra -Werror to enable warnings as errors. 
This ensures your code is clean and bug-free.

8. No C++11:
You are not allowed to use C++11 features, so stick to the older C++ standard.

9. Coding Style:
While there's no enforced coding style, it's essential to maintain consistent 
and readable code. Indentation, comments, and naming conventions are crucial.

10. Independent Includes:
Make sure that your header files can be included independently of each other 
without causing issues.

11. Multiple Files:
You can have multiple files in your project, but ensure that they are organized 
and follow the naming and structural conventions.

///////////////////////////////////////////////////////////////////////////////

Containers: (NOT ALLOWED TO USE UNTIL MODULE 08)
C++ standard library containers like std::vector, std::list, and std::string 
manage memory for you. They automatically allocate and deallocate memory as 
needed when elements are added or removed.

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

