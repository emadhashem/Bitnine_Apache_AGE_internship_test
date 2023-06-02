# [ Question No. 2 ]

This implementation includes three different functions: f_recursive, f_iterative, and f_dynamic_programming. The first function uses recursion to calculate the sequence, the second function uses a loop, and the third function uses dynamic programming.

# Recursive Implementation (f_recursive)
This implementation has a time complexity of O(2^n), which means that it grows exponentially with n. This makes it very slow for larger values of n, and it can also lead to stack overflow errors if n is too large. This implementation is very simple and elegant.

# Iterative Implementation (f_iterative)
This implementation has a time complexity of O(n), which means that it is relatively efficient for small values of n. However, for larger values of n, the time complexity grows linearly, which can become slow. This implementation is easy to understand and implement.

# Dynamic Programming Implementation (f_dynamic_programming)
This implementation has a time complexity of O(n), which is much faster than the recursive implementation for larger values of n. It also has the advantage of being easy to understand and implement. However, it requires more memory than the iterative implementation, as it needs to store an array of size n+2 to store the intermediate results. This can be a disadvantage for very large values of n, as it can lead to memory allocation errors.



<hr/>
<hr/>


##  Compile and Run

<ul>
 <li> Install GCC compiler: If you haven't already, you will need to install the GCC compiler on your system. On Unix-like systems, GCC is often pre-installed or can be installed using the package manager. On Windows, you can download and install the MinGW-w64 toolchain from the official website: https://sourceforge.net/projects/mingw-w64/ </li>

 <li>
    Open a terminal or command prompt: Open the terminal or command prompt on your system.
 </li>
 <li>
   Navigate to the directory where the source code file is located: Use the cd command to navigate to the directory where the source file (task2.c) is located.
 </li>
 <li>
    Compile the code: Type the following command to compile the code: (gcc task2.c -o run2) <br>
    This command uses the GCC compiler to compile the C code and create an executable file.
 </li>
 <li>
    Run the program: Type the following command to run the program: ./run2
 </li>
</ul>
That's it! You should now be able to run the program and generate the sequence of numbers for the piecewise recurrence relation.




