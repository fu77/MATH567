/*
 * This small program estimates the ratio of
 * psi(x) = #{primes under x that are congruent to 3 mod 4}
 * and
 * pi(x) = #{primes under x}
 * for large x
 * Primality test proposed by https://www.tutorialspoint.com/
 */
#include <math.h>
#include <iostream>
using namespace std;

int power(int a, unsigned int n, int p) {
  int res = 1;
  a = a % p;
  while (n > 0) {
    if (n & 1) res = (res * a) % p;
    n = n / 2;
    a = (a * a) % p;
  }
  return res;
}

int gcd(int a, int b) {
  if (a < b)
    return gcd(b, a);
  else if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

bool isPrime(unsigned int n, int k) {
  if (n <= 1 || n == 4) return false;
  if (n <= 3) return true;
  while (k > 0) {
    int a = 2 + rand() % (n - 4);
    if (gcd(n, a) != 1) return false;
    if (power(a, n - 1, n) != 1) return false;
    k--;
  }
  return true;
}

int psi(unsigned int n) {
  int count = 0;
  for (int i = 3; i <= n; i += 2) {
    if ((isPrime(i, 3)) && (i % 4 == 3)) {
      // cout << i << " ";
      count++;
    }
  }
  cout << endl;
  return count;
}

int pi(unsigned int n) {
  int count = 1;
  for (int i = 3; i <= n; i += 2) {
    if (isPrime(i, 3)) {
      // cout << i << " ";
      count++;
    }
  }
  cout << endl;
  return count;
}

int main(int argc, char *argv[]) {
  if (argc != 2) exit(1);
  int n = atoi(argv[1]);
  cout << psi(n) * 1.0 / pi(n) << endl;
  return 0;
}
