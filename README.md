# C++ Structures, Functions, Arrays, and Pointers — Scientific Assignments

**To test your solutions:**
```bash
./check.sh
```

The script will test each question with multiple input cases and report which test cases pass/fail.

**To test a specific program:**
```bash
./check.sh question1.cpp
```

This will only test question1.cpp with its input cases.

**To run a program manually with a specific input file:**
```bash
g++ -o question1 question1.cpp
./question1 test_data/input1a.txt
```

Replace `question1` with the appropriate question number and `input1a.txt` with the desired input file.

---

## 📘 Assignment 1 — Book Metadata

**Your Task:**

* Design a struct `Book` with fields for bibliographic data (title, author, pages, year, isbn at minimum).
* Create an array of books and fill with values.
* Print each book using the given output function.

**Required Output Function:**

```cpp
void print_book(int index, const char* title, const char* author,
                int year, int pages, const char* isbn) {
    std::cout << "Book[" << index << "]: "
              << "title=" << title << ", "
              << "author=" << author << ", "
              << "year=" << year << ", "
              << "pages=" << pages << ", "
              << "isbn=" << isbn << "\n";
}
```

**Example Input File Content:**

```
2
The Hobbit
J.R.R. Tolkien
1937
310
978-0547928227
Dune
Frank Herbert
1965
412
978-0441172719
```

**Example Struct Values:**

```cpp
Book b1 = {"The Hobbit", "J.R.R. Tolkien", 1937, 310, "978-0547928227"};
Book b2 = {"Dune", "Frank Herbert", 1965, 412, "978-0441172719"};
```

**Example Output:**

```
Book[0]: title=The Hobbit, author=J.R.R. Tolkien, year=1937, pages=310, isbn=978-0547928227
Book[1]: title=Dune, author=Frank Herbert, year=1965, pages=412, isbn=978-0441172719
```

---

## 🟦 Assignment 2 — Rectangular Plate in Mechanics

**Your Task:**

* Design a struct `Rectangle` with fields such as width, height, thickness, density and Material.
* Compute the mass of each plate using:

  ```
  mass = width * height * thickness * density
  ```
* Store at least 2 plates and print results.

**Required Output Function:**

```cpp
void print_plate(int index, double width, double height,
                 double density, double mass, const char* material) {
    std::cout << "Plate[" << index << "]: "
              << "width=" << width << ", "
              << "height=" << height << ", "
              << "density=" << density << ", "
              << "mass=" << mass << ", "
              << "material=" << material << "\n";
}
```

**Example Input File Content:**

```
2
2.0
3.0
0.01
7850
Steel
1.5
2.5
0.02
2700
Aluminium
```

**Example Output:**

```
Plate[0]: width=2, height=3, density=7850, mass=471, material=Steel
Plate[1]: width=1.5, height=2.5, density=2700, mass=202.5, material=Aluminium
```

---

## 🔵 Assignment 3 — Point with Rotation

**Your Task:**

* Design a struct `Point` with x and y coordinates.
* Write a function to rotate a point (x, y) around a pivot point (px, py) by angle θ (in radians):

```
x' = px + (x - px) * cos(θ) - (y - py) * sin(θ)
y' = py + (x - px) * sin(θ) + (y - py) * cos(θ)
```
* Print the point before and after rotation.

**Required Output Function:**

```cpp
void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    std::cout << "Before rotation: (x=" << x_before << ", y=" << y_before << ")\n";
    std::cout << "After rotation (θ=" << theta << " rad): "
              << "(x=" << x_after << ", y=" << y_after << ")\n";
}
```

**Example Input File Content:**

```
1.0
0.0
1.5707963267948966
0.0
0.0
```

**Example Output:**

```
Before rotation: (x=1, y=0)
After rotation (θ=1.5708 rad): (x=0, y=1)
```
** Another Example Input File Content(rotation around pivot(1,1)):**

```
1.0
0.0
1.5707963267948966
0.0
0.0
```

**Example Output:**

```
Before rotation: (x=1, y=0)
After rotation (θ=1.5708 rad): (x=2, y=1)
```
---

## 🟣 Assignment 4 — Taylor Series Expansion

**Your Task:**

* Design a struct `TaylorTerm` with fields: order, coeff, value.
* Use it to approximate `sin(x)` with N terms:

  ```
  sin(x) ≈ Σ (-1)^n * x^(2n+1) / (2n+1)!
  ```
* Store each term in an array and print each one.
* Print the final approximation.

**Required Output Functions:**

```cpp
void print_taylor_term(int index, int order, double coeff, double value) {
    std::cout << "Term[" << index << "]: "
              << "order=" << order << ", "
              << "coeff=" << coeff << ", "
              << "value=" << value << "\n";
}

void print_taylor_result(const char* function_name, double x,
                         int terms, double approximation) {
    std::cout << "Approximation of " << function_name
              << "(x) at x=" << x
              << " with " << terms << " terms: "
              << approximation << "\n";
}
```

**Example Input File Content:**

```
1.0
3
```

**Example Output:**

```
Term[0]: order=1, coeff=1, value=1
Term[1]: order=3, coeff=-0.166667, value=-0.166667
Term[2]: order=5, coeff=0.00833333, value=0.00833333
Approximation of sin(x) at x=1 with 3 terms: 0.841667
```
---

## 🟢 Assignment 5 — Array of Sensors (Pointers Exercise)

**Your Task:**

* Design a struct `Sensor` with fields such as id, temperature, voltage, and status.
* Store several sensors in an array.
* Use a **pointer** to iterate through the array (not indexing).
* Print the details of each sensor using the given output function.

**Required Output Function:**

```cpp
void print_sensor(int index, int id, double temperature, double voltage, const char* status) {
    std::cout << "Sensor[" << index << "]: "
              << "id=" << id << ", "
              << "temperature=" << temperature << ", "
              << "voltage=" << voltage << ", "
              << "status=" << status << "\n";
}
```

**Example Input File Content:**

```
3
101
36.5
3.3
Active
102
40.2
3.1
Inactive
103
38.7
3.4
Active
```

**Example Output:**

```
Sensor[0]: id=101, temperature=36.5, voltage=3.3, status=Active
Sensor[1]: id=102, temperature=40.2, voltage=3.1, status=Inactive
Sensor[2]: id=103, temperature=38.7, voltage=3.4, status=Active
```
