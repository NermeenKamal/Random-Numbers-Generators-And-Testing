![Screenshot 2024-05-08 224247](https://github.com/NermeenKamal/Random-Numbers-Generators-And-Testing/assets/114883845/11ffd04d-6f93-4e0d-85a4-b7c55459bf79)

---

# Random Number Generator

This is a C++ project for generating random numbers using different methods:

1. **ICG (Inversive Congruential Generator)**
2. **MSM (Middle Square Method)**
3. **LFG (Lagged Fibonacci Generator)**
4. **MRG (Multiple Recursive Generators)**
5. **KS Test (Kolmogorov-Smirnov Test)**

## Introduction

This project implements various algorithms for generating random numbers and includes a method for testing the generated sequence with the KS (Kolmogorov-Smirnov) test. The methods implemented are as follows:

- **ICG (Inversive Congruential Generator):** Generates random numbers using the ICG rule: X(i+1) = (a / Xi) % m.
- **MSM (Middle Square Method):** Generates random numbers using the MSM rule: X(i) = (Xi)^2 -> mid % m.
- **LFG (Lagged Fibonacci Generator):** Generates random numbers using the LFG rule: X(i) = (Xi - j operator Xi - k) % m.
- **MRG (Multiple Recursive Generators):** Generates random numbers using the MRG rule: X(i+1) = sum(an * Xi - q) % m.
- **KS Test (Kolmogorov-Smirnov Test):** Performs the Kolmogorov-Smirnov test to evaluate the uniformity of the generated sequence.

## Usage

1. Clone this repository:
git clone https://github.com/NermeenKamal/random-number-generator.git


2. Navigate to the project directory:
cd random-number-generator


3. Compile the code:
g++ -o random_number_generator random_number_generator.cpp


4. Run the program:
./random_number_generator


5. Follow the on-screen instructions to generate random numbers and perform the KS Test.

## Method Selection

1. **ICG:**
   - Enter method number `1`.
   - Provide the required inputs.
   - Generated random numbers will be displayed.

2. **MSM:**
   - Enter method number `2`.
   - Provide the required inputs.
   - Generated random numbers will be displayed.

3. **LFG:**
   - Enter method number `3`.
   - Provide the required inputs.
   - Generated random numbers will be displayed.

4. **MRG:**
   - Enter method number `4`.
   - Provide the required inputs.
   - Generated random numbers will be displayed.

5. **KS Test:**
   - Enter method number `5`.
   - Choose whether you want to provide your own random numbers or not.
   - Perform the test.

  ---
