// it is used to prevent overflow errors(eg. integer overflow);
// result = x%n , result = [0, ..., n-1];
// for example 100%3 will lye in the range 0,1,2. It can't be greater or equal to 3.

// ans%(power(10,7)+9);

// Modulo Properties
// (x+y) % m = x%m + y%m
// (x-y) % m = x%m - y%m
// (x.y) % m = x%m . y%m
// ((((x%m)%m)%m)%m)... will remains same 
