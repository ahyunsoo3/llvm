# Why LLVM `IR .ll` is human-readable

LLVM IR comes in two main forms:

Text format (.ll) – human-readable, like assembly

Binary bitcode (.bc) – compact, efficient for the compiler

**Note:** Human-readability doesn’t mean LLVM is slower; the compiler usually converts .ll into binary .bc for actual compilation.

<br>

## Compliation Pipeline (LLVM-focused)
```
High-level code (C/C++, Rust, etc.)
        │
        ▼
LLVM IR (.ll)  <--- human-readable, optional
        │
        ▼
LLVM bitcode (.bc)  <--- optimized internally
        │
        ▼
Target machine code
```

<br><br>

# Meaning of the flags

`clang -O0 -S -emit-llvm test.c -o test.ll`

| Flag         | Meaning                                                                                                  |
| ------------ | -------------------------------------------------------------------------------------------------------- |
| `-O0`        | No optimization. The compiler keeps the code as close to the original as possible. Useful for debugging. |
| `-S`         | Generate an **assembly-like output** (in this case, LLVM IR text), not an object file.                   |
| `-emit-llvm` | Instead of producing CPU assembly, produce **LLVM intermediate representation (IR)**.                    |
| `test.c`     | generate a human-readable LLVM IR file from test.c.                                                      |
| `-o test.ll` | Output file is named `test.ll`.                                                                          |

<br><br>
`opt -load ./MyPass.so -my-pass < test.ll > optimized.ll`

| Part                | Meaning                                                                    |
| ------------------- | -------------------------------------------------------------------------- |
| `opt`               | The LLVM tool for running **optimization and analysis passes** on LLVM IR. |
| `-load ./MyPass.so` | Loads your custom LLVM pass compiled as a shared object (`.so` file).      |
| `-my-pass`          | Runs the pass called `my-pass` that you implemented.                       |
| `< test.ll`         | Reads input LLVM IR from `test.ll` (generated from `clang -emit-llvm`).    |
| `> optimized.ll`    | Writes the transformed IR to `optimized.ll`.                               |

- The result is saved in optimized.ll.
- You can then inspect optimized.ll to see the effect of your pass.
  
<br>**Note:** In modern LLVM, `-load` is often unnecessary. You can build your pass as a plugin or use the new pass manager. Older guides may still show `-load ./MyPass.so`.
<br>Modern syle: `opt -passes=my-pass -S test.ll -o optimized.ll`

<br><br>
