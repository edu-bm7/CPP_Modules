# What is inline function and why does it improves the Function Call Overhead?

## What is Function Call Overhead?

Function call overhead refers to the extra time and resource consumption associated with calling a function in a program. This overhead is not related to the actual execution of the function's core logic but to the mechanics of the function call itself.

### The overhead includes:

#### Parameter Passing:

The process of copying arguments to the function's parameters. 
This can involve copying data onto the stack or setting up registers, depending on the size and type of the arguments and the calling convention used by the compiler.

#### Call and Return Mechanics:

The CPU operations involved in jumping to the function's code block and then returning to the point of call after the function completes. This includes managing the call stack, pushing the return address onto the stack, and jumping to the function's entry point.

#### Stack Frame Management:

Each function call typically involves setting up and tearing down a stack frame for the function. This stack frame includes memory for the function's local variables, a return address, and may include saved copies of registers that the function is allowed to alter (based on the calling convention).

## How Inlining Reduces Function Call Overhead

Inlining is a compiler optimization technique where the compiler replaces a function call with the actual code of the function. That is, the function's body is "inlined" into the place where it is called, so instead of performing a function call, the program simply executes the function's code directly in place.

### The benefits of inlining include:

- **Eliminating Call and Return Overhead:** Since there's no function call made, there's no need to manage call and return operations or manipulate the call stack for this function call. This saves the time and operations associated with these mechanics.

- **Avoiding Parameter Passing and Stack Frame Setup:** When a function is inlined, parameter passing can often be optimized away, especially for small and simple functions. Local variables can be optimized into registers, and unnecessary memory accesses can be reduced or eliminated.

- **Enabling Further Optimizations:** Once a function's code is inlined, its body can be subject to further optimizations in the context of its usage. The compiler has a better opportunity to optimize the inlined code together with the caller's code, such as simplifying expressions, unrolling loops, or optimizing away redundant calculations that may be apparent due to the specific context in which the function is used.

## Example

Consider the following simple function:
```cpp
inline int add(int x, int y) {
    return x + y;
}

int main() {
    int result = add(5, 3);
    return 0;
}
```

If *add* is inlined, the compiler might transform the main function to look like this after compilation:

```cpp
int main() {
    int result = 5 + 3; // Direct computation, no function call overhead
    return 0;
}
```

## When Not to Inline

Despite its benefits, **inlining is not always advisable:**

- **Large Functions:** Inlining large functions can lead to code bloat, where the increased size of the executable code can negatively impact cache performance and, ultimately, the speed of the application.

- **Recursive Functions:** Inlining recursive functions can lead to infinite recursion at compile-time unless the compiler is smart enough to handle a base case inline while keeping recursive calls normal.

- **Virtual Functions:** Virtual functions, used in polymorphic behavior, generally should not be inlined because their behavior depends on runtime type identification, although compilers might inline them in contexts where the dynamic type is known.
