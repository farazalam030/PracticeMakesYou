/*
 * An exception is a problem that arises during the execution of a program. A
C++ exception is a response to an exceptional circumstance that arises while a
program is running, such as an attempt to divide by zero.

Exceptions provide a way to transfer control from one part of a program to
another. C++ exception handling is built upon three keywords: try, catch, and
throw.

throw ? A program throws an exception when a problem shows up. This is done
using a throw keyword.

catch ? A program catches an exception with an exception handler at the place in
a program where you want to handle the problem. The catch keyword indicates the
catching of an exception.

try ? A try block identifies a block of code for which particular exceptions
will be activated. It's followed by one or more catch blocks.

Assuming a block will raise an exception, a method catches an exception using a
combination of the try and catch keywords. A try/catch block is placed around
the code that might generate an exception. Code within a try/catch block is
referred to as protected code, and the syntax for using try/catch as follows ?

 try {
   // protected code
} catch( ExceptionName e1 ) {
   // catch block
} catch( ExceptionName e2 ) {
   // catch block
} catch( ExceptionName eN ) {
   // catch block
}

You can list down multiple catch statements to catch different type of
exceptions in case your try block raises more than one exception in different
situations.


Throwing Exceptions
Exceptions can be thrown anywhere within a code block using throw statement. The
operand of the throw statement determines a type for the exception and can be
any expression and the type of the result of the expression determines the type
of exception thrown.

Following is an example of throwing an exception when dividing by zero condition
occurs ?

double division(int a, int b) {
   if( b == 0 ) {
      throw "Division by zero condition!";
   }
   return (a/b);
}
Catching Exceptions
The catch block following the try block catches any exception. You can specify
what type of exception you want to catch and this is determined by the exception
declaration that appears in parentheses following the keyword catch.

try {
   // protected code
} catch( ExceptionName e ) {
  // code to handle ExceptionName exception
}
Above code will catch an exception of ExceptionName type. If you want to specify
that a catch block should handle any type of exception that is thrown in a try
block, you must put an ellipsis, ..., between the parentheses enclosing the
exception declaration as follows ?

try {
   // protected code
} catch(...) {
  // code to handle any exception
}

 */
#include <bits/stdc++.h>
using namespace std;

double division(int a, int b) {
  if (b == 0) {
    throw "Exception Division by zero Encountered!!!!!!";
  }
  return (((double)a) / b);
}

int throwExample() {
  int a = 50;
  int b = 0;
  double c = 0.0;
  try {
    c = division(a, b);
    cout << "\n\nresult = " << c << endl;
  } catch (const char* ErrorMessage) {
    cerr << ErrorMessage << endl;
  }
  return 0;
}

int tryCatchFlowExample() {
  int x = -1;
  cout << "\nbefore try block\n " << endl;

  try {
    cout << "\nInside try block\n " << endl;
    if (x < 0) {
      throw x;
      cout << "\nafter throw + never reachced" << endl;
    }
  } catch (int x) {
    cout << "\nin catch block + exception caugth =  " << x << endl;
  }
  cout << "\nAfter Catch block\n  + completed" << endl;

  return 0;
}

int catchAllExample() {
  /*
   * ) There is a special catch block called �catch all� catch(�) that can be
   * used to catch all types of exceptions. For example, in the following
   * program, an int is thrown as an exception, but there is no catch block for
   * int, so catch(�) block will be executed.
   */
  try {
    throw "Hi all exception";
  } catch (int e) {
    cout << "exception -> " << e << endl;
  } catch (...) {
    cout << "Catch All Default exception " << endl;
  }

  return 0;
}

int noImplicitTypeConversioninCatchTypeparam() {
  /*
   * Implicit type conversion doesn�t happen for primitive types. For example,
   * in the following program �a� is not implicitly converted to int
   */
  try {
    throw 'b';
  } catch (int e) {
    cout << "exception -> " << e << endl;
  } catch (...) {
    cout << "Catch All Default exception " << endl;
  }
}

int abnormalHandlingExample() {
  /*
   *  If an exception is thrown and not caught anywhere, the program terminates
   * abnormally. For example, in the following program, a char is thrown, but
   * there is no catch block to catch a char.
   */
  try {
    throw 'b';
  } catch (int e) {
    cout << "exception -> " << e << endl;
  }
  //	  catch (...) {
  //	    cout << "Catch All Default exception " << endl;
  //	  }
}
int main() {  //
              //  tryCatchFlowExample();

  //  throwExample();
  //  catchAllExample();
  //  noImplicitTypeConversioninCatchTypeparam();
  abnormalHandlingExample();
  return 0;
}
