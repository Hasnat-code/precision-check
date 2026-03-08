# Precision Check – High-Precision Numerical Integration in C++

This project demonstrates a simple **high-precision numerical integration program in C++**.
The goal is to compute an integral accurately while minimizing floating-point errors and ensuring **consistent results across multiple runs and machines**.

---

## Project Goal

The main objectives of this project are:

* Achieve **high numerical accuracy (≤ 1e-6)**
* Produce **deterministic results** for the same input
* Explore **floating-point precision issues**
* Compare behavior that could appear on **different machines or CPU vs GPU environments**
* Demonstrate how **Kahan Summation** improves numerical stability

---

## Mathematical Problem

The program computes the numerical approximation of:

∫₀¹ x² dx

Exact analytical solution:

1 / 3 ≈ 0.3333333333

The program compares the **computed numerical result** with the **exact mathematical value** to evaluate accuracy.

---

## Key Concepts Demonstrated

### 1. Numerical Integration

The integral is approximated using the **rectangle method** with a large number of steps.

### 2. Floating-Point Error

Repeated summation of floating-point numbers can introduce rounding errors.

### 3. Kahan Summation Algorithm

The program uses **Kahan Summation** to compensate for floating-point rounding errors and improve numerical accuracy.

### 4. Deterministic Computation

The program is designed to produce **consistent results for identical inputs**, helping explore reproducibility in numerical computing.

---

## Program Output Example

Example output from running the program:

```
Computed integral: 0.3333328333
Exact integral   : 0.3333333333
Absolute error   : 0.0000005000
Execution time   : 33 ms
Precision goal achieved (<= 1e-6)
```

This shows that the numerical result is **within the target precision threshold**.

---

## How the Program Works

1. Define the function **f(x) = x²**
2. Divide the interval `[0,1]` into **N small steps**
3. Compute the area of each rectangle
4. Sum all values using **Kahan Summation**
5. Compare the result with the **exact analytical value**
6. Measure **execution time**

---

## Build and Run

### Compile

```bash
g++ main.cpp -O2 -o precision-check
```

### Run

```bash
./precision-check
```

---

## Project Structure

```
precision-check
│
├── main.cpp      # C++ implementation
└── README.md     # Project documentation
```

---

## Why This Project Matters

Numerical precision is critical in fields such as:

* Scientific computing
* Physics simulations
* Financial modeling
* Machine learning
* High-performance computing

Even small floating-point errors can accumulate and affect results.
Techniques like **Kahan Summation** help maintain numerical reliability.

---

## Future Improvements

Possible extensions for this project:

* Implement **parallel reduction**
* Compare **CPU vs GPU numerical differences**
* Experiment with **different numerical integration methods**
* Measure error growth with increasing iterations

---

## Author

Hasnat

---

## License

This project is open source and available for educational purposes.
