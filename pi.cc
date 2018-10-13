/*
 * Program uses the grid method to estimate pi for a given number of grid points. Prints result to screen.
 */

#include <iostream>
#include <cmath>

// estimates pi using a grid of n points.
double gridpi(unsigned npoints) {
// constexpr double gridpi(unsigned npoints) {  // constexpr version
  unsigned x = npoints-1;
  unsigned y = 0;
  double result = 0;
  // convert to float once for comparison with float from hypot
  float fnpoints = static_cast<float>(npoints);
  // loop through each row, starting at the bottom.
  for (; y <= npoints; y++) {
    // decrement x until the hypotenuse is less than the radius of the circle
    // (which is npoints).
    while (std::hypot(x, y) > fnpoints) {
      x--;
    }
    // x is the first point to be inside the circle. therefore all x less than
    // this value in this row are also inside the circle. there are x of these,
    // so add x to the result.
    // the first x inside the circle in the next row up will be at most x,
    // so start decrementing from there on the next loop iteration.
    result += x;
  }
  return (result*static_cast<double>(4))/(static_cast<double>(npoints)
                                       *static_cast<double>(npoints));
}

int main() {
  double d = gridpi(1000);
  // constexpr double d = gridpi(1000);  //constexpr version
  std::cout << d << std::endl;
  return 0;
}
